#include "DataLogger.h"

DataLogger::DataLogger(const std::string& filename)
{
    file.open(filename);
    file << "step,time,angle\n";
}

DataLogger::~DataLogger()
{
    file.close();
}

void DataLogger::logStep(int step, double time, double angle)
{
    file << step << "," << time << "," << angle << "\n";
}