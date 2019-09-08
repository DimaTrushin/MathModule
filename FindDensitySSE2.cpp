#include "FindDensity.h"
#include <vector>
#define MAX_VECTOR_SIZE 512
#include "vectorclass/vectorclass.h"

// This file must be compiled with SSE2 level of simd
void FindDensity::find_densitySSE2(
  const std::vector<double> &arg,
  const std::vector<double> &mean,
  const std::vector<double> &dev,
  std::vector<double> &results
) {
  find_density_template<Vec2d>(arg, mean, dev, results, 2);
}
