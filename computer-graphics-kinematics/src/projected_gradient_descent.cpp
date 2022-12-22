/**
 * @file projected_gradient_descent.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Conduct `max_iters` iterations of projected gradient descent.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "projected_gradient_descent.h"
#include "line_search.h"

void projected_gradient_descent(
  const std::function<double(const Eigen::VectorXd &)> & f,
  const std::function<Eigen::VectorXd(const Eigen::VectorXd &)> & grad_f,
  const std::function<void(Eigen::VectorXd &)> & proj_z,
  const int max_iters,
  Eigen::VectorXd & z)
{
  /////////////////////////////////////////////////////////////////////////////

  double max_step = 10000, sigma = 0;
  Eigen::VectorXd grad_z;

  for(int a = 0; a < max_iters; a++){

    // compute gradient of f with respect to z at a given z
    grad_z = grad_f(z);

    // Calculate sigma
    sigma = line_search(f, proj_z, z, grad_z, max_step);
    z = z - sigma * grad_z;

    // Project updated z onto the set of feasible values
    proj_z(z);
  }

  /////////////////////////////////////////////////////////////////////////////
}
