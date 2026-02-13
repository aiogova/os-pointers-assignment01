// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

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

    // get student first name
    student.f_name = new char[128];
    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    // get student last name
    student.l_name = new char[128];
    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;

    // get student's number of assignments
    std::string numAssignmentsPrompt = "Please enter how many assignments were graded: ";
    int minNumAssignments = 1;
    int maxNumAssignments = 134217728;
    student.n_assignments = promptInt(numAssignmentsPrompt, minNumAssignments, maxNumAssignments);
    
    std::cout << std::endl;

    // get student's assignment grades
    student.grades = new double[student.n_assignments];
    double minGrade = 0;
    double maxGrade = 999.000000;
    std::string gradePrompt;

    for (int i = 0; i < student.n_assignments; i++) {
        gradePrompt = "Please enter grade for assignment " + std::to_string(i) + ": ";

        student.grades[i] = promptDouble(gradePrompt, minGrade, maxGrade);
    }

    // Call `CalculateStudentAverage(???, ???)`
    // double *avgPtr = &average;
    calculateStudentAverage(&student, &average);

    // Output `average`
    std::cout << std::endl;
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    
    // only output one digit after decimal
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "  Average grade: " << average << std::endl;

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
    std::string strResult;
    int result;

    while (true) {
        std::cout << message;
        std::cin >> strResult;

        //find_first_not_of returns the index of the first char NOT in the specified list of chars,
        // else it returns std::string::npos. So if the only the specified chars are used, it returns npos

        // if there IS a char in the string that's not included in the list. Essentially just check for valid chars
        if (!(strResult.find_first_not_of("0123456789") == std::string::npos)) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            continue; // jump to the next loop iteration
        }

        result = std::stoi(strResult);

        // check min and max
        if (result < min || result > max) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            continue; // jump to the next loop iteration
        }

        // return once all conditions were met
        return result;
    }

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
    std::string strResult;

    while (true) {
        std::cout << message;
        std::cin >> strResult;

        //find_first_not_of returns the index of the first char NOT in the specified list of chars,
        // else it returns std::string::npos. So if the only the specified chars are used, it returns npos

        // if there IS a char in the string that's not included in the list. Essentially just check for valid chars
        if (!(strResult.find_first_not_of("0123456789.") == std::string::npos)) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            continue; // jump to the next loop iteration
        }

        // if there is more than one decimal
        if (std::count(strResult.begin(), strResult.end(), '.') > 1) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            continue; // jump to the next loop iteration
        }

        result = std::stod(strResult);

        // check min and max
        if (result < min || result > max) {
            std::cout << "Sorry, I cannot understand your answer" << std::endl;
            continue; // jump to the next loop iteration
        }

        // return once all conditions were met
        return result;
    }
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    double average;
    double sum = 0;

    // cast the void pointer to be a pointer to a student object
    Student *student = (Student*)object;

    // loop through and make the calculation by dereferencing the student pointer
    for (int i = 0; i < student->n_assignments; i++) {
        sum += student->grades[i];
    }

    average = sum / student->n_assignments;

    *avg = average;
}
