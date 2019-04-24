#ifndef _Table_
#define _Table_
#include "List.h"
#include <vector>
#define BUFF 2

template<class Tip>
class unsortedTable
{
public:
	int sizeMass;
	int rightBorder;
	List<Tip> *polinoms;

	unsortedTable()
	{
		flout << "creat the unsorted table" << endl;
		sizeMass = 2;
		rightBorder = -1;
		polinoms = new List<Tip>[sizeMass];
	}
	void clrTable()
	{
		flout << "delete the unsorted table" << endl;
		delete[] polinoms;
		sizeMass = 2;
		rightBorder = -1;
		polinoms = new List<Tip>[sizeMass];
	}

	unsortedTable(unsortedTable<Tip> &A)
	{
		flout << "copy the unsorted table" << endl;
		sizeMass = A.sizeMass;
		rightBorder = A.rightBorder;

		delete[] polinoms;

		polinoms = new List<Tip>[sizeMass];

		for (int i = 0; i <= rightBorder; i++)
			polinoms[i] = A.polinoms[i];
	}

	void expansion()
	{
		int i;
		flout << "expansion the unsorted table" << endl;
		unsortedTable<Tip> A(*this);
		sizeMass = BUFF * sizeMass;
		polinoms = new List<Tip>[sizeMass];
		for (i = 0; i <= A.rightBorder; i++)
			polinoms[i] = A.polinoms[i];
		flout << "    number of actions: " <<i<< endl;
	}

	int search(List<Tip> a)
	{
		int i;
		flout << "search in the unsorted table" << endl;
		for (i = 0; i <= rightBorder; i++)
			if (comp(polinoms[i], a) == 0)
			{
				flout << "    number of actions: " << i << endl;
				return i;
			}
		flout << "    number of actions: " << i << endl;
		cout << endl << "there are no such polynomials in the unsorted table" << endl;
		return -1;
	}

	void del(List<Tip> a)
	{
		flout << "del elem in unsorted table"<< endl;
		int i;
		int k = search(a);
		if (k == -1)
			return;
		for (i = k; i < rightBorder; i++)
			polinoms[i] = polinoms[i + 1];
		flout << "    number of actions: " << i << endl;
		rightBorder--;
	}

	List<Tip> getPolinom(int i)
	{
		flout << "get at unsorted table(1 action)"<< endl;

		if ((i < 0) || (i > rightBorder))
			throw("uncorrect index");
	
		return polinoms[i];
	}

	void inseart(List<Tip> a)
	{
		int i;
		flout << "inseart in unsorted table" << endl;

		if (sizeMass == rightBorder)
			(*this).expansion();

		for (i = 0; i <= rightBorder; i++)
			if (comp(polinoms[i], a) == 0)
			{
				flout << "    number of actions: " << i << endl;
				return;
			}

		polinoms[rightBorder + 1] = a;
		flout << "    number of actions: " << i+1 << endl;
		rightBorder++;
	}

	void show()
	{
		cout << "Size = " << rightBorder + 1 << endl;
		for (int i = 0; i <= rightBorder; i++)
		{
			cout << i << ") ";
			polinoms[i].print();
			cout << endl;
		}
	}

	void work()
	{
		flout << "work with unsorted table" << endl;

		int ind2;
		do
		{
			system("cls");
		(*this).show();
		
		cout << endl << "What you want doing?" << endl;
		cout << "1 - insert, 2 - delete, 0 - back" << endl;
		
			do {
				cin >> ind2;
			} while (!check(ind2, 0, 2));

			if (ind2 == 1)
			{
				List<double> T;
				T.record();
				(*this).inseart(T);
			}
			if (ind2 == 2)
			{
				List<double> T;
				T.record();
				(*this).del(T);
			}
		} while (ind2 != 0);
	}
};


template<class Tip>
class sortedTable
{

public:
	int sizeMass;
	int rightBorder;
	List<Tip> *polinoms;
	
	sortedTable()
	{
		flout << "creat the sorted table" << endl;
		sizeMass = 2;
		rightBorder = -1;
		polinoms = new List<Tip>[sizeMass];
	}
	
	sortedTable(sortedTable<Tip> &A)
	{
		int i;
		flout << "copy the sorted table" << endl;
		sizeMass = A.sizeMass;
		rightBorder = A.rightBorder;

		delete[] polinoms;

		polinoms = new List<Tip>[sizeMass];

		for (i = 0; i <= rightBorder; i++)
			polinoms[i] = A.polinoms[i];
		flout << "    number of actions: " << i + 1 << endl;

	}

	void clrTable()
	{
		flout << "del the sorted table" << endl;
		sizeMass = 2;
		rightBorder = -1;
		polinoms = new List<Tip>[sizeMass];
	}

	void expansion()
	{
		flout << "expansion the sorted table" << endl;
		int i;
		sortedTable<Tip> A(*this);
		sizeMass = BUFF * sizeMass;
		polinoms = new List<Tip>[sizeMass];
		for (i = 0; i <= A.rightBorder; i++)
			polinoms[i] = A.polinoms[i];
		flout << "    number of actions: " << i + 1 << endl;


	}

	int search(List<Tip> a) 
	{
		int tmp=0;
		flout << "search in the sorted table" << endl;

		bool flag = false;
		int l = 0;
		int r = rightBorder;
		int mid;

		while ((l <= r) && (flag != true))
		{
			tmp++;
			mid = (l + r) / 2;

			if (comp(polinoms[mid], a) == 0) flag = true;
			if (comp(polinoms[mid], a) == 1) r = mid - 1;
			else l = mid + 1;
		}
		flout << "    number of actions: " << tmp << endl;

		if (flag == true)
			return mid;
		cout << endl << "there are no such polynomials in the unsorted table" << endl;
		return -1;
	}

