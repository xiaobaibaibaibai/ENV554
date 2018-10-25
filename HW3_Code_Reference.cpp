//HW3

//By C-Y (Roger) Chen
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
	course(string n, int s, int c) { name = n; section = s; credits = c; }
	bool operator<(course c) { return (name < c.name); }
	bool operator==(course c) { return (name == c.name); }
};
void add_student(map<int, map<int, vector<course *> * > > &DB, int id);
void remove_student(map<int, map<int, vector<course *> * > > &DB, int id);
void add_course(map<int, map<int, vector<course *> * > > &DB, int semester, int id, course c); //20171 Spring semester of 2017; 20172: Fall semester of 2017
																							   //All courses in the list should be sorted according to name (increasing order)
void drop_course(map<int, map<int, vector<course *> * >> &DB, int semester, int id, course c);
void print_student_semester_courses(map<int, map<int, vector<course *> * >> &DB, int semester, int id);
void print_student_all_courses(map<int, map<int, vector<course *> * > > &DB, int id);
void print_DB(map<int, map<int, vector<course *> * > > &DB);

int main() {
	map<int, map<int, vector<course *> *> > DB;
	add_student(DB, 11111);
	course C1("CIS554", 1, 3), C2("CSE674", 1, 3), C3("MAT296", 8, 4), C4("WRT205", 5, 3);
	course test1("abc", 1, 1), test2("abcd", 1, 1), test3("abce", 1, 1);


	// cout << (1==1) << endl;
	// cout << (2 < 1) << endl;
	// cout << (test1==test2) << endl;
	// cout << (test1 < test2) << endl;
	// cout << (test2 < test3) << endl;
	

	add_course(DB, 20171, 11111, C1);
	add_course(DB, 20171, 11111, C4);
	add_course(DB, 20171, 11111, C3);
	add_course(DB, 20171, 11111, C2);
	add_course(DB, 20171, 11111, C1);
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
	if (DB.find(id) != DB.end()) return;
	map<int, vector<course *>*> M;
	DB[id] = M;

}

void remove_student(map<int, map<int, vector<course *> * > > &DB, int id) {
	if (DB.size() == 0) return;
	if (DB.find(id) == DB.end()) return;
	if (DB[id].size() == 0) { DB.erase(id); return; }
	// map<int, vector<course *> *>::iterator it1 = DB[id].begin();
	auto it1 = DB[id].begin();
	while (it1 != DB[id].end()) {
		if (it1->second->size() != 0) {
			// list<course *>::iterator it2 = it1->second->begin();
			// list<course *>::iterator it3;
			auto it2 = it1->second->begin();
			while (it2 != it1->second->end()) {
				delete *it2;
				it2++;
			}
			// for (size_t i = 0; i< it1->second->size(); i++) {
			// 	delete ((*(it1->second))[i]);
			// }
			it1->second->clear();
		}
		delete(it1->second);
		it1++;
	}

	DB.erase(id);
}

void add_course(map<int, map<int, vector<course *> * > > &DB, int semester, int id, course c) {

	if (DB.find(id) == DB.end()) return;

	if (DB[id].size() == 0 || DB[id].find(semester) == DB[id].end()) {
		(DB[id])[semester] = new vector <course *>;

		(DB[id])[semester]->push_back(new course(c));
		return;
	}

	else {
		int found = 0;
		vector<course *>::iterator it1 = (DB[id])[semester]->begin();
		for (size_t i = 0; i < DB[id][semester]->size(); i++) {
			if (*((*(DB[id][semester]))[i]) == c) found = 1;
		}
		if (found == 1) return;
		DB[id][semester]->push_back(new course(c));

		//DB[id][semester]->sort();
	}
}

void drop_course(map<int, map<int, vector<course *> * > > &DB, int semester, int id, course c) {

	if (DB.find(id) == DB.end()) return;
	if (DB[id].size() == 0) return;
	if (DB[id].find(semester) == DB[id].end()) return;
	for (size_t i = 0; i < DB[id][semester]->size(); i++) {
		if (*((*(DB[id][semester]))[i]) == c) {
			delete (*(DB[id][semester]))[i];
			DB[id][semester]->erase(DB[id][semester]->begin() + i);
			break;
		}

	}
}

void print_student_semester_courses(map<int, map<int, vector<course *> * > > &DB, int semester, int id) {
	cout << endl;
	if (DB.size() == 0) return;
	if (DB.find(id) == DB.end()) return;
	if (DB[id].find(semester) == DB[id].end()) return;
	cout << "student id = " << id << endl;

	if (DB[id][semester]->size() != 0) {
		cout << "semester = " << semester << endl;
		for (size_t i = 0; i < DB[id][semester]->size(); i++) {
			cout << (*(DB[id][semester]))[i]->name << " " << (*(DB[id][semester]))[i]->section << " " << (*(DB[id][semester]))[i]->credits << "  ";
		}
		cout << endl;
	}

}
void print_student_all_courses(map<int, map<int, vector<course *> * > > &DB, int id) {
	cout << endl;
	if (DB.size() == 0) return;
	if (DB.find(id) == DB.end()) return;
	map<int, vector<course *> *>::iterator it1 = DB[id].begin();
	cout << "student id = " << id << endl;
	while (it1 != DB[id].end()) {




		//list<course *>::iterator it2 = it1->second->begin();
		cout << "semester = " << it1->first << endl; ;
		for (size_t i = 0; i < it1->second->size(); i++) {
			cout << (*(it1->second))[i]->name << " " << (*(it1->second))[i]->section << " " << (*(it1->second))[i]->credits << "  ";

		}


		cout << endl;
		it1++;
	}
}

void print_DB(map<int, map<int, vector<course *> * > > &DB) {
	cout << endl;
	if (DB.size() == 0) return;
	map<int, map<int, vector<course *> *> >::iterator it1 = DB.begin();

	while (it1 != DB.end()) {
		if (it1->second.size() != 0) {

			cout << "student id = " << it1->first << endl;

			map<int, vector<course *> *>::iterator it2 = it1->second.begin();
			while (it2 != it1->second.end()) {
				if (it2->second->size() != 0) {
					cout << "semester = " << it2->first << endl;

					for (size_t i = 0; i < it2->second->size(); i++) {

						cout << (*(it2->second))[i]->name << " " << (*(it2->second))[i]->section << " " << (*(it2->second))[i]->credits << "  ";

					}
					cout << endl;
				}
				it2++;
			}
		}
		it1++;
	}
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
