#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <string>
#include <fstream>

class DataLogger {
public:
    DataLogger(const std::string& filename);
    ~DataLogger();

    void logStep(int step, double time, double angle);

private:
    std::ofstream file;
};

#endif