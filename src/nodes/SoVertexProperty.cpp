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
  \class SoVertexProperty SoVertexProperty.h Inventor/nodes/SoVertexProperty.h
  \brief The SoVertexProperty class ...
  \ingroup nodes

  FIXME: write class doc
*/


//
// FIXME: this class is really not correctly implemented. Each
// vertex shape node should support this node internally.
// Right now we just push its values on the stack.
//

#include <Inventor/nodes/SoVertexProperty.h>


#include <Inventor/actions/SoGetBoundingBoxAction.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/actions/SoPickAction.h>
#include <Inventor/actions/SoCallbackAction.h>

#include <Inventor/actions/SoGetPrimitiveCountAction.h>

#include <Inventor/elements/SoCoordinateElement.h>
#include <Inventor/elements/SoGLCoordinateElement.h>
#include <Inventor/elements/SoMaterialBindingElement.h>
#include <Inventor/elements/SoNormalBindingElement.h>
#include <Inventor/elements/SoGLNormalElement.h>
#include <Inventor/elements/SoGLTextureCoordinateElement.h>
#include <Inventor/elements/SoDiffuseColorElement.h>
#include <Inventor/elements/SoOverrideElement.h>
#include <Inventor/elements/SoGLShadeModelElement.h>

/*!
  \enum SoVertexProperty::Binding
  FIXME: write documentation for enum
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::OVERALL
  FIXME: write documentation for enum definition
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::PER_PART
  FIXME: write documentation for enum definition
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::PER_PART_INDEXED
  FIXME: write documentation for enum definition
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::PER_FACE
  FIXME: write documentation for enum definition
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::PER_FACE_INDEXED
  FIXME: write documentation for enum definition
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::PER_VERTEX
  FIXME: write documentation for enum definition
*/
/*!
  \var SoVertexProperty::Binding SoVertexProperty::PER_VERTEX_INDEXED
  FIXME: write documentation for enum definition
*/


/*!
  \var SoMFVec3f SoVertexProperty::vertex
  FIXME: write documentation for field
*/
/*!
  \var SoMFVec2f SoVertexProperty::texCoord
  FIXME: write documentation for field
*/
/*!
  \var SoMFVec3f SoVertexProperty::normal
  FIXME: write documentation for field
*/
/*!
  \var SoSFEnum SoVertexProperty::normalBinding
  FIXME: write documentation for field
*/
/*!
  \var SoMFUInt32 SoVertexProperty::orderedRGBA
  FIXME: write documentation for field
*/
/*!
  \var SoSFEnum SoVertexProperty::materialBinding
  FIXME: write documentation for field
*/


SO_NODE_SOURCE(SoVertexProperty);

/*!
  Constructor.
*/
SoVertexProperty::SoVertexProperty()
{
  SO_NODE_INTERNAL_CONSTRUCTOR(SoVertexProperty);

  SO_NODE_ADD_FIELD(vertex, (0));
  SO_NODE_ADD_FIELD(normal, (0));
  SO_NODE_ADD_FIELD(texCoord, (0));
  SO_NODE_ADD_FIELD(orderedRGBA, (0));
  // FIXME: is this the correct way of making empty multifields?
  // 19990301 mortene.
  vertex.setNum(0);
  texCoord.setNum(0);
  normal.setNum(0);
  orderedRGBA.setNum(0);

  SO_NODE_ADD_FIELD(normalBinding, (SoVertexProperty::PER_VERTEX_INDEXED));
  SO_NODE_ADD_FIELD(materialBinding, (SoVertexProperty::OVERALL));

  SO_NODE_DEFINE_ENUM_VALUE(Binding, OVERALL);
  SO_NODE_DEFINE_ENUM_VALUE(Binding, PER_PART);
  SO_NODE_DEFINE_ENUM_VALUE(Binding, PER_PART_INDEXED);
  SO_NODE_DEFINE_ENUM_VALUE(Binding, PER_FACE);
  SO_NODE_DEFINE_ENUM_VALUE(Binding, PER_FACE_INDEXED);
  SO_NODE_DEFINE_ENUM_VALUE(Binding, PER_VERTEX);
  SO_NODE_DEFINE_ENUM_VALUE(Binding, PER_VERTEX_INDEXED);

  SO_NODE_SET_SF_ENUM_TYPE(normalBinding, Binding);
  SO_NODE_SET_SF_ENUM_TYPE(materialBinding, Binding);
}

/*!
  Destructor.
*/
SoVertexProperty::~SoVertexProperty()
{
}

