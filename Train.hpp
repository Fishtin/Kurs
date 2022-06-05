#ifndef COLUMN_HPP
#define COLUMN_HPP

#include "Program.hpp"

class Train
{

private:
	int iG = 0;
	int iGF = 0;
	int iter = 10;
	int* number = {};
	std::string* Mark = {};
public:
	Train();
	void ADD(int number, std::string mark);
	void Dele(int mode);
	~Train();

	bool        getNumberF(int number);
	int			getNumber();
	void        IGOBN();

	std::string getMark();
};

#endif
