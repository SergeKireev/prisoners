#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "tester.h"
#include "parametercontainer.h"

int main ()
{
  Tester::parameters = new ParameterContainer();
  int i = 0;
  int days = 10000;
  int result = 10000;
  int maxSuccessRateParameter;
  while  (result <= days)
  {
  days = result;
  Tester::NUM_EXECUTIONS = 1000;
  Tester::parameters->DAYS_PER_ROUND1 = 20;
  Tester::parameters->DAYS_PER_ROUND2 = 100;


  Tester::parameters->DAYS_PHASE1 = 60;
  Tester::phases[0][0] = 780;
  Tester::phases[1][0] = 720;
  Tester::phases[2][0] = 640;
  Tester::phases[3][0] = 590;
  Tester::phases[4][0] = 540;
  Tester::phases[5][0] = 510;
  Tester::phases[6][0] = 500;
  for (int x = 0;x<7;++x)
  {
    for (int y = 1;y<100;++y)
    {
        Tester::phases[x][y] = 200+30*x;
    }
  }
  result = Tester::executeAll();
  i++;
  maxSuccessRateParameter = Tester::parameters->DAYS_PHASE1;
  }
  std::cout << "maximum de succès :" << result << std::endl;
  std::cout << "valeur du paramètre" << maxSuccessRateParameter << std::endl;
  return 0;
}
