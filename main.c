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
#include "algorithms/tsp.h"

int main(int argc, char *argv[]){
	Graph *hamiltonGraph = NULL;
	Graph *tspGraph = NULL;
	int *tspWalk = NULL;
	int tspCost = 0;
	Node *hamiltonSolution = NULL;

	fprintf(stdout,"[*] Allocating memory for all algorithms...\n");
	fprintf(stdout,"[*] === Hamilton Cycle Graph ===\n");
	hamiltonGraph = createHamiltonSample();
	fprintf(stdout,"[*] === TSP Graph ===\n");
	tspGraph = createTSPSample();
	if((hamiltonSolution=(Node*)malloc(sizeof(Node)*hamiltonGraph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	if((tspWalk=(int*)malloc(sizeof(int)*tspGraph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	fprintf(stdout,"[*] Executing Hamilton Cyclo algorithm...\n");fflush(stdout);
	if(hamiltonCycle(hamiltonGraph, hamiltonSolution) == 0)
		fprintf(stdout,"[*] There's no hamilton cycle available!\n");
	else{
		fprintf(stdout,"[*] There's a hamilgon cycle available:");
		for(int i=0;i<hamiltonGraph->numNodes;i++)
			fprintf(stdout, " %d",hamiltonSolution[i].id);
	}
	fprintf(stdout,"\n[*] Executing TSP algorithm...\n");
	tspCost = tsp(tspGraph, 0, tspWalk);
	if(tspCost < 0)
		fprintf(stdout,"[*] TSP is not possible!\n");
	else{
		fprintf(stdout,"[*] Best tour:");
		for(int i=0;i<tspGraph->numNodes;i++)
			fprintf(stdout," %d", tspWalk[i]);
		fprintf(stdout,"\n[*] Tour Cost: %d\n", tspCost);
	}

	fprintf(stdout,"[*] Freeing memory\n");
	clearGraph(tspGraph);
	clearGraph(hamiltonGraph);
	free(tspWalk);
	free(hamiltonSolution);

	return EXIT_SUCCESS;
}

