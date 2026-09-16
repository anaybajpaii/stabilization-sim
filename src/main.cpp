#include "Pendulum.h"
#include <iostream>

int main()
{
    Pendulum myPendulum(0.1, 0.0);

    double dt = 0.01;
    int numSteps = 500;

    for (int i = 0; i < numSteps; i++)
    {
        myPendulum.update(dt);
        std::cout << "Step " << i << ": angle = " << myPendulum.getAngle() << " rad" << std::endl;
    }

    return 0;
}