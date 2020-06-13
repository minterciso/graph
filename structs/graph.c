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

int* neighbors(Graph *graph, int nodeId){
	int *neighbors_id= NULL;
	Node *sourceNode = NULL;
	Edge *tmp = NULL;
	int idx = 0;

	if(graph == NULL){
		fprintf(stderr,"Invalid graph!\n");
		return NULL;
	}

	sourceNode = findNode(graph->nodes, nodeId);
	if(sourceNode == NULL){
		fprintf(stderr,"Unable to find node '%d'\n", nodeId);
		return NULL;
	}

	// Allocate memory for the neighbors list
	if((neighbors_id = (int*)malloc(sizeof(int)*graph->numNodes))==NULL){
		perror("malloc");
		return NULL;
	}
	memset(neighbors_id, -1, sizeof(int)*graph->numNodes);

	tmp = graph->edges;
	int found = 0;
	while(tmp){
		if(tmp->start->id == nodeId){
			for(int i=0;i<graph->numNodes;i++){
				if(neighbors_id[i] == tmp->end->id){
					found = 1;
					break;
				}
			}
			if(found == 0)
				neighbors_id[idx++] = tmp->end->id;
			found = 0;
		}
		tmp=tmp->next;
	}

	return neighbors_id;
}

void clearGraph(Graph *g){
	if(g == NULL)
		return;
	clearNodes(g->nodes);
	clearEdges(g->edges);
	free(g);
}
