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
        grid[pos.first][pos.second] = '*'; // Mark with an asterisk
    }
}

// Function to display the grid
void displayGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << "|" << cell;
        }
        cout << "|" << endl; // New line for the next row
    }
}

// Function to get the positions for each letter of "Hello World!"
vector<vector<pair<int, int>>> getHelloWorldPositions() {
    // These are the grid positions to push on GitHub for each letter across the months
    return {
        // H (January) - Fill first and last column, and the middle row
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {3, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
        
        // E (February) - Fill first column and two horizontal rows
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {0, 2}, {3, 2}, {6, 2}},
        
        // L (March) - Fill first column, bottom row
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {6, 2}},
        
        // L (April) - Same as March
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {6, 2}},
        
        // O (May) - Fill first and last column, top and bottom row
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {6, 0}, {5, 0}, {6, 2}, {5, 2}},
        
        // W (June) - First and last columns, with diagonal towards center
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {6, 0}, {0, 2}, {6, 2}, {5, 2}, {3, 1}},
        
        // O (July) - Same as May
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {6, 0}, {5, 0}, {6, 2}, {5, 2}},
        
        // R (August) - Fill first and middle columns, with diagonal
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 2}, {3, 1}, {2, 1}},
        
        // L (September) - Same as March
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {6, 2}},
        
        // D (October) - Fill first column, and outer columns of the middle rows
        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {6, 0}, {0, 2}, {1, 2}, {2, 2}, {6, 2}},
        
        // ! (November) - Fill only the center column
        {{0, 1}, {1, 1}, {2, 1}, {5, 1}},
    };
}

int main() {
    // Grid dimensions for each month: 7 rows and 4 columns
    const int rows = 7;
    const int cols = 4;

    // Create grids for each month
    vector<vector<vector<char>>> grids(12, vector<vector<char>>(rows, vector<char>(cols)));

    // Initialize all grids
    for (auto& grid : grids) {
        initializeGrid(grid);
    }

    // Get the positions for "Hello World!"
    vector<vector<pair<int, int>>> helloWorldPositions = getHelloWorldPositions();

    // Mark contributions for each month
    for (int month = 0; month < 12; ++month) {
        if (month < helloWorldPositions.size()) {
            markContributions(grids[month], helloWorldPositions[month]);
        }
    }

    // Display the grids for each month
    for (int month = 0; month < 12; ++month) {
        cout << "Month " << (month + 1) << " contribution grid:" << endl;
        displayGrid(grids[month]);
        cout << endl;
    }

    return 0;
}

