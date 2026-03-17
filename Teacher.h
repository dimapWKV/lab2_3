#ifndef TEACHER_H
#define TEACHER_H

#include "Human.h"
#include <vector>
#include <string>

enum class Position
{
    ASSISTANT,
    SENIOR_LECTURER,
    DOCENT,
    PROFESSOR,
    UNKNOWN
};

class Teacher : public Human
{
private:
    Position position;
    vector<string> subjects;

    string positionToString() const;

public:
    Teacher();
    Teacher(const string& surname, const string& name, const string& patronymic,
            Position position, const vector<string>& subjects);

    void addSubject(const string& subject);
    string getShortTeacherInfo() const;
    string getFullTeacherInfo() const;

    Position getPosition() const { return position; }
    const vector<string>& getSubjects() const { return subjects; }
};

#endif