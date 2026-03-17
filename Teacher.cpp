#include "Teacher.h"
#include <sstream>

Teacher::Teacher() : Human(), position(Position::UNKNOWN) {}

Teacher::Teacher(const string& surname, const string& name, const string& patronymic,
                 Position position, const vector<string>& subjects)
    : Human(surname, name, patronymic), position(position), subjects(subjects) {}

string Teacher::positionToString() const
{
    switch (position)
    {
    case Position::ASSISTANT: return "ассистент";
    case Position::SENIOR_LECTURER: return "старший преподаватель";
    case Position::DOCENT: return "доцент";
    case Position::PROFESSOR: return "профессор";
    default: return "Неизвестно";
    }
}

void Teacher::addSubject(const string& subject)
{
    subjects.push_back(subject);
}

string Teacher::getShortTeacherInfo() const
{
    stringstream ss;
    ss << getSurnameAndInitials() << " " << positionToString() << ": " << subjects.size();
    return ss.str();
}

string Teacher::getFullTeacherInfo() const
{
    stringstream ss;
    ss << getFullName() << " " << positionToString() << ": ";

    for (size_t i = 0; i < subjects.size(); ++i)
    {
        ss << subjects[i];
        if (i < subjects.size() - 1) ss << ", ";
    }

    return ss.str();
}