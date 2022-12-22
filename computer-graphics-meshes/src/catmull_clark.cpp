/**
 * @file catmull_clark.cpp
 * @author Meghna Ravikumar (1005954380)
 * @brief Conduct num_iters iterations of Catmull-Clark
 * subdivision on a pure quad mesh (V,F).
 * @version 0.1
 * @date 2022-11-01
 *
 * @copyright CSC317 Teaching Team
 *
 */

#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>
#include <vector>

// hash function so that we can use a pair as a key for unordered_map
// https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

using Pair = std::pair<int, int>;
using edges_map = std::unordered_map<Pair, std::vector<int>, pair_hash>;
using edge_points_map = std::unordered_map<Pair, Eigen::RowVector3d, pair_hash>;

// function declarations
void construct_faces(
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF,
  std::vector<Eigen::RowVector3d> points);

void catmull_clark(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const int num_iters,
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  edges_map edges;
  edge_points_map edge_points;
  std::unordered_map<int, Eigen::RowVector3d> face_points;
  std::unordered_map<int, std::vector<int>> adjacent_faces;
  std::unordered_map<int, std::vector<int>> adjacent_vertices;
  std::unordered_map<int, Eigen::RowVector3d> new_coords;

  // base case
  if(num_iters == 0) return;

  for(int i = 0; i < F.rows(); i++){
    for(int j = 0; j < F.cols(); j++){
      // 1. get all face points
      face_points[i] = (V.row(F(i, 0)) + V.row(F(i, 1)) + V.row(F(i, 2)) + V.row(F(i, 3))) / 4.0;

      // 2. get all adjacent faces
      adjacent_faces[F(i, j)].push_back(i);

      // 3. get all edges
      Pair key1 = std::make_pair(F(i, j), F(i, (j + 1) % F.cols()));
      Pair key2 = std::make_pair(F(i, (j + 1) % F.cols()), F(i, j));
      auto iter1 = std::find(edges[key1].begin(), edges[key1].end(), i) == edges[key1].end();
      auto iter2 = std::find(edges[key2].begin(), edges[key2].end(), i) == edges[key2].end();
      if(iter1) edges[key1].push_back(i);
      if(iter2) edges[key2].push_back(i);

      // 4. get all adjacent vertices
      int v1 = F(i, (j + 1) % F.cols());
      int v2 = F(i, (j - 1 + F.cols()) % F.cols());
      auto v1check = std::find(adjacent_vertices[F(i, j)].begin(), adjacent_vertices[F(i, j)].end(), v1) == adjacent_vertices[F(i, j)].end();
      auto v2check = std::find(adjacent_vertices[F(i, j)].begin(), adjacent_vertices[F(i, j)].end(), v2) == adjacent_vertices[F(i, j)].end();
      if(v1check) adjacent_vertices[F(i, j)].push_back(v1);
      if(v2check) adjacent_vertices[F(i, j)].push_back(v2);

      // 5. get all new points
      // the num of edges n neighboring a vertex is also the number of adjacent faces
      double n = adjacent_faces[F(i,j)].size();
      double m1 = (n-3)/n;
      double m2 = 1/n;
      double m3 = 2/n;

      // take the average (F) of all n (recently created) face points for faces touching P
      Eigen::RowVector3d avg_face_points(0, 0, 0);
      for(int i: adjacent_faces[F(i,j)]) avg_face_points += face_points[i];
      avg_face_points = avg_face_points / (double)adjacent_faces[F(i,j)].size();

      // take the average (R) of all n edge midpoints for original edges touching P,
      // where each edge midpoint is the average of its two endpoint vertices
      // (not to be confused with new edge points above)
      Eigen::RowVector3d avg_mid_edges(0, 0, 0);
      Eigen::RowVector3d old_coords = V.row(F(i,j));
      for(int i : adjacent_vertices[F(i,j)]) avg_mid_edges += (old_coords + V.row(i)) / 2.0;
      avg_mid_edges = avg_mid_edges / (double)adjacent_vertices[F(i,j)].size();

      new_coords[F(i,j)] = (m1 * old_coords) + (m2 * avg_face_points) + (m3 * avg_mid_edges);

      // 6. get paired edge points for this iteration
      Eigen::RowVector3d point(0, 0, 0);
      for(int i : edges[key1]) point += face_points[i];
      edge_points[key1] = (point + V.row(key1.first) + V.row(key1.second)) / 4.0;

      Eigen::RowVector3d point2(0, 0, 0);
      for(int i : edges[key2]) point2 += face_points[i];
      edge_points[key2] = (point + V.row(key2.first) + V.row(key2.second)) / 4.0;

    }
  }

  // resize matrices
  SV.resize(0, 3);
  SF.resize(0, 4);

  for(int i = 0; i < F.rows(); i++){
    for(int j = 0; j < F.cols(); j++){
      Pair key1 = std::make_pair(F(i, j), F(i, (j + 1) % F.cols()));
      Pair key2 = std::make_pair( F(i, j), F(i, ((j - 1) + F.cols()) % F.cols()));
      std::vector<Eigen::RowVector3d> points;
      points.push_back(new_coords[F(i,j)]);
      points.push_back(edge_points[key1]);
      points.push_back(face_points[i]);
      points.push_back(edge_points[key2]);
      construct_faces(SV, SF, points);
    }
  }

  // recursive call
  catmull_clark(Eigen::MatrixXd(SV), Eigen::MatrixXi(SF), num_iters - 1, SV, SF);
  ////////////////////////////////////////////////////////////////////////////
}

void construct_faces(
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF,
  std::vector<Eigen::RowVector3d> points){

    int empty = -1, row = 0;
    double ref = 1e-10;
    Eigen::MatrixXi new_SF(SF.rows() + 1, 4);
    Eigen::RowVector4i faces(empty, empty, empty, empty);

    // fill in SV
    for(int j = 0; j < points.size(); j++){
      Eigen::RowVector3d p = points[j];
      for(int i = 0; i < SV.rows(); i++) if((p - SV.row(i)).norm() < ref) faces(row) = i;

      if(faces(row) == empty){
        Eigen::MatrixXd new_SV(SV.rows() + 1, 3);
        for(int x = 0; x < SV.rows(); x++) new_SV.row(x) = SV.row(x);
        new_SV.row(SV.rows()) = p;
        SV = new_SV;
        faces(row) = SV.rows()-1;
      }
      row++;
    }

    // fill in SF
    for(int x = 0; x < SF.rows(); x++) new_SF.row(x) = SF.row(x);
    new_SF.row(SF.rows()) = faces;
    SF = new_SF;
}
