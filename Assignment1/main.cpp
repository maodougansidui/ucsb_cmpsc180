// DO NOT EDIT REST OF THE FILE
// ONLY WRITE CODE BELOW THE "WRITE BELOW" COMMENTS

#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main() {
    // You are required to create the matrices for 
    // the mentioned questions and print them to 
    // std::cout

    
    //---------------------------------------------------------------------
    // Question 2
    std::cout << "------------------------\n";
    std::cout << "Question 2\n------------------------" << std::endl;

    // matrix definition for Question 2
    Eigen::Matrix3f rot_45;

    // Write the 3×3 transformation matrix for a 45 degrees
    // clockwise rotation in 2D (assuming homogeneous coordinates) 
    // Use the << operator to create the rot_45 matrix (WRITE BELOW)
    const float PI=3.14159265;
    float param=315.0;
    float cosT=cos(param*PI/180.0);
    float sinT= sin(param*PI/180.0);

    rot_45 << cosT, -sinT, 0.0, sinT, cosT, 0.0, 0.0, 0.0, 1.0;

    std::cout << rot_45 << std::endl;
    std::cout << "------------------------\n";
    
    //---------------------------------------------------------------------
    // Question 3
    std::cout << "Question 3\n------------------------" << std::endl;

    // matrix definition for Question 3
    Eigen::Matrix4f translation;

    // Write the 4×4 transform matrix to move a point by (3,4,5)
    // Use the << operator to create the translation matrix (WRITE BELOW)

    translation << 1.0, 0.0, 0.0, 3.0, 0.0, 1.0, 0.0, 4.0, 0.0, 0.0, 1.0, 5.0, 0.0, 0.0, 0.0, 1.0;

    std::cout << translation << std::endl;
    std::cout << "------------------------\n";

    //---------------------------------------------------------------------
    // Question 4
    std::cout << "Question 4\n------------------------" << std::endl;
    // Define and create (using << operator) the matrices here. Make sure
    // that they have the correct dimensions and ordering.
    // Print the matrices to std out with each matrix in a new line
    // WRITE BELOW
    Eigen::Matrix3d op1;
    Eigen::Matrix3d op2;
    Eigen::Matrix3d op3;

    op1<<1,0,-2,0,1,-3,0,0,1;
    op2<<1,0,0,0,1,0,0,0,1;
    op3<<1,0,3,0,1,2,0,0,1;

    std:: cout << "step1: move (2,3) back to origin" << std::endl;
    std:: cout << op1 << std::endl;

    std:: cout<< "step2: scale, since the origin's size is same as new's, scale sx and sy are both 1" << std:: endl;
    std:: cout << op2 << std::endl;

    std:: cout << "step3: move to (3,2)" << std::endl;
    std:: cout << op3 << std::endl;

    std::cout << "------------------------\n";


    return 0;
}