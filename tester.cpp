#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <assert.h>
#include "tester.h"
#include "controller.h"
#include "parametercontainer.h"
#include "prisoner.h"

std::vector<Result*> Tester::results;
ParameterContainer* Tester::parameters;
int Tester::NUM_EXECUTIONS;
int Tester::phases[7][100];

void Tester::execute() {


    const int NUM_PRISONERS= Controller::NUM_PRISONERS;
    const int DAYS_PER_ROUND1= parameters->DAYS_PER_ROUND1;
    const int DAYS_PER_ROUND2= parameters->DAYS_PER_ROUND2;

    int DAYS_PHASE1 = parameters->DAYS_PHASE1;
    int DAYS_PHASE2 = parameters->DAYS_PHASE2;
    int DAYS_PHASE3 = parameters->DAYS_PHASE3;
    int DAYS_PHASE4 = parameters->DAYS_PHASE4;
    int DAYS_PHASE5 = parameters->DAYS_PHASE5;
    int DAYS_PHASE6 = parameters->DAYS_PHASE6;
    int DAYS_PHASE7 = parameters->DAYS_PHASE7;
    int DAYS_PHASE8 = parameters->DAYS_PHASE8;

    const int NUM_ROUNDS = 4;

    bool lightbulb;
    bool daysAllVisitedYetAssigned = false;

    Prisoner* prisoners = new Prisoner[NUM_PRISONERS];
    Result* result = new Result();

    int day = 0;
    int round =0;

    for (int i = 0;i<28;++i)
    {
        prisoners[i].count++;
    }

    /////////
    //
    //phase 1:
    //
    //////////

    while (day <DAYS_PHASE1)
    {
        int r = (int)(rand() % NUM_PRISONERS);
        Prisoner * chosen = &prisoners[r];

        round = (day%DAYS_PER_ROUND1);
        if (!lightbulb && chosen->count != 0 && !(round == DAYS_PER_ROUND1-1))
        {
            chosen->count -= 1;
        }
        else if (!lightbulb && chosen->count == 0 && (round != DAYS_PER_ROUND1-1))
        {
               lightbulb = true;
               chosen->count += round;
               chosen->isCounter = true;
        }
        else if (!lightbulb && (round == DAYS_PER_ROUND1-1))
        {
                chosen->count += round;
                chosen->isCounter = true;
        }
        else if (round == DAYS_PER_ROUND1-1)
        {
                if (!lightbulb)
                {
                    chosen->count += DAYS_PER_ROUND1-1;
                    chosen->isCounter = true;
                }
                else
                {
                    lightbulb = false;
                }
        }
        chosen->hasBeen = true;
    //    std::cout << round << std::endl;
    //    std::cout << Controller::total(prisoners) << std::endl;
    //    Controller::printArray(prisoners);
        if (Controller::allVisited(prisoners) && !daysAllVisitedYetAssigned)
        {
            result->daysAllVisit = day;
            daysAllVisitedYetAssigned = true;
        }
        day++;
    }

    day = DAYS_PHASE1;
    result->daysAllVisit = -1;
    int macroPhase = 0;
    while (result->daysAllVisit == -1)
    {

        if (macroPhase>1) {

//         DAYS_PHASE1 =  100;
//         DAYS_PHASE2 = 100;
//         DAYS_PHASE3 = 100;
//        DAYS_PHASE4 = 100;
//        DAYS_PHASE5 = 100;
//        DAYS_PHASE6 = 100;
//        DAYS_PHASE7 = 100;
//         DAYS_PHASE8 = 100;


        }
    for (int i = 0;i<7;++i) {
    result->daysAllVisit = Tester::phase(day,day+Tester::phases[i][macroPhase],pow(2,i),false,daysAllVisitedYetAssigned,prisoners,result);
    day += Tester::phases[i][macroPhase];

    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,i);

    }

/*
    /////////
    //
    //phase 2:
    //
    //////////
    result->daysAllVisit = Tester::phase(day,macroPhase*macroPhaseDays+DAYS_PHASE1+DAYS_PHASE2,pow(2,0),false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+macroPhaseDays*macroPhase;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,0);
    ///////////
    //
    //Phase 3:
    //
    /////
    //return 0;
    result->daysAllVisit = Tester::phase(day,macroPhase*macroPhaseDays+DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3,2,false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+macroPhaseDays*macroPhase;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,1);
    ///////////
    //
    //Phase 3:
    //
    /////
    //return 0;
    result->daysAllVisit = Tester::phase(day,macroPhaseDays*macroPhase+DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4,pow(2,2),false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+macroPhaseDays*macroPhase;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,2);

    result->daysAllVisit = Tester::phase(day,macroPhaseDays*macroPhase+DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5,pow(2,3),false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+macroPhase*macroPhaseDays;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,3);

    result->daysAllVisit = Tester::phase(day,macroPhase*macroPhaseDays+DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+DAYS_PHASE6,pow(2,4),false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+DAYS_PHASE6+macroPhase*macroPhaseDays;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,4);

    result->daysAllVisit = Tester::phase(day,macroPhase*macroPhaseDays+DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+DAYS_PHASE6+DAYS_PHASE7,pow(2,5),false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+DAYS_PHASE6+DAYS_PHASE7+macroPhaseDays*macroPhase;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,5);

    result->daysAllVisit = Tester::phase(day,macroPhaseDays*macroPhase+DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+DAYS_PHASE6+DAYS_PHASE7+DAYS_PHASE8,pow(2,6),false,daysAllVisitedYetAssigned,prisoners,result);
    day = DAYS_PHASE1+DAYS_PHASE2+DAYS_PHASE3+DAYS_PHASE4+DAYS_PHASE5+DAYS_PHASE6+DAYS_PHASE7+DAYS_PHASE8+macroPhaseDays*macroPhase;
    if (result->daysAllVisit>0)
    {
        break;
    }
    Controller::fillResultPhases(prisoners,6);
    if (macroPhase>2) {
      //  result->daysAllVisit = day;
    }*/
    macroPhase++;
    }

    ///////////
    //
    //Phase 4:
    //
    /////
    //return 0;

    Controller::fillResult(prisoners,*result);
    Tester::results.push_back(result);
    delete[] prisoners;
}

