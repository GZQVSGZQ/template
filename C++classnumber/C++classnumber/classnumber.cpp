#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;


#if 0
namespace N1
{
	int a = 10;
}

int a = 20;

class Test
{
public:
	void SetA(int a)
	{
		_a = a;
	}

	void PrintA()
	{
		cout << _a << endl;
	}

protected:
	int _a;
};//1、尽量避免成员函数的参数与成员变量同名 2、类中的成员变量在类中具有全局作用域属性

int main()
{
	Test t;
	t.SetA(30);
	cout << N1::a << endl;
	cout << a << endl;
	t.PrintA();
	cin.get();
	return 0;
}
#endif

#if 0
class Student
{
public:
	void SetStudentInfo(char *name, char *gender, int age)
	{
		strcpy(_name,name);
		strcpy(_gender,gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

private:
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student S;
	S.SetStudentInfo("一郎", "男", 18);
	S.PrintStudentInfo();
	cout << sizeof(S) << endl;
	cin.get();
	return 0;
}
#endif


#if 0
class A
{
private:
	int _a;
	int _b;
	int _c;
};

int main()
{
	A a;
	//int *p = (int *)((char*)&a + 8);
	//int *p = (int *)((char*)&a + offsetof(A, _c));
	*p = 10;
	cin.get();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t, int a)
		: _t(t)
		, _a(a)
	{}
private:
	int _t;
	int &_a;
};

int main()
{
	Test T(1, 2);
	cin.get();
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year=1970,int month=1,int day=1)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(00,00,00)
	{
		cout << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date D(1996, 3, 2);
//	D.SetPrintf();
	//cout << << endl;
	cin.get();
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	Date(int year)
		: _year(year)
	{}

private:
	int _year;
	int _month;
	int _day;
};

int mian()
{
	Date D1(2018,11,12);
	D1 = 2018;//此处隐式类型转换
	cin.get();
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test()
	{
		cout << "Test()" << this << endl;
	}
	
	Test(const Test& t)
	{
		cout << "Test(const Test&)" << this << endl;
	}

	Test& operator = (const Test& t)
	{
		cout << this << "=" << &t << endl;
		return *this;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}
};

Test FunTest(Test t)
{
	Test t1;
	Test temp(t);
	t1 = temp;
	return t1;
}

void FunTest()
{
	Test t1, t2;
	t2 = FunTest(t1);
}

int main()
{
	FunTest();
	cin.get();
	return 0;
}
#endif

#if 0
//友元
class Date
{
	friend void TestFunc();
	friend ostream& operator<<(ostream& _cout,const Date& d);
public:
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void PrintfDate()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

	/*ostream& operator<<(ostream& _cout)
	{
		_cout << _year << " " << _month << " " << _day;
		return _cout;
	}*/

	
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "_" << d._month << "_" << d._day;
	return _cout;
}

class Time
{
	friend void TestFunc();
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

void TestFunc()
{
	Time t;
	t._hour = 10;

	Date d;
	d._year = 2018;
}

int main()
{
	Date d(2018, 7, 29);
	d.PrintfDate();
	//d.operator<<(cout);
	//d << cout;
	cout << d << endl;
	cin.get();
	return 0;
}
#endif


/*
//查看构造次数
class Test
{
public:
	Test()
	{
		+_count++;
	}
	Test(const Test& T)
	{
		_count++; 
	}
	~Test()
	{
		_count--;
	}
private:
	int _b;
	int _count;
};

void TestFunc()
{
	Test T1, T2, T3;
}*/


/*
//全局
int g_count = 0;//任何人都可修改
class Test
{
public:
	Test()
	{
		g_count++;
	}
	Test(const Test& t)
	{
		g_count++;
	}
	~Test()
	{
		g_count--;
	}
private:
	int _count;
};

void TestFunc()
{
	Test t1;
	Test t2(t1);
	Test t3;
	Test t4(t3);
}
int main()
{
	Test t0;
	TestFunc();
	cin.get();
	return 0;
}
*/



#if 0
//static所修饰的类成员，类的静态成员：静态的成员变量+静态的成员函数
class Test
{
public:
	Test()
	{
		s_count++;
	}
	Test(const Test& t)
	{
		s_count++;
	}
	~Test()
	{
		s_count--;
	}

	static int GetCount()//静态成员函数无this指针
	{
		//cout<<this<<endl;
		//
		return s_count;
	}

private:
	static int s_count;//只是声明,初始化在类外
};

int Test::s_count = 0;

void TestFunc()
{
	Test t1;
	Test t2(t1);
	Test t3;
	Test t4(t3);
}

int main()
{
	cout << Test::GetCount() << endl;//没有声明对象时，可以使用静态函数
	Test t1;
	Test t2(t1);
	Test t3;
	Test t4(t3);
	
	cout << t1.GetCount() << endl;
	//int a = 0;//比较两种的区别（都是下面这种调用）
	//a = t1.s_count;
	//a = Test::s_count;

	//cout << sizeof(t1) << endl;

	cin.get();
	return 0;
}
#endif

