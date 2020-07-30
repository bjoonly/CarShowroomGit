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
class Volume {
	double volume;
public:
	Volume(double volume = 0) :volume(volume) {}
	bool operator()(const Car& c1, const Car& c2) {
		return c1.volume < c2.volume;
	}
	bool operator()(const Car& car) {
		return volume == car.volume;
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
	void SearchByVolume(double volume);

	void SortByModel();
	void SortByYear();
	void SortByPrice();
	void SortByVolume();
	void Remove();
	void IsCorrectYear()const;
	void PriceMore100000()const;
	void VolumeLess1()const;
	void PriceCarsLess5()const;
	void PriceReduction();
};
