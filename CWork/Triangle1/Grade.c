#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **Grade(int mark){
  if (mark < 0 || mark > 100)return "Invalid mark";
else if (mark < 40 ) return "Fail";
else if (mark < 50) return "Third class (3)";
else if (mark < 60) return "Lower second class (2.2)";
else if (mark < 70) return 5;
else return 6;
}


int main(){
  int mark;
  printf("Please enter the mark out of 100: ");
  scanf("%d", &mark);
  int result = grade(mark)

return 0;
  }
