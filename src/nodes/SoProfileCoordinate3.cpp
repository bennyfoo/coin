/**************************************************************************\
 *
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

/*!
  \class SoProfileCoordinate3 SoProfileCoordinate3.h Inventor/nodes/SoProfileCoordinate3.h
  \brief The SoProfileCoordinate3 class ...
  \ingroup nodes

  FIXME: write class doc
*/

#include <Inventor/nodes/SoProfileCoordinate3.h>

#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/actions/SoPickAction.h>
#include <Inventor/elements/SoProfileCoordinateElement.h>
#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/actions/SoGetPrimitiveCountAction.h>

/*!
  \var SoMFVec3f SoProfileCoordinate3::point
  FIXME: write documentation for field
*/

// *************************************************************************

SO_NODE_SOURCE(SoProfileCoordinate3);

/*!
  Constructor.
*/
SoProfileCoordinate3::SoProfileCoordinate3()
{
  SO_NODE_INTERNAL_CONSTRUCTOR(SoProfileCoordinate3);

  SO_NODE_ADD_FIELD(point, (0.0f, 0.0f, 1.0f));
}

/*!
  Destructor.
*/
SoProfileCoordinate3::~SoProfileCoordinate3()
{
}

/*!
  Does initialization common for all objects of the
  SoProfileCoordinate3 class. This includes setting up the
  type system, among other things.
*/
void
SoProfileCoordinate3::initClass(void)
{
  SO_NODE_INTERNAL_INIT_CLASS(SoProfileCoordinate3);

  SO_ENABLE(SoGLRenderAction, SoProfileCoordinateElement);
  SO_ENABLE(SoPickAction, SoProfileCoordinateElement);
  SO_ENABLE(SoCallbackAction, SoProfileCoordinateElement);
  SO_ENABLE(SoGetPrimitiveCountAction, SoProfileCoordinateElement);
}

/*!
  FIXME: write doc
 */
void
SoProfileCoordinate3::doAction(SoAction *action)
{
  SoProfileCoordinateElement::set3(action->getState(), this,
                                   point.getNum(), point.getValues(0));
}

/*!
  FIXME: write doc
 */
void
SoProfileCoordinate3::GLRender(SoGLRenderAction *action)
{
  SoProfileCoordinate3::doAction(action);
}

/*!
  FIXME: write doc
 */
void
SoProfileCoordinate3::callback(SoCallbackAction *action)
{
  SoProfileCoordinate3::doAction(action);
}

/*!
  FIXME: write doc
 */
void
SoProfileCoordinate3::pick(SoPickAction *action)
{
  SoProfileCoordinate3::doAction(action);
}

/*!
  FIXME: write doc
 */
void
SoProfileCoordinate3::getPrimitiveCount(SoGetPrimitiveCountAction *action)
{
  SoProfileCoordinate3::doAction(action);
}
