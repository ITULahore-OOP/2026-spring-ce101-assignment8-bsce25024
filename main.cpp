#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

using namespace std;

int main()
{
    // Creating Access Cards
    AccessCard card1("AC-101", 1);
    AccessCard card2("AC-102", 2);

    // Creating Student, Staff, Teaching Assistant
    Student s1("Ali", 1001, 3.4);
    Staff st1("Ahmed", 1002, 50000, card1);
    TeachingAssistant ta1("Sara", 1003, 3.9, 15000, card2, 20);

    // Creating Department and add members
    Department csDept("Computer Science");
    csDept.addMember(&s1);
    csDept.addMember(&st1);
    csDept.addMember(&ta1);

    cout << "Displaying Roles (Run-time Polymorphism):" << endl;
    csDept.displayAllRoles();

    cout << endl;

    // Compile time
    cout << "Grading Assignments:" << endl;
    ta1.gradeAssignment(95);
    ta1.gradeAssignment("A+");

    cout << endl;

    // Tutoring-------Session
    TutoringSession session1(1, 45, &ta1, &s1);
    TutoringSession session2(2, 30, &ta1, &s1);

    // Operator
    if (session1 > session2)
        cout << "Session 1 is longer than Session 2" << endl;
    else
        cout << "Session 2 is longer than Session 1" << endl;

    // Using  Operator ++
    TutoringSession mergedSession = session1 + session2;
    cout << "Merged Session Duration: "
         << mergedSession.getDuration() << " minutes" << endl;

    return 0;
}