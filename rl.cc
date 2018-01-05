

void BasicBlock::step() {
   _draw();

   _driver.interact(_sim);
   if (in_terminal_state && ~was_in_terminal){
     if _sim.score < 0{
       _losses += 1;
     } else {
       _wins += 1;
     }
   }
   _was_in_terminal_state = _sim.in_terminal_state;
}

void BasicBlock::_draw() {
   printf("the winner score is %d", _wins);
} 


int RandomPolicy::pick_action() {
    return rand() % 3;
}

int GreedyQ::pick_action(std::pair<vector<float>, int> state) {
    return self._q.best(state)[0];
}

void EpsilonPolicy::pick_action(state) {
    if (random.random() < self._epsilon)
      return _policy_b.pick_action(state)
    else
      return _policy_a.pick_action(state)
}

float QTable::get(std::vector<float> state, int action) {
   std::pair<std::vector<float>, int> n_state = std::make_pair(state, action);
    return _table[n_state];
}


void QTable::set(std::vector<float> state, int action, float value) {
  std::pair<std::vector<float>, int> n_state = std::make_pair(state, action);
  _table[n_state] = value;
}


int QTable::best(std::vector<float> state) {
  best_value = -1e20;
  best_action = 5;
  for (int i = 0; i < 5; i++) {
    float value = get(state, i);
    if (value > best_value) {
      best_action = action;
    }
  }
  return action;
}


void QLearner::observe(std::vector<float> old_state, int action, float reward, std::vector<float> new_state) {
  float prev = _q.get(old_state, action);
  _q.set(old_state, action, prev + self._alpha * (
        reward + self._gamma * self._q.best(new_state)[1] - prev));
}

virtual void interact(Simulation sim) override {
  if sim.in_terminal_state:
    sim.terminal();
    sim.reset()
  else:
    old_state = sim.state
    action = _policy.pick_action(sim.state)
    reward = sim.act(action)
    _learner.observe(old_state, action, reward, sim.state)
}
