/**
 * @file euler_angles_to_transform.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Construct a rotation matrix (as a 4x4 transformation) given a set of Euler angles.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "euler_angles_to_transform.h"

Eigen::Affine3d euler_angles_to_transform(
  const Eigen::Vector3d & xzx)
{
  /////////////////////////////////////////////////////////////////////////////

  // Convert xzx angles to radians
  // Necessary because AngleAxis expects radians
  Eigen::Vector3d xzx_radians = xzx * EIGEN_PI/180;

  // Construct rotation matrices
  Eigen::AngleAxis<double> rotation_matrix_1(xzx_radians[0], Eigen::Vector3d::UnitX());
  Eigen::AngleAxis<double> rotation_matrix_2(xzx_radians[1], Eigen::Vector3d::UnitZ());
  Eigen::AngleAxis<double> rotation_matrix_3(xzx_radians[2], Eigen::Vector3d::UnitX());

  // The order matters, as Bone.xzx is backwards
  // xzx(2) is first angle to rotate by, xzx(0) is last
  Eigen::Affine3d A(rotation_matrix_3 * rotation_matrix_2 * rotation_matrix_1);

  return A;
  /////////////////////////////////////////////////////////////////////////////
}
