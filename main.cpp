#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::                                                                         :*/
/*::  This routine calculates the distance between two points (given the     :*/
/*::  latitude/longitude of those points). It is being used to calculate     :*/
/*::  the distance between two locations using GeoDataSource(TM) products.   :*/
/*::                                                                         :*/
/*::  Definitions:                                                           :*/
/*::    South latitudes are negative, east longitudes are positive           :*/
/*::                                                                         :*/
/*::  Passed to function:                                                    :*/
/*::    lat1, lon1 = Latitude and Longitude of point 1 (in decimal degrees)  :*/
/*::    lat2, lon2 = Latitude and Longitude of point 2 (in decimal degrees)  :*/
/*::    unit = the unit you desire for results                               :*/
/*::           where: 'M' is statute miles (default)                         :*/
/*::                  'K' is kilometers                                      :*/
/*::                  'N' is nautical miles                                  :*/
/*::  Worldwide cities and other features databases with latitude longitude  :*/
/*::  are available at https://www.geodatasource.com                         :*/
/*::                                                                         :*/
/*::  For enquiries, please contact sales@geodatasource.com                  :*/
/*::                                                                         :*/
/*::  Official Web site: https://www.geodatasource.com                       :*/
/*::                                                                         :*/
/*::           GeoDataSource.com (C) All Rights Reserved 2018                :*/
/*::                                                                         :*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#define pi 3.14159265358979323846

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function prototypes                                           :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double);

double rad2deg(double);

double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2)) {
        return 0;
    } else {
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        dist = acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        switch (unit) {
            case 'M':
                break;
            case 'K':
                dist = dist * 1.609344;
                break;
            case 'N':
                dist = dist * 0.8684;
                break;
            default:
                dist = dist * 1.609344;
                break;
        }
        return (dist);
    }
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts decimal degrees to radians             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double deg) {
    return (deg * pi / 180);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts radians to decimal degrees             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

using namespace std;

class My_punct : public std::numpunct<char> {
protected:
    char do_decimal_point() const { return ','; }//comma
};


int main() {
    int zone;
    int count_s_punkt_sym;
    int count_s_punkt;
    int count_z_punkt;
    int count_z_punkt_sym;
    int j = count_s_punkt;
    string inputModus,Name_der_Haltstelle;
    string I_found_startpunkt_in_dvb_stops_synonome;
    string found_startpunkt, found_zielpunkt, Zielpunkt_Tarifzone, startpunkt_Tarifzone;
    double startpunkt_WGS84_X, startpunkt_WGS84_Y, zielpunkt_WGS84_Y, zielpunkt_WGS84_X;
    string input_Auswahl, Ticket_output;
    string z_tz_1, z_tz_2, z_tz_3;
    string s_tz_1, s_tz_2, s_tz_3, Ticket_output_no_zone;
    cout << "     _       _\n"
            "    | |     | |\n"
            "  __| |_   _| |__\n"
            " / _` \\ \\ / / '_ \\\n"
            "| (_| |\\ V /| |_) |\n"
            " \\__,_| \\_/ |_.__/" << endl;
    cout << endl;
    cout << "[Catch my Ticket]" << endl;
    cout << endl;
    cout << "wähle deinen Modus aus [Auskunft / Ticket]" << endl;
    cout << endl;
    std::getline (std::cin,inputModus);
    cout << endl;
    if (inputModus == "Auskunft" || inputModus == "auskunft") {
        cout << "  Auskunft" << endl;
        cout << endl;
        cout << " ------------------------------" << endl;
        cout << endl;

        cout << " Geben Sie die Haltstelle ein!" << endl;
        cout << endl;
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




            if (Name_der_Haltstelle == Haltestelle[i] || kuerzel[i].find(Name_der_Haltstelle) != std::string::npos) {
                cout << "-------------------" << endl;
                cout << "Name der Haltestelle (ohne Ort) : " << Haltestelle[i] << '\n';
                cout << "Kuerzel  :" << "   " << kuerzel[i] << endl;




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

    else if (inputModus == "Ticket" || inputModus == "ticket") {
        string Startpunkt,Zielpunkt, Ticket_input;
        cout << "  Ticket" << endl;
        cout << endl;
        cout<< " ------------------------------" <<endl;
        cout << endl;
        cout<< " Was ist dein Startpunkt : " <<endl;

        std::getline (std::cin,Startpunkt);
        cout << endl;
        cout << " Was ist dein Zielpunkt : " << endl;
        std::getline(std::cin, Zielpunkt);
        cout << endl;
        cout << " Welches Ticket möchtest du? [ Einzel / Tag / Woche / Monat ]  " << endl;
        std::getline(std::cin, Ticket_input);
        cout << endl;

        vector<string> Nummer_vector(4374);
        vector<string> Name_mit_Ort_vector(4374);
        vector<string> Name_ohne_Ort_vector(4374);
        vector<string> Ort_vector(4374);
        vector<string> Tarifzone_1_vector(4374);
        vector<string> Tarifzone_2_vector(4374);
        vector<string> Tarifzone_3_vector(4374);
        vector<string> WGS84_X_vector(4374);
        vector<string> WGS84_Y_vector(4374);

        vector<string> Haltestelle(670);
        vector<string> kuerzel(670);

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


        for (int z = 1; z <
                        670; z++) {//search in dvb_stops_sym    for the [ startpunkt]
            count_s_punkt_sym = z;


            getline(dvb_stops_synonome, Haltestelle[count_s_punkt_sym], ';');
            getline(dvb_stops_synonome, kuerzel[count_s_punkt_sym], '\n');







            if (Zielpunkt == Haltestelle[z] || kuerzel[z].find(Zielpunkt) !=
                                               std::string::npos) {


                found_zielpunkt = Haltestelle[z];


            } else if (Startpunkt == Haltestelle[z] || kuerzel[z].find(Startpunkt) !=
                                                       std::string::npos) {

                found_startpunkt = Haltestelle[z];





            }


            }


        for (j = 1; j <= 4373; ++j) {
            getline(dvb_stops_infos, Nummer_vector[j], ';');
            getline(dvb_stops_infos, Name_mit_Ort_vector[j], ';');
            getline(dvb_stops_infos, Name_ohne_Ort_vector[j], ';');
            getline(dvb_stops_infos, Ort_vector[j], ';');
            getline(dvb_stops_infos, Tarifzone_1_vector[j], ';');
            getline(dvb_stops_infos, Tarifzone_2_vector[j], ';');
            getline(dvb_stops_infos, Tarifzone_3_vector[j], ';');
            getline(dvb_stops_infos, WGS84_X_vector[j], ';');
            getline(dvb_stops_infos, WGS84_Y_vector[j], '\n');





            if ((found_startpunkt == Name_ohne_Ort_vector[j]) &&
                Ort_vector[j] == "Dresden") { // found the same dvb stop  +++++++++ found the right one ==========
                count_s_punkt = j;
                startpunkt_Tarifzone = Tarifzone_1_vector[j] + Tarifzone_2_vector[j] + Tarifzone_3_vector[j];
                s_tz_1 = Tarifzone_1_vector[j];
                s_tz_2 = Tarifzone_2_vector[j];
                s_tz_3 = Tarifzone_3_vector[j];



                stringstream ee(WGS84_X_vector[j]);
                locale loc(locale(), new My_punct);
                ee.imbue(loc);
                double v;
                ee >> v;

                startpunkt_WGS84_X = v;

                stringstream qq(WGS84_Y_vector[j]);
                locale lot(locale(), new My_punct);
                qq.imbue(lot);
                double h;
                qq >> h;
                startpunkt_WGS84_Y = h;





            }
            if ((found_zielpunkt == Name_ohne_Ort_vector[j]) &&
                Ort_vector[j] == "Dresden") { // found the same dvb stop  +++++++++ found the right one ==========
                count_z_punkt = j;

                Zielpunkt_Tarifzone = Tarifzone_1_vector[j] + Tarifzone_2_vector[j] + Tarifzone_3_vector[j];
                z_tz_1 = Tarifzone_1_vector[j];
                z_tz_2 = Tarifzone_2_vector[j];
                z_tz_3 = Tarifzone_3_vector[j];



                stringstream ss(WGS84_X_vector[j]);
                locale loc(locale(), new My_punct);
                ss.imbue(loc);
                double d;
                ss >> d;
                zielpunkt_WGS84_X = d;

                stringstream mm(WGS84_Y_vector[j]);
                locale lov(locale(), new My_punct);
                mm.imbue(lov);
                double n;
                mm >> n;
                zielpunkt_WGS84_Y = n;


            }


        }


        if (!(s_tz_1.empty() && z_tz_1.empty()) or !(s_tz_2.empty() && z_tz_2.empty()) or
            !(s_tz_3.empty() && z_tz_3.empty())) {
            zone = 1;


        } else if (!(s_tz_1.empty() && z_tz_2.empty()) or !(s_tz_2.empty() && z_tz_1.empty()) or
                   !(s_tz_2.empty() && z_tz_3.empty()) || !(s_tz_3.empty() && z_tz_2.empty())) {
            zone = 2;


        } else if (!(s_tz_1.empty() && z_tz_3.empty()) or !(s_tz_3.empty() && z_tz_1.empty())) {
            zone = 3;

        }

        if (!DVB_T.is_open()) std::cout << "ERROR: File Open" << '\n';


        while (DVB_T.good()) {

            for (int k = 0; k < 10; k++) {

                getline(DVB_T, TicketID[k], ';');
                getline(DVB_T, Bezeichnung[k], ';');
                getline(DVB_T, Zonen[k], ';');
                getline(DVB_T, Preis[k], '\n');


                if (Ticket_input == "Tag" && Bezeichnung[k].find(Ticket_input) != std::string::npos) {
                    if (((!s_tz_1.empty() && !z_tz_1.empty()) || (s_tz_2.empty() && z_tz_2.empty()) == 0 ||
                         !(s_tz_3.empty() && z_tz_3.empty()) == 0)) {

                        if (zone == 1) {


                            Ticket_output = Preis[5];



                        }
                        if (zone == 2) {


                            Ticket_output = Preis[6];






                        }
                    }
                }
                if (Ticket_input == "Woche" && Bezeichnung[k].find(Ticket_input) != std::string::npos) {
                    if (TicketID[k].find("Woche") != std::string::npos) {


                        Ticket_output = Preis[k];


                    }
                }
                if (Ticket_input == "Monat") {
                    if (TicketID[k].find("Monat") != std::string::npos) {


                        Ticket_output = Preis[k];


                    }
                }
                if (Ticket_input == "Einzel" && Bezeichnung[k].find(Ticket_input) !=
                                                std::string::npos) {//+++++++++++++++++++++++++++++++++++++++++++Einzel



                    if (!(Zonen[k].empty())) {


                        if (zone == 1) {

                            Ticket_output = Preis[1];
                        }


                        if (zone == 2) {


                            Ticket_output = Preis[2];

                        } else if (zone == 3) {


                            Ticket_output = Preis[3];
                        }

                    }


                }
            }


        }
        dvb_stops_infos.close();
        dvb_stops_synonome.close();
        DVB_T.close();


    }
    cout << endl;

    cout << "---------------------------------------------------------------++++++++++++++++++++++++++++++++++" << endl;


    cout << "    " << found_startpunkt << "    -------->" << "    " << found_zielpunkt << endl;
    cout << "---------------------------------------------------------------" << endl;


    cout << endl;
    cout << "Tarif zone  " << zone << endl;
    cout << endl;
    cout << Ticket_output << endl;
    cout << "(Erwachsener)";
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "Das entspricht einen Weg von "
         << distance(startpunkt_WGS84_X, startpunkt_WGS84_Y, zielpunkt_WGS84_X, zielpunkt_WGS84_Y, 'K') << " km"
         << endl;
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "Auskunft :" << endl;
    cout << "google.de/maps/dir/" << found_startpunkt << "/" << found_zielpunkt << endl;
    cout << endl;


    cout << "---------------------------------------------------------------++++++++++++++++++++++++++++++++++" << endl;


    main();
}
