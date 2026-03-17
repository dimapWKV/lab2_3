#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>

#include "Figures.h"
#include "Circle.h"
#include "trapezoid.h"
#include "triangle.h"

#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"

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
    cout << "СИСТЕМА УПРАВЛЕНИЯ УНИВЕРСИТЕТОМ\n" << endl;

    vector<Student> students;
    students.push_back(Student("Иванов", "Иван", "Иванович", {5, 4, 5, 4, 5}));
    students.push_back(Student("Петров", "Петр", "Петрович", {3, 3, 2, 4, 3}));
    students.push_back(Student("Сидоров", "Сидор", "Сидорович", {2, 2, 3, 2, 2}));
    students.push_back(Student("Смирнов", "Алексей", "Алексеевич", {5, 5, 5, 5, 5, 5}));
    students.push_back(Student("Кузнецов", "Дмитрий", "Дмитриевич", {4, 4, 4, 4, 3}));
    students.push_back(Student("Попов", "Андрей", "Андреевич", {3, 3, 3, 3, 4}));
    students.push_back(Student("Васильев", "Василий", "Васильевич", {5, 5, 4, 5, 4, 5, 4}));
    students.push_back(Student("Зайцев", "Михаил", "Михайлович", {2, 3, 2, 2, 3}));
    students.push_back(Student("Волков", "Сергей", "Сергеевич", {4, 5, 4, 5, 4, 5}));
    students.push_back(Student("Медведев", "Денис", "Денисович", {3, 4, 3, 4, 3}));

    vector<Teacher> teachers;
    teachers.push_back(Teacher("Иванова", "Мария", "Ивановна", Position::DOCENT, {"ОС", "Базы данных", "Информатика"}));
    teachers.push_back(Teacher("Петров", "Владимир", "Сергеевич", Position::PROFESSOR, {"Математика", "Физика", "Информатика", "Программирование"}));
    teachers.push_back(Teacher("Сидорова", "Елена", "Викторовна", Position::ASSISTANT, {"Английский язык"}));
    teachers.push_back(Teacher("Козлов", "Николай", "Петрович", Position::SENIOR_LECTURER, {"История", "Философия"}));
    teachers.push_back(Teacher("Морозов", "Александр", "Игоревич", Position::PROFESSOR, {"Физика", "Математика", "Механика", "Термодинамика", "Квантовая физика"}));
    teachers.push_back(Teacher("Волкова", "Татьяна", "Александровна", Position::DOCENT, {"Программирование", "Алгоритмы", "Структуры данных"}));
    teachers.push_back(Teacher("Соколов", "Игорь", "Владимирович", Position::DOCENT, {"Информатика", "Компьютерные сети"}));
    teachers.push_back(Teacher("Михайлов", "Антон", "Павлович", Position::SENIOR_LECTURER, {"Физкультура"}));
    teachers.push_back(Teacher("Федорова", "Наталья", "Сергеевна", Position::PROFESSOR, {"Химия", "Биология", "Экология"}));
    teachers.push_back(Teacher("Алексеев", "Виктор", "Николаевич", Position::DOCENT, {"Информатика", "Web-программирование", "JavaScript", "HTML/CSS"}));


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

    cout << "Данные сохранены в файлы\n" << endl;


    cout << "1) Студенты со средним баллом > 4:" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& s = students[i];
        double avg = (s.getScores().empty()) ? 0 : sumScores(s.getScores()) / s.getScores().size();
        if (avg > 4.0) {
            cout << "   " << s.getSurnameAndInitials() << ": " << avg << endl;
        }
    }

    cout << "\n2) Студенты со средним баллом < 3:" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        const Student& s = students[i];
        double avg = (s.getScores().empty()) ? 0 : sumScores(s.getScores()) / s.getScores().size();
        if (avg < 3.0) {
            cout << "   " << s.getSurnameAndInitials() << ": " << avg << endl;
        }
    }

    cout << "\n3) Студент с наибольшим количеством оценок:" << endl;
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

    cout << "\n4) Доценты:" << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        if (t.getPosition() == Position::DOCENT) {
            cout << "   " << t.getSurnameAndInitials() << " доцент: " << t.getSubjects().size() << endl;
        }
    }

    cout << "\n5) Профессор с наибольшим количеством предметов:" << endl;
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
        cout << "   " << t.getFullName() << " профессор: ";
        const vector<string>& subjects = t.getSubjects();
        for (size_t j = 0; j < subjects.size(); ++j) {
            cout << subjects[j];
            if (j < subjects.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    cout << "\n6) Преподаватели, ведущие информатику:" << endl;
    for (size_t i = 0; i < teachers.size(); ++i) {
        const Teacher& t = teachers[i];
        const vector<string>& subjects = t.getSubjects();
        bool teachesInformatics = false;
        for (size_t j = 0; j < subjects.size(); ++j) {
            if (subjects[j] == "Информатика") {
                teachesInformatics = true;
                break;
            }
        }
        if (teachesInformatics) {
            cout << "   " << t.getFullName() << " ";
            switch(t.getPosition()) {
                case Position::ASSISTANT: cout << "ассистент"; break;
                case Position::SENIOR_LECTURER: cout << "старший преподаватель"; break;
                case Position::DOCENT: cout << "доцент"; break;
                case Position::PROFESSOR: cout << "профессор"; break;
                default: cout << "Неизвестно";
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
        // c = new Rectangle(3, 4);
        break;
    }


    cout << c->to_string() << endl;
    cout << calc_cylinder_volume(c, 5) << endl;

    delete c;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

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
        }
    } while (choice != 0);

    return 0;
}