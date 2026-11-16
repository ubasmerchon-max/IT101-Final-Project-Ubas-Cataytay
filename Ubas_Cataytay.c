#include <stdio.h>
int main() {
    int choice, size, shape, rows, i, j, spaces, stars;
    int level, length, palindrome, ch;
    long long number;
    float grade, total, average;
    char again = 'Y';
    char word[100], names[4][12] = {"Prelim", "Midterm", "Pre-Final", "Final"};

    while (again == 'Y' || again == 'y') {
        printf("\n=== MAIN MENU ===\n");
        printf("1. Pattern Generator\n2. Pascal's Triangle\n3. Grade Calculator\n4. Palindrome Checker\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n=== PATTERN GENERATOR ===\nEnter size: ");
                scanf("%d", &size);

                if (size < 1) {
                    printf("Invalid size!\n");
                    break;
                }

                printf("1. Right Triangle\n2. Square\n3. Isosceles Triangle\n4. Inverted Triangle\n5. Christmas Tree\nChoice: ");
                scanf("%d", &shape);

                if (shape < 1 || shape > 5) {
                    printf("Invalid shape!\n");
                    break;
                }

                rows = size;
                if (shape == 5) rows = 2 * size + 1;

                for (i = 1; i <= rows; i++) {
                    spaces = 0;
                    stars = size;

                    if (shape == 1) stars = i;
                    else if (shape == 3) {
                        spaces = size - i;
                        stars = 2 * i - 1;
                    }
                    else if (shape == 4) stars = size - i + 1;
                    else if (shape == 5) {
                        if (i < 2 * size) {
                            if (i <= size) level = i;
                            else level = i - size + 1;

                            spaces = size - level;
                            stars = 2 * level - 1;
                        }
                        else {
                            spaces = size - 1;
                            stars = 1;
                        }
                    }

                    for (j = 0; j < spaces; j++) printf("  ");
                    for (j = 0; j < stars; j++) printf("* ");
                    printf("\n");
                }
                break;

            case 2:
                printf("\n=== PASCAL'S TRIANGLE ===\nEnter rows (1-20): ");
                scanf("%d", &rows);

                if (rows < 1 || rows > 20) {
                    printf("Invalid rows!\n");
                    break;
                }

                for (i = 0; i < rows; i++) {
                    for (j = 0; j < rows - i; j++) printf("  ");

                    number = 1;

                    for (j = 0; j <= i; j++) {
                        printf("%4lld", number);
                        number = number * (i - j) / (j + 1);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("\n=== GRADE CALCULATOR ===\n");
                total = 0;

                for (i = 0; i < 4; i++) {
                    do {
                        printf("Enter %s grade: ", names[i]);
                        scanf("%f", &grade);

                        if (grade < 1.0 || grade > 5.0)
                            printf("Invalid grade! Try again.\n");

                    } while (grade < 1.0 || grade > 5.0);

                    total += grade;
                }

                average = total / 4;

                printf("\nAverage: %.2f\n", average);

                if (average <= 3.0)
                    printf("Status: PASSED\n");
                else
                    printf("Status: FAILED\n");
                break;

            case 4:
                printf("\n=== PALINDROME CHECKER ===\nEnter a word: ");
                scanf("%99s", word);

                length = 0;
                while (word[length] != '\0') length++;

                palindrome = 1;

                for (i = 0; i < length / 2; i++) {
                    if (word[i] != word[length - 1 - i])
                        palindrome = 0;
                }

                if (palindrome == 1)
                    printf("%s is a PALINDROME.\n", word);
                else
                    printf("%s is NOT a palindrome.\n", word);
                break;

            case 5:
                printf("Thank you for using the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }

        while ((ch = getchar()) != '\n' && ch != EOF) { }

        do {
            printf("\nDo you want to try another operation? (Y/N): ");
            scanf(" %c", &again);

            if (again != 'Y' && again != 'y' &&
                again != 'N' && again != 'n')
                printf("Please enter Y or N.\n");

        } while (again != 'Y' && again != 'y' &&
                 again != 'N' && again != 'n');

        if (again == 'Y' || again == 'y')
            printf("\n====================================\n");
    }

    printf("\nProgram ended. Have a great day!\n");
    return 0;
}