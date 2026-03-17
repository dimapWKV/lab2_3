#ifndef LABUBA3_STUDENT_H
#define LABUBA3_STUDENT_H

#include "Human.h"
#include <vector>

class Student: public Human
{
    private:
        vector<int> scores;

    public:
        Student();
        Student(const std::string& surname, const std::string& name, const std::string& patronymic,
                const std::vector<int>& scores);

        void addScore(int score);
        double getAverageScore() const;

        string getShortStudentInfo() const;
        string getFullStudentInfo() const;

        const std::vector<int>& getScores() const { return scores; }
};


#endif //LABUBA3_STUDENT_H