#include "Pendulum.h"
#include <cmath>

Pendulum::Pendulum(double initialAngle, double initialAngularVelocity)
{
    angle = initialAngle;
    angularVelocity = initialAngularVelocity;
}

void Pendulum::update(double dt, double controlTorque)
{
    double angularAcceleration = (GRAVITY / LENGTH) * sin(angle) + controlTorque;
    angularVelocity = angularVelocity + (angularAcceleration * dt);
    angle = angle + angularVelocity * dt;
}

double Pendulum::getAngle() const
{
    return angle;
}

double Pendulum::getAngularVelocity() const
{
    return angularVelocity;
}