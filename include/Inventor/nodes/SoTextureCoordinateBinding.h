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

#ifndef __SOTEXTURECOORDINATEBINDING_H__
#define __SOTEXTURECOORDINATEBINDING_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/elements/SoTextureCoordinateBindingElement.h>


class SoTextureCoordinateBinding : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoTextureCoordinateBinding);

public:
  static void initClass(void);
  SoTextureCoordinateBinding(void);

  enum Binding {
    PER_VERTEX = SoTextureCoordinateBindingElement::PER_VERTEX,
    PER_VERTEX_INDEXED = SoTextureCoordinateBindingElement::PER_VERTEX_INDEXED
  };

  SoSFEnum value;

  virtual void doAction(SoAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void pick(SoPickAction * action);

protected:
  virtual ~SoTextureCoordinateBinding();

  virtual SbBool readInstance(SoInput * in, unsigned short flags);
};

#endif // !__SOTEXTURECOORDINATEBINDING_H__
