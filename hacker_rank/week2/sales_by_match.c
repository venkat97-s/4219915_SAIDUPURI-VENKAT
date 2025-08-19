#include <stdio.h>

int countPairs(int n, int socks[]) {
    int pairs = 0;
    int visited[101] = {0};  

    for (int i = 0; i < n; i++) {
        int color = socks[i];
        visited[color]++;

        
        if (visited[color] == 2) {
            pairs++;
            visited[color] = 0; 
        }
    }
    return pairs;
}

int main() {
    int n;
    scanf("%d", &n);

    int socks[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &socks[i]);
    }

    printf("%d\n", countPairs(n, socks));
    return 0;
}
