#ifndef PENDULUM_H
#define PENDULUM_H

class Pendulum 
{
public:
    Pendulum(double initialAngle, double initialAngularVelocity);
    void update(double dt, double controlTorque);
    double getAngle() const;
    double getAngularVelocity() const;

private:
    double angle;
    double angularVelocity;
    static constexpr double GRAVITY = 9.81;
    static constexpr double LENGTH = 1.0;
};

#endif