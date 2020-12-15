// BruteForce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cpr/cpr.h>
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_set>
using namespace std;


int main() {
   
    string WebAppURL , loc , SucCode;
    unordered_set<long> codes;

        // Get Web App URL from user (can be multiple, separated by space)
        cout << "URLs (separated by space):";
        getline(std::cin, WebAppURL);

        /*cout << "\nFile location: ";
        getline(std::cin, loc);*/

        // Get Success Status Codes from user (space separated) 
        cout << "\nEnter Success Status Codes(Space Seperated): ";
        getline(std::cin, SucCode);

        // Add status codes to a set
        stringstream ss;
        ss << SucCode;
        string temp;
        long found;

        while (!ss.eof()) {
            ss >> temp;

            if (stringstream(temp) >> found)
                codes.insert(found);
            temp = "";
        }
       
        // Tokenize URLs to perform bruteforce using stringstream
        stringstream UrlStream;
        UrlStream << WebAppURL;
        string tempURL;

        while (!UrlStream.eof()) {

            //Extracting a single URL at a time
            UrlStream >> tempURL;

            //Open wordlist.txt for bruteforcing
            ifstream file("wordlist.txt");
            if (!file)
                cout << "\nCan't open input file, check input filename (should be 'wordlist.txt' ) \nor check location of file (must be local)\n\n\n";
            else {
                
                string str;

                while (std::getline(file, str)) {

                    //Get response from Modified URL
                    cpr::Response head_response = cpr::Head(cpr::Url{ tempURL + "/" + str });

                    //Get response Status Code from Modified URL
                    long ResStatCode = head_response.status_code;

                    //Print if Response code is of success category according to user
                    if (codes.find(ResStatCode) != codes.end())
                        cout << tempURL + "/" + str << " [STATUS CODE " << ResStatCode << "]" << endl;

                }

                //Close input fil estream
                file.close();
            }
            
        }
        cout << "Press Enter to Continue...";
        cin.get();
        return 0;
 
}

