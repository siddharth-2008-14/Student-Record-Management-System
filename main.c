#include <stdio.h>

struct student {
    int roll;
    char name[50];
    char department[20];
    int semester;
    int age;
    int marks_s1;
    int marks_s2;
    int marks_s3;
    int total;
    float average;
    float percentage;
    char grade;
};

int main(void) {
    int choice;
    int n = 4;
    struct student s[4];
    int current_count = 0;

    do {
        printf("\n=====================================\n"
               "STUDENT RECORD MANAGEMENT SYSTEM"
               "\n=====================================\n"
               "1. Add Students\n"
               "2. Display All Students\n"
               "3. Search Student\n"
               "4. Update Student\n"
               "5. Delete Student\n"
               "6. Calculate Student Result\n"
               "7. Display Topper\n"
               "8. Sort Students by Marks\n"
               "9. Display Statistics\n"
               "10. Save and Exit\n");
        printf("Enter your choice:->");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                FILE *fp = fopen("student_Record.txt", "w");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    return 1;
                }
                printf("Enter the students details\n");
                for (int i = 0; i < n; i++) {
                    printf("\nStudent %d:\n", i + 1);
                    printf("Roll number: ");
                    scanf("%d", &s[i].roll);
                    printf("Name: ");
                    scanf("%s", s[i].name);
                    printf("Department: ");
                    scanf("%s", s[i].department);
                    printf("Semester in number: ");
                    scanf("%d", &s[i].semester);
                    printf("Age: ");
                    scanf("%d", &s[i].age);
                    printf("Marks in Physics: ");
                    scanf("%d", &s[i].marks_s1);
                    printf("Marks in Chemistry: ");
                    scanf("%d", &s[i].marks_s2);
                    printf("Marks in Mathematics: ");
                    scanf("%d", &s[i].marks_s3);

                    s[i].total = s[i].marks_s1 + s[i].marks_s2 + s[i].marks_s3;
                    s[i].average = s[i].total / 3.0f;
                    s[i].percentage = (s[i].total / 300.0f) * 100.0f;

                    if (s[i].percentage >= 90.0) s[i].grade = 'A';
                    else if (s[i].percentage >= 80.0) s[i].grade = 'B';
                    else if (s[i].percentage >= 70.0) s[i].grade = 'C';
                    else if (s[i].percentage >= 60.0) s[i].grade = 'D';
                    else if (s[i].percentage >= 40.0) s[i].grade = 'E';
                    else s[i].grade = 'F';

                    current_count++;
                }

                for (int j = 0; j < current_count; j++) {
                    fprintf(fp, "Roll no: %d\n", s[j].roll);
                    fprintf(fp, "Name: %s\n", s[j].name);
                    fprintf(fp, "Department: %s\n", s[j].department);
                    fprintf(fp, "Semester: %d\n", s[j].semester);
                    fprintf(fp, "Age: %d\n", s[j].age);
                    fprintf(fp, "Marks in Physics: %d\n", s[j].marks_s1);
                    fprintf(fp, "Marks in Chemistry: %d\n", s[j].marks_s2);
                    fprintf(fp, "Marks in Maths: %d\n", s[j].marks_s3);
                    fprintf(fp, "Total: %d\n", s[j].total);
                    fprintf(fp, "Grade: %c\n\n", s[j].grade);
                }
                fclose(fp);
                break;
            }
            case 2:
                if (current_count == 0) {
                    printf("No student records available.\n");
                } else {
                    for (int i = 0; i < current_count; i++) {
                        printf("\nRoll no: %d\n", s[i].roll);
                        printf("Name: %s\n", s[i].name);
                        printf("Department: %s\n", s[i].department);
                        printf("Semester: %d\n", s[i].semester);
                        printf("Age: %d\n", s[i].age);
                        printf("Marks in Physics: %d\n", s[i].marks_s1);
                        printf("Marks in Chemistry: %d\n", s[i].marks_s2);
                        printf("Marks in Maths: %d\n", s[i].marks_s3);
                        printf("Total: %d\n", s[i].total);
                        printf("Grade: %c\n", s[i].grade);
                    }
                }
                break;


                case 3: {
    int search_roll;
    int found = 0;
    
    if (current_count == 0) {
        printf("No student records available to search.\n");
        break;
    }
    
    printf("Enter Roll Number to search: ");
    scanf("%d", &search_roll);
    
    for (int i = 0; i < current_count; i++) {
        if (s[i].roll == search_roll) {
            printf("\n--- Student Found ---\n");
            printf("Roll no: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Department: %s\n", s[i].department);
            printf("Semester: %d\n", s[i].semester);
            printf("Age: %d\n", s[i].age);
            printf("Total Marks: %d\n", s[i].total);
            printf("Grade: %c\n", s[i].grade);
            found = 1;
            break; 
        }
    }
    
    if (!found) {
        printf("Student with Roll Number %d not found.\n", search_roll);
    }
    break;
}

