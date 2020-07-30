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
class Year {
	int year;
public:
	Year(int year = 0) :year(year) {}
	bool operator()(const Car& car) {
		return year == car.year;
	}
	bool operator()(const Car& c1, const Car& c2) {
		return c1.year < c2.year;
	}
};
class Price {
	double price;
public:
	Price(double price = 0) :price(price) {}
	bool operator()(const Car& car) {
		return price == car.price;
	}
	bool operator()(const Car& c1, const  Car& c2) {
		return c1.price < c2.price;
	}
};
class CarShowroom {
	vector<Car>cars;
public:
	void AddCar(const Car& car);
	void Show()const;
	void SearchByModel(string model);
	void SearchByYear(int year);
	void SearchByPrice(double price);

	void SortByModel();
	void SortByYear();
	void SortByPrice();
};
