/**
 * @file per_vertex_normals.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute per-vertex normals for a triangle mesh.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:

  for (int i = 0; i < V.rows(); i++) {
    Eigen::RowVector3d n(0, 0, 0);
    for (int j = 0; j < F.rows(); j++) {
      bool check = (F(j, 0) == i || F(j, 1) == i || F(j, 2) == i);
      n += check ? triangle_area_normal(V.row(F(j, 0)), V.row(F(j, 1)), V.row(F(j, 2))) : Eigen::RowVector3d(0, 0, 0);
    }
    N.row(i) = n.normalized();
  }
  ////////////////////////////////////////////////////////////////////////////
}
