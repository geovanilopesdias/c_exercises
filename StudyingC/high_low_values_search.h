#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*Auxiliar comparing function for quicksort*/
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}


/* Counts the numbers in a standardly splitted string*/
int countValuesInString(const char *str, const char splitter){
  int c = 0;
  while(*str){
    if (*str++ == splitter) c++;
  }
  return ++c;
}

/**
* Assuming all elements in a string are valid integers, converts its elements,
* standardly splitted, into the passed integer vector.
*/
void strToIntVector(int32_t *vector, int vectorLength, const char *str, char *splitter){
  char copy[strlen(str)];
  strcpy(copy, str);
  char *ptr = strtok(copy, " ");
  int i = 0;
  while(ptr != NULL){
    vector[i++] = atoi(ptr);
    ptr = strtok(NULL, " ");
  }
  
}

void high_and_low (const char *strnum, char *result)
{
  int arrayLength = countValuesInString(strnum, ' ');
  int32_t array[arrayLength];
  strToIntVector(array, arrayLength, strnum, " ");
  qsort(array, arrayLength, sizeof(int32_t), comp);
	sprintf(result, "%d %d", array[arrayLength-1], array[0]);
}