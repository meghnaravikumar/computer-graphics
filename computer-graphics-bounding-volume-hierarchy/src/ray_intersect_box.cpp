/**
 * @file ray_intersect_box.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Intersects a ray with a solid box (careful: if the ray or min_t lands inside
 * the box this could still hit something stored inside the box, so this counts as a hit).
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */
#include "ray_intersect_box.h"
#include <vector>

bool ray_intersect_box(
  const Ray & ray,
  const BoundingBox& box,
  const double min_t,
  const double max_t)
{
  ////////////////////////////////////////////////////////////////////////////

  std::vector<double> minimum_t, maximum_t;
  double min, max;

  // Cover all 3 axes
  for(int i = 0; i < 3; i++){

    min = ray.direction(i) >= 0.0 ?  (box.min_corner(i) - ray.origin(i)) : (box.max_corner(i) - ray.origin(i));
    min = ray.direction(i) >= 0.0 ?  (box.max_corner(i) - ray.origin(i)) : (box.min_corner(i) - ray.origin(i));

    min /= ray.direction(i);
    max /= ray.direction(i);

    minimum_t.push_back(min);
    maximum_t.push_back(max);

  }

  double true_max = *std::max_element(maximum_t.begin(), maximum_t.end());
  double true_min = *std::min_element(minimum_t.begin(), minimum_t.end());

  if(true_min > true_max || min_t > true_max || true_min > max_t) return false;

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
