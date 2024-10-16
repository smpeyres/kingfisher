#pragma once

#include "ADMaterial.h"

/**
 * Material-derived objects override the computeQpProperties()
 * function.  They must declare and compute material properties for
 * use by other objects in the calculation such as Kernels and
 * BoundaryConditions.
 */
class KayMaterial : public ADMaterial
{
public:
  static InputParameters validParams();

  KayMaterial(const InputParameters & parameters);

protected:
  /**
   * Necessary override.  This is where the values of the properties
   * are computed.
   */
  virtual void computeQpProperties() override;

  /// The coupled variable gradient
  const ADVariableGradient & _grad_u;

  /// The k material property
  ADMaterialProperty<Real> & _k;

};
