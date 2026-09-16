#include "Pendulum.h"
#include "DataLogger.h"
#include <iostream>

int main()
{
    Pendulum myPendulum(0.1, 0.0);
    DataLogger logger("data/uncontrolled.csv");

    double dt = 0.01;
    int numSteps = 500;

    for (int i = 0; i < numSteps; i++)
    {
        myPendulum.update(dt);
        double time = i * dt;
        logger.logStep(i, time, myPendulum.getAngle());
        std::cout << "Step " << i << ": angle = " << myPendulum.getAngle() << " rad" << std::endl;
    }

    return 0;
}