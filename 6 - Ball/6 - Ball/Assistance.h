#ifndef __ASSISTANCE_H__
#define __ASSISTANCE_H__
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <limits>
#include <cmath>
#include <fstream>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cstdarg>
#include <cassert>
#include<algorithm>
using namespace std;

enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

constexpr auto DEFAULT_SIZE = 1000;
constexpr auto DEFAULT_INFINITY = 1000000;


char GetChar(istream &inStream = cin);

template <class ElemType >
void Swap(ElemType &e1, ElemType &e2);

template<class ElemType>
void Display(ElemType elem[], int n);

template <class ElemType>
void Write(const ElemType &e);

class Error;

char GetChar(istream &inStream)
{
	char ch;
	while ((ch = (inStream).peek()) != EOF
		&& ((ch = (inStream).get()) == ' '
		|| ch == '\t'));
	return ch;
}

constexpr auto MAX_ERROR_MESSAGE_LEN = 100;

class Error
{
public:
	Error(const char *mes = "һ�����쳣!");
	~Error(void) {};
	void Show() const;
private:
	char message[MAX_ERROR_MESSAGE_LEN];
};

Error::Error(const char *mes)
{
	strcpy(message, mes);
}

void Error::Show()const
{
	cout << message << endl;
}


template <class ElemType >
void Swap(ElemType &e1, ElemType &e2)
{
	ElemType temp;
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
{
	for (int i = 0; i < n; i++)
		cout << elem[i] << "  ";
	cout << endl; 
}

template <class ElemType>
void Write(const ElemType &e)
{
	cout << e << endl;
}

#endif
