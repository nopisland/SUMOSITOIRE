
#define remote 2

/*#define TOUT_DROIT 1
#define MARCHE_ARRIERE 2
#define DROITE 3
#define GAUCHE 4
#define STOP 5
*/

//sharp
#define pin1 A5  //sharp arrier
#define pin2 A4 //sharp gauche
#define pin3 A7 //sharp droite
int sueil_infra_arierre = 5;
int sueil_infra_droite = 30;
int sueil_infra_gauche = 30;
#define SHAR 16
#define SHG 32
#define SHD 64

//Ligne var
int input_ligne_ar = A2;
#define AR 1

int input_ligne_av_G = A1;
#define AVG 2

int input_ligne_av_D = A0;
#define AVD 4

double value1, distance1, value2, distance2, value3, distance3;
int valeur_arl, valeur_avg, valeur_avd;

//US var
int trig = 13;
int echo = 12;
long lecture_echo;
long cm;
int sueil_ultrason = 50; // meusure en cm
#define US 8


// Motors
const byte moteur_gauche[] = {8, 7}; //Bin2_-_Bin1
const byte moteur_droite[] = {6, 5}; //Ain2_-_Ain1
enum { TOUT_DROIT = 1, MARCHE_ARRIERE, GAUCHE, DROITE, STOP};

//led
const byte led_g = 11, led_b = 9;
//button
const byte button = 3;

byte arret = 0;
