#include "../src/Controller.h"
#include <iostream>
#include <cassert>
#include <cmath>

bool approxEqual(double a, double b, double tolerance = 1e-9)
{
    return std::fabs(a - b) < tolerance;
}

void testZeroAngleGivesZeroCorrection()
{
    Controller c(5.0);
    double result = c.computeCorrection(0.0);
    assert(approxEqual(result, 0.0));
    std::cout << "testZeroAngleGivesZeroCorrection passed" << std::endl;
}

void testPositiveAngleGivesNegativeCorrection()
{
    Controller c(5.0);
    double result = c.computeCorrection(0.2);
    assert(result < 0.0);
    std::cout << "testPositiveAngleGivesNegativeCorrection passed" << std::endl;
}

void testNegativeAngleGivesPositiveCorrection()
{
    Controller c(5.0);
    double result = c.computeCorrection(-0.2);
    assert(result > 0.0);
    std::cout << "testNegativeAngleGivesPositiveCorrection passed" << std::endl;
}

void testCorrectionScalesWithGain()
{
    Controller lowGain(2.0);
    Controller highGain(10.0);
    double angle = 0.3;

    double lowResult = lowGain.computeCorrection(angle);
    double highResult = highGain.computeCorrection(angle);

    assert(std::fabs(highResult) > std::fabs(lowResult));
    std::cout << "testCorrectionScalesWithGain passed" << std::endl;
}

void testExactFormula()
{
    Controller c(4.0);
    double result = c.computeCorrection(0.5);
    assert(approxEqual(result, -2.0));
    std::cout << "testExactFormula passed" << std::endl;
}

int main()
{
    testZeroAngleGivesZeroCorrection();
    testPositiveAngleGivesNegativeCorrection();
    testNegativeAngleGivesPositiveCorrection();
    testCorrectionScalesWithGain();
    testExactFormula();

    std::cout << "All tests passed." << std::endl;
    return 0;
}