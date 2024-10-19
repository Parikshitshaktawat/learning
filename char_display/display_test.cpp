#include <iostream>
#include <vector>

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

int main() {
    // Grid dimensions: 7 rows, 4 columns
    const int rows = 7;
    const int cols = 4;

    // Initialize the display grid (using 2x width for visual effect)
    vector<vector<char>> display(rows, vector<char>(cols * 2 + 1)); // +1 for the last column pipe

    // Initialize the display with | and _
    initializeDisplay(display);

    // Example: Fill the grid with * to form a pattern or a letter (e.g., "H")
    vector<pair<int, int>> positions = {
        {0, 0}, {0, 3}, // Top corners
        {1, 0}, {1, 3},
        {2, 0}, {2, 3},
        {3, 0}, {3, 1}, {3, 2}, {3, 3}, // Middle horizontal bar
        {4, 0}, {4, 3},
        {5, 0}, {5, 3},
        {6, 0}, {6, 3} // Bottom corners
    };

    // Fill the grid with the pattern
    fillDisplay(display, positions);

    // Display the grid
    displayGrid(display);

    return 0;
}

