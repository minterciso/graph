/*
 * edge.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "edge.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Edge *createEdge(void){
	size_t edgeSize = sizeof(Edge);
	Edge *newEdge = NULL;

	// If possible, allocate the new edge memory and clear it
	if((newEdge=(Edge*)malloc(edgeSize))==NULL){
		perror("malloc");
		return NULL;
	}
	memset(newEdge,'\0', edgeSize);
	return newEdge;
}

Edge* addEdge(Edge *edges, Node *nodeStart, Node *nodeEnd, float weight){
	Edge *newEdge = createEdge();
	Edge *tmp = NULL;
	newEdge->start = nodeStart;
	newEdge->end = nodeEnd;
	newEdge->weight = weight;

	if(edges == NULL)
		edges = newEdge;
	else{
		// If the edges is not NULL, than we need to go to the end of the linked list
		tmp = edges;
		while(tmp->next)
			tmp = tmp->next;
		// Now add the new edge
		newEdge->prev = tmp;
		tmp->next = newEdge;
	}
	return edges;
}

void clearEdges(Edge* l){
	Edge *edge = l;
	Edge *tmp = NULL;
	// Walk the list and clear all the edges
	while(edge){
		tmp = edge;
		edge = edge->next;
		free(tmp);
	}
	if(edge)
		free(edge);

}

