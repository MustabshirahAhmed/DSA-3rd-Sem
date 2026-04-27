#include <iostream>
using namespace std;

struct Student {
    string seatNo;
    Student* snext;
};

struct Course {
    int courseNo;
    string courseTitle;
    Student* studentHead;
    Course* cnext;
};

Course* head = NULL;
Course* previous = NULL;

void AddCourse(int courseNo, string courseTitle) {
    Course* newCourse = new Course();
    newCourse->courseNo = courseNo;
    newCourse->courseTitle = courseTitle;
    newCourse->studentHead = NULL;
    newCourse->cnext = NULL;

    if (head == NULL) {
        head = newCourse;
    } else {
        Course* current = head;
        while (current->cnext != NULL) {
            current = current->cnext;
        }
        current->cnext = newCourse;
    }
}

Course* SearchCourse(int courseNo) {
    Course* current = head;
    previous = NULL;

    while (current != NULL) {
        if (current->courseNo == courseNo) {
            return current;
        }
        previous = current;
        current = current->cnext;
    }
    return NULL;
}

void DeleteCourse(int courseNo) {
    Course* current = SearchCourse(courseNo);
    if (current == NULL) {
        return;
    }

    if (current == head) {
        head = head->cnext;
    } else {
        previous->cnext = current->cnext;
    }

    Student* temp;
    while (current->studentHead != NULL) {
        temp = current->studentHead;
        current->studentHead = current->studentHead->snext;
        delete temp;
    }

    delete current;
}

void PrintCourses() {
    Course* current = head;
    while (current != NULL) {
        cout << current->courseTitle << " (" << current->courseNo << ")\n";
        current = current->cnext;
    }
}

void AddStudent(int courseNo, string seatNo) {
    Course* subject = SearchCourse(courseNo);
    if (subject == NULL) {
        return;
    }

    Student* newStudent = new Student();
    newStudent->seatNo = seatNo;
    newStudent->snext = subject->studentHead;
    subject->studentHead = newStudent;
}

void PrintStudents(int courseNo) {
    Course* subject = SearchCourse(courseNo);
    if (subject == NULL) {
        return;
    }

    Student* current = subject->studentHead;
    while (current != NULL) {
        cout << current->seatNo << "\n";
        current = current->snext;
    }
}

void SearchStudent(int courseNo, string seatNo) {
    Course* subject = SearchCourse(courseNo);
    if (subject == NULL) {
        return;
    }

    Student* current = subject->studentHead;
    while (current != NULL) {
        if (current->seatNo == seatNo) {
            return;
        }
        current = current->snext;
    }
}

void DeleteStudent(int courseNo, string seatNo) {
    Course* subject = SearchCourse(courseNo);
    if (subject == NULL) {
        return;
    }

    Student* current = subject->studentHead;
    Student* prev = NULL;

    while (current != NULL) {
        if (current->seatNo == seatNo) {
            if (prev == NULL) {
                subject->studentHead = current->snext;
            } else {
                prev->snext = current->snext;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->snext;
    }
}

int main() {
    int choice, courseNo;
    string courseTitle, seatNo;

    do {
        cout << "\n1. Add a course\n";
        cout << "2. Delete a course\n";
        cout << "3. Search a course\n";
        cout << "4. Print all courses\n";
        cout << "5. Add a student to a course\n";
        cout << "6. Delete a student from a course\n";
        cout << "7. Print students of a course\n";
        cout << "8. Search a student in a course\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> courseNo >> ws;
                getline(cin, courseTitle);
                AddCourse(courseNo, courseTitle);
                break;
            case 2:
                cin >> courseNo;
                DeleteCourse(courseNo);
                break;
            case 3:
                cin >> courseNo;
                SearchCourse(courseNo);
                break;
            case 4:
                PrintCourses();
                break;
            case 5:
                cin >> courseNo >> seatNo;
                AddStudent(courseNo, seatNo);
                break;
            case 6:
                cin >> courseNo >> seatNo;
                DeleteStudent(courseNo, seatNo);
                break;
            case 7:
                cin >> courseNo;
                PrintStudents(courseNo);
                break;
            case 8:
                cin >> courseNo >> seatNo;
                SearchStudent(courseNo, seatNo);
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}
