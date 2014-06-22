#ifndef QUEUE_H
#define QUEUE_H

class vertexTag ; 
class link {
public:
	vertexTag * vertex;
	link * next ;
	link * prev ;
	link();
};

class que{
	link * head;
public:
	que();
	vertexTag * push(vertexTag * w);
	vertexTag * pop();
	bool empty();
};

#endif