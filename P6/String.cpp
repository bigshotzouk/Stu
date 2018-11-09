#include "String.h"

String::String()
{
	m_Data = "";
	m_Lenth = 0;
}

String::String(char * Data)
{
	m_Data = new char[sizeof(*Data)];
	Assignment(m_Data, Data);
	m_Lenth = sizeof(*Data);
}

String::String(String & a)
{
	m_Data = new char[a.m_Lenth];
	Assignment(m_Data, a.m_Data);
	m_Lenth = a.m_Lenth;
}

int String::Lenth()
{
	return m_Lenth;
}

bool String::IsEmpty()
{//空返回1 反之0
	return !m_Lenth;
}

void String::Clear()
{
	delete m_Data;
	m_Data = "";
	m_Lenth = 0;
}

String & String::SubStr(int pos, int end)
{//起始位置1 位置包括pos，不包括end
	if (pos < 1 || end > this->m_Lenth)
	{
		return String();
	}

	int L = end - pos + 1;
	char *Sub = new char[L];
	Assignment(Sub, this->m_Data + pos - 1, L);

	String New(Sub);
	return New;
}

bool String::operator>(String & b)
{
	int i = 0, j = 0;
	char *Data_a = this->m_Data;
	char *Data_b = b.m_Data;
	int Max_a = this->m_Lenth;
	int Max_b = b.m_Lenth;

	for (i, j; i < Max_a && j < Max_b; i++, j++)
	{
		if (Data_a[i] > Data_b[j])
			return true;
		else if (Data_a[i] < Data_b[j])
			return false;
	}

	return Max_a > Max_b;
}

bool String::operator<(String & b)
{
	int i = 0, j = 0;
	char *Data_a = this->m_Data;
	char *Data_b = b.m_Data;
	int Max_a = this->m_Lenth;
	int Max_b = b.m_Lenth;

	for (i, j; i < Max_a && j < Max_b; i++, j++)
	{
		if (Data_a[i] < Data_b[j])
			return true;
		else if (Data_a[i] > Data_b[j])
			return false;
	}

	return Max_a < Max_b;
}

bool String::operator==(String & b)
{
	int i = 0, j = 0;
	char *Data_a = this->m_Data;
	char *Data_b = b.m_Data;
	int Max_a = this->m_Lenth;
	int Max_b = b.m_Lenth;

	for (i, j; i < Max_a && j < Max_b; i++, j++)
	{
		if (Data_a[i] != Data_b[j])
			return false;
	}

	return Max_a == Max_b;
}

String & String::operator+(String & b)
{
	char *NewData = new char(*this->m_Data + *b.m_Data);
	String New(NewData);
	return New;
}

String::~String()
{
	delete m_Data;
}

void Assignment(char Array[], char * List,int Lenth)
{
	if(!Lenth)
		Lenth = sizeof(*List);
	for (int i = 0; i < Lenth; i++)
	{
		Array[i] = *(List + i);
	}
}
