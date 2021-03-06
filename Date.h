// ------------------------
// projects/c++/date/Date.h
// Copyright (C) 2010
// Glenn P. Downing
// ------------------------

#ifndef Date_h
#define Date_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <utility>   // !=, <=, >, >=

/*

namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

// -----
// using
// -----

using namespace std::rel_ops;

// ----
// Date
// ----

template <typename T>
class Date {
    public:
        // ----------
        // operator +
        // ----------

        /**
         * adds rhs to the Date lhs.
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        friend Date operator + (Date lhs, const T& rhs) {
          try{
            const Date<int> result(lhs.get_days() + rhs);
            return result;
          }
          catch (std::invalid_argument& e) {throw;}
        }

        // ----------
        // operator -
        // ----------

        /**
         * subtracts rhs from the Date lhs.
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        friend Date operator - (Date lhs, const T& rhs) {
          try{
            int x = lhs.get_days() - rhs;
            const Date<int> result(x);
            return result;
          }
          catch (std::invalid_argument& e) {throw;}
        }

        // -----------
        // operator <<
        // -----------

        /**
         * @param  lhs an ostream
         * @param  rhs a date
         * @return the ostream
         * output a string representation of the date (e.g. "3 Feb 2008")
         * you can loop through an array of month names
         */
        friend std::ostream& operator << (std::ostream& lhs, const Date& rhs) {
            const std::string month_strings[] = {" ", "Jan", "Feb", "Mar", "April", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
            return lhs << rhs.get_day() << " " << month_strings[rhs.get_month()] << " " << rhs.get_year();}

    private:
        // ----
        // data
        // ----

        T _day;
        T _month;
        T _year;
        int _days;

    public:
        // -----
        // valid
        // -----

        /**
         * checks if the current date is valid or not.
         */
        bool valid () const {
            return (_day > 0) && (_day < 32) && (_month > 0) && (_month < 13) && (_year > 1599);}

        // ----------------
        // accessor methods
        // ----------------
        T get_day() const
        {
          return _day;
        }
        
        T get_month() const
        {
          return _month;
        }
        
        T get_year() const
        {
          return _year;
        }
        
        T get_days() const
        {
          return _days;
        }

        // -----------
        // constructor
        // -----------

        /**
         * @param days >= 0
         * Date(0) -> 1 Jan 1600
         * you can loop through an array of month days
         */
        Date (const T& days) {
	    using namespace std;
            assert(days >= 0);
            int thisyear[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int d = days;
            _days = days;
            _day = 1;
            _month = 1;
            _year = 1600;

            int test = 366;
            while (d >= test){
              if((_year % 400 == 0) || (_year % 4 == 0 && _year % 100 != 0)){
                d -= 366;
                _year++;}
              else {
                d -= 365;
                _year++;
              }
              test = (leap_year()) ? 366 : 365;
            }

	    if(leap_year()) thisyear[2]++;

            while(d > thisyear[_month])
            {
              d = d - thisyear[_month];
              _month++;
            }

            d++;
	    _day = d;


            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // -------
        // to_days
        // -------
 
        /**
         * @return the number of days since 1 Jan 1600, >= 0
         * 1 Jan 1600 -> 0
         */
        T to_days () const {
          //const int begdays = 584388;
          int y = _year - 1600;
          T days = (365 * y) + (y / 4) - (y / 100) + (y / 400);
          int thisyear[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
          if(leap_year()) thisyear[2]++;
          for(int i = 1; i < _month; i++) days += thisyear[i];
          days += _day;

          if(!leap_year())
            days++;
          return days - 1;
        }

    public:
        // -----------
        // constructor
        // -----------

        /**
         * @param  day   >= 1 && <= 31
         * @param  month >= 1 && <= 12
         * @param  year  >= 1600
         * @throws invalid_argument if the resulting date is invalid
         */
        Date (const T& day, const T& month, const T& year) {
            _day = day;
            _month = month;
            _year = year;
            _days = to_days();
            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // Default copy, destructor, and copy assignment.
        // Date (const Date&);
        // ~Date ();
        // Date& operator = (const Date&);

        // -----------
        // operator ==
        // -----------

        /**
         * checks if this Date is equal to the Date rhs.
         */
        bool operator == (const Date& rhs) const {
          return get_days() == rhs.get_days();}

        // ----------
        // operator <
        // ----------

        /**
         * checks if this date is less than the Date rhs.
         */
        bool operator < (const Date& rhs) const {
            return get_days() < rhs.get_days();}

        // -----------
        // operator +=
        // -----------

        /**
         * adds days tho this Date and assigns the value to this Date.
         * @param  days the number of days to add (may be negative!)
         * @return the date resulting from adding days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator += (const T& days) {
          try{
            Date(_days + days);
            return *this;}
          catch(std::invalid_argument& e) {throw;}
        }

        // -----------
        // operator -=
        // -----------

        /**
         * subtracts days from this Date and assigns the value to this Date.
         * @param  days the number of days to subtract (may be negative!)
         * @return the date resulting from subtracting days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator -= (const T& days) {
          try{
            Date(_days - days);
            return *this;}
          catch(std::invalid_argument& e) {throw;}
        }

        // ----------
        // operator -
        // ----------

        /**
         * determines the number of days between this Date and the Date rhs.
         * @return the number of days between the dates (lhs - rhs)
         */
        T operator - (const Date& rhs) const {
            return get_days() - rhs.get_days();}

        // ---------
        // leap_year
        // ---------

        /**
         * checks if this year is a leap year or not.
         */
        bool leap_year () const {
            if(_year % 400 == 0)
              return true;
            else if(_year % 100 == 0)
              return false;
            else if(_year % 4 == 0)
              return true;
            else
              return false;}};

#endif // Date_h


