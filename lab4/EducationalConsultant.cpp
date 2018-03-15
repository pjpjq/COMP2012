
#include "Employee.h"
#include "Consultant.h"
#include "EducationalConsultant.h"

EducationalConsultant::EducationalConsultant(int id, string name, double base, double wage, int hour) : Consultant(id,
                                                                                                                   name,
                                                                                                                   base),
                                                                                                        wagePerHour(
                                                                                                                wage),
                                                                                                        workingHours(
                                                                                                                hour) {

}

double EducationalConsultant::getWage() const {
    return wagePerHour;
}

int EducationalConsultant::getHours() const {
    return workingHours;
}

void EducationalConsultant::setWage(double wage) {
    wagePerHour = wage;
}

void EducationalConsultant::setHours(int hours) {
    workingHours = hours;
}

double EducationalConsultant::performanceSalary() const {
    return workingHours * wagePerHour;
}

double EducationalConsultant::netSalary() const {
    return Consultant::netSalary(getBaseSalary() + performanceSalary());
}

void EducationalConsultant::check(Item item) const {
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
            cout << "Net Salary: " << netSalary() << endl;
            break;
        case Item::performance_salary:
            cout << "Performance Salary: " << performanceSalary() << endl;
            break;
    }
}
