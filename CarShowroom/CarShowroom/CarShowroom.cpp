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
	if (volume < 0.1)
		volume = 0.1;
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
		cout << "Not found car with entered model.\n";
}
void CarShowroom::SearchByPrice(double price) {
	auto res = find_if(cars.begin(), cars.end(), Price(price));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered price.\n";
}
void CarShowroom::SearchByYear(int year) {
	auto res = find_if(cars.begin(), cars.end(), Year(year));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered year.\n";
}
void CarShowroom::SearchByVolume(double volume) {
	auto res = find_if(cars.begin(), cars.end(), Volume(volume));
	if (res != cars.end())
		cout << *res;
	else
		cout << "Not found car with entered volume.\n";
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

void CarShowroom::Remove(){
	auto newEnd=remove_if(cars.begin(), cars.end(), [](const Car&car) {return car.year < 2000; });
	cars.erase(newEnd, cars.end());
}

void CarShowroom::IsCorrectYear() const{
	if (all_of(cars.begin(), cars.end(), [](const Car& car) {return car.year >= 1885 && car.year <= 2020; }))
		cout << "All cars have correct year of manufature.\n";
	else
		cout << "Not all cars have correct year of manufature.\n";
}

void CarShowroom::PriceMore100000() const{
	if (any_of(cars.begin(), cars.end(), [](const Car& car) {return car.price > 100000; })) {
		cout << "Car with price more than 100 000 is present.\n";
	}
	else
		cout << "No cars with a price more than 100 000.\n";
}

void CarShowroom::VolumeLess1() const{
	if (none_of(cars.begin(), cars.end(), [](const Car& car) {return car.volume < 1.0; }))
		cout << "There are no cars with volume less than 1.0.\n";
	else
		cout << "Car with volume less 1.0 is present.\n";
}

void CarShowroom::PriceCarsLess5() const{
	double sum = 0.0;
	for_each(cars.begin(), cars.end(), [&sum](const Car& car) {if (car.year > 2015) sum += car.price; });
	cout << "Price of cars produced less than 5 years ago: " << sum << ".\n";
}

void CarShowroom::PriceReduction(){
	for_each(cars.begin(), cars.end(), [](Car& car) {if (car.year < 2006)car.price-=car.price*0.2; });
}

void CarShowroom::CountEuro5() const{
	int count = 0;
	for_each(cars.begin(), cars.end(), [&count](const Car& car) {if (car.year > 2010) ++count; });
	cout << "Count of EURO-5 standard cars: " << count << ".\n";
}
