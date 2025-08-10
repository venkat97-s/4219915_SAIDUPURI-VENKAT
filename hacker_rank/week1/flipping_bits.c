#include <stdio.h>
#include <stdint.h>
uint32_t flippingBits(uint32_t n) {
    return ~n; // operation not
}

int main() {
    int q;
    scanf("%d", &q); 

    for (int i = 0; i < q; i++) {
        uint32_t num;
        scanf("%u", &num);
        printf("%u\n", flippingBits(num));
    }

    return 0;
}
