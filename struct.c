#include <stdio.h>

struct Employee
{
        char name[10];
        int age;
        int salary;
}

int main()
{
        FILE *fp;
        struct Employee e1;
        char temp_name[10];
        int temp_age;
        int temp_salary;

        fp = fopen("employee_data", "w");
        printf("Enter employee name, age, and salary: ");
        scanf("%s %d %d", &temp_name, &temp_age, &temp_salary);
        fprintf(fp, "%s %d %d", temp_name, temp_age, temp_salary);

        fclose(fp);
        fp = fopen("employee_data", "r");
        fscanf(fp, "%s %d %d", &e1.name, &e1.age, &e1.salary);

        fclose(fp);

        return 0;
}