
#include "rl.h"
#include <iostream>
int main(){
  QTable g;
  QLearner learn(g, 0.05, 0.1);
  GreedyQ q(g);
  RandomPolicy r;
  EpsilonPolicy policy(q, r, 0.5);
  MachinePlayer mp(policy, learn);
  BasicBlock bas(mp);
  int i = 1;
  while (i >= 0 ) {
	  if (i % 9 == 0) {
	    bas.step(true);
	    i++;
	  } else {
		  bas.step(false);
	  i++;
	  }

  }
}
