/**
 * @file vertex_triangle_adjacency.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute a vertex-triangle adjacency list.
 * For each vertex store a list of all incident faces.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "vertex_triangle_adjacency.h"

void vertex_triangle_adjacency(
  const Eigen::MatrixXi & F,
  const int num_vertices,
  std::vector<std::vector<int> > & VF)
{
  VF.resize(num_vertices);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  for (int i = 0; i < F.rows(); i++) {
    for (int j = 0; j < F.cols(); j++) {
      VF[F(i, j)].push_back(i);
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
