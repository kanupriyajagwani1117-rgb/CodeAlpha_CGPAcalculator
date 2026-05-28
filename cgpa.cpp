#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Course {
    std::string name;
    char grade;
    int credits;
};

double gradeToPoints(char grade) {
   
    if (grade == 'A' || grade == 'a') return 4.0;
    if (grade == 'B' || grade == 'b') return 3.0;
    if (grade == 'C' || grade == 'c') return 2.0;
    if (grade == 'D' || grade == 'd') return 1.0;
    if (grade == 'F' || grade == 'f') return 0.0;
    return -1.0; 
}

int main() {
    std::cout << "=========================================\n";
    std::cout << "         GRADES & CGPA CALCULATOR        \n";
    std::cout << "=========================================\n\n";
    
    double previousCGPA = 0.0;
    int previousCredits = 0;
    char hasPastSemesters;
    
    std::cout << "Do you want to include previous semesters for CGPA? (y/n): ";
    std::cin >> hasPastSemesters;
    
    if (hasPastSemesters == 'y' || hasPastSemesters == 'Y') {
        std::cout << "Enter your current cumulative GPA (e.g., 3.50): ";
        std::cin >> previousCGPA;
        std::cout << "Enter total credit hours earned so far: ";
        std::cin >> previousCredits;
    }

    int numCourses;
    std::cout << "\nEnter the number of courses taken this semester: ";
    std::cin >> numCourses;
    
    std::vector<Course> courses(numCourses);
    int currentCredits = 0;
    double currentGradePoints = 0.0;

    std::cin.ignore(); 

    for (int i = 0; i < numCourses; ++i) {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "Course " << i + 1 << " Name: ";
        std::getline(std::cin, courses[i].name);
        
        while (true) {
            std::cout << "Enter Grade (A, B, C, D, F): ";
            std::cin >> courses[i].grade;
            if (gradeToPoints(courses[i].grade) != -1.0) {
                break;
            }
            std::cout << "❌ Invalid grade! Please enter A, B, C, D, or F.\n";
        }
        
        std::cout << "Enter Credit Hours: ";
        std::cin >> courses[i].credits;
        
        std::cin.ignore(); 

        currentCredits += courses[i].credits;
        currentGradePoints += (gradeToPoints(courses[i].grade) * courses[i].credits);
    }

    std::cout << "\n=========================================\n";
    std::cout << std::left << std::setw(25) << "Course Name" 
              << std::setw(10) << "Grade" 
              << std::setw(10) << "Credits" << "\n";
    std::cout << "=========================================\n";
    

    for (int i = 0; i < numCourses; ++i) {
        char upperGrade = (courses[i].grade >= 'a' && courses[i].grade <= 'z') ? (courses[i].grade - 32) : courses[i].grade;
        std::cout << std::left << std::setw(25) << courses[i].name 
                  << std::setw(10) << upperGrade 
                  << std::setw(10) << courses[i].credits << "\n";
    }
    std::cout << "-----------------------------------------\n";

    double semesterGpa = (currentCredits > 0) ? (currentGradePoints / currentCredits) : 0.0;
    
    int totalOverallCredits = previousCredits + currentCredits;
    double totalOverallPoints = (previousCGPA * previousCredits) + currentGradePoints;
    double finalCgpa = (totalOverallCredits > 0) ? (totalOverallPoints / totalOverallCredits) : 0.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Semester Credits Registered : " << currentCredits << "\n";
    std::cout << "Computed Semester GPA       : " << semesterGpa << "\n";
    
    if (hasPastSemesters == 'y' || hasPastSemesters == 'Y') {
        std::cout << "Total Cumulative Credits    : " << totalOverallCredits << "\n";
        std::cout << "Final Cumulative CGPA       : " << finalCgpa << "\n";
    } else {
        std::cout << "Final Cumulative CGPA       : " << semesterGpa << "\n";
    }
    std::cout << "=========================================\n";

    return 0;
}