#include <iostream>
#include <vector>
#include <string>

# define W "WORRY"
# define Q "QUIET"
# define W_C "WORRY_COUNT"
# define C "COME"

using namespace std;

class line_people{
    vector<int> line;
    int worry_count = 0;
public:
    void    worried_pers(int i){
        if (line[i] > 0){
            line[i] = -1;
            worry_count++;
        }
    }

    void    quiet_a_pers(int i){
        if (line[i] < 0){
            line[i] = 1;
            worry_count--;
        }
    }

    void    print_worry_count(){
        cout << worry_count << endl;
    }

    void    pers_push_back(int val){
        while (val-- > 0)
            line.push_back(1);
    }

    void    pers_pop_back(int val){
        while (val-- > 0){
            if (line[line.size() - 1] < 0)
                worry_count--;
            line.pop_back();
        }
    }
};


int    init_oper(const string& oper, const vector<string>& op_box, int& val)
{
    for (int i = 0; i < op_box.size(); i++)
        if (oper == op_box[i]){
            if (i == 3 && val < 0){
                val *= -1;
                return (5);
            }
            return (++i);
        }
    return (0);
}

void    changes(int in_op, int val)
{
    static line_people     line;
    if (in_op == 1)
        line.worried_pers(val);
    if (in_op == 2)
        line.quiet_a_pers(val);
    if (in_op == 3)
        line.print_worry_count();
    if (in_op == 4)
        line.pers_push_back(val);
    if (in_op == 5)
        line.pers_pop_back(val);
}

int main()
{
    vector<string>  oper_box = {W, Q, W_C, C};
    string          line;
    int             count_oper, in_op, val = 0;

    cin >> count_oper;
    for (int i = 1; i <= count_oper; i++){
        cin >> line;
        if (line != W_C)
            cin >> val;
        in_op = init_oper(line, oper_box, val);
        changes(in_op, val);
    }
    return 0;
}