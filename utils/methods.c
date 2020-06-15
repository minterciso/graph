/*
 * methods.c
 *
 *  Created on: 15 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "methods.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INFINITY INT_MAX / 2

int distanceMatrix(Graph *g, int **distance){
	if(g==NULL || distance == NULL){
		fprintf(stderr,"Invalid parameters\n");
		return -1;
	}
	Node *start= NULL;
	Node *end = NULL;
	Edge *tmp = NULL;
	int dist = -1;
	for(int i=0;i<g->numNodes;i++){
		for(int j=0;j<g->numNodes;j++){
			dist = INFINITY;
			start = findNode(g->nodes, i);
			end = findNode(g->nodes, j);
			tmp = findEdge(g->edges, start, end);
			if(tmp != NULL)
				dist = tmp->weight;
			distance[i][j] = dist;
		}
	}
	return 0;
}

void printDistanceMatrix(Graph *g, int **distance){
	if(g == NULL || distance == NULL) return;
	for(int i=0;i<g->numNodes;i++){
		fprintf(stdout, "%d:", i);
		for(int j=0;j<g->numNodes;j++){
			fprintf(stdout,"%d ", distance[i][j]);
		}
		fprintf(stdout, "\n");
	}
}
