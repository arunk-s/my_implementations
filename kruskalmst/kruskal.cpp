#include "elem_set_.h"
#include "mat_graph.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
  DISJOINT OPERATIONS  ON ELEM_SET 
  CANT BE PUT IN ELEM_SET
*/

elem_set & find_elem(vector<elem_set>& v , int vertex){
  for(size_t i=0;i<v.size();i++){
    if(v[i].get_data()==vertex)
      return v[i];
  }
  return v.back();
}

void link(elem_set &x,elem_set &y){
  if (x.get_rank() > y.get_rank()){
    y.set_parent(x) ; 
  }
  else{
    x.set_parent(y);
    if(x.get_rank() == y.get_rank()){
      y.set_rank(y.get_rank()+1);
      
    }
  }
}

elem_set & find_set(elem_set &x){
if(x != x.get_parent()) {  
  	x.set_parent(find_set(x.get_parent()));
  }
  return x.get_parent();
}

void union_(elem_set &x,elem_set &y){
  link(find_set(x),find_set(y));
}

/*
  FOR SORTING EDGES ACC. TO WEIGHT
*/
bool sort_edge(const edge &e ,const edge &f){
  return e.weight < f.weight ;
}

/*
  MST MAKING FUNCTION BY KRUSKAL ALGO
*/

vector<edge> make_mst(mat_graph &G){

  vector <edge> mst ;  
  std::vector<elem_set> e_list;

  for(size_t i=0;i<static_cast<int>(sizeof(G.vertex_num)/sizeof(int));i++){
  	elem_set u(G.vertex_num[i]);
    e_list.push_back(u);
  }
  std::sort(G.edge_arr.begin(),G.edge_arr.end(),sort_edge);
  
  for(size_t i = 0 ; i < G.edge_arr.size();i++){
    if(find_set(find_elem(e_list,G.edge_arr[i].u))!=find_set(find_elem(e_list,G.edge_arr[i].v))){
      mst.push_back(G.edge_arr[i]);
      union_(find_elem(e_list,G.edge_arr[i].u),find_elem(e_list,G.edge_arr[i].v)); 
    }
  }
  return mst;
}

int main(){
  mat_graph m1;
  m1.fill_edges();
  std::vector<elem_set> e_list;
  vector <edge> mst;

  mst = make_mst(m1);

   for(size_t i =0 ;i<mst.size();i++){
  	cout<<mst[i].u<<" "<<mst[i].v<<" "<<mst[i].weight<<endl;
  }
	return 0;
}

