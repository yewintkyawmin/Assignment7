#include<iostream>
#include<fstream>
using namespace std;

char ans;

void ExistedNumber();
void BuyNumber();
void ViewRecord();

class persons{
	private:
		char name[20];
		int phone;
		
	public:	
		int quantity;
		int number[10];
			
		void RequestData();
		void ShowRecord();
		void get_exist_num();

};

void persons::RequestData()
{	
	int i;
	int temp =0;
		
	cout<<"\n\nEnter Name:";cin>>name;
	cout<<"Enter Phone:";cin>>phone;
	cout<<"How many Numbers U want to buy:";
	cin>>quantity;
	
	for(i=0;i<quantity;i++)
	{
		cout<<"Enter Number U want to buy:";
		cin>>number[i];
		
		persons pp;
		ifstream infile;
		infile.open("Record File.txt");
		infile.read((char*)&pp,sizeof(pp));
		while(!infile.eof())
		{
			for(int j=0;j<pp.quantity;j++)
			{
				if(number[i] == pp.number[j])
				{
					cout<<"Number "<<number[i]<<" had already been already bought.";
					temp = 1;
					break;
				}
			}
			if(temp == 1)
			{
				break;
			}
			infile.read((char*)&pp,sizeof(pp));
		}// end while
		if(temp == 1)
		{
			persons::RequestData() ;
		}
	}//end for
}

void persons::ShowRecord()
{
	int i ;
	cout<<"\n\nName:"<<name;
	cout<<"\nPhone:"<<phone;
	cout<<"\nQuantity:"<<quantity;
	for(i=0;i<quantity;i++)
	{
		cout<<"\nNumber :"<<number[i];
	}

}

void persons::get_exist_num()
{	
	for(int i=0;i<quantity;i++)
	{
		cout<<" "<<number[i];
	}
}

int main()
{
	int choice;
	cout<<"\t\t\t\t\t\tWelcome To Cycle Ticket Lucky Dip Program\n";
	cout<<"You can buy Numbers from 100 to 999";
	
	while(true)
	{	
		cout<<"\n\n(1)To Buy A Number";
		cout<<"\n(2)To View Record";
		cout<<"\n(3)To View Existed Number";
		cout<<"\n(4)To Exit";
		cout<<"\nEnter Here : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1 : BuyNumber();break;
			case 2 : ViewRecord();break;
			case 3 : ExistedNumber();break;
			case 4 : exit(0);
		}	}
	
	return 0;
}

void ExistedNumber()
{	
	persons p;
	ifstream infile;
	
	infile.open("Record File.txt");
	infile.read((char*)&p,sizeof(p));
	cout<<"\nYou can't buy following existed Numbers:\n";
	while(!infile.eof())
	{
		p.get_exist_num();
		infile.read((char*)&p,sizeof(p));
	}
}

void BuyNumber()
{
	persons p;
	ofstream outfile;
	
	do{
		outfile.open("Record File.txt",ios::app);
		p.RequestData();
		cout<<"\nYou have bought Numbers successfully";
		outfile.write((char*)&p,sizeof(p));
		outfile.close();
		
		cout<<"\nTry Again(y/n)? :";cin>>ans;			
	}while(ans=='y');
}

void ViewRecord()
{
	persons p;
	ifstream infile;
	
	infile.open("Record File.txt");
	infile.read((char*)&p,sizeof(p));
	while(!infile.eof())
	{
		p.ShowRecord();
		infile.read((char*)&p,sizeof(p));
	}
	infile.close();
}
