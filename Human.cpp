#include "Human.h"

Human::Human()
{
    this->surname = "Неизвестно";
    this->name = "Неизвестно";
    this->patronymic = "Неизвестно";
}

Human::Human(const string& surname, const string& name, const string& patronymic)
{
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
}

string Human::getSurnameAndInitials() const
{
    string result = surname + " ";

    if (!name.empty() && name != "Неизвестно")
        result += name.substr(0, 1) + ".";
    else
        result += "?.";

    if (!patronymic.empty() && patronymic != "Неизвестно")
        result += patronymic.substr(0, 1) + ".";
    else
        result += "?";

    return result;
}


string Human::getFullName() const
{
    return surname + " " + name + " " + patronymic;
}