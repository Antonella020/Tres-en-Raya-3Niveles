
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    //variables:
    char entrada,jugador1,jugador2;
    bool valido=true;
    //0. BIENVENIDO AL NIVEL 1:
    cout<<"!BIENVENIDO AL NIVEL 2\n!";
    cout<<"Jugador1 VS BOOT \n";
    //1.-ESCOGER ENTRE X O O:
    //6.-RANDOM(para jugador 2):
    
    srand(time(nullptr));
    
    int n{9};
    
    int random=rand()%n;//numeros desde el 0 hasta el 8.
    
    do {
        cout<<"Entre un valor(X/O): ";
        cin>>entrada;
        if (entrada=='X'||entrada=='O'){
            if (entrada=='X'){
                jugador1='X';
                jugador2='O';
            }
            
            if (entrada=='O'){
                jugador1='O';
                jugador2='X';
            }
            valido=true;
        }
        else{
            valido=false;
        }
    }while(!valido);
    char matriz[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    //3.-CAMBIAR EL TURNO DEL JUGADOR:
    //3.1-LOS JUGADORES SE TURNAN ENTRADO SUS MOVIMIENTOS:
    int numero;
    int contador=-1;
    int i=0;
    int j=0;
    //4.-CHECKEAR AL GANADOR:
    bool ganador=false;
    do {
        //2.-MOSTRA LA TABLA(MATRIZ):
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                cout<<matriz[i][j]<<" | ";
            }
            cout<<"\n";
        }
        contador++;
        if ((contador%2)==0){
            cout<<"Jugador 1 (1-9): ";
            cin>>numero;
            //5.-CELDA VALIDA (1 AL 9):
            do{
                if ((1<=numero)&&(numero<=9)){
                    numero-=1;
                    i=numero/3;
                    j=numero%3;
                    if ((matriz[i][j]=='O')||(matriz[i][j]=='X')){
                        cout<<"Casilla Ocupada\n";
                        cout<<"Jugador 2 (1-9) : ";
                        cin>>numero;
                        valido=false;
                    }
                    else{
                        valido=true;
                    }
                }
                else{
                    cout<<"Fuera de Rango\n";
                    cout<<"Jugador 1 (1-9): ";
                    cin>>numero;
                    valido=false;
                }
            }while(!valido);
            //nosotros utlizamos una matriz de 0 hasta 8 en indexes:
            //POSICIONES:
            matriz[i][j]=jugador1;
            if (contador>=4){
                //CHEKEAR GANADOR(JUGADOR 1):
                if ((matriz[0][0]==jugador1&&matriz[1][0]==jugador1&&matriz[2][0]==jugador1)||
                (matriz[0][1]==jugador1&&matriz[1][1]==jugador1&&matriz[2][1]==jugador1)||
                (matriz[0][2]==jugador1&&matriz[1][2]==jugador1&&matriz[2][2]==jugador1)){
                    cout<<"!Raya Vertical!\n";
                    cout<<"!Jugador1,gana el juego!";
                    ganador=true;
                }
                if ((matriz[0][0]==jugador1&&matriz[0][1]==jugador1&&matriz[0][2]==jugador1)||
                (matriz[1][0]==jugador1&&matriz[1][1]==jugador1&&matriz[1][2]==jugador1)||
                (matriz[2][0]==jugador1&&matriz[2][1]==jugador1&&matriz[2][2]==jugador1)){
                    cout<<"!Raya Horizontal!\n";
                    cout<<"!Jugador1,gana el juego!";
                    ganador=true;
                }
                if ((matriz[2][0]==jugador1&&matriz[1][1]==jugador1&&matriz[0][2]==jugador1)||
                (matriz[0][0]==jugador1&&matriz[1][1]==jugador1&&matriz[2][2]==jugador1)){
                    cout<<"!Raya Diagonall!\n";
                    cout<<"!Jugador1,gana el juego!";
                    ganador=true;
                }
            }
        }
        //3.2:EL JUEGO ACTUALIZA EL TABLERO BASADO EN LA ENTRADA DEL USUARIO:
        
        else{
            numero=random;
            //5.-CELDA VALIDA (1 AL 9):
            do{
                numero-=1;
                i=numero/3;
                j=numero%3;
                if ((matriz[i][j]=='O')||(matriz[i][j]=='X')){
                    do{
                        //indexes de 0 hasta el 8;
                        random=rand()%n;
                        numero=random;
                        i=numero/3;
                        j=numero%3;
                        
                    }while(matriz[i][j]=='O'||matriz[i][j]=='X');
                    valido=true;
                }
                else{
                    valido=true;
                }
            }while(!valido);
            //nosotros utlizamos una matriz de 0 hasta 8 en indexes:
            //POSICIONES:
            matriz[i][j]=jugador2;
            //CHECKEAR GANADOR (JUGADOR2)
            if (contador>=4){
                if ((matriz[0][0]==jugador2&&matriz[1][0]==jugador2&&matriz[2][0]==jugador2)||
                (matriz[0][1]==jugador2&&matriz[1][1]==jugador2&&matriz[2][1]==jugador2)||
                (matriz[0][2]==jugador2&&matriz[1][2]==jugador2&&matriz[2][2]==jugador2)){
                    cout<<"!Raya Vertical!\n";
                    cout<<"!Jugador2,gana el juego!";
                    ganador=true;
                }
                if ((matriz[0][0]==jugador2&&matriz[0][1]==jugador2&&matriz[0][2]==jugador2)||
                (matriz[1][0]==jugador2&&matriz[1][1]==jugador2&&matriz[1][2]==jugador2)||
                (matriz[2][0]==jugador2&&matriz[2][1]==jugador2&&matriz[2][2]==jugador2)){
                    cout<<"!Raya Horizontal!\n";
                    cout<<"!Jugador2,gana el juego!";
                    ganador=true;
                }
                if ((matriz[2][0]==jugador2&&matriz[1][1]==jugador2&&matriz[0][2]==jugador2)||
                (matriz[0][0]==jugador2&&matriz[1][1]==jugador2&&matriz[2][2]==jugador2)){
                    cout<<"!Raya Diagonall!\n";
                    cout<<"!Jugador2,gana el juego!";
                    ganador=true;
                }
            }
        }
        cout<<"\n"<<contador<<"\n";
        if (ganador==true){
            break;
        }
    //ya que va desde 0 hasta 8, para tomar 9 posiciones de las que le indiquamos.
    }while(contador<8);
    //6.PARTES FINALES DEL JUEGO:
    //6.1 GANAR O EMPATE:
    if (contador==8){
        cout<<"!El juego es un empate!\n";
    }
    cout<<"Tablero Final:\n";
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cout<<matriz[i][j]<<" | ";
        }
        cout<<"\n";
    }
    //6.2 EMPEZAR UN NUEVO JUEGO O DAR AL EXIT:
    cout<<"\nMENU DEL JUEGO\n";
    cout<<"----------------\n";
    cout<<"NIVEL 1(jugador1VSjugador2) = 1\n";
    cout<<"NIVEL 2(jugador VS BOT basico = 2\n";
    cout<<"NIVEL 3(jugador VS BOT PRO = 3\n";
    cout<<"SALIR = 4\n";
    int juego;
    do{
        cout<<"¿Cual nivel deseea?: ";
        cin>>juego;
        if(juego==1||juego==2||juego==3||juego==4){
            if (juego==1){
                cout<<"llamar a la funcion 1";
            }
            if (juego==2){
                cout<<"llamar a la funcion 2";
            }
            if (juego==3){
                cout<<"llamar a la funcion 3";
            }
            if (juego==4){
                cout<<"!Muchas gracias por jugar!";
            }
            valido=true;
        }
        else{
            cout<<"Entrada invalda";
            valido=false;
        }
    }while(!valido);
    
    return 0;

}