case 4: {
    int update_roll;
    int found = 0;
    if (current_count == 0) {
        printf("No student records available to update.\n");
        break;
    }
    printf("Enter Roll Number to update: ");
    scanf("%d", &update_roll);
    for (int i = 0; i < current_count; i++) {
        if (s[i].roll == update_roll) {
            found = 1;
            printf("\n--- Current Details ---\n");
            printf("Name: %s | Department: %s\n", s[i].name, s[i].department);
            printf("\nEnter New Details:\n");
            printf("New Name: ");
            scanf("%s", s[i].name);
            printf("New Department: ");
            scanf("%s", s[i].department);
            printf("New Semester in number: ");
            scanf("%d", &s[i].semester);
            printf("New Age: ");
            scanf("%d", &s[i].age);
            printf("New Marks in Physics: ");
            scanf("%d", &s[i].marks_s1);
            printf("New Marks in Chemistry: ");
            scanf("%d", &s[i].marks_s2);
            printf("New Marks in Mathematics: ");
            scanf("%d", &s[i].marks_s3);

            s[i].total = s[i].marks_s1 + s[i].marks_s2 + s[i].marks_s3;
            s[i].average = s[i].total / 3.0f;
            s[i].percentage = (s[i].total / 300.0f) * 100.0f;

            if (s[i].percentage >= 90.0) s[i].grade = 'A';
            else if (s[i].percentage >= 80.0) s[i].grade = 'B';
            else if (s[i].percentage >= 70.0) s[i].grade = 'C';
            else if (s[i].percentage >= 60.0) s[i].grade = 'D';
            else if (s[i].percentage >= 40.0) s[i].grade = 'E';
            else s[i].grade = 'F';

            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", update_roll);
    } else {
        FILE *fp = fopen("student_Record.txt", "w");
        if (fp != NULL) {
            for (int j = 0; j < current_count; j++) {
                fprintf(fp, "Roll no: %d\n", s[j].roll);
                fprintf(fp, "Name: %s\n", s[j].name);
                fprintf(fp, "Department: %s\n", s[j].department);
                fprintf(fp, "Semester: %d\n", s[j].semester);
                fprintf(fp, "Age: %d\n", s[j].age);
                fprintf(fp, "Marks in Physics: %d\n", s[j].marks_s1);
                fprintf(fp, "Marks in Chemistry: %d\n", s[j].marks_s2);
                fprintf(fp, "Marks in Maths: %d\n", s[j].marks_s3);
                fprintf(fp, "Total: %d\n", s[j].total);
                fprintf(fp, "Grade: %c\n\n", s[j].grade);
            }
            fclose(fp);
        }
    }
    break;
}

case 5: {
    int delete_roll;
    int found = 0;
    
    if (current_count == 0) {
        printf("No student records available to delete.\n");
        break;
    }
    
    printf("Enter Roll Number to delete: ");
    scanf("%d", &delete_roll);
    
    for (int i = 0; i < current_count; i++) {
        if (s[i].roll == delete_roll) {
            found = 1;
            for (int j = i; j < current_count - 1; j++) {
                s[j] = s[j + 1];
            }
            current_count--;
            printf("Record deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Student with Roll Number %d not found.\n", delete_roll);
    } else {
        FILE *fp = fopen("student_Record.txt", "w");
        if (fp != NULL) {
            for (int j = 0; j < current_count; j++) {
                fprintf(fp, "Roll no: %d\n", s[j].roll);
                fprintf(fp, "Name: %s\n", s[j].name);
                fprintf(fp, "Department: %s\n", s[j].department);
                fprintf(fp, "Semester: %d\n", s[j].semester);
                fprintf(fp, "Age: %d\n", s[j].age);
                fprintf(fp, "Marks in Physics: %d\n", s[j].marks_s1);
                fprintf(fp, "Marks in Chemistry: %d\n", s[j].marks_s2);
                fprintf(fp, "Marks in Maths: %d\n", s[j].marks_s3);
                fprintf(fp, "Total: %d\n", s[j].total);
                fprintf(fp, "Grade: %c\n\n", s[j].grade);
            }
            fclose(fp);
        }
    }
    break;
}

            case 6: {
                if (current_count == 0) {
                    printf("No records available to calculate results.\n");
                } else {
                    printf("\n--- STUDENT SCORECARDS & RESULTS ---\n");
                    for (int i = 0; i < current_count; i++) {
                        printf("Roll: %d | Name: %s | Total: %d/300 | Percentage: %.2f%% | Grade: %c | Result: %s\n",
                               s[i].roll, s[i].name, s[i].total, s[i].percentage, s[i].grade,
                               (s[i].grade != 'F') ? "PASSED" : "FAILED");
                    }
                }
                break;
            }




            case 10:
                printf("Exiting program...\n");
                break;
            default:
                printf("Option not fully implemented yet or invalid choice.\n");
                break;
        }
    } while (choice != 10);

    return 0;
}
