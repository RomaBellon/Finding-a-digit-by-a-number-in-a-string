#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void head() {
	cout << '№' << setw(25) << "Название:" << setw(25) << "Автор:" << setw(25) << "Издательство:" << setw(25) << "Год:" << setw(25) << "Цена:" << endl;
}

void sortprice(vector < vector<string>> books) {
	int min, max;
	cout << "Введите min диапазона: ";
	while (1) {
		cin >> min;
		if (cin.fail() or min < 0) {
			cin.clear();
			cin.ignore();
			cout << "Ошибка ввода, введите заново: ";
		}
		else {
			break;
		}
	}

	cout << "Введите max диапазона: ";
	while (1) {
		cin >> max;
		if (cin.fail() or max < 0) {
			cin.clear();
			cin.ignore();
			cout << "Ошибка ввода, введите заново: ";
		}
		else {
			break;
		}
	}

	head();

	for (int i = 0; i < books.size(); i++) {
		if (atoi(books[i][4].c_str()) >= min and atoi(books[i][4].c_str()) <= max) {
			cout << i + 1;
			for (int j = 0; j < 5; j++) {
				cout << setw(25) << books[i][j];
			};
			cout << endl;
		};
	};
}

vector <string> newbook() {
	vector <string> book(5);
	cout << "Введите название книги:" << endl;
	cin.get();
	getline(cin, book[0]);
	cout << "Введите автора книги:" << endl;
	getline(cin, book[1]);
	cout << "Введите издательство:" << endl;
	getline(cin, book[2]);
	cout << "Введите год издательства:" << endl;
	getline(cin, book[3]);
	cout << "Введите цену:" << endl;
	getline(cin, book[4]);
	return book;
}

