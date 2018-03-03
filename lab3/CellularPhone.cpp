
#include "CellularPhone.h"


CellularPhone::CellularPhone(const string &vendor, int num) : vendor(vendor), num(num) {}

CellularPhone::~CellularPhone() {

}

void CellularPhone::turn_on() {
    cout << "The phone is on." << endl;
    status = true;
}

void CellularPhone::turn_off() {
    cout << "The phone is off." << endl;
    status = false;
}

void CellularPhone::call(int num) {
    if (is_available()) {
        cout << "Make phone call from " << this->num << " to " << num << "." << endl;
        battery -= 0.01f;
    } else {
        cout << "Cannot make phone calls when the phone is unavailable." << endl;
    }
}

bool CellularPhone::is_available() const {
    return status && battery > 0.0f;
}

void CellularPhone::print() const {
    cout << "This is a phone from " << vendor << "! The phone number is " << num << ". The battery life is "
         << 100 * battery << "%." << endl;
}

string CellularPhone::get_vendor() const {
    return vendor;
}

int CellularPhone::get_num() const {
    return num;
}

float CellularPhone::get_battery() const {
    return battery;
}

void CellularPhone::set_battery(float battery) {
    this->battery = battery;
}





