/*
 * node.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *createNode(void){
	size_t nodeSize = sizeof(Node);
	Node *newNode = NULL;

	// If possible, allocate the new node memory and clear it
	if((newNode = (Node*)malloc(nodeSize))==NULL){
		perror("malloc");
		return NULL;
	}
	memset(newNode, '\0', nodeSize);
	return newNode;
}

Node* addNode(Node *nodes, int id){
	Node *newNode = createNode();
	Node *tmp = NULL;
	newNode->id = id;
	newNode->next = NULL;

	if(nodes == NULL)
		nodes = newNode;
	else{
		// If the nodes is not NULL, than we need to go to the end of the linked list
		tmp = nodes;
		while(tmp->next){
			tmp=tmp->next;
		}
		// Now add the newly created node on the end
		newNode->prev = tmp;
		tmp->next = newNode;
	}
	return nodes;
}

Node *findNode(Node *nodes, int id){
	Node *tmp = nodes;

	// If the list is NULL, simply return NULL (can't find something on nowehere)
	if(nodes == NULL)
		return NULL;

	// Simply walk the list till you find the node id you want
	while(tmp){
		if(tmp->id == id) // If found, return it
			return tmp;
		tmp=tmp->next;
	}
	// If we are here, we were unable to find it, so return NULL
	return NULL;
}

void clearNodes(Node* l){
	Node *node = l;
	Node *tmp = NULL;
	// Walk the list and clear all the nodes
	while(node){
		tmp = node;
		node = node->next;
		if(tmp->neighbors)
			free(tmp->neighbors);
		free(tmp);
	}
	if(node)
		free(node);
}
