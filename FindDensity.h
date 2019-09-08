#pragma once

#include <vector>
#include "Library\FunctionModuleBase.h"
#include "InstructionLevels.h"
#include "Library/FindDerivative.h"


template<typename T>
void find_density_template(
  const std::vector<double> &arg,
  const std::vector<double> &mean,
  const std::vector<double> &dev,
  std::vector<double> &results,
  int shift
) {
  for (size_t i = 0; i < arg.size(); i += shift) {
    T current_result(0);
    T current_arg;
    current_arg.load(&arg[i]);

    for (size_t j = 0; j < mean.size(); j += shift) {
      T current_mean, current_deviation;
      current_mean.load(&mean[j]);
      current_deviation.load(&dev[j]);

      current_result = find_derivative_2<T>(current_arg, current_mean, current_deviation)
    }

    current_result /= static_cast<double>(mean.size());
    current_result.store(&output[i]);
  }
}


using FindDensityBase =
  NSLibrary::FunctionModuleBase<
    void(
      const std::vector<double> &,
      const std::vector<double> &,
      const std::vector<double> &,
      std::vector<double>&
    ),
    CInstrLevel::AVX,
    CInstrLevel::SSE2>;

class FindDensity :
  public FindDensityBase {
  using CBase = FindDensityBase;
public:
  FindDensity(int instruction_level);

private:
  static void find_densityAVX(
    const std::vector<double> &,
    const std::vector<double> &,
    const std::vector<double> &,
    std::vector<double> &);

  static void find_densitySSE2(
    const std::vector<double> &,
    const std::vector<double> &,
    const std::vector<double> &,
    std::vector<double> &);

  static void find_density(
    const std::vector<double> &,
    const std::vector<double> &,
    const std::vector<double> &,
    std::vector<double> &);
};