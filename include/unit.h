#ifndef UNIT_H
#define UNIT_H

#include "limits.h"

struct Unit {
    char name[MAX_SIZE]; // unit name
    char code[MAX_SIZE]; // unit code
    double test_scores[TESTS_COUNT]; // to store the score of each test
    double total_tests_score;
    double score; // to store the average score of tests / unit score
};

#endif