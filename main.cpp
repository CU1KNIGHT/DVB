#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
int main() {

//------------------------------------------------------------------------------------------------------
    vector<string> TicketID(10);
    vector<string> Bezeichnung(10);
    vector<string> Zonen(10);
    vector<string> Preis(10);


    ifstream DVB_T("dvb_ticket.csv");

    if (!DVB_T.is_open()) std::cout << "ERROR: File Open" << '\n';



    while (DVB_T.good()) {


        for (int k = 0; k < 10; k++) {

            getline(DVB_T, TicketID[k], ';');
            getline(DVB_T, Bezeichnung[k], ';');
            getline(DVB_T, Zonen[k], ';');
            getline(DVB_T, Preis[k], '\n');
/*
            cout << "TicketID: "<<TicketID[k] << '\n';
            cout << "Bezeichnung: "<< Bezeichnung[k] << '\n';
            cout << "Zonen: "<< Zonen[k] << '\n';
            cout << "Preis: "<< Preis[k] << '\n';

            cout << "-------------------" << '\n';
*/
        }

    }

    DVB_T.close();
//------------------------------------------------------------------------------------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    vector<string> Haltestelle(669);
    vector<string> kuerzel(669);

    ifstream dvb_stops_synonome("dvb_stops_sym.csv");

    if (!dvb_stops_synonome.is_open()) std::cout << "ERROR: File Open" << '\n';



    while (dvb_stops_synonome.good()) {


        for (int i = 0; i < 669; i++) {

            getline(dvb_stops_synonome, Haltestelle[i], ';');

            getline(dvb_stops_synonome, kuerzel[i], '\n');
/*
            cout << "Haltestelle: "<<Haltestelle[i] << '\n';

            cout << "kuerzel: "<< kuerzel[i] << '\n';
            cout << "-------------------" << '\n';
*/
        }

    }

    dvb_stops_synonome.close();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//**********************************************************************************
    vector<string> Nummer_vector(4374);
    vector<string> Name_mit_Ort_vector(4374);
    vector<string> Name_ohne_Ort_vector(4374);
    vector<string> Ort_vector(4374);
    vector<string> Tarifzone_1_vector(4374);
    vector<string> Tarifzone_2_vector(4374);
    vector<string> Tarifzone_3_vector(4374);
    vector<string> WGS84_X_vector(4374);
    vector<string> WGS84_Y_vector(4374);



    //+++++++++++++++++++++++++++++   [  DVB stops   ]    ++++++++++++++++++++++
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    ifstream dvb_stops_infos("dvb_stops.csv");

    if (!dvb_stops_infos.is_open()) std::cout << "ERROR: File Open" << '\n';



    while (dvb_stops_infos.good()) {
        for (int j = 0; j < 4374; j++) {

            getline(dvb_stops_infos, Nummer_vector[j], ';');
            getline(dvb_stops_infos, Name_mit_Ort_vector[j], ';');
            getline(dvb_stops_infos, Name_ohne_Ort_vector[j], ';');
            getline(dvb_stops_infos, Ort_vector[j], ';');
            getline(dvb_stops_infos, Tarifzone_1_vector[j], ';');
            getline(dvb_stops_infos, Tarifzone_2_vector[j], ';');
            getline(dvb_stops_infos, Tarifzone_3_vector[j], ';');
            getline(dvb_stops_infos, WGS84_X_vector[j], ';');
            getline(dvb_stops_infos, WGS84_Y_vector[j], '\n');
/*
            cout << "Nummer_vector: "<<Nummer_vector[j] << '\n';
            cout << "Name_mit_Ort_vector: "<< Name_mit_Ort_vector[j] << '\n';
            cout << "Name_ohne_Ort_vector: "<< Name_ohne_Ort_vector[j] << '\n';
            cout << "Ort_vector: "<< Ort_vector[j] << '\n';
            cout << "Tarifzone_1_vector: "<< Tarifzone_1_vector[j] << '\n';
            cout << "Tarifzone_2_vector: "<< Tarifzone_2_vector[j] << '\n';
            cout << "Tarifzone_3_vector: "<< Tarifzone_3_vector[j] << '\n';
            cout << "WGS84_X_vector: "<< WGS84_X_vector[j] << '\n';
            cout << "WGS84_Y_vector: "<< WGS84_Y_vector[j] << '\n';

            std::cout << "-------------------" << '\n';
*/

        }
        dvb_stops_infos.close();
        return 0;
    }

//***************************************************************************************************
//5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555

    cout << "wähle deinen Modus aus [ Auskunft/ Ticket]" << endl;




}