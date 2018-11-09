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
	int Index_normal(String &b);
	int Index_next(String &b);
	int next(int j);
	int Strlen(char *b);
	String &SubString(int pos,int end);
	void StrInsert(int pos,String &b);
	void StrInsert(int pos, char *b);
	bool operator > (String &b);
	bool operator < (String &b);
	bool operator == (String &b);
	String& operator + (String &b);
	String& operator = (String &b);
	~String();
	//友元
	friend void FindCommentStr(String &a,String &b);
	friend void Assignment(char Array[], char *List,int Lenth);//长度默认即定义为List的长度
};



