#include "GroceryTracker.h"
#include <fstream>
#include <iomanip>
#include <filesystem>

// 1. Constructor
GroceryTracker::GroceryTracker() {
    LoadDataFromFile("CS210_Project_Three_Input_File.txt");
    CreateBackupFile("frequency.dat");
}

// 2. SearchItem
int GroceryTracker::SearchItem(const std::string& item) const {
    auto it = itemFrequencyMap.find(item);
    if (it != itemFrequencyMap.end()) {
        return it->second;
    }
    return 0;
}

// 3. PrintAllFrequencies
void GroceryTracker::PrintAllFrequencies() const {
    std::cout << "\n--- Item Purchase Frequencies ---" << std::endl;
    for (const auto& pair : itemFrequencyMap) {
        std::cout << std::left << std::setw(15) << pair.first
            << " " << pair.second << std::endl;
    }
    std::cout << std::endl;
}

// 4. PrintHistogram
void GroceryTracker::PrintHistogram() const {
    std::cout << "\n--- Purchase Histogram ---" << std::endl;
    for (const auto& pair : itemFrequencyMap) {
        std::cout << std::left << std::setw(15) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// 5. LoadDataFromFile
void GroceryTracker::LoadDataFromFile(const std::string& inputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        inputFile.open("../" + inputFilename);
    }

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file \"" << inputFilename << "\"." << std::endl;
        std::cerr << "Expected in: " << std::filesystem::current_path() << std::endl;
        return;
    }

    std::string item;
    while (inputFile >> item) {
        itemFrequencyMap[item]++;
    }
    inputFile.close();
}

// 6. CreateBackupFile
void GroceryTracker::CreateBackupFile(const std::string& outputFilename) const {
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create backup file \"" << outputFilename << "\"." << std::endl;
        return;
    }

    for (const auto& pair : itemFrequencyMap) {
        outputFile << pair.first << " " << pair.second << "\n";
    }
    outputFile.close();
}