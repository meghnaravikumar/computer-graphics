/**
 * @file ray_intersect_triangle_mesh_brute_force.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Shoots a ray at a triangle mesh with n faces and record the closest hit.
 * Uses a brute force loop over all triangles, aim for O(n) complexity but focus on correctness.
 * This is my reference solution.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "ray_intersect_triangle_mesh_brute_force.h"
#include "ray_intersect_triangle.h"

bool ray_intersect_triangle_mesh_brute_force(
  const Ray & ray,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double min_t,
  const double max_t,
  double & hit_t,
  int & hit_f)
{
  ////////////////////////////////////////////////////////////////////////////

  // Similar to previous labs
  hit_t = std::numeric_limits<double>::infinity();
  hit_f = 0;
  bool hit = false;

  double curr_t = 0;

  for (int i = 0; i < F.rows(); i++) {
    Eigen::MatrixXd pointA = V.row(F(i,0));
    Eigen::MatrixXd pointB = V.row(F(i,1));
    Eigen::MatrixXd pointC = V.row(F(i,2));
    bool intersection_found = ray_intersect_triangle(ray, pointA, pointB, pointC, min_t, max_t, curr_t);
    if (curr_t < hit_t  && intersection_found && curr_t < max_t) {
      hit_t = curr_t;
      hit_f = i;
      hit = true;
    }
  }

  return hit;
  ////////////////////////////////////////////////////////////////////////////
}
