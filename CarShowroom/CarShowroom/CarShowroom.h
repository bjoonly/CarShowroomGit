#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Car {
	string model;
	int year;
	double price;
	double volume;
	Car(string model, int year, double price, double volume);
	void SetYear(int year);
	void SetModel(string model);
	void SetPrice(double price);
	void SetVolume(double volume);
	friend ostream& operator<<(ostream& out, const Car& car);
};


