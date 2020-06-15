/*
 * sample.h
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef SAMPLE_H_
#define SAMPLE_H_
#include "../structs/graph.h"

/**
 * @brief Create a sample small graph and return the pointer to it
 * @return A pointer to a sample small graph
 */
Graph* createSampleGraph(void);

/**
 * @brief Create a sample small graph used on the hamilton cycle algorithm
 * @return A pointer to a sample small graph
 */
Graph* createHamiltonSample(void);

/**
 * @brief Create a sample small graph used on the TSP algorithm
 * @return A pointer to a sample small graph
 */
Graph* createTSPSample(void);

/**
 * @brief Create a sample small graph used on the Dijksta algorithm
 * @return A pointer to a sample small graph
 */
Graph* createDijkstraSample(void);

/**
 * @brief Print the graph, in the most simple way possible.
 */
void printGraph(Graph *g);


#endif /* SAMPLE_H_ */
