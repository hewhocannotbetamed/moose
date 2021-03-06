//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Material.h"
#include "DerivativeMaterialInterface.h"

// Forward Declarations

/**
 * Calculates resistivity and electrical conductivity as a function of temperature.
 * It is assumed that resistivity varies linearly with temperature.
 */
class ElectricalConductivity : public DerivativeMaterialInterface<Material>
{
public:
  static InputParameters validParams();

  ElectricalConductivity(const InputParameters & parameters);

protected:
  virtual void computeQpProperties();

private:
  const Real _ref_resis;
  const Real _temp_coeff;
  const Real _ref_temp;
  const VariableValue & _T;

  const std::string _base_name;
  MaterialProperty<Real> & _electric_conductivity;
  MaterialProperty<Real> & _delectric_conductivity_dT;
};
