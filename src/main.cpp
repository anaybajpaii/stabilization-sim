#include "Pendulum.h"
#include "Controller.h"
#include "DataLogger.h"
#include <iostream>
#include <string>
#include <vector>

void runScenario(double initialAngle, double length, double gain, const std::string& filename)
{
    Pendulum myPendulum(initialAngle, 0.0, length);
    Controller myController(gain);
    DataLogger logger(filename);

    double dt = 0.01;
    int numSteps = 500;

    for (int i = 0; i < numSteps; i++)
    {
        double correction = myController.computeCorrection(myPendulum.getAngle());
        myPendulum.update(dt, correction);
        double time = i * dt;
        logger.logStep(i, time, myPendulum.getAngle());
    }
}

int main()
{
    double initialAngle;
    double length;

    std::cout << "Enter initial angle (radians): ";
    std::cin >> initialAngle;

    std::cout << "Enter pole length (meters): ";
    std::cin >> length;

    runScenario(initialAngle, length, 1.0, "data/underdamped.csv");
    runScenario(initialAngle, length, 5.0, "data/tuned.csv");
    runScenario(initialAngle, length, 20.0, "data/overdamped.csv");

    std::cout << "Done. Wrote data/underdamped.csv, data/tuned.csv, data/overdamped.csv" << std::endl;

    return 0;
}