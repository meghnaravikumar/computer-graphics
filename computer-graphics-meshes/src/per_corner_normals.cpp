/**
 * @file per_corner_normals.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute per corner normals for a triangle mesh by computing the
 * area-weighted average of normals at incident faces whose normals deviate
 * less than the provided threshold.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include "per_face_normals.h"

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::vector<std::vector<int>> VF;
  vertex_triangle_adjacency(F, V.rows(), VF);

  Eigen::MatrixXd FN;
  per_face_normals(V, F, FN);

  double w = cos(corner_threshold * M_PI / 180.0);
  Eigen::RowVector3d n;

  for(int i = 0; i < F.rows(); i++) {
    for (int j = 0; j< F.cols(); j++) {
      n = Eigen::RowVector3d(0, 0, 0);
      for(int face : VF[F(i, j)]) {
        if(FN.row(face).dot(FN.row(i)) > w) {
          n += triangle_area_normal(V.row(F(face, 0)), V.row(F(face, 1)), V.row(F(face, 2)));
        }
      }
      N.row(i * 3 + j) << n.normalized();
    }
  }
  ///////////////////////////////////////////////////////////////
}
