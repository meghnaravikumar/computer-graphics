/**
 * @file ray_intersect_triangle.cpp
 * @author tempeghna Ravikumar (1005954380)
 * @brief Intersects a ray with a triangle.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "ray_intersect_triangle.h"
#include <Eigen/Dense>
#include <iostream>

bool ray_intersect_triangle(
  const Ray & ray,
  const Eigen::RowVector3d & A,
  const Eigen::RowVector3d & B,
  const Eigen::RowVector3d & C,
  const double min_t,
  const double max_t,
  double & t)
{
  ////////////////////////////////////////////////////////////////////////////

  // Same as previous labs

  Eigen::Vector3d p1 = A.transpose();
  Eigen::Vector3d p2 = B.transpose() - p1;
  Eigen::Vector3d p3 = C.transpose() - p1;

  Eigen::Matrix3d temp;
  temp.col(0) = p2;
  temp.col(1) = p3;
  temp.col(2) = -1 * ray.direction;

  if(temp.determinant() == 0) return false;

  Eigen::Vector3d calculations = temp.inverse() * (ray.origin - p1);

  double gamma_value = calculations[0];
  double beta_value = calculations[1];
  t = calculations[2];

  if (t < min_t || t > max_t || gamma_value < 0 || gamma_value > 1 ||
       beta_value < 0 || (beta_value + gamma_value) > 1)
  {
    return false;
  }

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
