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
    li.push_back(masa("ohfuji1",12));    //  ���Ƀf�[�^��}��
    li.push_back(masa("ohfuji2",14));    //  ���Ƀf�[�^��}��
    li.push_front(masa("ohfuji3",15));   //  �O�Ƀf�[�^��}��
    list<int>::iterator itr;
    //  �f�[�^�̑}��
    itr = li.begin();   //  �C�e���[�^��擪�ɐݒ�
    itr++;              //  ��ړ�
    li.insert(itr,masa("ohfuji4",13));   //  �l�̑}��
    //  �f�[�^�̕\��
    for (itr = li.begin(); itr != li.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}