#include <iostream>
#include <vector>
#include <string>

// ----------------------------- Model --------------------------------
class Student {
private:
    std::string name;
    int age;
    std::string studentId;

public:
    Student(const std::string& name, int age, const std::string& studentId)
        : name(name), age(age), studentId(studentId) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getStudentId() const { return studentId; }
};

// ----------------------------- View ---------------------------------
class StudentView {
public:
    void displayStudent(const Student& student) const {
        std::cout << "Name: " << student.getName()
                  << ", Age: " << student.getAge()
                  << ", ID: " << student.getStudentId() << std::endl;
    }

    void displayStudentList(const std::vector<Student>& students) const {
        if (students.empty()) {
            std::cout << "No students in the list." << std::endl;
            return;
        }
        std::cout << "Student List:" << std::endl;
        for (const auto& student : students) {
            displayStudent(student);
        }
    }

    void displayMessage(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

// --------------------------- Controller ----------------------------
class StudentController {
private:
    std::vector<Student> students;
    StudentView view;

public:
    StudentController(const StudentView& view) : view(view) {}

    void addStudent(const std::string& name, int age, const std::string& studentId) {
        students.emplace_back(name, age, studentId);
        view.displayMessage("Student added successfully!");
    }

    void removeStudent(const std::string& studentId) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getStudentId() == studentId) {
                students.erase(it);
                view.displayMessage("Student removed successfully!");
                return;
            }
        }
        view.displayMessage("Student not found!");
    }

    void showAllStudents() const {
        view.displayStudentList(students);
    }
};

// ------------------------------ Main --------------------------------
int main() {
    StudentView view;
    StudentController controller(view);

    controller.addStudent("Alice", 20, "S001");
    controller.addStudent("Bob", 22, "S002");
    controller.addStudent("Charlie", 21, "S003");

    controller.showAllStudents();

    controller.removeStudent("S002");
    controller.showAllStudents();

    controller.removeStudent("S004"); // Try to remove non-existing student

    return 0;
}
