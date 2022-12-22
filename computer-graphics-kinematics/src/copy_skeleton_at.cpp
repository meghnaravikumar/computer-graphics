/**
 * @file copy_skeleton_at.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Copy a given skeleton with joint angles set to those in vector A.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "copy_skeleton_at.h"
Skeleton copy_skeleton_at(
  const Skeleton & skeleton,
  const Eigen::VectorXd & A)
{
  /////////////////////////////////////////////////////////////////////////////

  Skeleton copy = skeleton;
  for(int i = 0; i < skeleton.size(); i++){
    copy[i].xzx = Eigen::Vector3d(A[3 * i], A[3 * i + 1], A[3 * i + 2]);
  }

  return copy;
  /////////////////////////////////////////////////////////////////////////////
}
