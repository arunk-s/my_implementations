#include "queue.h"
#include <iostream>
class vertexTag;
using namespace std;
link::link(){
	vertex = NULL;
	prev = NULL;
	next = NULL;
}
que::que(){
	head = NULL;	
}
vertexTag * que::push(vertexTag * w){
	if(head==NULL){
		head = new link();
		head->vertex = w;
	}
	else{
		link * temp = new link();
		temp->vertex = w;
		link * temp2 = head;
		while(temp2->next!=NULL)
			temp2 = temp2->next;
		
		temp->prev = temp2;
		temp2->next = temp;
	}
	return w;
}
vertexTag * que::pop() {
	if(head!=NULL) {
		link * temp = head;
		head = temp->next;
		return temp->vertex;
	}
	else{
		cout<<"Queue Empty"<<endl;
		return NULL;
	}
}
bool que::empty(){
	if(head==NULL)
		return true;
	else
		return false;
}