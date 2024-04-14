#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <limits>

// Function to parse and store bitcoin prices from a CSV file
void loadBitcoinPrices(const char* filename, std::map<std::string, double>& prices) {
    std::ifstream file(filename);
    std::string line, date;
    double price;

    if (!file.is_open()) {
        std::cerr << "Error: could not open bitcoin price file." << std::endl;
        exit(1);
    }

    while (getline(file, line)) {
        std::stringstream ss(line);
        getline(ss, date, ',');
        ss >> price;
        prices[date] = price;
    }

    file.close();
}

// Function to find the closest lower date in the prices map
std::string findClosestDate(const std::map<std::string, double>& prices, const std::string& inputDate) {
    std::string closestDate = "";
    for (std::map<std::string, double>::const_iterator it = prices.begin(); it != prices.end(); ++it) {
        if (it->first <= inputDate) {
            closestDate = it->first;
        } else {
            break;
        }
    }
    return closestDate;
}

// Main function to handle input and perform calculations
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }

    std::map<std::string, double> bitcoinPrices;
    loadBitcoinPrices("data.csv", bitcoinPrices);

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line, date, valueStr;
    double value;
    while (getline(input, line)) {
        std::stringstream ss(line);
        if (!getline(ss, date, '|') || !getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim spaces
        date.erase(date.find_last_not_of(" \n\r\t")+1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        if (sscanf(valueStr.c_str(), "%lf", &value) != 1 || value <= 0 || value > 1000) {
            std::cerr << "Error: not a valid number." << std::endl;
            continue;
        }

        std::string closestDate = findClosestDate(bitcoinPrices, date);
        if (closestDate.empty()) {
            std::cerr << "Error: no suitable date found in database for " << date << std::endl;
            continue;
        }

        std::cout << closestDate << " => " << value << " = " << (value * bitcoinPrices[closestDate]) << std::endl;
    }

    input.close();
    return 0;
}
