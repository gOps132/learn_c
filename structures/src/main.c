#include <stdio.h>
#define MAX_CHAR_BUF 100
#define NO_OF_STUDENTS 2
/**
 * 1. Create a structure called "Student" with members name, age, and total marks. Write a C program to input data for two students, display their information, and find the average of total marks.
 */
typedef struct Student {
    char name[MAX_CHAR_BUF];
    int age;
    float total_marks;
    
} student_t;

int main(int argc, char** argv)
{
    student_t students[NO_OF_STUDENTS];

    for (int i = 0; i < NO_OF_STUDENTS; i++)
    {
        printf("Input the details of the student %d:\n", i);
        printf("Name: ");
        scanf("%s", &students[i].name);
        printf("age: ");
        scanf("%d", &students[i].age);
        printf("total marks: ");
        scanf("%f", &students[i].total_marks);   
    }

    float avg_marks = 0;
    for (int i = 0; i < NO_OF_STUDENTS; i++)
    {
        printf("Student 1 details\n");
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Total Marks: %f\n", students[i].total_marks);
        avg_marks += students[i].total_marks;
    }
    
    printf("Average Marks: %f", (avg_marks) / (float)NO_OF_STUDENTS);

    return 1;
}