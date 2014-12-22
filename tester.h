#ifndef TESTER_H
#define TESTER_H

#include <vector>
#include "parametercontainer.h"
#include "result.h"

struct Prisoner;
class Tester {
    private:
    public :
      static int NUM_EXECUTIONS;
      static const int FINAL_VALUE = 128;
      static int phases[7][100];
      static std::vector<Result*> results;
      static ParameterContainer* parameters;
      static int failedPhase[7];

      static void execute();
      static int  executeAll();
      static int phase(int currentDay, int untilDay,int tokenValue,bool lightbulb,bool daysAllVisitedYetAssigned, Prisoner* prisoners,Result* result);

};

#endif
