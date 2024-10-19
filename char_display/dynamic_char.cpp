#include <iostream>
#include <vector>
#include <unordered_map>

// ANSI escape code for green text
const std::string PREV_GREEN = "\033[32m";  // Green
const std::string BRIGHT_GREEN = "\033[1;32m";  // Bright green color
const std::string BRIGHT_YELLOW = "\033[1;33m"; // Bright yellow color
const std::string RESET = "\033[0m";   // Reset to default color
const std::string GREEN = "\033[01;36m";

// Define the grid for each letter from A to Z
std::unordered_map<char, std::vector<std::string>> letterPatterns = {
    {'A', {"|*|_|*|*|", "|*|_|_|*|", "|*|*|*|*|", "|*|_|_|*|", "|*|_|_|*|"}},
    {'B', {"|*|*|*|_|", "|*|_|_|*|", "|*|*|*|_|", "|*|_|_|*|", "|*|*|*|_|"}},
    {'C', {"|*|*|*|*|", "|*|_|_|_|", "|*|_|_|_|", "|*|_|_|_|", "|*|*|*|*|"}},
    {'D', {"|*|*|*|_|", "|*|_|_|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|*|*|_|"}},
    {'E', {"|*|*|*|*|", "|*|_|_|_|", "|*|*|*|_|", "|*|_|_|_|", "|*|*|*|*|"}},
    {'F', {"|*|*|*|*|", "|*|_|_|_|", "|*|*|*|_|", "|*|_|_|_|", "|*|_|_|_|"}},
    {'G', {"|*|*|*|*|", "|*|_|_|_|", "|*|_|*|*|", "|*|_|_|*|", "|*|*|*|*|"}},
    {'H', {"|*|_|_|*|", "|*|_|_|*|", "|*|*|*|*|", "|*|_|_|*|", "|*|_|_|*|"}},
    {'I', {"|*|*|*|*|", "|_|_*_|_|", "|_|_*_|_|", "|_|_*_|_|", "|*|*|*|*|"}},
    {'J', {"|*|*|*|*|", "|_|_|*|_|", "|_|_|*|_|", "|_|_|*|_|", "|*|_|*|_|"}},
    {'K', {"|*|_|_|*|", "|*|_|*|_|", "|*|*|_|_|", "|*|_|*|_|", "|*|_|_|*|"}},
    {'L', {"|*|_|_|_|", "|*|_|_|_|", "|*|_|_|_|", "|*|_|_|_|", "|*|*|*|*|"}},
    {'M', {"|*|_|_|*|", "|*|*|*|*|", "|*|_*_|*|", "|*|_|_|*|", "|*|_|_|*|"}},
    {'N', {"|*|_|_|*|", "|*|*|_|*|", "|*|_*_|*|", "|*|_|*|*|", "|*|_|_|*|"}},
    {'O', {"|*|*|*|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|*|*|*|"}},
    {'P', {"|*|*|*|*|", "|*|_|_|*|", "|*|*|*|_|", "|*|_|_|_|", "|*|_|_|_|"}},
    {'Q', {"|*|*|*|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|*|*|*|", "|_|_|*|_|"}},
    {'R', {"|*|*|*|_|", "|*|_|_|*|", "|*|*|*|_|", "|*|_|*|_|", "|*|_|_|*|"}},
    {'S', {"|*|*|*|*|", "|*|_|_|_|", "|*|*|*|*|", "|_|_|_|*|", "|*|*|*|*|"}},
    {'T', {"|*|*|*|*|", "|_|_*_|_|", "|_|_*_|_|", "|_|_*_|_|", "|_|_*_|_|"}},
    {'U', {"|*|_|_|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|*|*|*|"}},
    {'V', {"|*|_|_|*|", "|*|_|_|*|", "|*|_|_|*|", "|_|*|*|_|", "|_|_*_|_|"}},
    {'W', {"|*|_|_|*|", "|*|_|_|*|", "|*|_|_|*|", "|*|_*_|_|", "|*|_|_|*|"}},
    {'X', {"|*|_|_|*|", "|_|*|*|_|", "|_|_*_|_|", "|_|*|*|_|", "|*|_|_|*|"}},
    {'Y', {"|*|_|_|*|", "|_|*|*|_|", "|_|_*_|_|", "|_|_*_|_|", "|_|_*_|_|"}},
    {'Z', {"|*|*|*|*|", "|_|_|_|*|", "|_|*|_|_|", "|*|_|_|_|", "|*|*|*|*|"}},
    {' ', {"     ", "     ", "     ", "     ", "     "}}  // Pattern for space
};

// Function to print a string in the 7x4 grid with green stars
void printStringOnGrid(const std::string &input) {
    // Print each row of the grid
    for (int row = 0; row < 5; ++row) {
        for (char letter : input) {
            if (letterPatterns.find(letter) != letterPatterns.end()) {
                // Replace * with green * for printing
                std::string line = letterPatterns[letter][row];
                for (char &c : line) {
                    if (c == '*') {
                        std::cout << GREEN << c << RESET;
                    } else {
                        std::cout << c;
                    }
                }
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Enter the word to print: ";
    std::getline(std::cin, input);  // Allow spaces in the input

    // Convert input to uppercase
    for (char &ch : input) {
        ch = toupper(ch);
    }

    // Print the word in the grid
    printStringOnGrid(input);

    return 0;
}

