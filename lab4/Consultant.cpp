/*
 * Consultant.cpp
 *
 */

#include "Consultant.h"

Consultant::Consultant(int cid, string cname, double base) : Employee(cid, cname),
                                                             cid(cid),
                                                             cname(cname),
                                                             baseSalary(base) {
}

double Consultant::getBaseSalary() const {
    return baseSalary;
}

void Consultant::setBaseSalary(double base) {
    baseSalary = base;
}

double Consultant::netSalary(double salary) const {
    if (salary < 0) {
        cout << "Invalid salary!" << endl;
        return 0;
    } else if (salary <= 40000 && salary >= 0) {
        return salary * .98;
    } else if (salary > 40000 && salary <= 80000) {
        return (salary - 40000) * .93 + 40000 * .98;
    } else if (salary > 80000 && salary <= 120000) {
        return (salary - 80000) * .88 + 40000 * (.93 + .98);
    } else if (salary > 120000) {
        return (salary - 120000) * .83 + 40000 * (.88 + .93 + .98);
    } else {
        return 0;
    }
}

void Consultant::check(Item item) const {
    switch (item) {
        case Item::id:
            cout << "ID: " << getID() << endl;
            break;
        case Item::name:
            cout << "Name: " << getName() << endl;
            break;
        case Item::base_salary:
            cout << "Base Salary: " << getBaseSalary() << endl;
            break;
        case Item::net_salary:
            cout << "Net Salary: " << netSalary(baseSalary) << endl;
            break;
        default:
            cout << "Invalid item." << endl;
    }
}




