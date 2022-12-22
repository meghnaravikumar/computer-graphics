/**
 * @file find_all_intersecting_pairs_using_AABBTrees.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Find all intersecting pairs of leaf boxes between one AABB tree and another.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */

#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list>

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > &
    leaf_pairs)
{
  ////////////////////////////////////////////////////////////////////////////

  leaf_pairs.clear();

  std::list<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>> queue;

  if(!box_box_intersect(rootA->box, rootB->box)) return;

  queue.push_back(std::make_pair(rootA, rootB));

  while(!queue.empty()){
    std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>> node = queue.front();
    queue.pop_front();

    std::shared_ptr<AABBTree> A = std::dynamic_pointer_cast<AABBTree>(node.first);
    std::shared_ptr<AABBTree> B = std::dynamic_pointer_cast<AABBTree>(node.second);

    if (!A && B) {
      if (B->right && box_box_intersect(node.first->box, B->right->box)) {
        queue.push_back(std::make_pair(node.first, B->right));
      }
      if (B->left && box_box_intersect(node.first->box, B->left->box)) {
        queue.push_back(std::make_pair(node.first, B->left));
      }
    }else if (A && !B) {
      if  (A->left && box_box_intersect(A->left->box, node.second->box)) {
        queue.push_back(std::make_pair(A->left, node.second));
      }
      if (A->right && box_box_intersect(A->right->box,  node.second->box)) {
        queue.push_back(std::make_pair(A->right, node.second));
      }
    }else if (!A && !B) {
      leaf_pairs.push_back(std::make_pair(node.first, node.second));
    }else {
      if (A->left && B->left && box_box_intersect(A->left->box, B->left->box)) {
        queue.push_back(std::make_pair(A->left, B->left));
      }
      if (A->right && B->right && box_box_intersect(A->right->box, B->right->box)) {
        queue.push_back(std::make_pair(A->right, B->right));
      }
       if (A->right && B->left && box_box_intersect(A->right->box, B->left->box)) {
        queue.push_back(std::make_pair(A->right, B->left));
      }
      if (A->left && B->right && box_box_intersect(A->left->box, B->right->box)) {
        queue.push_back(std::make_pair(A->left, B->right));
      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
