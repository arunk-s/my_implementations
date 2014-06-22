
#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using namespace std;
class vertexTag;
class edgeTag {
public:
    vertexTag * points_to;
    edgeTag * enext;
    int cost ;
    edgeTag();
};

class vertexTag {
public:
  int id;
  string v_name ;
  vertexTag * vnext ;
  edgeTag *edges;
  bool visited ;
  vertexTag();
  void get_vt();
  void add_edge(vertexTag * v,int cost);
  void show_edge();
  string return_name(){
    return v_name;
  }
};
#endif