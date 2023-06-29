#include <iostream>     // For input/output stream
#include <algorithm>    // For string transformation functions  
#include <string>       // For string handling

// Function to check if two strings are anagrams of each other
bool areAnagrams(const std::string& str1, const std::string& str2) {
    // Convert the strings to lowercase and remove any spaces
    std::string modifiedStr1 = str1;
    std::string modifiedStr2 = str2;

    // Remove spaces from the strings
    modifiedStr1.erase(std::remove_if(modifiedStr1.begin(), modifiedStr1.end(), ::isspace), modifiedStr1.end());
    modifiedStr2.erase(std::remove_if(modifiedStr2.begin(), modifiedStr2.end(), ::isspace), modifiedStr2.end());

    // Convert the strings to lowercase
    std::transform(modifiedStr1.begin(), modifiedStr1.end(), modifiedStr1.begin(), ::tolower);
    std::transform(modifiedStr2.begin(), modifiedStr2.end(), modifiedStr2.begin(), ::tolower);

    // Sort the modified strings
    std::sort(modifiedStr1.begin(), modifiedStr1.end());
    std::sort(modifiedStr2.begin(), modifiedStr2.end());

    // Compare the sorted strings
    return modifiedStr1 == modifiedStr2;
}

int main() {
    std::string string1, string2;
    char continueChoice = 'Y';

    // Continue the loop as long as the user wants to check anagrams
    while (continueChoice == 'Y' || continueChoice == 'y') {
        // Get the input strings from the user
        std::cout << "Enter the first string: ";
        std::getline(std::cin, string1);

        std::cout << "Enter the second string: ";
        std::getline(std::cin, string2);

        // Check if the strings are anagrams
        if (areAnagrams(string1, string2)) {
            std::cout << "The strings are anagrams." << std::endl;
        }
        else {
            std::cout << "The strings are not anagrams." << std::endl;
        }

        // Prompt the user to continue or exit
        std::cout << "Do you want to continue? (Y/N): ";
        std::cin >> continueChoice;
        std::cin.ignore(); // Ignore the newline character
    }

    return 0;
}
