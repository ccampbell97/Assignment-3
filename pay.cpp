#include<iostream>
#include"person.h"
#include<vector>
#include<fstream>
#include<iomanip>

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
			else if (j == companyNames.size() - 1)
				companyNames.push_back(employees[i].getCompanyName());
		}
	}
}

void printHighestPaid(vector<Person> &employees)
{
	int i = 0, highIndex = 0;
	for (i = 0; i < employees.size(); i++)
	{
		if (employees[i].totalPay() > employees[highIndex].totalPay())
			highIndex = i;
	}
	cout << "Highest Paid: " << employees[highIndex].fullName() << endl;
	cout << "Employee ID: " << employees[highIndex].getEmployeeId() << endl;
	cout << "Employer: " << employees[highIndex].getCompanyName() << endl;
	cout << "Total Pay: $" << employees[highIndex].totalPay() << endl;
}

void separateAndSave(vector<Person> &employees, vector<string> &companyNames)
{
	ofstream dataFile;
	int i, j;
	float companyTotal = 0;
	for (i = 0; i < companyNames.size(); i++)
	{
		dataFile.open(companyNames[i] + ".txt");
		for (j = 0; j < employees.size(); j++)
		{
			if (employees[j].getCompanyName() == companyNames[i])
			{
				dataFile << left << setw(17) << employees[j].fullName() << " " << setw(3) << employees[j].getEmployeeId() << " " << employees[j].getCompanyName() << " ";
				dataFile.precision(2);
				dataFile << employees[j].totalPay() << endl;
				companyTotal = companyTotal + employees[j].totalPay();
			}
		}
		dataFile << "Total: " << companyTotal;
		companyTotal = 0;
		dataFile.close();
	}
}

int main()
{
	vector<Person> employees;
	vector<string> companyNames;
	readData(employees);
	getCompanies(employees, companyNames);
	printHighestPaid(employees);
	separateAndSave(employees, companyNames);
}
