/*
 * simple_deque.h
 *
 *  Created on: 12 de jun de 2020
 *      Author: Mateus Interciso
 */

#ifndef NODE_H_
#define NODE_H_


typedef struct node_list{
	int id;
	float weight;
	struct node_list *next;
	struct node_list *prev;
}Node;

Node* addNode(Node *nodes, int id, float weight);

Node *findNode(Node *nodes, int id);

void clearNodes(Node* l);


#endif /* NODE_H_ */
