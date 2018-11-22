#include <iostream>

using namespace std;

//显式
class Date
{
public:
	Date(int year = 1970, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!(/*(_year > 0) &&*/
			(_month > 0 && _month<13) && 
			(_day>0 && _day <= _GetDayOfMonth(_year,_month))))
		{
			_year = 1970;
			_month = 1;
			_day = 1;
		}

	}

	Date operator+(int days)
 	{
		if (days < 0)
		{
			return *this - (0 - days);
		}
		Date temp(*this);
		temp._day += days;
		while (temp._day > (days = _GetDayOfMonth(temp._year, temp._month)))
		{
			temp._day -= days;
			++temp._month;
			if (temp._month > 12)
			{
				temp._month = 1;
				++temp._year;
			}
		}
		return temp;
	}

	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day -= days;
		while (temp._day <= 0)
		{
			--temp._month;
			if (0 == temp._month)
			{
				temp._month = 12;
				--temp._year;
			}	
			temp._day += (days = _GetDayOfMonth(temp._year, temp._month));
		}
		return temp;
	}

	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	Date operator++(int)
	{
		Date temp(*this);
		++(*this);
		return temp;
	}
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		--(*this);
		return temp;
	}

	//2018 11  4
	//2019  1  1
	int operator-(const Date& d)
	{
		Date MinDate(*this);
		Date MaxDate(d);

		if (*this > d)
		{
			MinDate = d;
			MaxDate = *this;
		}
		int count = 0;
		while (MinDate != MaxDate)
		{
			++count;
			++MinDate;
		}
		return count;
	}
	
	bool operator>(const Date& d)const
	{
		if ((_year > d._year) || 
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
		{
				return true;
		}
		return false;
	}
	
	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

private:
	bool IsInvalidDate()//判断输入日期是否有效
	{
		if ((/*(_year > 0) &&*/
			(_month > 0 && _month<13) &&
			(_day>0 && _day <= _GetDayOfMonth(_year, _month))))
		{
			return true;
		}
		return false;
	}

	int _GetDayOfMonth(int year,int month)
	{
		int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (2 == month && _IsLeapYear(year))
		{
			day[month] += 1;
		}
		return day[month];
	}

	bool _IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
		{
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		cout << d._year << " " << d._month << " " << d._day;
		return _cout;
	}
	friend istream& operator>>(istream& _cin, Date& d)
	{
		cin >> d._year >> d._month >> d._day;
		if (!d.IsInvalidDate())
		{
			cout << "输入的日期无效" << d << endl;
		}
		return _cin;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 11, 13);
	Date d2(2019, 12, 13);
	cout << d1-d2 << endl;
	//cout << d1++ << endl;
	//cout << d1++ << endl;
	cin.get();
	return 0;
}