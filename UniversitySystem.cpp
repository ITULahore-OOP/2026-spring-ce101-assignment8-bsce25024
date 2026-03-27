#include "UniversitySystem.h"

// ===== UniversityMember =====
UniversityMember::UniversityMember(string name, int memberID)
{
    this->name = name;
    this->memberID = memberID;
}

UniversityMember::~UniversityMember() {}

string UniversityMember::getName()
{
    return name;
}

int UniversityMember::getMemberID()
{
    return memberID;
}

// ===== AccessCard =====
AccessCard::AccessCard(string cardID, int accessLevel)
{
    this->cardID = cardID;
    this->accessLevel = accessLevel;
}

string AccessCard::getCardID()
{
    return cardID;
}

int AccessCard::getAccessLevel()
{
    return accessLevel;
}

void AccessCard::displayCardInfo()
{
    cout << "Card ID: " << cardID << " Access Level: " << accessLevel << endl;
}

// ===== Student =====
Student::Student(string name, int memberID, double cgpa)
    : UniversityMember(name, memberID)
{
    this->cgpa = cgpa;
}

double Student::getCGPA()
{
    return cgpa;
}

void Student::updateCGPA(double newCGPA)
{
    cgpa = newCGPA;
}

void Student::displayRole()
{
    cout << "Role: Student" << endl;
}

// ===== Staff =====
Staff::Staff(string name, int memberID, double salary, AccessCard card)
    : UniversityMember(name, memberID), card(card)
{
    this->salary = salary;
}

double Staff::getSalary()
{
    return salary;
}

void Staff::displayRole()
{
    cout << "Role: Staff" << endl;
}

void Staff::displayCard()
{
    card.displayCardInfo();
}

// ===== TeachingAssistant =====
TeachingAssistant::TeachingAssistant(string name, int memberID, double cgpa,
                                     double salary, AccessCard card, int workingHours)
    : UniversityMember(name, memberID),
      Student(name, memberID, cgpa),
      Staff(name, memberID, salary, card)
{
    this->workingHours = workingHours;
}

void TeachingAssistant::displayRole()
{
    cout << "Role: Teaching Assistant" << endl;
}

void TeachingAssistant::gradeAssignment(int score)
{
    cout << "Graded assignment with numeric score: " << score << "/100" << endl;
}

void TeachingAssistant::gradeAssignment(string letterGrade)
{
    cout << "Graded assignment with letter grade: " << letterGrade << endl;
}

// ===== TutoringSession =====
TutoringSession::TutoringSession(int sessionID, double durationMinutes,
                                 TeachingAssistant* ta, Student* student)
{
    this->sessionID = sessionID;
    this->durationMinutes = durationMinutes;
    this->ta = ta;
    this->student = student;
}

double TutoringSession::getDuration()
{
    return durationMinutes;
}

void TutoringSession::displaySession()
{
    cout << "Session ID: " << sessionID
         << " Duration: " << durationMinutes << endl;
}

TutoringSession TutoringSession::operator+(const TutoringSession& other)
{
    return TutoringSession(0, durationMinutes + other.durationMinutes, ta, student);
}

bool operator>(TutoringSession s1, TutoringSession s2)
{
    return s1.durationMinutes > s2.durationMinutes;
}

// ===== Department =====
Department::Department(string departmentName)
{
    this->departmentName = departmentName;
    memberCount = 0;
}

void Department::addMember(UniversityMember* member)
{
    members[memberCount++] = member;
}

void Department::displayAllRoles()
{
    for (int i = 0; i < memberCount; i++)
    {
        members[i]->displayRole();
    }
}