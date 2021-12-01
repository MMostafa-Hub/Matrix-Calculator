/*
CSE131 Project
Name:Mohamed Mostafa Ibrahim | Name:Mohamed Medhat Hanafy | Name:Mohamed Nasser Sayed Ahmed
ID: 1806165					 | ID: 1801113				  | ID: 1805791
Year : 1st Electrical
*/
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <conio.h>
#define  maxSize  10

using namespace std;

float** declareMat();
float** getFromUserA(string strA, float* A[maxSize], int* row1, int* col1);
float** getFromUserB(string strB, float* B[maxSize], int* row2, int* col2);
float** stoMat(string x, int* row, int* column);
void printMat(float* arr[maxSize], int m, int n);
float** multMat(float* arr1[maxSize], float* arr2[maxSize], int m1, int n1, int m2, int n2);
float** transMat(float* arr[maxSize], int m, int n);
float** addMat(float* arr1[maxSize], float* arr2[maxSize], int m1, int n1, int m2, int n2);
float** subMat(float* arr1[maxSize], float* arr2[maxSize], int m1, int n1, int m2, int n2);
float detMat(float* a[maxSize], int m, int n);
float** cofMat(float* a[maxSize], int m, int n);
float** swapRow(float* a[maxSize], int m, int n, int r);
float** constMultMat(float* arr[maxSize], int m, int n, float c);
float** InverseMat(float* arr[maxSize], int m, int n);
float** adjMat(float* arr[maxSize], int m, int n);

/*
**********************************Please enter the matrix in on line like the one in the form "[1.2 2.2 3.1; -4.5 5.4 6.3; 2.3 5.2 4.7]"**********
**********************************YOU MUST ADD A SPACE BETWEEN TWO NUMBERS TO MAKE THE PROGRAM WORK AS INTENDED**********************************
*/

