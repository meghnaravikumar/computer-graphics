/**
 * @file AABBTree_ray_intersect.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Determine whether and how a ray intersects the contents of an AABB tree.
 * The method should perform in O(logn) time for a tree containing n (reasonably distributed) objects.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const
{
  ////////////////////////////////////////////////////////////////////////////

  if(!ray_intersect_box(ray, this->box, min_t, max_t)) return false;

  std::shared_ptr<Object> left_children = this->left, right_children = this->right;
  double t_left, t_right;

  bool hit_left = (this->left) && this->left->ray_intersect(ray, min_t, max_t, t_left, left_children);
  bool hit_right = (this->right) && this->right->ray_intersect(ray, min_t, max_t, t_right, right_children);

  if(hit_left && !hit_right){
    t = t_left;
    descendant = left_children;
  }else if(hit_right && !hit_left){
    t = t_right;
    descendant = right_children;
  }else if(hit_left && hit_right){
    t = std::min(t_left, t_right);
    descendant = (t_left == t) ? left_children : right_children;
  }else{
    return false;
  }

  return true;
  ////////////////////////////////////////////////////////////////////////////
}
