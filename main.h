#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "recursion_study.h"
#include "lklist.h"

void cpfStringToIntArray(char *cpf, int *intArray) {
  int i = 0;
  while (*cpf != '\0') {
    intArray[i] = *cpf - '0';
    cpf++;
    i++;
  }
}

int isCpfValid(char *sCpf) {
  int iCpf[11];
  int sum, rem, digitCount = 0;
  cpfStringToIntArray(sCpf, iCpf);

  // Checking if all digits are equal:
  for (int i = 0; i < 10; i++) {
    if (iCpf[i] == iCpf[i + 1])
      digitCount++;
  }
  if (digitCount == 10)
    return 0;

  // Checkin last digits test:
  sum = 0;
  for (int i = 0, f = 10; i < 9; i++, f--)
    sum += iCpf[i] * f;
  rem = (10 * sum) % 11;
  if ((iCpf[9] != 0 && sum * 10 % 11 != iCpf[9]) ||
      (iCpf[9] == 0 && sum * 10 % 11 != 10))
    return 0;

  sum = 0;
  for (int i = 0, f = 11; i < 10; i++, f--)
    sum += iCpf[i] * f;
  rem = (10 * sum) % 11;
  if ((iCpf[10] != 0 && sum * 10 % 11 != iCpf[10]) ||
      (iCpf[10] == 0 && sum * 10 % 11 != 10))
    return 0;
  else
    return 1;
}

void removeInvalidCPFs(StrLinkedListNode **head) {
  StrLinkedListNode *temp, *toDelete;
  if (*head != NULL) {
    temp = *head;
    while (temp != NULL) {

      if (isCpfValid(temp->word) == 0) {
        toDelete = temp;
        temp = temp->next;
        deletStrNode(head, toDelete->word);
      } else {
        temp = temp->next;
      }
    }
    free(temp);
  } else
    printf("An empty list was passed\n");
}

int main() {
  char cpf1[] = "78202032008";
  char cpf2[] = "11111111111";
  char cpf3[] = "22222222222";
  char cpf4[] = "79172260009";
  StrLinkedListNode *head = NULL;
  insertStrAtTheEnd(&head, cpf1);
  insertStrAtTheEnd(&head, cpf2);
  insertStrAtTheEnd(&head, cpf3);
  insertStrAtTheEnd(&head, cpf4);
  printf("Before removing invalid CPFs:\n");
  showStrLinkedList(&head);

  removeInvalidCPFs(&head);
  printf("After removing invalid CPFs:\n");
  showStrLinkedList(&head);

    compare_factorials();
    int num_linked_vertices = 5;  // Example number of linked vertices

    struct Vertex *vertex = malloc(sizeof(struct Vertex));
    vertex -> linked_vertices = malloc(num_linked_vertices * sizeof(struct Vertex *));

    free(vertex->linked_vertices);
    free(vertex);

    
  return 0;
}

