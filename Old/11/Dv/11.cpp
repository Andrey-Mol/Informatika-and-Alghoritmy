#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include<windows.h>
#include <fstream>
using namespace std;

struct Student
{
	char name[255], surname[255], surname2[255];// ФИО ученика по char массивам
	int date[3];//Дата рождения
	char address[255];//Адрес
	float rating;//Рейтинг
	Student* next = nullptr;
};
struct List
{
	size_t size = 0;
	Student* head = nullptr;
	Student* tail = nullptr;
};

int n = 0;
char filename[] = "test.txt";

void push_back(List* list, Student* student);

int getValue(string query)
{
	int value;
	cout << query;
	while (!(cin >> value))
	{
		cin.clear(); //Сбрасываем флаг ошибки, если таковая была
		cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Ошибка ввода, попробуйте снова: ";
	}
	return value;
}
float getValueF(string query)
{
	float value;
	cout << query;
	while (!(cin >> value) || value < 1)
	{
		cin.clear(); //Сбрасываем флаг ошибки, если таковая была
		cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Ошибка ввода, попробуйте снова: ";
	}
	return value;
}
Student* get_obj(List* list, int num)
{
	Student* obj = list->head;
	for (int i = 1; i < num; ++i)
	{
		obj = obj->next;
	}
	return obj;
}
Student* zapolnenie()
{
	Student* student = new Student;
	char l = 'r';
	cout << "Введите ФИО: \n";
	cout << "* Введите фамилию: ";
	cin.getline(student->surname, 255);
	cout << "* Введите имя: ";
	cin.getline(student->name, 255);
	cout << "* Введите отчество: ";
	cin.getline(student->surname2, 255);
	cout << "Введите дату рождения: \n";
	student->date[0] = 0;
	student->date[1] = 0;
	while (!(student->date[0] && student->date[1]))
	{
		while (student->date[0] < 1 || student->date[0] > 31)
		{
			student->date[0] = getValue("* Введите день: ");
			if (student->date[0] < 1 || student->date[0] > 31)
				cout << "\nОшибка ввода, день не может иметь такое значение!\n\n";
		}
		while (student->date[1] < 1 || student->date[1] > 12)
		{
			student->date[1] = getValue("* Введите месяц: ");
			if (student->date[1] < 1 || student->date[1] > 12)
				cout << "\nОшибка ввода, месяц не может иметь такое значение!\n\n";
		}
		student->date[2] = getValue("* Введите год: ");
		if (student->date[2] < 24)
			student->date[2] += 2000;
		else if (student->date[2] < 101)
			student->date[2] += 1900;
		else if (student->date[2] < 1900)
		{
			while (student->date[2] < 1900 && (l != 'y') && student->date[2] > 100)
			{
				cout << "Подтвердите правильность ввода да/нет буквой (y/n)\n";
				cin >> l;
				if (l == 'n')
					student->date[2] = getValue("* Введите год: ");
			}
			if (student->date[2] < 24)
				student->date[2] += 2000;
			else if (student->date[2] < 101)
				student->date[2] += 1900;
		}
		else if (student->date[2] > 2023)
		{
			cout << "Год не может привышать 2023. Попробуйте снова!\n";
			student->date[2] = getValue("* Введите год: ");
		}
		if ((student->date[0] > 29 && student->date[1] == 2 && ((student->date[2] % 4) == 0)) || (student->date[0] > 28 && student->date[1] == 2 && ((student->date[2] % 4) != 0)) || (student->date[0] > 30 && student->date[1] % 2 == 0))
		{
			student->date[0] = 0;
			student->date[1] = 0;
			student->date[2] = 0;
			cout << "\nОшибка ввода, такая дата невозможна!\n\n";
		}
	}
	cout << "Введите адрес: ";
	cin.get();
	cin.getline(student->address, 255);
	student->rating = getValueF("Введите рейтинг: ");
	cout << "_______________________________________________________________\n";
	cin.get();
	return student;
}
Student* zapolnenie(int mas[8])
{
	char l = 'r';
	Student* student = new Student;
	if (mas[0] == 1 || mas[1] == 1 || mas[2] == 1)
	{
		cin.get();
		cout << "Введите ФИО: \n";
		if (mas[0] == 1)
		{
			cout << "* Введите фамилию: ";
			cin.getline(student->surname, 255);
		}
		if (mas[1] == 1)
		{
			cout << "* Введите имя: ";
			cin.getline(student->name, 255);
		}
		if (mas[2] == 1)
		{
			cout << "* Введите отчество: ";
			cin.getline(student->surname2, 255);
		}
	}
	if (mas[3] == 1 || mas[4] == 1 || mas[5] == 1)
	{
		cout << "Введите дату рождения: \n";
		if (mas[3] == 1)
		{
			student->date[0] = getValue("* Введите день: ");
		}
		if (mas[4] == 1)
		{
			student->date[1] = getValue("* Введите месяц: ");
		}
		if (mas[5] == 1)
		{
			student->date[2] = getValue("* Введите год: ");
			if (student->date[2] < 24)
				student->date[2] += 2000;
			else if (student->date[2] < 101)
				student->date[2] += 1900;
			else if (student->date[2] < 1900)
			{
				while (student->date[2] < 1900 && (l != 'y') && student->date[2] > 100)
				{
					cout << "Подтвердите правильность ввода да/нет буквой (y/n)\n";
					cin >> l;
					if (l == 'n')
						student->date[2] = getValue("* Введите год: ");
				}
				if (student->date[2] < 24)
					student->date[2] += 2000;
				else if (student->date[2] < 101)
					student->date[2] += 1900;
			}
			else if (student->date[2] > 2023)
			{
				cout << "Год не может привышать 2023. Попробуйте снова!\n";
				student->date[2] = getValue("* Введите год: ");
			}
		}
	}
	if (mas[6] == 1)
	{
		cout << "Введите адрес: ";
		cin.get();
		cin.getline(student->address, 255);
	}
	if (mas[7] == 1)
	{
		student->rating = getValueF("Введите рейтинг: ");
	}
	cout << "_______________________________________________________________\n";
	return student;
}
bool list_is_empty(List* list) 
{
	return list == nullptr || n == 0;
}
bool ravenstvo_strok(char* a, char* b)
{
	for (int i = 0; i < 255; i++)
	{
		if (a[i] != b[i])
			return 0;
		return 1;
	}
}
bool ravenstvo(Student* a, Student* b, int mas[8])
{
	if (mas[0] == 1 && !(ravenstvo_strok(a->surname, b->surname)))
		return 0;
	if (mas[1] == 1 && !(ravenstvo_strok(a->name, b->name)))
		return 0;
	if (mas[2] == 1 && !(ravenstvo_strok(a->surname2, b->surname2)))
		return 0;
	if (mas[3] == 1 && (a->date[0] != b->date[0]))
		return 0;
	if (mas[4] == 1 && (a->date[1] != b->date[1]))
		return 0;
	if (mas[5] == 1 && (a->date[2] != b->date[2]))
		return 0;
	if (mas[6] == 1 && !(ravenstvo_strok(a->address, b->address)))
		return 0;
	if (mas[7] == 1 && (a->rating != b->rating))
		return 0;
	return 1;
}

