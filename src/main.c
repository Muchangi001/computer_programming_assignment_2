#include "../include/classroom.h"

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
