#ifndef STUDENT_H
#define STUDENT_H

#include "units.h"

struct Student {
    char name[MAX_SIZE];
    double score; // to store the average score for units
    char grade; 
    char remarks[MAX_SIZE];
    struct Units units; // to store student's units
    struct Student *next; // to store reference to the next adjacent student
};

#endif