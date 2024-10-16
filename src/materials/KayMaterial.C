//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
#include "KayMaterial.h"

registerMooseObject("kingfisherApp", KayMaterial);

InputParameters
KayMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();

  return params;
}

KayMaterial::KayMaterial(const InputParameters & parameters)
  : ADMaterial(parameters)
{
}

void
KayMaterial::computeQpProperties()
{
}
