#ifndef PENDULUM_H
#define PENDULUM_H

class Pendulum 
{
public:
    Pendulum(double initialAngle, double initialAngularVelocity, double length);
    void update(double dt, double controlTorque);
    double getAngle() const;
    double getAngularVelocity() const;

private:
    double angle;
    double angularVelocity;
    double length;
    static constexpr double GRAVITY = 9.81;
};

#endif