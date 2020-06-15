/*
 * dijkstra.h
 *
 *  Created on: 15 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "../structs/graph.h"

/**
 * @brief Calculates dijkstra and puts the distancves from the starting node (hardcoded to 0) on distances, and each predecessor on predecessors
 * @parameters g The graph to calculate Dijkstra
 * @parameter distances The already initialized vector for all distances
 * @parameter pradecessors The alread initialized vector all predecessors
 */
int dijkstra(Graph *g, int *distances, int *predecessors);


#endif /* DIJKSTRA_H_ */
