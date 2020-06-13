/*
 * simple_deque.h
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef NODE_H_
#define NODE_H_

/// Basic definition of a node (a simple double linked list to add n nodes) with id information
typedef struct node_list{
	int id;						/// The id information of the node
	int visited;				/// This is used on the hamiltonian cycle
	int *neighbors;				/// This is used on the hamiltonian cycle
	struct node_list *next;		/// A pointer to the next node
	struct node_list *prev;		/// A pointer to the previous node
}Node;

/**
 * @brief Add a node and return a pointer to the start of the linked list (if new)
 * @parameter nodes A pointer to an already initialized double linked list of nodes, if it's NULL this function creates a new one and returns it
 * @parameter id The id information of the node
 * @return A pointer to nodes, or to a new double linked list of nodes
 */
Node* addNode(Node *nodes, int id);

/**
 * @brief Finds a node on the double linked list
 * @parameter nodes An already initialized double linked list of nodes
 * @parameter id The id to search
 * @return A pointer to the node found, or NULL if unable to find
 */
Node *findNode(Node *nodes, int id);

/**
 * @brief Clear the node memory
 * @param l A pointer to double linked list of nodes
 */
void clearNodes(Node* l);


#endif /* NODE_H_ */
