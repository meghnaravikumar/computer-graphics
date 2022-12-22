/**
 * @file triangle_area_normal.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute the normal vector of a 3D triangle given its
 * corner locations. The output vector should have length equal
 * to the area of the triangle.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "triangle_area_normal.h"
#include <Eigen/Geometry>

Eigen::RowVector3d triangle_area_normal(
  const Eigen::RowVector3d & a,
  const Eigen::RowVector3d & b,
  const Eigen::RowVector3d & c)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code:
  Eigen::RowVector3d normal = (c-a).cross(b-a);
  auto area = normal.norm()/2.0;
  ////////////////////////////////////////////////////////////////////////////
  return -normal.normalized() * area;
}
