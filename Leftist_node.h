
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
 * Calender Term of Submission:  (Fall) 2017
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

#ifndef LEFTIST_NODE_H
#define LEFTIST_NODE_H

#include <algorithm>
// You may use std::swap and std::min
// a =5  b =3
//std::swap ->  swap(a,b)
//a =3 b =5

//std::min returns smaller of given values. min(a,b)
#ifndef nullptr
#define nullptr 0
#endif
using namespace std;

template <typename Type>
class Leftist_node {
	private:
		Type element;
		Leftist_node *left_tree;
		Leftist_node *right_tree;
		int heap_null_path_length;

	public:
		Leftist_node( Type const & );

		Type retrieve() const;
		bool empty() const;
		Leftist_node *left() const;
		Leftist_node *right() const;
		int count( Type const & ) const;
		int null_path_length() const;

		void push( Leftist_node *, Leftist_node *& );
		void clear();
};

template <typename Type>
Leftist_node<Type>::Leftist_node( Type const &obj ):
element( obj ),
left_tree( nullptr ),
right_tree( nullptr ),
heap_null_path_length( 0 ) {
	// does nothing
}

// You may need this

template <typename Type>
bool Leftist_node<Type>::empty() const {
	return ( this == nullptr );
}

// You must implement everything
template <typename Type>
Type Leftist_node<Type>::retrieve() const {
    return (this->element);
}

template <typename Type>
int Leftist_node<Type>::count(Type const &obj) const{
    int count = 0;
    if (element == obj){
        count++;
    }
    if (left_tree ->empty() && right_tree ->empty()){
        return count;
    }
    if (left_tree -> empty() == 0 ){
        count += left_tree->count(obj);
    }
    if (right_tree->empty() == 0){
        count += right_tree->count(obj);
    }
    return count;


}


template <typename Type>
int Leftist_node<Type>::null_path_length() const {
    if(this->empty()){
        return (-1);
    }
	return (this->heap_null_path_length);
}

template <typename Type>
Leftist_node<Type>* Leftist_node<Type>::left() const {
	return (this->left_tree);
}

template <typename Type>
Leftist_node<Type>* Leftist_node<Type>::right() const {
	return (this->right_tree);
}

template <typename Type>
void Leftist_node<Type>::clear() {
    if (empty()){

        return;
    }else{
        this->left()->clear();
        this->right()->clear();
        delete this;

    }
}

template <typename Type>
void Leftist_node<Type>::push( Leftist_node *new_heap, Leftist_node *&ptr_to_this ){
    if(new_heap->empty()){
        return;
    }
    if(ptr_to_this->empty()){
        ptr_to_this = new_heap;
        return;
    }
    if(ptr_to_this->retrieve() <= new_heap->retrieve()){

        right_tree->push(new_heap, right_tree);

        if(this->empty()){
            this->heap_null_path_length = -1;
        }
        if(this->right()->empty() || this->left()->empty()){
            this->heap_null_path_length = 0;
        }else{
            this->heap_null_path_length = min(this->left()->null_path_length(), this->right()->null_path_length())+ 1;
        }

        if(this->left()->null_path_length()<this->right()->null_path_length()){
            std::swap(left_tree, right_tree);
        }

    }else{
        ptr_to_this = new_heap;
        (*new_heap).push(this, ptr_to_this);

    }

}
#endif
