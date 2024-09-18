#include <stdio.h>
#include <stdbool.h>

// The constants below are used in the matricesMultiplication function; it' wi'll be improved soon so they won't be necessary anymore.
#define L 3
#define M 4
#define N 5

// ----- Simples arithmetic operations

/**
* Sum all elements of the given vector.
*/
float sumVectorElements(float *vector, int vectorLength) {
  float sum = 0;
  for (int i = 0; i < vectorLength; i++){
    sum += vector[i];
  }
  return sum;
}


/**
* Returns the average of the elements of the given float vector.
*/
float getVectorAverage(float *vector, int vectorLenght) {
  float average = sumVectorElements(vector, vectorLenght)/vectorLenght;
  return average;
}


// ----- Searchers: to be extend with adequations for different time complexities

bool isElementPresent(float element, float *vector, int vectorLength){
  int i;
  for (i = 0; i < vectorLength; i++){
    if(element == vector[i]) return true;
  }
  
  return false;
}


float getLowestElement(float *vector, int vectorLength){
  int lE = vector[0], i;
  for (i = 1; i < vectorLength; i++){
    if(lE > vector[i]) lE = vector[i];
  }
  return lE;
}


float getHighestElement(float *vector, int vectorLength){
  int hE = vector[0], i;
  for (i = 1; i < vectorLength; i++){
    if(hE < vector[i]) hE = vector[i];
  }
  return hE;
}





/**
* Multiplies the given matrices storing the product in
* the third matrix-argument.
*/
void multiplyMatrices(int a[L][M], int b[M][N], int product[L][N]) {
  int rw_count, p_raw = 0, p_col = 0;
  while (p_raw < L) {
    product[p_raw][p_col] = 0;
    for (rw_count = 0; rw_count < M; rw_count++) {
      product[p_raw][p_col] += a[p_raw][rw_count] * b[rw_count][p_col];
    }
    p_col++;
    if (p_col == N) {
      p_col = 0;
      p_raw++;
    }
  }
}


// ----- Vector and matrix printers:

/**
* Prints a vector with the given length.
*/
void printVector(int vector[], int vectorLength) {
  int i;
  for (i = 0; i < vectorLength; i++) {
    printf("%d, ", vector[i]);
    printf("\n");
  }
}


/**
* Prints a matrix of order "raw" x "col".
*/
void printMatrix(int raw, int col, int m[raw][col]) {
  int i, j;
  for (i = 0; i < raw; i++) {
    printf("%dª linha: ", i + 1);
    for (j = 0; j < col; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}


// ----- Vector and matrix register:

void registerVectorElements(float *vector, int vectorLength, float minValue, float maxValue){
  int index;
  float input;
  bool valid = false, isInputInRange;
  
  for(index = 0; index < vectorLength; index++){
    if (index == 0){
      printf("Insira o primeiro valor do vetor: ");  
    }
    else if (index == vectorLength-1){
      printf("Insira o último valor do vetor: ");  
    }
    else {
      printf("Insira o próximo valor: ");
    }
    
    while (valid == false){
      scanf("%f", &input);
      isInputInRange = (minValue <= input && maxValue >= input);
      if (isInputInRange){
        valid = true;
        vector[index] = input;
        fflush(stdin);
      }
      else {
        printf("\tValor inválido! Digite um valor entre %d e %d.\n", minValue, maxValue);
        printf("\tInsira um valor na faixa exigida: ");
      }
    }
    
    valid = false;
  }
}
