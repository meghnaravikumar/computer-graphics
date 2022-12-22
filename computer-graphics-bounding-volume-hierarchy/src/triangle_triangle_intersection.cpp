/**
 * @file triangle_triangle_intersection.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Determine whether two triangles intersect.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "triangle_triangle_intersection.h"
#include "ray_intersect_triangle.h"

bool triangle_triangle_intersection(
  const Eigen::RowVector3d & A0,
  const Eigen::RowVector3d & A1,
  const Eigen::RowVector3d & A2,
  const Eigen::RowVector3d & B0,
  const Eigen::RowVector3d & B1,
  const Eigen::RowVector3d & B2)
{
  ////////////////////////////////////////////////////////////////////////////

  // Literally compute every possibility
  // Inspiration from: http://www.dgp.toronto.edu/~karan/courses/418/slides/lecture8a.compressed.pdf

  // The idea is to make a ray from each triangle
  Ray ray1 = Ray(B0, B2 - B0),
      ray2 = Ray(B1, B0 - B1),
      ray3 = Ray(B2, B1 - B2),
      ray4 = Ray(A0, A2 - A0),
      ray5 = Ray(A1, A0 - A1),
      ray6 = Ray(A2, A1 - A2);

  // Declare t value
  double t;

  bool intersection_exists = ray_intersect_triangle(ray1, A0, A1, A2, 0, 1, t) ||
      ray_intersect_triangle(ray2, A0, A1, A2, 0, 1, t) ||
      ray_intersect_triangle(ray3, A0, A1, A2, 0, 1, t) ||
      ray_intersect_triangle(ray4, B0, B1, B2, 0, 1, t) ||
      ray_intersect_triangle(ray5, B0, B1, B2, 0, 1, t) ||
      ray_intersect_triangle(ray6, B0, B1, B2, 0, 1, t);

  return intersection_exists;
  ////////////////////////////////////////////////////////////////////////////
}
