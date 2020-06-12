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
	if((g = (Graph*)malloc(graphSize))==NULL){
		perror("malloc");
	}
	return g;
}

Graph* addNodeToGraph(Graph *graph, int nodeId){
	Graph *g = graph;

	if(g == NULL)
		g = startGraph();
	g->nodes = addNode(g->nodes, nodeId, -1);
	g->numNodes++;

	return g;
}

Graph* addEdgeToGraph(Graph *graph, int startNodeId, int endNodeId, float weight){
	Graph *g = graph;
	Node *startNode = NULL;
	Node *endNode = NULL;

	if(g == NULL){
		fprintf(stderr,"Uninitialized graph, please add the nodes first!\n");
		return NULL;
	}
	//Find the nodes pointer
	startNode = findNode(graph->nodes, startNodeId);
	endNode = findNode(graph->nodes, endNodeId);
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
