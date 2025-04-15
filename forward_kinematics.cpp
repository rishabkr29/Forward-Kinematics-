#include <iostream>
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

const double L = 1.0; // Link length (1 meter)

// Rotation about Z axis
Matrix4d rotZ(double theta) {
    Matrix4d m = Matrix4d::Identity();
    m(0,0) = cos(theta); m(0,1) = -sin(theta);
    m(1,0) = sin(theta); m(1,1) = cos(theta);
    return m;
}

// Rotation about Y axis
Matrix4d rotY(double theta) {
    Matrix4d m = Matrix4d::Identity();
    m(0,0) = cos(theta);  m(0,2) = sin(theta);
    m(2,0) = -sin(theta); m(2,2) = cos(theta);
    return m;
}

// Rotation about X axis
Matrix4d rotX(double theta) {
    Matrix4d m = Matrix4d::Identity();
    m(1,1) = cos(theta); m(1,2) = -sin(theta);
    m(2,1) = sin(theta); m(2,2) = cos(theta);
    return m;
}

// Translation along X axis (link direction)
Matrix4d translateX(double d) {
    Matrix4d m = Matrix4d::Identity();
    m(0,3) = d;
    return m;
}

// Compute Forward Kinematics
Vector3d computeFK(double j1, double j2, double j3, double j4) {
    // Chain of transforms: T = T1 * T2 * T3 * T4
    Matrix4d T1 = rotZ(j1) * translateX(L);
    Matrix4d T2 = rotY(j2) * translateX(L);
    Matrix4d T3 = rotX(j3) * translateX(L);
    Matrix4d T4 = rotY(j4) * translateX(L);

    Matrix4d T = T1 * T2 * T3 * T4;

    // End-effector position in homogeneous coordinates
    Vector4d end_effector = T * Vector4d(0, 0, 0, 1);
    return end_effector.head<3>(); // Return x, y, z
}

int main() {
    // Example joint angles in radians
    double j1 = M_PI / 4; // 45 deg
    double j2 = M_PI / 6; // 30 deg
    double j3 = M_PI / 3; // 60 deg
    double j4 = M_PI / 4; // 45 deg

    Vector3d position = computeFK(j1, j2, j3, j4);
    cout << "End-effector position:\n";
    cout << "  x: " << position.x() << " m\n";
    cout << "  y: " << position.y() << " m\n";
    cout << "  z: " << position.z() << " m\n";

    return 0;
}
