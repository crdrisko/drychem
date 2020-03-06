// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAllConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:31:45
// Description: Run all the conversion tests with googletest

#include <gtest/gtest.h>

#include "AmountOfSubstance/testAmountOfSubstanceConversionFunctions.hpp"
#include "Angle/testAngleConversionFunctions.hpp"
#include "Area/testAreaConversionFunctions.hpp"
#include "ElectricCharge/testElectricChargeConversionFunctions.hpp"
#include "Energy/testEnergyConversionFunctions.hpp"
#include "Length/testLengthConversionFunctions.hpp"
#include "MagneticFluxDensity/testMagneticFluxDensityConversionFunctions.hpp"
#include "Mass/testMassConversionFunctions.hpp"
#include "MolarEnergy/testMolarEnergyConversionFunctions.hpp"
#include "Pressure/testPressureConversionFunctions.hpp"
#include "SI_UnitPrefixes/testSI_UnitPrefixesConversionFunctions.hpp"
#include "Temperature/testTemperatureConversionFunctions.hpp"
#include "Time/testTimeConversionFunctions.hpp"
#include "Volume/testVolumeConversionFunctions.hpp"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
