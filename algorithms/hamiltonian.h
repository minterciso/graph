/*
 * hamiltonian.h
 *
 *  Created on: 13 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef HAMILTONIAN_H_
#define HAMILTONIAN_H_

#include "../structs/graph.h"

/**
 * @brief Check's if there's a valid Hamiltonian Cycle (a way to visit all nodes) on the graph
 * @parameter g The Graph we want to find if there's a valid solution
 * @parameter solution If this is not NULL, set the solution here
 * @return 0 if there's not cycle available, 1 otherwise
 */
int hamiltonCycle(Graph *g, Node *solution);

#endif /* HAMILTONIAN_H_ */
