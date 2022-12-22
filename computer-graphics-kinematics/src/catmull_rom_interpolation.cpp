/**
 * @file atmull_rom_interpolation.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Interpolate a given set of 3d vector keyframes (e.g., of Euler angles) at a
 * time t using a Catmull-Rom spline.
 * @version 0.1
 * @date 2022-12-06
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "catmull_rom_interpolation.h"
#include <Eigen/Dense>

Eigen::Vector3d catmull_rom_interpolation(
  const std::vector<std::pair<double, Eigen::Vector3d> > & keyframes,
  double t)
{
  /////////////////////////////////////////////////////////////////////////////

  // Source: https://en.wikipedia.org/wiki/Cubic_Hermite_spline#Interpolation_on_the_unit_interval_with_matched_derivatives_at_endpoints

  // Edge case: There are no keyframes (size is zero)
  if(keyframes.empty()){
    return Eigen::Vector3d::Zero();
  }

  // Force circulating animation
  t = fmod(t, keyframes.back().first);

  // Find four points
  int n;
  for(n = 0; n < keyframes.size(); n++){
    if(keyframes[n].first > t) break;
  }

  // Set the value of each point
  Eigen::Vector3d p0 = (n == keyframes.size() - 1 || n  - 2< 2) ? keyframes[n - 1].second : keyframes[n - 2].second,
                  p1 = (n == keyframes.size() - 1 || n  - 2< 2) ? keyframes[n].second : keyframes[n - 1].second,
                  p2 = keyframes[n].second,
                  p3 = keyframes[n + 1].second;

  // Set the value of each time
  double t0 = (n == keyframes.size() - 1 || n -2< 2) ? keyframes[n - 1].first : keyframes[n - 2].first,
         t1 = (n == keyframes.size() - 1 || n -2< 2) ? keyframes[n].first : keyframes[n - 1].first,
         t2 = keyframes[n].first,
         t3 = keyframes[n + 1].first;

  // Edge case: handle extreme edges
  if(n == keyframes.size() - 1 || n -2 < 2) return (t - t1)/(t0 - t1) * p0 + (1 - (t - t1)/(t0 - t1)) * p1;

  // Using equation given in lecture notes
  auto time = (t - t1) / (t2 - t1);
  auto term_1 = (2 * pow(time, 3) - 3 * pow(time, 2) + 1) * p1;
  auto term_2 = (pow(time, 3) - 2 * pow(time, 2) + time) * (p2 - p0) / (t2 - t0);
  auto term_3 = (pow(time, 3) - pow(time, 2)) * (p3 - p1) / (t3 - t1);

  return term_1 + term_2 + term_3;

  /////////////////////////////////////////////////////////////////////////////
}
