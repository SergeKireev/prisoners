#ifndef CONTROLLER_H
#define CONTROLLER_H

class Prisoner;

struct Result;
class Tester;

class Controller {
  public :
      static const int NUM_PRISONERS = 100;
      static const int NUM_ROUNDS = 40;
      static const int DAYS_PER_ROUND = 40;

      static bool isSolved(Prisoner* prisoners);
      static void printArray(Prisoner* prisoners);
      static int total(Prisoner* prisoners);
      static bool allVisited(Prisoner* prisoners);
      static void fillResult(Prisoner* prisoners,Result& result);
      static void printResult(Result* result);
      static void fillResultPhases(Prisoner* prisoners,int phase);
};

#endif
