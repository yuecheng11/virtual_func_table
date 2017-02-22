#include <iostream>
using namespace std;

typedef void(*Fun)(void);
class Base
{
	public:
		Base()
		{
			_bval = 1;
		}
		virtual void f(){cout<<"Base::f()"<<endl;}
		virtual void g(){cout<<"Base::g()"<<endl;}
		virtual void h(){cout<<"Base::h()"<<endl;}
	private:
		int _bval;
};
class Derive:public Base
{
	public:
		Derive()
		{
			_dval = 1;
		}
		virtual void f(){cout<<"Derive::f1()"<<endl;}
		virtual void g1(){cout<<"Derive::g1()"<<endl;}
		virtual void h1(){cout<<"Derive::h1()"<<endl;}
	private:
		int _dval;
};

int main()
{
	Base b;
	cout<<"base size : "<<sizeof(b)<<endl;
	Derive d;
	cout<<"Derive size : "<<sizeof(d)<<endl;

	Fun pFun = NULL;
	cout<<"Base: virtual table address: "<<(int*)(&b)<<endl;
	cout<<"Base: 1rd Vtable add: "<<(int*)*(int*)(&b)<<endl;
	
	cout<<"Derive:virtual table address: "<<(int*)(&d)<<endl;
	cout<<"Derive: 1rd Vtable add: "<<(int*)*(int*)(&d)<<endl;

	pFun = (Fun)*(int*)*(int*)(&d);
	pFun();

	pFun = (Fun)*((int*)*(int*)(&d) + 1);
	pFun();


	Base *pb = new Derive();
	pb->f();


	pb->g();
	return 0;
}