	void del(List<Tip> a)
	{
		flout << "del elem in sorted table" << endl;
		int i;
		int k = search(a);
		if (k == -1)
			return;
		for (i = k; i < rightBorder; i++)
			polinoms[i] = polinoms[i + 1];
		rightBorder--;
		flout << "    number of actions: " << i << endl;


	}

	List<Tip> getPolinom(int i)
	{
		flout << "get at sorted table(1 action)" << endl;

		if ((i < 0) || (i > rightBorder))
			throw("uncorrect index");

		return polinoms[i];
	}

	void inseart(List<Tip> a)
	{
		flout << "inseart in sorted table" << endl;
		int tmp = 0;
		if (sizeMass == rightBorder)
			(*this).expansion();
		
		rightBorder++;
				
		bool flag = false;
		int l = 0; 
		int r = rightBorder;
		int mid;

		while ((l <= r) && (flag != true)) 
		{
			tmp++;
			mid = (l + r) / 2; 

			if (comp(polinoms[mid],a)==0) flag = true; 
			if (comp(polinoms[mid],a)==1) r = mid - 1; 
			else l = mid + 1;
		}
		flout << "    number of actions: " << tmp << endl;

		if (flag) {
			rightBorder--;
			return;
		}
		
		for (int i = rightBorder; i >= mid; i--)
		{
			polinoms[i + 1] = polinoms[i];
			tmp++;
		}
		

		polinoms[mid] = a;
		

		
		
	}

	void show()
	{
		cout << "Size = " << rightBorder + 1 << endl;
		for (int i = 0; i <= rightBorder; i++)
		{
			cout << i << ") ";
			polinoms[i].print();
			cout << endl;
		}
	}

	void work()
	{

		flout << "work with sorted table" << endl;
		int ind2;
		do
		{
			system("cls");
			(*this).show();

			cout << endl << "What you want doing?" << endl;
			cout << "1 - insert, 2 - delete, 0 - back" << endl;

			do {
				cin >> ind2;
			} while (!check(ind2, 0, 2));

			if (ind2 == 1)
			{
				List<double> T;
				T.record();
				(*this).inseart(T);
			}
			if (ind2 == 2)
			{
				List<double> T;
				T.record();
				(*this).del(T);
			}
		} while (ind2 != 0);
	}
};


template<class Tip>
class hashTable
{

public:
	const int sizeMass = 64;
	vector<List<double>> *polinoms;
	
	hashTable()
	{
		flout << "creat the hash table" << endl;
		polinoms = new vector<List<double>>[sizeMass];
	}

	void clrTable()
	{
		int i;
		flout << "delete the hash table" << endl;
		for (i = 0; i < sizeMass; i++)
			polinoms[i].clear();
		delete[] polinoms;
		polinoms = new List<List<double>>[sizeMass];
	}

	int hashCode(List<double> a)
	{
		flout << "hash code" << endl;
		int j=0;
		int hc = 0;
		Node<double> *tmp1 = a.head;
		while (tmp1 != nullptr)
		{
			hc += tmp1->power;
			tmp1 = tmp1->next;
			j++;
		}
		flout << "    number of actions: " << j << endl;

		return hc % 64;
	}

	void inseart(List<double> a)
	{
		flout << "iseart in the hash table" << endl;
		int hc = hashCode(a);
		polinoms[hc].push_back(a);
	}

	void work()
	{
		flout << "work with hash table" << endl;

		int ind2;
		do
		{
			system("cls");
			(*this).show();

			cout << endl << "What you want doing?" << endl;
			cout << "1 - insert, 2 - delete, 0 - back" << endl;

			do {
				cin >> ind2;
			} while (!check(ind2, 0, 2));

			if (ind2 == 1)
			{
				List<double> T;
				T.record();
				(*this).inseart(T);
			}
			if (ind2 == 2)
			{
				List<double> T;
				T.record();
				(*this).del(T);
			}
		} while (ind2 != 0);
	}

	int search(List<Tip> a)
	{
		flout << "search in hash table" << endl;
		int j=0;
		int hc = hashCode(a);

		vector<List<double>> tmp1 = polinoms[hc];
		for(int i = 0; i< tmp1.size(); i++)
		{
			j++;
			if (comp(tmp1[i], a) == 0)
			{
				flout << "    number of actions: " << j << endl;
				return j -1;
			}
		}
		flout << "    number of actions: " << j << endl;
		cout << endl << "there are no such polynomials in the unsorted table" << endl;
		return -1;
	}

	void del(List<Tip> a)
	{
		flout << "del elem in hash table(action as del elem in vector)" << endl;

		int k = search(a);
		if (k == -1)
			return;
		int hc = hashCode(a);

		auto iter = polinoms[hc].cbegin(); 
		polinoms[hc].erase(iter + k);
	
	}

	void show()
	{
		for (int i = 0; i < 64; i++)
		{
			if (!polinoms[i].empty())
			{
				cout << i << ")" << endl;
				for (int j = 0; j < polinoms[i].size(); j++)
				{
					cout << "    " << i << "." << j << ") ";
					polinoms[i][j].print();
					cout << endl;
				}
			}
			
		}
	}

	List<Tip> getPolinom(int tmp1, int tmp2)
	{
		flout << "get at hash table" << endl;
		
		return polinoms[tmp1][tmp2];
	}
};


#endif _Table_
