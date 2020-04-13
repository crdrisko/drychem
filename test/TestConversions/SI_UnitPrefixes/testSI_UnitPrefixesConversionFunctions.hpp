// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testSI_UnitPrefixesConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all si unit prefix conversion functions

#ifndef TESTSI_UNITPREFIXESCONVERSIONFUNCTIONS_HPP
#define TESTSI_UNITPREFIXESCONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_yotta)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "yotta").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "zetta").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "exa").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "peta").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "tera").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "giga").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "mega").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "kilo").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "hecto").isConvertedTo(1e22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "deka").isConvertedTo(1e23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "base").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "deci").isConvertedTo(1e25);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "centi").isConvertedTo(1e26);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "milli").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "micro").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "nano").isConvertedTo(1e33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "pico").isConvertedTo(1e36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "femto").isConvertedTo(1e39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "atto").isConvertedTo(1e42);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "zepto").isConvertedTo(1e45);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yotta", "yocto").isConvertedTo(1e48);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_zetta)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "yotta").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "zetta").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "exa").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "peta").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "tera").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "giga").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "mega").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "kilo").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "hecto").isConvertedTo(1e19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "deka").isConvertedTo(1e20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "base").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "deci").isConvertedTo(1e22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "centi").isConvertedTo(1e23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "milli").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "micro").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "nano").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "pico").isConvertedTo(1e33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "femto").isConvertedTo(1e36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "atto").isConvertedTo(1e39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "zepto").isConvertedTo(1e42);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zetta", "yocto").isConvertedTo(1e45);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_exa)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "yotta").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "zetta").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "exa").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "peta").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "tera").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "giga").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "mega").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "kilo").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "hecto").isConvertedTo(1e16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "deka").isConvertedTo(1e17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "base").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "deci").isConvertedTo(1e19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "centi").isConvertedTo(1e20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "milli").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "micro").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "nano").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "pico").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "femto").isConvertedTo(1e33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "atto").isConvertedTo(1e36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "zepto").isConvertedTo(1e39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("exa", "yocto").isConvertedTo(1e42);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_peta)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "yotta").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "zetta").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "exa").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "peta").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "tera").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "giga").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "mega").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "kilo").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "hecto").isConvertedTo(1e13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "deka").isConvertedTo(1e14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "base").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "deci").isConvertedTo(1e16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "centi").isConvertedTo(1e17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "milli").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "micro").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "nano").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "pico").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "femto").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "atto").isConvertedTo(1e33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "zepto").isConvertedTo(1e36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("peta", "yocto").isConvertedTo(1e39);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_tera)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "yotta").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "zetta").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "exa").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "peta").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "tera").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "giga").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "mega").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "kilo").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "hecto").isConvertedTo(1e10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "deka").isConvertedTo(1e11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "base").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "deci").isConvertedTo(1e13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "centi").isConvertedTo(1e14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "milli").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "micro").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "nano").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "pico").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "femto").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "atto").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "zepto").isConvertedTo(1e33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("tera", "yocto").isConvertedTo(1e36);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_giga)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "yotta").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "zetta").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "exa").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "peta").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "tera").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "giga").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "mega").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "kilo").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "hecto").isConvertedTo(1e7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "deka").isConvertedTo(1e8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "base").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "deci").isConvertedTo(1e10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "centi").isConvertedTo(1e11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "milli").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "micro").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "nano").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "pico").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "femto").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "atto").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "zepto").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("giga", "yocto").isConvertedTo(1e33);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_mega)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "yotta").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "zetta").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "exa").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "peta").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "tera").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "giga").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "mega").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "kilo").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "hecto").isConvertedTo(1e4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "deka").isConvertedTo(1e5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "base").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "deci").isConvertedTo(1e7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "centi").isConvertedTo(1e8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "milli").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "micro").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "nano").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "pico").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "femto").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "atto").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "zepto").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("mega", "yocto").isConvertedTo(1e30);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_kilo)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "yotta").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "zetta").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "exa").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "peta").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "tera").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "giga").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "mega").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "kilo").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "hecto").isConvertedTo(1e1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "deka").isConvertedTo(1e2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "base").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "deci").isConvertedTo(1e4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "centi").isConvertedTo(1e5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "milli").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "micro").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "nano").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "pico").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "femto").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "atto").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "zepto").isConvertedTo(1e24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("kilo", "yocto").isConvertedTo(1e27);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_hecto)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "yotta").isConvertedTo(1e-22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "zetta").isConvertedTo(1e-19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "exa").isConvertedTo(1e-16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "peta").isConvertedTo(1e-13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "tera").isConvertedTo(1e-10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "giga").isConvertedTo(1e-7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "mega").isConvertedTo(1e-4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "kilo").isConvertedTo(1e-1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "hecto").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "deka").isConvertedTo(1e1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "base").isConvertedTo(1e2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "deci").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "centi").isConvertedTo(1e4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "milli").isConvertedTo(1e5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "micro").isConvertedTo(1e8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "nano").isConvertedTo(1e11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "pico").isConvertedTo(1e14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "femto").isConvertedTo(1e17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "atto").isConvertedTo(1e20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "zepto").isConvertedTo(1e23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("hecto", "yocto").isConvertedTo(1e26);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_deka)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "yotta").isConvertedTo(1e-23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "zetta").isConvertedTo(1e-20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "exa").isConvertedTo(1e-17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "peta").isConvertedTo(1e-14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "tera").isConvertedTo(1e-11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "giga").isConvertedTo(1e-8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "mega").isConvertedTo(1e-5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "kilo").isConvertedTo(1e-2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "hecto").isConvertedTo(1e-1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "deka").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "base").isConvertedTo(1e1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "deci").isConvertedTo(1e2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "centi").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "milli").isConvertedTo(1e4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "micro").isConvertedTo(1e7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "nano").isConvertedTo(1e10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "pico").isConvertedTo(1e13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "femto").isConvertedTo(1e16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "atto").isConvertedTo(1e19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "zepto").isConvertedTo(1e22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deka", "yocto").isConvertedTo(1e25);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_base)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "yotta").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "zetta").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "exa").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "peta").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "tera").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "giga").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "mega").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "kilo").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "hecto").isConvertedTo(1e-2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "deka").isConvertedTo(1e-1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "base").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "deci").isConvertedTo(1e1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "centi").isConvertedTo(1e2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "milli").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "micro").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "nano").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "pico").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "femto").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "atto").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "zepto").isConvertedTo(1e21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("base", "yocto").isConvertedTo(1e24);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_deci)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "yotta").isConvertedTo(1e-25);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "zetta").isConvertedTo(1e-22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "exa").isConvertedTo(1e-19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "peta").isConvertedTo(1e-16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "tera").isConvertedTo(1e-13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "giga").isConvertedTo(1e-10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "mega").isConvertedTo(1e-7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "kilo").isConvertedTo(1e-4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "hecto").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "deka").isConvertedTo(1e-2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "base").isConvertedTo(1e-1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "deci").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "centi").isConvertedTo(1e1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "milli").isConvertedTo(1e2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "micro").isConvertedTo(1e5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "nano").isConvertedTo(1e8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "pico").isConvertedTo(1e11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "femto").isConvertedTo(1e14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "atto").isConvertedTo(1e17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "zepto").isConvertedTo(1e20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("deci", "yocto").isConvertedTo(1e23);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_centi)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "yotta").isConvertedTo(1e-26);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "zetta").isConvertedTo(1e-23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "exa").isConvertedTo(1e-20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "peta").isConvertedTo(1e-17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "tera").isConvertedTo(1e-14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "giga").isConvertedTo(1e-11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "mega").isConvertedTo(1e-8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "kilo").isConvertedTo(1e-5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "hecto").isConvertedTo(1e-4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "deka").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "base").isConvertedTo(1e-2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "deci").isConvertedTo(1e-1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "centi").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "milli").isConvertedTo(1e1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "micro").isConvertedTo(1e4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "nano").isConvertedTo(1e7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "pico").isConvertedTo(1e10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "femto").isConvertedTo(1e13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "atto").isConvertedTo(1e16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "zepto").isConvertedTo(1e19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("centi", "yocto").isConvertedTo(1e22);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_milli)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "yotta").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "zetta").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "exa").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "peta").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "tera").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "giga").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "mega").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "kilo").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "hecto").isConvertedTo(1e-5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "deka").isConvertedTo(1e-4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "base").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "deci").isConvertedTo(1e-2);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "centi").isConvertedTo(1e-1);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "milli").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "micro").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "nano").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "pico").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "femto").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "atto").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "zepto").isConvertedTo(1e18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("milli", "yocto").isConvertedTo(1e21);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_micro)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "yotta").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "zetta").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "exa").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "peta").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "tera").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "giga").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "mega").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "kilo").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "hecto").isConvertedTo(1e-8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "deka").isConvertedTo(1e-7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "base").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "deci").isConvertedTo(1e-5);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "centi").isConvertedTo(1e-4);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "milli").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "micro").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "nano").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "pico").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "femto").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "atto").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "zepto").isConvertedTo(1e15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("micro", "yocto").isConvertedTo(1e18);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_nano)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "yotta").isConvertedTo(1e-33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "zetta").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "exa").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "peta").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "tera").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "giga").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "mega").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "kilo").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "hecto").isConvertedTo(1e-11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "deka").isConvertedTo(1e-10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "base").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "deci").isConvertedTo(1e-8);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "centi").isConvertedTo(1e-7);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "milli").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "micro").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "nano").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "pico").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "femto").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "atto").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "zepto").isConvertedTo(1e12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("nano", "yocto").isConvertedTo(1e15);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_pico)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "yotta").isConvertedTo(1e-36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "zetta").isConvertedTo(1e-33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "exa").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "peta").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "tera").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "giga").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "mega").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "kilo").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "hecto").isConvertedTo(1e-14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "deka").isConvertedTo(1e-13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "base").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "deci").isConvertedTo(1e-11);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "centi").isConvertedTo(1e-10);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "milli").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "micro").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "nano").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "pico").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "femto").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "atto").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "zepto").isConvertedTo(1e9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("pico", "yocto").isConvertedTo(1e12);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_femto)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "yotta").isConvertedTo(1e-39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "zetta").isConvertedTo(1e-36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "exa").isConvertedTo(1e-33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "peta").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "tera").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "giga").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "mega").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "kilo").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "hecto").isConvertedTo(1e-17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "deka").isConvertedTo(1e-16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "base").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "deci").isConvertedTo(1e-14);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "centi").isConvertedTo(1e-13);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "milli").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "micro").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "nano").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "pico").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "femto").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "atto").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "zepto").isConvertedTo(1e6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("femto", "yocto").isConvertedTo(1e9);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_atto)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "yotta").isConvertedTo(1e-42);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "zetta").isConvertedTo(1e-39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "exa").isConvertedTo(1e-36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "peta").isConvertedTo(1e-33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "tera").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "giga").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "mega").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "kilo").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "hecto").isConvertedTo(1e-20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "deka").isConvertedTo(1e-19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "base").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "deci").isConvertedTo(1e-17);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "centi").isConvertedTo(1e-16);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "milli").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "micro").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "nano").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "pico").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "femto").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "atto").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "zepto").isConvertedTo(1e3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("atto", "yocto").isConvertedTo(1e6);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_zepto)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "yotta").isConvertedTo(1e-45);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "zetta").isConvertedTo(1e-42);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "exa").isConvertedTo(1e-39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "peta").isConvertedTo(1e-36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "tera").isConvertedTo(1e-33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "giga").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "mega").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "kilo").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "hecto").isConvertedTo(1e-23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "deka").isConvertedTo(1e-22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "base").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "deci").isConvertedTo(1e-20);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "centi").isConvertedTo(1e-19);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "milli").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "micro").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "nano").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "pico").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "femto").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "atto").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "zepto").isConvertedTo(1e0);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("zepto", "yocto").isConvertedTo(1e3);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_yocto)
{
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "yotta").isConvertedTo(1e-48);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "zetta").isConvertedTo(1e-45);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "exa").isConvertedTo(1e-42);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "peta").isConvertedTo(1e-39);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "tera").isConvertedTo(1e-36);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "giga").isConvertedTo(1e-33);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "mega").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "kilo").isConvertedTo(1e-27);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "hecto").isConvertedTo(1e-26);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "deka").isConvertedTo(1e-25);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "base").isConvertedTo(1e-24);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "deci").isConvertedTo(1e-23);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "centi").isConvertedTo(1e-22);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "milli").isConvertedTo(1e-21);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "micro").isConvertedTo(1e-18);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "nano").isConvertedTo(1e-15);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "pico").isConvertedTo(1e-12);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "femto").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "atto").isConvertedTo(1e-6);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "zepto").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::DimensionlessQuantity>("yocto", "yocto").isConvertedTo(1e0);
}

GTEST_TEST(testSI_UnitPrefixesConversionFunctions, SI_UnitPrefixesWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::DimensionlessQuantity value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("y", "femto");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\ty is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("yocto", "f");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tf is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("yocto", "Ang");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
