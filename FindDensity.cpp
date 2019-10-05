#include <vector>
#include "FindDensity.h"


using Selector = NSLibrary::Selector;
using IL = CInstrLevel;


FindDensity::FindDensity(int instruction_level)
    : CBase(&find_densityAVX, &find_densitySSE2, &find_density, instruction_level) {
}


void FindDensity::find_density(
  const std::vector<double> &arg,
  const std::vector<double> &mean,
  const std::vector<double> &dev,
  std::vector<double> &results
  ) {
  for (size_t i = 0; i != arg.size(); ++i) {
    results[i] = 0;
    for (size_t j = 0; j != mean.size(); ++j) {
      results[i] += find_derivative_2<double>(arg[i], mean[j], dev[j]);
    }
    results /= static_cast<double>(mean.size());
  }
}
