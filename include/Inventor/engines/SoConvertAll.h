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

#ifndef __SOCONVERTALL_H__
#define __SOCONVERTALL_H__

#include <Inventor/engines/SoFieldConverter.h>
#include <Inventor/SbDict.h>
#include <Inventor/engines/SoEngineOutput.h>


class SoConvertAll : public SoFieldConverter {
  typedef SoFieldConverter inherited;
  SO_ENGINE_ABSTRACT_HEADER(SoConvertAll);

public:
  SoField * input;
  SoEngineOutput output;

  static void initClass();
  SoConvertAll(const SoType fromType, const SoType toType);

protected:
  virtual ~SoConvertAll();
  virtual void evaluate();
  virtual SoField * getInput(SoType type);
  virtual SoEngineOutput * getOutput(SoType type);

private:
//   void convert2String();
//   void convertFromString();
//   void convertScalar();

  SoType fromType, toType;

};

#endif // !__SOCONVERTALL_H__
