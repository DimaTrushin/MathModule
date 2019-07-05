#pragma once
/* find supported instruction set
return value:
0           = 80386 instruction set
1  or above = SSE (XMM) supported by CPU (not testing for O.S. support)
2  or above = SSE2
3  or above = SSE3
4  or above = Supplementary SSE3 (SSSE3)
5  or above = SSE4.1
6  or above = SSE4.2
7  or above = AVX supported by CPU and operating system
8  or above = AVX2
9  or above = AVX512F
10 or above = AVX512VL
11 or above = AVX512BW, AVX512DQ
*/

struct CInstrLevel {
  using type = int;
  enum : type {
    IL80386 = 0,
    Default = IL80386,
    SSE = 1,
    SSE2 = 2,
    SSE3 = 3,
    SSSE3 = 4,
    SSE4_1 = 5,
    SSE4_2 = 6,
    AVX = 7,
    AVX2 = 8,
    AVX512F = 9,
    AVX512VL = 10,
    AVX512BW = 11,
    AVX512DQ = AVX512BW
  };
};
