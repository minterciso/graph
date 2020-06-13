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
	graph = createSampleGraph();
	int hasHamiltonCycle = 0;

	printGraph(graph);

	fprintf(stdout,"[*] Starting Hamilton Cycle algorithm...\n");fflush(stdout);
	Node *hamiltonSolution = NULL;
	size_t hamiltonSolutionSize = sizeof(Node)*graph->numNodes;
	if((hamiltonSolution=(Node*)malloc(hamiltonSolutionSize))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	memset(hamiltonSolution, '\0', hamiltonSolutionSize);
	hasHamiltonCycle = hamiltonCycle(graph, hamiltonSolution);
	if(hasHamiltonCycle == 1){
		fprintf(stdout,"[*] There's a Hamilton Cycle available!\n");
		fprintf(stdout,"[*] Cycle:");
		for(int i=0;i<graph->numNodes;i++)
			fprintf(stdout," %d", hamiltonSolution[i].id);
		fprintf(stdout,"\n");
	}
	else
		fprintf(stdout,"[*] There's no Hamilton Cycle available!\n");
	fflush(stdout);
	if(hamiltonSolution!=NULL)
		free(hamiltonSolution);

	clearGraph(graph);

	return EXIT_SUCCESS;
}

