#include <iostream>
#include <memory> //for smart pointers
using namespace std;
struct ThreeD {
	int ht;
	int wid;
	int dep;
	ThreeD(int i, int j, int k) { ht = i, wid = j; dep = k; }
	ThreeD() {}
};

int main() {
/*
	//unique_ptr
	int * p3 = new int(10);
	{
		unique_ptr<ThreeD> p1 = make_unique<ThreeD>(3, 4, 5);
		cout << p1->ht << endl;
		//unique_ptr<ThreeD> p2 = p1; Error!  object is uniquely pointed by p1
		unique_ptr<int> p4 = make_unique<int>(40);
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

			//reference count = 2: p5, p6
		}

		//reference count = 1: p6

	}
	//reference count = 0;
	//the object pointed by p5 will be deleted automatically
	//cout << *p7 << endl;  Error! 
	//weak_ptr does not affect object reference count


	if (!p7.expired()) {//p7 is pointing to an object which is not deleted.

	}

	weak_ptr<ThreeD> p10 = make_shared<ThreeD>(4, 5, 6);
	//cout << p10->ht << endl;  Error!  The reference count = 0
	//object has expired.
	shared_ptr<ThreeD> p11 = make_shared<ThreeD>(4, 5, 6);
	cout << p11->ht << endl;
	p10 = p11;
*/
	shared_ptr<int> sp1 = make_shared<int>(5);
	//reset funciton
	sp1.reset(new int(20));//sp1 points to the new object with value 20
	//the object with value 5 will be removed (ref count = 0)

	sp1.reset();//sp1 will become empty; the object with value 20 will be removed.

	int * p1 = new int(30);
	delete p1;
	p1 = nullptr;

	sp1.reset(new int(100));
	weak_ptr<int> wp1 = sp1;
	cout << "sp1 : " << *sp1 << endl;
	//cout << *wp1 << endl; Error!  weak_ptr does not support -> * 

	shared_ptr<int> sp2;
	weak_ptr<int> wp2;
	wp2 = wp1;
	//sp2 = wp1; YOu are not allowed to assign weak_ptr to shared_ptr
	sp2 = wp1.lock();//type casting weak_ptr to shared_ptr
	wp2.reset();//only allow to reset to empty
    cout << "sp2 : " << *sp2 << endl;

	cout << "wp1 : " << *(wp1.lock()) << endl;
	shared_ptr<ThreeD> sp3 = make_shared<ThreeD>(3, 4, 5);
	weak_ptr<ThreeD> wp4 = sp3;

	cout << "sp3->ht : " << sp3->ht << endl;
	cout<< "wp4->ht : "  << (wp4.lock())->ht << endl;


}