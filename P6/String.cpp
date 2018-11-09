#include "String.h"
//ggg
String::String()
{
	m_Data = "";
	m_Lenth = 0;
}

String::String(char * Data)
{
	m_Data = new char[Strlen(Data)];
	Assignment(m_Data, Data,Strlen(Data));
	m_Lenth = Strlen(Data);
}

String::String(String & a)
{
	m_Data = new char[a.m_Lenth];
	Assignment(m_Data, a.m_Data,Strlen(a.m_Data));
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
	delete[] m_Data;
	m_Data = "";
	m_Lenth = 0;
}

int String::Index_normal(String &b)
{//普通版本的查找子串
	if(this->m_Lenth < b.m_Lenth)
		return -1;//长度不可能比子串小

	int L = b.m_Lenth;
	String Compare;
	for(int i = 0;i <= this->m_Lenth - L;i++)
	{
		Compare = SubString(i + 1,i + L);
		if(Compare == b)
			return i + 1;
	}
	return -1;
}

int String::Index_next(String &b)
{//next版本
	return -1;
}

int String::next(int j)
{
	j--;
	char *p = m_Data;
	if(j == 0)
		return 0;
	else if(j == 1)
	{
		return 1;
	}
	int result = 0;
	String T;
	for(int i = 0;i < j;i++)
	{
		if(SubString(1,i+1) == SubString(j-i-1,j-1))
		{
			result = i + 2;
		}
	}

	return result;
}

int String::Strlen(char *b)
{
	char * p = b;
	int Lenth = 0;
	
	while(*p != '\0')
	{
		Lenth++;
		p++;
	}

	return Lenth;
}

String & String::SubString(int pos, int end)
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

void String::StrInsert(int pos, String & b)
{
	pos = pos - 1;
	int L = this->m_Lenth + b.m_Lenth;
	char *Char_a = this->m_Data;
	char *Char_b = b.m_Data;
	char *New = new char[L];
	int Max_a = this->m_Lenth;
	int Max_b = b.m_Lenth;

	if (pos < 1 || pos > Max_a)
	{
		return;
	}

	for (int i = 0; i < pos; i++)
	{
		New[i] = Char_a[i];
	}
	for (int i = 0; i < Max_b; i++)
	{
		New[i + pos] = Char_b[i];
	}
	for (int i = pos; i < Max_a - pos; i++)
	{
		New[i + Max_b] = Char_a[i];
	}

	delete[] m_Data;
	m_Data = New;
	m_Lenth = L;
}

void String::StrInsert(int pos, char * b)
{
	String New(b);
	StrInsert(pos,New);
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
	char *NewData = new char[this->m_Lenth + b.m_Lenth];
	
	for (int i = 0; i < m_Lenth; i++)
	{
		NewData[i] = m_Data[i];
	}
	for (int i = 0; i < b.m_Lenth; i++)
	{
		NewData[m_Lenth + i] = b.m_Data[i];
	}

	String New(NewData);
	return New;
}

String & String::operator=(String & b)
{
	delete[] m_Data;
	m_Data = new char[b.m_Lenth];
	Assignment(m_Data,b.m_Data,Strlen(b.m_Data));
	m_Lenth = b.m_Lenth;

	return *this;
}

String::~String()
{
	delete[] m_Data;
}

void FindCommentStr(String &a,String &b)
{
	int L = a.m_Lenth < b.m_Lenth ? a.m_Lenth : b.m_Lenth;
	int Max_Lenth = 0;
	if(a.m_Lenth > b.m_Lenth)
	{
		String t;
		t = a;
		a = b;
		b = t;
	}//将大小排成从小到大

	String T;
	for(int i = 0;i < a.m_Lenth;i++)
	{
		for(int j = 0;j < a.m_Lenth - i;j++)
		{
			T = a.SubString(i + 1,j + 1);
			if(b.Index_normal(T) != -1)
				Max_Lenth = T.m_Lenth;
		}
	}
}

void Assignment(char Array[], char * List,int Lenth)
{
	for (int i = 0; i < Lenth; i++)
	{
		Array[i] = *(List + i);
	}
}
