
#include <vector>
#include <iostream>

class Simulation {
  public:
    Simulation() {
      curr_weight = 0.0;
      prev_weight = 100;
      _state = {0.0, 0.0, 0.0};
      _score = 0;
      terminal_state = false;
    }
    void reset();
    float allocate(int action);
    void terminal();
 
    bool terminal_state;
    std::vector<float> _state;
    int _score;
    float prev_weight;
  private:
    float curr_weight;
};
