#include "sort.h"
/**
 * 
*/
void swap_nodes(listint_t *prev, listint_t *curr) 
{
    if (prev->prev != NULL)
        prev->prev->next = curr;  
            
    curr->prev = prev->prev;  
    prev->next = curr->next; 
    if (curr->next != NULL)
        curr->next->prev = prev;
            
    curr->next = prev;  
    prev->prev = curr;
}

void insertion_sort_list(listint_t **list) 
{
    listint_t *curr, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;    
    while (curr != NULL) {
        prev = curr->prev;    
        next = curr->next;
        
        while (prev != NULL && prev->n > curr->n) {      
            // Swap nodes      
            swap_nodes(prev, curr);           
            prev = curr->prev;           
            // Print list after swap           
            printf("Result: ");           
            print_list(*list);        
        }
        curr = next;
    }
}



