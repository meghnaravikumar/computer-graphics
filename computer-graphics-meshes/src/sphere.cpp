/**
 * @file sphere.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Construct a quad mesh of a sphere with num_faces_u × num_faces_v faces.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:

  // variable declarations
  int n_faces = num_faces_v * num_faces_u;
  int n_vert = (num_faces_u + 1) * (num_faces_v + 1);
  double theta, phi;
  int row_num = 0;

  // resize relevant matrices
  V.resize(n_vert, 3);
  F.resize(n_faces, 4);
  UV.resize(n_vert, 2);
  UF.resize(n_faces, 4);
  NV.resize(n_vert, 3);
  NF.resize(n_faces, 4);

  // vertices
  for(double u = 0; u <= num_faces_u; u++){
    theta = u * 2.0 * (M_PI / num_faces_u);
    for(double v = 0; v <= num_faces_v; v++){
      phi = v * (M_PI / num_faces_v);
      V.row(row_num) << -sin(phi) * cos(theta), -sin(theta) * sin(phi), -cos(phi);
      NV.row(row_num) << V.row(row_num).normalized();
      UV.row(row_num) << u/num_faces_u, v/num_faces_v;
      row_num++;
    }
  }

  // faces
  row_num = 0;
  for(double u = 0; u < num_faces_u; u++){
    for(double v = 0; v < num_faces_v; v++){
      F.row(row_num) << v + (u + 1) * (num_faces_v + 1), v + u * (num_faces_v + 1), v + u * (num_faces_v + 1) + 1, v + (u + 1) * (num_faces_v + 1) + 1;
      UF.row(row_num) << F.row(row_num);
      NF.row(row_num) << F.row(row_num);
      row_num++;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
