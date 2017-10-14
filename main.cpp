#include <iostream>
#include "Dynamic_stack.h"
#include "Exception.h"
#include <cstdlib>

class wrong_answer{};

int main(){

/*
    Dynamic_stack s = Dynamic_stack(1);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << endl<<s.top()<<endl;
*/

        int case_number = 0;
    std::cout << "Exception checking..." << std::endl;
    // case 0


    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(-1);
        if ((s.capacity() == 1)){
            std::cout<<"nice meme"<<std:: endl;
        }
    }catch(illegal_argument){
        std::cout << "Exception Caught, Test Passed." << std::endl;
    }


    // case 1
    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(-1);
    }catch(illegal_argument){
        std::cout << "Exception Caught, Test Passed." << std::endl;
    }

    // case 2
    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(1);
        s.pop();
    }catch(underflow){
        std::cout << "Exception Caught, Test Passed." << std::endl;
    }

    // case 3
    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(1);
        s.push(1);
        s.pop();
        s.pop();
    }catch(underflow){
        std::cout << "Exception Caught, Test Passed." << std::endl;
    }

    //csae 5
    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(1);
        s.push(10);
        if (s.pop() != 10){
            throw wrong_answer();
        }
        std::cout << "Passed, Correct answer." << std::endl;
    }catch(wrong_answer){
        std::cout << "!Wrong answer";
    }

    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(23);
        int * arr = new int[1000];
        for (int i = 0; i < 1000; ++i){
            arr[i] = rand();
            s.push(arr[i]);
        }
        for (int i = 999; i >= 0; --i){
            if (s.pop() != arr[i]){
                throw wrong_answer();
            }
        }
        std::cout << "Passed, Correct answer." << std::endl;
    }catch(wrong_answer){
        std::cout << "!Wrong answer";
    }

    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(23);
        if (s.capacity() != 23){
            throw wrong_answer();
        }
        std::cout << "Passed, Correct answer." << std::endl;
    }catch(wrong_answer){
        std::cout << "!Wrong answer";
    }

    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(23);
        for (int i = 0; i < 100; ++i){
            s.push(rand());
        }
        s.clear();
        if (s.capacity() != 23){
            throw wrong_answer();
        }
        std::cout << "Passed, Correct answer." << std::endl;
    }catch(wrong_answer){
        std::cout << "!Wrong answer";
    }

    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(23);
        if (s.size() != 0){
            throw wrong_answer();
        }

        std::cout << "Passed, Correct answer." << std::endl;
    }catch(wrong_answer){
        std::cout << "!Wrong answer";
    }

    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(1);
        s.push(rand());
        if (s.size() != 1){
            throw wrong_answer();
        }

        std::cout << "Passed, Correct answer." << std::endl;
    }catch(wrong_answer){
        std::cout << "!Wrong answer";
    }

    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(1);
        s.push(rand());
        if(s.empty()){
            throw wrong_answer();
        }else{
            std::cout<<"The following is not empty so right!"<<std::endl;
        }

    }catch(wrong_answer){
        std::cout<<"!Wrong answer";
    }


    try{
        std::cout << "Test Case " << case_number++ << std::endl;
        Dynamic_stack s = Dynamic_stack(1);

        if(s.empty()){
            std::cout<<"The following is empty so right!"<<std::endl;
        }else{
            throw wrong_answer();
        }

    }catch(wrong_answer){
        std::cout<<"!Wrong answer";
    }

    for (int i=0; i<10; i++) {
        cout << i*i << endl;
    }

    return 0;


}
