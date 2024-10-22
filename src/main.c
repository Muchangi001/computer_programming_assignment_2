#include "../include/class.h"

int main() {

    classroom.init(); // Initializing class (student_count, units_count, tests_count)

    // Prompt the user to enter the names of units
    printf("Enter the units' names (NOTE : WILL APPLY TO EVERY STUDENT)\n");
    for (size_t i = 0; i < classroom.units_count; ++i) {
        printf("Unit [%zu] : ", i + 1); // Prompt user to enter test name
        fgets(classroom.units_names[i], sizeof(classroom.units_names[i]), stdin); // Reading input
        classroom.units_names[i][strcspn(classroom.units_names[i], "\n")] = '\0'; // Removing newline character inserted by fgets()
    }
    
    // Prompting user for student details
    for (size_t i = 0; i < classroom.students_count; ++i) {
        struct Student *s = classroom.newStudent();
        printf("\n\nEnter student %zu name : ", i + 1); // Prompt the user to enter student name
        fgets(s->name, sizeof(s->name), stdin);

        // Handles the units per student
        for (size_t j = 0; j < classroom.units_count; ++j) {
            // Handles the tests per unit
            for (size_t k = 0; k < classroom.tests_count; ++k) {
                printf("%s score %zu : ", classroom.units_names[j], k + 1);
                scanf("%lf", s->units.units[j].test_scores[k]);

                while (getchar() != '\n'); // Clear input buffer
            }
        }
        classroom.appendStudent(s);
    }

    // Update students' details to have same units
    struct Student *curr = classroom.head;
    size_t i = 0;
    while (curr) {
        for (size_t i = 0; i < classroom.units_count; ++i) {
            strcpy(curr->units.units[i].name, classroom.units_names[i]);
        }
        curr = curr->next;
    }

    // COMPUTATIONS
    curr = classroom.head;
    while (curr) {
        for (size_t i = 0; i < classroom.units_count; ++i) {
            for (size_t j = 0; j < classroom.tests_count; ++j) {
                curr->units.units[i].total_tests_score += curr->units.units[i].test_scores[j]; // Compute the total sum for individual tests
            }
            curr->units.units[i].score = curr->units.units[i].total_tests_score / classroom.tests_count; // Compute the average test score and set it to unit score
            curr->units.total_units_score += curr->units.units[i].score; // Compute the total sum of individual units
        }
        curr->units.score = curr->units.total_units_score / classroom.units_count; // Compute the average unit score and set it to students score
        curr->score = curr->units.score; // Update the student score to match the average score for all units
        curr = curr->next;
    }
    

    // Printing students' details
    curr = classroom.head;
    while (curr) {
        printf("%s  ", curr->name); // Print name
        for (size_t i = 0; i < classroom.units_count; ++i) {
            printf("[%s -> %u]", curr->units.units[i], curr->units.units[i].score);
            for (size_t j = 0; j < classroom.tests_count; ++j) {
                // display tests logic
            }
        }
        printf("\n");
        curr = curr->next;
    }

    classroom.freeMemory();

    return 0;
}