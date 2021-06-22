//CS 31 Project 3
//Cassandra Cantu
//UID: 305-100-205
//W21

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

//declare all functions
int extractNumber(string commands, size_t& index, bool& isValid ); //extracts number from string
bool isValidResultString(string results); //true if string is valid
int positiveTests(string results); //returns total # positive tests if string is valid
int negativeTests(string results); //returns total # negative tests if string is valid
int totalTests(string results); //returns total # of tests from all batches if string is valid
int batches(string results); //returns total # of batches is string is valid

//main
int main()
{
    assert(isValidResultString("") == false); //empty string
    assert(isValidResultString("    ") == false); //string with just whitespace
    assert(isValidResultString("R+1-1") == false); //need number ot total tests
    assert(isValidResultString("R3+1-2") == true); //valid string
    assert(isValidResultString("R0+0-0") == false); //must have a number of cases to report
    assert(isValidResultString("R0-0+0") == false); //must have a number of cases to report
    assert(isValidResultString("R5+0-0") == false); //total must equal pos and neg tests
    assert(isValidResultString("r1+0-1") == false); //must have capital R
    assert(isValidResultString("R1+-1") == false); //need number of positive tests
    assert(isValidResultString("R1+1-") == false); //need number of negative tests
    assert(isValidResultString("R360-300+60") == true); //int values are not limited to a single digit
    assert(isValidResultString("R1+0-1 asdfR") == false); //no extra characters
    assert(isValidResultString("R3-1+2      ") == false); //no extr characters, spec, spaces
    assert(isValidResultString("R5+00003-0002") == false); //no leading zeros
    assert(isValidResultString("R5-3-2") == false); // + and - required every batch
    assert(isValidResultString("R5+3+2") == false); // + and - required every batch
    assert(isValidResultString("R2-1+1R5+3-2") == true); //can take in multiple batches
    
    assert(positiveTests("R3+2-1") == 2); //2 positive results
    assert(positiveTests("R1+1-0R1-1+0R1-1+0R1+1-0") == 2); //positive results from more than 1 batch
    assert(positiveTests("R5+00003-0002") == -1); //invalid string (no leading 0s)
    assert(positiveTests("R3+2+1") == -1); //invalid string (need + and - each batch)
    
    assert(negativeTests("R3+2-1") == 1); //1 negative result
    assert(negativeTests("R3+2-1R9+5-4") == 5); //negative results from more than 1 batch
    assert(negativeTests("R3-2-1") == -1); //return -1 for invalid string
    
    assert(totalTests("R3+2-1") == 3); //3 total tests
    assert(totalTests("R3+2-1R9+5-4") == 12); //total tests from more than 1 batch
    assert(totalTests("R3-2-1") == -1); //return -1 for invalid string
    
    assert(batches("R3+2-1") == 1); //1 batch
    assert(batches("R3+2-1R9+5-4") == 2); //more than 1 batch
    assert(batches("R3-2-1") == -1); //return -1 for invalid string
    
    cout << "All tests succeedded :)" << endl;
}


/* define all functions */
//extractNumber function
int extractNumber( string commands, size_t& index, bool& isValid )
{
 int quantity( 0 ); // track the integer value found
 if (commands.at(index) >= '1' && commands.at(index) <= '9')  // the number can't start with a zero!
 {
     while( index < commands.length() &&  // the number should be made up of digits
           (commands.at(index) >= '0' && commands.at(index) <= '9') )
     {
         // extract one digit and add it to the cumulative value
         // held in quantity "123" ---> 123
         int digit = commands.at( index ) - '0';  // extract one digit and add it to the cumulative value
         quantity = quantity * 10 + digit;
         index = index + 1;
     }
 }
 isValid = (quantity != 0); // run out of digits to consume, the cumulative quantity must not still be zero
 return( quantity );
}

