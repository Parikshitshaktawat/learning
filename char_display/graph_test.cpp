#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the grid with spaces
void initializeGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            grid[i][j] = ' '; // Initialize with spaces
        }
    }
}

// Function to mark contributions in the grid
void markContributions(vector<vector<char>>& grid, const vector<pair<int, int>>& positions) {
    for (const auto& pos : positions) {
        int row = pos.first;
        int col = pos.second;
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size()) {
            grid[row][col] = '*'; // Mark with an asterisk
        }
    }
}

// Function to display the grid
void displayGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell << " "; // Print each cell with a space
        }
        cout << endl; // New line for the next row
    }
}

// Function to convert a day of the year to a row and column
pair<int, int> dayToGridPosition(int dayOfYear) {
    int col = (dayOfYear - 1) % 54; // Columns range from 0 to 53
    int row = (dayOfYear - 1) / 54; // Rows range from 0 to 6
    return {row, col};
}

int main() {
    // Grid dimensions: 7 rows and 54 columns
    const int rows = 7;
    const int cols = 54;

    // Create a 2D grid
    vector<vector<char>> grid(rows, vector<char>(cols));

    // Initialize the grid with spaces
    initializeGrid(grid);

    // Example coordinates to form "Hello World!"
    vector<pair<int, int>> helloWorldPositions = {
        // H
        {1, 2}, {2, 2}, {3, 2}, {4, 2}, {3, 3}, {1, 4}, {2, 4}, {3, 4}, {4, 4},
        // E
        {1, 6}, {2, 6}, {3, 6}, {4, 6}, {1, 7}, {3, 7}, {4, 7},
        // L
        {1, 9}, {2, 9}, {3, 9}, {4, 9}, {4, 10},
        // L
        {1, 12}, {2, 12}, {3, 12}, {4, 12}, {4, 13},
        // O
        {1, 15}, {2, 15}, {3, 15}, {4, 15}, {1, 16}, {4, 16}, {1, 17}, {2, 17}, {3, 17}, {4, 17},
        // W
        {1, 20}, {2, 20}, {3, 20}, {4, 20}, {2, 21}, {3, 21}, {4, 21}, {1, 22}, {4, 22},
        // O
        {1, 24}, {2, 24}, {3, 24}, {4, 24}, {1, 25}, {4, 25}, {1, 26}, {2, 26}, {3, 26}, {4, 26},
        // R
        {1, 28}, {2, 28}, {3, 28}, {4, 28}, {1, 29}, {3, 29}, {1, 30}, {2, 30}, {4, 30},
        // L
        {1, 32}, {2, 32}, {3, 32}, {4, 32}, {4, 33},
        // D
        {1, 35}, {2, 35}, {3, 35}, {4, 35}, {1, 36}, {4, 36}, {1, 37}, {2, 37}, {3, 37}, {4, 37},
        // !
        {1, 39}, {3, 39}, {4, 39}
    };

    // Mark the positions on the grid
    markContributions(grid, helloWorldPositions);

    // Display the contribution graph
    cout << "Simulated GitHub Contribution Grid: 'Hello World!'" << endl;
    displayGrid(grid);

    // Output the days of the year to push for "Hello World!"
    cout << "\nDays to push on GitHub to spell 'Hello World!':" << endl;
    for (const auto& pos : helloWorldPositions) {
        int dayOfYear = pos.second + (pos.first * cols) + 1; // Calculate day of year (1-based)
        cout << "Day " << dayOfYear << endl; // Output the day
    }

    return 0;
}

