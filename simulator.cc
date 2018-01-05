#include "simulator.h"

std::vector<float> reg = {33.3, 35.8, 3.5};


float spill(int action) {
  return reg[action];
}

void Simulation::reset() {
  _state = init_state;
  _score = 0;
}

int Simulation::allocate(int action) {
  int reward = -1;

  float w = spill(action);
  std::vector<float> new_state = reg;
  if (w > 0.0) {
    if (w > prev_weight) {
      reward -= 10000;
    } else if (w <= prev_weight) {
      reward += 1000;
    } else if (w <= prev_weight && terminal_state) {  
      reward += 10000;
    }
      _state = new_state;
  } else {
      reward -= 5;
  }

  curr_weight += w;
  _score += reward;
  return reward;
}	  

void Simulation::terminal() {
  prev_weight = curr_weight;
}
