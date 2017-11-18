#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<bits/stdc++.h>

using namespace std;

int i,j,x,turn,n1;
int fuel_check=0;
char ch;
class UBER
{
	public:
	float km_c,km_app,cash_c,amt_shown,tax_per,net,u_fee_per,tcasht;
	char date[10];
	float tax,km1;
	float permin,perkm,base;
	float u_fee, fuel,kmt,tt;
	float fuel_cost;
	float bonus;
	UBER()
	{
	fuel_cost=0.0;
	permin=1.59;
	km1=0.0;
	tcasht=0.0;
	perkm=5.30;
	base=47.70;
	kmt=0;tt=0;
	u_fee_per=20.0;
	tax_per=4.6;
	bonus=0.0;
	net=0.0;
	fuel=0.0;

	}

	float U_f;
	int n;

	void cal(int n3=0)//....................................
	{
	if(n3==1)
	{cash_c=tcasht;
	km_c=km1;
	}
	if(n>=7&& n<10)
	{
	      if(cash_c>=1000)
	      bonus+=0;
	      else
	      {		bonus=bonus+(1000.0 - cash_c);	}
	}
	else if(n>=10&& n<12)
	{
		if(cash_c>=1500)
		bonus+=0;
		else
		{	bonus=bonus+(1500.0 -cash_c);	}
	}
	else if(n>=12 )
	{
		if(cash_c>=2100)
		bonus+=0;
		else
		{	bonus=bonus+(2100.0 -cash_c);	}

	}


	tax=(cash_c*tax_per) /100.0;
	u_fee=(cash_c * u_fee_per)/100.0;
	net=net+cash_c - (tax + u_fee);

	}
	void sh()
	{
		cout<<"READ THE FOLLOWING INSTRUCTIONS CAREFULLY..\n";
		cout<<"This software is used to cross check the data shown\n";
		cout<<"in the Uber driver app. It is still under development and\n";
		cout<<"further features would be added\n\n";
		cout<<"Tax percent 		     :"<<"4.6"<<"%"<<endl;
		cout<<"Uber Fee percent 	     :"<<"20%"<<endl;
		cout<<"In this software, use (1) for yes and (2) for no\n";
		//cout<<"PRESS ANY KEY TO CONTINUE..";
		getchar();

	}
	void ask_day_wise()
	{
		cout<<"\nEnter the date (DD.MM.YYYY) ";
		scanf("%s",&date);
		cout<<"Enter the following :\n ";
		cout<<"Total number of rides of the day :";
		cin>>n;
		n1=n;
		cout<<" KMs travelled shown in car :";cin>>km_c;
		cout<<" KMs travelled shown in app :";cin>>km_app;
		cout<<" Cash collected  	   :";cin>>cash_c;
		cout<<" Amount shown in app 	   :";cin>>amt_shown;
	}
	void fuel2()
	{
		cout<<"Enter the average fuel economy of the day : ";

		cin>>fuel;
		fuel_cost=
		net= net - fuel_cost ;

	}
	void cal_manual()
	{
		float t1;float s1;
		if(i==1)
		{
		cout<<"Enter the km and time of the following \n";
		}
		cout<<"\t------- RIDE "<<i<<" --------"<<endl;
		mps:
		cout<<"KMs Travelled : ";
		cin>>km1;kmt+=km1;
		cout<<"Total Time : ";cin>>t1;tt+=t1;
		cout<<"Surge percent "<<i<<" : ";cin>>s1;
		cout<<"Do you want to re-enter the values for this ride ? ";
		int che;cin>>che;
		if(che==1)
		{ goto mps;}
		float tcash;
		tcash=((km1*perkm)+(t1*permin))*s1;
		tcasht+=tcash;
		cout<<"Total cash collected for the ride "<<i<<" should be "<<tcash<<endl;
		cout<<endl<<endl;
		if(i!=n)
		{cout<<"\n\n\n\n\n\nPRES ANY KEY FOR NEXT INPUT";getchar();system("cls");
		cout<<"\n\n\n\n\n\n\n\n";}

	}
	void display()
	{

		system("cls");
		cout<<"\n\n\n\n\n";
		cout<<"--------- DATE : ";cout<<date<<" ---------"<<endl;
		cout<<"\nTotal number of rides of the day :"<<n;
		cout<<"\nKMs travelled shown in car 	:"<<km_c;
		cout<<"\nKMs travelled shown in app 	:"<<km_app;
		cout<<"\nCash collected	   		:"<<cash_c;
		cout<<"\nAmount shown in app 	   	:"<<amt_shown;
		cout<<"\nBonus earned		   	:"<<bonus;
		cout<<"\nTax paid			:"<<tax;
		cout<<"\nUber fee			:"<<u_fee;
		if(fuel_check==1)
		{
		cout<<"Total cost for fuel consumed ="<<fuel_cost<<endl;
		cout<<"Net money earned = "<<net;
		}
		else
		{cout<<"\nNet amount 			:"<<net;
		}
	}

}obj;
void record()
{
	ofstream t("uber record.txt",ios::out|ios::app);
	t<<"\nDATE : "<<obj.date<<"\n";
	t<<"Total number of rides 	:"<<obj.n<<"\n";
	t<<"KMs travelled shown in car 	:"<<obj.km_c<<"\n";
	t<<"KMs travelled shown in app 	:"<<obj.km_app<<"\n";
	t<<"Cash collected	  	:"<<obj.cash_c<<"\n";
	t<<"Amount shown in app      	:"<<obj.amt_shown<<"\n";
	t<<"Bonus earned	     	:"<<obj.bonus<<"\n";
	t<<"Tax paid			:"<<obj.tax<<"\n";
	t<<"Uber fee			:"<<obj.u_fee<<"\n";
	t<<"Net amount 			:"<<obj.net<<"\n";
}
void work_1st()
{
	ofstream x1("uber.dat",ios::out|ios::binary);
	obj.sh();obj.ask_day_wise();
	cout<<"Do you want to calculate the individual ride cost ? (yes -> 1, no -> 2) : ";
	int nu;
	cin>>nu;
	if(nu==1)
	{ system("cls");
	for(i=1;i<=n1;i++)
	obj.cal_manual();
	obj.cal(1);}
	else
	{
	obj.cal();
	}
	/*cout<<"Do you want to proceed to fuel calculations ? ( yes->1 ; no -> 2) : ";//for fuel related calculations and actual profit
	cin>>nu;
	if(nu==1)
	{
	obj.fuel2();
	fuel_check=1;
	}*/
	x1.write((char*)&obj,sizeof(obj));

	record();
	obj.display();
	x1.close();
}
void work_continue()
{
	ofstream x1("uber.dat",ios::app|ios::binary|ios::out);
	cout<<"Do you want to calculate the individual ride cost ? (yes -> 1, no -> 2) : ";
	int nu;
	cin>>nu;
	if(nu==1)
	{
	system("cls");
	obj.cal_manual();
	obj.cal(1);
	}
	else
	{

	obj.ask_day_wise();
	obj.cal();
	}
	/*out<<"Do you want to proceed to fuel calculations ? ( yes->1 ; no -> 2) : ";//for fuel related calculations and actual profit
	cin>>nu;
	if(nu==1)
	{
	obj.fuel2();
	fuel_check=1;
	}*/
	x1.write((char*)&obj,sizeof(obj));
	record();
	obj.display();
	x1.close();
}
void read_file()
{
	turn=1;
	ifstream y("uber.dat",ios::binary);
	while(!y.eof())
	{

		y.read((char*)&obj,sizeof(obj));

		obj.display();
		cout<<"\n PRESS ANY KEY TO SHOW NEXT RECORD \n";
		cout<<"\nRECORD NUMBER "<<turn<<"\n";
		turn++;
		getchar();
		system("cls");
	}
	y.close();
}
int main()
{
	system("cls");
	int ak;
	cout<<"WELCOME\nAre you using this software for the first time ?\n";
	cout<<" (USE) yes->(1)	no->(2) ";
	cin>>ak;
	if(ak==1)
	{work_1st();}
	cout<<"\nDo you want to add more records?\n";
	cin>>ak;
	if(ak==1)
	{
		cout<<"How many records do u want to add at a time?\n ";
		int nu=0;
		cin>>nu;
		for(i=1;i<=nu;i++)
		{
			cout<<"\n\nRECORD NUMBER :"<<i<<endl;
			work_continue();
		}
	}
	cout<<"\nDo you want to read all the existing records ?\n";
	cin>>ak;
	if(ak==1)
	read_file();
	cout<<"\n\n\n\n\n\n\n\n THANK YOU..!"<<endl;
	getchar();
	return 0;

}






