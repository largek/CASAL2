/**
 * @file Factory.cpp
 * @author  Scott Rasmussen (scott.rasmussen@zaita.com)
 * @date 6/06/2013
 * @section LICENSE
 *
 * Copyright NIWA Science �2013 - www.niwa.co.nz
 *
 */

// headers
#include "Factory.h"

#include "Common/Model/Model.h"
#include "Common/Model/Managers.h"
#include "Common/DerivedQuantities/Manager.h"
#include "Age/DerivedQuantities/Factory.h"
#include "Length/DerivedQuantities/Factory.h"

// namespaces
namespace niwa {
namespace derivedquantities {

/**
 * Create the instance of our object as defined by the two parameters
 * object_type and sub_type.
 *
 * @param object_type The type of object to create (e.g age_size, process)
 * @param sub_type The child type of the object to create (e.g ageing, schnute)
 * @return shared_ptr to the object we've created
 */
DerivedQuantity* Factory::Create(Model* model, const string& object_type, const string& sub_type, PartitionType partition_type) {
  DerivedQuantity* result = nullptr;

  if (partition_type == PartitionType::kAge || model->partition_type() == PartitionType::kAge)
    result = age::derivedquantities::Factory::Create(model, object_type, sub_type);
  else if (partition_type == PartitionType::kLength || model->partition_type() == PartitionType::kLength)
    result = length::derivedquantities::Factory::Create(model, object_type, sub_type);

  if (result)
    model->managers().derived_quantity()->AddObject(result);

  return result;
}


} /* namespace derivedquantities */
} /* namespace niwa */
