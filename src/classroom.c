#include "../include/classroom.h"

void init();
void greetUser();
struct Student * newStudent();
void appendStudent(struct Student *s);
void promptUnitNames();
void promptStudentDetails();
void updateStudentUnits();
void computeStudentDetails();
void printStudentDetails();
void freeMemory();

struct Classroom classroom = {
    .head = NULL,
    .tail = NULL,
    .init = &init,
    .greetUser = &greetUser,
    .newStudent = &newStudent,
    .appendStudent = &appendStudent,
    .promptUnitNames = &promptUnitNames,
    .promptStudentDetails = &promptStudentDetails,
    .updateStudentUnits = &updateStudentUnits,
    .computeStudentDetails = &computeStudentDetails,
    .printStudentDetails = &printStudentDetails,
    .freeMemory = &freeMemory,
};

void init() {
    classroom.students_count = STUDENTS_COUNT;
    classroom.units_count = UNITS_COUNT;
    classroom.tests_count = TESTS_COUNT;
}

void greetUser() {
    printf("\nHello there :)\n\n");
}

void promptUnitNames() {
    // Prompt the user to enter the names of units
    printf("Enter the units' names (NOTE : WILL APPLY TO EVERY STUDENT)\n\n");
    for (size_t i = 0; i < classroom.units_count; ++i) {
        printf("Unit [%zu] : ", i + 1); // Prompt user to enter unit name
        fgets(classroom.units_names[i], sizeof(classroom.units_names[i]), stdin); // Reading input
        classroom.units_names[i][strcspn(classroom.units_names[i], "\n")] = '\0'; // Removing newline character inserted by fgets()

        printf("%s unit code : ", classroom.units_names[i]); // Prompt user to enter unit code
        fgets(classroom.units_code[i], sizeof(classroom.units_code[i]), stdin);
        classroom.units_code[i][strcspn(classroom.units_names[i], "\n")] = '\0';
    }
}

void promptStudentDetails() {
    // Prompting user for student details
    for (size_t i = 0; i < classroom.students_count; ++i) {
        struct Student *s = classroom.newStudent();
        printf("\nEnter student %zu name : ", i + 1); // Prompt the user to enter student name
        fgets(s->name, sizeof(s->name), stdin);
        s->name[strcspn(s->name, "\n")] = '\0';

        // Handles the units per student
        for (size_t j = 0; j < classroom.units_count; ++j) {
            // Handles the tests per unit
            for (size_t k = 0; k < classroom.tests_count; ++k) {
                printf("%s test %zu score : ", classroom.units_names[j], k + 1);
                scanf(" %lf", &s->units.units[j].test_scores[k]);
                while (getchar() != '\n'); // Clear input buffer
            }
        }
        classroom.appendStudent(s);
    }
}

struct Student * newStudent() {
    return malloc(sizeof(struct Student)); // allocate memory for a new student node
}

void updateStudentUnits() {
    // Update students' details to have same units
    struct Student *curr = classroom.head;
    size_t i = 0;
    while (curr) {
        for (size_t i = 0; i < classroom.units_count; ++i) {
            strcpy(curr->units.units[i].name, classroom.units_names[i]);
            strcpy(curr->units.units[i].code, classroom.units_code[i]);
        }
        curr = curr->next;
    }
}

void appendStudent(struct Student *s) {
    s->next = NULL;
    if (classroom.head == classroom.tail && !classroom.tail) {
        classroom.head = classroom.tail = s;
        return;
    }

    if (classroom.head == classroom.tail) {
        classroom.tail = s;
        classroom.head->next = classroom.tail;
        return;
    }

    classroom.tail->next = s;
    classroom.tail = s;
}

void computeStudentDetails() {
    // COMPUTATIONS
    struct Student *curr = classroom.head;
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
        curr->grade = curr->score >= 70 ? 'A' : curr->score >= 60 ? 'B' : curr->score >= 50 ? 'C' : curr->score >= 40 ? 'D' : 'F'; // Compute the grade of the student based on the student's score
        strcpy(curr->remarks, curr->grade == 'A' ? "Excellent" : curr->grade == 'B' ? "Good" : curr->grade == 'C' ? "Average" : curr->grade == 'D' ? "Pass" : "Fail");
        curr = curr->next;
    }
}

void printStudentDetails() {
    // Printing students' details
    printf("\n\nSTUDENT DETAILS...\n");
    struct Student *curr = classroom.head;
    while (curr) {
        printf("\n");
        printf("%s      ", curr->name); // Print student name
        for (size_t i = 0; i < classroom.units_count; ++i) {
            printf("%s [%s] average : %.2lf%%       \n\n", curr->units.units[i].name, curr->units.units[i].code, curr->units.units[i].score);
        }

        for (size_t i = 0; i < classroom.units_count; ++i) {
            printf("            ");
            for (size_t j = 0; j < classroom.tests_count; ++j) {
                printf("Test %zu score    : %.2lf%%       ", i + 1, curr->units.units[j].test_scores[i]);
            }
            printf("\n");
        }
        printf("            ");
        printf("TOTAL AVERAGE -> %.2lf%%        GRADE -> %c      REMARKS -> %s\n",curr->score, curr->grade, curr->remarks);
        printf("\n");
        curr = curr->next;
    }
}

void freeMemory() {
    struct Student *curr = classroom.head;

    // deallocate memory from the heap
    while (curr) {
        struct Student *temp = curr->next;
        free(curr);
        curr = temp;
    }
    classroom.head = classroom.tail = NULL; // to avoid dangling pointers
}