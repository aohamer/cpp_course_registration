#include <iostream>

using namespace std;
class Person //Base class
{
private:
    //Attributes
    string forename;
    string surname;
    string email;
public:
    //public parameters and functions to get/access private parameters and constructors
    Person(string forename, string surname, string email)
        : forename(forename), surname(surname), email(email) {}
    string getFirstname(){return forename;}
    string getLastname(){return surname;}
    string getEmail(){return email;}
};


class Lecturer : public Person //inherited class from Person
{
private:
    string academic_title;
public:
    Lecturer(string forename, string surname, string email, string academic_title) : Person(forename, surname, email), academic_title(academic_title) {}
    string getAcademic_Title(){return academic_title;}
};


class Student : public Person //inherited class from Person
{
private:
    int matr_number;
    string university;
public:
    Student() : Person("", "", ""), matr_number(0), university("") {}
    Student(string forename, string surname, string email, int matr_number, string university)
        : Person(forename, surname, email), matr_number(matr_number), university(university) {}
    //methods to get/access the private attributes
    int getMatrNum(){return matr_number;}
    string getUniversity(){return university;}
};

class Course
{
private:
    string name;
    Lecturer lecturer;
    Student students[10];
    int students_count = 0;
    const int min_students = 3;
    const int max_students = 10;

public:
    //constructors
    Course(string name, Lecturer lecturer) : name(name), lecturer(lecturer) {}
    //methods to get/access the private attributes
    string getName() {return name;}
    string getLecturerName() { return lecturer.getAcademic_Title() + " " + lecturer.getFirstname() + " " + lecturer.getLastname(); }
    int getStudentCount(){return students_count;}
    bool addStudent(Student student) //method to add students data in the array and check if the student is already registered
    {
        if(getStudentCount() >= max_students)
        {
            cout << "Course is full" <<endl;
            return false;
        }
        for(int i = 0; i < students_count; i++)
        {
            Student s = students[i];
            if((s.getEmail() == student.getEmail()))
            {
                cout << "Student already registered!" << endl;
                return false;
            }
        }
        students[students_count] = student;
        students_count++;
        cout << "Student added successfully!" << endl;
        return true;
    }
    void displayStudentList() //method for displaying the students in the registered courses
    {
        cout << "Course: " << getName() << "\nLecturer: " << getLecturerName() << "\nParticipants:\n";
        for (int i = 0; i < students_count; ++i)
        {
            Student student = students[i];
            cout << student.getFirstname() << " " << student.getLastname() << " (" << student.getEmail() << ")" << " (" << student.getMatrNum () << ")" << " (" << student.getUniversity() << ")" ;
        }
        if (students_count < min_students)
        {
            cout << "Course will not take place\n";
        }
    }
    void displayCourseInfo()// a method for the 3rd choice
    {
        cout << "Course: " << getName() << "\nLecturer: " << getLecturerName() << "\nFree places: " << (max_students - students_count) << "\n";
    }

    void notifyParticipants()//method to notify the participants that the course will not take place
    {
        for (int i = 0; i < students_count; ++i) {
            cout << students[i].getFirstname() << " " << students[i].getLastname() << " (" << students[i].getEmail() << ")\n";
        }
    }


};
int main()
{
    Lecturer lecturer1("Peter", "Faber", "peterfaber@thd.com", "Prof. Dr.");
    Lecturer lecturer2("Buss", "Rudi", "bussrudi@thd.com", "Dr.");
    Course course1("Programming", lecturer1);
    Course course2("Databases", lecturer2);
    Course course3("Software Engineering", lecturer1);
    while (true) //to keep the menu running
    {
        cout << "\nMenu:" << endl;
        cout << "1. Register for a course\n";
        cout << "2. Display course participants\n";
        cout << "3. Display available courses\n";
        cout << "4. Exit program\n";
        int choice;
        cin >> choice;
        if (choice == 1) // Register for a course
        {
            string forename, surname, email, university;
            int matr_number;
            int courseChoice;
            cout << "Enter student details:\n";
            cout << "Forename: ";
            cin >> forename;
            cout << "Surname: ";
            cin >> surname;
            cout << "Email: ";
            cin >> email;
            cout << "Matriculation number: ";
            cin >> matr_number;
            cout << "University: ";
            cin >> university;
            Student student(forename, surname, email, matr_number, university);
            cout << "Choose a course (1. Programming, 2. Databases, 3. Software Engineering): ";
            cin >> courseChoice;
            if (courseChoice == 1)
            {
                course1.addStudent(student);
            }
            else if (courseChoice == 2)
            {
                course2.addStudent(student);
            }
            else if (courseChoice == 3)
            {
                course3.addStudent(student);
            }
            else
            {
                cout << "Invalid course choice.\n";
            }
        }
        else if (choice == 2) // Display course participants
        {
            int courseChoice;
            cout << "Choose a course to display participants (1. Programming, 2. Databases, 3. Software Engineering): ";
            cin >> courseChoice;

            if (courseChoice == 1)
            {
                course1.displayStudentList();
            }
            else if (courseChoice == 2)
            {
                course2.displayStudentList();
            }
            else if (courseChoice == 3)
            {
                course3.displayStudentList();
            }
            else
            {
                cout << "Invalid course choice.\n";
            }
        }
        else if (choice == 3) // Display available courses
        {

            cout << "\nAvailable courses:\n";
            if (course1.getStudentCount() >= 3)
            {
                course1.displayCourseInfo();
            }
            else if (course2.getStudentCount() >= 3)
            {
                course2.displayCourseInfo();
            }
            else if (course3.getStudentCount() >= 3)
            {
                course3.displayCourseInfo();
            }
        }
        else if (choice == 4) //Exiting the program and checking if the participants does not reach the minimum to notify them that the course won't take place
        {
            cout << "Exiting program...\n";
            cout << "Notifying participants of courses that are not taking place:\n";

            if (course1.getStudentCount()< 3) {
                course1.notifyParticipants();
            }
            else if (course2.getStudentCount()< 3) {
                course2.notifyParticipants();
            }
            else if (course3.getStudentCount()< 3) {
                course3.notifyParticipants();
            }

            break;
        }
        else
        {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}


