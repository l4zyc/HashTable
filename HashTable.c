#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data Data;

struct Data {
    int val;
    char name[100];
    Data *next, *prev;
}; Data* Table[26];

Data* newData(char name[], int val) {
    Data* data = (Data*) malloc(sizeof(Data));
    strcpy(data->name, name);
    data->val = val;
    return data;
}

int getKey(char name[]) {
    int sum;
    int len = strlen(name);
    for(int i = 0; i < len; i++) {
        sum += name[i];
    }
    return sum % 26;
}

void insertData(char name[], int val) {
    int key = getKey(name);
    if(Table[key] == NULL) {
        Table[key] = newData(name, val); 
        return;
    }
    Data* temp = Table[key];
    while(temp->next != NULL) temp = temp->next;
    temp->next = newData(name, val);
}

void update(int val) {
    for(int i = 0; i < 26; i++) {
        Data* temp = Table[i]->next;
        while(temp != NULL) {
            if(temp->val == val) {
                scanf("Enter new Value: %d", &temp->val); getchar();
                scanf("Enter new Name: %s", temp->name); getchar();
                printf("Successful");
                return;
            }
            temp = temp->next;
        }
    }
}

void printTable() {
    for(int i = 0; i < 26; i++) {
        if(Table[i] != NULL) {
            printf("%s %d\n", Table[i]->name, Table[i]->val);
            Data* temp = Table[i]->next;
            while(temp != NULL) {
                printf(" -> %s %d\n", temp->name, temp->val);
                temp = temp->next;
            }
        } else {
            printf("NULL\n");
        }
    }
}   

int main() {
    insertData("Glenn", 1);
    insertData("Glenm", 2);
    insertData("Kei", 2);

    printTable();

    return 0;
}