/*
 * main.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs/graph.h"
#include "utils/sample.h"
#include "utils/methods.h"
#include "algorithms/hamiltonian.h"
#include "algorithms/tsp.h"
#include "algorithms/dijkstra.h"

int main(int argc, char *argv[]){
	Graph *hamiltonGraph = NULL;
	Graph *tspGraph = NULL;
	Graph *dijkstraGraph = NULL;
	int *tspWalk = NULL;
	int tspCost = 0;
	Node *hamiltonSolution = NULL;
	int *dijkstraDistances = NULL;
	int *dijkstraPredecessors = NULL;

	// Initialize all memory and algorithms
	fprintf(stdout,"[*] Allocating memory for all algorithms...\n");
	fprintf(stdout,"[*] === Hamilton Cycle Graph ===\n");
	hamiltonGraph = createHamiltonSample();
	fprintf(stdout,"[*] === TSP Graph ===\n");
	tspGraph = createTSPSample();
	fprintf(stdout,"[*] === Dijkstra Graph ===\n");
	dijkstraGraph = createDijkstraSample();
	fprintf(stdout,"[*] Placeholders...");
	if((hamiltonSolution=(Node*)malloc(sizeof(Node)*hamiltonGraph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	if((tspWalk=(int*)malloc(sizeof(int)*tspGraph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	if((dijkstraDistances=(int*)malloc(sizeof(int)*dijkstraGraph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	if((dijkstraPredecessors=(int*)malloc(sizeof(int)*dijkstraGraph->numNodes))==NULL){
		perror("malloc");
		return EXIT_FAILURE;
	}
	fprintf(stdout,"Done!\n");

	// Execute all algorithms
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
	fprintf(stdout,"[*] Executing Dijkstra algorithm\n");
	if(dijkstra(dijkstraGraph, dijkstraDistances, dijkstraPredecessors) < 0)
		fprintf(stderr,"[*] Unable to execute Dijkstra\n");
	else{
		fprintf(stdout,"[*] Dijkstra distances:");
		for(int i=0;i<dijkstraGraph->numNodes;i++)
			fprintf(stdout," %d", dijkstraDistances[i]);
		fprintf(stdout,"\n[*] Dijkstra predecessors:");
		for(int i=0;i<dijkstraGraph->numNodes;i++)
			fprintf(stdout," %d", dijkstraPredecessors[i]);
		fprintf(stdout,"\n");
	}

	fprintf(stdout,"[*] Freeing memory\n");
	free(tspWalk);
	free(hamiltonSolution);
	free(dijkstraDistances);
	free(dijkstraPredecessors);
	clearGraph(tspGraph);
	clearGraph(hamiltonGraph);
	clearGraph(dijkstraGraph);


	return EXIT_SUCCESS;
}

