#include <iostream>
#include "vertex.h"
edgeTag::edgeTag(){
	points_to = NULL ;
	cost = 0;
	enext = NULL;
}
vertexTag::vertexTag() {
  id=0;
  v_name = " ";
  vnext = NULL;
  edges = NULL;
}
      
void vertexTag::get_vt (){
  cout<<"Enter Vertex Name: "<<endl;
  cin>>v_name;
}

void vertexTag::add_edge(vertexTag * v,int cost) {
  if(edges == NULL){
      edges = new edgeTag();
      edges->points_to = v ;
      edges->cost = cost;
  }
  else {
    edgeTag * temp = new edgeTag();
    temp->points_to = v;
    temp->cost = cost;
    edgeTag * t2 = edges;
    while(t2->enext!=NULL)
      t2= t2->enext;
    t2->enext = temp;
  }
}
void vertexTag::show_edge() {
    cout<<"Vertex "<<v_name<<endl;
    edgeTag * temp = edges;
    while(temp!=NULL){
      cout<<"Connects to "<<(temp->points_to)->v_name<<endl;
      cout<<"Cost"<<temp->cost<<endl;
      temp = temp->enext ;
    }
}
