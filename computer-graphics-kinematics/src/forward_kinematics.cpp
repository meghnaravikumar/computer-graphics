/**
 * @file forward_kinematics.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute the deformations (tranformations from rest pose) for each node in a
 * forward kinematics hiearchy (reading each node's relative transformation from rest).
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "forward_kinematics.h"
#include "euler_angles_to_transform.h"
#include <functional> // std::function

std::function<void(const Skeleton &,
                    std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d>> &,
                    int)> recurse_T;

void forward_kinematics(
  const Skeleton & skeleton,
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T)
{
  /////////////////////////////////////////////////////////////////////////////

  T.resize(skeleton.size(),Eigen::Affine3d::Identity());

  // Define recursive function to calculate bone transformations
  recurse_T =[](const Skeleton & skeleton,
        std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d>> & T,
        int i){
    if(skeleton[i].parent_index == -1){
      T[i] = Eigen::Affine3d::Identity();
    }else{
      recurse_T(skeleton, T, skeleton[i].parent_index);
      T[i] =  T[skeleton[i].parent_index] * skeleton[i].rest_T * euler_angles_to_transform(skeleton[i].xzx) * (skeleton[i].rest_T).inverse();
    }
  };

  // Get T values
  for(int i = 0; i < skeleton.size(); i++){
    recurse_T(skeleton, T, i);
  }

  /////////////////////////////////////////////////////////////////////////////
}
