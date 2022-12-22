/**
 * @file line_search.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Given a function handle that computes an objective value to minimize, a
 * function handle that projects a guess onto a set of constraints and a
 * direction to search along, use exponential search to find a decreasing step distance.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "line_search.h"
#include <iostream>

double line_search(
  const std::function<double(const Eigen::VectorXd &)> & f,
  const std::function<void(Eigen::VectorXd &)> & proj_z,
  const Eigen::VectorXd & z,
  const Eigen::VectorXd & dz,
  const double max_step)
{
  /////////////////////////////////////////////////////////////////////////////

  // Start with max_step
  double sigma = max_step;
  Eigen::VectorXd temp_z = z - sigma * dz;
  proj_z(temp_z);

  while(f(temp_z) > f(z)){
    // Keep halving until we find the energy is decreasing
    sigma /= 2;
    temp_z = z - sigma * dz;
    proj_z(temp_z);
  }

  return sigma;
  /////////////////////////////////////////////////////////////////////////////
}
