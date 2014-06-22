#ifndef HEAP_H
#define HEAP_H
class vertexTag;
class heapitem {
	vertexTag * vertex;
	int key;
public:
	heapitem();
	heapitem(vertexTag *,int);
	inline int getkey();
	inline void setkey(int);
	inline vertexTag * getitem();
	inline void setitem(vertexTag *);
};
class heap{
	heapitem * elements;
	int num_of_elem;
	int current_num;
public:
	heap();
	heap(int);
	heapitem remove();
	vertexTag *rem_with_vertex();
	bool add(const heapitem item);
	bool add(vertexTag *,const int);
	void shiftdown(int index);
	void shiftup(int index);
	inline int leftchild(int index);
	inline int rightchild(int index);
	inline int parentof(int index);
	int current_elements();
	bool empty();
	vertexTag * get_top_vertex();
	bool desc_priority(vertexTag * , int newkey);	
};



#endif