#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;
/*! enum class used on the listing menu */
enum type {
    PID = 1,       /*!< Passengers by ID */
    PNAME = 2,     /*!< Passengers by name */
    PAGE = 3,      /*!< Passengers by age */
    PACT = 4,      /*!< Active Passengers*/
    PINC = 5,      /*!< Active Passengers*/
    AID = 6,       /*!< Airplanes by ID */
    FID = 7,       /*!< Flights by ID */
    FPRICEL = 8,   /*!< Flights based on Price(lowest to highest) */
    FPRICEH = 9,   /*!< Flights based on Price(highest to lowest) */
    FDEST = 10,     /*!< Flights by Destination city */
    FTIME = 11      /*!< Flights by the time remaining to the time of the flight */
};
/*! enum used on time management menu */
enum date_member_t {
    YEAR = 1,
    MONTH = 2,
    DAY = 3,
    HOUR = 4,
    MINUTE = 5
};

static vector<int> monthdays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//! struct Date
/*! Used to implement dynamic time  */
struct Date {
    int day = 0; /*!< day */
    int month = 0; /*!< month */
    int year = 0; /*!< year */
    int hour = 0; /*!< hour */
    int minute = 0; /*!< minute */

    /**
     * @brief Date default constructor
     */
    Date() {};

    /**
     * @brief Date constructor
     * @param y year
     * @param mo month
     * @param d day
     * @param h hour
     * @param mn minutes
     */
    Date(int y, int mo, int d, int h, int mn) : year(y), month(mo), day(d), hour(h), minute(mn) {}

    /**
     * @brief overload of < operator for Date
     * @return true if lhs is before rhs or false otherwise
     */
    bool operator<(const Date &d1) const {
        return std::tie(year, month, day, hour, minute) < std::tie(d1.year, d1.month, d1.day, d1.hour, d1.minute);
    }

    /**
     * @breif overload of == operator for Date
     * @return true if lhs is equal to rhs or false otherwise
     */
    bool operator==(const Date &d1) const {
        return std::tie(year, month, day, hour, minute) == std::tie(d1.year, d1.month, d1.day, d1.hour, d1.minute);
    }

    /**
     * @brief overload of > operator for Date
     * @return true if lhs is after rhs or false otherwise
     */
    bool operator>(const Date &d1) const {
        return std::tie(year, month, day, hour, minute) > std::tie(d1.year, d1.month, d1.day, d1.hour, d1.minute);
    }

    /**
     * @brief overload of + operator for Date
     * @return sum of dates
     */
    Date &operator+(const Date &d1) {
        Date *d = new Date;
        d->year = this->year + d1.year;
        d->month = this->month + d1.month;
        d->day = this->day + d1.day;
        d->hour = this->hour + d1.hour;
        d->minute = this->minute + d1.minute;
        d->normalize();
        return *d;
    }

    /**
     * @brief overload of - operator for Date
     * @return time difference between 2 Date objects
     */
    Date &operator-(const Date &d1) {
        int m = this->convertToMinutes() - d1.convertToMinutes();
        Date *d = new Date;
        d->minute = abs(m);
        d->normalize();
        return *d;

    }

    /**
     * @brief overload of = operator for Date
     */
    Date &operator=(const Date &d1) {
        this->year = d1.year;
        this->month = d1.month;
        this->day = d1.day;
        this->hour = d1.hour;
        this->minute = d1.minute;
        this->normalize();
        return *this;
    }

    /**
     * @return string of date in DD/MM/YYYY format
     */
    string print() const {
        stringstream s;
        s << std::right << setfill('0') << setw(2) << to_string(this->day) << "/" << setfill('0') << setw(2)
          << to_string(this->month) << "/" << setfill('0') << setw(4) << to_string(this->year)
          << resetiosflags(std::ios::showbase) << setfill(' ');
        return s.str();
    }

    /**
     * @return string of date in DD/MM/YYYY-hh:mm format
     */
    string printFullDate() const {
        stringstream s;
        s << std::right << setfill('0') << setw(2) << to_string(this->day) << "/" << setfill('0') << setw(2)
          << to_string(this->month) << "/" << setfill('0') << setw(4) << to_string(this->year) << "-" << setfill('0')
          << setw(2) << to_string(this->hour) << ":" << setfill('0') << setw(2) << to_string(this->minute)
          << resetiosflags(std::ios::showbase) << setfill(' ');
        return s.str();

    }

    /**
     * @return string of date in hh:mm format
     */
    string printTime() const {
        stringstream s;
        cout << std::right << setfill('0')
             << setw(2) << to_string(this->hour) << ":" << setfill('0') << setw(2) << to_string(this->minute)
             << resetiosflags(std::ios::showbase) << setfill(' ');
        return s.str();
    }

    /**
     * @brief constrains Date data members to default values
     */
    void normalize();

    /**
     * @brief converts Date object to minutes
     * @return number of minutes in Date
     */
    int convertToMinutes() const;
};


/**
 * @brief checks if input is valid
 * @param variable int &variable
 * @return true if input is valid and false otherwise
 */
bool validArg(int &variable);

/**
 * @brief deletes space characters in the begining and end of the string
 * @param s string &s
 */
void trimString(string &s);

/**
 * @brief waits for user input
 */
void pause();

/**
 * @brief normalizes string
 * @param s string &s
 */
void normalize(string &s);

/**
 * @brief separates string based on the separator
 * @param elem int &elem
 * @param piece string &piece
 * @param separator string separator
 */
void next(int &elem, string &piece, string separator);

/**
 * @brief separates string based on the separator
 * @param piece
 * @param line
 * @param separator
 */
void next(string &piece, string &line, string separator);

/**
 * @brief checks if input is valid
 * @param s string &s
 * @return true if input is valid and false otherwise
 */
bool validString(string &s);

/**
 * @brief Checks if a full Date is valid or not
 * @param date Date &date
 * @return bool - true if valid and false otherwise
 */
bool validFullDate(Date &date);

/**
 * @brief Checks if a Time is valid or not
 * @param date Date &date
 * @return bool - true if valid and false otherwise
 */
bool validTime(Date &date);

/**
 * @brief Checks if a Date is valid or not
 * @param date Date &date
 * @return bool - true if valid and false otherwise
 */
bool validDate(Date &date);

#endif /* SRC_HELPER_H_ */