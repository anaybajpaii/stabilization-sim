#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
public:
    Controller(double gain);
    double computeCorrection(double angle) const;

private:
    double gain;
};

#endif