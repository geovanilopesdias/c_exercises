#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// INTEGER LINKED LIST

typedef struct iNode {
  int value;
  struct iNode *next;
} IntLinkedListNode;

void insertAtTheStart(IntLinkedListNode **head, int value) {
  IntLinkedListNode *newNode = NULL;
  newNode = (IntLinkedListNode *)malloc(sizeof(IntLinkedListNode));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
  } else
    printf(
        "Allocation failed for start/left insertion in Integer Linked List.");
}

void insertIntAtTheEnd(IntLinkedListNode **head, int value) {
  IntLinkedListNode *newNode = NULL;
  newNode = (IntLinkedListNode *)malloc(sizeof(IntLinkedListNode));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->next = NULL;
    if (*head == NULL) {
      *head = newNode;
    } else {
      IntLinkedListNode *temp = *head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
}

void deleteIntNode(IntLinkedListNode **head, int value) {
  IntLinkedListNode *temp = *head;
  IntLinkedListNode *prev = NULL;
  if (temp != NULL && temp->value == value) {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->value != value) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Node not found in Integer Linked List.");
  } else {
    prev->next = temp->next;
    free(temp);
  }
}

void showIntLinkedList(IntLinkedListNode **head) {
  IntLinkedListNode *node;
  if (*head != NULL) {
    node = *head;
    while (node->next != NULL) {
      printf("%d | ", node->value);
      node = node->next;
    }
    printf("%d\n", node->value);
  }

  else
    printf("An empty list was passed\n");
}

// STRING LINKED LIST
typedef struct strNode {
  char *word;
  struct strNode *next;
} StrLinkedListNode;

void insertStrAtTheEnd(StrLinkedListNode **head, char *new_word) {
  StrLinkedListNode *newNode = NULL;
  newNode = (StrLinkedListNode *)malloc(sizeof(StrLinkedListNode));
  if (newNode != NULL) {
    newNode->word = new_word;
    newNode->next = NULL;
    if (*head == NULL) {
      *head = newNode;
    } else {
      StrLinkedListNode *temp = *head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  } else
    free(newNode);
}

void deletStrNode(StrLinkedListNode **head, char *exclusion) {
  StrLinkedListNode *temp = *head;
  StrLinkedListNode *prev = NULL;
  if (temp != NULL && strcmp(temp->word, exclusion) == 0) {
    *head = temp->next;
    free(temp);
    temp = *head;
  }
  while (temp != NULL && strcmp(temp->word, exclusion) != 0) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Node not found in String Linked List.");
  }
  prev->next = temp->next;
  free(temp);
}

void showStrLinkedList(StrLinkedListNode **head) {
  StrLinkedListNode *node;
  if (*head != NULL) {
    node = *head;
    while (node->next != NULL) {
      printf("%s | ", node->word);
      node = node->next;
    }
    printf("%s\n", node->word);

  } else
    printf("An empty list was passed\n");
}
