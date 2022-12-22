/**
 * @file point_box_squared_distance.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute the squared distance between a query point and a box.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "point_box_squared_distance.h"
#include <vector>

double point_box_squared_distance(
  const Eigen::RowVector3d & query,
  const BoundingBox & box)
{
  ////////////////////////////////////////////////////////////////////////////

  std::vector<double> distances;

  // Consider all 3 axes
  for(int i = 0; i < 3; i++){
    double distance = std::fmax((query(i) - box.max_corner(i)), std::fmax((box.min_corner(i) - query(i)), 0.0));
    distances.push_back(distance);
  }

  return std::pow(distances[0], 2) + std::pow(distances[1], 2) + std::pow(distances[2], 2);
  ////////////////////////////////////////////////////////////////////////////
}
