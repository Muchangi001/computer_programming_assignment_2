## **Student Performance Tracker**

### **1. Overview**
The **Student Performance Tracker** is a C program designed to manage and evaluate student performance based on test scores from various subjects (units). It gathers information about students, including their test scores across multiple subjects and computes various metrics, such as average scores, grades, and remarks. The program displays this information in a well-formatted output.

### **2. Data Structures Used**

1. **Struct: `Unit`**
   - Holds information about a single subject (unit), including test scores for a predefined number of tests, the total score for all tests, and the average score.

   ```c
   struct Unit {
       char name[MAX_SIZE];            // Name of the unit
       double test_scores[TESTS_COUNT]; // Array to store test scores for each test
       double total_tests_score;        // Total score for all tests
       double score;                    // Average score for the unit
   };
   ```

2. **Struct: `Units`**
   - A container for multiple `Unit` structures. It holds the overall score of all units and the cumulative total score for a student’s subjects.

   ```c
   struct Units {
       double score;              // Overall average score across all units
       double total_units_score;   // Total of all unit scores
       struct Unit units[UNITS_COUNT]; // Array to store individual unit details
   };
   ```

3. **Struct: `Student`**
   - Represents a student. Contains the student's name, score (average of all subjects), grade, and remarks. It also contains an array of units (`Units`). Each student is linked to the next via a pointer, forming a singly linked list.

   ```c
   struct Student {
       char name[MAX_SIZE];          // Student's name
       double score;                 // Student's overall average score
       char grade;                   // Student's grade based on the score
       char remarks[MAX_SIZE];       // Remarks based on grade
       struct Units units;           // Contains unit details
       struct Student *next;         // Pointer to the next student (for linked list)
   };
   ```

4. **Struct: `Classroom`**
   - Acts as a controller for the entire program. It holds the head and tail of the student linked list, the list of unit names, and metadata for the classroom, such as the number of students, subjects, and tests.

   ```c
   struct Classroom {
       struct Student *head;         // Pointer to the first student (start of linked list)
       struct Student *tail;         // Pointer to the last student (end of linked list)
       char units_names[UNITS_COUNT][MAX_SIZE]; // Array to store the names of the units
       unsigned students_count;      // Number of students
       unsigned units_count;         // Number of units
       unsigned tests_count;         // Number of tests per unit
       double average_score;         // Classroom average score
       
       // Method pointers for functionality
       void (*init)();
       void (*greetUser)();
       struct Student* (*newStudent)();
       void (*appendStudent)(struct Student *s);
       void (*promptUnitNames)();
       void (*promptStudentDetails)();
       void (*updateStudentUnitNames)();
       void (*computeStudentDetails)();
       void (*printStudentDetails)();
       void (*freeMemory)();
   };
   ```

### **3. Program Flow**

1. **Initialization (`init`)**
   - Initializes the number of students, units, and tests.

2. **Greeting (`greetUser`)**
   - Displays a welcome message.

3. **Input Unit Names (`promptUnitNames`)**
   - Prompts the user to input the names of the subjects. These names apply to all students.

4. **Input Student Details (`promptStudentDetails`)**
   - For each student, it prompts the user to input the student's name and test scores for each unit.

5. **Creating and Appending Students (`newStudent`, `appendStudent`)**
   - Dynamically allocates memory for a new student and appends the student to the linked list.

6. **Compute Student Details (`computeStudentDetails`)**
   - Calculates the average scores for each unit and overall, assigns grades, and generates remarks based on the performance.

7. **Display Student Details (`printStudentDetails`)**
   - Outputs the student details, including test scores, average scores, grades, and remarks, in a formatted manner.

8. **Memory Management (`freeMemory`)**
   - Frees the memory allocated for each student to avoid memory leaks.

### **4. Grading and Remarks Logic**
The program calculates the average score of each student and assigns a grade based on the following criteria:
- **A (Excellent):** 70% and above
- **B (Good):** 60% to 69.99%
- **C (Average):** 50% to 59.99%
- **D (Pass):** 40% to 49.99%
- **F (Fail):** Below 40%

### **5. Usage Example**

