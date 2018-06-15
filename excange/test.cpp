#include <iostream>
#include <list>
 
using namespace std;

class masa {
private:
	string name;
	int age;
public:
	masa(string name,int age){
		this->name = name;
		this->age  =age;
	}
};
 
int main(){
    list<masa> li;
    li.push_back(masa("ohfuji1",12));    //  後ろにデータを挿入
    li.push_back(masa("ohfuji2",14));    //  後ろにデータを挿入
    li.push_front(masa("ohfuji3",15));   //  前にデータを挿入
    list<int>::iterator itr;
    //  データの挿入
    itr = li.begin();   //  イテレータを先頭に設定
    itr++;              //  一つ移動
    li.insert(itr,masa("ohfuji4",13));   //  値の挿入
    //  データの表示
    for (itr = li.begin(); itr != li.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}