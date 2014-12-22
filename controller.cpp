#include <string>
#include <iostream>
#include <math.h>
#include "tester.h"
#include "controller.h"
#include "result.h"
#include "prisoner.h"

int Tester::failedPhase[7];

void Controller::printArray(Prisoner* prisoners) {
    for (int i=0;i<Controller::NUM_PRISONERS;i++) {
        std::cout << prisoners[i].count  << ' ';
    }
    std::cout << std::endl;
}

bool Controller::isSolved(Prisoner* prisoners) {
    for (int i=0;i<Controller::NUM_PRISONERS;i++) {
        if (prisoners[i].count >Controller::NUM_PRISONERS) {
            return true;
        }
    }
    return false;
}

bool Controller::allVisited(Prisoner* prisoners)
{
    for (int i=0;i<Controller::NUM_PRISONERS;i++) {
        if (!(prisoners[i].hasBeen)) {
            return false;
        }
    }
    return true;
}

int Controller::total(Prisoner* prisoners) {
    int total = 0;
    for (int i=0;i<Controller::NUM_PRISONERS;i++) {
        Prisoner * tmp = &prisoners[i];
        total += tmp->count;
    }
    return total;
}

void Controller::fillResult(Prisoner* prisoners,Result& result) {
    int max = 0;
    for (int i = 0;i<Controller::NUM_PRISONERS;i++)
    {
        Prisoner * tmp = &prisoners[i];
        for (int j = 0;j<5;++j)
        {
            if (tmp->count == (j+1))
            {
                result.noise[j] += 1;
            }
        }
        if (tmp->count > max)
        {
            max = tmp->count;
        }
    }
    result.maxCount = max;
}

void Controller::fillResultPhases(Prisoner* prisoners, int phase) {
    for (int i =0; i<Controller::NUM_PRISONERS;i++)
    {
        if (prisoners[i].count == pow(2,phase)) {
          Tester::failedPhase[phase] += 1;
        }
    }
}

void Controller::printResult(Result* result)
{
    std::cout << "Les prisonniers ont tous visité au jour"  << result->daysAllVisit;
    std::cout << std::endl;

}
