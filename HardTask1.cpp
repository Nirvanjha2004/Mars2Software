#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream file("sample.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // To store obstacle positions in all 4 directions
    vector<vector<int>> obstacles;
    int n1, e, s, w;
    int maxDistance = 0;

    // Read the obstacle file
    while (file >> n1 >> e >> s >> w) {
        obstacles.push_back({n1, e, s, w});
        maxDistance = max({maxDistance, n1, e, s, w});
    }

    int gridSize = 2 * maxDistance + 1; // to safely include both directions
    vector<vector<int>> arena(gridSize, vector<int>(gridSize, 1)); // fill with safe = 1

    // Starting point at center
    int startX = maxDistance;
    int startY = maxDistance;

    // Mark obstacles as 0
    for (const auto& obs : obstacles) {
        int n = obs[0], e = obs[1], s = obs[2], w = obs[3];

        if (n != 0) arena[startX - n][startY] = 0;
        if (e != 0) arena[startX][startY + e] = 0;
        if (s != 0) arena[startX + s][startY] = 0;
        if (w != 0) arena[startX][startY - w] = 0;
    }

    // Print arena
    cout << "Arena Map (0 = Obstacle, 1 = Safe):\n";
    for (const auto& row : arena) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}