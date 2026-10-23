#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <iostream>
#include <string>
#include <map>

class GroceryTracker {
public:
    // Constructor: loads data from file and creates backup file
    GroceryTracker();

    // Searches for an item and returns its frequency count
    int SearchItem(const std::string& item) const;

    // Prints all items and their frequencies
    void PrintAllFrequencies() const;

    // Prints a histogram using asterisks
    void PrintHistogram() const;

private:
    std::map<std::string, int> itemFrequencyMap;

    // Helper functions
    void LoadDataFromFile(const std::string& inputFilename);
    void CreateBackupFile(const std::string& outputFilename) const;
};

#endif // GROCERY_TRACKER_H