#include <stdlib.h>
#include <stdbool.h>
#include "lib.h"

kdTree create_kdTree()
{
	kdTree retorno = (kdTree)
	{
		.root = NULL,
		.number_elements = 0,
	};
	return retorno;

}

Node* _create_node()
{
	Node* retorno;
	*retorno = (Node)
	{
		.point = 0,
		.Obj = NULL,
		.father = NULL,
		.left = NULL,
		.right = NULL,
	};
	return retorno;
}

bool insert_element(kdTree* tree, const Point point, const size_t size_props, const void* element)
{
	if(tree->root == NULL) {
		Node* root = tree->root;
		root->point = point;
	}

	
	return true;
}

Point get_element(const kdTree* tree)


