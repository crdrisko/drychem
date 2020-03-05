// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testSI_UnitPrefixesConversionFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 03/05/2020-08:54:51
// Description: Provides 100% unit test coverage over all SI unit prefix conversion functions

#include "../testAssertions.hpp"
#include "../../../include/physicalQuantities.hpp"

using namespace PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


long double ConversionAssert::doConversion() const
{
    DimensionlessQuantity dimensionlessQuantity(1.0);

    DimensionlessQuantity convertedValue 
        = dimensionlessQuantity.convertQuantity(Conversions::getSIPrefixConversionFactor(initialUnits, finalUnits));

    return convertedValue.getMagnitude();
}


TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_yotta)
{
    assertThat("yotta", "yotta").isConvertedTo(1e0);
    assertThat("yotta", "zetta").isConvertedTo(1e3);
    assertThat("yotta", "exa").isConvertedTo(1e6);
    assertThat("yotta", "peta").isConvertedTo(1e9);
    assertThat("yotta", "tera").isConvertedTo(1e12);
    assertThat("yotta", "giga").isConvertedTo(1e15);
    assertThat("yotta", "mega").isConvertedTo(1e18);
    assertThat("yotta", "kilo").isConvertedTo(1e21);
    assertThat("yotta", "hecto").isConvertedTo(1e22);
    assertThat("yotta", "deka").isConvertedTo(1e23);
    assertThat("yotta", "base").isConvertedTo(1e24);
    assertThat("yotta", "deci").isConvertedTo(1e25);
    assertThat("yotta", "centi").isConvertedTo(1e26);
    assertThat("yotta", "milli").isConvertedTo(1e27);
    assertThat("yotta", "micro").isConvertedTo(1e30);
    assertThat("yotta", "nano").isConvertedTo(1e33);
    assertThat("yotta", "pico").isConvertedTo(1e36);
    assertThat("yotta", "femto").isConvertedTo(1e39);
    assertThat("yotta", "atto").isConvertedTo(1e42);
    assertThat("yotta", "zepto").isConvertedTo(1e45);
    assertThat("yotta", "yocto").isConvertedTo(1e48);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_zetta)
{
    assertThat("zetta", "yotta").isConvertedTo(1e-3);
    assertThat("zetta", "zetta").isConvertedTo(1e0);
    assertThat("zetta", "exa").isConvertedTo(1e3);
    assertThat("zetta", "peta").isConvertedTo(1e6);
    assertThat("zetta", "tera").isConvertedTo(1e9);
    assertThat("zetta", "giga").isConvertedTo(1e12);
    assertThat("zetta", "mega").isConvertedTo(1e15);
    assertThat("zetta", "kilo").isConvertedTo(1e18);
    assertThat("zetta", "hecto").isConvertedTo(1e19);
    assertThat("zetta", "deka").isConvertedTo(1e20);
    assertThat("zetta", "base").isConvertedTo(1e21);
    assertThat("zetta", "deci").isConvertedTo(1e22);
    assertThat("zetta", "centi").isConvertedTo(1e23);
    assertThat("zetta", "milli").isConvertedTo(1e24);
    assertThat("zetta", "micro").isConvertedTo(1e27);
    assertThat("zetta", "nano").isConvertedTo(1e30);
    assertThat("zetta", "pico").isConvertedTo(1e33);
    assertThat("zetta", "femto").isConvertedTo(1e36);
    assertThat("zetta", "atto").isConvertedTo(1e39);
    assertThat("zetta", "zepto").isConvertedTo(1e42);
    assertThat("zetta", "yocto").isConvertedTo(1e45);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_exa)
{
    assertThat("exa", "yotta").isConvertedTo(1e-6);
    assertThat("exa", "zetta").isConvertedTo(1e-3);
    assertThat("exa", "exa").isConvertedTo(1e0);
    assertThat("exa", "peta").isConvertedTo(1e3);
    assertThat("exa", "tera").isConvertedTo(1e6);
    assertThat("exa", "giga").isConvertedTo(1e9);
    assertThat("exa", "mega").isConvertedTo(1e12);
    assertThat("exa", "kilo").isConvertedTo(1e15);
    assertThat("exa", "hecto").isConvertedTo(1e16);
    assertThat("exa", "deka").isConvertedTo(1e17);
    assertThat("exa", "base").isConvertedTo(1e18);
    assertThat("exa", "deci").isConvertedTo(1e19);
    assertThat("exa", "centi").isConvertedTo(1e20);
    assertThat("exa", "milli").isConvertedTo(1e21);
    assertThat("exa", "micro").isConvertedTo(1e24);
    assertThat("exa", "nano").isConvertedTo(1e27);
    assertThat("exa", "pico").isConvertedTo(1e30);
    assertThat("exa", "femto").isConvertedTo(1e33);
    assertThat("exa", "atto").isConvertedTo(1e36);
    assertThat("exa", "zepto").isConvertedTo(1e39);
    assertThat("exa", "yocto").isConvertedTo(1e42);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_peta)
{
    assertThat("peta", "yotta").isConvertedTo(1e-9);
    assertThat("peta", "zetta").isConvertedTo(1e-6);
    assertThat("peta", "exa").isConvertedTo(1e-3);
    assertThat("peta", "peta").isConvertedTo(1e0);
    assertThat("peta", "tera").isConvertedTo(1e3);
    assertThat("peta", "giga").isConvertedTo(1e6);
    assertThat("peta", "mega").isConvertedTo(1e9);
    assertThat("peta", "kilo").isConvertedTo(1e12);
    assertThat("peta", "hecto").isConvertedTo(1e13);
    assertThat("peta", "deka").isConvertedTo(1e14);
    assertThat("peta", "base").isConvertedTo(1e15);
    assertThat("peta", "deci").isConvertedTo(1e16);
    assertThat("peta", "centi").isConvertedTo(1e17);
    assertThat("peta", "milli").isConvertedTo(1e18);
    assertThat("peta", "micro").isConvertedTo(1e21);
    assertThat("peta", "nano").isConvertedTo(1e24);
    assertThat("peta", "pico").isConvertedTo(1e27);
    assertThat("peta", "femto").isConvertedTo(1e30);
    assertThat("peta", "atto").isConvertedTo(1e33);
    assertThat("peta", "zepto").isConvertedTo(1e36);
    assertThat("peta", "yocto").isConvertedTo(1e39);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_tera)
{
    assertThat("tera", "yotta").isConvertedTo(1e-12);
    assertThat("tera", "zetta").isConvertedTo(1e-9);
    assertThat("tera", "exa").isConvertedTo(1e-6);
    assertThat("tera", "peta").isConvertedTo(1e-3);
    assertThat("tera", "tera").isConvertedTo(1e0);
    assertThat("tera", "giga").isConvertedTo(1e3);
    assertThat("tera", "mega").isConvertedTo(1e6);
    assertThat("tera", "kilo").isConvertedTo(1e9);
    assertThat("tera", "hecto").isConvertedTo(1e10);
    assertThat("tera", "deka").isConvertedTo(1e11);
    assertThat("tera", "base").isConvertedTo(1e12);
    assertThat("tera", "deci").isConvertedTo(1e13);
    assertThat("tera", "centi").isConvertedTo(1e14);
    assertThat("tera", "milli").isConvertedTo(1e15);
    assertThat("tera", "micro").isConvertedTo(1e18);
    assertThat("tera", "nano").isConvertedTo(1e21);
    assertThat("tera", "pico").isConvertedTo(1e24);
    assertThat("tera", "femto").isConvertedTo(1e27);
    assertThat("tera", "atto").isConvertedTo(1e30);
    assertThat("tera", "zepto").isConvertedTo(1e33);
    assertThat("tera", "yocto").isConvertedTo(1e36);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_giga)
{
    assertThat("giga", "yotta").isConvertedTo(1e-15);
    assertThat("giga", "zetta").isConvertedTo(1e-12);
    assertThat("giga", "exa").isConvertedTo(1e-9);
    assertThat("giga", "peta").isConvertedTo(1e-6);
    assertThat("giga", "tera").isConvertedTo(1e-3);
    assertThat("giga", "giga").isConvertedTo(1e0);
    assertThat("giga", "mega").isConvertedTo(1e3);
    assertThat("giga", "kilo").isConvertedTo(1e6);
    assertThat("giga", "hecto").isConvertedTo(1e7);
    assertThat("giga", "deka").isConvertedTo(1e8);
    assertThat("giga", "base").isConvertedTo(1e9);
    assertThat("giga", "deci").isConvertedTo(1e10);
    assertThat("giga", "centi").isConvertedTo(1e11);
    assertThat("giga", "milli").isConvertedTo(1e12);
    assertThat("giga", "micro").isConvertedTo(1e15);
    assertThat("giga", "nano").isConvertedTo(1e18);
    assertThat("giga", "pico").isConvertedTo(1e21);
    assertThat("giga", "femto").isConvertedTo(1e24);
    assertThat("giga", "atto").isConvertedTo(1e27);
    assertThat("giga", "zepto").isConvertedTo(1e30);
    assertThat("giga", "yocto").isConvertedTo(1e33);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_mega)
{
    assertThat("mega", "yotta").isConvertedTo(1e-18);
    assertThat("mega", "zetta").isConvertedTo(1e-15);
    assertThat("mega", "exa").isConvertedTo(1e-12);
    assertThat("mega", "peta").isConvertedTo(1e-9);
    assertThat("mega", "tera").isConvertedTo(1e-6);
    assertThat("mega", "giga").isConvertedTo(1e-3);
    assertThat("mega", "mega").isConvertedTo(1e0);
    assertThat("mega", "kilo").isConvertedTo(1e3);
    assertThat("mega", "hecto").isConvertedTo(1e4);
    assertThat("mega", "deka").isConvertedTo(1e5);
    assertThat("mega", "base").isConvertedTo(1e6);
    assertThat("mega", "deci").isConvertedTo(1e7);
    assertThat("mega", "centi").isConvertedTo(1e8);
    assertThat("mega", "milli").isConvertedTo(1e9);
    assertThat("mega", "micro").isConvertedTo(1e12);
    assertThat("mega", "nano").isConvertedTo(1e15);
    assertThat("mega", "pico").isConvertedTo(1e18);
    assertThat("mega", "femto").isConvertedTo(1e21);
    assertThat("mega", "atto").isConvertedTo(1e24);
    assertThat("mega", "zepto").isConvertedTo(1e27);
    assertThat("mega", "yocto").isConvertedTo(1e30);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_kilo)
{
    assertThat("kilo", "yotta").isConvertedTo(1e-21);
    assertThat("kilo", "zetta").isConvertedTo(1e-18);
    assertThat("kilo", "exa").isConvertedTo(1e-15);
    assertThat("kilo", "peta").isConvertedTo(1e-12);
    assertThat("kilo", "tera").isConvertedTo(1e-9);
    assertThat("kilo", "giga").isConvertedTo(1e-6);
    assertThat("kilo", "mega").isConvertedTo(1e-3);
    assertThat("kilo", "kilo").isConvertedTo(1e0);
    assertThat("kilo", "hecto").isConvertedTo(1e1);
    assertThat("kilo", "deka").isConvertedTo(1e2);
    assertThat("kilo", "base").isConvertedTo(1e3);
    assertThat("kilo", "deci").isConvertedTo(1e4);
    assertThat("kilo", "centi").isConvertedTo(1e5);
    assertThat("kilo", "milli").isConvertedTo(1e6);
    assertThat("kilo", "micro").isConvertedTo(1e9);
    assertThat("kilo", "nano").isConvertedTo(1e12);
    assertThat("kilo", "pico").isConvertedTo(1e15);
    assertThat("kilo", "femto").isConvertedTo(1e18);
    assertThat("kilo", "atto").isConvertedTo(1e21);
    assertThat("kilo", "zepto").isConvertedTo(1e24);
    assertThat("kilo", "yocto").isConvertedTo(1e27);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_hecto)
{
    assertThat("hecto", "yotta").isConvertedTo(1e-22);
    assertThat("hecto", "zetta").isConvertedTo(1e-19);
    assertThat("hecto", "exa").isConvertedTo(1e-16);
    assertThat("hecto", "peta").isConvertedTo(1e-13);
    assertThat("hecto", "tera").isConvertedTo(1e-10);
    assertThat("hecto", "giga").isConvertedTo(1e-7);
    assertThat("hecto", "mega").isConvertedTo(1e-4);
    assertThat("hecto", "kilo").isConvertedTo(1e-1);
    assertThat("hecto", "hecto").isConvertedTo(1e0);
    assertThat("hecto", "deka").isConvertedTo(1e1);
    assertThat("hecto", "base").isConvertedTo(1e2);
    assertThat("hecto", "deci").isConvertedTo(1e3);
    assertThat("hecto", "centi").isConvertedTo(1e4);
    assertThat("hecto", "milli").isConvertedTo(1e5);
    assertThat("hecto", "micro").isConvertedTo(1e8);
    assertThat("hecto", "nano").isConvertedTo(1e11);
    assertThat("hecto", "pico").isConvertedTo(1e14);
    assertThat("hecto", "femto").isConvertedTo(1e17);
    assertThat("hecto", "atto").isConvertedTo(1e20);
    assertThat("hecto", "zepto").isConvertedTo(1e23);
    assertThat("hecto", "yocto").isConvertedTo(1e26);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_deka)
{
    assertThat("deka", "yotta").isConvertedTo(1e-23);
    assertThat("deka", "zetta").isConvertedTo(1e-20);
    assertThat("deka", "exa").isConvertedTo(1e-17);
    assertThat("deka", "peta").isConvertedTo(1e-14);
    assertThat("deka", "tera").isConvertedTo(1e-11);
    assertThat("deka", "giga").isConvertedTo(1e-8);
    assertThat("deka", "mega").isConvertedTo(1e-5);
    assertThat("deka", "kilo").isConvertedTo(1e-2);
    assertThat("deka", "hecto").isConvertedTo(1e-1);
    assertThat("deka", "deka").isConvertedTo(1e0);
    assertThat("deka", "base").isConvertedTo(1e1);
    assertThat("deka", "deci").isConvertedTo(1e2);
    assertThat("deka", "centi").isConvertedTo(1e3);
    assertThat("deka", "milli").isConvertedTo(1e4);
    assertThat("deka", "micro").isConvertedTo(1e7);
    assertThat("deka", "nano").isConvertedTo(1e10);
    assertThat("deka", "pico").isConvertedTo(1e13);
    assertThat("deka", "femto").isConvertedTo(1e16);
    assertThat("deka", "atto").isConvertedTo(1e19);
    assertThat("deka", "zepto").isConvertedTo(1e22);
    assertThat("deka", "yocto").isConvertedTo(1e25);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_base)
{
    assertThat("base", "yotta").isConvertedTo(1e-24);
    assertThat("base", "zetta").isConvertedTo(1e-21);
    assertThat("base", "exa").isConvertedTo(1e-18);
    assertThat("base", "peta").isConvertedTo(1e-15);
    assertThat("base", "tera").isConvertedTo(1e-12);
    assertThat("base", "giga").isConvertedTo(1e-9);
    assertThat("base", "mega").isConvertedTo(1e-6);
    assertThat("base", "kilo").isConvertedTo(1e-3);
    assertThat("base", "hecto").isConvertedTo(1e-2);
    assertThat("base", "deka").isConvertedTo(1e-1);
    assertThat("base", "base").isConvertedTo(1e0);
    assertThat("base", "deci").isConvertedTo(1e1);
    assertThat("base", "centi").isConvertedTo(1e2);
    assertThat("base", "milli").isConvertedTo(1e3);
    assertThat("base", "micro").isConvertedTo(1e6);
    assertThat("base", "nano").isConvertedTo(1e9);
    assertThat("base", "pico").isConvertedTo(1e12);
    assertThat("base", "femto").isConvertedTo(1e15);
    assertThat("base", "atto").isConvertedTo(1e18);
    assertThat("base", "zepto").isConvertedTo(1e21);
    assertThat("base", "yocto").isConvertedTo(1e24);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_deci)
{
    assertThat("deci", "yotta").isConvertedTo(1e-25);
    assertThat("deci", "zetta").isConvertedTo(1e-22);
    assertThat("deci", "exa").isConvertedTo(1e-19);
    assertThat("deci", "peta").isConvertedTo(1e-16);
    assertThat("deci", "tera").isConvertedTo(1e-13);
    assertThat("deci", "giga").isConvertedTo(1e-10);
    assertThat("deci", "mega").isConvertedTo(1e-7);
    assertThat("deci", "kilo").isConvertedTo(1e-4);
    assertThat("deci", "hecto").isConvertedTo(1e-3);
    assertThat("deci", "deka").isConvertedTo(1e-2);
    assertThat("deci", "base").isConvertedTo(1e-1);
    assertThat("deci", "deci").isConvertedTo(1e0);
    assertThat("deci", "centi").isConvertedTo(1e1);
    assertThat("deci", "milli").isConvertedTo(1e2);
    assertThat("deci", "micro").isConvertedTo(1e5);
    assertThat("deci", "nano").isConvertedTo(1e8);
    assertThat("deci", "pico").isConvertedTo(1e11);
    assertThat("deci", "femto").isConvertedTo(1e14);
    assertThat("deci", "atto").isConvertedTo(1e17);
    assertThat("deci", "zepto").isConvertedTo(1e20);
    assertThat("deci", "yocto").isConvertedTo(1e23);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_centi)
{
    assertThat("centi", "yotta").isConvertedTo(1e-26);
    assertThat("centi", "zetta").isConvertedTo(1e-23);
    assertThat("centi", "exa").isConvertedTo(1e-20);
    assertThat("centi", "peta").isConvertedTo(1e-17);
    assertThat("centi", "tera").isConvertedTo(1e-14);
    assertThat("centi", "giga").isConvertedTo(1e-11);
    assertThat("centi", "mega").isConvertedTo(1e-8);
    assertThat("centi", "kilo").isConvertedTo(1e-5);
    assertThat("centi", "hecto").isConvertedTo(1e-4);
    assertThat("centi", "deka").isConvertedTo(1e-3);
    assertThat("centi", "base").isConvertedTo(1e-2);
    assertThat("centi", "deci").isConvertedTo(1e-1);
    assertThat("centi", "centi").isConvertedTo(1e0);
    assertThat("centi", "milli").isConvertedTo(1e1);
    assertThat("centi", "micro").isConvertedTo(1e4);
    assertThat("centi", "nano").isConvertedTo(1e7);
    assertThat("centi", "pico").isConvertedTo(1e10);
    assertThat("centi", "femto").isConvertedTo(1e13);
    assertThat("centi", "atto").isConvertedTo(1e16);
    assertThat("centi", "zepto").isConvertedTo(1e19);
    assertThat("centi", "yocto").isConvertedTo(1e22);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_milli)
{
    assertThat("milli", "yotta").isConvertedTo(1e-27);
    assertThat("milli", "zetta").isConvertedTo(1e-24);
    assertThat("milli", "exa").isConvertedTo(1e-21);
    assertThat("milli", "peta").isConvertedTo(1e-18);
    assertThat("milli", "tera").isConvertedTo(1e-15);
    assertThat("milli", "giga").isConvertedTo(1e-12);
    assertThat("milli", "mega").isConvertedTo(1e-9);
    assertThat("milli", "kilo").isConvertedTo(1e-6);
    assertThat("milli", "hecto").isConvertedTo(1e-5);
    assertThat("milli", "deka").isConvertedTo(1e-4);
    assertThat("milli", "base").isConvertedTo(1e-3);
    assertThat("milli", "deci").isConvertedTo(1e-2);
    assertThat("milli", "centi").isConvertedTo(1e-1);
    assertThat("milli", "milli").isConvertedTo(1e0);
    assertThat("milli", "micro").isConvertedTo(1e3);
    assertThat("milli", "nano").isConvertedTo(1e6);
    assertThat("milli", "pico").isConvertedTo(1e9);
    assertThat("milli", "femto").isConvertedTo(1e12);
    assertThat("milli", "atto").isConvertedTo(1e15);
    assertThat("milli", "zepto").isConvertedTo(1e18);
    assertThat("milli", "yocto").isConvertedTo(1e21);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_micro)
{
    assertThat("micro", "yotta").isConvertedTo(1e-30);
    assertThat("micro", "zetta").isConvertedTo(1e-27);
    assertThat("micro", "exa").isConvertedTo(1e-24);
    assertThat("micro", "peta").isConvertedTo(1e-21);
    assertThat("micro", "tera").isConvertedTo(1e-18);
    assertThat("micro", "giga").isConvertedTo(1e-15);
    assertThat("micro", "mega").isConvertedTo(1e-12);
    assertThat("micro", "kilo").isConvertedTo(1e-9);
    assertThat("micro", "hecto").isConvertedTo(1e-8);
    assertThat("micro", "deka").isConvertedTo(1e-7);
    assertThat("micro", "base").isConvertedTo(1e-6);
    assertThat("micro", "deci").isConvertedTo(1e-5);
    assertThat("micro", "centi").isConvertedTo(1e-4);
    assertThat("micro", "milli").isConvertedTo(1e-3);
    assertThat("micro", "micro").isConvertedTo(1e0);
    assertThat("micro", "nano").isConvertedTo(1e3);
    assertThat("micro", "pico").isConvertedTo(1e6);
    assertThat("micro", "femto").isConvertedTo(1e9);
    assertThat("micro", "atto").isConvertedTo(1e12);
    assertThat("micro", "zepto").isConvertedTo(1e15);
    assertThat("micro", "yocto").isConvertedTo(1e18);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_nano)
{
    assertThat("nano", "yotta").isConvertedTo(1e-33);
    assertThat("nano", "zetta").isConvertedTo(1e-30);
    assertThat("nano", "exa").isConvertedTo(1e-27);
    assertThat("nano", "peta").isConvertedTo(1e-24);
    assertThat("nano", "tera").isConvertedTo(1e-21);
    assertThat("nano", "giga").isConvertedTo(1e-18);
    assertThat("nano", "mega").isConvertedTo(1e-15);
    assertThat("nano", "kilo").isConvertedTo(1e-12);
    assertThat("nano", "hecto").isConvertedTo(1e-11);
    assertThat("nano", "deka").isConvertedTo(1e-10);
    assertThat("nano", "base").isConvertedTo(1e-9);
    assertThat("nano", "deci").isConvertedTo(1e-8);
    assertThat("nano", "centi").isConvertedTo(1e-7);
    assertThat("nano", "milli").isConvertedTo(1e-6);
    assertThat("nano", "micro").isConvertedTo(1e-3);
    assertThat("nano", "nano").isConvertedTo(1e0);
    assertThat("nano", "pico").isConvertedTo(1e3);
    assertThat("nano", "femto").isConvertedTo(1e6);
    assertThat("nano", "atto").isConvertedTo(1e9);
    assertThat("nano", "zepto").isConvertedTo(1e12);
    assertThat("nano", "yocto").isConvertedTo(1e15);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_pico)
{
    assertThat("pico", "yotta").isConvertedTo(1e-36);
    assertThat("pico", "zetta").isConvertedTo(1e-33);
    assertThat("pico", "exa").isConvertedTo(1e-30);
    assertThat("pico", "peta").isConvertedTo(1e-27);
    assertThat("pico", "tera").isConvertedTo(1e-24);
    assertThat("pico", "giga").isConvertedTo(1e-21);
    assertThat("pico", "mega").isConvertedTo(1e-18);
    assertThat("pico", "kilo").isConvertedTo(1e-15);
    assertThat("pico", "hecto").isConvertedTo(1e-14);
    assertThat("pico", "deka").isConvertedTo(1e-13);
    assertThat("pico", "base").isConvertedTo(1e-12);
    assertThat("pico", "deci").isConvertedTo(1e-11);
    assertThat("pico", "centi").isConvertedTo(1e-10);
    assertThat("pico", "milli").isConvertedTo(1e-9);
    assertThat("pico", "micro").isConvertedTo(1e-6);
    assertThat("pico", "nano").isConvertedTo(1e-3);
    assertThat("pico", "pico").isConvertedTo(1e0);
    assertThat("pico", "femto").isConvertedTo(1e3);
    assertThat("pico", "atto").isConvertedTo(1e6);
    assertThat("pico", "zepto").isConvertedTo(1e9);
    assertThat("pico", "yocto").isConvertedTo(1e12);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_femto)
{
    assertThat("femto", "yotta").isConvertedTo(1e-39);
    assertThat("femto", "zetta").isConvertedTo(1e-36);
    assertThat("femto", "exa").isConvertedTo(1e-33);
    assertThat("femto", "peta").isConvertedTo(1e-30);
    assertThat("femto", "tera").isConvertedTo(1e-27);
    assertThat("femto", "giga").isConvertedTo(1e-24);
    assertThat("femto", "mega").isConvertedTo(1e-21);
    assertThat("femto", "kilo").isConvertedTo(1e-18);
    assertThat("femto", "hecto").isConvertedTo(1e-17);
    assertThat("femto", "deka").isConvertedTo(1e-16);
    assertThat("femto", "base").isConvertedTo(1e-15);
    assertThat("femto", "deci").isConvertedTo(1e-14);
    assertThat("femto", "centi").isConvertedTo(1e-13);
    assertThat("femto", "milli").isConvertedTo(1e-12);
    assertThat("femto", "micro").isConvertedTo(1e-9);
    assertThat("femto", "nano").isConvertedTo(1e-6);
    assertThat("femto", "pico").isConvertedTo(1e-3);
    assertThat("femto", "femto").isConvertedTo(1e0);
    assertThat("femto", "atto").isConvertedTo(1e3);
    assertThat("femto", "zepto").isConvertedTo(1e6);
    assertThat("femto", "yocto").isConvertedTo(1e9);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_atto)
{
    assertThat("atto", "yotta").isConvertedTo(1e-42);
    assertThat("atto", "zetta").isConvertedTo(1e-39);
    assertThat("atto", "exa").isConvertedTo(1e-36);
    assertThat("atto", "peta").isConvertedTo(1e-33);
    assertThat("atto", "tera").isConvertedTo(1e-30);
    assertThat("atto", "giga").isConvertedTo(1e-27);
    assertThat("atto", "mega").isConvertedTo(1e-24);
    assertThat("atto", "kilo").isConvertedTo(1e-21);
    assertThat("atto", "hecto").isConvertedTo(1e-20);
    assertThat("atto", "deka").isConvertedTo(1e-19);
    assertThat("atto", "base").isConvertedTo(1e-18);
    assertThat("atto", "deci").isConvertedTo(1e-17);
    assertThat("atto", "centi").isConvertedTo(1e-16);
    assertThat("atto", "milli").isConvertedTo(1e-15);
    assertThat("atto", "micro").isConvertedTo(1e-12);
    assertThat("atto", "nano").isConvertedTo(1e-9);
    assertThat("atto", "pico").isConvertedTo(1e-6);
    assertThat("atto", "femto").isConvertedTo(1e-3);
    assertThat("atto", "atto").isConvertedTo(1e0);
    assertThat("atto", "zepto").isConvertedTo(1e3);
    assertThat("atto", "yocto").isConvertedTo(1e6);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_zepto)
{
    assertThat("zepto", "yotta").isConvertedTo(1e-45);
    assertThat("zepto", "zetta").isConvertedTo(1e-42);
    assertThat("zepto", "exa").isConvertedTo(1e-39);
    assertThat("zepto", "peta").isConvertedTo(1e-36);
    assertThat("zepto", "tera").isConvertedTo(1e-33);
    assertThat("zepto", "giga").isConvertedTo(1e-30);
    assertThat("zepto", "mega").isConvertedTo(1e-27);
    assertThat("zepto", "kilo").isConvertedTo(1e-24);
    assertThat("zepto", "hecto").isConvertedTo(1e-23);
    assertThat("zepto", "deka").isConvertedTo(1e-22);
    assertThat("zepto", "base").isConvertedTo(1e-21);
    assertThat("zepto", "deci").isConvertedTo(1e-20);
    assertThat("zepto", "centi").isConvertedTo(1e-19);
    assertThat("zepto", "milli").isConvertedTo(1e-18);
    assertThat("zepto", "micro").isConvertedTo(1e-15);
    assertThat("zepto", "nano").isConvertedTo(1e-12);
    assertThat("zepto", "pico").isConvertedTo(1e-9);
    assertThat("zepto", "femto").isConvertedTo(1e-6);
    assertThat("zepto", "atto").isConvertedTo(1e-3);
    assertThat("zepto", "zepto").isConvertedTo(1e0);
    assertThat("zepto", "yocto").isConvertedTo(1e3);
}

