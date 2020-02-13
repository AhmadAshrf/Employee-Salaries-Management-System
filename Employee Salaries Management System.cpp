#include<iostream>
#include<string>
using namespace std;

class Employee {
protected :
	string name;
	int emp_id;
	float salary;
public:
	Employee(){								//defualt constractor
		name = "Unknown";
		emp_id = 0;
		salary = 0.0;					// also we can set default values using -> intialization list  
	};
	Employee(string n, int id, float s){
		name = s;
		emp_id = id;
		salary = s;
	}
	virtual float get_total_salary() = 0;	//pure virtual function

	virtual void print() {
		cout << "Emplyee Name : " << name << " and ID :" << emp_id << " and Salary :" << salary << endl;
	};
};
class Sales :public Employee {
private:
	float gross_salary;
	float commission_rate;
public:
	Sales(string n, int id, float s, float gs, float cr):Employee(n,id,s){ //default constractor
		gross_salary = gs;
		commission_rate = cr;
	};
	float get_total_salary() {
		return salary + (gross_salary * commission_rate);
	};
	void print() {
		Employee::print();
		cout << "Gross Salary : " << gross_salary << " and Commission Rate Is: " << commission_rate << endl;
	};
};
class Engineer :public Employee{
private:
	string speciality;
	int expereince;
	int over_time;
	float overTime_hour_rate;
public:
	Engineer(string n, int id, float s, string sp, int exp, int ot, float ohr):Employee(n,id,s){
		speciality = sp;
		expereince = exp;
		over_time = ot;
		overTime_hour_rate = ohr;
	};
	float get_total_salary(){			//overriding the method
		return salary + (over_time*overTime_hour_rate);
	};
	void print() {
		Employee::print();
		cout << "Emplyee Speciality : " << speciality << " and Expereince : " << expereince << " and Over Time Hours :" <<over_time << "and Over Time Hour Rate is : " << overTime_hour_rate << endl;

	}
};



int main() {

	Employee* emp_ptr;
	Sales S1("Ahmed Ashraf", 2387, 6000, 80000, 0.15);
	Engineer E1("Ahmed Ashraff", 150, 8000, "Software Engineer", 5, 3, 50);
						//Polymorphism//
	emp_ptr = &S1;
	emp_ptr -> get_total_salary();
	emp_ptr -> print();

	emp_ptr = &E1;
	emp_ptr -> get_total_salary();
	emp_ptr -> print();


	system("pause");
	return 0;
};