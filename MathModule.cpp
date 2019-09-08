#include "MathModule.h"
//--------------------------------------------------------------------------------
// MathModuleBase
//--------------------------------------------------------------------------------

int MathModuleBase::getSimdLevel() const {
  return SimdDetector_.level();
}
//--------------------------------------------------------------------------------
// MathModule
//--------------------------------------------------------------------------------

MathModule::MathModule()
  : PrintInt_(getSimdLevel()) {
}

void MathModule::print(int arg) const {
  return PrintInt_(arg);
}
//--------------------------------------------------------------------------------