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

typedef struct {
	int numNodes;
	int numEdges;
	Node *nodes;
	Edge *edges;
}Graph;

Graph* addNodeToGraph(Graph *graph, int nodeId);

Graph* addEdgeToGraph(Graph *graph, int startNodeId, int endNodeId, float weight);

void clearGraph(Graph *g);

#endif /* GRAPH_H_ */
