#include <iostream>
#include "PrintInt.h"
#define MAX_VECTOR_SIZE 512
#include "vectorclass\vectorclass.h"

// This file must be compiled with AVX level of simd
void PrintInt::printAVX(int arg) {
  std::cout << "printAVX(" << arg << ")" << std::endl;
}
