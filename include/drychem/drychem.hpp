// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: drychem.hpp
// Author: crdrisko
// Date: 01/15/2025-06:40:33
// Description: The public API for all available sections of the DryChem library. This header file
//   should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_INCLUDE_DRYCHEM_DRYCHEM_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_DRYCHEM_HPP

#include "errors/exceptions/fatalException.hpp"
#include "errors/traits/isFatal.hpp"
#include "errors/utils/errorHandling.hpp"
#include "errors/utils/errorTypes.hpp"
#include "files/fileParsing/fileParser.hpp"
#include "files/fileParsing/parserStrategies/columnStrategy.hpp"
#include "files/fileParsing/parserStrategies/rowStrategy.hpp"
#include "files/utils/fileExceptions.hpp"
#include "math/calculus/differentiation/backwardsDifferenceMethod.hpp"
#include "math/calculus/differentiation/centeredDifferenceMethod.hpp"
#include "math/calculus/differentiation/forwardDifferenceMethod.hpp"
#include "math/calculus/differentiation/nPointStencil.hpp"
#include "math/calculus/integration.hpp"
#include "math/containers/vector3D.hpp"
#include "math/statistics/linearLeastSquaresFitting.hpp"
#include "math/statistics/quadraticLeastSquaresFitting.hpp"
#include "math/statistics/statistics.hpp"
#include "math/utils/basicMath.hpp"
#include "math/utils/mathExceptions.hpp"
#include "meta/algorithms/basicAlgorithms.hpp"
#include "meta/algorithms/reverseList.hpp"
#include "meta/traits/containerTraits.hpp"
#include "meta/types/integer_sequences/integerSequenceAlgorithms.hpp"
#include "meta/types/tuples/tupleAlgorithms.hpp"
#include "strings/traits/ciString.hpp"
#include "strings/utils/ctStringHashing.hpp"
#include "strings/utils/lexicalCast.hpp"
#include "strings/utils/stringUtils.hpp"
#include "strings/utils/tokenizer.hpp"
#include "utilities/operators/comparisonOperators.hpp"
#include "utilities/operators/potentiallyEmptyBaseClass.hpp"
#include "utilities/testing/performanceTesting.hpp"

#endif
