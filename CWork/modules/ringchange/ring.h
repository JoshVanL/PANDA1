#include <stdbool.h>


//Define ring structure
struct ring;
typedef struct ring ring;

//Creat new ring
ring *new_ring();

//Add item to next in list
ring *push_next(ring *r, char *name);

//Add item to previous in list
ring *push_previous(ring *r, char* name);

//Pull item from current position in the list
char *pull(ring *r);

//Change current pointer to next in list
void next(ring *r);

//Change current point to previous in list
void previous(ring *r);

//Delete current item in list
ring *delete_Item(ring *r);

//Rename current item
ring *rename_Item(ring *r, char *name);

//Change current item to first item in list
void start_ring(ring *r);

//Test for current item is at the start of list. True on sucsess
bool isStart_ring(ring *r);

//Return number of items in list
int sizeOf_ring(ring *r);
