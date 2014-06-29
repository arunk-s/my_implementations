#include "binomialheap.h"
#include <iostream>

namespace binomial_heap {

	node::node(){
		data = 0;
		degree = 0; 
		sibling = NULL;
		child = NULL;
		parent = NULL ;

		}
	node::node(int x){
		data = x;
		degree = 0; 
		sibling = NULL;
		child = NULL;
		parent = NULL ;
		}
	void node::print(node *h)
		{
			if(h==NULL)
				return;
			else{
				std::cout<<h->data<<std::endl;
				print(h->child);				
			}
		}
	void node::print(){
		std::cout<<data<<std::endl;
		if(child==NULL)
			return;
		else{
			child->print();
		}
	}
	node& node::link(node &to_link){
		to_link.set_parent(*this);
		to_link.set_sibling(*child);
		child = &to_link;
		degree++;
		return *this;
	}

//Unused at this time
	bin_tree::bin_tree(){
		root = new node ;
	}
/*
	bin_heap::bin_heap(){
		head = NULL;
	}
*/
	void bin_heap::print(){
		node * dummy = head;
		while(dummy!=NULL){
			dummy->print();
			dummy = &(dummy->get_sibling());
			std::cout<<std::endl;
		}
	}	
	bin_heap& make_heap(){
		bin_heap * h1 = new bin_heap;
		return *h1;
	}

	bin_heap& merge_heap(bin_heap &h1,bin_heap &h2){
//		bin_heap * n = &(make_heap());
		bin_heap * n = new bin_heap;
		node * current_1=NULL;
		node * current_2=NULL;
		
		//H1 and H2 heaps shouldbe checked first but they didn't  ???

		if(h1.head->get_degree() < h2.head->get_degree()){
			n->head = h1.head;
			current_1 = &(h1.head->get_sibling());
			current_2 = h2.head;
		}
		else{
			n->head = h2.head;
			current_2 = &(h2.head->get_sibling());
			current_1 = h1.head;
		}
		node * current = n->head;
		while ( current_1!=NULL && current_2!=NULL){
			if(current_1->get_degree() > current_2->get_degree()){
				current->set_sibling(*current_2);
				current = &(current->get_sibling());
				current_2 = &(current_2->get_sibling()); 
			}
			else {
				current->set_sibling(*current_1);
				current = &(current->get_sibling());
				current_1 = &(current_1->get_sibling()); 				
			}
		}

		node * rem = NULL;
		if (current_1 == NULL)
			rem = current_2;
		else
			rem = current_1;
		
		while(rem != NULL){
			current->set_sibling(*rem);
			current = &current->get_sibling();
			rem = &rem->get_sibling();
		}
		return *n;
	}

	bin_heap * bin_heapify(bin_heap & h1, bin_heap & h2){
		bin_heap * final = NULL;
		if (h1.head == NULL){
			//std::cout<<&h2<<std::endl;
			final = &h2;	
			return final;
		}
		else if( h2.head == NULL){
			final = &h1;
			return final;
		}

		final = &(merge_heap(h1,h2));
		node * prev = NULL;
		node * current= final->head;
		node * next = &(current->get_sibling());
		bool need_merge = true;
		while(next!=NULL){
			if(current->get_degree()!=next->get_degree())
				need_merge = false;
			else if (&next->get_sibling() != NULL && next->get_sibling().get_degree() == next->get_degree()){
				need_merge = false;	
			}

			if(need_merge){
				if(current->get_key() <= next->get_key()){
					current->set_sibling(next->get_sibling());
					current->link(*next);
				}
				else if (prev != NULL){
					prev->set_sibling(*next);
					next->link(*current);
				}
				else {
					final->head = next;
					next->link(*current);
				}
			}	
			else{
				prev = current ;
				current = next;
			}	

			next = &(current->get_sibling());
		}
		return final;
	}
	bin_heap * insert_heap(bin_heap * h1,int x){
		node * n_node = new node(x);
		bin_heap * n = new bin_heap;
		n->head	= n_node ;
		h1 = bin_heapify(*h1,*n);
		return h1;
	}
}

