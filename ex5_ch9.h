
#pragma once
#include <iostream>




using namespace std;
class Book {

private:
	string isbn;
	string title;
	string author;
	int copyrightdate;
	bool checkedout;
	bool checkisbn();
	
public:
	Book(string xisbn, string xtitle, string xauthor, int xcopyrightdate);

	const string &getisbn()const;
	const string &gettitle()const;
	const string &getauthor()const;
	int getcopyrightdate()const;
	bool getcheckedout()const;
	void checkout();
	void checkin();
	
};

