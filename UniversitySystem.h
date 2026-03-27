#ifndef UNIVERSITYSYSTEM_H
#define UNIVERSITYSYSTEM_H

#include <iostream>
#include <string>
using namespace std;

// ================= UniversityMember =================
class UniversityMember
{
protected:
    string name;
    int memberID;

public:
    UniversityMember(string name, int memberID);
    virtual ~UniversityMember();

    string getName();
    int getMemberID();

    virtual void displayRole() = 0;
};

// ================= AccessCard =================
class AccessCard
{
private:
    string cardID;
    int accessLevel;

public:
    AccessCard(string cardID = "", int accessLevel = 0);

    string getCardID();
    int getAccessLevel();
    void displayCardInfo();
};

// ================= Student =================
class Student : virtual public UniversityMember
{
private:
    double cgpa;

public:
    Student(string name, int memberID, double cgpa);

    double getCGPA();
    void updateCGPA(double newCGPA);

    void displayRole() override;
};

// ================= Staff =================
class Staff : virtual public UniversityMember
{
private:
    double salary;
    AccessCard card;

public:
    Staff(string name, int memberID, double salary, AccessCard card);

    double getSalary();
    void displayRole() override;
    void displayCard();
};

// ================= TeachingAssistant =================
class TeachingAssistant : public Student, public Staff
{
private:
    int workingHours;

public:
    TeachingAssistant(string name, int memberID, double cgpa,
                      double salary, AccessCard card, int workingHours);

    void displayRole() override;

    void gradeAssignment(int score);
    void gradeAssignment(string letterGrade);
};

// ================= TutoringSession =================
class TutoringSession
{
private:
    int sessionID;
    double durationMinutes;
    TeachingAssistant* ta;
    Student* student;

public:
    TutoringSession(int sessionID, double durationMinutes,
                    TeachingAssistant* ta, Student* student);

    double getDuration();
    void displaySession();

    TutoringSession operator+(const TutoringSession& other);
    friend bool operator>(TutoringSession s1, TutoringSession s2);
};

// ================= Department =================
class Department
{
private:
    string departmentName;
    UniversityMember* members[50];
    int memberCount;

public:
    Department(string departmentName);

    void addMember(UniversityMember* member);
    void displayAllRoles();
};

#endif