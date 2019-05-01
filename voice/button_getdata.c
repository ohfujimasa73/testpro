#include "./button_getdata.h"

int get_data(int button){
	
	int get_data;
	
	if( button == AMPLFER ){
		get_data = dial_point() * 8;
	}else{
		get_data = 60;
	}
	//
	return get_data;
}

int dial_point(){
	srand((unsigned)time(NULL));
	return (rand() % 10);
}