
#ifndef DOUBLEHASHING_H_
#define DOUBLEHASHING_H_
#include <iostream>
#include <string>
using namespace std;

template <class V>
class DoubleHashing {

public:
	//Variable: Size of the array
	static const int size = 31;

	//Constructor
	DoubleHashing(){
		for(int i = 0; i < size; i++){
			ar[i] = Entry();
		}
	}

	//Accessors & Mutators
	//Inserts a key and value to map
	void insert(int k, V val){
		ar[hashKey(k, 0)] = Entry(k, val);
	}

	//Remove a key and value from map
	void remove(int k){
		ar[hashKey(k, 0)] = Entry();
	}

	//Print all present keys and their corresponding values.
	void Print(){
		cout << "Key     Value\n";
		cout << "----------------\n";
		for(int i = 0; i < size; i++){
			cout << ar[i].key << " ";
			if(ar[i].value == V())
				cout << " NULL" << endl;
			else
				cout << ar[i].value << endl;
		}
		cout << endl << endl;
	}


private:
	//Variable to store key and value in together
	//Struct will maintain relationship between key and value
	struct Entry{
		int key;
		V value;

		//Constructor
		Entry(){
			key = 0;
			value = V();
		}

		//Constructor
		Entry(int k, V val){
			key = k;
			value = val;
		}

	};
	Entry ar[size];		//Array of struct elements.


	//Function to check for an open spot by generating hashkeys
	//and checking against data
	int hashKey(int k, int j){
		int hashkey;
		hashkey = ( (k % size) + j * (17 - k % 17) ) % size;
		//If array hashkey = v(), then return hashkey.
		if(ar[hashkey].value == V() || ar[hashkey].key == k){
			return hashkey;
		}
		//else call hashkey recursively with the original key k and j+1.
		else{
			return hashKey(k, j+1);					//Recursion till empty spot is found.
		}
	}

};

#endif /* DOUBLEHASHING_H_ */
