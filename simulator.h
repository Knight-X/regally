
#include <vector>
#include <iostream>

std::vector<float> init_state = {0.0, 0.0, 0.0};
class Simulation {
  public:
    Simulation() {
      curr_weight = 0.0;
      prev_weight = 0.0;
      _state = init_state;
      _score = 0;
      terminal_state = false;
    }
    void reset();
    int allocate(int action);
    void terminal();
 
    bool terminal_state;
    std::vector<float> _state;
    int _score;
  private:
    float curr_weight;
    float prev_weight;
};
