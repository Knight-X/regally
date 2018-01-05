class Simulation {
  Simulation() {
    curr_weight = 0.0;
    prev_weight = 0.0;
    _state = init_state;
    _score = 0;
  }
  void reset();
  void allocate(int action);
  void terminal();
 
  private:
    std::vector<float> _state;
    int _score;
    float curr_weight;
    float prev_weight;
};