//isValidRestultString function
bool isValidResultString(string results)
{
   //check for empty string
    if (results == "") {
        return (false);
    }
    
    //check for uppercase R
    for (size_t i =0; i < results.size()-1; i++) { //go through string
        if (isalpha(results.at(i))) { //looks for letters of the alphabet
            string letters = "";
            letters += results.at(i); //string of found letters
            for (size_t j = 0; j < letters.size()-1; j++) {
                char checkR = letters.at(j);
                if (checkR != 'R') { //only R allowed
                    return (false);
                }
            }
        }
    }
    
    //check for total after R
    bool b = true;
    int tot = 0;
    int total_tests = 0;
    for (size_t i =0; i < results.size()-1; i++) {
        if (results.at(i) == 'R') { //look for R
            size_t position = i+1; //have index start at next position
           tot = extractNumber(results, position, b); //call on function to get the total number of cases
            if (tot <= 0) { //check
                return(false);
            }
            total_tests += tot;
        }
    }
    
    //check for leading 0s
    for (size_t i =0; i < results.size()-1; i++) {
        if (i >1 && isdigit(results.at(i)) && isdigit(results.at(i-1)) == '0') {
            return (false);
        }
    }
    
    //check if last char is a digit
    size_t last_pos = results.size()-1;
    if (!isdigit(results.at(last_pos))) {
        return (false);
    }
    
    
    //check total equals positive and negative tests
    int value = 0;
    int check_tot = 0;
    size_t pos = 0;
    for (size_t i =0; i < results.size()-1; i++) {
        if (results.at(i) == '+' || results.at(i) == '-' ) { //look for + or -
            pos = i + 1; //go to next position after + or -
            if (isdigit(results.at(pos))) { //check if digit after + or -
                value = extractNumber(results, pos, b);
                check_tot += value;

            }
            else {
               return (false);
            }
        }
    }
    if (check_tot <= 0 || check_tot != total_tests) { //check if total greater than 0 and equal to actual total
    return(false);
    }
//
//
    //check for both + and - in each batch
    int num_pos = 0;
    int num_neg = 0;
    int num_tot = 0;
    for (size_t i =0; i < results.size()-1; i++) {
        if (results.at(i) == 'R' && isdigit(results.at(i+1)) && results.at(i+1) != '0') {
            num_tot++; //number of total tests
        }
        if (results.at(i) == '+') {
           num_pos++; //number of positive tests
        }
            if (results.at(i) == '-' ) {
                num_neg++; //number of negative tests
        }
    }
    if (num_pos != num_neg || ((num_pos+num_neg)/2) != (num_tot)) { //same num of pos/neg tests, avg equals true total
      return (false);
        }
return (true); //if passes all checks
} // finish function here

//positiveTests function
int positiveTests(string results)
{
    if (isValidResultString(results) == true) {  //if string is valid only
        int pos_total = 0;
        int pos_test = 0;
        bool b = true;
        for (size_t i =0; i < results.size()-1; i++) {
            if (results.at(i) == '+') { //look for + sign
                size_t position = i+1;
                pos_test = extractNumber(results, position, b);
                pos_total += pos_test;
            }
                
        }
        return (pos_total);
    }
        
    else { //invalid string
       return(-1);
      }
}

//negativeTests function
int negativeTests(string results)
{
    if (isValidResultString(results) == true) {  //if string is valid only
        int neg_total = 0;
        int neg_test = 0;
        bool b = true;
        for (size_t i =0; i < results.size()-1; i++) {
            if (results.at(i) == '-') { //look for - sign
                size_t position = i+1;
                neg_test = extractNumber(results, position, b);
                neg_total += neg_test;
            }
        }
        return (neg_total);
    }
        
    else { //invalid string
       return(-1);
      }
}

//totalTests function
int totalTests(string results)
{
    if (isValidResultString(results) == true) {
        bool b = true;
        int tot = 0;
        int total_tests = 0;
        for (size_t i =0; i < results.size()-1; i++) {
            if (results.at(i) == 'R') { //look for R
                size_t position = i+1; //have index start at next position
               tot = extractNumber(results, position, b);
                total_tests += tot;
            }
        }
        return(total_tests);
    }
    else {
        return(-1); //if not valid
    }
}

//batches function
int batches(string results)
{
    if (isValidResultString(results) == true) {
        int batch_counter = 0;
   //     int batch_tot = 0;
        for (size_t i =0; i < results.size()-1; i++) {
            if (results.at(i) == 'R') { //look for R
                batch_counter++;
            }
        }
        return(batch_counter);
    }
    else {
        return(-1);
    }
}
