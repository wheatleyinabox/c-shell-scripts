#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *      Summary of All Hard-Coded Elements:
 *              - Number of Students
 *                      = function main/Students students[]
 *              - Number of Grades
 *                      = struct Student/char grade[]
 *              - Directory for file access
 */

typedef struct {
    char name[256];
    int score;
    char grade[4]; // HARD-CODED
} Student;

void bubbSort(Student arr[], int n)
{
        Student temp;

        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                {
                        if (arr[j].score < arr[j + 1].score)
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}

int compareCodeAndScore(char* code)
{
        FILE* answer;
        FILE* studentWork;
        answer = fopen("answer_code.c", "r");
        studentWork = fopen(code, "r");

        if ((answer == NULL) && (studentWork == NULL))
        {
                printf("ERROR: File(s) don't exist!");
                return 1;
        }

        printf("%s\n", "Answer key and student files opened.");

        int score = 100;
        char* A = malloc(256 * sizeof(char));
        char* S = malloc(256 * sizeof(char));
        while ((fgets(A, 256, answer) != NULL) && (fgets(S, 256, studentWork) !=  NULL))
        {
                if (strcmp(A, S) != 0)
                {
                        score -= 1;
                }
        }

        fclose(answer);
        fclose(studentWork);
        free(A);
        free(S);

        printf("%s\n", "Scores calculated.");

        return score;
}

char* assignLetterGrade(int grade)
{
        if (grade >= 94)
        {
                return "A";
        }
        else if (grade >= 89 && grade <= 93)
        {
                return "A-";
        }
        else if (grade >= 86 && grade <= 88)
        {
                return "B+";
        }
        else if (grade >= 82 && grade <= 85)
        {
                return "B";
        }
        else if (grade >= 78 && grade <= 81)
        {
                return "B-";
        }
        else if (grade >= 75 && grade <= 77)
        }
        else if (grade >= 71 && grade <= 74)
        {
                return "C";
        }
        else if (grade >= 68 && grade <= 70)
        {
                return "C-";
        }
        else if (grade >= 65 && grade <= 67)
        {
                return "D+";
        }
        else if (grade >= 61 && grade <= 64)
        {
                return "D";
        }
        else if (grade >= 58 && grade <= 60)
        {
                return "D-";
        }
                return "F";
        }

        return "NULL";
}

int main()
{
        const char* path = "/user/vdeleon/cs2600/project1"; // HARD-CODED
        DIR* directory = opendir(path);
        FILE* grades;
        grades = fopen("student_grades", "w");

        if (!directory)
        {
                printf("ERROR: Directory doesn't exist!");
                return 1;
        }
        if (grades == NULL)
        {
                printf("ERROR: Unable to create grades file!");
                return 1;
        }

        printf("%s\n", "Directory opened!");
        printf("%s\n", "Grades file created!");

        struct dirent* entity;
        entity = readdir(directory);
        Student students[4]; // HARD-CODED
        int count = 0;

        while (entity != NULL)
        {
                if ((strstr(entity->d_name, "student") != NULL) && (strstr(entity->d_name, ".c") != NULL))
                {
                        strcpy(students[count].name, entity->d_name);

                        printf("%s\n", "Starting comparisons...");

                        students[count].score = compareCodeAndScore(entity->d_name);
                        strcpy(students[count].grade, assignLetterGrade(students[count].score));

                        printf("%s\n", "Data successfully stored.");

                        count++;
                }

                entity = readdir(directory);
        }

        closedir(directory);

        bubbSort(students, count);
        for (int i = 0; i < count; i++)
        {
                fprintf(grades, "%s %d %s\n", students[i].name, students[i].score, students[i].grade);
        }
        printf("%s\n", "Grades file successfully created and Student information sorted! :D");

        fclose(grades);

        printf("%s\n", "All done! :D");

        return 0;
}