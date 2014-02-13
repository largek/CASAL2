/**
 * @file Observation.cpp
 * @author  Scott Rasmussen (scott.rasmussen@zaita.com)
 * @date 21/01/2014
 * @section LICENSE
 *
 * Copyright NIWA Science �2013 - www.niwa.co.nz
 *
 */

// headers
#include "Observation.h"
#include "Observations/Manager.h"

// namespaces
namespace isam {
namespace reports {

namespace obs = isam::observations;

/**
 *
 */
Observation::Observation() {
  LOG_TRACE();
  model_state_ = State::kPostExecute;
  run_mode_    = RunMode::kBasic;

  parameters_.Bind<string>(PARAM_OBSERVATION, &observation_label_, "Observation label");
}

/**
 *
 */
void Observation::DoBuild() {
  LOG_TRACE();

  observation_ = observations::Manager::Instance().GetObservation(observation_label_);
  if (!observation_)
    LOG_ERROR(parameters_.location(PARAM_OBSERVATION) << " (" << observation_label_ << ") could not be found. Have you defined it?");
}

/**
 *
 */
void Observation::Execute() {
  cout << CONFIG_ARRAY_START << label_ << CONFIG_ARRAY_END << "\n";

  cout << PARAM_OBSERVATION << ": " << observation_->label() << "\n";
  cout << "Comparisons: \n";

  cout << "year age observed expected residual error_value score\n";

  map<unsigned, vector<obs::Comparison> >& comparisons = observation_->comparisons();
  for (auto iter = comparisons.begin(); iter != comparisons.end(); ++iter) {
    for (obs::Comparison comparison : iter->second) {

      cout << iter->first << " " << comparison.age_ << " " << comparison.observed_ << " " << comparison.expected_
          << " " << comparison.observed_ - comparison.expected_ << " " << comparison.error_value_ << " "
          << comparison.score_ << "\n";
    }
  }

  cout << CONFIG_END_REPORT << "\n" << endl;
}

} /* namespace reports */
} /* namespace isam */
