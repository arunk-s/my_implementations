#ifndef ELEM_SET
#define ELEM_SET
/*
  DISJOINT SET ELEMENT CLASS
*/

class elem_set{

  int data;
  int rank;
  elem_set * parent; 
public:
  elem_set():data(0),rank(0),parent(this){
  }
  elem_set(int d,elem_set& _parent):data(d),rank(0),parent(&_parent){
  }
  elem_set(int d):data(d),rank(0),parent(this){
  }
  elem_set(const elem_set &a){
    data=a.data;
    rank=a.rank;
    if(a.parent!= &a){
      parent = a.parent;
    }
    else{
      parent = this;
    }
  }
  int get_data(){
    return data;
  }
  int get_rank(){ 
    return rank;
  }
  void set_parent(elem_set & _parent){
    parent = &_parent;
  }
  int set_rank(int r){
    rank = r ;
    return r;
  }
  elem_set & get_parent(){
    return *parent;
  }
  elem_set & operator = (const elem_set &a){
    data=a.data;
    rank=a.rank;
    if(a.parent!= &a){
      parent=a.parent;
    }
    else{
      parent = this;
    }
    return *this;
  }
  bool operator == (elem_set &a){
    return this == &a;
  }
  bool operator != (elem_set &a){
    return this != &a;
  }
};
#endif