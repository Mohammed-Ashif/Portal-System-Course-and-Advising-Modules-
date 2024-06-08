#include "advising.h"

void main() {
    Node* availableCourses = NULL;
    StudentAdvising s = {NULL};
    StudentAdvising *limit;
    limit->courseCount = 0;
    int choice;
    float credits;
    char *code = (char*)malloc(6 * sizeof(char));
    char *title = (char*)malloc(50 * sizeof(char));
    char option;

    while (1) {
                printf("*************************************************************\n");
                printf("********************* Portal System *************************\n");
                printf("*************************************************************\n\n");
        printf("\t A. Course Module.\n");
        printf("\t B. Advising Module.\n");
        printf("\t C. Quit.\n");
        printf("\n Enter your choice: ");
        scanf(" %c", &option);

        printf("\n_________________________________________________\n\n");
        switch (option) {
            case 'A':
                printf("*************************************************************\n");
                printf("********************* Course Module *************************\n");
                printf("*************************************************************\n\n");

                do {
                    printf("\t1. Add Course.\n");
                    printf("\t2. Display Courses.\n");
                    printf("\t3. Remove Course.\n");
                    printf("\t4. Exit.\n\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter Course Code: ");
                            scanf(" %[^\n]s", code);
                            printf("Enter Course Title: ");
                            scanf(" %[^\n]s", title);
                            printf("Enter Course Credits: ");
                            scanf("%f", &credits);
                            Course* newCourse = createCourse(code, title, credits);
                            addCourse(&availableCourses, newCourse);
                            printf("Course added successfully.");
                            printf("\n_________________________________________________\n\n");
                            break;

                        case 2:
                            printf("Displaying Courses:\n");
                            displayCourses(availableCourses);
                            break;

                        case 3:
                            printf("Enter Course Code to remove: ");
                            scanf(" %[^\n]s", code);
                            removeCourse(&availableCourses, code);
                            printf("\n_________________________________________________\n\n");
                            break;

                        case 4:
                            printf("\nExiting Course Module...\n");
                            printf("Exit Successful. \n");
                            printf("\n_________________________________________________\n\n");
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                            printf("\n_________________________________________________\n\n");
                    }
                } while (choice != 4);
                break;

            case 'B':
                printf("*************************************************************\n");
                printf("******************** Advising Module ************************\n");
                printf("*************************************************************\n\n");

                do {
                    printf("\t1. Course Advising.\n");
                    printf("\t2. Display Advised Courses Details.\n");
                    printf("\t3. Drop Advised Course.\n");
                    printf("\t4. Exit.\n\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf ("Available course:\n");
                            displayCourses(availableCourses);
                            printf("Enter Course Code to advise: ");
                            scanf(" %[^\n]s", code);
                            Node* temp = availableCourses;
                            while (temp != NULL && strcmp(temp->course->courseCode, code) != 0)
                            {
                                temp = temp->next;
                            }

                            if (temp != NULL)
                            {
                                if (limit->courseCount < MAX_COURSE_ADVISING)
                                {
                                    advisingCourse(&s.advisedCourses, temp->course);
                                    ++limit->courseCount;
                                }
                                else
                                {
                                    printf("Maximum course selection limit has reached.");
                                }
                            }

                            else
                            {
                                printf("Course with Code %s not found.\n", code);
                            }
                            printf("\n_________________________________________________\n\n");
                            break;

                        case 2:
                            displayAdvisedCourses(s.advisedCourses);
                            printf("\n_________________________________________________\n\n");
                            break;

                        case 3:
                            if(limit->courseCount > 0)
                            {
                                printf("Enter Course Code to drop: ");
                                scanf(" %[^\n]s", code);
                                dropCourse(&s.advisedCourses, code);
                                --limit->courseCount;
                            }
                            else
                            {
                                printf("There is no course selected yet.");
                            }
                            printf("\n_________________________________________________\n\n");
                            break;

                        case 4:
                            printf("\nExiting Advising Module...\n");
                            printf("Exit Successful. \n");
                            printf("\n_________________________________________________\n\n");
                            break;

                        default:
                            printf("Invalid choice. Please try again.\n");
                            printf("\n_________________________________________________\n\n");
                    }
                } while (choice != 4);
                break;

            case 'C':
                printf("\n Quiting the program...\n");
                while (availableCourses != NULL) {
                    Node* temp = availableCourses;
                    availableCourses = availableCourses->next;
                    free(temp->course->courseCode);
                    free(temp->course->courseTitle);
                    free(temp->course);
                    free(temp);
                }

                while (s.advisedCourses != NULL) {
                    Node* temp = s.advisedCourses;
                    s.advisedCourses = s.advisedCourses->next;
                    free(temp);
                }
                free(code);
                free(title);
                printf("Operation Successful\n");
                exit(0);

            default:
                printf("Invalid Option. Please try again.\n");
                break;
        }
    }
}
