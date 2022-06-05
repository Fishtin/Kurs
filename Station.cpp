#include "Station.hpp"
#include "Program.hpp"

Station::Station()
{
	number = 0;
	first = new Train();
	this->next = nullptr;
	this->prev = nullptr;
}

Station::Station(int number)
{
	this->number = number;
	first = new Train();
	this->next = nullptr;
	this->prev = nullptr;
}

Station::~Station()
{
	delete (first);
}

Station* Station::getPrev() 
{
	return prev;
}

Station* Station::getNext()
{
	return next;
}

void Station::setNext(Station* _next)
{
	this->next=_next;
}
void Station::setPrev(Station* _prev)
{
	this->prev = _prev;
}

int Station::getNumber()
{
	return number;
}

bool Station::isEmpty()
{
	if (first->getNumber() == -1) 
	{
		first->IGOBN();
		return true;
	}
	first->IGOBN();
	return false;
}

bool Station::add(int number, std::string fuel)
{
	if (!find(number))
	{
		first->ADD(number, fuel);
		return true;
	}
	return false;
}

bool Station::del(int mode)
{
	if (!isEmpty())
	{
		first->Dele(mode);
		return true;
	}
	return false;
}

bool Station::find(int number)
{
	return first->getNumberF(number);
}

void Station::show()
{
	int temp;
	Train* current = first;
	while (true) 
	{
		temp = current->getNumber();
		if (temp < 0)
		{
			current->getMark();
			break;
		}
		if (current != first) 
			std::cout << "|" << std::setw(16) << "|";

		std::cout << std::setw(13) << temp
			<< std::setw(8) << " " << std::setw(10) << current->getMark()<<std::endl << "|" << std::setw(16) << "|";
	}
}

void Station::setNumber(int number)
{
	this->number = number;
}

std::string Station::getString()
{
	int temp;
	std::string str = "";
	if (!isEmpty())
	{
		Train* current =first;
		do
		{
			
			std::stringstream ss;
			temp = current->getNumber();
			if (temp < 0)
			{
				break;
			}
			str += " ";
			ss << temp;
			str += ss.str();
			str += " ";
			str += current->getMark();
		}while (true);
	}
	return str;
}