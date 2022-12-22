/**
 * @file insert_box_into_box.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Grow a box B by inserting a box A.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "insert_box_into_box.h"

void insert_box_into_box(
  const BoundingBox & A,
  BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////

  // Cover all axes (x, y, z)
  for(int i = 0; i < 3; i++){
    B.max_corner[i] = std::max(A.max_corner(i), B.max_corner(i));
    B.min_corner[i] = std::min(A.min_corner(i), B.min_corner(i));
  }

  ////////////////////////////////////////////////////////////////////////////
}
