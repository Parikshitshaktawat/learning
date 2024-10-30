#include <iostream>
#include <vector>
#include <queue>
#include <opencv2/opencv.hpp> // OpenCV for image handling

using namespace std;
using namespace cv;

// Direction vectors for moving up, down, left, and right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS function to find the shortest path from start to destination in a 2D grid
int bfs(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> dest) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> distance(rows, vector<int>(cols, -1)); // Distance array
    
    // Initialize BFS
    q.push(start);
    distance[start.first][start.second] = 0;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        // Check if we've reached the destination
        if (node == dest) return distance[node.first][node.second];

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];

            // Check bounds and if the cell is open
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[node.first][node.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; // Return -1 if there's no path
}

// Function to load and convert an image into a 2D grid
vector<vector<int>> loadMaze(const string &filename) {
    Mat image = imread(filename, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error loading image" << endl;
        exit(1);
    }

    // Resize image for easier processing if necessary
    if (image.rows > 1000 || image.cols > 1000) {
        resize(image, image, Size(), 0.2, 0.2); // Reduce to 20%
    }

    // Thresholding to ensure binary image (white path, black wall)
    Mat binaryImage;
    threshold(image, binaryImage, 200, 255, THRESH_BINARY);

    // Print image information
    cout << "Image Information:" << endl;
    cout << " - Width: " << binaryImage.cols  << endl;
    cout << " - Height: " << binaryImage.rows << endl;

    // Convert image to grid representation
    vector<vector<int>> grid(binaryImage.rows, vector<int>(binaryImage.cols, 0));
    for (int i = 0; i < binaryImage.rows; ++i) {
        for (int j = 0; j < binaryImage.cols; ++j) {
            grid[i][j] = (binaryImage.at<uchar>(i, j) == 255) ? 1 : 0;
        }
    }

    // Show the binary image for visual confirmation
    // imshow("Maze", binaryImage);
    // waitKey(0);
    return grid;
}

int main() {
    string filename = "map.png";
    vector<vector<int>> grid = loadMaze(filename);

    // Define start and destination points (use coordinates in the resized image if it was resized)
    pair<int, int> start = {50, 50}; // Adjust to be on a white path area
    pair<int, int> dest = {200, 400};  // Adjust to be on a white path area

    // Find shortest path
    int pathLength = bfs(grid, start, dest);

    if (pathLength != -1) {
        cout << "Shortest path length: " << pathLength << endl;
    } else {
        cout << "No path found!" << endl;
    }
    return 0;
}
