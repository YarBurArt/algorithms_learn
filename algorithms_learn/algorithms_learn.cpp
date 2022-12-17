#include <vector>
#include <algorithm>
#include <array>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#define _USE_MATH_DEFINES
#define repeat(n) for (int i=0; i<n; i++) 

using namespace std;

void cycles(vector<int>); //указатель на функцию, чтобы их можно было писать ниже призыва
int random_range(int, int);
vector<int> mySortPointers(vector<int>, int);
int searchBrute(vector<int>, int);

int main()
{
	cout << "Hello World!\n";

	vector<int> num_vect = { 12,3,32,43, 3468, 34 };
	//sort(num_vect.begin(), num_vect.end()); //от стандартных библиотек
	mySortPointers(num_vect, num_vect.size()); //сортировка вставками
	cycles(num_vect);

	cout << "num search: " << searchBrute(num_vect, 43) << endl; //поиск перебором
	if (find(num_vect.begin(), num_vect.end(), 34) != num_vect.end()) {
		cout << "num search: " << true;
	} else { cout << "null"; }
	

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
	cout << "unsigned num: " << smile;


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
		if (vect[i] == sn) {
			return i;
		}
		else {
			return 0;
		}
	}
}

