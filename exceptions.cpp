//
// Created by Mariana on 10/11/2017.
//

#include <iostream>
#include "exceptions.h"

using namespace std;

InvalidPassenger::InvalidPassenger(unsigned int id) {

    this->id = id;
}

void InvalidPassenger::print() const {

        cout << id << " is an invalid passenger id. Reenter.\n";

}

void InvalidPassenger::printDuplicate() const {

    cout << "This passenger already exists. Please insert another id or delete the passenger.\n";

}

InvalidAirplane::InvalidAirplane(unsigned int id) {

    this->id = id;
}

void InvalidAirplane::print() const {

    cout << id << " is an invalid airplane id. Reenter.\n";

}

void InvalidAirplane::printDuplicate() const {

    cout << "This airplane already exists. Please insert another id or delete the airplane.\n";

}

InvalidFlight::InvalidFlight(unsigned int id) {

    this->id = id;
}

void InvalidFlight::print() const {

    cout << id << " is an invalid flight id. Reenter.\n";

}

void InvalidFlight::printDuplicate() const {

    cout << "This flight already exists. Please insert another id or delete the flight.\n";

}

OverlapingFlight::OverlapingFlight() {}

void OverlapingFlight::print() const {

    cout << "It is not possible to add this flight to this plane.\n";

}

InvalidFormat::InvalidFormat() {

}

ConnectionFlight::ConnectionFlight() {

}

void ConnectionFlight::print() const {

    cout << "It is not possible to delete this flight.\n";
}

void InvalidFilePath::print() {
    if (type == "empty") cout << "File path is empty.\n";
    else if (type == "fail") cout << "Failed to open file.\n";
}

InvalidFilePath::InvalidFilePath(std::string type): type(type) {}
