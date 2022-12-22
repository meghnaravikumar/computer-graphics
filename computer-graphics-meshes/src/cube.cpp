/**
 * @file cube.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Construct the quad mesh of a cube including parameterization
 * and per-face normals.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:

  //Hint:
  V.resize(8,3);
  F.resize(6,4);
  UV.resize(14,2);
  UF.resize(6,4);
  NV.resize(6,3);
  NF.resize(6,4);

  // vertices
  V << 0, 0, 0,
       1, 0, 0,
       1, 1, 0,
       0, 1, 0,
       0, 0, 1,
       1, 0, 1,
       1, 1, 1,
       0, 1, 1;

  // normals
  NV <<  1, 0, 0,
        -1, 0, 0,
         0, 1, 0,
         0, -1, 0,
         0, 0, 1,
         0, 0, -1;

  // faces
  F << 0, 1, 5, 4, // bottom
       0, 4, 7, 3, // left
       1, 2, 6, 5, // right
       4, 5, 6, 7, // front
       3, 2, 1, 0, // back
       7, 6, 2, 3; // top

  UF << 4, 8, 7, 3,
        4, 3, 0, 1,
        8, 11, 10, 7,
        3, 7, 6, 2,
        5, 9, 8, 4,
        12, 10, 11, 13;

  NF << 3, 3, 3, 3,
        1, 1, 1, 1,
        0, 0, 0, 0,
        4, 4, 4, 4,
        5, 5, 5, 5,
        2, 2, 2, 2;

  // texture coords
  UV << 0, 0.25,
        0, 0.5,
        0.25, 0,
        0.25, 0.25,
        0.25, 0.5,
        0.25, 0.75,
        0.5, 0,
        0.5, 0.25,
        0.5, 0.5,
        0.5, 0.75,
        0.75, 0.25,
        0.75, 0.5,
        1, 0.25,
        1, 0.5;

  ////////////////////////////////////////////////////////////////////////////

}
