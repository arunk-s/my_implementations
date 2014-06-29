#ifndef BINO_HEAP
#define BINO_HEAP

namespace binomial_heap{
	class node {
		int data;
		int degree;
		node * sibling ;
		node * child ;
		node * parent ;

	public:
		node();
		node (int x);
		void set_data(int x){
			data = x ;
		}
		void set_sibling(node& sib){
			sibling = &sib ;
		}
		void set_child (node& ch){
			child = &ch;
		}
		void set_parent(node& _parent){
			parent = &_parent;
		}
		node& get_sibling(){
			return *sibling; 
		}
		node& get_child(){
			return *child;
		}
		node& get_parent(){
			return *parent;
		}
		int get_key(){
			return data;
		}
		int get_degree(){
			return degree;
		}
		void print(node * h);
		void print();
		/*
		Binomial Link
		*/
		node& link(node& to_link);
		//Make a destructor after making a working copy
	};

	class bin_tree{
		public:
			node * root;
			bin_tree();
	};

	class bin_heap{

	public:
		node * head ;
		bin_heap(){
			head = 0;
		}
		void print();
//		bin_heap();
	};

	bin_heap& make_heap();
	bin_heap * insert_heap(bin_heap * h1,int x);
	bin_heap * bin_heapify(bin_heap & h1, bin_heap & h2);
	bin_heap& merge_heap(bin_heap &h1,bin_heap &h2);


//	bin_heap& make_heap();
//	heap_merge(bin_heap&,bin_heap&);

}

#endif