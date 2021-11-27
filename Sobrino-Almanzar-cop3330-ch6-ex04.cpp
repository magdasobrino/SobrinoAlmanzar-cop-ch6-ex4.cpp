/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Magdalena Sobrino-Almanzar
 */

//SobrinoAlmanzar-cop-ch6-ex04.cpp//

//Chapter 4 ex 19//
/*/19. Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add
the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if
names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and
terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line./*/
// Use only one vector//


#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::runtime_error;

struct Name_value {
        Name_value(string n, int s)    // constructor
                :name{n}, score{s}    // member initializer list
        {
        }
        string name;
        int score;
};

void error(string s) {
        throw runtime_error(s);
}

int main()
try{
        vector<Name_value> nameVal;
        string n;
        int v;

        cout << "Enter some single names and scores. To terminate enter no name:\n";

        // to terminate, enter "no name"
        while (cin>>n>>v && n!="noname") {
                for (int i=0; i<nameVal.size(); ++i) {
                        if (n==nameVal[i].name) {
                                error("Try again. It is a duplicate");
                        }
                }
                nameVal.push_back(Name_value(n,v)); 
        }
        
        for (int i=0; i<nameVal.size(); ++i)
                cout << nameVal[i].name << ',' << nameVal[i].score << '\n';
                
} //end of main//
catch (runtime_error e) {
        cout << e.what() << '\n';
}