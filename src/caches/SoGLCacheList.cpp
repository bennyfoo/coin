/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2000 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

/*!
  \class SoGLCacheList include/Inventor/caches/SoGLCacheList.h
  \brief The SoGLCacheList class is used to store and manage GL caches.

  SGI uses an LRU/MRU strategy or something here. We're not quite sure
  we should support multiple caches per Separator though. After all,
  there is some overhead in cheching for valid caches etc. If a
  situation occurs where multiple caches would help the performance,
  the user should probably redesign the scene graph and enable caching
  further down the scene graph instead. We will store at least one
  cache per cache context to support rendering in multiple contexts
  though.
*/

#include <Inventor/caches/SoGLCacheList.h>
#include <Inventor/caches/SoGLRenderCache.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/misc/SoState.h>
#include <Inventor/elements/SoGLCacheContextElement.h>
#include <Inventor/elements/SoCacheElement.h>

/*!
  Constructor. Currently the \a numcaches argument is not used.
*/
SoGLCacheList::SoGLCacheList(int numcaches)
  : numcaches(numcaches),
    flags(0),
    opencache(NULL)
{
}

/*!
  Destructor. Frees remaining caches.
*/
SoGLCacheList::~SoGLCacheList()
{
  int n = this->itemlist.getLength();
  for (int i = 0; i < n; i++) {
    this->itemlist[i]->unref();
  }
}

/*!
  Test for valid cache and execute. Returns TRUE if a valid cache
  could be found, FALSE otherwise. Note that when a valid cache is
  found, it is executed before returning from this method.
*/
SbBool
SoGLCacheList::call(SoGLRenderAction * action)
{
  SoState * state = action->getState();
  int context = SoGLCacheContextElement::get(state);

  int n = this->itemlist.getLength();
  for (int i = 0; i < n; i++) {
    SoGLRenderCache * cache = this->itemlist[i];
    if (cache->getCacheContext() == context) {
      if (cache->isValid(state)) {
        cache->call(state);
        return TRUE;
      }
      // if we get here cache is invalid. Throw it away.
      cache->unref(state);
      this->itemlist.removeFast(i);
      n--;
    }
  }
  // none found
  return FALSE;
}

/*!  
  Start recording a new cache. The \a autocache element is currently
  ignored. Remember to call close() when you've finished recoring the
  cache.

  \sa close() 
*/
void
SoGLCacheList::open(SoGLRenderAction * action, SbBool autocache)
{
  assert(this->opencache == NULL);
  SoState * state = action->getState();
  this->savedinvalid = SoCacheElement::setInvalid(FALSE);
  this->opencache = new SoGLRenderCache(state);
  this->opencache->ref();
  SoCacheElement::set(state, this->opencache);
  this->opencache->open(state);
}

/*!
  Finish recording the currently open cache.
  \sa open()
 */
void
SoGLCacheList::close(SoGLRenderAction * action)
{
  assert(this->opencache);
  this->opencache->close();
  this->itemlist.append(this->opencache);
  this->opencache = NULL;
  SoCacheElement::setInvalid(this->savedinvalid);
}

/*!
  Invalidate all caches in this instance. Should be called
  from the notify() method of nodes doing caching.
*/
void
SoGLCacheList::invalidateAll(void)
{
  int n = this->itemlist.getLength();
  for (int i = 0; i < n; i++) {
    this->itemlist[i]->invalidate();
  }
}
