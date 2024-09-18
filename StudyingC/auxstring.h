#include <string.h>

int isLetter(char letter){
  if (letter >= 65 && letter <=90 ||
    letter >= 97 && letter <=122 || letter == 45) // Hyphen
    return 1;
  else return 0;
}

int isSeparator(char letter){
  int seps[8] = {32, 33, 40, 41, 46, 58, 59, 63};
  for (int i = 0; i<8; i++)
    if (letter == seps[i]) return 1;
  
  return 0;
}

int countWords(char* sentence){
  int count = 0, i;
  for (i = 0; i < strlen(sentence); i++){
    if(isLetter(sentence[i]) == 0 && 
      (isSeparator(sentence[i+1]) == 0))
        count++;
  }
  return count;
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
* Returns the index of the first occurante of a space,
* from firstIndex; returns -1 if none is find or -2 if,
* firstIndex is out of the text length bound.
*/
int spaceOccurance(char* text, int firstIndex){ 
  int tLen = strlen(text);
  if (firstIndex > tLen-1) return -2;
  
  for(int i = firstIndex; i < tLen; i++)
    if(text[i] == ' ') 
      return i;
  
  return -1;
}

/**
* Reverse a string; shall be passed to a char pointer.
*/
char* reverseWord(char* word){
  int wLen = strlen(word);
  char* aux = (char*) malloc((wLen+1)*sizeof(char));
  for (int i = wLen-1; i >= 0; i--){
    aux[i] = word[wLen -1 - i];
  }
  aux[wLen] = '\0';
  return aux;
}