#include <iostream>
#include "heap.h"
#include "vertex.h"
using namespace std;
heapitem::heapitem(){
	vertex = NULL;
	key = 0;
}

heapitem::heapitem(vertexTag * v,int k):key(k){
	vertex = v;
}

inline int heapitem::getkey(){
	return key;
}

inline vertexTag * heapitem::getitem(){
	return vertex;
}

inline void heapitem::setkey(int k){
	key = k;
}

inline void heapitem::setitem(vertexTag *v){
	vertex = v;
}

heap::heap(){
	num_of_elem= 0;
	elements = NULL;
	current_num= 0;
};

heap::heap(int num):num_of_elem(num),current_num(0){
	elements = new heapitem[num_of_elem];
}
/*
heapitem heap::remove(){
	if(current_num > 0) {
	heapitem temp = elements[0];
	elements[0] = elements[--current_num];
	shiftdown(0); //compare with the children
	return temp;
	}
}*/

vertexTag * heap::rem_with_vertex(){
	if(current_num > 0) {
	heapitem temp = elements[0];
	elements[0] = elements[--current_num];
	shiftdown(0); //compare with the children
	return temp.getitem();
	}
	else
		return NULL;	
}

bool heap::add(const heapitem item){
	if(current_num >= num_of_elem)
		return false;

	elements[current_num] = item ;
	shiftup(current_num++) ; //compare with the parents;
	return true;
}

bool heap::add(vertexTag *v,const int k){
	heapitem * temp = new heapitem(v,k);
	return add(*temp);	
}

void heap::shiftdown(int index){
	int current = index;
	int child = leftchild(index);
	heapitem item = elements[current];
	while(child < current_num){
		if(elements[child].getkey() > elements[child+1].getkey())
			child++;
		if(elements[child].getkey() < item.getkey()){
			elements[current] = elements[child];
			current = child ;
			child = leftchild(current);
		}
		else
			break;
	}
	elements[current] = item;
}

void heap::shiftup(int index){
	int current = index, parent = parentof(index)	;

	heapitem item = elements[current];
	while(current > 0){
		if(elements[parent].getkey() > item.getkey()){
			elements[current] = elements[parent];
			current = parent ;
			parent = parentof(current);
		}
		else
			break;
	}

	elements[current] = item;
}

vertexTag * heap::get_top_vertex(){
	if(!empty())
		return elements[0].getitem();
	else{
		cout<<"Empty Heap!!"<<endl;
		return NULL;
	}
}

int heap::current_elements(){
	return current_num;
}
inline int heap::leftchild(int index){
	return (index*2) + 1;
}

inline int heap::parentof(int index){
	return (index - 1)/2 ;
}

bool heap::empty(){
	return current_num == 0;
}
bool heap::desc_priority(vertexTag * v, int newkey){
	vertexTag * temp;
	for (int i = 0; i < current_num; ++i)
	{
		temp = elements[i].getitem();
		if( temp->return_name() == v->return_name()){
			elements[i].setkey(newkey);	
			shiftup(i);		
			return true;
		}
	}
	return false;
}
