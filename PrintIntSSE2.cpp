#include <iostream>
#include "PrintInt.h"
#define MAX_VECTOR_SIZE 512
#include "vectorclass\vectorclass.h"

// This file must be compiled with SSE2 level of simd
void PrintInt::printSSE2(int arg) {
  std::cout << "printSSE2(" << arg << ")" << std::endl;
}
