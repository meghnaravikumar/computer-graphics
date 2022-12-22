/**
 * @file signed_incidence_matrix_dense.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Construct the sparse incidence matrix for a given edge network.
 * @version 0.1
 * @date 2022-12-08
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "signed_incidence_matrix_dense.h"

void signed_incidence_matrix_dense(
  const int n,
  const Eigen::MatrixXi & E,
  Eigen::MatrixXd & A)
{
  //////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  A = Eigen::MatrixXd::Zero(E.rows(),n);

  for(int i = 0; i < E.rows(); i++){
    A(i, E(i, 0)) = 1;
    A(i, E(i, 1)) = -1;
  }
  //////////////////////////////////////////////////////////////////////////////
}
