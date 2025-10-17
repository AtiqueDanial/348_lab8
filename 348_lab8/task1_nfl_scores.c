#include <stdio.h>

static void list_combinations(int score) {
    int found = 0;

    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    // Let a=TD+2pt (8), b=TD+FG (7), c=TD (6), d=FG (3), e=Safety (2)
    for (int a = 0; a <= score / 8; ++a) {
        int remain_a = score - 8 * a;
        for (int b = 0; b <= remain_a / 7; ++b) {
            int remain_b = remain_a - 7 * b;
            for (int c = 0; c <= remain_b / 6; ++c) {
                int remain_c = remain_b - 6 * c;
                for (int d = 0; d <= remain_c / 3; ++d) {
                    int remain_d = remain_c - 3 * d;
                    // last piece must be made of safeties (2 pts)
                    if (remain_d % 2 != 0) continue;
                    int e = remain_d / 2;

                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                           a, b, c, d, e);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No combinations possible.\n");
    }
}

int main(void) {
    while (1) {
        int score;
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            // Clear bad input and keep going
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            puts("Invalid input. Please enter an integer.");
            continue;
        }

        if (score == 1) {
            break;
        }
        if (score < 0) {
            puts("Invalid score: score cannot be negative.");
            continue;
        }
        if (score == 0) {
            // Score of 0 is valid: no scoring plays
            puts("Possible combinations of scoring plays if a team's score is 0:");
            puts("0 TD + 2pt, 0 TD + FG, 0 TD, 0 3pt FG, 0 Safety");
            continue;
        }
        list_combinations(score);
    }
    return 0;
}
