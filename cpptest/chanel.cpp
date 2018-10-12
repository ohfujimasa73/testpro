#include <iostream>
#include <string>

#define ABCCHAN "0"
#define DEFCHAN "1"
#define OFFCHAN "OFF"

class CHANNEL {
private:
	std::string name;
public:
	CHANNEL(std::string input){
		this->name = input;
	}
	std::string get_name(){
		return this->name;
	}
	
};

class ABC : public CHANNEL {
public:
	ABC():CHANNEL("ABC局"){}
};

class DEF : public CHANNEL {
public:
	DEF():CHANNEL("DEF局"){}
};


class TV {
private:
	ABC abc;
	DEF def;
public:
	TV(){
		std::cout << "スイッチON\n";
	}
	
	~TV(){
		std::cout << "スイッチOFF\n";
	}
	void change_channel(){
		std::cout << "チャンネル入力 [ 0 or 1 or off ] : ";
		std::string input;
		std::cin >> input;
		if(input == ABCCHAN){
			std::cout << abc.get_name() << std::endl;
		}else if(input == DEFCHAN){
			std::cout << def.get_name() << std::endl;
		}else if(input == OFFCHAN){
			break;
		}
	}
};

int main(){
    TV tv;
    tv.change_channel();
    return 0;
}