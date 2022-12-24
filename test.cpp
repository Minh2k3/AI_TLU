#include <iostream>
using namespace std;

class coso{
	public:
	coso(){}
	~coso(){cout << "1";}
};

class danxuat:coso{
	public:
		danxuat(){}
		~danxuat(){cout << 2;}
};

int main(){
	danxuat d;
}
