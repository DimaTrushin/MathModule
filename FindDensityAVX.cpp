#include "FindDensity.h"
#include <vector>
#define MAX_VECTOR_SIZE 512
#include "vectorclass/vectorclass.h"

// This file must be compiled with AVX level of simd
void FindDensity::find_densityAVX(
  const std::vector<double> &arg,
  const std::vector<double> &mean,
  const std::vector<double> &dev,
  std::vector<double> &results
) {
  find_density_template<Vec4d>(arg, mean, dev, results, 4);
}
