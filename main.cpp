#include <iostream>
#include "WeatherData.h"
#include "Statistics.h"

void displayMenu() {
    std::cout << "Weather Data Analysis\n";
    std::cout << "1. Load Data\n";
    std::cout << "2. Display Statistics\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    WeatherData weatherData;
    int choice;
    std::string filename;

    do {
        displayMenu();
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter the filename: ";
                std::cin >> filename;
                if (weatherData.loadFromFile(filename)) {
                    std::cout << "Data loaded successfully.\n";
                } else {
                    std::cout << "Failed to load data.\n";
                }
                break;
            case 2:
                Statistics::displayStatistics(weatherData);
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
