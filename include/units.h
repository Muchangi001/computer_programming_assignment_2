#ifndef UNITS_H
#define UNITS_H

#include "unit.h"

struct Units {
    double score; // to store the average score of units
    double total_units_score;
    struct Unit units[UNITS_COUNT];
};

#endif