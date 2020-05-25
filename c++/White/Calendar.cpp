#include <iostream>
#include <vector>
#include <string>

# define A "ADD"
# define N "NEXT"
# define D "DUMP"

using namespace std;

void    init_months(vector<string>& calendar, int i)
{
        if (i == 0)
            calendar.resize(28);
        else if ((i < 6 && i % 2 != 0) || (i >= 8 && i % 2 == 0))
            calendar.resize(30);
        else 
            calendar.resize(31);
}

void    next_month(vector<string>& calendar, int size, int month)
{
    vector<string> tmp;
    if (month == 0){
        tmp.insert(end(tmp), end(calendar) - 3, end(calendar));
        init_months(calendar, 0);
    }
    else ((month < 6 && month % 2 != 0)
    || (month >= 8 && month % 2 == 0))
    else
}

void    print_plans(const vector<string>& day)
{
    cout << day.size();
    if (!day.empty)
        for (auto &a : day)
            cout << " " << a;
    cout << endl;
}

int main()
{
    vector<string> calendar(12);
    string  oper, plan;
    int     oper_count, day, month = 0;

    init_months(calendar, month);
    cin >> oper_count;
    for (int i = 0; i < oper_count; i++){
        if ((cin >> oper) == A){
            cin >> day >> plan;
            calendar[day - 1].push_back(plan);
        }
        else if (oper == D){
            cin >> day;
            print_plans(calendar[day - 1]);
        }
        else if (oper == N)
            next_month(calendar, calendar.size(), ++month)
        }
    }
    return 0;
}