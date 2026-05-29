#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;
using namespace std;

int command();
json we; // This is for the weight    
json wat; // This is for the water 
json st; // This is for the steps
int main() {
    json cf = {
    {"verify", 0}
};

    ifstream Conf("conf.json");
    if (Conf.is_open()) {
        try {
            Conf >> cf;

        } catch(...) {
            cf = {{"verify", 0}};
        }
        Conf.close();
    }

    int verif = cf.value("verify", 0);

    if (verif==0) {
        //Tutorial 
        cout << "Hello! Welcome to OpenFitness (Beta)\n" << "OpenFitness is foss (free and open source) fitness application!\n";
        cout << "For your convenience, did you use this app before?\n" << "If yes, you are free to skip this tutorial.\n" << "Y - yes, N - no\n";
        char yn;
        cin >> yn;
        if (yn=='Y') {
            command();
        } else if (yn=='N') {
            cout << "Hello! Since this app is currently in BETA,\n" << "it sadly only supports water tracking, weight tracking and steps tracker.\n" << "So welcome! :)\n";
            verif = 1;
            cf["verify"]=verif;
            ofstream conf("conf.json");
            conf << cf.dump(4);
            conf.close();
            //call command function here
            command();
        }
     } else {
        command();
        //cout << "nice :)";
     }
    return 0;
}

int command() {
    json we = json::object();

    ifstream infile("weight.json");
    if (infile.is_open()) {
        try {
            infile >> we;
        } catch (...) {
            we = json::object();
        }
        infile.close();
    }
    json wat = json::object();

    ifstream WaterIn("water.json");
    if (WaterIn.is_open()) {
        try {
            WaterIn >> wat;
        } catch (...) {
            wat = json::object();
        }
        WaterIn.close();
    }

    json steps = json::object();

    ifstream StepsIn("steps.json");
    if (StepsIn.is_open()) {
        try {
            StepsIn >> st;
        } catch (...) {
            st = json::object();
        }
        StepsIn.close();
    }
    cout << "What do you want to do?\n" << "1. Input weight.\n2. Input water.\n3. Input steps.\n" ;
    int ot;
    cin >> ot;
    if (ot==1) {
        cout << "Please input the weight (kg): ";
        float w;
        cin >> w;
        cout << "Please enter the date (DD-MM-YYYY): ";
        string date;
        cin >> date;
        we[date]["Date"]=date;
        we[date]["weight"]=w;
        ofstream outfile("weight.json");
        outfile << we.dump(4);
        outfile.close();
        command();
    } else if (ot==2) {
        cout << "Please input the amount you drank (ml): ";
        float wa;
        cin >> wa;
        cout << "Please enter the date (DD-MM-YYYY): ";
        string time;
        cin >> time;
        wat[time]["Date"]=time;
        wat[time]["Water (ml)"]=wa;
        ofstream file("water.json");
        file << wat.dump(4);
        file.close();
        command();
    } else if (ot==3) {
        cout << "Please input the amount of steps you did (the specific day, NO comma or seperator): ";
        int steps;
        cin >> steps;
        cout << "Please enter the date (DD-MM-YYYY): ";
        string date;
        cin >> date;
        st[date]["Date"]=date;
        st[date]["Steps"]=steps;
        ofstream sfile("steps.json");
        sfile << st.dump(4);
        sfile.close();
        command();
    }
    return 0;
}

/*Program is under the licence of GNU General Public License V3
This text MUST NOT be removed.*/
