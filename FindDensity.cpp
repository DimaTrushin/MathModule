#include <vector>
#include "FindDensity.h"


using Selector = NSLibrary::Selector;
using IL = CInstrLevel;


FindDensity::FindDensity(int instruction_level)
    : CBase(&find_densityAVX, &find_densitySSE2, &find_density, instruction_level) {
}


void FindDensity::find_density(const std::vector<double> &input, std::vector<double> &output) {
  for (size_t i = 0; i != output.size(); ++i) {
    output[i] = 0;
    for (size_t j = 0; j != input.size(); ++j) {
      output[i] += input[j];
    }
  }
}
