#include <iostream>
#include <string.h>
using namespace std;

void swap(char *input ,char *input2);

class ListItem {
public:
	char* name;	/* 名前(日付)を格納した文字列を指すポインタ */
public:
	/* 印字メソッド(純仮想関数) */
	virtual void Print() = 0;
	/* コンストラクタ */
	ListItem(const char* _date){
		/* 名前を初期化 */
		this->name = new char[strlen(_date) + 1];
		memset( this->name , '\0' , strlen( _date ) + 1);
		strcpy( this->name , _date );
	}
};

class WeatherRecord : public ListItem {
private:
	char* weather;	/* 天気を格納した文字列を指すポインタ */
	int high;		/* 最高気温(℃) */
	int low;		/* 最低気温(℃) */
public:
	/* コンストラクタ */
	WeatherRecord(
	const char* _date,
	const char* _weather,
	int _high,
	int _low):ListItem(_date){
		/* 天気を初期化 */
		this->weather = new char[strlen(_weather) + 1];
		memset( this->weather , '\0' , strlen(_weather) + 1);
		strcpy( this->weather , _weather);
		/* 最高気温代入 */
		this->high = _high;
		/* 最低気温代入 */
		this->low = _low;
	}
	/* 印字メソッド */
	void Print(){
		cout << this->name << ": " 
		<< this->weather << ": " 
		<< this->high << "/" << this->low << 
		"(度)" << endl;
	}
};

class List{
private:
	ListItem **data;	/* データ格納 */
	int point;			/* 格納位置 */
	int max;			/* データ最大数 */
public:
	/* コンストラクタ */
	List(int num){
		/* データ数分メモリ確保 */
		this->data = new ListItem * [num];
		/* 現在のポインタ位置 */
		this->point = 0;
		/* 最大サイズ */
		this->max = num;
	}
	/* デストラクタ */
	~List(){
		delete[] this->data;
	}
	/* データ追加 */
	void Add(ListItem* p){
		/* データオーバー */
		if(this->point >= this->max){
			cout << "memory size over" << endl;
			return;
		}
		/* データ格納 */
		data[this->point++] = p;
		return;
	}
	/* ソートメソッド */
	void Sort(){
		/* ソートする */
		for(int loop = 0; loop < this->point - 1; loop++){
			for(int loop2 = this->point - 1 ; loop2 > loop ; loop2--){
				if(strcmp(this->data[loop2]->name,this->data[loop2 - 1]->name) < 0){
					/* スワップする */
					swap(this->data[loop2],this->data[loop2 -1]);
				}
			}
		}
		return;
	}
	/* データ印字メソッド */
	void Print(){
		/* データ印字 */
		for(int loop = 0 ; loop < this->point; loop++){
			data[loop]->Print();
		}
		return;
	}
	/* データ確認 */
	void Search(const char *input){
		/* データ存在を確認 */
		for(int loop = 0 ; loop < this->point; loop++){
			/* データ存在 */
			if(!strcmp(input,data[loop]->name)){
				cout << input << " is exist" << endl;
				return;
			}
		}
		/* データ存在しない */
		cout << input << " is not exist" << endl;
		return;
	}
};

/* スワップ関数 */
void swap(char *input ,char *input2){
	char *temp = input;
	input = input2;
	input2 = temp;
}

int main(){

	int num;
	/* データサイズ入力 */
	cout <<"INPUT DATA SIZE:" << endl;
	cin >> num;
	/* Listクラスのインスタンスの生成 */
	List weatherlist(num);
	/* エントリーの追加 */
	weatherlist.Add(new WeatherRecord("2015-06-24", "sunny", 29, 18));
	weatherlist.Add(new WeatherRecord("2015-06-25", "cloudy", 29, 20));
	weatherlist.Add(new WeatherRecord("2015-06-23", "sunny", 27, 19));
	weatherlist.Add(new WeatherRecord("2015-06-26", "rain", 26, 19));
	/* 印刷 */
	weatherlist.Print();
	cout << "-----------------" << endl;
	/* エントリーのソート */
	weatherlist.Sort();
	/* 印刷 */
	weatherlist.Print();
	cout << "-----------------" << endl;
	/* 検索 */
	weatherlist.Search("2015-06-22");
	weatherlist.Search("2015-06-24");
	return 0;
}
