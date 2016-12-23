#include <iostream>
#include "book.h"


Book::Book(string xisbn, string xtitle, string xauthor, int xcopyrightdate)
{
	isbn = xisbn;
	title = xtitle;
	author = xauthor;
	copyrightdate = xcopyrightdate;
	checkedout = false;
	if (!checkisbn()) {
		cout << "invalid isbn" << endl;
	}
	
}//Book

const string &Book::getauthor() const{
	return author;
}



const string &Book::gettitle() const{
	return title;
}


const string &Book::getisbn() const {
	return isbn;
}

bool Book::getcheckedout() const{
	return checkedout;
}
void Book::checkout() {
	checkedout = true;
}
void Book::checkin() {
	checkedout = false;
}

bool Book::checkisbn() {
	
	if (isbn.size() != 4) {
		return false;
	}//if
	for (int i = 0; i < 3; i++) {
		char tmp = isbn[i];
		if (tmp < 48) {
			return false;
		}
		if (tmp > 57) {
			return false;
		}
	}//for
	char tmp = isbn[3];
	bool isdigit = (tmp >= '0') && (tmp <= '9');
	bool isalphalower = (tmp >= 'a') && (tmp <= 'z');
	bool isalphaupper = (tmp >= 'A') && (tmp <= 'Z');
	if (!(isdigit || isalphalower || isalphaupper))
		return false;
	return true;
}
int Book::getcopyrightdate() const{

	return copyrightdate;
}





	
