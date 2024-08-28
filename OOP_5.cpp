#include <iostream>



using namespace std;

class Object {

public:

	Object() {
		cout << "Object()\t" << this << endl;
	}

	virtual ~Object() {
		cout << "~Object()\t" << this << endl;
	}

	void Print() {
		cout << "Print() Object\t" << this << endl;
	}

	virtual void VirtualPrint() {
		cout << "VirtualPrint() Object\t" << this << endl;
	}

	void Method1() {
		cout << "Method1() Object\t" << this << endl;
		Method2();
		VirtualMethod2();
	}

	void Method2() {
		cout << "Method2() Object\t" << this << endl;
	}

	virtual void VirtualMethod2() {
		cout << "VirtualMethod2() Object\t" << this << endl;
	}
};

class Animal : public Object {

public:

	Animal() {
		cout << "Animal()\t" << this << endl;
	}

	~Animal() {
		cout << "~Animal()\t" << this << endl;
	}

	void Print() {
		cout << "Print() Animal\t" << this << endl;
	}

	void VirtualPrint() override {
		cout << "VirtualPrint() Animal\t" << this << endl;
	}

	void Method2() {
		cout << "Method2() Animal\t" << this << endl;
	}

	void VirtualMethod2() override {
		cout << "VirtualMethod2() Animal\t" << this << endl;
	}
};

class Plant : public Object {

public:

	Plant() {
		cout << "Plant()\t\t" << this << endl;
	}

	~Plant() {
		cout << "~Plant()\t" << this << endl;
	}

	void VirtualPrint() override {
		cout << "VirtualPrint() Plant\t" << this << endl;
	}
};



class GeometricObject {

public:

	GeometricObject() {
		cout << "GeometricObject()\t" << this << endl;
	}

	virtual ~GeometricObject() {
		cout << "~GeometricObject()\t" << this << endl;
	}

	virtual string classname() {
		return "GeometricObject";
	}

	virtual bool isA(string classname) {
		return (classname == "GeometricObject");
	}
};

class Triangle : public GeometricObject {

public:

	Triangle() {
		cout << "Triangle()\t\t" << this << endl;
	}

	~Triangle() {
		cout << "~Triangle()\t\t" << this << endl;
	}

	string classname() override {
		return "Triangle";
	}

	bool isA(string classname) override {
		return (classname == "Triangle" || GeometricObject::isA(classname));
	}

	void Area() {
		cout << "S = (a * h) / 2\t" << this << endl;
	}
};

class Parallelepiped : public GeometricObject {

public:

	Parallelepiped() {
		cout << "Parallelepiped()\t" << this << endl;
	}

	~Parallelepiped() {
		cout << "~Parallelepiped()\t" << this << endl;
	}

	string classname() override {
		return "Parallelepiped";
	}

	bool isA(string classname) override {
		return (classname == "Parallelepiped" || GeometricObject::isA(classname));
	}

	void Volume() {
		cout << "V = S * h\t" << this << endl;
	}
};

class Cube : public Parallelepiped {

public:

	Cube() {
		cout << "Cube()\t\t\t" << this << endl;
	}

	~Cube() {
		cout << "~Cube()\t\t\t" << this << endl;
	}

	string classname() override {
		return "Cube";
	}

	bool isA(string classname) override {
		return (classname == "Cube" || Parallelepiped::isA(classname));
	}
};



class Base {

private:
	string str;

public:

	Base() {
		str = "Empty line";
		cout << "Base()\t" << this << endl;
	}

	Base(string s) {
		str = s;
		cout << "Base(string s)\t" << this << endl;
	}

	Base(Base* obj) {
		str = obj->str;
		cout << "Base(Base* obj)\t" << this << endl;
	}

	Base(const Base& obj) {
		str = obj.str;
		cout << "Base(const Base& obj)\t" << this << endl;
	}

	~Base() {
		cout << "~Base()\t" << this << endl;
	}

	void Print() {
		cout << "Print()\t" << str << endl;
	}
};

class Desc : public Base {

public:

	Desc() {
		cout << "Desc()\t" << this << endl;
	}

	Desc(Desc* obj) {
		cout << "Desc(Desc* obj)\t" << this << endl;
	}

	Desc(Desc& obj) {
		cout << "Desc(Desc& obj)\t" << this << endl;
	}

	~Desc() {
		cout << "~Desc()\t" << this << endl;
	}
};

void func1(Base obj) {
	cout << "func1(Base obj)" << endl;
}

void func2(Base* obj) {
	cout << "func2(Base* obj)" << endl;
}

void func3(Base& obj) {
	cout << "func3(Base& obj)" << endl;
}

Base func1() {
	cout << "Base func1()" << endl;
	Base obj("func1");
	return obj;
}

Base* func2() {
	cout << "Base* func2()" << endl;
	Base obj("func2");
	return &obj;
}

Base& func3() {
	cout << "Base& func3()" << endl;
	Base obj("func3");
	return obj;
}

Base func4() {
	cout << "Base func4()" << endl;
	Base* obj = new Base("func4");
	return *obj;
}

