/*
 * tsp.h
 *
 *  Created on: 15 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef TSP_H_
#define TSP_H_

#include "../structs/graph.h"

/**
 * @brief Find's if possible the Traveling Salesman Problem using the idea for the Hmiltonian Cycle
 * @parameter g The graph to search for
 * @parameter start The initial node
 * @parameter walk A pointer to an already initialized array of int to store the best walk found
 * @return The value of the TSP solution
 */
int tsp(Graph *g, int start, int *walk);

#endif /* TSP_H_ */
