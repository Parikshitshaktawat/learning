#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to initialize the display with underscores and pipes
void initializeDisplay(vector<vector<char>>& display) {
    for (int i = 0; i < display.size(); ++i) {
        for (int j = 0; j < display[i].size(); ++j) {
            if (j % 2 == 0) {
                display[i][j] = '|';  // Vertical separator
            } else {
                display[i][j] = '_';  // Horizontal separator
            }
        }
    }
}

// Function to fill the grid with * to form a letter
void fillDisplay(vector<vector<char>>& display, const vector<pair<int, int>>& positions) {
    for (const auto& pos : positions) {
        display[pos.first][pos.second * 2 + 1] = '*';  // Correct placement of '*' inside the blocks
    }
}

// Function to display the grid
void displayGrid(const vector<vector<char>>& display) {
    for (const auto& row : display) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

// Function to return the positions for a given letter
vector<pair<int, int>> getLetterPattern(char letter) {
    unordered_map<char, vector<pair<int, int>>> patterns;

    // Pattern for H
    patterns['H'] = {
        {0, 0}, {0, 3},
        {1, 0}, {1, 3},
        {2, 0}, {2, 3},
        {3, 0}, {3, 1}, {3, 2}, {3, 3},  // Middle bar
        {4, 0}, {4, 3},
        {5, 0}, {5, 3},
        {6, 0}, {6, 3}
    };

    // Pattern for C (ensuring first and last row, last column is also filled)
    patterns['C'] = {
        {0, 0}, {0, 1}, {0, 2}, {0, 3},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0}, {6, 1}, {6, 2}, {6, 3}
    };

    // Add more letter patterns here
    patterns['O'] = {
        {0, 0}, {0, 1}, {0, 2}, {0, 3},
        {1, 0}, {1, 3},
        {2, 0}, {2, 3},
        {3, 0}, {3, 3},
        {4, 0}, {4, 3},
        {5, 0}, {5, 3},
        {6, 0}, {6, 1}, {6, 2}, {6, 3}
    };

    patterns['E'] = {
        {0, 0}, {0, 1}, {0, 2}, {0, 3},
        {1, 0},
        {2, 0},
        {3, 0}, {3, 1}, {3, 2}, 
        {4, 0},
        {5, 0},
        {6, 0}, {6, 1}, {6, 2}, {6, 3}
    };

    patterns['L'] = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0}, {6, 1}, {6, 2}, {6, 3}
    };

    // Default pattern if letter is not defined
    if (patterns.find(letter) != patterns.end()) {
        return patterns[letter];
    }

    return {};  // Empty if no pattern found
}

// Function to process a word and display it using a grid for each character
void processWord(string word) {
    for (char& c : word) {
        c = toupper(c);  // Convert to uppercase
        vector<vector<char>> display(7, vector<char>(4 * 2 + 1));  // Initialize 7x4 grid for each letter

        initializeDisplay(display);  // Initialize the grid with | and _
        vector<pair<int, int>> positions = getLetterPattern(c);  // Get positions for the letter
        fillDisplay(display, positions);  // Fill grid with the letter pattern
        displayGrid(display);  // Display the letter grid
        cout << endl;
    }
}

int main() {
    string word = "HELLO";
    processWord(word);  // Display the word "HELLO" in grid format

    return 0;
}

