#include "Statistics.h"
#include <iostream>
#include <map>

void Statistics::displayStatistics(const WeatherData& weatherData) {
    const auto& data = weatherData.getData();
    if (data.empty()) {
        std::cout << "No data available.\n";
        return;
    }

    std::cout << "Average Temperature: " << calculateAverageTemperature(data) << "°C\n";
    std::cout << "Max Temperature: " << findMaxTemperature(data) << "°C\n";
    std::cout << "Min Temperature: " << findMinTemperature(data) << "°C\n";
    std::cout << "Most Common Condition: " << mostCommonCondition(data) << "\n";
}

double Statistics::calculateAverageTemperature(const std::vector<WeatherRecord>& data) {
    double sum = 0.0;
    for (const auto& record : data) {
        sum += record.temperature;
    }
    return sum / data.size();
}

double Statistics::findMaxTemperature(const std::vector<WeatherRecord>& data) {
    double maxTemp = data.front().temperature;
    for (const auto& record : data) {
        if (record.temperature > maxTemp) {
            maxTemp = record.temperature;
        }
    }
    return maxTemp;
}

double Statistics::findMinTemperature(const std::vector<WeatherRecord>& data) {
    double minTemp = data.front().temperature;
    for (const auto& record : data) {
        if (record.temperature < minTemp) {
            minTemp = record.temperature;
        }
    }
    return minTemp;
}

std::string Statistics::mostCommonCondition(const std::vector<WeatherRecord>& data) {
    std::map<std::string, int> conditionCount;
    for (const auto& record : data) {
        conditionCount[record.condition]++;
    }

    std::string mostCommon;
    int maxCount = 0;
    for (const auto& condition : conditionCount) {
        if (condition.second > maxCount) {
            mostCommon = condition.first;
            maxCount = condition.second;
        }
    }
    return mostCommon;
}
