#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from source %c to target %c\n", source, target);
        return;
    }
    tower_of_hanoi(n-1, source, target, auxiliary);
    printf("Move disk %d from source %c to target %c\n", n, source, target);
    tower_of_hanoi(n-1, auxiliary, source, target);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}
