/*
*   Author: ARBAAZ MEGHANI
*/

//typedefs for structs
typedef struct struct_lst Queuelst;
typedef struct struct_lst *queueLst;
typedef struct struct_queue *queuePtr;

//defining boolean
typedef enum{FALSE, TRUE} boolean;

//declare debugMode variable as boolean
boolean debugMode;

extern void debugInfo(queuePtr n, boolean debugMode);

extern queueLst lst_init();

extern void lst_free(queueLst *lst);

extern void doAdd(queueLst *lst);

extern void doCallAhead(queueLst *lst);

extern void doWaiting(queueLst lst);

extern void doRetrieve(queueLst *lst);

extern void doList(queueLst lst);

extern void doDisplay(queueLst lst);

extern void clearToEoln();

extern int getNextNWSChar();

extern int getPosInt();

extern char *getName();

extern void printCommands();

extern void addToList(queueLst *lst, boolean status, int size, char *name);

extern boolean doesNameExist(queueLst lst, char *name);

extern boolean updateStatus(queueLst lst, char *name);

extern char* retrieveAndRemove(queueLst *lst, int size);

extern int countGroupsAhead(queueLst lst, char* name);

extern void displayGroupSizeAhead(queueLst lst, char* name);

extern void displayListInformation(queueLst lst);
