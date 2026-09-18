#include "Controller.h"

Controller::Controller(double gain)
{
    this->gain = gain;
}

double Controller::computeCorrection(double angle) const
{
    return -gain * angle;
}