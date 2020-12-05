#include <sstream>
#include "MyHashTable.h"
#include <string>
using namespace std;

// Default constructor. Do not modiify.
MyHashTable::MyHashTable() {
  for (size_t i = 0; i < CAPACITY; i++) {
    table[i] = new vector<pair<string, int>>;
  }
}

// Simple hash function. Do not modify.
//hash function
size_t MyHashTable::hash(string name) const {
	size_t accumulator = 0;
	//name.erase(remove(name.begin(),name.end(),' '),name.end()); //remove space from string
	for (size_t i = 0; i < name.size(); i++) { 
		accumulator += name.at(i); 
	}
	return accumulator % CAPACITY;
}

void MyHashTable::insertItem(string name, int perm) { //done
	
	pair<string,int> newpair {name, perm};
	//size_t index = hash(name); //retrieve index
	this->table[this->hash(name)]->push_back(newpair); //insert new pair into vector
}

void MyHashTable::deleteItem(string name) { //done
	size_t index = hash(name);
	vector<pair<string,int>>::const_iterator iter;
	for(iter = table[index]->begin(); iter !=table[index]->end();iter++){
		if(iter->first == name) break;
	}
	if(iter != table[index]->end())
		table[index]->erase(iter);
}

string MyHashTable::toString() const { //done
	stringstream ss;
	for(int i = 0; i < 5; i++){
		ss << i << ":[";
		vector<pair<string,int>>::const_iterator j= table[i]->begin();
		while(j < table[i]->end()){
			ss << "(" << j->first << "," << j->second << ")";
			++j;

		}
		ss << "]\n";
	}
  return ss.str();
}

MyHashTable::MyHashTable(const MyHashTable &orig) { //copy constructor
	*this = orig;
	/*
	vector<pair<string,int>>* newtable[CAPACITY]; //create array of pointers to vector of pairs

	
	for (size_t i = 0; i < CAPACITY; i++){ //iterate through arr of pointers
		if(orig.table[i] == NULL){ //if original table has null pointers
			newtable[i] = NULL; //set new table to null pointers
		}
		//then there is at least one element
		newtable[i] = orig.table[i];
		cout<<newtable[i]<<endl;
		cout<<orig.table[i]<<endl;
		
		for(vector<pair<string,int>>::const_iterator iter = orig.table[i]->begin(); iter < orig.table[i]->end(); ++iter){ //using iterator of orig table vectors
			pair<string,int> newpair {iter->first, iter->second}; //create new pair with name and perm of orig table vectors using iter
			newtable[i]->push_back(newpair);
		}
		

	}
	*/
}

MyHashTable& MyHashTable::operator =(const MyHashTable &orig){ //memleak

	if(&orig == this){
		return (*this);
	}
	//if empty, then clear this instance
	vector<pair<string,int>>* newtable [CAPACITY];
	for (size_t i = 0; i < CAPACITY; i++){
		newtable[i] = orig.table[i];
	}
	return *this;


}

MyHashTable::~MyHashTable() {

	
	//vector<pair<string,int>>* tmp 
	for(size_t i = 0; i < CAPACITY; i++){
		//for(vector<pair<string,int>>::const_iterator j = table[i]->begin(); j < table[i]->end(); ++j){
		//} 
		table[i]->clear(); //clear the vector this pointer references
		
	}
	
}
