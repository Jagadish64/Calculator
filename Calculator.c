#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

#ifndef PI
#define PI 3.14159265358979323846
#endif

double lastResult = 0.0; // Global memory for last result // Always Store the most current result

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

void pause(void)
{
    printf("Press Enter to continue...");
    clearInputBuffer();
}

void menu(void)
{
    printf("=========================\n");
    printf("=== Modern Calculator ===\n");
    printf("=========================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Percentage (Modulus)\n");
    printf("6. Power\n");
    printf("7. Square Root\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");
    printf("11. Recall Last Result\n");
    printf("12. Add to Last Result\n");
    printf("13. Subtract from Last Result\n");
    printf("14. Multiply Last Result\n");
    printf("15. Divide Last Result\n");
    printf("16. Clear Memory\n");
    printf("0. Exit\n");
    printf("=========================\n");
}

int main(void)
{
    int choice;
    double num1, num2, result;

    while (1) {
        system("cls"); // Use "clear" on Linux/macOS if needed
        menu();
        printf("Choose an option:\n");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice!\n");
            clearInputBuffer();
            pause();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                lastResult = result;
                getchar();
                break;

            case 2:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                lastResult = result;
                getchar();
                break;

            case 3:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                lastResult = result;
                getchar();
                break;

            case 4:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (num2 == 0.0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                    lastResult = result;
                }
                getchar();
                break;

            case 5: {
                int int1, int2;
                printf("Enter two integers: ");
                if (scanf("%d %d", &int1, &int2) != 2) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (int2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    printf("Remainder: %d\n", int1 % int2);
                    result = ((double)int1 / (double)int2) * 100.0;
                    printf("Result: %.2lf%%\n", result);
                    lastResult = result;
                }
                getchar();
                break;
            }

            case 6:
                printf("Enter base and exponent: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (num1 == 0.0 && num2 < 0.0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = pow(num1, num2);
                    if (isinf(result)) {
                        printf("Error: Result is infinity.\n");
                    } else if (isnan(result)) {
                        printf("Error: Result is not a number.\n");
                    } else {
                        printf("Result: %.6lf\n", result);
                        lastResult = result;
                    }
                }
                getchar();
                break;

            case 7:
                printf("Enter a number: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (num1 < 0.0) {
                    printf("Error: Cannot compute square root of a negative number.\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.2lf\n", result);
                    lastResult = result;
                }
                getchar();
                break;

            case 8:
                printf("Enter angle in degrees: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                result = sin(num1 * PI / 180.0);
                printf("Result: %.4lf\n", result);
                lastResult = result;
                getchar();
                break;

            case 9:
                printf("Enter angle in degrees: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                result = cos(num1 * PI / 180.0);
                printf("Result: %.4lf\n", result);
                lastResult = result;
                getchar();
                break;

            case 10: {
                double angle;
                printf("Enter angle in degrees: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                angle = fmod(num1, 180.0);
                if (angle < 0.0) {
                    angle += 180.0;
                }
                if (fabs(angle - 90.0) < 1e-9) {
                    printf("Result: Undefined (tan of %.2lf degrees)\n", num1);
                } else {
                    result = tan(num1 * PI / 180.0);
                    printf("Result: %.4lf\n", result);
                    lastResult = result;
                }
                getchar();
                break;
            }

            case 11:
                printf("Memory Recall:\nlastResult = %.2lf\n", lastResult);
                getchar();
                break;

            case 12:
                printf("lastResult = %.2lf\n", lastResult);
                printf("Enter a number to add: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                lastResult += num1;
                printf("Updated Result: %.2lf\n", lastResult);
                getchar();
                break;

            case 13:
                printf("lastResult = %.2lf\n", lastResult);
                printf("Enter a number to subtract: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                lastResult -= num1;
                printf("Updated Result: %.2lf\n", lastResult);
                getchar();
                break;

            case 14:
                printf("lastResult = %.2lf\n", lastResult);
                printf("Enter a number to multiply: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                lastResult *= num1;
                printf("Updated Result: %.2lf\n", lastResult);
                getchar();
                break;

            case 15:
                printf("lastResult = %.2lf\n", lastResult);
                printf("Enter a number to divide: ");
                if (scanf("%lf", &num1) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                if (num1 == 0.0) {
                    printf("Error: Division by zero!\n");
                } else {
                    lastResult /= num1;
                    printf("Updated Result: %.2lf\n", lastResult);
                }
                getchar();
                break;

            case 16:
                lastResult = 0.0;
                printf("lastResult reset: 0.00\n");
                getchar();
                break;

            case 0:
                printf("Exiting calculator. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        clearInputBuffer();
        pause();
    }

    return 0;
}

