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
	graph = createSampleGraph();
	printGraph(graph);

	clearGraph(graph);
	return EXIT_SUCCESS;
}

