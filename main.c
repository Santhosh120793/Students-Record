#include <stdio.h>
#include <string.h>

// Structure to store student information
typedef struct
{
    char name[50];
    int roll_number;
    int marks[5];
    int status_flag;
} Student;

// Function to calculate the average marks of a student
float average(int *marks)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    return (float)sum / 5.0;
}

// Function to find the topper
void Topper(Student *students, int num_students, Student *topper)
{
    float max_average = -1.0;
    for (int i = 0; i < num_students; i++)
    {
        float avg = average(students[i].marks);
        if (avg > max_average)
        {
            max_average = avg;
            *topper = students[i];
        }
    }
}

// Function to display subject-wise performance
void subject_performance(Student *students, int num_students)
{
    printf("\nSubject-wise Performance:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("Student: %s  Roll: %d \n", students[i].name, students[i].roll_number);
        for (int j = 0; j < 5; j++)
        {
            printf("Subject %d: %d\n", j + 1, students[i].marks[j]);

           if (students[i].marks[j] >= 0 && students[i].marks[j]  < 35 )
            {
                students[i].status_flag = 0;
            }
            // check for pass condition
            if (students[i].marks[j] >= 35 && students[i].marks[j] < 75)
            {
                students[i].status_flag = 1;
            }
            // Check for distinction condition
            if (students[i].marks[j] >= 75 && students[i].marks[j] <=100)
            {
                students[i].status_flag = 2;
            }

        if (students[i].status_flag == 0)
        {
            printf("Result: Failed\n");
        }
        else if (students[i].status_flag == 1)
        {
            printf("Result: Passed\n");
        }
        else if (students[i].status_flag == 2)
        {
            printf("Result: Distinction\n");
        }
        }
        printf("\n");
    }
}

int main()
{
    // Declare an array of 5 student structures
    Student students[5];
    int num_students = 5;

    // Input student data
    for (int i = 0; i < num_students; i++)
        {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("Enter marks for 5 subjects:\n");
        for (int j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
}

    // Display average marks
    printf("\nAverage Marks:\n");
    for (int i = 0; i < num_students; i++)
    {
        float avg = average(students[i].marks);
        printf("Student: %s  Roll: %d  Average: %.2f\n", students[i].name, students[i].roll_number, avg);
    }

    // Display the topper
    Student topper;
    Topper(students, num_students, &topper);
    float topper_avg = average(topper.marks);
    printf("\nTopper:\n");
    printf("Name: %s\tRoll:%d\tAverage: %.2f\n", topper.name, topper.roll_number, topper_avg);

    // Display subject-wise performance
    subject_performance(students, num_students);

    return 0;
}
