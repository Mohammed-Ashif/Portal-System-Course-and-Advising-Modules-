#ifndef ADVISING_H
#include "utils.h"
#include "course.h"
#define MAX_COURSE_ADVISING 4

typedef struct StudentAdvising
{
    int courseCount;
    Node* advisedCourses;
} StudentAdvising;

void advisingCourse(Node** head, Course* course);
void displayAdvisedCourses(Node* head);
void dropCourse(Node** head, const char* code);

#endif // ADVISING_H
