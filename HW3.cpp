//HW3
//Due: Saturday (10/6) at 11:59PM


#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

class course {
public:
	string name;
	int section;
	int credits;
	course() {}
	course(string n, int s, int c) {
        name = n;
        section = s;
        credits = c;
    }
	bool operator<(course c) {
        return (name < c.name);
    }
	bool operator==(course c) {
        return (name == c.name);
    }
};
//Implement the following function
//Please note that when visiting elements of vector, similar to HW2, you are required to use index (i.e., []) rather than using iterators.

void add_student(map<int, map<int, vector<course *> * > > &DB, int id);
void remove_student(map<int, map<int, vector<course *> * > > &DB, int id);
void add_course(map<int, map<int, vector<course *> * > > &DB, int semester, int id, course c); //20171 Spring semester of 2017; 20172: Fall semester of 2017
											   
void drop_course(map<int, map<int, vector<course *> * >> &DB, int semester, int id, course c);
void print_student_semester_courses(map<int, map<int, vector<course *> * >> &DB, int semester, int id);
void print_student_all_courses(map<int, map<int, vector<course *> * > > &DB, int id);
void print_DB(map<int, map<int, vector<course *> * > > &DB);

int main() {
//Do not change code for main function
	map<int, map<int, vector<course *> *> > DB;
	add_student(DB, 11111);
	course C1("CIS554", 1, 3), C2("CSE674", 1, 3), C3("MAT296", 8, 4), C4("WRT205", 5, 3);
    
	add_course(DB, 20171, 11111, C1);
    add_course(DB, 20171, 11111, C4);
	add_course(DB, 20171, 11111, C3);
	add_course(DB, 20171, 11111, C2);
    
	print_student_semester_courses(DB, 20171, 11111);
    
	drop_course(DB, 20171, 11111, C1);
	print_student_semester_courses(DB, 20171, 11111);

	add_course(DB, 20172, 11111, C2);
	add_course(DB, 20172, 11111, C4);
	add_course(DB, 20172, 11111, C3);
	add_course(DB, 20172, 11111, C1);
	print_student_all_courses(DB, 11111);

	add_student(DB, 11112);
	add_course(DB, 20171, 11112, C2);
	add_course(DB, 20171, 11112, C4);
	add_course(DB, 20171, 11112, C3);
	add_course(DB, 20171, 11112, C1);
	print_student_semester_courses(DB, 20171, 11112);

	add_course(DB, 20172, 11112, C2);
	add_course(DB, 20172, 11112, C4);
	add_course(DB, 20172, 11112, C3);
	add_course(DB, 20172, 11112, C1);
	print_student_semester_courses(DB, 20172, 11112);

	print_student_all_courses(DB, 11112);

	print_DB(DB);
	remove_student(DB, 11111);
	print_DB(DB);
    /*
	getchar();
	getchar();
    */
	return 0;
}

void add_student(map<int, map<int, vector<course *> * > > &DB, int id) {
    if (DB.find(id) != DB.end()) {
        return;
    }
    map<int, vector<course *> * > semester;
    DB.insert(make_pair(id, semester));
}

void remove_student(map<int, map<int, vector<course *> * > > &DB, int id) {
    if (DB.find(id) == DB.end()) {
        return;
    }
    DB.erase(id);
}

void add_course(map<int, map<int, vector<course *> * > > &DB, int semester, int id, course c) {
    if (DB.find(id) == DB.end()) {
        return;
    }
    auto student = DB.find(id);
    if ((student -> second).find(semester) == (student -> second).end()) {
        vector<course *> *v1 = new vector<course *>;
        course *temp = new course(c);
        v1 -> push_back(temp);
        (student -> second).insert(make_pair(semester, v1));
    } else {
        auto cur_semester = (student -> second).find(semester);
        for (int i = 0; i < (cur_semester -> second) -> size(); i++) {
            if ((*cur_semester -> second)[i] -> name == c.name) {
                cout << (*cur_semester -> second)[i] -> name << " exit" << endl;
                return;
            }
        }
        course *temp = new course(c);
        (*cur_semester -> second).push_back(temp);
    }
}

