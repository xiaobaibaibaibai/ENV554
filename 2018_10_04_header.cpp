using namespace std;

int global_value = 100;//global varialbe
class ThreeD {//class
public:
	int ht;
	int wid;
	int dep;
	ThreeD() {}
	ThreeD(int i, int j, int k) { ht = i; wid = j; dep = k; }

};

void f1(int k) { cout << k; }//functions