TEST(testSI_UnitPrefixesConversionFunctions, conversionsOfSI_UnitPrefixesFrom_yocto)
{
    assertThat("yocto", "yotta").isConvertedTo(1e-48);
    assertThat("yocto", "zetta").isConvertedTo(1e-45);
    assertThat("yocto", "exa").isConvertedTo(1e-42);
    assertThat("yocto", "peta").isConvertedTo(1e-39);
    assertThat("yocto", "tera").isConvertedTo(1e-36);
    assertThat("yocto", "giga").isConvertedTo(1e-33);
    assertThat("yocto", "mega").isConvertedTo(1e-30);
    assertThat("yocto", "kilo").isConvertedTo(1e-27);
    assertThat("yocto", "hecto").isConvertedTo(1e-26);
    assertThat("yocto", "deka").isConvertedTo(1e-25);
    assertThat("yocto", "base").isConvertedTo(1e-24);
    assertThat("yocto", "deci").isConvertedTo(1e-23);
    assertThat("yocto", "centi").isConvertedTo(1e-22);
    assertThat("yocto", "milli").isConvertedTo(1e-21);
    assertThat("yocto", "micro").isConvertedTo(1e-18);
    assertThat("yocto", "nano").isConvertedTo(1e-15);
    assertThat("yocto", "pico").isConvertedTo(1e-12);
    assertThat("yocto", "femto").isConvertedTo(1e-9);
    assertThat("yocto", "atto").isConvertedTo(1e-6);
    assertThat("yocto", "zepto").isConvertedTo(1e-3);
    assertThat("yocto", "yocto").isConvertedTo(1e0);
}