void drop_course(map<int, map<int, vector<course *> * > > &DB, int semester, int id, course c) {
    if (DB.find(id) == DB.end()) {
        return;
    }
    auto student = DB.find(id);
    if ((student -> second).find(semester) == (student -> second).end()) {
        cout << "not exit semester " << semester << endl;
        return;
    } else {
        auto cur_semester = (student -> second).find(semester);
        for (int i = 0; i < (cur_semester -> second) -> size(); i++) {
            // cout << (*cur_semester -> second)[i] -> name <<endl;
            if ((*cur_semester -> second)[i] -> name == c.name) {
                (*cur_semester -> second).erase((*cur_semester -> second).begin() + i);
                return;
            }
        }
        cout << "not exit course " << c.name << endl;
    }

}

void print_student_semester_courses(map<int, map<int, vector<course *> * > > &DB, int semester, int id) {
    cout << endl;
    if (DB.find(id) == DB.end()) {
        cout << "not exit student " << id << endl;
        return;
    }
    auto student = DB.find(id);
    if ((student -> second).find(semester) == (student -> second).end()) {
        cout << "not exit semester " << semester << endl;
        return;
    } else {
        cout << "student id = " << id << endl;
        cout << "semester = " << semester << endl;
        auto cur_semester = (student -> second).find(semester);
        for (int i = 0; i < (cur_semester -> second) -> size(); i++) {
            auto cur_course = (*cur_semester -> second)[i];
            cout << (*cur_course).name << " " << (*cur_course).section << " " << (*cur_course).credits << "  ";
        }
    }
    cout << endl;
}
void print_student_all_courses(map<int, map<int, vector<course *> * > > &DB, int id) {
    cout << endl;
    if (DB.find(id) == DB.end()) {
        cout << "not exit student " << id << endl;
        return;
    }
    cout << "student id = " << id << endl;
    auto student = DB.find(id);
    auto semesters = (student -> second).begin();
    while (semesters != (student -> second).end()) {
        cout << "semester = " << semesters -> first << endl;
        for (int i = 0; i < semesters -> second -> size(); i++) {
            auto cur_course = (*semesters -> second)[i];
            cout << (*cur_course).name << " " << (*cur_course).section << " " << (*cur_course).credits << "  ";
        }
        semesters++;
        cout << endl;
    }
    cout << endl;
}

void print_DB(map<int, map<int, vector<course *> * > > &DB) {
    cout << endl;
	auto students = DB.begin();
    while (students != DB.end()) {
        cout << "student id = " << students -> first << endl;
        auto semesters = (students -> second).begin();
        while (semesters != (students -> second).end()) {
            cout << "semester = " << semesters -> first << endl;
            for (int i = 0; i < semesters -> second -> size(); i++) {
                auto cur_course = (*semesters -> second)[i];
                cout << (*cur_course).name << " " << (*cur_course).section << " " << (*cur_course).credits << "  ";
            }
            semesters++;
            cout << endl;
        }
        students++;
    }
    cout << endl;
}

/*
//Sample Screenshot

student id = 11111
semester = 20171
CIS554 1 3  WRT205 5 3  MAT296 8 4  CSE674 1 3

student id = 11111
semester = 20171
WRT205 5 3  MAT296 8 4  CSE674 1 3

student id = 11111
semester = 20171
WRT205 5 3  MAT296 8 4  CSE674 1 3
semester = 20172
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3

student id = 11112
semester = 20171
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3

student id = 11112
semester = 20172
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3

student id = 11112
semester = 20171
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3
semester = 20172
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3

student id = 11111
semester = 20171
WRT205 5 3  MAT296 8 4  CSE674 1 3
semester = 20172
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3
student id = 11112
semester = 20171
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3
semester = 20172
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3

student id = 11112
semester = 20171
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3
semester = 20172
CSE674 1 3  WRT205 5 3  MAT296 8 4  CIS554 1 3
*/