struct mean
{
    float n;
    mean() : n(0) {}
    float operator() (float f,Result * result)
    {
        if (result->daysAllVisit > 0)
        {
            n++;
            f *= ((n-1)/n);
            f += (result ->daysAllVisit)/n;
        }
    return f;
    }
};
struct successrate
{
    int operator() (int count,Result * result)
    {
    if (result->daysAllVisit == -1) {
        count++;
    }
    return count;
    }
};

int Tester::executeAll()
{
    Tester::results.clear();
    srand(time(NULL));
    for (int i =0;i<Tester::NUM_EXECUTIONS;++i)
    {
        Tester::execute();
    }
    std::for_each(Tester::results.begin(),Tester::results.end(),Controller::printResult);

    for (int i=0;i<7;i++) {
        std::cout << " " << Tester::failedPhase[i];
    }
    std::cout << std::endl;

    float totalAverage = std::accumulate(Tester::results.begin(),Tester::results.end(),0,mean());
    int successRate = Tester::NUM_EXECUTIONS-std::accumulate(Tester::results.begin(),Tester::results.end(),0,successrate());
    std::cout << totalAverage << std::endl;
    std::cout << successRate << std::endl;
    return totalAverage;
}

int Tester::phase(int currentDay, int untilDay,int tokenValue,bool lightbulb,bool daysAllVisitedYetAssigned, Prisoner* prisoners,Result* result)
{
    int day = currentDay;
    int round = tokenValue;
    while (day < untilDay)
    {
        int r = (int)(rand() % Controller::NUM_PRISONERS);
        Prisoner * chosen = &prisoners[r];


        if (!lightbulb && ((chosen->count & round) >= round) && (day != (untilDay-1)))
        {
                lightbulb = true;
                chosen->count -= round;
        }
        else if (lightbulb && ((chosen->count & round) >= round))
        {
               lightbulb = false;
               chosen->count += round;
               if (chosen->count == FINAL_VALUE) {
                  return day;
               }
        }
        else if (lightbulb && (day == (untilDay-1)) )
        {
                chosen->count += round;
                lightbulb = false;
        }

   //    std::cout << Controller::total(prisoners) << std::endl;
    //    if (lightbulb)
    //        std::cout << round << std::endl;
    //    std::cout << day << std::endl;
    //    Controller::printArray(prisoners);
        day++;
    }
    assert(Controller::total(prisoners) == FINAL_VALUE);
    return -1;
}

int daysInMacroPhase(int macroPhase)
{
    int sum = 0;
    for (int i =0;i<7;i++)
    {
     sum += Tester::phases[i][macroPhase];
    }
    return sum;
}
