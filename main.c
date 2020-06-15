/*
 * main.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/sample.h"
#include "algorithms/hamiltonian.h"

int main(int argc, char *argv[]){
	Graph *graph = NULL;
	graph = createTSPSample();
	int tspResult = 0;
	int *tspWalk = NULL;
	if((tspWalk=(int*)malloc(sizeof(int)*graph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	memset(tspWalk, '0', sizeof(int)*graph->numNodes);

	printGraph(graph);

	tspResult = tsp(graph, 0, tspWalk);
	if(tspResult < 0)
		fprintf(stdout,"TSP is not possible!\n");
	else{
		fprintf(stdout,"Best tour:");
		for(int i=0;i<graph->numNodes;i++)
			fprintf(stdout," %d", tspWalk[i]);
		fprintf(stdout,"\nTour Cost: %d", tspResult);
	}


	clearGraph(graph);
	if(tspWalk)
		free(tspWalk);

	return EXIT_SUCCESS;
}

