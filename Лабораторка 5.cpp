//  4. Создать класс "студент" (его имя и год рождения).Написать:
//  а) член - функцию печати информации о студенте;
//  б) функции реализующие поиск по имени, по году рождения.

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string student_name;
	int student_old;
	friend void info_year(Student*, int a);
	friend void info_names(Student* s, int a);
public:
	Student() {
	}

	void print() {
		cout << student_name << '\t' << student_old << endl;
	}

	void info() {
		cout << "Введите имя: ";
		cin >> student_name;
		cout << "Введите год рождения: ";
		cin >> student_old;
	}
};

void info_year(Student* s, int a) {
	int year;
	cout << "Введите год рождения: ";
	cin >> year;
	for (int i = 0; i < a; i++) {
		if (year == s[i].student_old) {
			cout << s[i].student_name << '\t' << year << endl;
		}
	}
}

void info_names(Student* s, int a) {
	string names;
	cout << "Введите имя: ";
	cin >> names;
	for (int i = 0; i < a; i++) {
		if (names == s[i].student_name) {
			cout << names << '\t' << s[i].student_old << endl;
		}
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	int a;
	Student n;
	cout << "Введите количество студентов: " << endl; 
	cin >> a;
	Student* student = new Student[a];
	for (int i = 0; i < a; i++)
		student[i].info();
	cout << "Информация о студентах: " << endl;
	for (int i = 0; i < a; i++)
		student[i].print();
	info_year(student, a);
	info_names(student, a);
}