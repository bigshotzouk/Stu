#include<iostream>
#include<string>
#include"String.h"

using namespace std;

int main()
{
	String name = "chenbin";
	String name2 = "xiaomin222";
	//String name3 = name;
	String name4 = name + name2;
	cout << "����" << name.Lenth() << endl;
	cout << "����" << name4.Lenth() << endl;
}