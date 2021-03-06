#ifndef AEDA_FEUP_PROJECT_PASSENGER_H
#define AEDA_FEUP_PROJECT_PASSENGER_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Card.h"
#include "helper.h"

using namespace std;

class Passenger {

private:
    unsigned int id;
    string name;
    Date dateOfBirth;
public:
    /**
     * @brief Default Constructor of a Passenger object
     */
    Passenger();

    /**
     * @brief Constructor of a PassengerWithCard object using ID, name, Date of birth
     * @param id
     * @param name
     * @param dateOfBirth
     */
    Passenger(unsigned int id, string name, Date dateOfBirth);

    //get Methods
    /**
     * @brief Gets the ID number of a Passenger
     * @return unsigned int ID of a Passenger
     */
    unsigned int getId() const;

    /**
     * @brief Gets the name of a Passenger
     * @return string name of a Passenger
     */
    string getName() const;

    /**
     * @brief Gets the Date of birth of a Passenger
     * @return string containing the Date of birth of a Passenger
     */
    Date getDateOfBirth() const;

    //set Methods
    /**
     * @brief Sets the ID of the Passenger object to the passed parameter
     * @param id unsigned int id
     */
    void setId(unsigned int id);

    /**
     * @brief Sets the name of the Passenger object to the passed parameter
     * @param name string name
     */
    void setName(string name);

    /**
     * @brief Sets the Date of Birth of the Passenger object to the passed parameter
     * @param dateOfBirth string dateOfBirth
     */
    void setDateOfBirth(Date dateOfBirth);

    /**
     * @brief Prints the id  and the name of the Passenger
     */
    void printSummary() const;

    /**
     * @brief Prints the id, name and the date of birth of a Passenger object
     */
    virtual void print() const;

    /**
     * @brief checks if the object is a Passenger or a PassengerWithCard
     * @return string "n" if it is a Passenger, "c" if it is a PassengerWithCard
     */
    virtual string getType() const;

    /**
    * @brief Gets the card of the passenger
    * @return Card * pointer to a Card object related to the Passenger
    */
    virtual Card *getCard() const;

    /**
    * @brief Sets the card of the passenger
    * @param card Card * card
    */
    virtual void setCard(Card *card);

    /**
     * @brief overload of the operator == to match Passenger objects
     * @param p const Passenger &p
     * @return true upon sucess matching the 2 Passenger objects ids and false otherwise
     */
    bool operator==(const Passenger &p);

    /**
     * @brief overload of the operator << for objects of class Passenger
     * @param o ostream &o
     * @param p const Passenger *p
     * @return ostream
     */
    friend ostream &operator<<(ostream &o, const Passenger *p);

    //void addBooking(Booking * booking);
};

class PassengerWithCard : public Passenger {

private:
    /**
     * @brief Card pointer to a Card object of a Passenger
     */
    Card *card;
public:
    /**
     * @brief Default constructor of a PassengerWithCard object
     */
    PassengerWithCard();

    /**
     * @brief Constructor of a PassengerWithCard object using ID, name, Date of birth and a Card object
     * @param id
     * @param name
     * @param dateOfBirth
     * @param card
     */
    PassengerWithCard(unsigned int id, string name, Date dateOfBirth, Card *card);

    /**
     * @brief Constructor of a PassengerWithCard object using ID, name, Date of birth, job and the number of Flights per year
     * @param id
     * @param name
     * @param dateOfBirth
     * @param job
     * @param nYear
     */
    PassengerWithCard(unsigned int id, string name, Date dateOfBirth, string job, int nYear);
    //get Methods
    /**
     * @brief Gets the card of a PassengerWithCard object
     * @return pointer to a Card object
     */
    Card *getCard() const;

    //Set Methods
    /**
     * @brief Sets the card of a PassengerWithCard object to the passed parameter
     * @param *card Card *card
     */
    void setCard(Card *card);

    /**
     * @brief Prints the ID, name, Date of birth, job and the average number of flights per year of a PassengerWithCard
     */
    void print() const;

    /**
     * @brief Checks if the PassengerWithCard holds a card object
     * @return string "c" if the Passenger really has a card
     */
    string getType() const;

};

/**
 * @brief compares two objects of class Passenger based on their id
 * @param p1 Passenger * p1
 * @param p2 Passenger * p2
 * @return returns true if p1's id is less than p2's id, false otherwise
 */
bool compPID(Passenger *p1, Passenger *p2);

/**
 * @brief compares two objects of class Passenger based on their name
 * @param p1 Passenger * p1
 * @param p2 Passenger * p2
 * @return returns true if p1's name is less than p2's name, false otherwise
 */
bool compPNAME(Passenger *p1, Passenger *p2);

/**
 * @brief compares two objects of class Passenger based on their age
 * @param p1 Passenger * p1
 * @param p2 Passenger * p2
 * @return returns true if p1 is younger than p2, false otherwise
 */
bool compPAGE(Passenger *p1, Passenger *p2);

#endif //AEDA_FEUP_PROJECT_PASSENGER_H