#include <stdio.h>

struct Student
{
    char name[50];
    int roll;
    float marks;
    char grade;
};

int main()
{
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Roll Number: ");
        scanf("%d", &students[i].roll);

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        if (students[i].marks >= 90)
            students[i].grade = 'A';
        else if (students[i].marks >= 75)
            students[i].grade = 'B';
        else if (students[i].marks >= 60)
            students[i].grade = 'C';
        else if (students[i].marks >= 40)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }

    printf("\n--- Student Records ---\n");
    for (i = 0; i < n; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Marks: %.2f\n", students[i].marks);
        printf("Grade: %c\n\n", students[i].grade);
    }

    return 0;
}
