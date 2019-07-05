#include <iostream>
#include "PrintInt.h"
#include "InstructionLevels.h"
#include "MathModule.h"

int main() {
  // Here is an example of how the dispatcher of functions work
  // We set simd level to level 5 in this case
  PrintInt Printer(5);
  // Then we call the Functor object on element 4
  // It will print the number 4 using SSE2 version (if the level is 5)
  Printer(4);

  // Create Math Module
  // It automatically detects the simd level on the current machine
  MathModule Math;
  // Check Simd level on this computer
  std::cout << "Simd Level = " << Math.getSimdLevel() << std::endl;
  // call print method using dispatching mechanism
  Math.print(5);

  system("pause");
  return 0;
}