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
	shared_ptr<smartclass> p1(new smartclass("pavan"));
	shared_ptr<smartclass> p2 = p1;
	shared_ptr<smartclass> p3(new smartclass("kumar"));
	
	p1->display();
	p2->display();
	p3->display();
	
	cout<<p1.use_count()<<endl;	
	cout<<"is p1 unique?"<<p1.unique()<<endl;	
	cout<<"is p3 unique?"<<p3.unique()<<endl;
	p1.swap(p3);
		
	p1->display();
	cout<<p1.use_count()<<endl;	
	cout<<"is p1 unique?"<<p1.unique()<<endl;	
	return 0;
}

