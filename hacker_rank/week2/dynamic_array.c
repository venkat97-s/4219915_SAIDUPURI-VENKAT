#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int used;
    int space;
} DynArray;

// add new number into chosen dynamic array
void push(DynArray *seq, int num) {
    if (seq->used == seq->space) {
        int newSize = (seq->space == 0) ? 2 : seq->space * 2;
        seq->arr = realloc(seq->arr, newSize * sizeof(int));
        seq->space = newSize;
    }
    seq->arr[seq->used++] = num;
}

int main() {
    int nSeq, nOps;
    scanf("%d %d", &nSeq, &nOps);

    DynArray *lists = calloc(nSeq, sizeof(DynArray));
    int last = 0;

    for (int i = 0; i < nOps; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ last) % nSeq;

        if (type == 1) {
            push(&lists[idx], y);
        } else if (type == 2) {
            int pos = y % lists[idx].used;
            last = lists[idx].arr[pos];
            printf("%d\n", last);
        }
    }

    // cleanup
    for (int i = 0; i < nSeq; i++) {
        free(lists[i].arr);
    }
    free(lists);

    return 0;
}
