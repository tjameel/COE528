#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * @param priority
 * @param data
 * @author tjameel
 * Insert a Node into a priority queue.
 */
void PQ_insert(int priority, char * data) {
 Node_ptr_t new, temp;
 new = (Node_ptr_t)malloc(sizeof(Node_t));
 new ->priority = priority;
 new -> next = NULL;
 new ->data = data;
 


 if(head == NULL || head->priority < priority || PQ_get_size() == 0){
    new->next = head;
    head = new;
 }
 else {
    temp = (Node_ptr_t)malloc(sizeof(Node_t));
    temp = head;
    while(temp->next !=NULL && temp->next->priority>=priority){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;


 }


}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
  Node_ptr_t two;
  two = (Node_ptr_t)malloc(sizeof(Node_t));
  if(head!=NULL){
    two=head;
    head = head->next;
    return two;
}
else {
    return NULL;
}
}


/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}


/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}
