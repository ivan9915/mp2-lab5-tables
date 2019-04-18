#include "table.h"


//if left <= X <= right -> check == true
//else check == false
bool check(int x, int l, int r)
{
	flout << "Go function check" << endl;
	if ((x >= l) && (x <= r))
	{
		flout << "    if operator - true" << endl;
		return true;
	}
	else
	{
		cout << endl << "uncorrect index" << endl;
		flout << "    if operator - false" << endl;
		return false;
	}
}

void main()
{
	int k;
	int tmp;
	List<double> A;
	List<double> B;
	List<double> R;

	unsortedTable<double> UT;
	sortedTable<double> ST;
	hashTable<double> HT;

	do
	{
		{
			system("cls");
			cout << "menu function:" << endl << "1 - To enter a polynom A" << endl;
			cout << "2 - To enter a polynom B" << endl << "3 - Selected operation" << endl;
			cout << "4 - Table" << endl;
			cout << "5 - Write result to table" << endl;
			cout << "6 - Search in table" << endl;
			cout << "0 - To exit" << endl;

			cout << "Polinom A: ";
			A.print();
			cout << endl;
			cout << "Polinom B: ";
			B.print();
			cout << endl;

			cout << "Polinom R: ";
			R.print();
			cout << endl;
		}

		do {
			cin >> k;
		} while (!check(k, 0, 6));

		switch (k)
		{
		case 1:	
		{
			A.ClrL();	
			system("cls");
			cout << "what metod to look?" << endl;
			cout << "1 - hand recording" << endl << "2 - the record from the table" << endl <<"0 - back"<< endl;
			do {
				cin >> tmp;
			} while (!check(tmp, 0, 2));
			if(tmp == 1)
				A.record();
			if (tmp == 2)
			{
				system("cls");
				cout << "what table to look?" << endl << "1 - unsorted table" << endl;
				cout << "2 - sorted table" << endl << "3 - Hash table" << endl << "0 - back" << endl;
				do {
					cin >> tmp;
				} while (!check(tmp, 0, 3));

				switch (tmp)
				{
				case 1:	
				{
					system("cls");
					UT.show(); 
					cout << "what index?" << endl;
					cin >> tmp;
					A = UT.getPolinom(tmp);
				}
				break;

				case 2:
				{
					system("cls");
					UT.show();
					cout << "what index?" << endl;
					do {
						cin >> tmp;
					} while (!check(tmp, 0, UT.rightBorder));
					A = UT.getPolinom(tmp);
				}break;

				case 3:
				{
					int  tmp1, tmp2;
					system("cls");
					HT.show();
					cout << "what index?" << endl;
					do {
						cin >> tmp1 >> tmp2;
					} while ((!check(tmp1, 0, 63)) && (!check(tmp2, 0, 63)));
					A = HT.getPolinom(tmp1, tmp2);
				}break;

				}
			}
		} break;

		case 2:
		{ 
			B.ClrL();
			system("cls");
			cout << "what metod to look?" << endl;
			cout << "1 - hand recording" << endl << "2 - the record from the table" << endl << "0 - back" << endl;

			do {
				cin >> tmp;
			} while (!check(tmp, 0, 2));

			if (tmp == 1)
				B.record();
			if (tmp == 2)
			{
				system("cls");
				cout << "what table to look?" << endl << "1 - unsorted table" << endl;
				cout << "2 - sorted table" << endl << "3 - Hash table" << endl << "0 - back" << endl;
				do {
					cin >> tmp;
				} while (!check(tmp, 0, 3));

				switch (tmp)
				{
				case 1:
				{
					system("cls");
					UT.show();
					cout << "what index?" << endl;
					do {
						cin >> tmp;
					} while (!check(tmp, 0, UT.rightBorder));
					B = UT.getPolinom(tmp);
				}
				break;

				case 2:
				{
					system("cls");
					UT.show();
					cout << "what index?" << endl;
					do {
						cin >> tmp;
					} while (!check(tmp, 0, UT.rightBorder));
					B = UT.getPolinom(tmp);
				}break;

				case 3:
				{
					int  tmp1, tmp2;
					system("cls");
					HT.show();
					cout << "what index?" << endl;
					do {
						cin >> tmp1 >> tmp2;
					} while ((!check(tmp1, 0, 63))&&(!check(tmp2, 0, 63)));
					B = HT.getPolinom(tmp1, tmp2);
				}break;
				}
			}
		}	break;

		case 3:
		{
			tmp = -1;
			cout << "to inter the nomber operation: 1 - add, 2 - subtraction, 3 - multiplication, 4 - multiplication by a constant" << endl;
			do {
				cin >> tmp;
			} while (!check(tmp, 1, 4));

			switch (tmp)
			{
			case 1:R = Add(A, B);break;
			case 2:R = Sub(A, B); break;
			case 3:R = Mull(A, B); break;
			case 4:
			{
				double a;
				cout << "To inter the constant" << endl;
				cin >> a;
				cout << "who? 1- A, 2- B" << endl;
				int i;
				cin >> i;
				if (i == 1)
					A.Mull(a);
				if (i == 2)
					B.Mull(a);
			} break;
			}



		} break;

		case 4:
		{
			tmp = -1;
			system("cls");
			cout << "what table to look?" << endl << "1 - unsorted table" << endl;
			cout << "2 - sorted table" << endl << "3 - Hash table" << endl <<"0 - back"<< endl;

			do {
				cin >> tmp;
			} while (!check(tmp, 0, 3));

						
			switch (tmp)
			{
			case 1:	UT.work(); break;

			case 2:
			{
				ST.work(); break;
			}break;

			case 3:
			{
				HT.work(); break;;
			}break;

			}
		} 
		break;

		case 5:
		{
			system("cls");
			cout << "what table?" << endl << "1 - unsorted table" << endl;
			cout << "2 - sorted table" << endl << "3 - Hash table" << endl << "0 - back" << endl;
			do {
				cin >> tmp;
			} while (!check(tmp, 0, 3));

			switch (tmp)
			{
			case 1:	UT.inseart(R); break;

			case 2: ST.inseart(R); break;

			case 3: HT.inseart(R); break;

			}
		}
		break;

		case 6:
		{
			tmp = -1;
			system("cls");
			cout << "what table to look?" << endl << "1 - unsorted table" << endl;
			cout << "2 - sorted table" << endl << "3 - Hash table" << endl << "0 - back" << endl;

			do {
				cin >> tmp;
			} while (!check(tmp, 0, 3));


			switch (tmp)
			{
			case 1:	
			{
				List<double> T;
				T.record();
				system("cls");
				int z = UT.search(T);
				if (z != -1)
					cout << "The polynomial you need in the unsorted table lies under the index: " << z << endl;
				system("pause");
			}
			break;

			case 2:
			{
				List<double> T;
				T.record();
				system("cls");
				int z = ST.search(T);
				if (z != -1)
					cout << "The polynomial you need in the unsorted table lies under the index: " << z << endl;
				system("pause");
			}break;

			case 3:
			{
				List<double> T;
				T.record();
				system("cls");
				int z = HT.search(T);
				if (z != -1)
					cout << "The polynomial you need in the unsorted table lies under the index: " << HT.hashCode(T)<<"."<< z << endl;
				system("pause");
			}break;

			}
		}
		break;
		}
	}while (k != 0);
}

