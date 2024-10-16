#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Check if the user passed any arguments to the program
    if (argc < 3) {
        fprintf(stderr, "Failed to run the program.\nMake sure to include the student_count and test_count when calling the program.\ne.g. './main 3 2' -> 3 students each with 2 tests.\n");
        exit(EXIT_FAILURE);
    }

    // Create student_count variable to hold the number of students in the class
    int student_count = atoi(argv[1]);

    // Create a test_count variable to hold the numbers of tests for each student
    int test_count = atoi(argv[2]);

    // Create students_names variable to store the name of students
    char students_names[10][128];

    // Create test_names variable to store the tests' names
    char test_names[10][2][128];

    // Create test_scores variable to store the tests' scores
    double test_scores[10][2];

    // Create total_average variable to store the class' average
    double total_average;

    // Greet the user
    printf("\nHello there :)\n");
    
    // Prompt user to enter students' details
    for (int i = 0; i < student_count; ++i) {
        for (int j = 0; j < test_count; ++j) {
            if (j == 0) {
            // Prompt the user to enter students names
            printf("\nEnter student %d name : ", i + 1);
            char student_name[128];
            fgets(student_name, sizeof(student_name), stdin);
            strcpy(students_names[i], student_name);
            students_names[i][strcspn(students_names[i], "\n")] = '\0';
            }

        // Prompt user to enter test names
        printf("Test [%d] : ", j + 1);
        char test_name[128];
        fgets(test_name, sizeof(test_name), stdin);
        strncpy(test_names[i][j], test_name, strlen(test_name));
        test_names[i][j][strcspn(test_names[i][j], "\n")] = '\0';

        // Prompt the user to enter test score
        printf("%s score : ", test_names[i][j]);
        scanf(" %lf", &test_scores[i][j]);

        // Clear input buffer
        while (getchar() != '\n');
        }
    }
    

    // Print students details
    printf("\nSTUDENT DETAILS...");
    for (int i = 0; i < student_count; ++i) {
        double sum = 0;
        for (int j = 0; j < test_count; ++j) {
            if (j == 0) {
                printf("\n%s    ", students_names[i]);
            }
            printf("  [%s -> ", test_names[i][j]);
            printf("%.2lf%%]", test_scores[i][j]);
            sum += test_scores[i][j];
        }
        printf("  [Average -> %.2lf%%]",  sum/2);
        total_average += sum/2;
    }
    printf("\n");

    // Print the total class average
    printf("\nTOTAL CLASS AVERAGE => %.2lf%%\n\n", total_average / student_count);
}