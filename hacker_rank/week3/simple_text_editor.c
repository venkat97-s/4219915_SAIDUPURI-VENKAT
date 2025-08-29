#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000000


typedef struct Operation {
    int type;           // 1 = append, 2 = delete
    char *data;         // data appended or deleted
} Operation;

Operation stack[100000]; // stack to store history
int top = -1;

// Push operation onto stack
void push(int type, const char *data) {
    top++;
    stack[top].type = type;
    stack[top].data = strdup(data); // copy string
}

// Pop operation from stack
Operation pop() {
    return stack[top--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAXLEN+1] = "";  // text string (initially empty)

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {  // append
            char W[MAXLEN+1];
            scanf("%s", W);
            strcat(S, W);
            push(1, W); // store appended string
        }
        else if (type == 2) {  // delete
            int k;
            scanf("%d", &k);
            int len = strlen(S);
            char deleted[MAXLEN+1];
            strcpy(deleted, S + len - k);  // save deleted substring
            S[len - k] = '\0';            
            push(2, deleted);
        }
        else if (type == 3) {  // print
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        }
        else if (type == 4) {  // undo
            Operation last = pop();
            if (last.type == 1) {  // undo append
                int len = strlen(S);
                int removeLen = strlen(last.data);
                S[len - removeLen] = '\0';
            }
            else if (last.type == 2) {  // undo delete
                strcat(S, last.data);
            }
            free(last.data); // cleanup
        }
    }

    return 0;
}