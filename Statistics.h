#ifndef STATISTICS_H
#define STATISTICS_H

#include "WeatherData.h"

class Statistics {
public:
    static void displayStatistics(const WeatherData& weatherData);

private:
    static double calculateAverageTemperature(const std::vector<WeatherRecord>& data);
    static double findMaxTemperature(const std::vector<WeatherRecord>& data);
    static double findMinTemperature(const std::vector<WeatherRecord>& data);
    static std::string mostCommonCondition(const std::vector<WeatherRecord>& data);
};

#endif // STATISTICS_H
