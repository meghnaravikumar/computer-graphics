/**
 * @file AABBTree.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Construct an axis-aligned bounding box tree given a list of objects.
 * Use the midpoint along the longest axis of the box containing the given objects
 * to determine the left-right split.
 * @version 0.1
 * @date 2022-19-10
 *
 * @copyright Copyright CSC317 Teaching Team
 *
 */
#include "AABBTree.h"
#include "insert_box_into_box.h"

int axis;

struct sortedVector
{
    bool operator()(const std::shared_ptr<Object>& a, const std::shared_ptr<Object>& b)
    {
       return a->box.center()[axis] < b->box.center()[axis];
    }
};

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth):
  depth(std::move(a_depth)),
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////

  this->left = NULL;
  this->right = NULL;

  if(num_leaves == 1){
    this->left = objects[0];
    insert_box_into_box(objects[0]->box, this->box);
    return;
  }else if(num_leaves == 2){
    this->left = objects[0];
    this->right = objects[1];
    insert_box_into_box(objects[0]->box, this->box);
    insert_box_into_box(objects[1]->box, this->box);
    return;
  }else if(num_leaves == 0) return;


  for(int i = 0; i < num_leaves; i++){
    insert_box_into_box(objects[i]->box, this->box);
  }

  // Find the longest axis
  std::vector<double> longest;
  for(int i = 0; i < 3; i++){
    longest.push_back(abs(this->box.max_corner(i) - this->box.min_corner(i)));
  }

  axis = std::max_element(longest.begin(),longest.end()) - longest.begin();
  double longest_axis = *std::max_element(longest.begin(), longest.end());
  double midpoint = this->box.center()[axis];

  std::vector<std::shared_ptr<Object>> left, right;

  for(int i = 0; i < num_leaves; i++){
    if(midpoint > objects[i]->box.center()[axis]){
        left.emplace_back(objects[i]);
    }else{
      right.emplace_back(objects[i]);
    }
  }

  if(left.empty() || right.empty()){
    left.clear();
    right.clear();
    std::vector<std::shared_ptr<Object>> new_list(objects);
    std::sort(new_list.begin(), new_list.end(), sortedVector());

    for(int i = 0; i < num_leaves; i++){
      if(i >= num_leaves / 2) right.push_back(new_list[i]);
      if(i < num_leaves / 2) left.push_back(new_list[i]);
    }
  }

  this->left = std::make_shared<AABBTree>(left, a_depth + 1);
  this->right = std::make_shared<AABBTree>(right, a_depth + 1);

  ////////////////////////////////////////////////////////////////////////////

}
