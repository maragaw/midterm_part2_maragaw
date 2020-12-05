#include <iostream>
#include <algorithm>
#include "MySorting.h"

using namespace std;


//concatenates array of strings into one string
string toString(string a[], size_t size){ 
    //cout<<"Printing Array" <<endl;
    string result = "";
    for(size_t i = 0; i < size; i++){
        result += (a[i] + ",");
    }
    return result;
}

string customSort(string a[], size_t size){

    string result = "";
    string upper = "";
    string item = "";
    int shiftIndex = 0;
    //first transform to uppercase
    for(size_t i = 0; i < size; i++){
        string upper = a[i]; //assign each string of array to temp string
        transform(upper.begin(), upper.end(), upper.begin(), ::toupper); //transform string to uppercase
        a[i] = upper; //change element in array to that new uppercase string
    }
    
    //sort them from shortest to longest
    //use alphabetical order to break ties
    //assume its only alphabetical letters
    for(size_t i = 1; i < size; i++){
        item = a[i];
        shiftIndex = i-1;
        //while loop 1
        while (shiftIndex >=0 && a[shiftIndex].length() > item.length()){
            a[shiftIndex+1] = a[shiftIndex];
            shiftIndex -=1;
        }
        //breaks when shiftindex not bigger than 0, string at shiftindex comes first alphabetically
        if(a[shiftIndex].length() == item.length()){ //runs when they are the same length to break the tie
            while(shiftIndex >= 0 && a[shiftIndex].compare(item)>0 && a[shiftIndex].length()==item.length()){ 
                a[shiftIndex+1] = a[shiftIndex];
                shiftIndex -=1;
            }
            
        }
        a[shiftIndex + 1] = item; //if while loop breaks, put selected "item" one to the right of what its smaller than
    }

    for(size_t i = 0; i < size; i++){
        result += (a[i] + ",");
    }
    result.pop_back();
    return result;
}
