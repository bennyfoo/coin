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

#ifndef __SOTEXTURE2_H__
#define __SOTEXTURE2_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFImage.h>
#include <Inventor/fields/SoSFString.h>
#include <Inventor/fields/SoSFColor.h>
#include <Inventor/elements/SoTextureImageElement.h>


class SoTexture2 : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoTexture2);

public:
  static void initClass(void);
  SoTexture2(void);


  SbBool readImage();

  enum Model {
    MODULATE = SoTextureImageElement::MODULATE,
    DECAL = SoTextureImageElement::DECAL,
    BLEND = SoTextureImageElement::BLEND
  };

  enum Wrap {
    REPEAT = SoTextureImageElement::REPEAT,
    CLAMP = SoTextureImageElement::CLAMP
  };

  SoSFString filename;
  SoSFImage image;
  SoSFEnum wrapS;
  SoSFEnum wrapT;
  SoSFEnum model;
  SoSFColor blendColor;

  virtual void doAction(SoAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void callback(SoCallbackAction * action);

  static SbBool readImage(const SbString & fname, int & w, int & h, int & nc,
                          unsigned char *& bytes);

protected:
  virtual ~SoTexture2();

  virtual SbBool readInstance(SoInput * in, unsigned short flags);
  int getReadStatus(void);
  void setReadStatus(int s);

private:
  void getImage();
  class SoImageInterface *imageData;
  class SoGLImage * glImage;
};

#endif // !__SOTEXTURE2_H__
