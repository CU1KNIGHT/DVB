#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>

using namespace std;
int main() {
    int count_s_punkt_sym;
    int count_s_punkt;
    int count_z_punkt;
    int count_z_punkt_sym;
    int j = count_s_punkt;
    string inputModus,Name_der_Haltstelle;
    string I_found_startpunkt_in_dvb_stops_synonome;
    string found_startpunkt, found_zielpunkt, Zielpunkt_Tarifzone, startpunkt_Tarifzone, startpunkt_WGS84_X, startpunkt_WGS84_Y, zielpunkt_WGS84_Y, zielpunkt_WGS84_X;
    string input_Auswahl;

    cout << "wähle deinen Modus aus [ Auskunft/ Ticket]" << endl;
    std::getline (std::cin,inputModus);
    if(inputModus== "Auskunft" ||  inputModus== "auskunft"){
       cout<< " modus ist:  Auskunft" <<endl;
        cout<< " Geben Sie die Haltstelle ein!" <<endl;
        std::getline (std::cin,Name_der_Haltstelle);



        vector<string> Nummer_vector(4374);
        vector<string> Name_mit_Ort_vector(4374);
        vector<string> Name_ohne_Ort_vector(4374);
        vector<string> Ort_vector(4374);
        vector<string> Tarifzone_1_vector(4374);
        vector<string> Tarifzone_2_vector(4374);
        vector<string> Tarifzone_3_vector(4374);
        vector<string> WGS84_X_vector(4374);
        vector<string> WGS84_Y_vector(4374);

        vector<string> Haltestelle(669);
        vector<string> kuerzel(669);

        ifstream dvb_stops_synonome("dvb_stops_sym.csv");
        ifstream dvb_stops_infos("dvb_stops.csv");


        dvb_stops_infos.is_open();
        dvb_stops_synonome.is_open();
        for (int i = 1; i <= Haltestelle.size(); i++) {
            getline(dvb_stops_synonome, Haltestelle[i], ';');
            getline(dvb_stops_synonome, kuerzel[i]);

/*
                cout<<"--------------------------------"<<endl;
                cout<<"Name_der_Haltstelle   "<<Name_der_Haltstelle<<endl;
                cout<<"Haltestelle   "<<Haltestelle[i]<<endl;
                cout<<"    Kuerzel " <<kuerzel[i]<<endl;


                cout<<"    kuerzel[i].data()" <<kuerzel[i].data()<<endl;

                cout<< "count  " << i<<endl;
                */


            if (Name_der_Haltstelle == Haltestelle[i] || kuerzel[i].find(Name_der_Haltstelle) != std::string::npos) {
                cout << "-------------------" << endl;
                cout << "Name der Haltestelle (ohne Ort) : " << Haltestelle[i] << '\n';
                cout << "Kuerzel  :" << "   " << kuerzel[i] << endl;
                // cout<< "count  " << i<<endl;



                for (j = 0; Name_ohne_Ort_vector[j] != Haltestelle[i]; j++) {

                    getline(dvb_stops_infos, Nummer_vector[j], ';');
                    getline(dvb_stops_infos, Name_mit_Ort_vector[j], ';');
                    getline(dvb_stops_infos, Name_ohne_Ort_vector[j], ';');
                    getline(dvb_stops_infos, Ort_vector[j], ';');
                    getline(dvb_stops_infos, Tarifzone_1_vector[j], ';');
                    getline(dvb_stops_infos, Tarifzone_2_vector[j], ';');
                    getline(dvb_stops_infos, Tarifzone_3_vector[j], ';');
                    getline(dvb_stops_infos, WGS84_X_vector[j], ';');
                    getline(dvb_stops_infos, WGS84_Y_vector[j], '\n');

                    if (Haltestelle[i] == Name_ohne_Ort_vector[j] && Ort_vector[j] == "Dresden") {
                        cout << "Tarifzone  : " << Tarifzone_1_vector[j] << Tarifzone_2_vector[j] <<
                             Tarifzone_3_vector[j] << endl;
                        cout << "-------------------" << endl;
                    }
                }

            }


        }







    }
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    else if(inputModus=="Ticket" || inputModus=="ticket"){
        string Startpunkt,Zielpunkt, Ticket_input;
        cout<< " modus ist:  Ticket" <<endl;
        cout<< " ------------------------------" <<endl;
        cout<< " Was ist dein Startpunkt : " <<endl;
        std::getline (std::cin,Startpunkt);

        cout << " Was ist dein Zielpunkt : " << endl;
        std::getline(std::cin, Zielpunkt);

        cout << " Welches Ticket möchtest du? [Einzel/Tag/Woche / Monat]  " << endl;
        std::getline(std::cin, Ticket_input);


        vector<string> Nummer_vector(4374);
        vector<string> Name_mit_Ort_vector(4374);
        vector<string> Name_ohne_Ort_vector(4374);
        vector<string> Ort_vector(4374);
        vector<string> Tarifzone_1_vector(4374);
        vector<string> Tarifzone_2_vector(4374);
        vector<string> Tarifzone_3_vector(4374);
        vector<string> WGS84_X_vector(4374);
        vector<string> WGS84_Y_vector(4374);

        vector<string> Haltestelle(669);
        vector<string> kuerzel(669);

        vector<string> TicketID(10);
        vector<string> Bezeichnung(10);
        vector<string> Zonen(10);
        vector<string> Preis(10);

        ifstream dvb_stops_synonome("dvb_stops_sym.csv");
        ifstream dvb_stops_infos("dvb_stops.csv");
        ifstream DVB_T("dvb_ticket.csv");


        dvb_stops_infos.is_open();
        dvb_stops_synonome.is_open();
        DVB_T.is_open();


        for (int z = 1; z <=
                        668/*(Startpunkt != kuerzel[z] || kuerzel[count_s_punkt_sym].find(Startpunkt) == std::string::npos)*/; ++z) {//search in dvb_stops_sym    for the [ startpunkt]
            count_s_punkt_sym = z;


            getline(dvb_stops_synonome, Haltestelle[count_s_punkt_sym], ';');
            getline(dvb_stops_synonome, kuerzel[count_s_punkt_sym], '\n');

            /*
            cout<<"--------------------------------"<<endl;
            cout<<"Name_der_Haltstelle   "<<Name_der_Haltstelle<<endl;
            cout<<"Haltestelle   "<<Haltestelle[z]<<endl;
            cout<<"    Kuerzel " <<kuerzel[z]<<endl;
            cout<<"    count_s_punkt_sym " <<count_s_punkt_sym<<endl;


            cout<<"    kuerzel[i].data()" <<kuerzel[z].data()<<endl;

            cout<< "count  " << z<<endl;
             */




            //cout << " look for 'ZOO' in dvb_stops_synonome  the line now is:   " << count_s_punkt_sym<< "   Haltestelle[count_s_punkt_sym]" << Haltestelle[count_s_punkt_sym] <<  "   kuerzel[count_s_punkt_sym]   " << kuerzel[count_s_punkt_sym] <<endl;

            if (Zielpunkt == Haltestelle[z] || kuerzel[z].find(Zielpunkt) !=
                                               std::string::npos) { // check if the input is same in data base ++dvb_stops_sym
                // cout << " I found 'startpunkt' in  dvb_stops_synonome and the number is :   " << count_s_punkt_sym << endl;
                I_found_startpunkt_in_dvb_stops_synonome = Haltestelle[count_s_punkt_sym];
                cout << "Haltestelle[z] " << Haltestelle[z] << endl;
                cout << "-------------------------------------------" << endl;

                found_zielpunkt = Haltestelle[z];


            } else if (Startpunkt == Haltestelle[z] || kuerzel[z].find(Startpunkt) !=
                                                       std::string::npos) { // check if the input is same in data base ++dvb_stops_sym
                // cout << " I found 'startpunkt' in  dvb_stops_synonome and the number is :   " << count_s_punkt_sym << endl;
                I_found_startpunkt_in_dvb_stops_synonome = Haltestelle[z];
                cout << "Haltestelle[z] " << Haltestelle[z] << endl;
                cout << "-------------------------------------------" << endl;
                found_startpunkt = Haltestelle[z];

                //cout << "found_startpunkt " << found_startpunkt << endl;
                // cout << "found_zielpunkt " << found_zielpunkt << endl;

/*
                for (j = 1; j <((Haltestelle[count_s_punkt_sym] != Name_ohne_Ort_vector[j]) && (Ort_vector[j] != "Dresden"))*//*; ++j) { // search in the secound data base [ dvb_stops  ] a from a == b
                    count_s_punkt = j;

                        getline(dvb_stops_infos, Nummer_vector[j], ';');
                        getline(dvb_stops_infos, Name_mit_Ort_vector[j], ';');
                        getline(dvb_stops_infos, Name_ohne_Ort_vector[j], ';');
                        getline(dvb_stops_infos, Ort_vector[j], ';');
                        getline(dvb_stops_infos, Tarifzone_1_vector[j], ';');
                        getline(dvb_stops_infos, Tarifzone_2_vector[j], ';');
                        getline(dvb_stops_infos, Tarifzone_3_vector[j], ';');
                        getline(dvb_stops_infos, WGS84_X_vector[j], ';');
                        getline(dvb_stops_infos, WGS84_Y_vector[j], '\n');




                    cout << "-----------------------------------------------------------" <<  endl;
                    cout << "look for 'Zoo' in the   dvb_stops  and  the line now is :   " << count_s_punkt << endl;
                    cout << "Haltestelle[count_s_punkt_sym] :   " << Haltestelle[count_s_punkt_sym] << endl;
                    cout << "Name_ohne_Ort_vector[j] :   " << Name_ohne_Ort_vector[j] << endl;
                    cout << "-----------------------------------------------------------" <<  endl;




                    if ((Haltestelle[count_s_punkt_sym] == Name_ohne_Ort_vector[count_s_punkt]) && Ort_vector[j] ==
                                                                                                   "Dresden") { // found the same dvb stop  +++++++++ found the right one ==========

                        cout
                                << "-------------------------++++++++++++++++++++++++++++++++++++++++----------------------------------"
                                << endl;

                        cout << " +++++++++++++++++++++  I found 'startpunkt' in  kuerzel[count_s_punkt_sym]    "
                             << I_found_startpunkt_in_dvb_stops_synonome << "     ++++++++++++++++++++++++++++++++"
                             << endl;


                        cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "
                             << count_s_punkt << "     ++++++++++++++++++++++++++++++++" << endl;
                        cout << " +++++++++++++++++++++  I found Name_ohne_Ort_vector[count_s_punkt] :   "
                             << Name_ohne_Ort_vector[count_s_punkt] << "     ++++++++++++++++++++++++++++++++" << endl;
                        cout
                                << "-------------------------+++++++++++++++++++++++++++++++++++++++++----------------------------------"
                                << endl;


                    }


                    }*/


            }
            //cout << "z " << z << endl;


            }


        cout << "found_startpunkt  " << found_startpunkt << endl;
        cout << "found_zielpunkt  " << found_zielpunkt << endl;
        for (int i = 0; i < 5; i++)
            cout << i << endl;


        for (j = 1; j <= 4373; ++j) { // search in the secound data base [ dvb_stops  ] a from a == b
            //                       count_s_punkt = j;
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

        cout << "-----------------------------------------------------------" <<  endl;
        cout << "look for 'Zoo' in the   dvb_stops  and  the line now is :   " << count_s_punkt << endl;
        cout << "Haltestelle[count_s_punkt_sym] :   " << Haltestelle[count_s_punkt_sym] << endl;
        cout << "Name_ohne_Ort_vector[j] :   " << Name_ohne_Ort_vector[j] << endl;
        cout << "-----------------------------------------------------------" <<  endl;

*/


            if ((found_startpunkt == Name_ohne_Ort_vector[j]) &&
                Ort_vector[j] == "Dresden") { // found the same dvb stop  +++++++++ found the right one ==========
                count_s_punkt = j;
                startpunkt_Tarifzone = Tarifzone_1_vector[j] + Tarifzone_2_vector[j] + Tarifzone_3_vector[j];
                startpunkt_WGS84_X = WGS84_X_vector[j];
                startpunkt_WGS84_Y = WGS84_Y_vector[j];


                cout
                        << "-------------------------++++++++++++++++++++++++++++++++++++++++----------------------------------"
                        << endl;

                cout << " +++++++++++++++++++++  I found 'startpunkt' in  kuerzel[count_s_punkt_sym]    "
                     << found_startpunkt << "     ++++++++++++++++++++++++++++++++" << endl;

                cout << "startpunkt_Tarifzone " << startpunkt_Tarifzone << endl;

                cout << "startpunkt_WGS84_X " << WGS84_X_vector[j] << endl;
                cout << "startpunkt_WGS84_X " << WGS84_Y_vector[j] << endl;


                cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   " << j
                     << "     ++++++++++++++++++++++++++++++++" << endl;
                cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "
                     << count_s_punkt << "     ++++++++++++++++++++++++++++++++" << endl;
                cout << " +++++++++++++++++++++  I found Name_ohne_Ort_vector[count_s_punkt] :   "
                     << Name_ohne_Ort_vector[j] << "     ++++++++++++++++++++++++++++++++" << endl;
                cout
                        << "-------------------------+++++++++++++++++++++++++++++++++++++++++----------------------------------"
                        << endl;

            }
            if ((found_zielpunkt == Name_ohne_Ort_vector[j]) &&
                Ort_vector[j] == "Dresden") { // found the same dvb stop  +++++++++ found the right one ==========
                count_z_punkt = j;
                Zielpunkt_Tarifzone = Tarifzone_1_vector[j] + Tarifzone_2_vector[j] + Tarifzone_3_vector[j];
                zielpunkt_WGS84_X = WGS84_X_vector[j];
                zielpunkt_WGS84_Y = WGS84_Y_vector[j];


                cout
                        << "-------------------------++++++++++++++++++++++++++++++++++++++++----------------------------------"
                        << endl;


                cout << " +++++++++++++++++++++  I found 'startpunkt' in  kuerzel[count_s_punkt_sym]    "
                     << found_zielpunkt << "     ++++++++++++++++++++++++++++++++" << endl;

                cout << "zielpunkt_WGS84_X " << WGS84_X_vector[j] << endl;
                cout << "zielpunkt_WGS84_Y " << WGS84_Y_vector[j] << endl;
                cout << "Zielpunkt_Tarifzone " << Zielpunkt_Tarifzone << endl;


                cout << " +++++++++++++++++++++  I found 'Zielpunkt' in  dvb_stops and the number is :   " << j
                     << "     ++++++++++++++++++++++++++++++++" << endl;
                cout << " +++++++++++++++++++++  I found 'Zielpunkt' in  dvb_stops and the number is :   "
                     << count_z_punkt << "     ++++++++++++++++++++++++++++++++" << endl;
                cout << " +++++++++++++++++++++  I found Name_ohne_Ort_vector[count_z_punkt] :   "
                     << Name_ohne_Ort_vector[j] << "     ++++++++++++++++++++++++++++++++" << endl;
                cout
                        << "-------------------------+++++++++++++++++++++++++++++++++++++++++----------------------------------"
                        << endl;

            }


        }
        /*
        cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "   << count_z_punkt << "     ++++++++++++++++++++++++++++++++" << endl;

        cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "   << count_s_punkt << "     ++++++++++++++++++++++++++++++++" << endl;
*/
        //cout<< "I_found_startpunkt_in_dvb_stops_synonome   "<< I_found_startpunkt_in_dvb_stops_synonome<<endl;


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
                if (Bezeichnung[k].find(Ticket_input) != std::string::npos) {
                    cout << "-------------------" << '\n';
                    //cout << "Bezeichnung" << Bezeichnung[k] << "  preis" << Preis[k] << endl;
                    if (Zielpunkt_Tarifzone == startpunkt_Tarifzone && Zonen[k].find('1') != std::string::npos) {
                        cout << " same zone  Bezeichnung " << Bezeichnung[k] << "  preis " << Preis[k] << endl;

                    } else if (Zielpunkt_Tarifzone != startpunkt_Tarifzone && Zonen[k].find('2') != std::string::npos) {
                        cout << " 2 zone  Bezeichnung " << Bezeichnung[k] << "  preis " << Preis[k]
                             << endl;
                    }
                    cout << "-------------------" << '\n';
                }
                // else if(){}
                //else if(){}

            }

        }
        dvb_stops_infos.close();
        dvb_stops_synonome.close();
        DVB_T.close();

