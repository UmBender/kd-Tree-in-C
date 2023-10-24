#ifndef LIB_H
#define LIB_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#define NUM_CHILD 1024


struct String {
	char* 									elem;
	size_t 									size;
};

typedef struct String String;

struct Point;
typedef struct Point Point;

struct Point {
	double 	    							 x;
	double                 		 y;
};

struct Node;
typedef struct Node Node;
struct Node
{
	Point  								 point;
	void*				 	   			   Obj;
	Node*	 	   						  left; 
	Node*									 right;
	Node* 		   	 		    father;
};

struct kdTree;
typedef struct kdTree kdTree;
struct kdTree 
{
	Node* 	 			          root;
	size_t       number_elements;
};


Point clone_point(const Point* point);
Point _random_point();
kdTree create_kdTree();
bool insert_element(kdTree* tree, const Point point, const size_t size_props,  void* element);
void* get_element(const kdTree* tree, const Point* point, const size_t size_props);
bool  _insert_element_child(Node* self, const Point point, const size_t size_props,  void* element, const int split_case);
//Node* _create_node();
Point _create_point(const double x, const double y);
void* _get_element_child(const Node* node, const Point* point,const size_t size_props, const int split_case);
void print_tree(kdTree* tree);
void _print_node(Node* node, size_t spaces);

bool _same_point(const Point* point1, const Point* point2) ;

#endif
