#pragma once

#include <vector>
#include "Library\FunctionModuleBase.h"
#include "InstructionLevels.h"


using FindDensityBase =
  NSLibrary::FunctionModuleBase<void(const std::vector<double> &,
                                     std::vector<double>&),
                                CInstrLevel::AVX,
                                CInstrLevel::SSE2>;

class FindDensity :
  public FindDensityBase {
  using CBase = FindDensityBase;
public:
  FindDensity(int instruction_level);

private:
  static void find_densityAVX(const std::vector<double> &input,
                              std::vector<double> &output);

  static void find_densitySSE2(const std::vector<double> &input,
                               std::vector<double> &output);

  static void find_density(const std::vector<double> &input,
                           std::vector<double> &output);
};