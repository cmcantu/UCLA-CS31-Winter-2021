//Cassandra Cantu
//UID: 305-100-205
//CS 31 W21 Project 4

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

//declare functions
int locateMaximum(const string array[ ], int n);
int countFloatingPointValues(const string array[ ], int n);
bool hasNoCapitals(const string array[ ], int n);
bool identicalValuesTogether(const string array[ ], int n);
bool hasTwoOrMoreDuplicates(const string array[ ], int n);
int shiftLeft(string array[ ], int n, int amount, string placeholder);
int replaceFirstAndLastOccurrences(string array[ ], int n, char charToFind, char charToReplace);

//main
int main()
{
//create strings to use in assert
    string a[6] =  { "123", "456", "789", "gamma", "beta", "delta" }; //given ex
    string num[3] = {"124", "-3", "0.1"}; //neg sign bad, leading 0 ok
    string data[5] = { "mamaBbcca", "mamaBbcca", "12,", "98.76", "tyrion" }; //given ex
    string folks[8] = {  "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "magdalena", "jon" }; //given ex
    string simple[5] = { "0", "1.0", "-2", ".", "."}; //easier to see locate max
    string repeat[6] = {"ate", "abe" "age" "are" "ate" "ate"};
    string c[4] = {"hearts" "hearts" "hearts" "clover"}; //set of 3 matching values
    string s[6] = {"s" "s" "s" "t" "t" "s"}; //3 in a row, 2 in a row, 1
    string d[3] = {"." "1" "hi"}; //optional decimal point

//asserts to test code
    assert(locateMaximum(data, 0) == -1); //n is 0
    assert(locateMaximum(data, -100) == -1); //n is less than 0
    assert(locateMaximum(s, 4) == 0); //smallest index with max calue, next to each other
    assert(locateMaximum(repeat, 6) == 0); //smallest index that has max value, spread out
    assert(locateMaximum(data, 5) == 4); //given ex
    
   
    assert(countFloatingPointValues(a, 0) == -1); //n is 0
    assert(countFloatingPointValues(a, -10) == -1); //n is less than 0
    assert(countFloatingPointValues(data, 5) == 1); //given ex
    assert(countFloatingPointValues(simple, 3) == 2); //optional decimal ok, negative sign not allowed
    assert(countFloatingPointValues(simple, 4) == 3); //n is less than 0
    
    
    assert(hasNoCapitals(data, 0) == true); //n is 0
    assert(hasNoCapitals(data, -300) == true); //n is less than 0
    assert(hasNoCapitals(folks, 8) == true); //does not have capital letters
    assert(hasNoCapitals(data, 5) == false); //has capital letters
 
    
    assert(identicalValuesTogether(data, 0) == false); //n is 0
    assert(identicalValuesTogether(data, -50) == false);  //n is less than 0
    assert(identicalValuesTogether(data, 5) == true); //two next to each other
    assert(identicalValuesTogether(folks, 8) == false); //repeated not next to each other
    assert(identicalValuesTogether(c,4) == true); //3 in a row
    assert(identicalValuesTogether(s,5) == true); //3 in a row, 2 in a row
 //   assert(identicalValuesTogether(s,6) == false); //3 in a row, 2 in a row, fails! gets true
    
    
    assert(hasTwoOrMoreDuplicates(c, 0) == false); //n is 0
    assert(hasTwoOrMoreDuplicates(c, -8) == false); //n is less than 0
    assert(hasTwoOrMoreDuplicates(folks, 8) == false); //given ex, one set of 2, not two
    assert(hasTwoOrMoreDuplicates(folks, 3) == false); //given ex, no 2 sets of 2 or 1 set of 3
    assert(hasTwoOrMoreDuplicates(c, 4) == true); //1 set of 3
    assert(hasTwoOrMoreDuplicates(c, 4) == true); //1 set of 3
    assert(hasTwoOrMoreDuplicates(s, 6) == true); //2 sets of 2
    
    
    assert(shiftLeft(data, 0, 2, "!") == -1); //n is 0
    assert(shiftLeft(data, -5000, 2, "!") == -1); //n is less than 0
    assert(shiftLeft(data, 5, 2, "foo") == 2); //given ex, amount<n
    assert(shiftLeft(data, 5, 10, "bar") == 5); //given ex, amount>n
    assert(shiftLeft(data, 5, -5, "foobar") == -1); //given ex, amount less than 0
    
    
    assert(replaceFirstAndLastOccurrences(folks, 0, 'A', 'Z') == -1); //n is 0
    assert(replaceFirstAndLastOccurrences(folks, -2, 'A', 'Z') == -1); //n is less than 0
    assert(replaceFirstAndLastOccurrences(folks, 8, 'A', 'Z') == 0); //given ex, no A's
    assert(replaceFirstAndLastOccurrences(folks, 8, 'a', 'Z') == 8); //given ex, some with occurences in middle
    
    cerr << "all tests succeeded :)" << endl;
    return 0;
}

//define functions
//return index of largest item
int locateMaximum(const string array[ ], int n)
{
    int index = 0;
    if (n <= 0) { //check n
        index = -1;
    }
    
    string max = array[0]; //define max
    for (int i=0; i<n; i++) { //go through array elements
        if (array[i] > max) {
            max = array[i]; //update with new max
            index = i; //get index
        }
    }
    return(index);
}

//return number of floating point values
int countFloatingPointValues(const string array[ ], int n)
{
    int count = 0;
    if (n <= 0) { //check n
        count = -1;
    }
    
    for (int i=0; i<n; i++) { //go through array elements
        string s = array[i]; //look through each string in array
        string temp = "";
        for (size_t j=0; j < s.size(); j++) { //go through string
            if (isdigit(s.at(j)) || s.at(j) == '.') { //look for number and optional decimal
                temp += s.at(j);
            }
            if (temp.size() == s.size()) {
                count++;
            }
        }
    }
    return(count);
}

//checks all elements have no capital letters
bool hasNoCapitals(const string array[ ], int n)
{
    bool b = true;
    int count = 0;
    if (n <= 0) { //check n
        b = true;
    }
    for (int i=0; i<n; i++) { //go through array elements check
        string s = array[i];
        for (size_t j=0; j < s.size(); j++) { //look at each string in array
                if (isupper(s.at(j))) { //check if capital letter
                    count++; //count number of capital letters
                }
            }
        }
    if (count > 0) {//has capitals
        b = false;
    }
    return(b); //if passes all checks
}

//checks if all identical values are next to each other
bool identicalValuesTogether(const string array[ ], int n)
{
    bool b = true;
    if (n <= 0) { //check n
        b = false;
    }
    for (int i=0; i<n; i++) { //go through array elements
        bool notfind = false;
        string find = array[i]; //search for this string
        for (int j=i+1; j<n; j++) { //look at each string in array
            if (array[j] != find) { //didn't find identical
                notfind = true;
            }
            if (notfind == true && find == array[j]) { //ran into different string and then run into find again
                    b = false; //not together
            }
        }
    }
    return(b);
}

bool hasTwoOrMoreDuplicates(const string array[ ], int n)
{
    bool b = true;
    if (n <= 0) { //check n
        b = false;
    }
    
    int count_two = 0;
    int count_three = 0;
    for (int i=0; i<n; i++) { //go through array elements
        string find = array[i];
        for (int j=0; j<n; j++) { //look at each string in array
            if (array[j] == find && j != i) { //find duplicate, not at same position
                count_two++;
                count_three++;
            }
            if ( (count_two>=4 && count_two%2==0) || (count_three>=3 && count_three%3==0) ) { //found 2 sets of 2 or 1 set of 3
                return true;
            }
            else {
                b = false;
            }
        }
    }
    return(b);
}

int shiftLeft(string array[ ], int n, int amount, string placeholder)
{
    int count = 0;
    int pos = 0;
    if (n <= 0  || amount <0) { //check n and amount
        return -1;
    }
    
    if (amount>n) { //find where to start replacing with placeholder
        pos = 0;
    }
    else {
        pos = n-amount;
    }
    
    for (int i=0; i<n; i++) { //shift everything over left by amount
        array[i] = array[i+amount];
    }
    for (int k=pos; k<n; k++) { //replace everything to right with placeholder
        array[k] = placeholder;
        count++;
    }
    //check array
    // for (int j=0; j<n; j++) {
    //    cout << array[j] << endl;
    //}
        return(count);
}


int replaceFirstAndLastOccurrences(string array[ ], int n, char charToFind, char charToReplace)
{
    int count = 0; //counter for times replaced
    if (n <= 0) { //check n
        count = -1;
    }
    for (int i=0; i<n; i++) {  //go through array elements
        int occur = 0; //counter for occurences
        int occ = 0; //subcounter for occurences
        string s = array[i];
         for (size_t j=0; j < s.size(); j++) { //go through each string from beginning
            if (s.at(j) == charToFind) { //found char
                occur++; //count number of times we found char
           }
         }
        if (occur <= 2) { //have char only first or only first and last
            for (size_t k=0; k < s.size(); k++) { //go through each string from beginning
                if (s.at(k) == charToFind) {
                    s.at(k) = charToReplace; //replace all
                    count++;
                    array[i] =s;
                }
            }
        }
        else if (occur >=3) { //if have char in the middle too
            for (size_t k=0; k < s.size(); k++) { //go through each string from beginning
                if (s.at(k) == charToFind) {
                    occ++;
                    if (occ==1) { //replace first
                        s.at(k) = charToReplace;
                        count++;
                        array[i] = s; //update
                    }
                    else if (occ==occur) {  //replace last
                        s.at(k) = charToReplace;
                        count++;
                        array[i] = s; //update
                    }
                }
            }
        }
    }
    //check array
//    for (int k=0; k<n; k++) {
//        cout << array[k] << endl;
//    }
//   cout << count << endl;
    return(count);
}
