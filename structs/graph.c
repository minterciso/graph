/*
 * graph.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Graph* startGraph(void){
	size_t graphSize = sizeof(Graph);
	Graph *g = NULL;
	// Allocate the graph, clear the memory in it and return it
	if((g = (Graph*)malloc(graphSize))==NULL){
		perror("malloc");
		return NULL;
	}
	memset(g, '\0', graphSize);
	return g;
}

Graph* addNodeToGraph(Graph *graph, int nodeId){
	Graph *g = graph;

	if(g == NULL) // If the graph is NULL, create it
		g = startGraph();
	// Now search if the node already exists
	if(findNode(g->nodes, nodeId) != NULL) // If it exists, simply return
		return g;
	g->nodes = addNode(g->nodes, nodeId);
	g->numNodes++;

	return g;
}

Graph* addEdgeToGraph(Graph *graph, int startNodeId, int endNodeId, float weight){
	Graph *g = graph;
	Node *startNode = NULL;
	Node *endNode = NULL;

	// If the graph is NULL, return an error
	if(g == NULL){
		fprintf(stderr,"Uninitialized graph, please add the nodes first!\n");
		return NULL;
	}
	//Find the nodes pointer
	startNode = findNode(graph->nodes, startNodeId);
	endNode = findNode(graph->nodes, endNodeId);
	// Create and add the Edge
	g->edges = addEdge(g->edges, startNode, endNode, weight);
	g->numEdges++;

	return g;
}

void clearGraph(Graph *g){
	if(g == NULL)
		return;
	clearNodes(g->nodes);
	clearEdges(g->edges);
	free(g);
}
