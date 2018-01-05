float spill(int action) {
  std::vector<float> reg;
  reg[0] = 33.3;
  reg[1] = 35.8;
  reg[2] = 3.5;
  return reg[action];
}

void Simulation::reset() {
  _state = init_state;
  _score = 0;
}

void Simulation::allocate(int action) {
  reward = -1;

  float w = spill(action);
  if (w > 0.0) {
    if (w > prev_weight) {
      reward -= 10000;
    } else if (w <= prev_weight) {
      reward += 1000;
    } else if (w <= prev_weight && terminal) {  
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
