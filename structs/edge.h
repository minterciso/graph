/*
 * edges.h
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef EDGE_H_
#define EDGE_H_
#include "node.h"

typedef struct edge_list{
	Node *start;
	Node *end;
	float weight;
	struct edge_list *next;
	struct edge_list *prev;
}Edge;

Edge* addEdge(Edge *edges, Node *nodeStart, Node *nodeEnd, float weight);

void clearEdges(Edge* l);


#endif /* EDGE_H_ */