int main()
{
	string strA, strB, operation, exit;
	int mA = 0, nA = 0, mB = 0, nB = 0, i = 0, op = 0;
	float constant;
	float** A = declareMat(); // declaring matrix A
	float** B = declareMat(); // declaring Matrix B
	float** C = declareMat(); // declaring Matrix C
	string repeatoperation = "";
	do
	{
		cout << "__________________________________________________________________________________________________________________\n";
		cout << "1:Addition C=A+B\n";
		cout << "2:Subtraction C=A-B\n";
		cout << "3:Matrix Multiplication C=A*B\n";
		cout << "4:Transpose C=A'\n";
		cout << "5:Division C=A/B\n";
		cout << "                                            ***EXTRA FUNCTIONS***                                                  \n";
		cout << "6:Determinant det(A):\n";
		cout << "7:Adjoint C=Adj(A):\n";
		cout << "8:Inverse C=Inv(A)\n";
		cout << "9:Constant Multiplication C=const * A:\n";
		cout << "__________________________________________________________________________________________________________________\n";
		cout << "if you want to exit the program just type 'exit' without any spacing at any time\n\n";
		do
		{
			cout << "please enter the number of the operation you want -> ";
			getline(cin, operation);
			op = abs((int)operation[0] - 48);

			if (op > 9 || op < 1)
			{
				for_each(operation.begin(), operation.end(), [](char& c) {
					c = ::tolower(c);
				});
			}
			if (operation == "exit") return 0;
			else if (op > 9 || op < 1)
			{
				cout << "please enter a valid operation\n";
			}

		} while (op > 9 || op < 1);

		switch (op)
		{
		case 1:
			do
			{
				do
				{
					if (repeatoperation == "yes")
					{
						cout << " existed Matrix A:\n";
						printMat(C, mA, nA);
						A = C;
					}
					else
					{
						A = getFromUserA(strA, A, &mA, &nA);
						if (A == 0) return 0;
						cout << "matrix A:\n";
						printMat(A, mA, nA);
					}
					B = getFromUserB(strB, B, &mB, &nB);
					if (B == 0) return 0;
					cout << "matrix B:\n";
					printMat(B, mB, nB);

					if (!addMat(A, B, mA, nA, mB, nB))
					{
						cout << "DIMENSION ERROR : the size of A must be EQUAL to the size of B\n";
					}
				} while (!addMat(A, B, mA, nA, mB, nB));
				cout << "The Sum Equals C=A+B :\n";
				C = addMat(A, B, mA, nA, mB, nB);
				printMat(C, mA, nA);
				cout << "====================================================================================================== \n ";
				cout << "If You want to use The add the result with another matrix just type 'yes' if not type any thing  \n";
				cout << "====================================================================================================== \n ";
				cin >> repeatoperation;
				if (repeatoperation == "exit") return 0;
				cin.get();
			} while (repeatoperation == "yes");
			break;
		case 2:
			do
			{
				do
				{
					if (repeatoperation == "yes")
					{
						cout << " existed Matrix A:\n";
						printMat(C, mA, nA);
						A = C;
					}
					else
					{
						A = getFromUserA(strA, A, &mA, &nA);
						if (A == 0) return 0;
						cout << "matrix A:\n";
						printMat(A, mA, nA);
					}
					B = getFromUserB(strB, B, &mB, &nB);
					if (B == 0) return 0;
					cout << "matrix B:\n";
					printMat(B, mB, nB);

					if (!subMat(A, B, mA, nA, mB, nB))
					{

						cout << "DIMENSION ERROR : the size of A must be EQUAL to the size of B\n";
					}
				} while (!subMat(A, B, mA, nA, mB, nB));
				cout << "The Difference Equals C=A-B :\n";
				C = subMat(A, B, mA, nA, mB, nB);
				printMat(C, mA, nA);
				cout << "====================================================================================================== \n ";
				cout << "If You want to use The subtract the result with another matrix just type 'yes' if not type any thing  \n";
				cout << "====================================================================================================== \n ";
				cin >> repeatoperation;
				if (repeatoperation == "exit") return 0;
				cin.get();
			} while (repeatoperation == "yes");
			break;
		case 3:
			do
			{
				do
				{
					if (repeatoperation == "yes")
					{
						cout << " existed Matrix A:\n";
						printMat(C, mA, nA);
						A = C;
					}
					else
					{
						A = getFromUserA(strA, A, &mA, &nA);
						if (A == 0) return 0;
						cout << "matrix A:\n";
						printMat(A, mA, nA);
					}
					if (B == 0) return 0;
					B = getFromUserB(strB, B, &mB, &nB);
					cout << "matrix B:\n";
					printMat(B, mB, nB);

					if (!multMat(A, B, mA, nA, mB, nB))
					{
						cout << "DIMENSION ERROR : the number of COLUMNS in A must be EQUAL to number of ROWS in B\n";
					}
				} while (!multMat(A, B, mA, nA, mB, nB));
				cout << "The Product Equals C=A*B :\n";
				C = multMat(A, B, mA, nA, mB, nB);
				printMat(C, mA, nA);
				cout << "====================================================================================================== \n ";
				cout << "If You want to use The Multiply the result with another matrix just type 'yes' if not type any thing \n";
				cout << "====================================================================================================== \n ";
				cin >> repeatoperation;
				if (repeatoperation == "exit") return 0;
				cin.get();
			} while (repeatoperation == "yes");
			break;
		case 4:

			A = getFromUserA(strA, A, &mA, &nA);
			if (A == 0) return 0;
			cout << "matrix A:\n";
			printMat(A, mA, nA);

			cout << "The Transpose Equals C=A' :\n";
			C = transMat(A, mA, nA);
			printMat(C, nA, mA);
			break;
		case 5:
			do
			{
				do
				{
					if (repeatoperation == "yes")
					{
						cout << " existed Matrix A:\n";
						printMat(C, mA, nA);
						A = C;
					}
					else
					{

						A = getFromUserA(strA, A, &mA, &nA);
						if (A == 0) return 0;
						cout << "matrix A:\n";
						printMat(A, mA, nA);
					}
					B = getFromUserB(strB, B, &mB, &nB);
					if (B == 0) return 0;
					cout << "matrix B:\n";
					printMat(B, mB, nB);
					if (mA != mB || nA != nB)
					{
						cout << "DIMENSION ERROR : the size of A must be EQUAL to the size of B\n";
					}
					else if (!detMat(B, mB, nB))
					{
						cout << "MATH ERROR : the determinant of B equals ZERO\n";
					}
				} while ((mA != mB || nA != nB) || !detMat(B, mB, nB));
				cout << "The Quotinont Equals C=A/B :\n";
				C = multMat(A, InverseMat(B, mB, nB), mA, nA, mB, nB);
				printMat(C, mA, nA);
				cout << "===================================================================================================== \n ";
				cout << "If You want to use The divide the result with another matrix just type 'yes' if not type any thing \n";
				cout << "====================================================================================================== \n ";
				cin >> repeatoperation;
				if (repeatoperation == "exit") return 0;

				cin.get();
			} while (repeatoperation == "yes");
			break;
		case 6:
			if (repeatoperation == "yes")
			{
				cout << " existed Matrix A:\n";
				printMat(C, mA, nA);
				A = C;
			}
			else
			{
				A = getFromUserA(strA, A, &mA, &nA);
				if (A == 0) return 0;
				cout << "matrix A:\n";
				printMat(A, mA, nA);
			}
			cout << "The Determinant of A Equals C=det(A) :\n";
			cout << detMat(A, mA, nA) << endl;;
			break;
		case 7:
			do
			{
				if (repeatoperation == "yes")
				{
					cout << " existed Matrix A:\n";
					printMat(C, mA, nA);
					A = C;
				}
				else
				{
					A = getFromUserA(strA, A, &mA, &nA);
					if (A == 0) return 0;
					cout << "matrix A:\n";
					printMat(A, mA, nA);
				}
				if (mA != nA)
				{
					cout << "DIMENSION ERROR : the size of A must be SQUARE\n";
				}
			} while (mA != nA);
			cout << "The Adjoint of A Equals C=adj(A) :\n";
			C = adjMat(A, mA, nA);
			printMat(C, mA, nA);
			break;
		case 8:

			do
			{
				if (repeatoperation == "yes")
				{
					cout << " existed Matrix A:\n";
					printMat(C, mA, nA);
					A = C;
				}
				else
				{
					A = getFromUserA(strA, A, &mA, &nA);
					if (A == 0) return 0;
					cout << "matrix A:\n";
					printMat(A, mA, nA);
				}
				if (mA != nA)
				{
					cout << "DIMENSION ERROR : the size of A must be SQUARE\n";
				}
				else if (!detMat(A, mA, nA))
				{
					cout << "MATH ERROR : the determinant of A equals ZERO\n";
				}
			} while (!detMat(A, mA, nA) || mA != nA);
			cout << "The Inverse of A  C=Inv(A) :\n";
			C = InverseMat(A, mA, nA);
			printMat(C, mA, nA);

			break;
		case 9:
			if (repeatoperation == "yes")
			{
				cout << " existed Matrix A:\n";
				printMat(C, mA, nA);
				A = C;
			}
			else
			{
				A = getFromUserA(strA, A, &mA, &nA);
				if (A == 0) return 0;
				cout << "matrix A:\n";
				printMat(A, mA, nA);
			}
			cout << "please Enter the constant :";
			cin >> constant;
			cin.ignore();
			C = constMultMat(A, mA, nA, constant);
			cout << "The Product Equals C=const*A :\n";
			printMat(C, mA, nA);
			break;

		}
		cout << "if you want another operation type any thing if not, type 'exit' -> ";
		getline(cin, exit);


	} while (exit != "exit");

}

