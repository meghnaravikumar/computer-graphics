/**
 * @file transformed_tips.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute the positions of specified bone "tips" (e.g., where the bone
 * connects to its children; as opposed to "tails", where the bone connects to
 * its parent) _after_ evaluating the forward kinematics chain in the given skeleton.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "transformed_tips.h"
#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(
  const Skeleton & skeleton,
  const Eigen::VectorXi & b)
{
  /////////////////////////////////////////////////////////////////////////////

  Eigen::VectorXd transformed_tips = Eigen::VectorXd::Zero(3*b.size());

  // Evaluate the forward kinematics chain in the given skeleton
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > T;
  forward_kinematics(skeleton, T);

  // Compute the positions of specified bone "tips"
  for(int i = 0; i < b.size(); i++){
    // Compute bone tip position based on skeleton endpoint b[i]
    Eigen::Vector4d bone_tips(skeleton[b[i]].length, 0, 0, 1);
    Eigen::Vector4d tip_coords = T[b[i]] * skeleton[b[i]].rest_T * bone_tips;

    // Stack bone tip positions into vector
    for(int j = 0; j < 3; j++){
      transformed_tips[i * 3 + j] = tip_coords[j]/tip_coords[3];
    }
  }

  return transformed_tips;

  /////////////////////////////////////////////////////////////////////////////
}
