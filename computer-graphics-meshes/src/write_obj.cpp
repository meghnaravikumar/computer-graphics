/**
 * @file write_obj.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Write a pure-triangle or pure-quad mesh with 3D vertex positions V
 * and faces F, 2D parametrization positions UV and faces UF, 3D normal vectors
 * NV and faces NF to a .obj file.
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:

  // get the filestream to write to
  std::ofstream obj_file(filename);

  // error check
  if(obj_file.fail()) return false;

  // vertex positions
  for(int i = 0; i < V.rows(); i++) obj_file << "v " << V(i, 0) << " " << V(i, 1) << " " << V(i, 2) << "\n";

  // texture coords
  for(int i = 0; i < UV.rows(); i++) obj_file << "vt " << UV(i, 0) << " " << UV(i, 1) << "\n";

  // normals
  for(int i = 0; i < NV.rows(); i++) obj_file << "vn " << NV(i, 0) << " " << NV(i, 1) << " " << NV(i, 2) << "\n";

  // faces
  for(int i = 0; i < F.rows(); i++) {
    obj_file << "f ";
    for(int j = 0; j < F.cols(); j++) {
      obj_file << F(i, j) + 1 << "/" << UF(i, j) + 1 << "/" << NF(i, j) + 1 << (j < F.cols()-1 ? " " : "");
    }
    obj_file << "\n";
  }

  // close filestream
  obj_file.close();

  ////////////////////////////////////////////////////////////////////////////
  return false;
}
