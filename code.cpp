#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int

struct Lv
{
	int a[1000000];	//
	int idx = 0;
	Lv * next;
	Lv * prev;
};

Lv *head = NULL, *tail = NULL;
ll arr_size = -1;

void pushBack(int x)
{
	if (arr_size == -1)
	{
		Lv *nn = (Lv*) malloc(sizeof(Lv));
		nn->next = NULL;
		nn->prev = NULL;
		head = nn;
		tail = nn;
	}
	else if (tail->idx > 999999)
	{
		Lv *nn = (Lv*) malloc(sizeof(Lv));
		nn->next = NULL;
		tail->idx--;
		nn->prev = tail;
		tail->next = nn;
		tail = nn;
	}

	arr_size++;
	tail->a[tail->idx] = x;
	tail->idx++;
}

void popBack()
{
	if (arr_size == -1)
	{
		cout << "Vector is empty cannot pop_back!" << "\n";
	}
	else if (tail->idx - 1 == 0)
	{
		if (tail->prev == NULL)
		{
			tail = NULL;
			head = NULL;
			arr_size--;
		}
		else
		{
			Lv *temp = tail;
			tail = tail->prev;
			free(temp);
			arr_size--;
		}
	}
	else
	{
		arr_size--;
		tail->idx--;

	}
}

int getSize()
{
	return arr_size + 1;

}

void getEle(int z)
{
	if (head == NULL || z > arr_size)
	{
		cout << "invalid index\n";
		return;
	}
	else
	{
		Lv *temp = head;
		int j = 0;
		for (int i = 0; i <= arr_size; i++)
		{
			if (i == z)
			{
				cout << "element at index " << z << " is " << temp->a[j] << "\n";
				break;
			}

			if (j < 1000000)
			{
				j++;
			}
			else
			{
				temp = temp->next;
				j = 0;
				j++;
			}
		}
	}
}

void display_vector()
{
	if (head == NULL)
	{
		cout << "Vector is empty!\n";
	}

	cout << "Vector elements are: ";
	Lv *temp = head;
	int j = 0;
	for (int i = 0; i <= arr_size; i++)
	{
		if (j < 1000000)
		{
			cout << temp->a[j] << " ";
			j++;
		}
		else
		{
			temp = temp->next;
			j = 0;
			cout << temp->a[j] << " ";
			j++;
		}
	}

	cout << "\n";
}

bool isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	clock_t begin = clock();
	ifstream fin;
	fin.open("input_1.txt");
	int q;
	while (fin >> q)
	{
		switch (q)
		{
			case 1:
				int x;
				fin >> x;
				pushBack(x);
				break;
			case 2:
				popBack();
				break;
			case 3:
				cout<<getSize()<<"\n";
				break;
			case 4:
				int z;
				fin >> z;
				getEle(z);
				break;
			case 5:
				display_vector();
				break;
			case 6:
				cout <<isEmpty()<<"\n";
				break;
			default:
				exit(0);
		}
	}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout <<"execution time:"<< time_spent;

	return 0;
}
