/**
 * @file fast_mass_springs_precomputation_dense.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Precompute matrices and factorizations necessary for the "Fast Simulation of
 * Mass-Spring Systems" method.
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "fast_mass_springs_precomputation_dense.h"
#include "signed_incidence_matrix_dense.h"
#include <Eigen/Dense>

bool fast_mass_springs_precomputation_dense(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXd & m,
  const Eigen::VectorXi & b,
  const double delta_t,
  Eigen::VectorXd & r,
  Eigen::MatrixXd & M,
  Eigen::MatrixXd & A,
  Eigen::MatrixXd & C,
  Eigen::LLT<Eigen::MatrixXd> & prefactorization)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  double w = 1e10;
  Eigen::MatrixXd Q = Eigen::MatrixXd::Identity(V.rows(),V.rows());
  M = Eigen::MatrixXd::Zero(V.rows(), V.rows());
  C = Eigen::MatrixXd::Zero(b.rows(), V.rows());
  r.resize(E.rows());

  for(int i = 0; i < E.rows(); i++) r(i) = (V.row(E(i, 0)) - V.row(E(i, 1))).norm();

  for(int i = 0; i < V.rows(); i++) M(i, i) = m(i);

  signed_incidence_matrix_dense(V.rows(), E, A);

  for(int i = 0; i < b.rows(); i++) C(i, b(i)) = 1;

  Q = k * A.transpose() * A + M * pow(delta_t, -2) + w * C.transpose() * C;

  /////////////////////////////////////////////////////////////////////////////
  prefactorization.compute(Q);
  return prefactorization.info() != Eigen::NumericalIssue;
}
