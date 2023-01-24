#include <iostream>
#include <vector>
#include "IPerson.h"
//API - Application Programming Interface
//class A {
//public:
//	A(int maxSpeed):_maxSpeed(maxSpeed){}
//private:
//	int _maxSpeed;
//};
//class B :public:A{
//public:
//	B(int maxSpeed) :A(maxSpeed) {}
//};
//int main() {
//	A a1(5);
//	A a2(1242134);
//	A a3(10);
//	A a4(5);
//	A a5(5);
//}
class IVehicle {
public:
	virtual void printName() {//virtual מעלועטעü
		std::cout << "IVehicle" << std::endl;
	}
	virtual int getSpeed() = 0;//
	virtual ~IVehicle() {
		std::cout << "IVehical destructor was called" << std::endl;
	}

};
class IMovable {
public:
	virtual void move(int x, int y) = 0;
};
class Car :public IVehicle {
public:
	Car(int speed):_speed(speed){}
	void printName()override {//override
		std::cout << "Car" << std::endl;
	}
	int getSpeed() override{
		return _speed;
	}
	~Car() {
		std::cout << "Car destructor was called" << std::endl;
	}
private:
	int _speed;
};
class Van :public Car{
public:
	Van(int speed): Car(speed){}
	~Van() {
		std::cout << "Van destructor was called" << std::endl;

	}
};
class HouseVan :public Van {
public:
	HouseVan(int speed):Van(speed){}
	~HouseVan() {
		std::cout << "HouseVan destructor was called" << std::endl;

	}
};
class Motorcycle :public IVehicle {
public:
	Motorcycle(int speed):_speed(speed){}
	int getSpeed() {
		return _speed;
	}
	~Motorcycle() {
		std::cout << "Motorcycle destructor was called" << std::endl;
	}
private:
	int _speed;
};
void printer(IVehicle* vehicle) {
	vehicle->printName();
	std::cout << vehicle->getSpeed() << std::endl;
}
int main() {
	//IVehicle *a = new IVehicle();
	IVehicle *b = new Car(50);
	IVehicle* c = new Motorcycle(60);
	IVehicle* d = new Van(70);
	IVehicle* e = new HouseVan(20);
	std::vector <IVehicle*> vehicles;//ctd
	//vehicles.push_back(a);
	vehicles.push_back(b);
	vehicles.push_back(c);
	vehicles.push_back(d);
	std::cout << "Traversing vehicles" << std::endl;
	//for (size_t i = 0; i < vehicles.size(); i++)
	//{
	//	vehicles[i]->printName();
	//}
	for (size_t i = 0; i < vehicles.size(); i++)
	{
		printer(vehicles[i]);
	}
	/*Person p("Alex");
	p.fight();*/
	IPerson* p = new Person("Alex");
	p->fight();
	delete b;
	delete c;
	delete d;
	delete e;

}