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

class Model {
	string model;
public:
	Model(string model=""):model(model){}
	bool operator()(const Car& c1, const Car& c2) {
		return c1.model < c2.model;
	}
	bool operator()(const Car& car) {
		return car.model == model;
	}
};

class CarShowroom {
	vector<Car>cars;
public:
	void AddCar(const Car& car);
	void Show()const;
	void SearchByModel(string model);

	void SortByModel();
};
