#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linked list.
int length(node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Parses the string in the linked list and returns it.
char* toCString(node* head) {
    int len = length(head);
    char* str = (char*)malloc(sizeof(char) * (len + 1));
    char* ptr = str;

    while (head != NULL) {
        *ptr++ = head->letter;
        head = head->next;
    }
    *ptr = '\0';
    return str;
}

// Inserts a character at the end of the linked list.
void insertChar(node** pHead, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
    }
    else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Deletes all nodes in the linked list.
void deleteList(node** pHead) {
    node* current = *pHead;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}

int main(void) {
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, " %d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is : %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }

    fclose(inFile);
}