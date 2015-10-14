/**
 * @file Abundance.h
 * @author Scott Rasmussen (scott.rasmussen@zaita.com)
 * @github https://github.com/Zaita
 * @date 24/06/2015
 * @section LICENSE
 *
 * Copyright NIWA Science �2015 - www.niwa.co.nz
 *
 * @section DESCRIPTION
 *
 * The abundance derived quantity will get the amount
 * of population in the partition with selectivity
 */
#ifndef DERIVEDQUANTITIES_ABUNDANCE_H_
#define DERIVEDQUANTITIES_ABUNDANCE_H_

// headers
#include "DerivedQuantities/DerivedQuantity.h"

// namespaces
namespace niwa {
namespace derivedquantities {

// classes
class Abundance : public niwa::DerivedQuantity {
public:
  // methods
  explicit Abundance(Model* model) : DerivedQuantity(model) { }
  virtual                     ~Abundance() = default;
  void                        PreExecute() override final;
  void                        Execute() override final;
};

} /* namespace derivedquantities */
} /* namespace niwa */
#endif /* DERIVEDQUANTITIES_ABUNDANCE_H_ */
