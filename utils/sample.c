/*
 * sample.c
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "sample.h"
#include "../structs/node.h"
#include "../structs/edge.h"

#include <stdio.h>
#include <stdlib.h>

Graph* createSampleGraph(void){
	Graph *graph = NULL;
	fprintf(stdout, "[*] Creating 4 nodes...");
	graph = addNodeToGraph(graph, 1);
	graph = addNodeToGraph(graph, 2);
	graph = addNodeToGraph(graph, 3);
	graph = addNodeToGraph(graph, 4);
	fprintf(stdout,"Done!\n");
	fprintf(stdout,"[*] Creating edges...\n");
	fflush(stdout);
	fprintf(stdout,"1->2 (10)\n");fflush(stdout);
	graph = addEdgeToGraph(graph, 1, 2, 10);
	fprintf(stdout,"1->3 (40)\n");fflush(stdout);
	graph = addEdgeToGraph(graph, 1, 3, 40);
	fprintf(stdout,"2->3 (20)\n");fflush(stdout);
	graph = addEdgeToGraph(graph, 2, 3, 20);
	fprintf(stdout,"3->4 (5)\n");fflush(stdout);
	graph = addEdgeToGraph(graph, 3, 4, 5);
	fprintf(stdout,"4->1 (70)\n");fflush(stdout);
	graph = addEdgeToGraph(graph, 4, 1, 70);
	fprintf(stdout,"[*] Done!\n");
	fprintf(stdout,"[*] Configuring all neighbors...");fflush(stdout);
	Node *tmp = graph->nodes;
	while(tmp){
		tmp->neighbors = neighbors(graph, tmp->id);
		tmp=tmp->next;
	}
	return graph;
}

Graph* createHamiltonSample(void){
	Graph *graph = NULL;
	fprintf(stdout, "[*] Creating 5 nodes...");
	for(int i=0;i<5;i++)
		graph = addNodeToGraph(graph, i+1);
	fprintf(stdout,"Done!\n");
	fprintf(stdout,"[*] Creating edges");
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 5, 4, 0);
	graph = addEdgeToGraph(graph, 4, 5, 0);
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 5, 3, 0);
	graph = addEdgeToGraph(graph, 3, 5, 0);
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 4, 2, 0);
	graph = addEdgeToGraph(graph, 2, 4, 0);
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 4, 1, 0);
	graph = addEdgeToGraph(graph, 1, 4, 0);
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 2, 1, 0);
	graph = addEdgeToGraph(graph, 1, 2, 0);
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 3, 1, 0);
	graph = addEdgeToGraph(graph, 1, 3, 0);
	fprintf(stdout,"."); fflush(stdout);
	graph = addEdgeToGraph(graph, 3, 5, 0);
	graph = addEdgeToGraph(graph, 5, 3, 0);
	fprintf(stdout,"[*] Done!\n");
	fprintf(stdout,"[*] Configuring all neighbors...");fflush(stdout);
	Node *tmp = graph->nodes;
	while(tmp){
		tmp->neighbors = neighbors(graph, tmp->id);
		tmp=tmp->next;
	}
	return graph;
}

void printGraph(Graph *g){
	Node *node = NULL;
	Edge *edge = NULL;

	if(g == NULL){
		fprintf(stderr,"Invalid graph!\n");
		return;
	}
	//Now print the nodes information
	fprintf(stdout,"[*] Node information:");
	node = g->nodes;
	while(node){
		fprintf(stdout," %d",node->id);
		node=node->next;
	}
	fprintf(stdout,"\n");
	fprintf(stdout,"[*] Edge information:\n");
	edge = g->edges;
	while(edge){
		fprintf(stdout,"\t(%d)-%2.2f->(%d)\n", edge->start->id, edge->weight, edge->end->id);
		edge = edge->next;
	}
	fprintf(stdout,"\n");
}
