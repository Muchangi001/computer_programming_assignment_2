#ifndef CLASS_H
#define CLASS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

// Singly linked list for students
struct Classroom {
    struct Student *head;
    struct Student *tail;
    
    char units_names[UNITS_COUNT][MAX_NAME_SIZE];

    unsigned students_count;
    unsigned units_count;
    unsigned tests_count;
    double average_score;

    // methods
    void (*init) ();
    struct Student * (*newStudent) (); // to create a student node
    void (*appendStudent) (struct Student *s);
    void (*freeMemory) ();
};

extern struct Classroom classroom;

#endif