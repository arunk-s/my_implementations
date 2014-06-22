#include <iostream>
#include "graph.h"
#include "queue.h"
#include "heap.h"
#include "vertex.h"

static int INT_MAX = 32767 ;
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
graphl::graphl(){
  v_head = NULL;
  num_of_vertices = 0;
}

void graphl::add_vertex () {
  if(v_head == NULL){
    v_head = new vertexTag();
    v_head->get_vt() ;
    v_head->id = num_of_vertices;
  }
  else{
    vertexTag * temp = new vertexTag();
    temp->get_vt();
    temp->id = num_of_vertices;
    vertexTag * t2 = v_head ;
    while(t2->vnext != NULL)
      t2 = t2->vnext;
    t2->vnext = temp;
    }
  num_of_vertices++;
}
void graphl::add_vertex (string vertex) {
  if(v_head == NULL){
    v_head = new vertexTag();
    v_head->v_name = vertex ;
    v_head->id = num_of_vertices;
  }
  else{
    vertexTag * temp = new vertexTag();
    temp->v_name = vertex;
    temp->id = num_of_vertices;
    vertexTag * t2 = v_head ;
    while(t2->vnext != NULL)
      t2 = t2->vnext;
      t2->vnext = temp;
  }
  num_of_vertices++;
}

void graphl::add_edge() {
  cout<<"Enter the source Vertex:"<<endl;
  string v,w;
  cin>>v;
  cout<<"Enter the dest Vertex:"<<endl;
  cin>>w;  
  int cost ;
  cout<<"Enter the cost :"<<endl;
  cin>>cost;
  add_edge(v,w,cost);  
}
void graphl::add_edge(string v, string w,int cost) {
  vertexTag *source, *dest;
  vertexTag * t1 = v_head ;
  
  while(t1!= NULL)
    {
      if(t1->v_name == v)
        source = t1;
      else if(t1->v_name == w)
        dest = t1;
      t1 = t1->vnext ;
    }
  
  if(source) {
    source->add_edge(dest,cost);
  }
  
  else
    cout<<"Vertex Not Found!!"<<endl;
  
}  

vertexTag * graphl::return_ver(string vertex){
  vertexTag * t1 = v_head;
  while(t1->vnext != NULL){
    if(t1->v_name == vertex)
      break;
    t1 = t1->vnext;
  }
  if(t1)
    return t1 ;
  else {
    cout<<"Vertex Not Found!"<<endl;
    return NULL;
  }    
}

void graphl::show(string v){
  vertexTag * temp = v_head;
  while(temp!=NULL){
    if(temp->v_name == v)
      temp->show_edge();
    temp = temp->vnext;
  }
} 
bool graphl::isReachable(vertexTag * s , string dest) {
  vertexTag * start = s;
  edgeTag * edge ;
  if(start->visited)
    return false;
  
  if(start->v_name == dest)
    return true ;
  
  start->visited = true ;
  
  for (edge = start->edges; edge!=NULL ; edge = edge->enext)
    {
      if(isReachable(edge->points_to,dest))
        return true;
    }
  
  return false;
}

bool graphl::reachable(string source, string dest){
  vertexTag * s;
  vertexTag * temp = v_head ;
  while(temp->vnext!=NULL){
    if(temp->v_name == source)
      s = temp ;
    
    temp->visited = false;
    temp = temp->vnext;
  }
  
  if(s == NULL )
    return false;
  
  if(isReachablePath(s,dest)){
    cout<<s->v_name<<endl;
    return true;
  }
  
  return false;
}

bool graphl::isReachablePath(vertexTag * s , string dest){
  vertexTag * start = s;
  edgeTag * edge ;
  if(start->visited)
    return false;
  
  if(start->v_name == dest){
    return true ;
  }
  
  start->visited = true ;
  
  for (edge = start->edges; edge!=NULL ; edge = edge->enext)
    {
      if(isReachablePath(edge->points_to,dest)){
	     cout<<edge->points_to->v_name<<"-";
	     return true;
      }
    }
  
  return false;

}

bool graphl::bfs(){
  vertexTag * s = v_head;
  vertexTag * temp = v_head ;
  
  while(temp->vnext!=NULL){
    temp->visited = false;
    temp = temp->vnext;
  }
  if(s == NULL)
    return false;
    
  que * q = new que();
  temp = v_head;
  while(temp->vnext!=NULL){
    if(!temp->visited)
      bfspart(temp,q);  
    temp = temp->vnext;
  }

  return true;
}
void graphl::bfspart(vertexTag * s,que * q){
  s->visited=true;
  q->push(s);
  vertexTag * V;
  edgeTag * edge;
  while(!q->empty()){
    V = q->pop();
    cout<<V->v_name<<" ";
    for (edge = V->edges; edge!=NULL ; edge = edge->enext)
      {
        if(!edge->points_to->visited){
            edge->points_to->visited = true;
            q->push(edge->points_to);
        }
    }
  }
}  

vertexTag * graphl::dijsktra(vertexTag * source){
  int * dist = new int[num_of_vertices];
  vertexTag * prev= new vertexTag[num_of_vertices];
  heap h1(num_of_vertices);
  dist[source->id] = 0;
  vertexTag * temp = v_head;
  while(temp!=NULL){
    if(temp!=source){
      dist[temp->id] = INT_MAX ;
      prev[temp->id] = *temp ;
    }
//    cout<<temp->v_name<<endl; 

    h1.add(temp,dist[temp->id]);
    temp = temp->vnext;
  }
  vertexTag * u,*v;
  edgeTag * e ;
  int alt;
  while(!h1.empty()){
    u = h1.rem_with_vertex();
    for(e = u->edges; e!=NULL;e = e->enext){
      v = e->points_to;
      alt = dist[u->id] + e->cost;
      if(alt < dist[v->id]){
        dist[v->id] = alt ;
        prev[v->id] = *u ;
        h1.desc_priority(v,alt);
      }
    }
  }
  
  for (int i = 0; i < size_of_graph(); ++i)
  {
    cout<<"Distance from source vertex of "<<i+1<<" is "<<dist[i]<<endl;
  }
  
  return prev;
} 
