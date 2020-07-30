#include "CarShowroom.h"
Car::Car(string model, int year, double price, double volume) :model(model) {
	SetYear(year);
	SetPrice(price);
	SetVolume(volume);
}

void Car::SetYear(int year) {
	if (year < 1885)
		year = 1885;
	this->year = year;
}

void Car::SetModel(string model) {
	this->model = model;
}

void Car::SetPrice(double price) {
	if (price < 1)
		price = 1;
	this->price = price;
}

void Car::SetVolume(double volume) {
	if (volume < 1)
		volume = 1;
	this->volume = volume;
}
ostream& operator<<(ostream& out, const Car& car) {
	cout << "Model: " << car.model << "\nYear: " << car.year << "\nVolume: " << car.volume << "\nPrice: " << car.price << endl;
	return out;
}

void CarShowroom::AddCar(const Car& car){
	cars.push_back(car);
}
