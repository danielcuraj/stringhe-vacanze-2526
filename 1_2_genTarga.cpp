#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;


const string stringaBase="Vacanze2526";

char chr(int num){
    return (char)num;
}

char toUpper(char c){
    return toupper(c);
}

bool controlloVoc(char c){
    c=toUpper(c);
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return true;
    }else
        return false;

}

/*la strategia che ho usato è quella di sostituire una vocale o un numero con la consonante C,
perchè è una strategia semplice che non complica il codice*/
char forzaCons(char c){
    c=toUpper(c);
    if(!(c >= 'A' && c <= 'Z') || controlloVoc(c)){
      c = 'C';
    }
    return c;
}

void append(string &s, char c){
    s.append(1, c);
}

char randomNum(){
    int n =rand()% 9 + 1;
    return chr(n + 48);
}

char randomLettera(){
    int a=rand()% 26 + 65;
    return chr(a);
}

string generaTarga(){

    string targa = "";
    char x = forzaCons(stringaBase[3]);
    append(targa, x);
    char y = forzaCons(randomLettera());
    append(targa, y);
    append(targa, randomNum());
    append(targa, randomNum());
    append(targa, randomNum());
    append(targa, toUpper(randomLettera()));
    append(targa, toUpper(randomLettera()));

    return targa;
}


//Sostituisce i numeri con 'X'
string sostituisciX(string targa){
    string nuova=targa;
    for (int i = 0; i < nuova.length(); i++){
        if (nuova[i]>='0' && nuova[i]<='9'){
            nuova[i]='X';
        }
    }
    return nuova;
}
//Inverte la targa utilizzando at()
string invertiTarga(string targa){
    string invertita= "";

    for(int i=targa.length() - 1; i >= 0; i--){
        invertita.append(1, targa.at(i));
    }
    return invertita;
}

//Verifica se un numero è presente utilizzando find()
bool cercaNumero(string targa, int numero){
    char c = char(numero + '0'); 

    if (targa.find(c)<targa.length()){
        return true;
    }
    return false;
}


void menu(string targa) {
    int scelta;
    int numero;
    do {
        cout<<"Menu:"<<endl;
        cout<<"1 Sostituisci numeri con X"<<endl;
        cout<<"2 Inverti targa"<<endl;
        cout<<"3 Cerca numero"<<endl;
        cout<<"0 Esci"<<endl;
        cout<<"Scelta: ";
        cin>>scelta;

        switch (scelta) {
            case 1:
                cout<<sostituisciX(targa)<<endl;
                break;
            case 2:
                cout<<invertiTarga(targa)<<endl;
                break;
            case 3:
                cout<<"Inserisci numero (1-9): ";
                cin>>numero;
                if(cercaNumero(targa, numero))
                    cout<< "Numero trovato"<<endl;
                else
                    cout<<"Numero non trovato"<<endl;
                break;
            case 0:
                cout<<"Uscito"<<endl;
                break;

            default:
                cout << "Scelta non valida"<<endl;
        }
    }while(scelta!=0);
}

int main(){
    srand(time(NULL));
    string targa=generaTarga();
    cout<<"Targa generata: "<<targa<<endl;
    menu(targa);

    return 0;
}
