

/*

weak_ptr = weak_ptr;

weak_ptr = shared_ptr;

shared_ptr = weak_ptr.lock();
weak_ptr.lock()-> ....
*(weak_ptr.lock())


if (!weak_ptr.expired()) //check to see if it is empty
if (weak_ptr == nullptr) //error

shared_ptr = nullptr; //ok
shared_ptr.reset(); //preferred
shared_ptr.reset(new int(4));//ok


weak_ptr = nullptr; //error
weak_ptr.reset(); //correct


if (shared_ptr != nullptr) //ok
if (shared_ptr) //preferred


int * p1 = new int(9);
shared_ptr<int> p2(p1);

int * p3;
...
if (p3 == p2.get()) ....

if p1 and p2 are both shared_ptr<int>,
we can swap the two:
p1.swap(p2);


*/



