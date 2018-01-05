#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

class BasicBlock {
  public:
  BasicBlock(MachinePlayer _driver) {
      _sim = simulation.Simulation(generator)
      _wins = 0
      _losses = 0
      _was_in_terminal_state = False
      _driver = driver;
    }
 
  void step();
  void _draw();
  private:
    int _wins;
    int _losses;
    bool _was_in_terminal_state;
    MachinePlayer driver;
};

class Player {
	virtual void interact(Simulation sim);
};


class RandomPolicy {
  int pick_action();
};



class GreedyQ(object) {
  GreedyQ(QTable q) {
    self._q = q
  }
  int pick_action(std::pair<vector<float>, int> state);

  private:
    QTable _q;
};

class EpsilonPolicy {
	
  EpsilonPolicy(policy_a, policy_b, epsilon){
    _policy_a = policy_al
    _policy_b = policy_b;
    _epsilon = epsilon;
  }
  void pick_action(std::pair<vector<float>, int> state);

  private:
    RandomPolicy _policy_a;
    GreedyQ _policy_b;
    float _epsilon;
};

class QTable {
  public:
    float get(std::vector<float> state, int action);
    void set(std::vector<float> state, int action, float value);
    int best(std::vector<float> state);
  private:
    std::map<std::pair<std::vector<float>, int>, float> _table;
};
class QLearner {
  public:
    QLearner(QTable q, float learning_rate, float discount_rate) {
      _q = q;
      _alpha = learning_rate;
      _gamma = discount_rate;
    }

    void observe(std::vector<float>, int action, float reward, std::vector<float>);
  private:
   float _alpha;
   float _gamma; 
};


class MachinePlayer : Player {

  MachinePlayer(EpsilonPolicy policy, QLearner learner) {
    _policy = policy
    _learner = learner
  }
  virtual void interact(Simulation) override;
  private:
    EpsilonPolicy policy;
    MachinePlayer player;
};

int main(){
  QTable g;
  QLearner learn(g);
  GreedyQ q;
  RandomPolicy r;
  EpsilonPolicy policy(q, r);
  MachinePlayer mp(policy, learn);
  BasicBlock bas(mp);

  while (i > 1000) {
	  bas.step();
  }
}
