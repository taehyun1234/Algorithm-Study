#include <iostream>

using namespace std;

class Test
{
	char * _name;
	int _age;

public:
	Test(const char * name, int age) : _age(age) 
	{
		cout << "Constructor" << endl; 

		_name = new char[strlen(name) + 1];
		memcpy(_name, name, strlen(name) + 1);
	}

	Test(const Test& rhs) :_age(rhs._age)
	{
		cout << "Copy Constructor" << endl;

		_name = new char[strlen(rhs._name) + 1];
		memcpy(_name, rhs._name, strlen(rhs._name) + 1);

		// 디폴트 복사 생성자를 사용하는 경우, 이와 같은 깊은 복사가 안되기 때문에, 
		// 이미 소멸된 포인터를 두번 지워버려서 에러가 뜨게 된다.
		// 그러므로, 왠만한 경우에는 복사생성자를 구현하는 것이 좋다.
	}

	Test(Test&& rhs) noexcept
	{
		cout << "Move Constructor" << endl;

		_age = rhs._age;
		_name = new char[strlen(rhs._name) + 1];
		memcpy(_name, rhs._name, strlen(rhs._name) + 1);

		rhs._age = 0;
		rhs._name = nullptr;
		// 이동 생성자는 A객체를 매개변수로 받아 A객체의 데이터를
		// B객체로 초기화 시킨 후, A객체는 0으로 만든다.
		// 그러므로, 이동 생성자는 객체가 살아있지만, 쓰지 않는다는
		// 가정하에서만 사용하여야 한다.
	}

	Test& operator=(Test&& rhs) noexcept
	{
		if (this != &rhs)
		{
			delete[] _name;

			_age = rhs._age;
			_name = new char[strlen(rhs._name) + 1];
			memcpy(_name, rhs._name, strlen(rhs._name) + 1);

			rhs._age = 0;
			rhs._name = nullptr;
		}
		return *this;
		// 이동 대입 연산자이다.
		// 이동 대입 연산을 통해 이미 이동되어 비어있는 객체에
		// 다른 객체를 이동시켜 다시 내용을 채울 수 있도록 한다.
	}

	~Test()
	{
		delete[] _name;
		cout << "Destructor" << endl;
	}

	void Show()
	{
		cout << "이름 : " << _name<<endl;
		cout << "나이 : " << _age<<endl;
	}

};

int main()
{
	Test t1("개똥이",10);

	t1.Show();

	Test t2 = t1;
	Test t3(move(t1));
	// 기본적으로 복사 생성자는 Default 복사생성자가 존재함.
	// 그러나, Default 복사생성자를 사용할 경우, 포인터가 같은 공간을 참조하게 된다.
	// 그러므로, 만약 하나가 delete를 하면, 나머지 하나도 포인터가 없게 되버린다. (댕글링 포인터)

	t2.Show();
	t3.Show();
	
	// 만약, 여기서 내가 t1의 show함수를 쓰고 싶다?
	// 그러면, 다시 t3를 t1로 옮겨야 한다. 이를 위해 이동 대입 연산자가 사용된다.
	t1 = move(t3);
	t1.Show();

	return 0;
}