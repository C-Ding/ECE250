#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H


/****************************************
 * UW User ID:  cmding
 * Submitted for ECE 250
 * Semester of Submission: (Fall) 2017
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 ****************************************/

#include "Exception.h"
#include "ece250.h"

enum state { EMPTY, OCCUPIED, DELETED };

template<typename T>
class DoubleHashTable {
	private:
		int count;
		int power;
		int array_size;
		T *array;
		state *array_state;

		int h1( T const & ) const; // first hash function
		int h2( T const & ) const; // second hash function

	public:
		DoubleHashTable( int = 5 );
		~DoubleHashTable();
		int size() const;
		int capacity() const;
		bool empty() const;
		bool member( T const & ) const;
		T bin( int ) const;

		void print() const;
		void insert( T const & );
		bool remove( T const & );
		void clear();
};

template<typename T >
DoubleHashTable<T >::DoubleHashTable( int m ):
count( 0 ), power( m ),
array_size( 1 << power ),
array( new T [array_size] ),
array_state( new state[array_size] ) {

	for ( int i = 0; i < array_size; ++i ) {
		array_state[i] = EMPTY;
	}
    count =0;
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
    //When deleting the array we need to delete both the array state and valeus within the array.
    delete []array_state;
    delete []array;
}

template<typename T >
int DoubleHashTable<T >::size() const{
    // enter your implemetation here
    // Count variable represents the number of elemnts in table
	return count;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    // enter your implemetation here
    //Capacity is the size of the array. So return array_size.
	return array_size;
}



template<typename T >
bool DoubleHashTable<T >::empty() const {
    // enter your implemetation here
    //If count(number of elements in the table is 0)
    //then the list is empty return true.
    //Otherwise return false.
    if (count ==0){
        return true;
    }
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
	// enter your implemetation here
	//number of elements in the hash table is n
	//size of the hash table is M.
	//object is i.
	//h1 = (i % M).
    T h1 = (static_cast<int>(obj)%array_size);
    //We cannot have a negative indexed array.
    if(h1<0){
        h1 = h1+ array_size;
    }
	return h1;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
	// enter your implemetation here
	//h2 calculation for the offset when collision occurs (basis for double hashing).
    T h2 = ((static_cast<int>(obj)/array_size)%array_size);
    if (h2 < 0){
        h2 = h2 + array_size;
    }
    if((static_cast<int>(h2) % 2) == 0){
        h2 = h2 +1;
    }

	return h2;
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
    //initialize probe, offset, counter.
	T probe = h1(obj);
	T offset = h2(obj);
	int counter = 0;
	// While scanning through elements that are not empty
	while(array_state[static_cast<int>(probe)] != EMPTY){
        //check if we found the object.
	    if (array[static_cast<int>(probe)] == obj){
	        //if the object is deleted we need to check if theres more possible links that could be that value.
	        //if not then the status is occupied and that object exits return true.
            if(array_state[(static_cast<int>(probe))] == DELETED){
                 probe = static_cast<int>(probe+offset)% array_size;
                 counter++;
            }else{
                return true;
            }
	    }
        //if that object does not exist in this spot there might be that object in another spot
        //so add offset.
        //increment counter ++ because if  we loop through all the links so many times we there are no values left to look for.
        if (array[static_cast<int>(probe)] != obj){
            probe = static_cast<int>(probe+offset)% array_size;
            counter++;
        }
        if (counter>=array_size){
            return false;
        }

	}
	//if the it is empty then its automatically false.
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
    // enter your implemetation here
    //just return that value in the array.
    return array[n];
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
    // enter your implemetation here
    //account for over flow
    if(count == (array_size)){
       throw overflow();
    }

    T probe = h1(obj);
    T offset = h2(obj);
    //check if the space is occupied. If it is then add offset.
    while(array_state[static_cast<int>(probe)] == OCCUPIED){
        probe = static_cast<int>(probe+offset)% array_size;
    }
    //add object.
    array[static_cast<int>(probe)] = obj;
    //set state to occupied.
    array_state[static_cast<int>(probe)] = OCCUPIED;
    count++;
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
	 // enter your implemetation here
    int counter = 0;
    T probe = h1(obj);
	T offset = h2(obj);

	while(array_state[static_cast<int>(probe)] != EMPTY){
        //the object must be occupied in order for it to be deleted.
	    if ((array[static_cast<int>(probe)] == obj) && (array_state[static_cast<int>(probe)]== OCCUPIED)){
                array_state[static_cast<int>(probe)] = DELETED;
                count--;
                return true;

	    }

            probe =(static_cast<int>(probe)+static_cast<int>(offset))% array_size;
            counter++;

        if (counter> array_size){
            return false;
        }

	}
    return false;


}

template<typename T >
void DoubleHashTable<T >::clear() {
	 // enter your implemetation here
	 //set states back to empty
    for ( int i = 0; i < array_size; ++i ) {
		array_state[i] = EMPTY;
	}
	//make sure count is reset too so size back to 0.
	count = 0;

	 return ;
}

template<typename T >
void DoubleHashTable<T >::print() const {
      // enter your implemetation
      //for testing purposes
      int i=0;
      for( i<0; i<array_size; i++){
        std::cout<<"Bin#";
        std::cout<<i;
        std::cout<<" ";
        std::cout<<"Value:";
        std::cout<<array[i];
        std::cout<<"        ";


      }
      std::cout<<"count   ";
      std::cout<<count ;


}

#endif
