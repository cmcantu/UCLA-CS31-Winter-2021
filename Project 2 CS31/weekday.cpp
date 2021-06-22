/* CS31 Project 2
Cassandra Cantu
UID:305-100-205
W21 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    
//Declare variables
    string m; int d=0; int y=0; //inputs
    int mc = 0; int cv =0; int cc = 0; int yc=0; int dc = 0; string w; //codes and calculations
    
//User input
    //Month
        cout << "Provide a month: ";
        getline(cin, m);
        if (m!="January" && m!="February" && m!="March" && m!="April" //Check for error
            && m!="May" && m!="June" && m!="July" && m!="August" && m!="September"
            && m!="October" && m!="November" && m!="December") {
            cout << "Invalid month!" << endl;
            return(-1);
        }
    //Day
        cout << "Provide a day: ";
        cin >> d;
        if (d<1||d>31) {  //Check for error
           cout << "Invalid day!" << endl;
           return(-1);
        }
    //Year
        cout << "Provide a year: ";
        cin >> y;
        if (y<1||y>3000) {  //Check for error
            cout << "Invalid year!" << endl;
            return (-1);
        }
    
//Calculations
    //month code
        if (m == "April" || m == "July") {
            mc = 0;
        }
        else if (m == "January" || m == "October") {
            mc = 1;
            if (m == "January" && y%4 == 0) { //Check for leap year offset
                mc = mc-1;
                if (y%100 == 0) {
                    mc = 1;
                    if (y%400 ==0) {
                        mc = mc-1;
                    }
                }
            }
        }
        else if (m == "May") {
            mc = 2;
        }
        else if (m == "August") {
            mc = 3;
        }
        else if (m == "February" || m == "March" || m == "November") {
            mc = 4;
            if(m== "February" && y%4 == 0) { //Check for leap year offset
                mc = mc-1;
                    if (y%100 == 0) {
                        mc = 4;
                        if (y%400 ==0) {
                            mc = mc-1;
                        }
                    }
                }
            }
        else if (m == "June") {
            mc = 5;
        }
        else if (m == "September" || m == "December") {
            mc = 6;
            cout << "mc is " << mc << endl;
        }
        else { //check for error
            cout << "Invalid month!" << endl;
            return(-1);
        }
    //Century Code
        cv = (y/100)%4; //century value calculation
        if (cv == 0) {
            cc = -2;
        }
        else if (cv==1) {
            cc = 3;
        }
        else if (cv==2) {
            cc = 1;
        }
        else if (cv==3) {
            cc = -1;
        }
    //Year Code
        yc = (y%100)/4 + y%100;
    //Day Code
        dc = (cc+d+yc+mc)%7;
        if (dc==0) { //get days of the week
            w = "Sunday";
        }
        else if (dc==1 || dc==-6) {
            w = "Monday";
        }
        else if (dc==2 || dc==-5) {
            w = "Tuesday";
        }
        else if (dc==3 || dc==-4) {
            w = "Wednesday";
        }
        else if (dc==4 || dc==-3) {
            w = "Thursday";
        }
        else if (dc==5 || dc==-2) {
            w = "Friday";
        }
        else if (dc==6 || dc==-1) {
            w = "Saturday";
        }
    
//Output message
  cout << m << ' ' << d << ", " << y << " was a " << w << '!' <<endl;
return (0);
}
