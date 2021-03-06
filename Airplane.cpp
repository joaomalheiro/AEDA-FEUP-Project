#include "Airplane.h"
#include "Application.h"
#include <iomanip>

Airplane::Airplane() {}

Airplane::Airplane(unsigned int id, string model, unsigned int capacity, vector<Flight *> flights, Date maintenance,
                   Date maintenancePeriod) : id(id),
                                             model(model),
                                             capacity(capacity),
                                             flights(flights), maintenance(maintenance),
                                             maintenancePeriod(maintenancePeriod) {}

Airplane::Airplane(unsigned int id, string model, unsigned int capacity, Date maintenance, Date maintenancePeriod) {

    this->id = id;
    this->model = model;
    this->capacity = capacity;
    vector<Flight *> v;
    flights = v;
    this->maintenance = maintenance;
    this->maintenancePeriod = maintenancePeriod;
}

string Airplane::getModel() const {
    return this->model;
}

unsigned int Airplane::getId() const {
    return this->id;
}

unsigned int Airplane::getCapacity() const {
    return this->capacity;
}

vector<Flight *> Airplane::getFlights() const {
    return this->flights;
}

Date Airplane::getMaintenance() const {
    return this->maintenance;
}

Date Airplane::getMaintenancePeriod() const {
    return this->maintenancePeriod;
}

void Airplane::setModel(string model) {
    this->model = model;
}

void Airplane::setId(unsigned int id) {
    this->id = id;
}

void Airplane::setCapacity(unsigned int capacity) {

    this->capacity = capacity;

    for (auto &f : flights) {

        f->setCapacity(capacity);

    }
}

void Airplane::setFlights(vector<Flight *> flights) {
    this->flights = flights;
}

void Airplane::setMaintenance(Date maintenance) {
    this->maintenance = maintenance;
}

void Airplane::setMaintenancePeriod(Date maintenancePeriod) {
    this->maintenancePeriod.day = maintenancePeriod.day;
}

void Airplane::printSummary() const {

    cout << setw(11) << id << setw(3) << " " << setw(7) << model << setw(3) << " " << setw(7) << capacity << endl;
}

void Airplane::print() const {

    cout << "Id: " << id << endl;
    cout << "Model: " << model << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Next maintenance date: " << maintenance.print() << endl;
    cout << "Maintenance period: " << maintenancePeriod.day << " day(s)" << endl;

}

void Airplane::removeFlight(Flight *flight) {

    if (flight->getId() == flights.at(0)->getId()) {

        flights.erase(flights.begin());
        return;
    }

    if (flight->getId() == flights.at(flights.size() - 1)->getId()) {

        flights.erase(flights.begin() + flights.size() - 1);
        return;
    }

    throw ConnectionFlight();

}

bool Airplane::operator==(const Airplane &a1) {

    return id == a1.getId();

}

void Airplane::addFlight(Flight *flight) {

    if (flights.empty()) {
        flights.push_back(flight);
        return;
    }

    Flight *elem1 = flights.at(0);
    Flight *lelem = flights.at(flights.size() - 1);

    if ((flight->getDate() + flight->getDuration()) < elem1->getDate() &&
        flight->getDestination() == elem1->getDeparture()) {


        flights.insert(flights.begin(), flight);
        return;
    }

    if (flight->getDate() > (lelem->getDate() + lelem->getDuration()) &&
        flight->getDeparture() == lelem->getDestination()) {

        flights.push_back(flight);
        return;
    }

    throw OverlappingFlight();
}

ostream &operator<<(ostream &o, const Airplane *a) {
    o << to_string(a->id) << "; " << a->model << "; " << to_string(a->capacity) << "; ";
    o << a->getMaintenance().print() << "; ";
    o << a->getMaintenancePeriod().day << "; ";
    if (!a->flights.empty()) {
        for (size_t i = 0; i < a->flights.size(); i++) {
            o << to_string(a->flights.at(i)->getId());
            if (i != a->flights.size() - 1) o << ", ";
        }
    } else o << "no_flights";
    return o;
}

bool compAId(Airplane *a1, Airplane *a2) {

    return (a1->getId() < a2->getId());
}

bool compMaintenance(pair<int, Date> d1, pair<int, Date> d2) {
    return d1.second < d2.second;
}