/*

        for (int k = 0; k <=669Zielpunkt!= Haltestelle[k]||  kuerzel[k].find(Zielpunkt) == std::string::npos ; ++k) { // search  for the [ Zielpunkt] ]]]]]]]]]]]]]]]]]]]]]]]]

            getline(dvb_stops_synonome, Haltestelle[k], ';');
            getline(dvb_stops_synonome, kuerzel[k], '\n');
            Haltestelle[k];
            kuerzel[k];
            count_z_punkt_sym = k;
            // cout<< " run 1"<< endl;
            cout << " look for 'Postplatz' in the   dvb_stops_synonome   and the line is  :   " << count_z_punkt_sym
                 << endl;

            if (Zielpunkt == Haltestelle[k] ||
                kuerzel[k].find(Zielpunkt) != std::string::npos) { // check  if the input is same for [ Zielpunkt]
                // cout << " run 2" << endl;
                //cout << " I found 'Postplatz' in  dvb_stops_synonome and the number is   " << count_z_punkt_sym << endl;


                for (int f = 0; f <=
                                4374Name_ohne_Ort_vector[f] != Haltestelle[k] && Ort_vector[f] != "Dresden"; ++f) { // search in the secound data base [ dvb_stops  ] a from a == b

                                        getline(dvb_stops_infos, Nummer_vector[f], ';');
                                        getline(dvb_stops_infos, Name_mit_Ort_vector[f], ';');
                                        getline(dvb_stops_infos, Name_ohne_Ort_vector[f], ';');
                                        getline(dvb_stops_infos, Ort_vector[f], ';');
                                        getline(dvb_stops_infos, Tarifzone_1_vector[f], ';');
                                        getline(dvb_stops_infos, Tarifzone_2_vector[f], ';');
                                        getline(dvb_stops_infos, Tarifzone_3_vector[f], ';');
                                        getline(dvb_stops_infos, WGS84_X_vector[f], ';');
                                        getline(dvb_stops_infos, WGS84_Y_vector[f], '\n');

                    count_z_punkt = f;
                    Name_ohne_Ort_vector[f];
                    Ort_vector[f];
                    Tarifzone_1_vector[f];
                    Tarifzone_2_vector[f];
                    Tarifzone_3_vector[f];
                    WGS84_X_vector[f];
                    WGS84_Y_vector[f];
                    // cout << " look for 'Zielpunkt' in the   dvb_stops  and  the line now is   " << count_z_punkt << endl;


                    if ((Name_ohne_Ort_vector[f] == Haltestelle[count_z_punkt_sym]) && Ort_vector[f] ==
                                                                                       "Dresden") {// found the same dvb stop  +++++++++ found the right one ===========



                        cout
                                << "-------------------------++++++++++++++++++++++++++++++++++++++++----------------------------------"
                                << endl;
                        // cout << " +++++++++++++++++++++  I found 'startpunkt' in  kuerzel[count_z_punkt_sym]    " << kuerzel[count_z_punkt_sym] << "     ++++++++++++++++++++++++++++++++" << endl;


                        cout << " +++++++++++++++++++++  I found 'ZIELpunkt' in  dvb_stops and the number is :   "
                             << count_z_punkt << endl;
                        cout << " +++++++++++++++++++++  I found Name_ohne_Ort_vector[count_s_punkt] :   "
                             << Name_ohne_Ort_vector[count_z_punkt] << endl;
                        cout
                                << "-------------------------+++++++++++++++++++++++++++++++++++++++++----------------------------------"
                                << endl;

                        cout << " I found 'Postplatz' in  dvb_stops and the number is :   " << count_z_punkt << endl;
                        std::cout << "-------------------" << '\n';
                        cout << "Start punkt : " << Haltestelle[count_s_punkt_sym] << " ----->   Ziel punkt : "
                             << Haltestelle[count_z_punkt_sym] << '\n';


                        std::cout << "-------------------" << '\n';
                        cout << "Tarifzone  : " << Tarifzone_1_vector[count_z_punkt]
                             << Tarifzone_2_vector[count_z_punkt] << Tarifzone_3_vector[count_z_punkt] << '\n';
                        std::cout << "-------------------" << '\n';
                        cout << "Tarifzone  : " << Tarifzone_1_vector[count_s_punkt]
                             << Tarifzone_2_vector[count_s_punkt] << Tarifzone_3_vector[count_s_punkt] << '\n';

                        std::cout << "-------------------" << '\n';






                        if(Ticket_input== "Einzel"){
                            for (int c = 0; c< 10; c++) {

                                getline(DVB_T, TicketID[c], ';');
                                getline(DVB_T, Bezeichnung[c], ';');
                                getline(DVB_T, Zonen[c], ';');
                                getline(DVB_T, Preis[c], '\n');

                                if(Bezeichnung[c]=="Einzelfahrt"){
                                    if( Tarifzone_1_vector[j]== Tarifzone_1_vector[f]   || Tarifzone_2_vector[j]== Tarifzone_2_vector[f] || Tarifzone_3_vector[j]== Tarifzone_3_vector[f]){
                                        cout<< "Bezeichnung"<<  Bezeichnung[c]<< "  preis" << Preis[c] << endl;
                                    }



                        //else if(){}
                        // else if(){}
                        //else if(){}



                        //cout << "TicketID: "<<TicketID[k] << '\n';
                        // cout << "Bezeichnung: "<< Bezeichnung[k] << '\n';
                        //  cout << "Zonen: "<< Zonen[k] << '\n';
                        //  cout << "Preis: "<< Preis[k] << '\n';

                        //  cout << "-------------------" << '\n';

                    }


                }

            }

        }










*/






    }
