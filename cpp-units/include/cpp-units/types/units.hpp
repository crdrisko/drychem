// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: units.hpp
// Author: crdrisko
// Date: 10/30/2020-10:50:26
// Description:

#ifndef UNITS_HPP
#define UNITS_HPP

#include <cstdint>
#include <ratio>
#include <utility>

#include "types/dimensionality.hpp"
#include "types/physicalQuantity.hpp"

namespace CppUnits
{
    template<class PhysicalQuantity, class Units = std::ratio<1>>
    class PhysicalQuantityWithUnits : public PhysicalQuantity
    {
    private:
        typename Units::type units;

    public:
        constexpr PhysicalQuantityWithUnits() noexcept = default;

        template<typename T>
        constexpr PhysicalQuantityWithUnits(T&& Magnitude) : PhysicalQuantity {std::forward<T>(Magnitude)}
        {
        }
    };

    template<class Units = std::ratio<1>>
    class Length : public PhysicalQuantityWithUnits<PhysicalQuantity<Dimensionality<1, 0, 0>>, Units>
    {
    public:
        constexpr Length() noexcept = default;

        template<typename T>
        constexpr Length(T&& Magnitude) : PhysicalQuantityWithUnits {std::forward<T>(Magnitude)}
        {
        }
    };

    // template<class Units = std::ratio<1>>
    // using Length = PhysicalQuantityWithUnits<PhysicalQuantity<Dimensionality<1, 0, 0>>, Units>;

    // using Length1 = PhysicalQuantityWithUnits<PhysicalQuantity<Dimensionality<1, 0, 0>>, std::ratio<1>>;

    template<class Units = std::ratio<1>>
    using Concentration = PhysicalQuantityWithUnits<PhysicalQuantity<Dimensionality<-3, 0, 0, 0, 0, 1>>, Units>;

    template<class Units = std::ratio<1>>
    using ConcentrationGradient = PhysicalQuantityWithUnits<PhysicalQuantity<Dimensionality<-4, 0, 0, 0, 0, 1>>, Units>;


#define DECLARE_SI_PREFIXED_SYMBOL(TYPE, UNIT)                                                                              \
    constexpr auto operator"" _a##UNIT(long double magnitude) noexcept { return TYPE<std::atto>(magnitude); }               \
    constexpr auto operator"" _f##UNIT(long double magnitude) noexcept { return TYPE<std::femto>(magnitude); }              \
    constexpr auto operator"" _p##UNIT(long double magnitude) noexcept { return TYPE<std::pico>(magnitude); }               \
    constexpr auto operator"" _n##UNIT(long double magnitude) noexcept { return TYPE<std::nano>(magnitude); }               \
    constexpr auto operator"" _µ##UNIT(long double magnitude) noexcept { return TYPE<std::micro>(magnitude); }              \
    constexpr auto operator"" _m##UNIT(long double magnitude) noexcept { return TYPE<std::milli>(magnitude); }              \
    constexpr auto operator"" _c##UNIT(long double magnitude) noexcept { return TYPE<std::centi>(magnitude); }              \
    constexpr auto operator"" _d##UNIT(long double magnitude) noexcept { return TYPE<std::deci>(magnitude); }               \
    constexpr auto operator"" _##UNIT(long double magnitude) noexcept { return TYPE<std::ratio<1>>(magnitude); }            \
    constexpr auto operator"" _da##UNIT(long double magnitude) noexcept { return TYPE<std::deca>(magnitude); }              \
    constexpr auto operator"" _h##UNIT(long double magnitude) noexcept { return TYPE<std::hecto>(magnitude); }              \
    constexpr auto operator"" _k##UNIT(long double magnitude) noexcept { return TYPE<std::kilo>(magnitude); }               \
    constexpr auto operator"" _M##UNIT(long double magnitude) noexcept { return TYPE<std::mega>(magnitude); }               \
    constexpr auto operator"" _G##UNIT(long double magnitude) noexcept { return TYPE<std::giga>(magnitude); }               \
    constexpr auto operator"" _T##UNIT(long double magnitude) noexcept { return TYPE<std::tera>(magnitude); }               \
    constexpr auto operator"" _P##UNIT(long double magnitude) noexcept { return TYPE<std::peta>(magnitude); }               \
    constexpr auto operator"" _E##UNIT(long double magnitude) noexcept { return TYPE<std::exa>(magnitude); }

    DECLARE_SI_PREFIXED_SYMBOL(Length, m)

    constexpr auto operator"" _m(long double magnitude) { return Length(magnitude); }
    constexpr auto operator"" _Ang(long double magnitude) { return Length<std::ratio<1, 10'000'000'000>>(magnitude); }
    constexpr auto operator"" _in(long double magnitude) { return Length<std::ratio<10'000, 393'701>>(magnitude); }
    constexpr auto operator"" _ft(long double magnitude) { return Length<std::ratio<1'000'000, 3'280'840>>(magnitude); }
    constexpr auto operator"" _yd(long double magnitude) { return Length<std::ratio<1'000'000, 1'093'613>>(magnitude); }
    constexpr auto operator"" _mil(long double magnitude) { return Length<std::ratio<160'934, 100>>(magnitude); }

    DECLARE_SI_PREFIXED_SYMBOL(Concentration, M)

    // constexpr auto operator"" _M(long double magnitude) { return Concentration<>(magnitude); }

    constexpr auto operator"" _M_m(long double magnitude) { return ConcentrationGradient<>(magnitude); }
}   // namespace CppUnits

#endif