#### **Sample Input:**
```
Enter the units' names:
Unit [1] : Algebra
Unit [2] : Calculus
Unit [3] : Physics

Enter student 1 name: Alice
Algebra test 1 score: 85
Algebra test 2 score: 90
Algebra test 3 score: 88
Calculus test 1 score: 70
Calculus test 2 score: 75
Calculus test 3 score: 80
Physics test 1 score: 60
Physics test 2 score: 65
Physics test 3 score: 70
```

#### **Sample Output:**
```
Alice      Algebra average : 87.67%       Calculus average : 75.00%       Physics average : 65.00%

            Test 1 score    : 85.00%       Test 1 score    : 70.00%       Test 1 score    : 60.00%
            Test 2 score    : 90.00%       Test 2 score    : 75.00%       Test 2 score    : 65.00%
            Test 3 score    : 88.00%       Test 3 score    : 80.00%       Test 3 score    : 70.00%

            TOTAL AVERAGE -> 75.89%        GRADE -> A      REMARKS -> Excellent
```

### **6. Code**
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definitions and Structures (as explained above)

// Function prototypes for Classroom (as explained above)

// Global Classroom instance (as explained above)

// MAIN FUNCTION
int main() {
    classroom.init(); 
    classroom.greetUser(); 
    classroom.promptUnitNames(); 
    classroom.promptStudentDetails(); 
    classroom.updateStudentUnitNames(); 
    classroom.computeStudentDetails(); 
    classroom.printStudentDetails(); 
    classroom.freeMemory();
    return 0;
}

// Implementation of function prototypes (as explained above)
```

---


**EXECUTION SAMPLE**
```
Hello there :)

Enter the units' names (NOTE : WILL APPLY TO EVERY STUDENT)

Unit [1] : Algebra
Unit [2] : Calculus
Unit [3] : Physics    

Enter student 1 name : Muchangi
Algebra test 1 score : 67
Algebra test 2 score : 78
Algebra test 3 score : 73
Calculus test 1 score : 66
Calculus test 2 score : 65
Calculus test 3 score : 80
Physics test 1 score : 78
Physics test 2 score : 81
Physics test 3 score : 72

Enter student 2 name : Einstein
Algebra test 1 score : 66
Algebra test 2 score : 62
Algebra test 3 score : 89
Calculus test 1 score : 89
Calculus test 2 score : 81
Calculus test 3 score : 78
Physics test 1 score : 90
Physics test 2 score : 99
Physics test 3 score : 100

Enter student 3 name : Marshall
Algebra test 1 score : 78
Algebra test 2 score : 67
Algebra test 3 score : 65
Calculus test 1 score : 68
Calculus test 2 score : 78
Calculus test 3 score : 81
Physics test 1 score : 78
Physics test 2 score : 72
Physics test 3 score : 77

Muchangi      Algebra average : 72.67%       Calculus average : 70.33%       Physics average : 77.00%       

            Test 1 score    : 67.00%       Test 1 score    : 66.00%       Test 1 score    : 78.00%       
            Test 2 score    : 78.00%       Test 2 score    : 65.00%       Test 2 score    : 81.00%       
            Test 3 score    : 73.00%       Test 3 score    : 80.00%       Test 3 score    : 72.00%       
            TOTAL AVERAGE -> 73.33%        GRADE -> A      REMARKS -> Excellent


Einstein      Algebra average : 72.33%       Calculus average : 82.67%       Physics average : 96.33%       

            Test 1 score    : 66.00%       Test 1 score    : 89.00%       Test 1 score    : 90.00%       
            Test 2 score    : 62.00%       Test 2 score    : 81.00%       Test 2 score    : 99.00%       
            Test 3 score    : 89.00%       Test 3 score    : 78.00%       Test 3 score    : 100.00%       
            TOTAL AVERAGE -> 83.78%        GRADE -> A      REMARKS -> Excellent


Marshall      Algebra average : 70.00%       Calculus average : 75.67%       Physics average : 75.67%       

            Test 1 score    : 78.00%       Test 1 score    : 68.00%       Test 1 score    : 78.00%       
            Test 2 score    : 67.00%       Test 2 score    : 78.00%       Test 2 score    : 72.00%       
            Test 3 score    : 65.00%       Test 3 score    : 81.00%       Test 3 score    : 77.00%       
            TOTAL AVERAGE -> 73.78%        GRADE -> A      REMARKS -> Excellent