/*!
  Does initialization common for all objects of the
  SoVertexProperty class. This includes setting up the
  type system, among other things.
*/
void
SoVertexProperty::initClass()
{
  SO_NODE_INTERNAL_INIT_CLASS(SoVertexProperty);

  SO_ENABLE(SoGetBoundingBoxAction, SoCoordinateElement);

  SO_ENABLE(SoGLRenderAction, SoGLCoordinateElement);
  SO_ENABLE(SoGLRenderAction, SoMaterialBindingElement);
  SO_ENABLE(SoGLRenderAction, SoNormalBindingElement);
  SO_ENABLE(SoGLRenderAction, SoGLNormalElement);
  SO_ENABLE(SoGLRenderAction, SoGLTextureCoordinateElement);

  SO_ENABLE(SoPickAction, SoCoordinateElement);
  SO_ENABLE(SoPickAction, SoMaterialBindingElement);
  SO_ENABLE(SoPickAction, SoNormalBindingElement);
  SO_ENABLE(SoPickAction, SoNormalElement);
  SO_ENABLE(SoPickAction, SoTextureCoordinateElement);

  SO_ENABLE(SoCallbackAction, SoCoordinateElement);
  SO_ENABLE(SoCallbackAction, SoMaterialBindingElement);
  SO_ENABLE(SoCallbackAction, SoNormalBindingElement);
  SO_ENABLE(SoCallbackAction, SoNormalElement);
  SO_ENABLE(SoCallbackAction, SoTextureCoordinateElement);

  SO_ENABLE(SoGetPrimitiveCountAction, SoCoordinateElement);
  SO_ENABLE(SoGetPrimitiveCountAction, SoMaterialBindingElement);
  SO_ENABLE(SoGetPrimitiveCountAction, SoNormalBindingElement);
  SO_ENABLE(SoGetPrimitiveCountAction, SoNormalElement);
  SO_ENABLE(SoGetPrimitiveCountAction, SoTextureCoordinateElement);
}

/*!
  FIXME: write function documentation
*/
void
SoVertexProperty::getBoundingBox(SoGetBoundingBoxAction * action)
{
  if (vertex.getNum() > 0) {
    SoCoordinateElement::set3(action->getState(), this,
                              vertex.getNum(), vertex.getValues(0));
  }
}

/*!
  FIXME: write function documentation
*/
void
SoVertexProperty::GLRender(SoGLRenderAction * action)
{
  if (texCoord.getNum() > 0) {
    SoGLTextureCoordinateElement::setTexGen(action->getState(),
                                            this, NULL);
  }

  SoVertexProperty::doAction((SoAction*)action);
  SoState *state = action->getState();
  if (!normalBinding.isIgnored()) {
    Binding binding = (Binding)normalBinding.getValue();
    SoGLShadeModelElement::setNormal(state,
                                     binding == PER_VERTEX ||
                                     binding == PER_VERTEX_INDEXED);
  }
  if (!materialBinding.isIgnored()
      && !SoOverrideElement::getMaterialBindingOverride(state)) {
    Binding binding = (Binding)materialBinding.getValue();
    SoGLShadeModelElement::setMaterial(state,
                                       binding == PER_VERTEX ||
                                       binding == PER_VERTEX_INDEXED);


  }
}

/*!
  FIXME: write doc
 */
void
SoVertexProperty::doAction(SoAction *action)
{
  SoState * state = action->getState();
  if (vertex.getNum() > 0)
    SoCoordinateElement::set3(state, this, vertex.getNum(),
                              vertex.getValues(0));

  if (texCoord.getNum() > 0) {
    SoTextureCoordinateElement::set2(state, this, texCoord.getNum(),
                                     texCoord.getValues(0));
  }
  if (normal.getNum() > 0) {
    SoNormalElement::set(state, this, normal.getNum(),
                         normal.getValues(0));
  }
  if (!normalBinding.isIgnored()
      ) {
    SoNormalBindingElement::set(state, this,
                                (SoNormalBindingElement::Binding)
                                normalBinding.getValue());
  }
  if (orderedRGBA.getNum() > 0
      && !SoOverrideElement::getDiffuseColorOverride(state)) {
    SoDiffuseColorElement::set(state, this, orderedRGBA.getNum(),
                               orderedRGBA.getValues(0));
  }
  if (!materialBinding.isIgnored()
      && !SoOverrideElement::getMaterialBindingOverride(state)) {
    SoMaterialBindingElement::set(state, this,
                                  (SoMaterialBindingElement::Binding)
                                  materialBinding.getValue());
  }
}

/*!
  FIXME: write doc
 */
void
SoVertexProperty::callback(SoCallbackAction *action)
{
  SoVertexProperty::doAction((SoAction*)action);
}

/*!
  FIXME: write doc
 */
void
SoVertexProperty::pick(SoPickAction *action)
{
  SoVertexProperty::doAction((SoAction*)action);
}

/*!
  FIXME: write doc
 */
void
SoVertexProperty::getPrimitiveCount(SoGetPrimitiveCountAction *action)
{
  SoVertexProperty::doAction((SoAction*)action);
}
