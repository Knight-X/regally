
#include "rl.h"

void BasicBlock::step() {
   _draw();

   _driver.interact(_sim);
   if (_sim.terminal_state && ~_was_in_terminal_state){
     if (_sim._score < 0) {
       _losses += 1;
     } else {
       _wins += 1;
     }
   }
   _was_in_terminal_state = _sim.terminal_state;
}

void BasicBlock::_draw() {
   printf("the winner score is %d", _wins);
} 


int RandomPolicy::pick_action() {
    return rand() % 3;
}

int GreedyQ::pick_action(std::vector<float> state) {
    return GreedyQ::_q.best(state);
}

int EpsilonPolicy::pick_action(std::vector<float> state) {
    if (random.random() < _epsilon)
      return _random.pick_action();
    else 
      return _greedy.pick_action(state);
}

float QTable::get(std::vector<float> state, int action) {
   std::pair<std::vector<float>, int> n_state = std::make_pair(state, action);
    return _table[n_state];
}


void QTable::set(std::vector<float> state, int action, float value) {
  std::pair<std::vector<float>, int> n_state = std::make_pair(state, action);
  _table[n_state] = value;
}


std::pair<std::vector<float>, int>  QTable::best(std::vector<float> state) {
  float best_value = 0.00001;
  int best_action = 0;
  for (int action = 0; action < 5; action++) {
    float value = get(state, action);
    if (value > best_value) {
      best_action = action;
    }
  }
  std::pair<std::vector<float>, int> n_state = std::make_pair(state, best_action);
  return n_state; 
}


void QLearner::observe(std::vector<float> old_state, int action, float reward, std::vector<float> new_state) {
  float prev = _q.get(old_state, action);
  _q.set(old_state, action, prev + _alpha * (
        reward + _gamma * _q.best(new_state)[1] - prev));
}

void MachinePlayer::interact(Simulation sim) {
  if (sim.terminal_state) {
    sim.terminal();
    sim.reset();
  } else {
    std::vector<float> old_state = sim._state;
    int action = _policy.pick_action(sim._state);
    int reward = sim.allocate(action);
    _learner.observe(old_state, action, reward, sim._state);
  } 
}
