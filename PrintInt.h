#pragma once

#include "Library\FunctionModuleBase.h"
#include "InstructionLevels.h"

//--------------------------------------------------------------------------------
// PrintInt
//--------------------------------------------------------------------------------

// We use FunctionModuleBase as base class for PrintInt
// We set Signature of a function and then the level of instructions
// Instruction levels must go in decreasing order
// otherwise you will get compilation error with a message
using PrintIntBase =
  NSLibrary::FunctionModuleBase<void(int), CInstrLevel::AVX, CInstrLevel::SSE2>;

class PrintInt :
  public PrintIntBase {
  using CBase = PrintIntBase;
public:
  // The only thing we need to provide is the constructor
  // see cpp file for the details
  PrintInt(int instruction_level);
private:
  // We must provide a static function of above signature
  // for each instruction level

  // This function must be defined in its own cpp file
  // and compiled on simd level AVX
  static void printAVX(int);
  // This function must be defined in its own cpp file
  // and compiled on simd level SSE2
  static void printSSE2(int);
  // We also provide one extra method for the default case
  // this is basically non-simd version
  static void print(int);
};