#pragma once
#include "SimdDetector.h"
#include "PrintInt.h"
//--------------------------------------------------------------------------------
// MathModuleBase
//--------------------------------------------------------------------------------

class MathModuleBase {
public:
  int getSimdLevel() const;
private:
  SimdDetector SimdDetector_;
};
//--------------------------------------------------------------------------------
// MathModule
//--------------------------------------------------------------------------------
// MathModule provide a convinient way of using math functions
// It uses automatic CPU dispatching mechanism to determine and set
// an appropriate level of SIMD instructions
// For each function, say, print(int) as below, we must provide:
// 1) The public function itself in order to access it via MathModule
// 2) The dispatching object, e.g. PrintInt PrintInt_
//    This object must be derived from FunctionModeulBase template
//    and provide all the required functionality
// 3) We must call the constructor of the dispatching object in
//    the constructor of MathModule with getSimdLevel() value
//--------------------------------------------------------------------------------

class MathModule : public MathModuleBase {
public:
  MathModule();
  void print(int arg) const;
private:
  PrintInt PrintInt_;
};
//--------------------------------------------------------------------------------
