//HW2
//Due: Wednesday (9/26) at 11:59pm

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

//Write code for the following five functions
//In both DB1_print and DB2_print, you are required to use index function (i.e., []) for vector, rather than iterator

void DB1_print(vector<list<list<string>>> &DB1);
void DB1_to_DB2(vector<list<list<string>>> &DB1, list<vector<list<string> * > *> &DB2);
void DB2_print(list<vector<list<string> * > *> &DB2);
void DB2_to_DB3(list<vector<list<string> * > *> &DB2, list < list<list<string *> * > > &DB3);
void DB3_print(list < list<list<string *> * > > &DB3);

int main() {
	vector<list<list<string>>> DB1 = {
		{ 
			{ "cat", "dog" },
			{ "duck", "chicken","pig" } 
		},
		{ 
			{ "lion", "tiger", "hyena", "leopard" },
			{ "Zebra", "elephant" },
			{ "buffalo" } 
		} 
	};
	
	DB1_print(DB1);
	list<vector<list<string> * > *> DB2;
	DB1_to_DB2(DB1, DB2);
	DB2_print(DB2);
	list < list<list<string *> * > > DB3;
	DB2_to_DB3(DB2, DB3);
	DB3_print(DB3);
	getchar();
	getchar();
	return 0;
}
void DB1_print(vector<list<list<string>>> &DB1) {
	//Your code
    for (size_t i = 0; i < DB1.size(); i++) {
        auto it1 = DB1[i].begin();
        while (it1 != DB1[i].end()) {
            auto it2 = it1 -> begin();
            while (it2 != it1 -> end()) {
                cout << *it2 << " ";
                it2++;
            }
            it1++;
            cout << endl;
        }
        cout << endl;
    }
	cout << endl;
}

void DB1_to_DB2(vector<list<list<string>>> &DB1, list<vector<list<string> * > *> &DB2) {
	//Your code
	for (size_t i = 0; i < DB1.size(); i++) {
		vector<list<string> * > *V1 = new vector<list<string> * >;
        auto it1 = DB1[i].begin();
        while (it1 != DB1[i].end()) {
			list<string> *l1 = new list<string>;
            auto it2 = it1 -> begin();
            while (it2 != it1 -> end()) {
				l1 -> push_back(*it2);
                it2++;
            }
			V1 -> push_back(l1);
            it1++;
        }
        DB2.push_back(V1);
    }
}

void DB2_print(list<vector<list<string> * > *> &DB2) {
	//Your code
	auto it1 = DB2.begin();
	while (it1 != DB2.end()) {
		for (size_t i = 0; i < (*it1) -> size(); i++) {
			auto it2 = (**it1)[i] -> begin();
			while (it2 != (**it1)[i] -> end()) {
				cout << *it2 << " ";
				it2++;
			}
			cout << endl;
		}
		it1++;
		cout << endl;
	}
	cout << endl;
}

void DB2_to_DB3(list<vector<list<string> * > *> &DB2, list < list<list<string *> * > > &DB3) {
	//Your code
	auto it1 = DB2.begin();
	while (it1 != DB2.end()) {
		list<list<string *> * > l1;
		for (size_t i = 0; i < (*it1) -> size(); i++) {
			list<string *> *l2 = new list<string *>;
			auto it2 = (**it1)[i] -> begin();
			while (it2 != (**it1)[i] -> end()) {
				string *s = new string(*it2);
				l2 -> push_back(s);
				it2++;
			}
			l1.push_back(l2);
		}
		DB3.push_back(l1);
		it1++;
	}
}
void DB3_print(list < list<list<string *> * > > &DB3) {
	//Your code
	auto it1 = DB3.begin();
	while (it1 != DB3.end()) {
		auto it2 = it1 -> begin();
		while (it2 != it1 -> end()) {
			auto it3 = (*it2) -> begin();
			while (it3 != (*it2) -> end()) {
				cout << **it3 << " ";
				it3++;
			}
			it2++;
			cout << endl;
		}
		it1++;
		cout << endl;
	}
}

//The following is a sample screenshot
//Your output needs to folloiwng idential format
/*

cat dog
duck chicken pig

lion tiger hyena leopard
Zebra elephant
buffalo


cat dog
duck chicken pig

lion tiger hyena leopard
Zebra elephant
buffalo


cat dog
duck chicken pig

lion tiger hyena leopard
Zebra elephant
buffalo
*/