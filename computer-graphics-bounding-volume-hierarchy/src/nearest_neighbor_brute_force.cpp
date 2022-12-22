/**
 * @file nearest_neighbor_brute_force.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute the nearest neighbor for a query in the set of n points (rows of points).
 * This should be a slow reference implementation.
 * Aim for a computational complexity of O(n) but focus on correctness.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "nearest_neighbor_brute_force.h"
#include <limits>// std::numeric_limits<double>::infinity();

void nearest_neighbor_brute_force(
  const Eigen::MatrixXd & points,
  const Eigen::RowVector3d & query,
  int & I,
  double & sqrD)
{
  ////////////////////////////////////////////////////////////////////////////
  I = -1;
  sqrD = std::numeric_limits<double>::infinity();

  for(int i = 0; i < points.rows(); i++){
    if(((query - points.row(i)).squaredNorm()) < sqrD){
      sqrD = (query - points.row(i)).squaredNorm();
      I = i;
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
