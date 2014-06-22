#include <string>
#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class vertexTag;
class que;
class graphl{
  vertexTag *v_head;
  int num_of_vertices ;  
public:
  graphl();
  void add_vertex ();
  void add_vertex (string vertex);
  void add_edge();
  void add_edge(string v, string w,int cost);
  vertexTag * return_ver(string vertex);
  void show(string v);
  bool isReachable(vertexTag * s , string dest);
  bool reachable(string source, string dest);
  bool isReachablePath(vertexTag * s , string dest);
  bool bfs();
  void bfspart(vertexTag * s, que * q);
  vertexTag * dijsktra(vertexTag * );
  inline int size_of_graph(){
    return num_of_vertices;
  };
};
#endif