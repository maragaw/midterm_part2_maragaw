#include <sstream>
#include "MyHashTable.h"
#include <string>
using namespace std;

// Default constructor. Do not modiify.
MyHashTable::MyHashTable() {
  for (size_t i = 0; i < CAPACITY; i++) {
    vector<pair<string, int> >* vv = new vector<pair<string, int> >;
	this->table[i] = vv;
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
	
	pair<string,int> newpair (name, perm);
	//size_t index = hash(name); //retrieve index
	this->table[this->hash(name)]->push_back(newpair); //insert new pair into vector
}

void MyHashTable::deleteItem(string name) { //done
	//size_t index = hash(name);
	if(name == ""){
		return;
	}
	if(this->table[this->hash(name)]->size() != 0){
		for(size_t i = 0; i < this->table[this->hash(name)]->size(); i++){
			if(name == this->table[this->hash(name)]->at(i).first)
				this->table[this->hash(name)]->erase(this->table[this->hash(name)]->begin()+i);
		}

	}
	/*
	vector<pair<string,int>>::const_iterator iter;
	for(iter = table[index]->begin(); iter !=table[index]->end();iter++){
		if(iter->first == name) break;
	}
	if(iter != table[index]->end())
		table[index]->erase(iter);
		*/
}

string MyHashTable::toString() const { //done
	stringstream ss;

	for(int i = 0; i < 5; i++){
		ss << i << ":[";
		if(this->table[i]->size() != 0){
			for(size_t j = 0; j < this->table[i]->size(); j++){
				ss<<"(" << this->table[i]->at(j).first << "," << this->table[i]->at(j).second << ")";
			}
			
		}
		ss << "]\n";
		
	}
	return ss.str();
/*
		vector<pair<string,int> >::const_iterator j= table[i]->begin();
		while(j < table[i]->end()){
			ss << "(" << j->first << "," << j->second << ")";
			++j;

		}
		ss << "]\n";
	}
	}
  return ss.str();
  */
}

MyHashTable::MyHashTable(const MyHashTable &orig) { //copy constructor
	//*this = orig;
	
	vector<pair<string,int> >* newtable[CAPACITY]; //create array of pointers to vector of pairs

	for (size_t i = 0; i < CAPACITY; i++){ //iterate through arr of pointers
		if(orig.table[i] == NULL){ //if original table has null pointers
			newtable[i] = NULL; //set new table to null pointers
		}
		//then there is at least one element
		newtable[i] = orig.table[i];
		cout<<newtable[i]<<endl;
		cout<<orig.table[i]<<endl;
		
		for(vector<pair<string,int> >::const_iterator iter = orig.table[i]->begin(); iter < orig.table[i]->end(); ++iter){ //using iterator of orig table vectors
			pair<string,int> newpair (iter->first, iter->second); //create new pair with name and perm of orig table vectors using iter
			newtable[i]->push_back(newpair);
		}
		

	}

	
}

MyHashTable& MyHashTable::operator =(const MyHashTable &orig){ //memleak
	//check for self assignment
	if(&orig != this){
		for(size_t i = 0; i<CAPACITY; i++)
		*table[i] = *orig.table[i];
	}
	return *this;
}

MyHashTable::~MyHashTable() {
	cout<<"Destructor Called"<<endl;
/*

	for(size_t i = 0; i < CAPACITY; i++){
		//delete[] table[i];
		delete table[i];
		//this->table[i]->erase(this->table[i]->begin()+i);
//this->table[i]->clear(); //clear the vector this pointer references
		
	}
	*/
	
}