
#include <iostream>
#include <conio.h>
#include <Windows.h>

#pragma once
#ifndef APPLICATION_H
#define APPLICATIOIN_H

class Tapplication
{
public:
	Tapplication();
	int exec();
private:
	int menu();
	COORD cord{ 0,0 };
};

#endif // !APPLICATION_H