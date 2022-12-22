/**
 * @file point_AABBTree_squared_distance.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Compute the distrance from a query point to the objects stored in a AABBTree
 * using a priority queue. Note: this function is not meant to be called recursively.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////

  std::priority_queue< std::pair<double, std::shared_ptr<Object>>,
                      std::vector<std::pair<double, std::shared_ptr<Object>>>,
                      std::greater<std::pair<double, std::shared_ptr<Object>>> > queue;

  queue.push(std::make_pair(point_box_squared_distance(query, root->box), root));

  sqrd = std::numeric_limits<double>::infinity();

  while (!queue.empty()) {
    std::pair<double, std::shared_ptr<Object>> front = queue.top();
    queue.pop();

    double front_dist = front.first;
    std::shared_ptr<AABBTree> temp = std::dynamic_pointer_cast<AABBTree>(front.second);

    if(front_dist < sqrd) {
      if (temp) {
        if (temp->left) queue.push(std::make_pair(point_box_squared_distance(query, temp->left->box), temp->left));
        if (temp->right) queue.push(std::make_pair(point_box_squared_distance(query, temp->right->box), temp->right));
      }else {
        sqrd = front_dist;
        descendant = front.second;
      }
    }
  }

  bool exists =  (max_sqrd > sqrd) && (min_sqrd < sqrd);
  return exists;

  ////////////////////////////////////////////////////////////////////////////
}
