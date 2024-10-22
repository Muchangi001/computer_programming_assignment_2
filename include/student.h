#ifndef STUDENT_H
#define STUDENT_H

#include "units.h"

struct Student {
    char name[MAX_NAME_SIZE];
    double score; // to store the average score for units
    struct Units units; // to store student's units
    struct Student *next; // to store reference to the next adjacent student
};

#endif