//------------------------------------------------------------------------------------------------------
/*


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

            cout << "TicketID: "<<TicketID[k] << '\n';
            cout << "Bezeichnung: "<< Bezeichnung[k] << '\n';
            cout << "Zonen: "<< Zonen[k] << '\n';
            cout << "Preis: "<< Preis[k] << '\n';

            cout << "-------------------" << '\n';

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

            cout << "Haltestelle: "<<Haltestelle[i] << '\n';

            cout << "kuerzel: "<< kuerzel[i] << '\n';
            cout << "-------------------" << '\n';

        }

    }

    dvb_stops_synonome.close();


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// **********************************************************************************
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


        }
        dvb_stops_infos.close();
        return 0;
    }
*/

/*
    cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "   << count_z_punkt << "     ++++++++++++++++++++++++++++++++" << endl;

    cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "   << found_zielpunkt << "     ++++++++++++++++++++++++++++++++" << endl;

    cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "   << count_s_punkt << "     ++++++++++++++++++++++++++++++++" << endl;
    cout << " +++++++++++++++++++++  I found 'startpunkt' in  dvb_stops and the number is :   "    << found_startpunkt<< "     ++++++++++++++++++++++++++++++++" << endl;
*/
    cout << "google.de/maps/dir/" << found_startpunkt << "/" << found_zielpunkt << endl;


    cout << " the end" << endl;


}