/**
 * @file box_box_intersect.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Determine if two bounding boxes intersect.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "box_box_intersect.h"
bool box_box_intersect(
  const BoundingBox & A,
  const BoundingBox & B)
{
  ////////////////////////////////////////////////////////////////////////////

  // Cover all axes (x, y, z)
  for(int i = 0; i < 3; i++){
    if(B.min_corner(i) > A.max_corner(i) || B.max_corner(i) < A.min_corner(i)) return false;
  }

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
