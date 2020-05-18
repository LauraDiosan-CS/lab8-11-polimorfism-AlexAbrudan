// OOP_makes_me_cry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "User.h"
#include "Train.h"
#include "FreightTrain.h"
#include "PersonalTrain.h"

#include "RepoFileTrainCSV.h"
#include "RepoFileTrainTXT.h"

#include "RepoFileUserCSV.h"
#include "RepoFileUserTXT.h"

#include "Service.h"

#include "UI.h"

#include "Exception.h"

#include "tests.h"

using namespace std;

int main()
{
    //live_tests();
    //all_tests();
    //test_train_validator();
    char op = ' ';

    string t_csv = "trains.csv";
    string t_txt = "trains.txt";

    string u_csv = "users.csv";
    string u_txt = "users.txt";
    
    while (true)
    {
        cout << "1. Use csv files. " << endl;
        cout << "2. Use txt files. " << endl;
        cout << "x. Exit. " << endl;
        cout << "Enter option: ";
        cin >> op;
        switch (op)
        {
            case '1':
            {
                RepoTrain* repo_trains = new RepoFileTrainCSV(t_csv);
                RepoUser* repo_users = new RepoFileUserCSV(u_csv);

                Service s(repo_trains, repo_users);

                UI u(s);
                system("CLS");
                u.log_or_reg();
                break;
            }
            case '2':
            {
                RepoTrain* repo_trains = new RepoFileTrainTXT(t_txt);
                RepoUser* repo_users = new RepoFileUserTXT(u_txt);

                Service s(repo_trains, repo_users);

                UI u(s);
                system("CLS");
                u.log_or_reg();
                break;
            }
            case 'x':
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
