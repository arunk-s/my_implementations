#ifndef MAT_GRAPH
#define MAT_GRAPH
#include <vector>
class edge{
public:
  int u;
  int v;
  int weight;
  edge():u(0),v(0),weight(0){
  }
  edge(int u_,int v_,int weight_):u(u_),v(v_),weight(weight_){}

};
class mat_graph{
 public:
  mat_graph();
  int adj_mat[8][8];
  int vertex_num[8];
  std::vector <edge> edge_arr; 
  void fill_adj();
  void fill_edges();
  void mark_vertex();
  
};
#endif