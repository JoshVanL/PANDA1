
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

//Define list structure
typedef struct List {
  struct List *next;
  char word[20];
  int count;
} list;


//Define hash table structure
typedef struct Hashtable {
  List **arrayOfLists;
  int size;
} Hashtable;


//reads in a word, if the file is at the end, adds the word EOF
void read(char word[20], FILE* book) {
  char c;
  if(fscanf(book,"%c",&c)!=EOF)
  {
    char a[]=". ,;:*!?'-\n\0\r";
    int i;
    i=0;
    while(strchr(a,c)==0)
    {
      word[i]=c;
      i++;
      if(fscanf(book,"%c",&c)==EOF)
      break;
    }
    word[i]='\0';
  }
  else
  {
    strcpy(word,"EOF");
  }
}


//inserts a new word to the linked list
list *insert( char new_word[20], list *next_node) {
  list *new_node=calloc(1, sizeof(list));
  strcpy(new_node->word,new_word);
  new_node->count=1;
  new_node->next=next_node;
  return new_node;
}


//adds a new node for new_word as the next of the list
list *add(list *old_list, char new_word[20]) {
  //this is a special case when the head of the list is empty
  if(old_list==NULL)
  {
    return insert(new_word,NULL);
  }
  else
  {
    list *new_list;
    for(new_list=old_list;new_list->next!=NULL;new_list=new_list->next)
    {
    }
    new_list->next=insert(new_word,NULL);
    return old_list;
  }
}


//Tests if word is in linked list
int find(list *t_list, char what[20]) {
  for(;t_list!=NULL;t_list=t_list->next)
  {
    if(strcasecmp(what,t_list->word)==0)
    {
      return 1;
    }
  }
  return 0;
}


//finds word, returns a pointer to its node
list *find_word(list *t_list, char word[20], int *steps) {
  *steps=0;
  for(;t_list!=NULL;t_list=t_list->next)
  {
    *steps=*steps+1;
    if(strcasecmp(word,t_list->word)==0)
    {
      return t_list;
    }
  }
  return 0;
}

//Insert word into the linked list
list *insertwordlist(list *a_list, FILE * book, long *number) {
  char word[20];
  int steps,t;
  list *point;
  read(word, book);
  if (word[0]!='\0'&&w}ord[0]!='\n'&&strcmp(word,"EOF")!=0) {
    a_list=add(a_list,word);
    *number = *number + 1;
  }
  while(strcmp(word,"EOF")!=0) {
    read(word, book);
    if (word[0]!='\0'&&word[0]!='\n'&&strcmp(word,"EOF")!=0) {
      if(find(a_list,word)==0) {
        a_list=add(a_list,word);
        *number = *number + 1;
        t++;
      }
      else {
        point=find_word(a_list,word,&steps);
        point->count++;
      }
    }
  }
  return a_list;
}

//Create hash value
int hash(char *str,int table_size) {
  long hash = 5381;
  int c;
  while (c = *str++)
  hash =( ((hash << 5) + hash) + c)%table_size; /* hash * 33 + c */
  return hash;
}


//Creates blank hash table
Hashtable newTable(int table_size) {

  return table;
}


//Looks through hash table to see if words exists. If it does, increment by 1
int *findHash(Hashtable table, char word[20]) {

  return find(table.arrayOfLists[wordhash], word);
}


//Creates new hashtable and fills with words from file
Hashtable makeHash(FILE *text) {

  return table;
}


//Main function
int main(int argc, char *args[argc]){
  //Creates linked list
  FILE* book;
  long numberOfWords = 0;
  listHashtable newTable(int table_size) {

  return table;
} *linked_list;
  linked_list=NULL;

  //Inserts words into linked list and outputs result
  book=fopen(args[1],"r");
  printf("%s\n", args[1]);
  clock_t start=clock();
  linked_list=insertwordlist(linked_list, book, &numberOfWords);
  clock_t stop=clock();
  fclose(book);
  double time_taken=(stop-start)/CLOCKS_PER_SEC;
  printf("Reading into a list took %fs for %li words.\n",time_taken, numberOfWords);



  //Insert words into hash table
  book=fopen(args[1],"r");
  start = clock();
  table = insertHashTable(table, table_size, book);
  fclose(book);
  stop = clock();

  //Output result of hash table
  time_taken=(stop-start)/CLOCKS_PER_SEC;
  printf("Reading into a table took %fs for %i words.\n",time_taken, table.wordCount);

  printf("%i\n",find(linked_list,"cow"));
  printf("%i\n",find(linked_list,"computer"));

  int step;
  list *lo
  location=find_word(linked_list,"moocow",&step);
  int this_count=location->count;
  printf("%i\n",this_count);


  //Prompt to enter a word to search
  char *input;
  printf("Enter a word to find in the book: ");
  fgets(input, sizeof(input), stdin);
  printf("\n%s appears %i times(s)\n", input, find(linked_list, input) );

  return 0;
}
