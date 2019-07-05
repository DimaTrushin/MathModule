#include "SimdDetector.h"
#include "vectorclass\instrset.h"
//--------------------------------------------------------------------------------
// SimdDetector
//--------------------------------------------------------------------------------

SimdDetector::SimdDetector()
  : InstructionLevel_(instrset_detect()) {
}

int SimdDetector::level() const {
  return InstructionLevel_;
}
//--------------------------------------------------------------------------------
