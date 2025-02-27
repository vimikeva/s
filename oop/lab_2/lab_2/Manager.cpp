/*!
* file: Manager.cpp
* written: 05/02/2015
* synopsis: Manager class implementation
* Copyright (c) 2015 by Yu.Zorin
*/
#include "Manager.h"

Manager::Manager(const Manager &m){
	(*this) = m;	
}

Manager& Manager::operator = (const Manager &m){
	if (this == &m) return *this;
	f_name = m.f_name;
	l_name = m.l_name;
	age = m.age;
	department = m.department;
	salary = m.salary;
	id = m.id;
	subordinates = m.subordinates;
	return *this;
}

Person* Manager::AddSubordinate(Person *p){
	list<Person*>::iterator it = subordinates.begin();
	while(it != subordinates.end()){
		if (dynamic_cast<Employee*>(*it)->GetId() == dynamic_cast<Employee*>(p)->GetId())
			return nullptr;
		++it;
	}
	subordinates.push_back(p);
	return p;
}

void Manager::DisplaySubordinates(){
	list <Person *>::iterator it;
	if (subordinates.empty()){
		cout << "\t\tnone\n\n\n";
		return;
	}
	for(it = subordinates.begin(); it != subordinates.end(); ++it)
		(*it)->Display(true);
}

void Manager::Display(bool){
	cout << "Employee type: manager\n";
	cout << "id: " << id << endl;
	cout << f_name << " " << l_name << "  age: " << age << "  salary: " << salary << endl;
	cout << "department:" << department << endl;
	cout << "Subordinates:\n";
	DisplaySubordinates();
}

void Manager::DellSubordinate(int id){
	list<Person*>::iterator it = subordinates.begin();
	while(it != subordinates.end()){
		if (id == dynamic_cast<Employee*>(*it)->GetId()){
			subordinates.erase(it);
			break;
		}
		++it;
	}
}
