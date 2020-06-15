/*
 * dijkstra.c
 *
 *  Created on: 15 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "dijkstra.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void startDijkstra(Graph *g, int *d, int *p, int s){
	int v;
	for(v=0;v < g->numNodes; v++){
		d[v]=INFINITY;
		p[v]=-1;
	}
	d[s]=0;
}

/**
 * @brief Try to relax node u until node v edge
 * @parameter g The graph to search nodes and edges weights
 * @parameter d The vector of distances
 * @parameter p The vector of predecessors
 * @parameter u The start node id
 * @parameter v The end node id
 */
void relax(Graph *g, int *d, int *p, int u, int v){
	// First, find the source (u) node and the end node (v)
	Node *start = findNode(g->nodes, u);
	// Now, for each neighbor of u, equal to v (we can have multiple edges to the same start/end), execute...
	for(int i=0;i<g->numNodes;i++){
		if(start->neighbors[i] != -1){
			int endNodeID = start->neighbors[i];
			if(endNodeID == v){
				Node *end = findNode(g->nodes, endNodeID);
				// Get the Edge from u to the neighbor (valid) and not v
				Edge *tmp = findEdge(g->edges, start, end);
				// Now relax it (seee if it's a shorter path, if it is, update accordingly
				if(d[v] > d[u] + tmp->weight){
					d[v] = d[u] + tmp->weight;
					p[v] = u;
				}
			}
		}
	}
}

/**
 * @brief Simply return if there's still an open Node on the Graph
 * @parameter g The graph to search for open nodes
 * @parameter o The vector of open nodes
 */
int openedDijkstra(Graph *g, int *o){
	for(int i=0;i<g->numNodes;i++){
		if(o[i]==1) return 1;
	}
	return 0;
}

/**
 * @brief Search on the graph for the smaller distance still open on the complete graph
 * @parameter g The Graph to search for
 * @parameter open The vector of open nodes
 * @parameter distances The vector of distances
 */
int smallDistance(Graph *g, int *open, int *distances){
	// Find the first open node
	int i=0;
	for(i=0;i<g->numNodes;i++){
		if(open[i] == 1) break;
	}
	if(i==g->numNodes) return -1; // If none, return -1
	// Now search on all other open nodes the one with smaller distance
	int smaller = i;
	for(i=smaller+1; i < g->numNodes; i++){
		if(open[i] == 1 && distances[smaller] > distances[i]){
			smaller = i;
		}
	}
	return smaller;
}


int dijkstra(Graph *g, int *distances, int *predecessors){
	int *open = NULL;
	int startNode = 0;

	if((open = (int*)malloc(sizeof(int)*g->numNodes))==NULL){
		perror("malloc");
		return -1;
	}

	// Initialize the parameters for dijkstra (set distances as infinite and predecessors as -1)
	startDijkstra(g, distances, predecessors, startNode);

	// Now set all nodes in the graph as "open" (ie: valid for checking distances)
	for(int i=0;i<g->numNodes;i++)
		open[i] = 1;

	// Now, while there's an open node (anyone) try to relax it
	while(openedDijkstra(g, open) == 1){
		// Find the last cost open node
		int u = smallDistance(g, open, distances);
		// Set it as closed
		open[u] = 0;
		// Now for all neighbor of the opened node, try to relax (from u to the neighbor node)
		Node *start = findNode(g->nodes, u);
		for(int i=0;i<g->numNodes;i++){
			if(start->neighbors[i] != -1){
				int v = start->neighbors[i];
				relax(g, distances, predecessors, u, v);
			}
		}
	}

	free(open);

	return 0;
}

