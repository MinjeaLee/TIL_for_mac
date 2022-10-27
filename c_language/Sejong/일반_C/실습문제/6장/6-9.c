#include <stdio.h>

int main() {
    int num, result = 0, pow, i, j, check_num, len, check_len;
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        pow = 1;
        len = 0;
        check_len = i;
        do {     // i len check
            check_len = check_len / 10;
            len++;
        } while (check_len != 0);

        for (j = 0; j < len; j++) {  // i num check, pow**
            check_num = i / pow % 10;
            pow *= 10;
            if (check_num == 3) {
                result++;
            }
        }
    }
    printf("%d", result);

    return 0;
}
