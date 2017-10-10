
#include "Date.h"

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(int startDay, int startMonth, int startYear)
{
    day = startDay;
    month = startMonth;
    year = startYear;
}

Date::~Date()
{

}
    /***************************************************************************
     ACCESSORS
     **************************************************************************/
        int Date::GetDay()
        {
            return day;
        }
        int Date::GetMonth()
        {
            return month;
        }
        int Date::GetYear()
        {
            return year;
        }

    /***************************************************************************
     MUTATORS
     **************************************************************************/
        void Date::SetDay(int newDay)
        {
            day = newDay;
        }
        void Date::SetMonth(int newMonth)
        {
            month = newMonth;
        }
        void Date::SetYear(int newYear)
        {
            year = newYear;
        }
        void Date::ClearDate()
        {
            day = 0;
            month = 0;
            year = 0;
        }

        void Date::StringToDate(QString input)
        {
            QString dayStr;
            QString monthStr;
            QString yearStr;

            for(int i = 0; i < 2; i++)
            {
                monthStr[i] = input[i];
            }
            for(int i = 3; i < 6; i++)
            {
                dayStr[i] = input[i];
            }
            for(int i = 6; i < 10; i++)
            {
                yearStr[i] = input[i];
            }
            day = dayStr.toInt();
            month = monthStr.toInt();
            year = yearStr.toInt();

        }

//	string Date::Output()
//	{
//		ostringstream output;

//		output << GetDay() << "/" << GetMonth() << "/" << GetYear();

//		return output.str();
//	}
