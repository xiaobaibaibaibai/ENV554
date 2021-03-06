#include <iostream>
#include <memory>
using namespace std;
struct ThreeD {
	int ht;
	int wid;
	int dep;
	ThreeD(int i, int j, int k) { ht = i, wid = j; dep = k; }
	ThreeD() {}
};

int main() {
	//unique_ptr
	int * p3 = new int(10);
	{
		unique_ptr<ThreeD> p1 = make_unique<ThreeD>(3, 4, 5);
		cout << p1->ht << endl;
		//unique_ptr<ThreeD> p2 = p1; Error!  object is uniquely pointed by p1
		auto p4 = make_unique<int>(40);
		cout << *p4 << endl;
	}
	//The objected pointed by p1 will be automatically deleted once p1 is out of scope

	weak_ptr<int> p7;
	{
		shared_ptr<int> p6;
		{
			shared_ptr<int> p5 = make_shared<int>(5);
			p6 = p5;
			p7 = p5;
            cout << "count number is " << p7.use_count() << endl;
			//reference count = 2: p5, p6
		}
        cout << "count number is " << p7.use_count() << endl;
		//reference count = 1: p6
	}
    cout << "count number is " << p7.use_count() << endl;
	//reference count = 0;
	//the object pointed by p5 will be deleted automatically
	//cout << *p7 << endl;  Error! 
	//weak_ptr does not affect object reference count

	

	if (p7.expired()) {//p7 is pointing to an object which is not deleted.
        cout << "p7 is expired" << endl;
	}

	weak_ptr<ThreeD> p10 = make_shared<ThreeD>(4, 5, 6);
	//cout << p10->ht << endl;  Error!  The reference count = 0
	//object has expired.
	shared_ptr<ThreeD> p11 = make_shared<ThreeD>(4, 5, 6);
	cout << p11->ht << endl;

	// 只要week point is not to an object which is not deleted, week point will not expire.
	p10 = p11;
	if (!p10.expired()) {
		cout << "p10 is not expired" << endl;
	}

}