// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: physicalQuantities.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:31:45
// Description: The public API for the PhysicalQuantities section of the Utilities-API program. This
//   header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef UTILITIES_API_PHYSICALQUANTITIES_HPP
#define UTILITIES_API_PHYSICALQUANTITIES_HPP

#include "internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/angle.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/area.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/length.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/volume.hpp"

#include "internal/PhysicalQuantities/MKSQuantities/OtherMKSQuantities/irradiance.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/OtherMKSQuantities/massDensity.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/OtherMKSQuantities/momentumFlux.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/OtherMKSQuantities/specificEnergy.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/OtherMKSQuantities/specificVolume.hpp"

#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/acceleration.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/force.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/mass.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/momentum.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/power.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/pressure.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/time.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/velocity.hpp"

#include "internal/PhysicalQuantities/MKSQuantities/WaveQuantities/action.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/WaveQuantities/energy.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/WaveQuantities/frequency.hpp"
#include "internal/PhysicalQuantities/MKSQuantities/WaveQuantities/waveNumber.hpp"

#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/capacitance.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/currentDensity.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricCharge.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricChargeDensity.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricConductivity.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricConductance.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricCurrent.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricField.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricFluxDensity.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricPotential.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/electricResistance.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/mobility.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/ChargedQuantities/permittivity.hpp"

#include "internal/PhysicalQuantities/ElectromagneticQuantities/MagneticQuantities/inductance.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/MagneticQuantities/magneticFieldStrength.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/MagneticQuantities/magneticFlux.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/MagneticQuantities/magneticFluxDensity.hpp"
#include "internal/PhysicalQuantities/ElectromagneticQuantities/MagneticQuantities/permeability.hpp"

#include "internal/PhysicalQuantities/TemperatureQuantities/entropy.hpp"
#include "internal/PhysicalQuantities/TemperatureQuantities/specificEntropy.hpp"
#include "internal/PhysicalQuantities/TemperatureQuantities/temperature.hpp"
#include "internal/PhysicalQuantities/TemperatureQuantities/thermalConductivity.hpp"

#include "internal/PhysicalQuantities/MolarQuantities/amountOfSubstance.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/concentration.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/concentrationGradient.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/faradays.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/molarConductivity.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/molarEnergy.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/molarEnergyFlux.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/molarEntropy.hpp"
#include "internal/PhysicalQuantities/MolarQuantities/molarMass.hpp"

#endif
