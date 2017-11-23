/*
*   Author: Arbaaz Meghani
*   DESCRIPTION: This file contains functions to implement a queue structure using a linked list.
*/

//include statements
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//define Node structs
struct struct_queue {
	char *name;
	int size;
	boolean status;
	struct struct_queue *next;
};

//define wrapper struct to keep track of head and end of list
struct struct_lst {
	queuePtr hd;
	queuePtr end;
};

/*
*   Function: initialize a list
*   Parameters: none
*   Return: return pointer to list structure
*/
queueLst lst_init() {
    queueLst ret = (queueLst)malloc(sizeof(struct struct_lst));
    ret->hd = NULL;
    ret->end = NULL;
    return ret;
}

/*
*   Function: Free the list
*   Parameters: Pointer to pointer of list
*   Return: none
*/
void lst_free(queueLst *lst) {
    queuePtr tmp = (*lst)->hd;
    while((*lst)->hd != NULL) {
        (*lst)->hd = (*lst)->hd->next;
        free(tmp->name);
        free(tmp);
        tmp = (*lst)->hd;
    }
    free(*lst);
}

/*
*   Function: add element to list
*   Parameters: Pointer to pointer of a list, status of group, size of group, name of group
*   Return: none
*/
void addToList(queueLst *lst, boolean status, int size, char *name) {
	queuePtr p = (struct struct_queue *)malloc(sizeof(struct struct_queue));
	p->next = NULL;
	p->name = name;
	p->status = status;
	p->size = size;
	if((*lst)->hd == NULL) {
		(*lst)->hd = p;
		(*lst)->end = p;
	}
	else {
		(*lst)->end->next = p;
		(*lst)->end = p;
	}
}

/*
*   Function: Checks if name exists in list
*   Parameters: Pointer to list, name
*   Return: true if name exists; false otherwise
*/
boolean doesNameExist(queueLst lst, char *name) {
    queuePtr temp = lst->hd;
    while(temp != NULL) {
        debugInfo(temp, debugMode);
        if(strcmp(temp->name, name) == 0) {
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}

/*
*   Function: Update the wait status of group
*   Parameters: Pointer to list, name of group
*   Return: TRUE if updated, false if already true
*/
boolean updateStatus(queueLst lst, char *name) {
    queuePtr tmp = lst->hd;
    while(tmp != NULL) {
        debugInfo(tmp, debugMode);
        if(strcmp(tmp->name, name) == 0) {
            if(tmp->status) {
                return FALSE;
            }
            else {
                tmp->status = TRUE;
                return TRUE;
            }
        }
        tmp = tmp->next;
    }
    return FALSE;
}

/*
*   Function: remove person from list
*   Parameters: Pointer to pointer of list, size of table
*   Return: name of group removed
*/
char* retrieveAndRemove(queueLst *lst, int size) {
    queuePtr curr = (*lst)->hd;
    queuePtr prev = NULL;
    while(curr != NULL) {
        debugInfo(curr, debugMode);
        if(curr->size <= size && curr->status == TRUE && prev == NULL) {
            (*lst)->hd = curr->next;
            char *name = curr->name;
            free(curr);
            return name;
        }
        else if(curr->size <= size && curr->status == TRUE) {
            prev->next = curr->next;
            char *name = curr->name;
            free(curr);
            return name;
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}

/*
*   Function: Count number of groups ahead of group
*   Parameters: Pointer to list, name of group
*   Return: number of groups ahead
*/
int countGroupsAhead(queueLst lst, char* name) {
    queuePtr tmp = lst->hd;
    if(tmp == NULL) {
        return -1;
    }
    int count = 0;
    while(tmp != NULL && (strcmp(tmp->name, name) != 0)) {
        debugInfo(tmp, debugMode);
        count++;
        tmp = tmp->next;
    }
    return count;
}

/*
*   Function: Display the size of each group ahead
*   Parameters: Pointer to list, name of group
*   Return: none
*/
void displayGroupSizeAhead(queueLst lst, char* name) {
    queuePtr tmp = lst->hd;
    int i = 1;
    while(tmp != NULL && (strcmp(tmp->name, name) != 0)) {
        debugInfo(tmp, debugMode);
        printf("%i) %i\n", i, tmp->size);
        tmp = tmp->next;
        i++;
    }
    printf("\n");
}

/*
*   Function: display all groups
*   Parameters: Pointer to list
*   Return: none
*/
void displayListInformation(queueLst lst) {
    queuePtr tmp = lst->hd;
    while(tmp != NULL) {
        printf("Name: %s\n", tmp->name);
        printf("Size: %i\n", tmp->size);
        if(tmp->status) {
            printf("Status: Waiting in restaurant\n");
        }
        else {
            printf("Status: Not in restaurant\n");
        }
        printf("\n");
        tmp = tmp->next;
    }
}

/*
*   Function: Displays debug info if debugMode is turned on
*   Parameters: pointer to a node in list and if debugMode is on or not
*   Return: none
*/
void debugInfo(queuePtr n, boolean debugMode) {
    if(debugMode) {
        printf("######DEBUG INFO######\n");
        printf("Name: %s\n", n->name);
        printf("Size: %i\n", n->size);
        if(n->status) {
            printf("Status: Waiting in restaurant\n");
        }
        else {
            printf("Status: Not in restaurant\n");
        }
        printf("####END OF DEBUG INFO####\n");
        printf("\n");
    }
}
