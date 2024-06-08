#ifndef COURSE_H
#include "utils.h"

typedef struct Course {
    char* courseCode;
    char* courseTitle;
    float credits;
} Course;

typedef struct Node {
    Course* course;
    struct Node* next;
} Node;

Course* createCourse(const char* code, const char* title, int credits);
Node* createNode(Course* course);
void addCourse(Node** head, Course* course);
void displayCourses(Node* head);
void removeCourse(Node** head, const char* code);

#endif // COURSE_H
