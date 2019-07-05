#pragma once
#include "Selector.h"
#include "FunctionHelper.h"
#include <utility>

namespace NSLibrary {
//--------------------------------------------------------------------------------
// FunctionModuleBase
//--------------------------------------------------------------------------------

template<class TSignature, class TElementList, class... TFuncs>
class FModeBaseImpl {
  using CSignature = TSignature;
  using CFunctionPtr = CSignature*;
  using LevelList = TElementList;
  using ReturnType = ReturnType<CSignature>;
  static_assert(EL::IsDecreasing<LevelList>::value,
                "Levels must go in decreasing order!");
  static_assert(EL::Length<LevelList>::value + 1 == sizeof...(TFuncs),
                "Incompatible amount of constructor arguments!");
public:
  FModeBaseImpl(TFuncs... funcs, int level)
    : Function_(Selector::
                SetSignature<CSignature>::
                SetLevelsT<TElementList>::
                choose(funcs..., level)) {}

  template<class... TArgs>
  ReturnType operator()(TArgs&&... args) const {
    return Function_(std::forward<TArgs>(args)...);
  }
private:
  CFunctionPtr Function_;
};

template<class TSignature, class TElementList, class TSeq>
struct FModeHelperImpl;

template<class TSignature, class TElementList, class TSeq>
using FModeHelper = typename FModeHelperImpl<TSignature, TElementList, TSeq>::Result;

template<class TSignature, class TElementList, class... TArgs>
struct FModeHelperImpl<TSignature, TElementList, TypeSeq<TArgs...>> {
  using Result = FModeBaseImpl<TSignature, TElementList, TArgs...>;
};

template<class TSignature, class TElementList>
using FModeBase =
  FModeHelper<TSignature,
  TElementList,
  TL::MakeTypeSeqN<TSignature,
  EL::Length<TElementList>::value + 1>>;

template<class TSignature, int... TInts>
using FunctionModuleBase =
  FModeBase<TSignature, EL::MakeElementList<TInts...>>;
//--------------------------------------------------------------------------------
} // NSLibrary
//--------------------------------------------------------------------------------
