/**
 * @file fast_mass_springs_step_sparse.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Same as fast_mass_springs_step_dense but with sparse matrices.
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "fast_mass_springs_step_sparse.h"
#include <igl/matlab_format.h>

void fast_mass_springs_step_sparse(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & E,
  const double k,
  const Eigen::VectorXi & b,
  const double delta_t,
  const Eigen::MatrixXd & fext,
  const Eigen::VectorXd & r,
  const Eigen::SparseMatrix<double>  & M,
  const Eigen::SparseMatrix<double>  & A,
  const Eigen::SparseMatrix<double>  & C,
  const Eigen::SimplicialLLT<Eigen::SparseMatrix<double> > & prefactorization,
  const Eigen::MatrixXd & Uprev,
  const Eigen::MatrixXd & Ucur,
  Eigen::MatrixXd & Unext)
{
  //////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  double w = 1e10;
  Eigen::MatrixXd l, d, y;
  d.resize(E.rows(), 3);

  for(int iter = 0; iter < 50; iter++)
  {
    for (int i=0; i<E.rows(); ++i) d.row(i) = r(i) * (Unext.row(E(i, 0)) - Unext.row(E(i, 1))).normalized();

    y = ((M * (2 * Ucur - Uprev)) / (delta_t * delta_t)) + fext;
    l = k * A.transpose() * d + y + w * C.transpose() * C * V;
    Unext = prefactorization.solve(l);
  }
  //////////////////////////////////////////////////////////////////////////////
}
