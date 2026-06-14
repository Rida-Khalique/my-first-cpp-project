#include<iostream>
#include<string>
using namespace std;

class Employee{

	protected:
		string name;
		int id;
		string department;
		static int employeecount;

	public:

		Employee(string n="unknown",int i=0,string d="unknown"){
			name=n;
			id=i;
			department=d;
			employeecount++;
		}

		static int getEmployeeCount(){
			return employeecount;
		}

		virtual void work()=0;

		virtual void display(){

			cout<<"Employee Name: "<<name<<endl;
			cout<<"Employee ID: "<<id<<endl;
			cout<<"Department: "<<department<<endl;
		}

		virtual ~Employee(){
			employeecount--;
		}
};

int Employee::employeecount=0;

class Manager : virtual public Employee{

	protected:
		int teamsize;

	public:

		Manager(string n="unknown",int i=0,string d="unknown",int t=0)
		: Employee(n,i,d){

			teamsize=t;
		}

		void work(){

			cout<<"Manager "<<name
			<<" is managing a team of "
			<<teamsize<<" employees."<<endl;
		}

		void display(){

			Employee::display();

			cout<<"Team Size: "<<teamsize<<endl;
		}
};

class Developer : virtual public Employee{

	protected:
		string programmingLanguage;

	public:

		Developer(string n="unknown",int i=0,
		string d="unknown",string p="unknown")
		: Employee(n,i,d){

			programmingLanguage=p;
		}

		void work(){

			cout<<"Developer "<<name
			<<" is coding in "
			<<programmingLanguage<<endl;
		}

		void display(){

			Employee::display();

			cout<<"Programming Language: "
			<<programmingLanguage<<endl;
		}
};

class TeamLead : public Manager, public Developer{

	protected:
		string projectName;

	public:

		TeamLead(string n="unknown",int i=0,
		string d="unknown",int t=0,
		string p="unknown",string pr="unknown")

		: Employee(n,i,d),
		  Manager(n,i,d,t),
		  Developer(n,i,d,p){

			projectName=pr;
		}

		void work(){

			cout<<"Team Lead "<<name
			<<" is managing project "
			<<projectName
			<<" and coding in "
			<<programmingLanguage<<endl;
		}

		void display(){

			Employee::display();

			cout<<"Team Size: "<<teamsize<<endl;
			cout<<"Programming Language: "
			<<programmingLanguage<<endl;

			cout<<"Project Name: "
			<<projectName<<endl;
		}
};

class Company{

	public:

		Employee* employees[100];
		int count;

		Company(){
			count=0;
		}

		void addEmployee(Employee* e){

			if(count>=100)
				throw 1;

			employees[count++]=e;
		}

		void showAllEmployees(){

			if(count==0)
				throw 2;

			for(int i=0;i<count;i++){

				employees[i]->display();
				cout<<"----------------------"<<endl;
			}
		}

		void employeeWork(){

			if(count==0)
				throw 3;

			for(int i=0;i<count;i++){

				employees[i]->work();
			}
		}

		void clearCompany(){

			for(int i=0;i<count;i++){

				delete employees[i];
			}

			count=0;

			cout<<"All employee records deleted successfully."<<endl;
		}

		~Company(){

			clearCompany();
		}
};

int main(){

	Company company;

	int choice;

	do{

		cout<<"\n===== Employee Management System ====="<<endl;

		cout<<"1. Add Manager"<<endl;
		cout<<"2. Add Developer"<<endl;
		cout<<"3. Add Team Lead"<<endl;
		cout<<"4. Show All Employees"<<endl;
		cout<<"5. Show Employee Work"<<endl;
		cout<<"6. Show Total Employees"<<endl;
		cout<<"7. Delete All Records"<<endl;
		cout<<"8. Exit"<<endl;

		cout<<"Enter choice: ";
		cin>>choice;

		try{

			switch(choice){

				case 1:{

					string n,d;
					int id,t;

					cout<<"Enter Name: ";
					cin>>n;

					cout<<"Enter ID: ";
					cin>>id;

					cout<<"Enter Department: ";
					cin>>d;

					cout<<"Enter Team Size: ";
					cin>>t;

					company.addEmployee(
					new Manager(n,id,d,t));

					cout<<"Manager added successfully."<<endl;

					break;
				}

				case 2:{

					string n,d,p;
					int id;

					cout<<"Enter Name: ";
					cin>>n;

					cout<<"Enter ID: ";
					cin>>id;

					cout<<"Enter Department: ";
					cin>>d;

					cout<<"Enter Programming Language: ";
					cin>>p;

					company.addEmployee(
					new Developer(n,id,d,p));

					cout<<"Developer added successfully."<<endl;

					break;
				}

				case 3:{

					string n,d,p,pr;
					int id,t;

					cout<<"Enter Name: ";
					cin>>n;

					cout<<"Enter ID: ";
					cin>>id;

					cout<<"Enter Department: ";
					cin>>d;

					cout<<"Enter Team Size: ";
					cin>>t;

					cout<<"Enter Programming Language: ";
					cin>>p;

					cout<<"Enter Project Name: ";
					cin>>pr;

					company.addEmployee(
					new TeamLead(n,id,d,t,p,pr));

					cout<<"Team Lead added successfully."<<endl;

					break;
				}

				case 4:{

					company.showAllEmployees();

					break;
				}

				case 5:{

					company.employeeWork();

					break;
				}

				case 6:{

					cout<<"Total Employees Created: "
					<<Employee::getEmployeeCount()
					<<endl;

					break;
				}

				case 7:{

					company.clearCompany();

					break;
				}

				case 8:{

					cout<<"Exiting Program..."<<endl;

					break;
				}

				default:

					cout<<"Invalid Choice."<<endl;
			}
		}

		catch(int e){

			if(e==1){

				cout<<"Company record is full."<<endl;
			}

			else if(e==2){

				cout<<"No employee records found."<<endl;
			}

			else if(e==3){

				cout<<"No employees available to work."<<endl;
			}
		}

	}while(choice!=8);

	return 0;
}
