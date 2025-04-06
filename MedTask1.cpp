#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate Euclidean distance
double calculateDistance(int x, int y, int z) {
    return sqrt(x * x + y * y + z * z);
}

// Function to adjust coordinates based on new reference frame
void adjustCoordinates(int x, int y, int z, int offset, int& x_final, int& y_final, int& z_final) {
    x_final = x - offset; // move back by 55 cm
    y_final = y;
    z_final = z;
}

int main() {
    // Marker coordinates from the camera frame
    int x, y, z = -60;
    cout << "Enter marker coordinates (x y): ";
    cin >> x >> y;

    // Camera offset from rover center (55 cm forward)
    int offset = 55;

    // Adjusted coordinates
    int x_final, y_final, z_final;
    adjustCoordinates(x, y, z, offset, x_final, y_final, z_final);

    // Calculate distances
    double dist_from_camera = calculateDistance(x, y, z);
    double dist_from_rover = calculateDistance(x_final, y_final, z_final);

    // Output results
    cout << "\nOriginal Coordinates (Camera frame): (" << x << ", " << y << ", " << z << ")\n";
    cout << "Adjusted Coordinates (Rover center frame): (" << x_final << ", " << y_final << ", " << z_final << ")\n";
    cout << "Distance from Camera: " << dist_from_camera << " cm\n";
    cout << "Distance from Rover Center: " << dist_from_rover << " cm\n";

    return 0;
}