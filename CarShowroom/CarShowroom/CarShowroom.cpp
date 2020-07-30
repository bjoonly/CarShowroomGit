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

void CarShowroom::Show() const{
	for_each(cars.begin(), cars.end(), [](const Car& car) {cout << car << endl; });
}

void CarShowroom::SearchByModel(string model) {
	auto res = find_if(cars.begin(), cars.end(), Model(model));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered model.";
}
void CarShowroom::SearchByPrice(double price) {
	auto res = find_if(cars.begin(), cars.end(), Price(price));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered price.";
}
void CarShowroom::SearchByYear(int year) {
	auto res = find_if(cars.begin(), cars.end(), Year(year));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered year.";
}
void CarShowroom::SearchByVolume(double volume) {
	auto res = find_if(cars.begin(), cars.end(), Volume(volume));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered volume.";
}
void CarShowroom::SortByModel() {
	sort(cars.begin(), cars.end(), Model());
}
void CarShowroom::SortByYear() {
	sort(cars.begin(), cars.end(), Year());
}
void CarShowroom::SortByPrice() {
	sort(cars.begin(), cars.end(), Price());
}
void CarShowroom::SortByVolume() {
	sort(cars.begin(), cars.end(), Volume());
}