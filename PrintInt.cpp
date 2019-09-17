#include "PrintInt.h"
#include <iostream>
//--------------------------------------------------------------------------------
// PrintInt
//--------------------------------------------------------------------------------

// We must send function with respect to decreasing of their simd level
// So, the default non-simd function goes last
// the last parameter must be the instruction_level
// that is the argument of the constructor
PrintInt::PrintInt(int instruction_level)
  : CBase(&printAVX, &printSSE2, &print, instruction_level) {
}

// This function does not need simd instructions
// So, it is OK to define it here
void PrintInt::print(int arg) {
  std::cout << "print(" << arg << ")" << std::endl;
}
