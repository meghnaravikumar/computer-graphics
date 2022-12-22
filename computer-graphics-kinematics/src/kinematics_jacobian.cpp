/**
 * @file kinematics_jacobian.cpp
 * @author Meghna Ravikumar (1005954380)
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "kinematics_jacobian.h"
#include "transformed_tips.h"
#include <iostream>

void kinematics_jacobian(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b,
  Eigen::MatrixXd & J)
{
  /////////////////////////////////////////////////////////////////////////////

  J = Eigen::MatrixXd::Zero(b.size()*3,skeleton.size()*3);

  Eigen::VectorXd tips = transformed_tips(skeleton, b);
  Skeleton copy = skeleton; // Make a copy so that the original skeleton isn't modified
  double h = 1e-7; // Fix h to a small limit, this value is given in the README

  J.resize(b.size() * 3, skeleton.size() * 3);

  for(int i; i < skeleton.size(); i++){
    for(int j = 0; j < 3; j++){
      copy[i].xzx(j) += h;
      Eigen::Vector3d x_tips = transformed_tips(copy, b);
      for(int x = 0; x < 3; x++){
        J(x, i * 3 + j) = (x_tips[x]- tips[x]) / h;
      }

    }
  }

  /////////////////////////////////////////////////////////////////////////////
}
