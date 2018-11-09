#pragma once
class String
{
private:
	char *m_Data;
	int m_Lenth;
public:
	String();
	String(char *Data);
	String(String &a);
	int Lenth();
	bool IsEmpty();
	void Clear();
	String &SubStr(int pos,int end);
	bool operator > (String &b);
	bool operator < (String &b);
	bool operator == (String &b);
	String& operator + (String &b);
	~String();
};

void Assignment(char Array[], char *List,int Lenth = 0);

