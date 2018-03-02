#include <iostream>
using namespace std;

class Animal {
public:
	virtual void eat() = 0;
	void sleep();
	int mData;
};

void Animal::sleep()
{
	cout << "zzZ..." << endl;
}

class Dog : public  Animal {
public:
	int dog;
	virtual void bark() { cout << "woof!" << endl; }
	virtual void eat() { cout << "The dog has eaten" << endl;}
};

class Bird : public  Animal {
public:
	int bird;
	Bird() : bird(0){}
	virtual void chirp() { cout << "chirp!" << endl; }
	virtual void eat() { cout << "The bird has eaten" << endl;}
};

class DogBird : public  Dog, public Bird {
public:
	int dogbird;
	virtual void eat() { cout << "The dogbird has eaten" << endl;}
};


int main()
{
	DogBird d;
	Animal  *a = &d; // offset直接获得

	//a->sleep();
	int s = a->mData;
	//cout << d.bird << sizeof(d);
	//int t = d.mData;
	//d.eat();
}
