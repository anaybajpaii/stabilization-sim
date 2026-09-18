#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
public:
    Controller(double gain);

    // Given the current angle, returns a corrective torque to apply
    double computeCorrection(double angle) const;

private:
    double gain; // proportional gain, often called "Kp"
};

#endif