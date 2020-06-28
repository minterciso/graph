/*
 * depht_first_search.c
 *
 *  Created on: 28 de jun de 2020
 *      Author: Mateus Interciso
 */
#include "depth_first_search.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int depthFirstSearch(Graph *g, Node *currentNode, Node *destNode){
	currentNode->visited = 1;
	if(currentNode->id == destNode->id) return 0;
	int nodeId = 0;
	while(currentNode->neighbors[nodeId] != -1){
		Node *tmp = findNode(g->nodes, currentNode->neighbors[nodeId]);
		if(tmp->visited == 0){
			int res = depthFirstSearch(g, tmp, destNode) + 1;
			if(res > 0) return res;
		}
		nodeId++;
	}
	return -1;
}

