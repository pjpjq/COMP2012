
#include "SmartPhone.h"

SmartPhone::SmartPhone(const string &vendor, int num) : CellularPhone(vendor, num), os(new OS()) {}

SmartPhone::SmartPhone(const string &vendor, int num, const string &os_name, int os_ver) :
        CellularPhone(vendor, num), os(new OS(os_name, os_ver)) {}

SmartPhone::~SmartPhone() {
    delete os;
}

void SmartPhone::browse_web(const string &url) {
    if (is_available()) {
        cout << "Visit a website at " << url << "." << endl;
        set_battery(get_battery() - 0.01f);
    } else {
        cout << "Cannot browse the website when the phone is unavailable." << endl;
    }
}

void SmartPhone::upgrade_os() {
    if (is_available()) {
        os->upgrade();
        set_battery(get_battery() - 0.01f);
    } else {
        cout << "Cannot upgrade os when the phone is unavailable." << endl;
    }
}

const OS *SmartPhone::get_os() const {
    return os;
}
