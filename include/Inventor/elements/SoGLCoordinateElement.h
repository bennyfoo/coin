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

#ifndef __SOGLCOORDINATEELEMENT_H__
#define __SOGLCOORDINATEELEMENT_H__

#include <Inventor/elements/SoCoordinateElement.h>


class SoGLCoordinateElement : public SoCoordinateElement {
  typedef SoCoordinateElement inherited;

  SO_ELEMENT_HEADER(SoGLCoordinateElement);
public:
  static void initClass(void);
protected:
  virtual ~SoGLCoordinateElement();

public:
  const SbVec3f *getPtr3() const;
  const SbVec4f *getPtr4() const;
  void send(const int index) const;

};

#endif // !__SOGLCOORDINATEELEMENT_H__
