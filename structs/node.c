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
		tmp = nodes;
		while(tmp->next){
			tmp=tmp->next;
		}
		newNode->prev = tmp;
		tmp->next = newNode;
	}
	return nodes;
}

Node *findNode(Node *nodes, int id){
	Node *tmp = nodes;

	if(nodes == NULL)
		return NULL;

	while(tmp){
		if(tmp->id == id)
			return tmp;
		tmp=tmp->next;
	}
	return NULL;
}

void clearNodes(Node* l){
	Node *node = l;
	Node *tmp = NULL;
	while(node){
		tmp = node;
		node = node->next;
		free(tmp);
	}
	if(node)
		free(node);
}