```

**SOURCE CODE**
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TESTS_COUNT 3
#define UNITS_COUNT 3
#define STUDENTS_COUNT 3
#define MAX_SIZE 128

// Unit structure to store details of a single unit
struct Unit {
    char name[MAX_SIZE]; // unit name
    double test_scores[TESTS_COUNT]; // to store the score of each test
    double total_tests_score;
    double score; // to store the average score of tests / unit score
};

// Units structure to store units' details
struct Units {
    double score; // to store the average score of units
    double total_units_score;
    struct Unit units[UNITS_COUNT];
};

// Student struct for storing student details
struct Student {
    char name[MAX_SIZE];
    double score; // to store the average score for units
    char grade; 
    char remarks[MAX_SIZE];
    struct Units units; // to store student's units
    struct Student *next; // to store reference to the next adjacent student
};

// Singly linked list for students
struct Classroom {
    struct Student *head;
    struct Student *tail;
    
    char units_names[UNITS_COUNT][MAX_SIZE];

    unsigned students_count;
    unsigned units_count;
    unsigned tests_count;
    double average_score;

    // methods
    void (*init) ();
    void (*greetUser) ();
    struct Student * (*newStudent) (); // to create a student node
    void (*appendStudent) (struct Student *s);
    void (*promptUnitNames)();
    void (*promptStudentDetails)();
    void (*updateStudentUnitNames)();
    void (*computeStudentDetails)();
    void (*printStudentDetails)();
    void (*freeMemory) ();
};

// Function prototypes for Classroom
void init();
void greetUser();
struct Student * newStudent();
void appendStudent(struct Student *s);
void promptUnitNames();
void promptStudentDetails();
void updateStudentUnitNames();
void computeStudentDetails();
void printStudentDetails();
void freeMemory();

// Global Classroom instance
struct Classroom classroom = {
    .head = NULL,
    .tail = NULL,
    .init = &init,
    .greetUser = &greetUser,
    .newStudent = &newStudent,
    .appendStudent = &appendStudent,
    .promptUnitNames = &promptUnitNames,
    .promptStudentDetails = &promptStudentDetails,
    .updateStudentUnitNames = &updateStudentUnitNames,
    .computeStudentDetails = &computeStudentDetails,
    .printStudentDetails = &printStudentDetails,
    .freeMemory = &freeMemory,
};

// MAIN FUNCTION (where execution begins)
int main() {

    classroom.init(); // Initializing class (student_count, units_count, tests_count)
    classroom.greetUser(); // Just greet the user :)
    classroom.promptUnitNames(); // Prompts the user to enter unit names
    classroom.promptStudentDetails(); // Prompts the user to enter student details (name and scores for each test per unit)
    classroom.updateStudentUnitNames(); // Makes sure the students have the same units
    classroom.computeStudentDetails(); // Computes student details such as average scores
    classroom.printStudentDetails(); // Prints the Students' details to stdout
    classroom.freeMemory(); // Frees all memory allocated on the heap

    return 0;
}

// Implementation for the function prototypes
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
        printf("Unit [%zu] : ", i + 1); // Prompt user to enter test name
        fgets(classroom.units_names[i], sizeof(classroom.units_names[i]), stdin); // Reading input
        classroom.units_names[i][strcspn(classroom.units_names[i], "\n")] = '\0'; // Removing newline character inserted by fgets()
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

void updateStudentUnitNames() {
    // Update students' details to have same units
    struct Student *curr = classroom.head;
    size_t i = 0;
    while (curr) {
        for (size_t i = 0; i < classroom.units_count; ++i) {
            strcpy(curr->units.units[i].name, classroom.units_names[i]);
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
        printf("%s      ", curr->name); // Print name
        for (size_t i = 0; i < classroom.units_count; ++i) {
            printf("%s average : %.2lf%%       ", curr->units.units[i].name, curr->units.units[i].score);
        }
        printf("\n\n");
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
```