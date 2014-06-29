#include "mat_graph.h"
#include <algorithm>
/*
  JUST TO FILL THE GRAPH WITH EDGES 
*/
void mat_graph::fill_edges(){
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++){
      if(adj_mat[i][j]!=0){
	edge e(i,j,adj_mat[i][j]);
	edge_arr.push_back(e);
      }
    }
}
mat_graph::mat_graph(){
    int vertex_num_[] = {0,1,2,3,4,5,6,7};
    int adj_mat_[8][8] = {
      {0,15,5,20,8,15,4,21},
      {15,0,10,12,0,7,0,6},
      {5,10,0,0,17,5,8,0},
      {20,12,0,0,12,1,9,3},
      {8,0,17,12,0,3,6,7},
      {15,7,5,1,3,0,5,14},
      {4,0,8,9,6,5,0,8},
      {21,6,0,3,7,14,8,0}
    };
    std::copy(vertex_num_,vertex_num_+8,vertex_num);
    std::copy(&adj_mat_[0][0],&adj_mat_[0][0]+64,&adj_mat[0][0]);

  }