List* createList(int size) //Создание БД с n-структурами Student;
{
	List* list = new List;
	if (size > 0)
	{
		cout << "Заполните формы  " << size << " элементов списка: \n";
		cin.get();
		for (int i = 1; i <= size; i++)
		{
			cout << i << ") \n";
			push_back(list, zapolnenie());
		}
	}
	return list;
}
void push_back(List* list, Student *student) //добавить новый элемент сверху
{
	Student* new_s = new Student;
	new_s = student;
	if (list_is_empty(list))
	{
		list->head = new_s;
		list->tail = new_s;
	}
	else {
		list->tail->next = new_s;
		list->tail = new_s;
	}
	n++;
}
void push_front(List* list, Student* student)
{
	Student* new_s = new Student;
	new_s = student;
	if (list_is_empty(list))
	{
		list->head = new_s;
		list->tail = new_s;
	}
	else
	{
		new_s->next = list->head;
		list->head = new_s;
	}
	n++;
}
void outputList(List* list) 
{
	Student* temp = list->head;
	Student t = *temp;
	cout << "\n_______________________________________________________________\n";
	for (int i = 0; i < n; i++)
	{
		cout << "ФИО: " << temp->surname << " " << temp->name << " " << temp->surname2 << endl;
		cout << "Дата рождения: ";
		if (temp->date[0] / 10 == 0)
			cout << "0" << temp->date[0] << ".";
		else
			cout << temp->date[0] << ".";
		if (temp->date[1] / 10 == 0)
			cout << "0" << temp->date[1] << ".";
		else
			cout << temp->date[1] << ".";
		cout << temp->date[2] << " г. ";
		cout << "Адрес: " << temp->address << endl;
		cout << "Рейтинг: ";
		cout << temp->rating;
		cout << "\n_______________________________________________________________\n";
		temp = temp->next;
	}
	return;
} //вывод содержимого файла //


