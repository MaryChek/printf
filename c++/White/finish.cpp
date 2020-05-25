#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <system_error>

# define A "Add"
# define D "Del"
# define F "Find"
# define P "Print"

// - добавление события: Add Дата Событие
// - удаление события: Del Дата Событие
// - удаление всех событий за конкретную дату: Del Дата
// - поиск событий за конкретную дату: Find Дата
// - печать всех событий за все даты: Print

using namespace std;

void NsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '-')
        throw runtime_error("Wrong date format: " + date)
    stream.ignore(1);
}
class Date {
public:
    void DateParsing(const string& new_date) {
        date = new_date;
        stringstream stream(new_date);
        stream >> year;
        NsureNextSymbolAndSkip(stream);
        stream >> month;
        EnsureTheMonthIsCorrect();
        NsureNextSymbolAndSkip(stream);
        stream >> day;
        EnsureTheDayIsCorrect();
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
    void PrintData() {
        
    }
private:
    int day, month, year;
    string date;
    void EnsureTheMonthIsCorrect() {
        if (month < 1 || month > 12)
            throw runtime_error("Month value is invalid: " + to_string(month));
    }
    void EnsureTheDayIsCorrect() {
        if (day < 1 || day > 12)
            throw runtime_error("Day value is invalid: " + to_string(day));
    }
};

class Database {
public:
void AddEvent(const Date& date, const string& event) {
    db[date].insert(event);
}
bool DeleteEvent(const Date& date, const string& event) {
    if (db.count(date) && db[date].count(event)) {
        db[date].erase(event);
        return true;
    }
    return false;
}
int DeleteDate(const Date& date) {
    int count = 0;
    if (db.count(date)) {
        count = db[date].size();
        db.erase(date);
    }
    return count;
}
void    Find(const Date& date) const {

}    
void Print() const {
    if (db.size()) {
        for (auto& data : db)
            for (auto& event : db.second)

    }
}
private:
    map<Date, set<string>> db;
};

bool ParsDate(stringstream& str, DateAndEvent& info) {
    Date date;
    string new_date;
    str >> new_date >> info.event;
    info.date = date;
    if (info.event.empty())
        return false;
    try {
        date.DateParsing(new_date);
    } catch(runtime_error& e) {
        cout << e.what();
    }
    return true;
}

struct DateAndEvent {
    Date date;
    string event;
};

bool operator<(const Date& lhs, const Date& rhs);

int main() {
    Database db;
    string command;

    while (getline(cin, command)) {
        stringstream str(command);
        string oper;
        str >> oper;
        if (oper == A) {
            DateAndEvent info;
                ParsDate(str, info))
            db.AddEvent(info.date, info.event);
        }
        else if (oper == D) {
            DateAndEvent info;
            if (ParsDate(str, info)) {
                if (db.DeleteEvent(info.date, info.event))
                    cout << "Deleted successfully" << endl;
                else
                    cout << "Event not found" << endl;
            } else
            cout << "Deleted " << db.DeleteDate(info.date) << " events" << endl;
        }
        else if (oper == F) {
            
        }
        else if (oper == P) {
            
        }
        else
            cout << "Unknown command: " << oper << endl;
    }
    return 0;
}