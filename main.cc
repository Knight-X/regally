
#include "rl.h"
#include "simulator.h"
#include <iostream>
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
