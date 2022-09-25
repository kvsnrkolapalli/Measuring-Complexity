#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
  
// driver code
int main()
{
    // filestream variable file
    fstream file;
    string word,filename,line;
    int rollin,roll,count,a=0,s=0,s1=0;
    double complexity,u=-1,com=0,avg;
    string newStr[99999];
  
    // filename of the file
    filename = "Alice_in_Wonderland.txt";
  
    // opening file
    file.open(filename.c_str());

    cout << "\nEnter Rolling Size:";
    cin >> rollin;
    cout << "\nRolling Number is " << rollin<<"\n"<<endl;

    while(file>>line){
        // Removing a non alphabetic character
        for (int i = 0, j; line[i] != '\0'; ++i) {
        while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == '\0')){
            for (j = i; line[j] != '\0'; ++j) {
                // if jth element of line is not an alphabet,
                // assign the value of (j+1)th element to the jth element
                line[j] = line[j + 1];
            }
            line[j] = '\0';
            }
        }
        // Converting to Lower Case
        for (int i = 0;line[i] != '\0';i++) {
            if(line[i] >= 'A' && line[i] <= 'Z') {
                line[i] = line[i] + 32;
            }
        }
        // displaying content
        cout << line << endl;
        newStr[a]=line;
        a++;
        count++;
    }
    cout << "\nTotal Count of words in a sentence:"<<count << endl;
    while((s1+rollin)<=count){
        u=0;
        for(int i=s;i<(s1+rollin);i++){
            for(int j=s;j<(s1+rollin);j++){
                //Storing the string value into temporary variable
                string temp1 = newStr[i];
                string temp2 = newStr[j];
                /*if second loop encounter same value again but j<i break the loop to
                avoid printing of duplicate value*/
                if(j<i && (temp1.compare(temp2) == 0)) {
                    break;
                }
                /*While traversing the array, if loop reached to last print the
                string with its number of count*/
                if(j==(s1+rollin-1)) {
                    // cout <<newStr[i]<<endl;
                    u=u+1;
                }
            }
        }
        cout << "\nUnique Count:"<<u << endl;
        complexity=u/rollin;
        cout << "Complexity Count:"<<complexity<< "\n\n";
        com=com+complexity;
        s++;
        s1++;
    }
    avg=com/s;
    cout<<"Total Complexity of all words\t:\t"<<com<<"\nTotal No.of Sliding Windows\t:\t"<<s<<endl;
    cout << "\nAverage Complexity of all words\t:\t"<<avg<<endl;
}