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

#ifndef __SOLIGHTATTENUATIONELEMENT_H__
#define __SOLIGHTATTENUATIONELEMENT_H__

#include <Inventor/elements/SoReplacedElement.h>
#include <Inventor/SbVec3f.h>


class SoLightAttenuationElement : public SoReplacedElement {
  typedef SoReplacedElement inherited;

  SO_ELEMENT_HEADER(SoLightAttenuationElement);
public:
  static void initClass(void);
protected:
  virtual ~SoLightAttenuationElement();

public:
  virtual void init(SoState * state);

  static void set(SoState * const state, SoNode * const node,
                  const SbVec3f & lightAttenuation);
  static const SbVec3f &get(SoState * const state);
  static const SbVec3f & getDefault();

  virtual SbBool matches(SoElement * element) const;
  virtual SoElement *copyMatchInfo() const;

  virtual void print(FILE * file) const;

protected:
  SbVec3f lightAttenuation;
  static const SbVec3f defaultAttenuation;

};

#endif // !__SOLIGHTATTENUATIONELEMENT_H__
