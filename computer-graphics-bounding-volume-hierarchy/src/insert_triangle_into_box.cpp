/**
 * @file insert_triangle_into_box.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Grow a box B by inserting a triangle with corners a, b, and c.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "insert_triangle_into_box.h"

void insert_triangle_into_box(
  const Eigen::RowVector3d & a,
  const Eigen::RowVector3d & b,
  const Eigen::RowVector3d & c,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////

  // Cover all axes (x, y, z)
  for(int i = 0; i < 3; i++){
    B.max_corner(i) = std::max({B.max_corner(i), a[i], b[i], c[i]});
    B.min_corner[i] = std::min({B.min_corner(i), a[i], b[i], c[i]});
  }

  ////////////////////////////////////////////////////////////////////////////

}
