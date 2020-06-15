/*
 * graph.h
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "node.h"
#include "edge.h"

#include <limits.h>

#define INFINITY INT_MAX / 2  // Very large number to represent the infinity

/// Simple graph information
typedef struct {
	int numNodes;		/// The amount of nodes on the graph
	int numEdges;		/// The amount of edges on the graph
	Node *nodes;		/// A pointer to the double linked list of nodes
	Edge *edges;		/// A pointer to the double linked list of edges
}Graph;

/**
 * @brief Create and add a node to the graph
 * @parameter graph A pointer to an existing graph, if this is NULL then the graph will be created
 * @parameter nodeId The node id to add on the graph
 * @return A pointer to a newly created graph, or graph
 */
Graph* addNodeToGraph(Graph *graph, int nodeId);

/**
 * @brief Add an edge to an already existing graph
 * @parameter graph An already create graph with valid nodes
 * @parameter startNodeId The start node id of the edge
 * @parameter endNodeId The end node id of the edge
 * @parameter weight The weight of the edge
 * @return A pointer to graph, or NULL if there was an error
 */
Graph* addEdgeToGraph(Graph *graph, int startNodeId, int endNodeId, float weight);

/**
 * @brief Returns a list of neighbors of the passed node id
 * @parameter graph An already initialized graph
 * @parameter nodeId The id of the node
 * @return NULL if the node was not found (or it has no neighbor) or a list of id's for each neighbor. You must free this pointer.
 */
int* neighbors(Graph *graph, int nodeId);

/**
 * @brief Clear the memory used when creating the graph
 * @parameter g A pointer to the created graph
 */
void clearGraph(Graph *g);

#endif /* GRAPH_H_ */
