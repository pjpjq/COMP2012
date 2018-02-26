#include <iostream>
#include <cstring>

#include "file.h"

using namespace std;

File::File() {
	name = '\0';
}

File::~File() {
	if (name) {
		delete name;
	}
}

File::File(const File &file) {
	name = new char[strlen(file.name) + 1];
	strcpy(name, file.name);
}

File::File(const char *fileName) {
	name = new char[strlen(fileName) + 1];
	strcpy(name, fileName);
}

bool File::equals(const File &file) const {
	return strcmp(name, file.name) == 0;
}

void File::print() const {
	if (name) {
		cout << "File " << name << endl;
	} else {
		cout << "File without name" << endl;
	}
}
