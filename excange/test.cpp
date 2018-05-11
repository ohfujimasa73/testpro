#include <iostream>
#include <string>
using namespace std;

class masa{
private:
	int age;
public:
	masa(int input){
		this->age;
	}
	
	int getage(){
		return this->age;
	}
	
};

int main(){
	
	masa test(12);
	
	cout << test.getage() << endl;
	return 0;
}