/**
 * @file fast_mass_springs_step_dense.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Conduct a single step of the "Fast Simulation of Mass-Spring Systems" method.
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "fast_mass_springs_step_dense.h"
#include <igl/matlab_format.h>

void fast_mass_springs_step_dense(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXi & b,
  const double delta_t,
  const Eigen::MatrixXd & fext,
  const Eigen::VectorXd & r,
  const Eigen::MatrixXd & M,
  const Eigen::MatrixXd & A,
  const Eigen::MatrixXd & C,
  const Eigen::LLT<Eigen::MatrixXd> & prefactorization,
  const Eigen::MatrixXd & Uprev,
  const Eigen::MatrixXd & Ucur,
  Eigen::MatrixXd & Unext)
{
  //////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  double w = 1e10;
  Eigen::MatrixXd d(E.rows(), 3);
  Eigen::MatrixXd y, l;

  for(int iter = 0;iter < 50; iter++)
  {

    for(int i = 0; i < r.size(); i++) d.row(i) = r(i) * (Unext.row(E(i, 0)) - Unext.row(E(i, 1))).normalized();

    y = pow(delta_t, -2) * M * (2 * Ucur - Uprev) + fext;
    l = k * A.transpose() * d + y + w * C.transpose() * C * V;

    Unext = prefactorization.solve(l);
  }
  //////////////////////////////////////////////////////////////////////////////
}
