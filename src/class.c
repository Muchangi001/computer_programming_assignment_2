#include "../include/class.h"

void init();
struct Student * newStudent();
void appendStudent(struct Student *s);
void freeMemory();

struct Classroom classroom = {
    .head = NULL,
    .tail = NULL,
    .init = &init,
    .newStudent = &newStudent,
    .appendStudent = &appendStudent,
    .freeMemory = &freeMemory,
};

void init() {
    classroom.students_count = STUDENTS_COUNT;
    classroom.units_count = UNITS_COUNT;
    classroom.tests_count = TESTS_COUNT;
}

struct Student * newStudent() {
    return malloc(sizeof(struct Student)); // allocate memory for a new student node
}

void appendStudent(struct Student *s) {
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