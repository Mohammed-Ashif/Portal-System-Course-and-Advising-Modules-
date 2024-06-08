#include "course.h"

// Function to create a new course
Course* createCourse(const char* code, const char* title, int credits)
{
    Course* newCourse = (Course*)malloc(sizeof(Course));
    newCourse->courseCode = (char*)malloc((strlen(code) + 1) * sizeof(char));
    newCourse->courseTitle = (char*)malloc((strlen(title) + 1) * sizeof(char));
    strcpy(newCourse->courseCode, code);
    strcpy(newCourse->courseTitle, title);
    newCourse->credits = credits;
    return newCourse;
}

// Function to create a new node
Node* createNode(Course* course)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}

// Function to add a course to a list
void addCourse(Node** head, Course* course)
{
    Node* newNode = createNode(course);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display courses
void displayCourses(Node* head)
{
    Node* temp = head;
    int k = 1;
    if (temp == NULL)
    {
        printf("No courses available.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d.Course Code: %s\n", k, temp->course->courseCode);
        printf(" Course Title: %s\n", temp->course->courseTitle);
        printf(" Course Credits: %.1f\n\n", temp->course->credits);
        temp = temp->next;
        ++k;
    }
}

// Function to remove a course from a list
void removeCourse(Node** head, const char* code)
{
    Node *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->course->courseCode, code) == 0)
    {
        *head = temp->next;
        free(temp->course->courseCode);
        free(temp->course->courseTitle);
        free(temp->course);
        free(temp);
        printf("Course with Code %s removed.\n", code);
        printf("Removal process is successful\n\n");
        return;
    }

    while (temp != NULL && strcmp(temp->course->courseCode, code) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Course with Code %s not found.\n", code);
        printf("Removal process failed.\n\n");
        return;
    }

    prev->next = temp->next;
    free(temp->course->courseCode);
    free(temp->course->courseTitle);
    free(temp->course);
    free(temp);
    printf("Course with Code %s removed.\n", code);
}

