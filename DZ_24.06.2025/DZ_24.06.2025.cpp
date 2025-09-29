#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

class Array {
private:
	int* data;
	size_t size;

public:
	// Конструктор по умолчанию
	Array(size_t n = 0) : size(n) {
		data = (size > 0) ? new int[size]() : nullptr;
	}

	// Конструктор копирования
	Array(const Array& other) : size(other.size) {
		data = (size > 0) ? new int[size]() : nullptr;
		for (size_t i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	// Конструктор из строки "10 20 30"
	Array(const string& str) {
		vector<int> nums;
		string temp = "";
		for (char ch : str) {
			if (ch == ' ') {
				if (!temp.empty()) {
					nums.push_back(stoi(temp));
					temp.clear();
				}
			}
			else {
				temp += ch;
			}
		}
		if (!temp.empty()) nums.push_back(stoi(temp));

		size = nums.size();
		data = (size > 0) ? new int[size] : nullptr;
		for (size_t i = 0; i < size; i++) {
			data[i] = nums[i];
		}
	}

	// Деструктор
	~Array() {
		delete[] data;
	}

	//Оператор присваивания "="
	Array& operator=(const Array& other) {
		if (this == &other) return *this;
		delete[] data;

		size = other.size;
		data = (size > 0) ? new int[size] : nullptr;
		for (size_t i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
		return *this;
	}

	// Перевод в string
	operator string() const {
		string result = "";
		for (size_t i = 0; i < size; i++) {
			result += to_string(data[i]) + " ";
		}
		return result;
	}

	// Оператор[]
	int& operator[](size_t index) {
		return data[index];
	}

	const int& operator[](size_t index) const {
		return data[index];
	}

	// Сравнение == и !=
	bool operator==(const Array& other) const {
		if (size != other.size) return false;
		for (size_t i = 0; i < size; i++) {
			if (data[i] != other.data[i]) return false;
		}
		return true;
	}

	bool operator!=(const Array& other) const {
		return !(*this == other);
	}

	//Вывод <<
	friend ostream& operator<<(ostream& os, const Array& arr) {
		for (size_t i = 0; i < arr.size; i++) {
			os << arr.data[i] << " ";
		}
		return os;
	}

	//Ввод >>
	friend istream& operator>>(istream& is, Array& arr) {
		for (size_t i = 0; i < arr.size; i++) {
			is >> arr.data[i];
		}
		return is;
	}
};

// Тест
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Array a1(3);
	cout << "Введите 3 числа: ";
	cin >> a1;

	cout << "Массив a1: " << a1 << "\n";

	Array a2 = a1;
	cout << "Копия a2: " << a2 << "\n";

	string s = (string)a1;
	cout << "Строка из a1: " << s << "\n";

	Array a3("10 20 30 40");
	cout << "Массив a3 из строки: " << a3 << "\n";

	cout << "a1 == a2 ? " << (a1 == a2 ? "да" : "нет") << "\n";
	cout << "a1 != a3 ? " << (a1 != a3 ? "да" : "нет") << "\n";

	a1[0] = 100;
	cout << "После изменения a1[0]: " << a1 << "\n";

	return 0;

}