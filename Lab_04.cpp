#include <bits/stdc++.h>
using namespace std;
#define nl cout << endl

/*****************************************************************************/

//User-Defined Function for calculating all subjects and students average number.
int marks[10][10];
double avgsub[10];
double avgstu[10];
void precompute()
{
    int sum1, sum2;
    for(int i = 0 ; i < 10 ; i++){
        sum1 = 0;sum2=0;
        for(int j = 0 ; j < 10; j++){
            sum1+= marks[i][j];
            sum2 +=marks[j][i];
        }
        avgsub[i] = 1.0*sum1/10;
        avgstu[i] = 1.0*sum2/10;
    }
}

int main()
{
    srand(time(0));
    int sub , u , sum = 0;
    char st;

    //Input
    for(int i = 0; i < 10 ; i++){
        for(int j = 0 ;j < 10 ; j++){
            marks[i][j] = rand()%100;

        }
    }

    //Number Representation

    cout << "***************************************************************";nl;
    cout << "* Subject *" << setw(35) << "Student's Marks" << setw(17) << "*";nl;
    cout << "*   Code  *" << setw(6) << "S1 |" << setw(5) << "S2 |" << setw(5)<< "S3 |" << setw(5)<< "S4 |" << setw(5)<< "S5 |" << setw(5)<< "S6 |" << setw(5)<< "S7 |" << setw(5)<< "S8 |" << setw(5)<< "S9 |" << setw(5)<< "S10 " << "*";
    nl;
    cout << "***************************************************************";nl;
    for(int i = 0; i < 10 ; i++){
        cout << "*" << setw(6) << 101+i << setw(5) << "* ";
        for(int j = 0 ;j < 9 ; j++){
           cout << setw(3)  << marks[i][j] << " |";
        }
        cout << setw(4) << marks[i][9] << " *";nl;
        if(i <9){
            cout << "*" <<"---------*---------------------------------------------------*";nl;
        }
    }
    cout << "***************************************************************";nl;nl;


    //Task #01
    cout << "Enter a Subject Code(101-110): ";
    cin >> sub;
    cout << "Mark of Subject " << sub << ":";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "* Student *" << setw(6) << "S1 |" << setw(5) << "S2 |" << setw(5)<< "S3 |" << setw(5)<< "S4 |" << setw(5)<< "S5 |" << setw(5)<< "S6 |" << setw(5)<< "S7 |" << setw(5)<< "S8 |" << setw(5)<< "S9 |" << setw(5)<< "S10 " << "*";
    nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "*" << setw(6) << "Mark" << setw(5) << "* ";

    sub-=101;
    for(int i = 0 ; i < 9 ; i++){
        cout << setw(3)  << marks[sub][i] << " |";
    }
    cout << setw(4) << marks[sub][9] << " *";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;nl;

    //Task #02
    cout << "Enter a Student(S1-S10): ";
    cin >> st >> u;
    cout << "Mark of Student " << u << ":";nl;

    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "* Subject *" << setw(6) << "101|" << setw(5) << "102|" << setw(5)<< "103|" << setw(5)<< "104|" << setw(5)<< "105|" << setw(5)<< "106|" << setw(5)<< "107|" << setw(5)<< "108|" << setw(5)<< "109|" << setw(5)<< "110" << "*";
    nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "*" << setw(6) << "Mark" << setw(5) << "* ";
    for(int i = 0 ; i < 9 ; i++){
        cout << setw(3)  << marks[i][u] << " |";
    }

    cout << setw(4) << marks[9][u] << " *";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;nl;

    // function call.
    precompute();

    //Task #03
    cout << "Average Mark in each subjects:";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "* Subject *" << setw(6) << "101|" << setw(5) << "102|" << setw(5)<< "103|" << setw(5)<< "104|" << setw(5)<< "105|" << setw(5)<< "106|" << setw(5)<< "107|" << setw(5)<< "108|" << setw(5)<< "109|" << setw(5)<< "110" << "*";
    nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "*" << setw(2) << "Avg Mark" << setw(3) << "* ";
    for(int i = 0 ; i < 9 ; i++){
        cout << setw(1) << fixed << setprecision(1) << avgsub[i] << "|";
    }

    cout << setw(5) << fixed << setprecision(1) << avgsub[9] << "*";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;nl;



    //Task #04
    cout << "Average Mark of each students:";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "* Student *" << setw(6) << "S1 |" << setw(5) << "S2 |" << setw(5)<< "S3 |" << setw(5)<< "S4 |" << setw(5)<< "S5 |" << setw(5)<< "S6 |" << setw(5)<< "S7 |" << setw(5)<< "S8 |" << setw(5)<< "S9 |" << setw(5)<< "S10 " << "*";
    nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;
    cout << "*" << setw(2) << "Avg Mark" << setw(3) << "* ";
    for(int i = 0 ; i < 9 ; i++){
        cout << setw(1) << fixed << setprecision(1) << avgstu[i] << "|";
    }

    cout << setw(5) << fixed << setprecision(1) << avgstu[9] << "*";nl;
    cout << "*" <<"---------*---------------------------------------------------*";nl;nl;

    //Task #05
    cout << "Enter two subject code to find the higher average number between the two subjects: ";
    int s1, s2;
    cin >> s1 >> s2;
    cout << "Subject-"<< ((avgsub[s1-101] > avgsub[s2-101])? s1:s2) <<" has the higher average mark.";nl;nl;

    //Task #06
    cout << "Enter a subject to know the number of student(s) who obtained more than 80: ";
    cin >> sub;
    for(int i = 0 ; i < 9 ; i++){
        if(marks[sub-101][i] >80) sum++;
    }
    cout << sum << " Student(s) have obtained more than 80 marks in " << sub << " subject.";nl;

    return 0;
}
