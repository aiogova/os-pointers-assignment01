// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;

    // Sequence of user input -> store in fields of `student`

    // get student ID
    std::string userIDPrompt = "Please enter the student's id number: ";
    int minStudentID = 0;
    int maxStudentID = 999999999;
    student.id = promptInt(userIDPrompt, minStudentID, maxStudentID);

    //std::cout << "Your student user ID is: " << student.id << std::endl;


    // get student first name
    student.f_name = new char[128];
    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    //std::cout << "Your first name is: " << student.f_name << std::endl;

    // get student last name
    student.l_name = new char[128];
    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;

    // get student's number of assignments
    std::string numAssignmentsPrompt = "Please enter how many assignments were graded: ";
    int minNumAssignments = 1;
    int maxNumAssignments = 134217728;
    student.n_assignments = promptInt(numAssignmentsPrompt, minNumAssignments, maxNumAssignments);
    
    //std::cout << "Your number of assignments is: " << student.n_assignments << std::endl;

    // get student's assignment grades
    student.grades = new double[student.n_assignments];
    double minGrade = 0;
    double maxGrade = 999.000000;
    std::string gradePrompt;

    for (int i = 0; i < student.n_assignments; i++) {
        gradePrompt = "Please enter grade for assignment " + std::to_string(i) + ": ";

        student.grades[i] = promptDouble(gradePrompt, minGrade, maxGrade);
    }

    //  for (int i = 0; i < student.n_assignments; i++) {
    //     std::cout << gradePrompt << i << ": ";
    //     std::cin >> student.grades[i];
    // }
    
    //student.grades = promptDouble(gradePrompt, minGrade, maxGrade);
    

    // Call `CalculateStudentAverage(???, ???)`
    // double *avgPtr = &average;
    calculateStudentAverage(student.grades, &average);

    // Output `average`

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int result;
    std::cout << message;
    std::cin >> result;
    return result;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double result;
    std::cout << message;
    std::cin >> result;
    return result;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    double result = 0.0;
    // for (int i = 0; i < student.n_assignments; i++) {

    // }
    *avg = result;
}
