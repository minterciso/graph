/*
 * edges.h
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef EDGE_H_
#define EDGE_H_
#include "node.h"

///A simple definition of a edge on the graph
typedef struct edge_list{
	Node *start;				/// The start node
	Node *end;					/// The end node
	float weight;				/// The edge weight
	struct edge_list *next;		/// A pointer to the next edge
	struct edge_list *prev;		/// A pointer to the previous edge
}Edge;

/**
 * @brief Add an edge on the double linked list
 * @parameter edges A pointer to an already initialized Edge list, if it's NULL we create a new one and return it
 * @parameter nodeStart A pointer to the starting node of the edge
 * @parameter nodeEnd A pointer to the ending node of the edge
 * @parameter weight The weight of the edge
 * @return A pointer to a newly allocated Edge list, or the same as edges
 */
Edge* addEdge(Edge *edges, Node *nodeStart, Node *nodeEnd, float weight);

/**
 * @brief Clear the memory used on the Edge double linked list
 * @parameter l A pointer to the start of the double linked list
 */
void clearEdges(Edge* l);


#endif /* EDGE_H_ */
