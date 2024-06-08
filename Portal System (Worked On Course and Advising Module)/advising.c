#include "advising.h"

void advisingCourse(Node** head, Course* course)
{
    addCourse(head, course);
    printf("Course Advising was successful.\n");
}

void displayAdvisedCourses(Node* head)
{
    printf("Advised Courses:\n");
    displayCourses(head);
}

void dropCourse(Node** head, const char* code)
{
    removeCourse(head, code);
    printf("The course has dropped.\n");
}

