#include <iostream>

#include "folder.h"

using namespace std;

Folder::Folder(unsigned int size) {
	files = new const File*[size];
	maxSize = size;
	currSize = 0;
}

Folder::~Folder() {
	if (files) {
		delete [] files;
	}
}

Folder::Folder(const Folder &folder) {
	maxSize = folder.maxSize;
	currSize = folder.currSize;
	files = new const File*[maxSize];
	for (int i = 0; i < currSize; ++i) {
		files[i] = new const File(*(folder.files[i]));
	}
}

void Folder::addFile(const File &file) {
	if (contains(file)) {
		cout << "File already exists in folder" << endl;
		return;
	}
	if (currSize == maxSize) {
		cout << "Insufficient space for folder" << endl;
		return;
	}
	files[currSize++] = &file;
}

bool Folder::contains(const File &file) const {
	for (int i = 0; i < currSize; ++i) {
		if (file.equals(*(files[i]))) {
			return true;
		}
	}
	return false;
}

void Folder::print() const {
	for (int i = 0; i < currSize; ++i) {
		files[i]->print();
	}
}
