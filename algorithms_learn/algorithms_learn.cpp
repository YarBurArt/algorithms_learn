#include <vector>
#include <algorithm>
#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <conio.h>

#define M_PI 3.14159265358979323846
#define _USE_MATH_DEFINES
#define repeat(n) for (int i=0; i<n; i++) 

using namespace std;

void cycles(vector<int>); //указатель на функцию, чтобы их можно было писать ниже призыва
int random_range(int, int);
vector<int> mySortPointers(vector<int>, int);
int searchBrute(vector<int>, int);
float circleS(float r);
int bi_search(vector<int> data, int elem);
vector<float> sigmoid(vector <float> m1);
void bayan_bayanuch(int cnt, int ind, int k, char init[6]);

int main()
{
	setlocale(0, "");

	cout << "Hello World!\n";
	cout << "привет мир";

	vector<int> num_vect = { 12,3,32,43,3468,34, }; //dinamic array
	int types_num[5] = { 2,1,5,3,7 }; //const array
	//sort(num_vect.begin(), num_vect.end()); //от стандартных библиотек
	mySortPointers(num_vect, num_vect.size()); //сортировка вставками
	cycles(num_vect);

	cout << "num search: " << searchBrute(num_vect, 43) << endl; //поиск перебором

	if (find(num_vect.begin(), num_vect.end(), 34) != num_vect.end()) {
		cout << "num search: " << true;
	}
	else { cout << "null"; } cout << endl;
	
	cout << "num search: " << bi_search(num_vect, 3) << endl; //бинарный поиск 

	string name = "jkygjkgf";
	sort(name.begin(), name.end());
	cout << name << endl;

	reverse(name.begin(), name.end());
	cout << name << endl;

	int rd = random_range(10, 1);
	cout << "random num: " << rd << endl;

	int ex_rd = exp(rd);
	cout << "exp num: " << ex_rd << endl;

	unsigned char smile = -255; // = 256 -|n/256| == :)
	cout << "unsigned num: " << smile << endl;

	cout << "S circle: " << circleS(rd) << endl;

	vector<float> tosigm = {0.5,0.1,0.3};
	cout << "sigmoid:";
	vector<float> outsigm = sigmoid(tosigm);
	repeat(outsigm.size()) {
		cout << outsigm[i] << " ";
	} cout << endl;

	char chek[6] = { '(','(','(',')',')',')' };
	bayan_bayanuch(0, 0, 6, chek);
}

int random_range(int min, int max) {
	srand(time(NULL)); // усиление псевдорандома
	int num = min + rand() % (max - min + 1);
	return num;  

}

// пока i меньше размера вектора
void cycles(vector<int> vect) {
	cout << "\n";
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << "\n"; //or
	repeat(vect.size()) { //работает только с переименованием define выше
		cout << vect[i] << " ";
	}
	cout << "\n"; //or
	int i = 0;
	while (i < vect.size()) {
		cout << vect[i] << " ";
		i++;
	}
	cout << "\n"; 
}

vector<int> mySortPointers(vector<int> vect, int n) {
	for (int i = 1; i < n; i++) // проход по всему вектору
		for (int j = i; j > 0 && vect[j-1] > vect[j]; j--) // пока j>0 и элемент j-1 > j, x это массив int
			swap(vect[j - 1], vect[j]);        // меняем местами элементы j (отсортированная часть с начала) и j-1 (следующий элемент)
	return vect;
}

int searchBrute(vector<int> vect, int sn) {
	repeat(vect.size()) {
		if (vect[i] == sn) return i;
		else return 0;
	}
}

float circleS(float r) {
	const float pi = 3.14; //M_PI
	return pi * r * r;
}

int bi_search(vector<int> data_o, int elem) {
	vector<int> data = mySortPointers(data_o, data_o.size());

	repeat(data.size()) cout << data[i] << " ";
	cout << endl;

	int low = 0;
	int high = data.size() - 1;
	
	while (low<=high) {
		float sum = low + high;
		int middle = (int)sum;
	
		if (data[middle] == elem) return middle;
		else if (data[middle] > elem) high = middle - 1;
		else low = middle + 1;
	}
	return -1;
}

vector<float> sigmoid(vector <float> m1) {
	// f(x) = 1/(1 + e^-x).
	vector <float> output(m1.size());
	for (unsigned i = 0; i != m1.size(); ++i) {
		output[i] = 1 / (1 + exp(-m1[i]));
	}
	return output;
}

void bayan_bayanuch(int cnt, int ind, int k, char init[6]) { 
	// ((())) to ()()() = генерация правильных скобочных последовательностей со скобками одного вида
	// k - размер списка и количество скобок, cnt - разница между скобками, ind - индекс для скобки 
	// кладем (, только если хватает места
	if (cnt <= k - ind - 2) {
		init[ind] = '(';
		// идем к следующей скобке
		bayan_bayanuch(cnt + 1, ind + 1, k, init);
	}
	// ) можно положить всегда, если cnt > 0
	if (cnt > 0) {
		init[ind] = ')';
		// идем к следующей скобке
		bayan_bayanuch(cnt - 1, ind + 1, k, init);
	}
	// печать по окончанию итерации
	if (ind == k && cnt == 0) cout << init;
}
