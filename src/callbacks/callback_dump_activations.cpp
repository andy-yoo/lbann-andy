////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014-2016, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory.
// Written by the LBANN Research Team (B. Van Essen, et al.) listed in
// the CONTRIBUTORS file. <lbann-dev@llnl.gov>
//
// LLNL-CODE-697807.
// All rights reserved.
//
// This file is part of LBANN: Livermore Big Artificial Neural Network
// Toolkit. For details, see http://software.llnl.gov/LBANN or
// https://github.com/LLNL/LBANN.
//
// Licensed under the Apache License, Version 2.0 (the "Licensee"); you
// may not use this file except in compliance with the License.  You may
// obtain a copy of the License at:
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the license.
////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include "lbann/callbacks/callback_dump_activations.hpp"
#include "lbann/layers/io/target/target_layer.hpp"

namespace lbann {

void lbann_callback_dump_activations::on_forward_prop_end(model *m, Layer *l) {

  // Skip if we are interested in saving inferences at (a) given layer(s)
  if (!m_layer_names.empty()) { return; }

  // Write each activation matrix to file
  for (int i = 0; i < l->get_num_children(); ++i) {

    // File name
    std::stringstream file;
    file << m_basename
         << "model" << m->get_comm()->get_model_rank() << "-"
         << "epoch" << m->get_cur_epoch() << "-"
         << "step" << m->get_cur_step() << "-"
         << l->get_name() << "-"
         << "Activations";
    if (l->get_num_children() > 1) { file << i; }

    // Write activations to file
    El::Write(l->get_activations(i), file.str(), El::ASCII);

  }

}

void lbann_callback_dump_activations::on_epoch_end(model *m) {
  auto cur_epoch = m->get_cur_epoch();
  auto tag = "train_epoch" + std::to_string(cur_epoch);
  if(cur_epoch % m_batch_interval == 0) dump_activations(*m,tag);
}

void lbann_callback_dump_activations::on_validation_end(model *m) {
  auto cur_epoch = m->get_cur_epoch();
  auto tag = "val_epoch" + std::to_string(cur_epoch);
  if(cur_epoch % m_batch_interval == 0) dump_activations(*m,tag);
}

void lbann_callback_dump_activations::on_test_end(model *m) {
  auto cur_epoch = m->get_cur_epoch();
  auto tag = "test_epoch" + std::to_string(cur_epoch);
  if(cur_epoch % m_batch_interval == 0) dump_activations(*m,tag);
}

void lbann_callback_dump_activations::dump_activations(model& m,
                                            std::string tag) {
  //Skip if layer list is empty, user may interested in the saving all activations
  //Use method above 
  if (m_layer_names.empty()) { return; }

  const auto layers = m.get_layers();
  for(auto& l: layers) {
    if(std::find(std::begin(m_layer_names), std::end(m_layer_names),
                  l->get_name()) != std::end(m_layer_names)) {
      //@todo: generalize to support different format
      const std::string file
        = (m_basename
           + "model" + std::to_string(m.get_comm()->get_model_rank())
           + "-" + l->get_name()
           + "-" + tag
           + "-Activations");
       El::Write(l->get_activations(), file, El::ASCII);
      }
    }
}


}  // namespace lbann