void remove_obj(List* list, Student* student,int mas[8])
{
	if (list_is_empty(list)) 
		cout << "Список пуст, нечего удалять!\n";
	else
	{
		Student* temp = list->head;
		if (ravenstvo(list->head, list->tail, mas) && ravenstvo(list->head, student, mas))
		{
			delete list->head;
			list->head = nullptr;
			list->tail = nullptr;
			n=0;
			return;
		}
		else if (ravenstvo(list->head, student, mas))
		{
			temp = list->head;
			list->head = list->head->next;
			delete temp;
			n--;
			system("cls");
			remove_obj(list, student, mas);
			return;
		}
		else
		{
			while (temp->next != nullptr)
			{
				if (ravenstvo(temp->next, student, mas))
				{
					if (ravenstvo(temp->next, list->tail, mas))
					{
						delete list->tail;
						list->tail = temp;
						list->tail->next = nullptr;
					}
					else
					{
						Student* temp2 = (temp->next)->next;
						delete temp->next;
						temp->next = temp2;
					}
					n--;
					remove_obj(list, student, mas);
					return;
				}
				temp = temp->next;
			}
		}

	}
}
void remove_nom(List* list, int b)
{
	if (list_is_empty(list))
		cout << "Список пуст, нечего удалять!\n";
	else
	{
		Student* temp = list->head;
		if (n == 1 && b == 1)
		{
			delete list->head;
			list->head = nullptr;
			list->tail = nullptr;
			system("cls");
			cout << "\nУченик успешно удалён, список пуст!\n\n";
			n--;
			return;
		}
		else if (b == 1)
		{
			temp = list->head;
			list->head = list->head->next;
			delete temp;
			system("cls");
			cout << "\nУченик успешно удалён!\n\n";
			n--;
			return;
		}
		else
		{
			for (int i = 2; i <= b; i++)
			{
				if (i == b)
				{
					if (b == n)
					{
						delete list->tail;
						list->tail = temp;
						list->tail->next = nullptr;
					}
					else
					{
						Student* temp2 = (temp->next)->next;
						delete temp->next;
						temp->next = temp2;
					}
					n--;
					system("cls");
					cout << "\nУченик успешно удалён!\n\n";
					return;
				}
				if (temp->next == nullptr)
				{
					system("cls");
					cout << "\nСлишком большой номер элемента!\n\n";
					return;
				}
				if (i < b)
				{
					temp = temp->next;
				}
			}
		}

	}
}
void push_before_obj(List* list, int k, int num, Student* obj)
{
	if (k == 0) return;
	Student* new_obj = new Student;
	new_obj = zapolnenie();
	push_before_obj(list, k - 1, num, obj);
	if (num == 1)
	{
		new_obj->next = list->head;
		list->head = new_obj;
	}
	else {
		new_obj->next = obj->next;
		obj->next = new_obj;
	}
	n++;
}
void push_before(List* list, int k, int num)
{
	if (!list_is_empty(list) && num >= 1 && num <= n)
	{
		if (k == 0) return;
		Student* obj = get_obj(list, num - 1);
		cout << "Введите " << k << " форм: \n";
		cin.get();
		push_before_obj(list, k, num, obj);
	}
	else cout << "Список пуст или введен неверный индекс!\n";
	system("pause");
}
void output(char* filename, List* list, int k)
{
	if (list_is_empty(list))
	{
		cout << "\nСписок пуст!\n\n";
		return;
	}
	else
	{
		Student* student = list->head;
		ofstream fout;
		fout.open(filename);
		for (int i = 0; i < k; i++)
		{
			fout << i + 1 << ")\n";
			fout << student->surname;
			fout << "\n";
			fout << student->name;
			fout << "\n";
			fout << student->surname2;
			fout << "\n";
			fout << student->date[0];
			fout << ".";
			fout << student->date[1];
			fout << ".";
			fout << student->date[2];
			fout << "\n";
			fout << student->address;
			fout << "\n";
			fout << student->rating;
			fout << "\n";
			student = student->next;
		}
		fout << "end";
		fout.close();
		cout << "\nДанные успешно выгружены в файл!\n\n";
	}
}
void input(char* filename, List* list)
{
	char h = '*';
	string g;
	string end = "end";
	ifstream fin;
	fin.open(filename, ios::in);
	fin >> g;
	if (g[0] != '1')
	{
		cout << "\nФайл пуст или повреждён!\n\n";
		return;
	}
	while(g != end)
	{
		Student* student = new Student;
		fin >> student->surname;
		fin >> student->name;
		fin >> student->surname2;
		fin >> student->date[0];
		fin >> h;
		fin >> student->date[1];
		fin >> h;
		fin >> student->date[2];
		fin.get();
		fin.getline(student->address, 254, '\n');
		fin >> student->rating;
		push_back(list, student);
		fin >> g;
	}
	fin.close();
	cout << "\nДанные из файла успешно добавлены в список!\n\n";
	return;
}
void remove_list(List* list)
{
	Student* temp;
	while (list->head != nullptr)
	{
		temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	n = 0;
	list->tail = nullptr;
	cout << "\nСписок удален!\n\n";
}
void ochistka(char* filename)
{
	remove(filename);
	ofstream fout;
	fout.open(filename);
	fout.close();
	cout << "\nФайл очищен!\n\n";
}
void menu()
{
	List* list = new List;
	int deistvie = 1;
	int vvod = 0, K, N;
	while (deistvie != 0)
	{
		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
		cout << "\tМеню\t\n";
		cout << "1 - Создание списка;\n";
		cout << "2 - Вывод списка;\n";
		cout << "3 - Добавление объекта в начало списка;\n";
		cout << "4 - Добавление объекта в конец списка;\n";
		cout << "5 - Добавление K объектов перед объектом с позицией N;\n";
		cout << "6 - Удаление объекта с заданным ключом;\n";
		cout << "7 - Удаление объекта с заданным номером;\n";
		cout << "8 - Удаление списка;\n";
		cout << "9 - Сохранить данные списка в файл;\n";
		cout << "10 - Добавить данные из файла в список;\n";
		cout << "11 - Очистить файл;\n";
		cout << "0 - Выход из меню;\n";
		cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
		cin >> deistvie;
		switch (deistvie)
		{
		case 1:
		{
			system("cls");
			int y;
			y = getValue("\nВведите количествово учеников для создания списка: ");
			while (!y)
			{
				system("cls");
				cout << "\nОшибка ввода, количество учеников не может быть равным 0. Попробуйте снова!\n\n";
				y = getValue("Введите количествово учеников для создания списка: ");
			}
			list = createList(y);
			system("cls");
			cout << "\nСписок создан!\n\n";
			system("pause");
			break;
		}
		case 2:
		{
			if (n == 0)
			{
				system("cls");
				cout << "\nСписок пуст!\n\n";
			}
			else
			{
				system("cls");
				cout << "\nВведённые ученики:\n";
				outputList(list);
			}
			cout << "\n\n";
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Заполните новую форму:\n";
			cin.get();
			push_front(list, zapolnenie());
			system("cls");
			cout << "\nУченик успешно добавлен!\n\n";
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Заполните новую форму:\n";
			cin.get();
			push_back(list, zapolnenie());
			system("cls");
			cout << "\nУченик успешно добавлен!\n\n";
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "Введите кол-во объетов K и позицию N:\n";
			cin >> K >> N;
			push_before(list, K, N);
			system("cls");
			cout << "\nУченики успешно добавлены!\n\n";
			system("pause");
			break;
		}
		case 6:
		{
			int j,x,v = n;
			int mas[] = { 0,0,0,0,0,0,0,0 };
			system("cls");
			cout << "Введите количество полей, по которым будет происходить удаление: ";
			cin >> j;
			cout << "\n1 - Фамилия;\n";
			cout << "2 - Имя;\n";
			cout << "3 - Отчество;\n";
			cout << "4 - День рождения;\n";
			cout << "5 - Месяц рождения;\n";
			cout << "6 - Год рождения;\n";
			cout << "7 - Адрес;\n";
			cout << "8 - Рейтинг;\n";
			cout << "Выберете номера полей, для сдаления: ";
			for (int i = 0; i < j; i++)
			{
				cin >> x;
				mas[x-1] = 1;
			}
			system("cls");
			remove_obj(list, zapolnenie(mas), mas);
			if (n < v)
				cout << "\nУдаление прошло успешно!\n\n";
			else if (n == 0)
				cout << "\nУдаление прошло успешно, список пуст!\n\n";
			else 
				cout << "\nЭлементов по данным параметрам не найдено!\n\n";
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			int y;
			y = getValue("\nВведите номер объекта, который хотите удалить: ");
			system("cls");
			remove_nom(list, y);
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			remove_list(list);
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			output(filename, list,n);
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			input(filename, list);
			system("pause");
			break;
		}
		case 11:
		{
			system("cls");
			ochistka(filename);
			system("pause");
			break;
		}
		case 0:
		{
			system("cls");
			cout << "\nСпасибо за выбор нашей программы!:)\n\n";
			system("pause");
			break;
		}
		default:
		{
			system("cls");
			cout << "\nВведено неверное значение, попробуйте ещё раз.\n\n";
			break;
		}
		}
		system("cls");
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Привет, дорогой Друг. Это программа создана для работы с базой данных учеников. Расскажу тебе о своих возможностях.\n";
	cout << "Для выполнения нижеследующих действий тебе необходимо ввести соответствующую цифру\n";
	menu();
	return 0;
}