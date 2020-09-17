#include<iostream>
#include<memory>
#include<string>

using namespace std;

class smartclass{
	string name;

	public:
		smartclass(string str)
		{
			name = str;
		}
		int display()
		{
			cout<<name<<endl;
		}
};

int main()
{
	unique_ptr<smartclass> p1(new smartclass("pavan"));
	unique_ptr<smartclass> p2 = move(p1);
	
	//p1->display();
	p2->display();
	return 0;
}

