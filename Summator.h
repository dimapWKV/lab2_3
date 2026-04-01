#ifndef LABUBA3_SUMMATOR_H
#define LABUBA3_SUMMATOR_H

#include <iostream>
#include <vector>

using namespace std;

class Summator
{
    protected:
    vector<int> sequence;

    public:
    virtual ~Summator() = default;
    Summator();

    virtual int transform(int *n);

    int sum(int n);

};

class SquareSummator : public Summator
{
public:
    int transform(int *n) override;
};

class CubeSummator : public Summator
{
public:
    int transform(int *n) override;
};

#endif //LABUBA3_SUMMATOR_H