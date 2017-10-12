/*****************************************
 * Instructions
 *  - Replace 'uwuserid' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  cmding@uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission: (Fall) 2017
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>
using namespace std;

//Creating class
class Dynamic_stack {

	private:
		int *array;
		int count;
		int array_size;
		int initial_size;

	public:
		Dynamic_stack(int = 10);
		~Dynamic_stack();

		int top() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void push( int const & );
		int pop();
		void clear();
};

//Constructor
Dynamic_stack::Dynamic_stack( int n ):
count(0),
array_size(n),
initial_size(n)
{
    //The following was to acount for if the user tried to create the array too big.
    //This did not compile within linux
    /*if (array_size  > INT_MAX/2 ){
        throw overflow();
    }*/
    count = 0;
    if(n <= 0){
        array_size=1;
        initial_size=1;
        array = new int[1];

    }
    else{
        array = new int[array_size];
    }

}
Dynamic_stack::

//The deconstructor
Dynamic_stack::~Dynamic_stack() {
	// Enter your implementation here.
	// In this deconstructor I simply delete the created array.
	delete array;
}

//This function accesses the top of the stack and returns its value
int Dynamic_stack::top() const {
    //If the count is == to zero this means there are no elements in the stack tehrefor there is no top value.
    if(count == 0){
        //Throws illegal argument if user tries to access top value when there is no top value
        throw illegal_argument();
    }
    //Count indicates the amount of elemts in the stack.
    //Since the stack is organized within an array, if there is 1 block(element or count =1) in the stack
    //then this owuld be placed within the array index 0 (array[0]).
    //Therefore I must return count -1 to reach top argument.
	return  array[count-1];
}

//This function returns the size of the array
int Dynamic_stack::size() const {
	// Enter your implementation here.
	//count holds the number of values within the stack.
	//Therefore to reutn the size, just return unmber of values within the stack.
	return  count;
}

//isEmpty function
bool Dynamic_stack::empty() const {
	// Enter your implementation here.
    //count represents number of elements in the stack.
    //If the count is 0 or stack has 0 elements in it then return true.
    //Otherwise return false.
	if(count == 0){
        return true;
	}
	else{
        return false;
	}
}

//Check how much space is available in the stack.
int Dynamic_stack::capacity() const {
	// Enter your implementation here.
	//Creates new variable called capcity
	//Capcity is eqvuivalent to the array_size of the array - current elements in the stack.
	//This is essentially saying take the total index of the array and subtract the current number of valeus in it.
    int capacity;
    capacity = array_size - count;
    //return the new variable capcity.
	return capacity;
}

//Push value into stack.
void Dynamic_stack::push( int const &obj ) {
     // Enter your implementation here.

     //If the stack is completely full, create a new stack(array)
     //with double the size.
     //Also, Set initial value to be double the size now aswell
     //because we might need to expand stack again.
     if(count >=array_size){
         //The following was to acount for if the user tried to create the array too big.
         //This did not compile within linux
         /*if (array_size  > INT_MAX/2 ){
            throw overflow();
         }*/
         int temp[array_size];                      //Create temperary variable
         for (int i = 0; i<array_size; i++){        //Store values of pervious array into temp
            temp[i] = array[i];
         }
         delete array;                              //Free memory of the old array (delete it)
         array = new int[(array_size*2)];           //Create a new array of double size

         for(int i=0; i<array_size; i++){           //Store values of temp into newly created array

            array[i]= temp[i];
         }
         array_size *=2;                            //Array size is now double that of before
     }
     //Push object passed by reference into the top of array.
     array[count] = obj;
     //increment count as this represents number of elements in stack.
     count++;
}

//Pop top value on stack
int Dynamic_stack::pop() {
    //If count ==0 there are no values to pop. Therefore throw error.
    if (count==0) {

        throw underflow();
    }
    //Store the variable we are popping into temp variable
    int temp = array[count-1];
    //pop the top value
	array[count-1]= NULL;
	//1 less value in the stack now so decrement count
	count--;
	//Return the value we popped.
	return temp;

}
//This is essentailly a reset
void Dynamic_stack::clear() {
	// Enter your implementation here
	delete array;                       //Free memory
	array = new int[(initial_size)];    //create a new array with the size the user initially set(initial size)
	array_size = initial_size;          //Array size is now initial size.
	count =0;                           //The count is now zero (no valeus within the stack).
}
#endif


