/*
 * main.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include <stdio.h>
#include <stdlib.h>
#include "utils/sample.h"

int main(int argc, char *argv[]){
	Graph *graph = NULL;
	graph = createHamiltonSample();
	printGraph(graph);
	fprintf(stdout,"Showing some neighbours...\n");
	for(int j=0;j<5;j++){
		fprintf(stdout,"\n%d=", j+1);
		int *n = neighbors(graph, j+1);
		for(int i=0;i<graph->numNodes;i++)
			printf("%d ", n[i]);
		if(n)
			free(n);
	}

	clearGraph(graph);

	return EXIT_SUCCESS;
}

