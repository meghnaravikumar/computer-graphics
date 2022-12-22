/**
 * @file linear_skin_blending.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Given a mesh with vertices in their rest positions, a skeleton, bone
 * transformations, and per-vertex weights, compute the linear blend skinning deformation.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "linear_blend_skinning.h"

void linear_blend_skinning(
  const Eigen::MatrixXd & V,
  const Skeleton & skeleton,
  const std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T,
  const Eigen::MatrixXd & W,
  Eigen::MatrixXd & U)
{
  /////////////////////////////////////////////////////////////////////////////

  // Resize U to the indicated size in header
  U.resize(V.rows(), 3);

  for(int x = 0; x < V.rows(); x++){
    // Temp variable for a row of U
    Eigen::Vector4d weighted_sum = Eigen::Vector4d::Zero();
    for(int i = 0; i < skeleton.size(); i++){
      // Compute the sum only if the weights exist
      if(skeleton[i].weight_index != -1){
        weighted_sum += W(x, skeleton[i].weight_index) * (T[i] * Eigen::Vector4d(V(x, 0), V(x, 1), V(x, 2), 1));
      }
    }
    // Update U to add the row
    U(x, 0) = weighted_sum[0];
    U(x, 1) = weighted_sum[1];
    U(x, 2) = weighted_sum[2];
  }

  /////////////////////////////////////////////////////////////////////////////
}
