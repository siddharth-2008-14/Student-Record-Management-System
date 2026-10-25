# Student Record Management System

A console-based **Student Record Management System** built in C. The application handles student records securely using file handling methods to preserve data across system restarts.

## Features
- **Data Persistence:** Automatic data loading on startup and saving on exit.
- **Record Management:** Easily Add, Update, and Delete student profiles.
- **Search System:** Locate individual student records instantly via Roll Number.
- **Academic Calculator:** Automatic processing of totals, averages, percentages, and letter grades (A-F).
- **Sorting Engine:** Sorts the entire database by marks in descending order.
- **Analytics Dashboard:** Detailed statistical summaries including class toppers, pass/fail counters, and class averages.

## How to Run the Project

### Prerequisites
Make sure you have a C compiler installed (like GCC/MinGW).

### Compilation
Open your terminal inside the project directory and run:
```bash
gcc main.c -o student_system
```

### Execution
Run the compiled executable:
- **Windows:**
  ```cmd
  student_system.exe
  ```
- **Linux/Mac:**
  ```bash
  ./student_system
  ```

## Menu Options
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Calculate Student Result
7. Display Topper
8. Sort Students by Marks
9. Display Statistics
10. Save and Exit
