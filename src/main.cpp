#include "Pendulum.h"
#include "Controller.h"
#include "DataLogger.h"
#include <iostream>

int main()
{
    double initialAngle;
    double length;
    double gain;

    std::cout << "Enter initial angle (radians): ";
    std::cin >> initialAngle;

    std::cout << "Enter pole length (meters): ";
    std::cin >> length;

    std::cout << "Enter controller gain (Kp): ";
    std::cin >> gain;

    Pendulum myPendulum(initialAngle, 0.0, length);
    Controller myController(gain);
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