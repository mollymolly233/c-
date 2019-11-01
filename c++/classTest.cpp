#include<iostream>


using namespace std;

class Base{
public:
	string publicVar = "Base::publicVar";
	void publicFunc(){cout << "Base::publicFunc" << endl;}
protected:
	string protectedVar = "Base::protectedVar";
	void protectedFunc(){cout << "Base::protectedFunc" << endl;}
private:
	string privateVar = "Base::privateVar";
	void privateFunc(){cout << "Base::privateFunc" << endl;}
};


//public方式的派生类，对父类成员的权限完全和父类一致
class A:public Base{
public:
	void show(){
		cout << "in a:" << endl;
		cout << "pub:" << publicVar << endl;
		cout << "pro:" << protectedVar << endl;
		// cout << "pri:" << privateVar << endl;//基类private的，不可访问，任何方式都不可以
		publicFunc();
		protectedFunc();
		// privateFunc();//基类private的，不可访问，任何继承方式都不可以
		cout << "----------------------------" << endl;
	}

	void update(){
		publicVar = "new publicVar";
		protectedVar = "new protectedVar";
		show();
	}
};



//protected方式的派生类，在类内对父类成员的权限完全和父类一致，外部和子类中则对所有protected及以上的成员都变为protected权限
class B:protected Base{
public:
	void show(){
		cout << "in b:" << endl;
		cout << "pub:" << publicVar << endl;
		cout << "pro:" << protectedVar << endl;
		publicFunc();
		protectedFunc();
		cout << "----------------------------" << endl;
	}
	void update(){
		publicVar = "new publicVar";
		protectedVar = "new protectedVar";
		show();
	}
};


class C:private Base{
public:
	void show(){
		cout << "in c:" << endl;
		cout << "pub:" << publicVar << endl;
		cout << "pro:" << protectedVar << endl;
		publicFunc();
		protectedFunc();
		cout << "----------------------------" << endl;
	}
	void update(){
		publicVar = "new publicVar";
		protectedVar = "new protectedVar";//结论：所有继承方式 的 protected，都可以被子类调用
		show();
	}
};

//protected方式的派生类的public派生类
class D:public B{
public:
	void update2(){
		protectedVar = "new nre protectedVar";
		show();
		//结论：protected方式继承的，除了继承的那个派生类以内及派生类的派生类，其它地方都不能访问
	}
};

//private方式的派生类的public派生类
class E:public C{
public:
	void update2(){
		// protectedVar = "new new nre protectedVar";//编译不通过
		//结论：private方式继承的，除了继承的那个派生类以内，其它地方都不能访问，包括派生类的派生类
		show();
	}
};

int main(){
	A a;
	B b;
	C c;
	a.show();
	b.show();
	c.show();
	cout << endl << "a.publicVar : " << a.publicVar << endl;
	// cout << endl << "b.publicVar : " << b.publicVar << endl;//不可行，protected方式继承的，只有那个派生类内部 和 它的派生类才可以访问，其它外部不可访问
	// cout << endl << "c.publicVar : " << c.publicVar << endl;//不可行，private方式继承的，只有那个派生类内部可以访问，这个派生类外部任何地方都不可以访问
	cout << "----------------------------" << endl;



	a.update();
	b.update();
	c.update();
	cout << "----------------------------" << endl;



	D d;
	d.update2();//可以更改
	//结论：protected方式继承的，除了继承的那个派生类以内及派生类的派生类，其它地方都不能访问

	return 0;
}