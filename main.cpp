#include <iostream>
#include <vector>
#include <fstream>
#include <string>


#include "Figures.h"
#include "Circle.h"
#include "trapezoid.h"
#include "triangle.h"
#include "Rectangle.h"
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"
#include "Summator.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;


string doubleToString(double value)
{
    string result = to_string(value);
    size_t dotPos = result.find('.');
    if (dotPos != string::npos) {
        while (result.length() > dotPos + 2 && result.back() == '0')
            result.pop_back();
        if (result.back() == '.')
            result.pop_back();
    }
    return result;
}


double sumScores(const vector<int>& scores)
{
    double sum = 0;
    for (size_t i = 0; i < scores.size(); ++i)
        sum += scores[i];
    return sum;
}

void runUniversitySystem()
{
    cout << "UNIVERSITY MANAGEMENT SYSTEM\n" << endl;

    vector<Student> students;
    students.push_back(Student("Ivanov", "Ivan", "Ivanovich", {5, 4, 5, 4, 5}));
    students.push_back(Student("Petrov", "Petr", "Petrovich", {3, 3, 2, 4, 3}));
    students.push_back(Student("Sidorov", "Sidor", "Sidorovich", {2, 2, 3, 2, 2}));
    students.push_back(Student("Smirnov", "Alexey", "Alexeevich", {5, 5, 5, 5, 5, 5}));
    students.push_back(Student("Kuznetsov", "Dmitry", "Dmitrievich", {4, 4, 4, 4, 3}));
    students.push_back(Student("Popov", "Andrey", "Andreevich", {3, 3, 3, 3, 4}));
    students.push_back(Student("Vasiliev", "Vasily", "Vasilievich", {5, 5, 4, 5, 4, 5, 4}));
    students.push_back(Student("Zaitsev", "Mikhail", "Mikhailovich", {2, 3, 2, 2, 3}));
    students.push_back(Student("Volkov", "Sergey", "Sergeevich", {4, 5, 4, 5, 4, 5}));
    students.push_back(Student("Medvedev", "Denis", "Denisovich", {3, 4, 3, 4, 3}));

    vector<Teacher> teachers;
    teachers.push_back(Teacher("Ivanova", "Maria", "Ivanovna", Position::DOCENT, {"OS", "Databases", "Computer Science"}));
    teachers.push_back(Teacher("Petrov", "Vladimir", "Sergeevich", Position::PROFESSOR, {"Mathematics", "Physics", "Computer Science", "Programming"}));
    teachers.push_back(Teacher("Sidorova", "Elena", "Viktorovna", Position::ASSISTANT, {"English Language"}));
    teachers.push_back(Teacher("Kozlov", "Nikolai", "Petrovich", Position::SENIOR_LECTURER, {"History", "Philosophy"}));
    teachers.push_back(Teacher("Morozov", "Alexander", "Igorevich", Position::PROFESSOR, {"Physics", "Mathematics", "Mechanics", "Thermodynamics", "Quantum Physics"}));
    teachers.push_back(Teacher("Volkova", "Tatiana", "Alexandrovna", Position::DOCENT, {"Programming", "Algorithms", "Data Structures"}));
    teachers.push_back(Teacher("Sokolov", "Igor", "Vladimirovich", Position::DOCENT, {"Computer Science", "Computer Networks"}));
    teachers.push_back(Teacher("Mikhailov", "Anton", "Pavlovich", Position::SENIOR_LECTURER, {"Physical Education"}));
    teachers.push_back(Teacher("Fedorova", "Natalia", "Sergeevna", Position::PROFESSOR, {"Chemistry", "Biology", "Ecology"}));
    teachers.push_back(Teacher("Alekseev", "Viktor", "Nikolaevich", Position::DOCENT, {"Computer Science", "Web Programming", "JavaScript", "HTML/CSS"}));

    ofstream f1("students.txt");
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& s = students[i];
        f1 << s.getFullName() << endl;

        const vector<int>& scores = s.getScores();
        f1 << scores.size();
        for (size_t j = 0; j < scores.size(); ++j)
            f1 << " " << scores[j];
        f1 << endl;
    }
    f1.close();

    ofstream f2("teachers.txt");
    for (size_t i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        f2 << t.getFullName() << endl;
        f2 << static_cast<int>(t.getPosition()) << endl;

        const vector<string>& subjects = t.getSubjects();
        f2 << subjects.size() << endl;
        for (size_t j = 0; j < subjects.size(); ++j)
            f2 << subjects[j] << endl;
    }
    f2.close();

    cout << "Data saved to files\n" << endl;

    cout << "1) Students with average score > 4:" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& s = students[i];
        double avg = (s.getScores().empty()) ? 0 : sumScores(s.getScores()) / s.getScores().size();
        if (avg > 4.0) {
            cout << "   " << s.getSurnameAndInitials() << ": " << avg << endl;
        }
    }

    cout << "\n2) Students with average score < 3:" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& s = students[i];
        double avg = (s.getScores().empty()) ? 0 : sumScores(s.getScores()) / s.getScores().size();
        if (avg < 3.0) {
            cout << "   " << s.getSurnameAndInitials() << ": " << avg << endl;
        }
    }

    cout << "\n3) Student with the most grades:" << endl;
    size_t maxScores = 0;
    int bestStudentIndex = -1;
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].getScores().size() > maxScores) {
            maxScores = students[i].getScores().size();
            bestStudentIndex = i;
        }
    }
    if (bestStudentIndex != -1) {
        const Student& s = students[bestStudentIndex];
        cout << "   " << s.getFullName() << ": ";
        const vector<int>& scores = s.getScores();
        for (size_t j = 0; j < scores.size(); ++j) {
            cout << scores[j];
            if (j < scores.size() - 1) cout << " ";
        }
        double avg = sumScores(scores) / scores.size();
        cout << " – " << avg << endl;
    }

    cout << "\n4) Docent level teachers:" << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        if (t.getPosition() == Position::DOCENT) {
            cout << "   " << t.getSurnameAndInitials() << " docent: " << t.getSubjects().size() << endl;
        }
    }

    cout << "\n5) Professor with the most subjects:" << endl;
    size_t maxSubjects = 0;
    int bestProfessorIndex = -1;
    for (size_t i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        if (t.getPosition() == Position::PROFESSOR && t.getSubjects().size() > maxSubjects) {
            maxSubjects = t.getSubjects().size();
            bestProfessorIndex = i;
        }
    }
    if (bestProfessorIndex != -1) {
        const Teacher& t = teachers[bestProfessorIndex];
        cout << "   " << t.getFullName() << " professor: ";
        const vector<string>& subjects = t.getSubjects();
        for (size_t j = 0; j < subjects.size(); ++j) {
            cout << subjects[j];
            if (j < subjects.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    cout << "\n6) Teachers who teach Computer Science:" << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        const vector<string>& subjects = t.getSubjects();
        bool teachesCS = false;
        for (size_t j = 0; j < subjects.size(); ++j) {
            if (subjects[j] == "Computer Science") {
                teachesCS = true;
                break;
            }
        }
        if (teachesCS) {
            cout << "   " << t.getFullName() << " ";
            switch(t.getPosition()) {
                case Position::ASSISTANT: cout << "assistant"; break;
                case Position::SENIOR_LECTURER: cout << "senior lecturer"; break;
                case Position::DOCENT: cout << "docent"; break;
                case Position::PROFESSOR: cout << "professor"; break;
                default: cout << "Unknown";
            }
            cout << ": ";
            for (size_t j = 0; j < subjects.size(); ++j) {
                cout << subjects[j];
                if (j < subjects.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
}



void testEarlyBinding()
{
    Fish fish;
    std::cout << "\nFish:" << std::endl;
    fish.breathe();
    fish.eat();
    fish.swim();

    Bird bird;
    std::cout << "\nBird:" << std::endl;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    FlyingBird flyingBird;
    std::cout << "\nFlyingBird:" << std::endl;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
}

void task1()
{
    Figure* c = nullptr;

    int number;
    cin >> number;

    switch (number) {
    case 1:
        c = new Circle(3);
        break;

    case 2:
        c = new Trapezoid(2,2, 4);
        break;

    case 3:
        c = new Triangle(5, 7);
        break;

    case 4:
        c = new Rectangle(3, 4);
        break;
    }


    cout << c->to_string() << endl;
    cout << calc_cylinder_volume(c, 5) << endl;

    delete c;
}

void SummatorStart()
{
    Summator s;
    Summator& ref = s;

    SquareSummator ss;
    SquareSummator& refs = ss;

    CubeSummator cs;
    CubeSummator& refc = cs;



    int N = 5;

    cout << "Summa " << ref.sum(N) << endl;
    cout << "SquareSumma " << refs.sum(N) << endl;
    cout << "CubeSumma " << refc.sum(N) << endl;

}

int main() {
    int choice;

    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            task1();
            break;
        case 2:
            testEarlyBinding();
            break;
        case 3:
            runUniversitySystem();
            break;
        case 4:
            SummatorStart();
            break;
        }
    } while (choice != 0);

    return 0;
}