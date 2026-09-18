#include "Pendulum.h"
#include "Controller.h"
#include "DataLogger.h"
#include <iostream>

int main()
{
    Pendulum myPendulum(0.1, 0.0);
    Controller myController(5.0);
    DataLogger logger("data/controlled.csv");

    double dt = 0.01;
    int numSteps = 500;

    for (int i = 0; i < numSteps; i++)
    {
        double correction = myController.computeCorrection(myPendulum.getAngle());
        myPendulum.update(dt, correction);
        double time = i * dt;
        logger.logStep(i, time, myPendulum.getAngle());
        std::cout << "Step " << i << ": angle = " << myPendulum.getAngle() << " rad" << std::endl;
    }

    return 0;
}