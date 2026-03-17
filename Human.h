#ifndef LABUBA3_HUMAN_H
#define LABUBA3_HUMAN_H

#include <string>

using namespace std;

class Human
{
    protected:
        string surname;
        string name;
        string patronymic;
    public:
        Human();
        Human(const string& surname, const string& name, const string& patronymic);
        virtual ~Human() {}
    
        string getSurnameAndInitials() const;
        string getFullName() const;
};


#endif //LABUBA3_HUMAN_H