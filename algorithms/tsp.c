/*
 * tsp.c
 *
 *  Created on: 15 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "tsp.h"
#include "../utils/methods.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INFINITY INT_MAX / 2  // Very large number to represent the infinity

void tspAux(Graph *g, int i, int *tempSolution, int *bestSolution, int *visited, int *valueBestSolution, int *valueCurrentSolution, int **distanceMatrix){
	if(*valueCurrentSolution > *valueBestSolution) return;
	if(i==g->numNodes){
		int dist = distanceMatrix[tempSolution[i-1]][tempSolution[0]];
		if(dist < INFINITY && *valueCurrentSolution + dist < *valueBestSolution){
			*valueBestSolution = *valueCurrentSolution + dist;
			memcpy(bestSolution, tempSolution, sizeof(int)*g->numNodes);
		}
		return;
	}
	int last = tempSolution[i-1];
	for(int t=0;t<g->numNodes;t++){
		int dist = distanceMatrix[last][t];
		if(visited[t] == 0 && dist < INFINITY){
			visited[t] = 1;
			tempSolution[i] = t;
			*valueCurrentSolution += dist;
			tspAux(g, i+1, tempSolution, bestSolution, visited, valueBestSolution, valueCurrentSolution, distanceMatrix);
			*valueCurrentSolution -= dist;
			visited[t] = 0;
		}
	}
}

int tsp(Graph *g, int start, int *walk){
	int *tempSolution = NULL;
	int *bestSolution = NULL;
	int *visited = NULL;
	int valueBestSolution = INFINITY;
	int valueCurrentSolution = 0;
	int **distance = NULL;

	if(walk != NULL)
		bestSolution = walk;

	fprintf(stdout,"[*] Allocating memory...");fflush(stdout);
	if((tempSolution=(int*)malloc(sizeof(int)*g->numNodes))==NULL){
		perror("malloc");
		return -1;
	}
	if(walk == NULL){
		if((bestSolution=(int*)malloc(sizeof(int)*g->numNodes))==NULL){
			perror("malloc");
			free(tempSolution);
			return -1;
		}
	}
	if((visited=(int*)malloc(sizeof(int)*g->numNodes))==NULL){
		perror("malloc");
		free(tempSolution);
		free(bestSolution);
		return -1;
	}
	if((distance=(int**)malloc(sizeof(int*)*g->numNodes))==NULL){
		perror("malloc");
		free(tempSolution);
		free(bestSolution);
		free(visited);
		return -1;
	}
	for(int i=0;i<g->numNodes;i++){
		if((distance[i]=(int*)malloc(sizeof(int)*g->numNodes))==NULL){
			perror("malloc");
			free(tempSolution);
			free(bestSolution);
			free(visited);
			return -1;
		}
	}
	memset(tempSolution,'\0', sizeof(int)*g->numNodes);
	memset(bestSolution,'\0', sizeof(int)*g->numNodes);
	memset(visited,'\0', sizeof(int)*g->numNodes);
	fprintf(stdout,"Done!\n");fflush(stdout);

	fprintf(stdout,"[*] Initializing...");fflush(stdout);
	if(distanceMatrix(g, distance) < 0){
		fprintf(stderr,"Unable to create distance matrix!\n");
		return -1;
	}
	visited[start] = 1;
	tempSolution[0] = start;
	fprintf(stdout,"Done!\n");fflush(stdout);

	fprintf(stdout,"[*] Calling auxiliary function..."); fflush(stdout);
	tspAux(g, 1, tempSolution, bestSolution, visited, &valueBestSolution, &valueCurrentSolution, distance);
	fprintf(stdout,"Done!\n"); fflush(stdout);

	// Need to free stuff
	if(walk == NULL)
		free(bestSolution);
	free(tempSolution);
	for(int i=0;i<g->numNodes;i++){
		free(distance[i]);
	}
	free(distance);
	free(visited);

	if(valueBestSolution < INFINITY) return valueBestSolution;
	return -1;
}