Base* func5() {
	cout << "Base* func5()" << endl;
	Base* obj = new Base("func5");
	return obj;
}

Base& func6() {
	cout << "Base& func6()" << endl;
	Base* obj = new Base("func6");
	return *obj;
}


void func_unique_ptr(unique_ptr<Base> base) {
	cout << "void func_unique_ptr(unique_ptr<Base> base)" << endl;
	base->Print();
}

unique_ptr<Base> func_unique_ptr() {
	cout << "unique_ptr<Base> func_unique_ptr()" << endl;
	unique_ptr<Base> b = make_unique<Base>();
	return b;
}

void func_shared_ptr(shared_ptr<Base> base) {
	cout << "void func_shared_ptr(shared_ptr<Base> base)" << endl;
	base->Print();
}

shared_ptr<Base> func_shared_ptr() {
	cout << "shared_ptr<Base> func_shared_ptr()" << endl;
	shared_ptr<Base> b = make_shared<Base>();
	return b;
}


int main() {

	setlocale(LC_ALL, "russian");

	/* ---> Определения <--- */
	
	Object* obj1 = new Object;
	Object* obj2 = new Animal;
	Animal* an = new Animal;

	cout << endl;

	obj1->Print();
	obj2->Print();
	an->Print();

	cout << endl;

	obj1->VirtualPrint();
	obj2->VirtualPrint();
	an->VirtualPrint();

	cout << endl;

	an->Method1();

	cout << endl;

	Object *array_object[2]{new Plant, new Animal};

	for (int i = 0; i < 2; i++) {
		array_object[i]->VirtualPrint();
	}

	for (int i = 0; i < 2; i++) {
		delete array_object[i];
	}

	cout << endl;

	delete obj1;
	delete obj2;
	delete an;
	


	/* ---> Реализация <--- */
	/*
	GeometricObject* array_GM[12];

	for (int i = 0; i < 12; i += 3) {
		array_GM[i] = new Triangle;
		array_GM[i + 1] = new Parallelepiped;
		array_GM[i + 2] = new Cube;
	}

	cout << "\nНебезопасное приведение типов\n\n";

	for (int i = 0; i < 12; i++) {
		((Parallelepiped*)array_GM[i])->Volume();
	}

	cout << "\n<<Правильное>> приведение типов\n\n";

	for (int i = 0; i < 12; i++) {
		if (array_GM[i]->classname() == "Parallelepiped" || array_GM[i]->classname() == "Cube")
			((Parallelepiped*)array_GM[i])->Volume();
	}

	cout << "\nПравильное приведение типов\n\n";

	for (int i = 0; i < 12; i++) {
		if (array_GM[i]->isA("Parallelepiped"))
			((Parallelepiped*)array_GM[i])->Volume();
	}

	cout << "\nDynamic_cast\n\n";

	for (int i = 0; i < 12; i++) {
		if (dynamic_cast<Parallelepiped*>(array_GM[i]))
			dynamic_cast<Parallelepiped*>(array_GM[i])->Volume();
	}

	cout << endl;

	for (int i = 0; i < 12; i++) {
		delete array_GM[i];
	}
	*/


	/* ---> Передача объектов как... <--- */
	/*
	Base B;
	Desc D;

	cout << endl;

	Base* b = new Base;
	Base* bd = new Desc;
	Desc* d = new Desc;

	cout << endl;

	func1(B);
	func1(D);
	func1(*b);
	func1(*bd);
	func1(*d);

	cout << endl;

	func2(&B);
	func2(&D);
	func2(b);
	func2(bd);
	func2(d);

	cout << endl;

	func3(B);
	func3(D);
	func3(*b);
	func3(*bd);
	func3(*d);

	cout << endl;

	delete b;
	delete bd;
	delete d;

	cout << "\n\n\n";

	{
		Base base11 = func1();
		base11.Print();		
	}
	cout << endl;
	{
		Base base12;
		base12 = func1();
		base12.Print();
	}
	cout << endl;
	{
		Base* base2 = func2();
		base2->Print();
	}
	cout << endl;
	{
		Base& base3 = func3();
		base3.Print();
	}
	cout << endl;
	{
		Base base41 = func4();
		base41.Print();
	}
	cout << endl;
	{
		Base base42;
		base42 = func4();
		base42.Print();
	}
	cout << endl;
	{
		Base* base5 = func5();
		base5->Print();
	}
	cout << endl;
	{
		Base& base6 = func6();
		base6.Print();
	}
	cout << endl;
	*/


	/* ---> Умные указатели... <--- */
	/*
	{
		unique_ptr<Base> b1 = make_unique<Base>();
		cout << endl;

		func_unique_ptr(move(b1));
		cout << endl;

		b1 = func_unique_ptr();
		cout << endl;

		//unique_ptr<Base> b22 = b1;
	}

	cout << "\n\n\n";

	{
		shared_ptr<Base> b2(new Base);
		cout << endl;

		func_shared_ptr(b2);
		cout << endl;

		b2 = func_shared_ptr();
		cout << endl;

		shared_ptr<Base> b22 = b2;
	}
	*/
}