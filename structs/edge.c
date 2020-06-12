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
	newEdge->next = NULL;

	if(edges == NULL)
		edges = newEdge;
	else{
		tmp = edges;
		while(tmp->next)
			tmp = tmp->next;
		newEdge->prev = tmp;
		tmp->next = newEdge;
	}
	return edges;
}

void clearEdges(Edge* l){
	Edge *edge = l;
	Edge *tmp = NULL;
	while(edge){
		tmp = edge;
		edge = edge->next;
		free(tmp);
	}
	if(edge)
		free(edge);

}

