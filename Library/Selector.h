#pragma once
#include "ElementList.h"
#include "TypeList.h"

namespace NSLibrary {
//--------------------------------------------------------------------------------
// Selector
//--------------------------------------------------------------------------------
//
// Selector selects a function pointer depending on a level parameter
// How to use:
// Selector::SetSignature<void(int)>::SetLevels<9,3>::choose(&f1, &f2, &fd, 5);
// 1) We select signature of a function void(int) in the example
// 2) We set levels of function (these are the SIMD levels)
//    9 and 3 in the example
// 3) We choose a required function using function choose
//    f1 has level 9
//    f2 has level 3
//    fd is a default function
//    5 is a given level
//    Function chooses the highest possible level of function less or equal to
//    the given level of instructions
//    In the example we will get f2
// Notes:
// 1) f1, f2, fd must be functions of the given signature
// 2) instruction levels must be sorted in decreasing order
// 3) instruction level is unsigned int
//--------------------------------------------------------------------------------

class Selector {
public:
  //--------------------------------------------------------------------------------
  // SetSignature
  //--------------------------------------------------------------------------------

  template<class TSignature>
  class SetSignature {
    using CSignature = TSignature;
    using FunctionPtr = CSignature*;
    //--------------------------------------------------------------------------------
    // SetLevels
    //--------------------------------------------------------------------------------

    template<class TElementList>
    class SetLevelsImpl {
      using LevelList = TElementList;
      static_assert(EL::IsDecreasing<LevelList>::value,
                    "Levels must go in decreasing order!");

      //--------------------------------------------------------------------------------
      // SelectorImpl
      //--------------------------------------------------------------------------------

      template<class... TFunArgs>
      struct SelectorImpl;

      template<class TFunArg, class... TFunArgs>
      struct SelectorImpl<TFunArg, TFunArgs...> {
        static TFunArg choose(TFunArg Fun1, TFunArgs... Funs, int level) {
          if (level >= LevelList::Head)
            return Fun1;
          return SetLevelsImpl<LevelList::Tail>::Selector::choose(Funs..., level);
        }
      };

      template<class TFunArg>
      struct SelectorImpl<TFunArg> {
        static TFunArg choose(TFunArg DefaultFun, int level) {
          return DefaultFun;
        }
      };
      //--------------------------------------------------------------------------------
      // SelectorHelper
      //--------------------------------------------------------------------------------

      template<class TSeq>
      struct SelectorHelper;

      template<class... TTypes>
      struct SelectorHelper<TypeSeq<TTypes...>> {
        using Result = SelectorImpl<TTypes...>;
      };
      //--------------------------------------------------------------------------------
    public:
      using Selector = typename SelectorHelper<TL::MakeTypeSeqN<FunctionPtr, EL::Length<LevelList>::value + 1>>::Result;
    };
    //--------------------------------------------------------------------------------
  public:
    template<int... TInts>
    using SetLevels = typename SetLevelsImpl<EL::MakeElementList<TInts...>>::Selector;
    template<class TElementList>
    using SetLevelsT = typename SetLevelsImpl<TElementList>::Selector;
  };
  //--------------------------------------------------------------------------------
};
//--------------------------------------------------------------------------------
} // NSLibrary
//--------------------------------------------------------------------------------
