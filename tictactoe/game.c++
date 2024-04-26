#include <iostream>
#include <stdlib.h>
using namespace std;

char A[3][3] = {  {'1','2','3'},
        		  {'4','5','6'},
        		  {'7','8','9'} };
int X, O;
int round = 0;
int r, c, i, j;
char symbol = 'O';
bool result = false;
string name1 = "";
string name2 = "";

void Name();
void GameBoard();
int RunGame();
bool Control();
int Again();

int main() {

    Name();
    while (!Control() && round < 9)
    {
        GameBoard();
        RunGame();
       result=Control();
    }

    if (symbol == 'X' && result == true)
    {
        cout << name1 << " kazandi !" << endl;
    }
   else if (symbol == 'O' && result == true)
    {
        cout << name2 << " kazandi !" << endl;
    }
   else if(round==9 && result== false) 
    {
        cout << "Sonuc berabere."<<endl;
    }
Again();
return 0;
}
void Name(){
cout <<endl<<endl<< "TicTacToe oyunu 2 kisi ile oynanmalidir. Peki nasil oynanir? Oyunculardan biri 'X' , digeri 'O' sembolunu kullanmalidir. Oyun sonunda 3 ayni sembolu arka arkaya veya carpraz siralayan oyuncu, 3 sembolun uzerine cizik atar ve oyunu kazanir. Oyun sonunda 3 ayni sembol arka arkaya veya carpraz siralanamamis ise oyun beraberedir.\n\n\n\n";

    cout << "Birinci oyuncunun ismini giriniz: ";
    cin >> name1;
    cout << endl;
    cout << "Ikinci oyuncunun ismini giriniz: ";
    cin >> name2;
    cout << endl;
    cout << "Oyuna ilk baslayan: " << name1 <<".   Sembolunuz:'O'"<< endl;
    cout << "Oyuna ikinci baslayan: " << name2 <<".     Sembolunuz:'X'"<<endl;
}
void GameBoard() {

    cout << "     |     |" << endl;
    cout << "  " << A[0][0] << "  |  " << A[0][1] << "  |  " << A[0][2] <<  endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |" << endl;
    cout << "  " << A[1][0] << "  |  " << A[1][1] << "  |  " << A[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |" << endl;
    cout << "  " << A[2][0] << "  |  " << A[2][1] << "  |  " << A[2][2] << endl;
    cout << "     |     |" << endl;
}
int RunGame() {

    int space;

    if (symbol == 'O') {
        cout << name1 << " sira sizde. Sembol:'O'"<<endl;
        cout<<"Secim: ";
    }
    else {
        cout << name2 << " sira sizde. Sembol'X'"<<endl;
        cout<<"Secim: ";
    }
    cin >> space;

    if (space < 1 || space > 9) {
        cout << "Lutfen tabloda gordugunuz rakamlardan baska sayilar girmeyiniz!\a";
        RunGame();
    }

    int r, c;

    switch (space) {
    case 1:
        r = 0;
        c = 0;
        break;
    case 2:
        r = 0;
        c = 1;
        break;
    case 3:
        r = 0;
        c = 2;
        break;
    case 4:
        r = 1;
        c = 0;
        break;
    case 5:
        r = 1;
        c = 1;
        break;
    case 6:
        r = 1;
        c = 2;
        break;
    case 7:
        r = 2;
        c = 0;
        break;
    case 8:
        r = 2;
        c = 1;
        break;
    case 9:
        r = 2;
        c = 2;
        break;
    }
    if (symbol == 'X' && A[r][c] != 'X' && A[r][c] != 'O') {
        A[r][c] = 'X';
        symbol = 'O';
        round++;
        system("cls");

    }
    else if (symbol == 'O' && A[r][c] != 'X' && A[r][c] != 'O') {

        A[r][c] = 'O';
        symbol = 'X';
        round++;
        system("cls");
    }
    else if (A[r][c] == 'X' || A[r][c] == 'O') {
        cout << "Bu bosluk dolu. Lutfen baska bir bosluga yerlestirin.\n";
        RunGame();
    }
}
bool Control() {

    if (A[0][0] == A[1][1] && A[0][0] == A[2][2] && A[0][0]!=' ')
        return true;
   
    if (A[2][0] == A[1][1] && A[2][0] == A[0][2] && A[2][0] != ' ')
        return true;

    if (A[0][0] == A[1][0] && A[0][0] == A[2][0] && A[0][0] != ' ')
        return true;

    if (A[0][1] == A[1][1] && A[0][1] == A[2][1] && A[0][1] != ' ')
        return true;

    if (A[0][2] == A[1][2] && A[0][2] == A[2][2] && A[0][2] != ' ')
        return true;

    if (A[0][0] == A[0][1] && A[0][0] == A[0][2] && A[0][0] != ' ')
        return true;

    if (A[1][0] == A[1][1] && A[1][0] == A[1][2] && A[1][0] != ' ')
        return true;

    if (A[2][0] == A[2][1] && A[2][0] == A[2][2] && A[2][0] != ' ')
        return true;

return false;
}
int Again(){
    int answer;
    cout<<"Oyun sona erdi, tekrar oynamak ister misiniz? Cevabiniz evet ise 1'i, hayir ise 0'i tuslayiniz."<<endl;
    cin>>answer;
if(answer==1)
{
    main();
}
else if(answer==0){
cout<<"Oyun sona ermistir. Oynadiginiz icin tesekkur ederiz."<<endl;
cout<<"Hazirlayan:"<<endl<<"Bengu Demiregen";
}
else{
cout<<"Lutfen 1 ve 0'dan baska rakam tuslamayiniz!"<<endl<<endl;
Again();
}
}