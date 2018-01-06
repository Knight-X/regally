#include "simulator.h"

std::vector<float> reg = {33.3, 35.8, 3.5};

float spill(int action) {
  return reg[action];
}

void Simulation::reset() {
  _state = {0.0, 0.0, 0.0};
  _score = 0;
}

float Simulation::allocate(int action) {
  int reward = -1;

  float w = spill(action);
  std::vector<float> new_state = reg;
  curr_weight += w;
  if (w > 0.0) {
    if (curr_weight > prev_weight) {
      reward = -10000;
    } else if (curr_weight == prev_weight && terminal_state) {  
      reward = 5;
    } else if (curr_weight < prev_weight && terminal_state) {  
      reward = 10000;
    } else if (curr_weight <= prev_weight) {
      reward = 5;
    }
      _state = reg;
  } else {
      reward -= 5;
  }

  _score += reward;
  return reward;
}	  

void Simulation::terminal() {
  if (prev_weight > curr_weight) {
    prev_weight = curr_weight;
  }
  curr_weight = 0.0;
}
