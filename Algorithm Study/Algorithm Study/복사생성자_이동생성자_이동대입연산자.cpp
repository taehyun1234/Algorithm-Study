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

		// ����Ʈ ���� �����ڸ� ����ϴ� ���, �̿� ���� ���� ���簡 �ȵǱ� ������, 
		// �̹� �Ҹ�� �����͸� �ι� ���������� ������ �߰� �ȴ�.
		// �׷��Ƿ�, �ظ��� ��쿡�� ��������ڸ� �����ϴ� ���� ����.
	}

	Test(Test&& rhs) noexcept
	{
		cout << "Move Constructor" << endl;

		_age = rhs._age;
		_name = new char[strlen(rhs._name) + 1];
		memcpy(_name, rhs._name, strlen(rhs._name) + 1);

		rhs._age = 0;
		rhs._name = nullptr;
		// �̵� �����ڴ� A��ü�� �Ű������� �޾� A��ü�� �����͸�
		// B��ü�� �ʱ�ȭ ��Ų ��, A��ü�� 0���� �����.
		// �׷��Ƿ�, �̵� �����ڴ� ��ü�� ���������, ���� �ʴ´ٴ�
		// �����Ͽ����� ����Ͽ��� �Ѵ�.
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
		// �̵� ���� �������̴�.
		// �̵� ���� ������ ���� �̹� �̵��Ǿ� ����ִ� ��ü��
		// �ٸ� ��ü�� �̵����� �ٽ� ������ ä�� �� �ֵ��� �Ѵ�.
	}

	~Test()
	{
		delete[] _name;
		cout << "Destructor" << endl;
	}

	void Show()
	{
		cout << "�̸� : " << _name<<endl;
		cout << "���� : " << _age<<endl;
	}

};

int main()
{
	Test t1("������",10);

	t1.Show();

	Test t2 = t1;
	Test t3(move(t1));
	// �⺻������ ���� �����ڴ� Default ��������ڰ� ������.
	// �׷���, Default ��������ڸ� ����� ���, �����Ͱ� ���� ������ �����ϰ� �ȴ�.
	// �׷��Ƿ�, ���� �ϳ��� delete�� �ϸ�, ������ �ϳ��� �����Ͱ� ���� �ǹ�����. (��۸� ������)

	t2.Show();
	t3.Show();
	
	// ����, ���⼭ ���� t1�� show�Լ��� ���� �ʹ�?
	// �׷���, �ٽ� t3�� t1�� �Űܾ� �Ѵ�. �̸� ���� �̵� ���� �����ڰ� ���ȴ�.
	t1 = move(t3);
	t1.Show();

	return 0;
}