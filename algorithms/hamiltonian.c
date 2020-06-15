/*
 * hamiltonian.c
 *
 *  Created on: 13 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "hamiltonian.h"
#include "../utils/methods.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INFINITY INT_MAX / 2  // Very large number to represent the infinity

/**
 * @brief This is the auxiliary function that actually walks trough the Graph and tries to find a valid Hamiltonian Cycle
 * @parameter g The Graph to check for a cycle
 * @parameter i The node to check the neighbors
 * @parameter solution The solution vector
 * @return 1 if it found a hamiltonian cycle, 0 otherwise
 */
int hamiltonCycloAux(Graph *g, int i, Node *solution){
	if(i==g->numNodes){ // If this is the last node
		int idx = 0;// Look trough all the node neighbors, if it's the same as the start, return true for cycle, otherwise return false
		while(solution[i-1].neighbors[idx]!=-1){
			Node *tmp = findNode(g->nodes, solution[i-1].neighbors[idx++]);
			if(tmp->id == solution[0].id) return 1;
		}
		return 0;
	}
	// If this is not the last node, go trough all node neighbors and visit tem, then check again if we have a valid cycle
	int idx=0;
	while(solution[i-1].neighbors[idx] != -1){
		Node *tmp = findNode(g->nodes, solution[i-1].neighbors[idx++]);
		if(tmp->visited == 0){
			tmp->visited = 1;
			memcpy(&solution[i], tmp, sizeof(Node));
			if(hamiltonCycloAux(g, i+1, solution) == 1) return 1;
			tmp->visited = 0;
		}
	}
	return 0;
}

int hamiltonCycle(Graph *g, Node *solution){
	int localSolution = 0; // Just a flag to know if we need to clear the solution memory or not
	int exists = 0;
	int startNode = 1;

	if(solution == NULL){
		localSolution = 1;
		fprintf(stdout,"[*] Allocating memory...");fflush(stdout);
		if((solution=(Node*)malloc(sizeof(Node)*g->numNodes))==NULL){
			perror("malloc");
			return -1;
		}
		memset(solution, '\0', sizeof(Node)*g->numNodes);
		fprintf(stdout, "Done!\n");fflush(stdout);
	}

	fprintf(stdout,"[*] Initializing...");fflush(stdout);

	g->nodes->visited = 1;
	memcpy(&solution[0], g->nodes, sizeof(Node));
	fprintf(stdout,"Done!\n");fflush(stdout);

	fprintf(stdout,"[*] Starting auxiliary function from start node %d...\n", startNode);fflush(stdout);
	exists = hamiltonCycloAux(g, startNode, solution);
	if(localSolution==1){
		fprintf(stdout,"[*] Clearing memory...");fflush(stdout);
		free(solution);
		fprintf(stdout,"Done!\n");fflush(stdout);
	}

	return exists;
}

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

	if(valueBestSolution < INFINITY) return valueBestSolution;
	return -1;
}
