#include<iostream>
#include"person.h"
#include<vector>
#include<fstream>

using namespace std;

void readData(vector<Person> &employees)
{
	string fName, lName, coName;
	int id;
	float hours, rate;
	Person employ;
	ifstream dataFile;
	dataFile.open("input.txt");
	dataFile >> fName;
	while (dataFile)
	{
		dataFile >> lName;
		dataFile >> id;
		dataFile >> coName;
		dataFile >> hours;
		dataFile >> rate;
		employ.setFirstName(fName);
		employ.setLastName(lName);
		employ.setEmployeeId(id);
		employ.setCompanyName(coName);
		employ.setHoursWorked(hours);
		employ.setPayRate(rate);
		employees.push_back(employ);
		dataFile >> fName;
	}
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
	int i = 0, j = 0;
	for (i = 0; i < employees.size(); i++)
	{
		if (companyNames.size() == 0)
			companyNames.push_back(employees[i].getCompanyName());
		for (j = 0; j < companyNames.size(); j++)
		{
			if (employees[i].getCompanyName() == companyNames.at(j))
				break;
			else if(j == companyNames.size())
				companyNames.push_back(employees[i].getCompanyName());
		}
	}
}

void printHighestPaid(vector<Person> &employees)
{

}

void separateAndSave(vector<Person> &employees, vector<string> companyNames)
{

}

int main()
{
	vector<Person> employees;
	vector<string> companyNames;
	readData(employees);
	getCompanies(employees, companyNames);
	int i = 0, j = 0;
	for (i = 0; i < employees.size(); i++)
	{
		cout << employees[i].getFirstName() << endl;
		cout << employees[i].getLastName() << endl;
		cout << employees[i].getEmployeeId() << endl;
		cout << employees[i].getCompanyName() << endl;
		cout << employees[i].getHoursWorked() << endl;
		cout << employees[i].getPayRate() << endl << endl;
	}
	for (j = 0; j < companyNames.size(); j++)
	{
		cout << companyNames[j] << endl;
	}
	system("pause");
}