vector<vector<string>> addBooks() {
	string way, slc;
	int count = 0;
	vector<vector<string>> books;
	cout << "Введите название файла, из которого хотите добавить книги" << endl;
	while (1) {
		cin >> way;
		ifstream in(way);
		if (in.is_open()) {
			vector<string> book;
			while (getline(in, slc)) {
				count++;
				book.push_back(slc);
				if (count % 5 == 0) {
					books.push_back(book);
					book.clear();
					count = 0;
				}
			}
			in.close();
			return books;

		}
		else {
			cin.clear();
			cin.ignore();
			cout << "Файл с таким именем не существует, введите заново:" <<  endl; //проверка на несуществующее название файла
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	string slc;
	string chiefway;
	int WayFile;
	cout << "Введите:" << endl;
	cout << "0 -- оставить исходный файл" << endl;
	cout << "1 -- указать новый файл" << endl;
	while (1) {
		cin >> WayFile;
		if (cin.fail() or WayFile < 0 or WayFile>1) {
			 cin.clear();
			cin.ignore();
			cout << "Введены некорректные данные, введите заново" << endl;
		}
		else {
			break;
		}
	}

	if (WayFile == 0) {
		chiefway = "books1.txt";
	}
	else {
		cout << "Введите название файла:" << endl;
		while (1) {
			cin >> chiefway;
			ifstream in(chiefway);
			if (in.is_open()) {
				break;
			}
			else {
				cin.clear();
				cin.ignore();
				cout << "Указанный вами файл не существует ";
			}
		}
	}

	ifstream in(chiefway);
	int count = 0;
	vector < vector<string>> books;
	vector<string> book;
	while (getline(in, slc)) {
		count++;
		book.push_back(slc);
		if (count % 5 == 0) {
			books.push_back(book);
			book.clear();
			count = 0;
		}
	}
	in.close();

	while (1) {

		cout << endl << "Введите:" << endl;
		cout << "1 -- вывести все книги" << endl;
		cout << "2 -- вывести все книги из диапазона цен" << endl;
		cout << "3 -- добавить новую книгу" << endl;
		cout << "4 -- удалить книгу из файла" << endl;
		cout << "5 -- добавить книги из другого  файла" << endl;
		cout << "6 -- вывести все книги, отсортированные по возрастанию цен" << endl;
		cout << "7 -- вывести все книги, отсортированные по убыванию цен" << endl;
		cout << "8 -- сохранить и выйти" << endl;

		int flag;
		while (1) {
			cin >> flag;
			if (cin.fail() or flag < 1 or flag > 8) {
				cin.clear();
				cin.ignore();
				cout << "Некорректный ввод, введите заново: " << endl;
			}
			else {
				break;
			}
		}

		switch (flag) {
		case 1: {
			system("cls");
			head();
			for (int i = 0; i < books.size(); i++) {
			cout << i + 1;
			for (int j = 0; j < 5; j++) {
			cout << setw(25) << books[i][j];
			}
				cout << endl;
			}
			break;
		}
		case 2: {
			system("cls");
			sortprice(books);
			break;
		}
		case 3:{
				system("cls");
				books.push_back(newbook());
				cout << "В файл была добавлена новая книга";
				break;
		}
		case 4: {
				int delBook;
				system("cls");
				head();
				for (int i = 0; i < books.size(); i++) {
					cout << i + 1;
					for (int j = 0; j < 5; j++) {
						cout << setw(25) << books[i][j];
					}
					cout << endl;
				}
				cout << "Введите номер книги, которую хотите удалить: ";
				while (1) {
					cin >> delBook;
					if (cin.fail() or delBook<1 or delBook>books.size()) {
						cin.clear();
						cin.ignore();
						cout << "Ошибка ввода, введите заново:" << endl;
					}
					else {
						break;
					}
				}
				books.erase(books.begin() + delBook - 1);
				cout << "Книга была удалена";
				break;
			}
		case 5: {
				system("cls");
				int num;
				vector<int> summaryNums;
				vector < vector<string>> books2 = addBooks();
				head();
				for (int i = 0; i < books2.size(); i++) {
					cout << i + 1;
					for (int j = 0; j < 5; j++) {
						cout << setw(25) << books2[i][j];
					}
					cout << endl;
				}
				cout << "Вводите по одному номера книг, которые нужно копировать. Введите 0 чтобы закончить ввод:" << endl;
				while (1) {
					cin >> num;
					if (num != 0) {
						if (num > 0 and num < books2.size() + 1) {
							summaryNums.push_back(num);
						}
						else {
							cout << "Ошибка ввода, введите данные заново:" << endl;
						}
						cin.clear();
						cin.ignore();
					}
					else
					{
						break;
					}
				}
				for (int i = 0; i < summaryNums.size(); i++) {
					books.push_back(books2[summaryNums[i] - 1]);
				}
				cout << "Книги были добавлены в исходный файл" << endl;
				break;
			}
		case 6: {
			system("cls");
			vector<vector<int>> outgoings(books.size());
			for (int i = 0; i < books.size(); i++) {
				outgoings[i].push_back(i);
				outgoings[i].push_back(atoi(books[i][4].c_str()));
			}

			vector<int> temp;
			for (int i = 0; i < books.size() - 1; i++) {
				for (int j = 0; j < books.size() - i - 1; j++) {
					if (outgoings[j][1] > outgoings[j + 1][1]) {
						temp = outgoings[j];
						outgoings[j] = outgoings[j + 1];
						outgoings[j + 1] = temp;
					}
				}
			}

			head();
			for (int i = 0; i < books.size(); i++) {
				cout << i + 1;
				for (int j = 0; j < 5; j++) {
					cout << setw(25) << books[outgoings[i][0]][j];
				}
				cout << endl;
			}
			break;
		}
		case 7: {
			system("cls");
			vector<vector<int>> outgoings(books.size());
			for (int i = 0; i < books.size(); i++) {
				outgoings[i].push_back(i);
				outgoings[i].push_back(atoi(books[i][4].c_str()));
			}

			vector<int> temp;
			for (int i = 0; i < books.size() - 1; i++) {
				for (int j = 0; j < books.size() - i - 1; j++) {
					if (outgoings[j][1] < outgoings[j + 1][1]) {
						temp = outgoings[j];
						outgoings[j] = outgoings[j + 1];
						outgoings[j + 1] = temp;
					}
				}
			}

			head();
			for (int i = 0; i < books.size(); i++) {
				cout << i + 1;
				for (int j = 0; j < 5; j++) {
					cout << setw(25) << books[outgoings[i][0]][j];
				}
				cout << endl;
			}
			break;
		}
		case 8:
			ofstream out(chiefway, ios::out);
			for (int i = 0; i < books.size(); i++) {
				for (int j = 0; j < 5; j++) {
					out << books[i][j] << endl;
				}
			}
			cout << "Сохраниние прошло успешно :3";
			out.close();

			return 0;


		};
	}
}
