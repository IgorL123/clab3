
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <ctime>
#include <string>
#include <utility>

using namespace std;

class person {

private:

    size_t id;
    string firstName;
    string middleName;
    string lastName;
    time_t birthDate;

public:

    person(){
        id = 0;
        firstName = "";
        middleName = "";
        lastName = "";
    }


    person (size_t ind, string fname, string mname, string lname, time_t bDate) {
        id = ind;
        firstName = std::move(fname);
        middleName = std::move(mname);
        lastName = std::move(lname);
        birthDate = bDate;
    }

    string getFirstName(){
        return firstName;
    }
    string getMiddleName(){
        return middleName;
    }
    string getLastName(){
        return lastName;
    }
    string getFullName() const {
     return firstName + " " + middleName + " " + lastName;
    }
    [[nodiscard]] time_t getBirthDate() const{
        return birthDate;
    }
    size_t getId() const{
        return id;
    }

    bool operator<( const person &a) const{
        return id < a.getId();
    }

    bool operator>( const person &a) const{
        return id > a.getId();
    }

    bool operator==( const person &a) const{
        return id == a.getId() && getFullName() == a.getFullName();
    }

    friend ostream& operator<<(ostream &out, const person& p){
        out << "Id: ";
        out << p.id;
        out << " First name: ";
        out << p.firstName;
        out << " Middle name: ";
        out << p.middleName;
        out << " Last name: ";
        out << p.lastName;
        out << " Birth date: ";
        out << p.birthDate;
        out << " \n";
        return out;
    }
    friend istream& operator>>(istream &in, person& p){
        in >> p.id;
        in >> p.firstName;
        in >> p.middleName;
        in >> p.lastName;
        in >> p.birthDate;
        return in;
    }
};





#endif //PERSON_HPP
