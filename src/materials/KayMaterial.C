//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
#include "KayMaterial.h"

registerMooseObject("kingfisherApp", KayMaterial);

InputParameters
KayMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();
  params.addRequiredCoupledVar("variable", "The variables in the denominator");
  return params;
}

KayMaterial::KayMaterial(const InputParameters & parameters)
  : ADMaterial(parameters),
  _grad_u(adCoupledGradient("variable")),
  _k(declareADProperty<Real>("k"))
{
}

void
KayMaterial::computeQpProperties()
{
}
