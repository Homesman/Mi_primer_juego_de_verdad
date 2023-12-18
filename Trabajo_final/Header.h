#pragma once

#include "pch.h"
#include "iostream"
#include "windows.h"
#include "Header1.h"
#define META 380

using namespace System;
using namespace std;
typedef struct {
    float x = 5;
    int y = 5;
    float velocidad;
} Bot;

void setxy(int x, int y)
{
    Console::SetCursorPosition(x, y);

}
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
float aleatorio() {
    return ((float)rand()) / RAND_MAX;
}
void escenario() {

    Console::SetWindowSize(80, 40);
    Console::SetBufferSize(500, 500);

    char cuadrado = 178;  // Codigo decimal del cuadrado en el conjunto de caracteres ASCII
    cout << " ____                                                                                                                                                                                                                                                 " << endl;
    cout << "|    |____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "|      |";
    for (int i = 0; i < 50; i++) {
        cout << "\033[38;2;255;228;196m"; cout << "   " << cuadrado << "   ";
    }
    cout << endl;
    cout << "|      |";
    for (int i = 0; i < 50; i++) {
        int random = getRandomNumber(2, 16);
        colores(random); cout << "  " << cuadrado << cuadrado << cuadrado << "  ";
    }
    cout << endl;
    cout << "|      |________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "|        |";
    for (int i = 0; i < 50; i++) {
        cout << "\033[38;2;255;228;196m"; cout << "   " << cuadrado << "   ";
    }
    cout << endl;
    cout << "|        |";
    for (int i = 0; i < 50; i++) {
        int random = getRandomNumber(2, 16);
        colores(random); cout << "  " << cuadrado << cuadrado << cuadrado << "  ";
    }
    colores(15);
    cout << endl;
    cout << "|        |________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "|          |";
    for (int i = 0; i < 50; i++) {
        cout << "\033[38;2;255;228;196m"; cout << "   " << cuadrado << "   ";
    }
    cout << endl;
    cout << "|          |";
    for (int i = 0; i < 50; i++) {
        int random = getRandomNumber(2, 16);
        colores(random); cout << "  " << cuadrado << cuadrado << cuadrado << "  ";
    }
    colores(15);
    cout << endl;
    cout << "|          |__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
    cout << "|             |                                                                                                                               " << endl;
    cout << "|             |                                                                                                                               " << endl;
    cout << "|_____________|__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << endl;



}


//JUGADOR
void dibuja_personaje(float& x, float& y)
{
    COORD personaje = { x, y };


    colores(16); setxy(personaje.X, personaje.Y);		  cout << R"( O )" << "\n";
    colores(15); setxy(personaje.X, personaje.Y + 1);	  cout << R"(/|\)" << "\n";
    colores(14); setxy(personaje.X, personaje.Y + 2);	  cout << R"(/ \)" << "\n";

}

void borrar(float x1, float y1)
{
    setxy(x1, y1);		 colores(14); cout << " "; cout << R"(   )";
    setxy(x1, y1 + 1);   colores(14); cout << " "; cout << R"(   )";
    setxy(x1, y1 + 2);   colores(14); cout << char(178); cout << R"(   )";

}

void aumentar_velocidad(float& dx1) // POR VER PARA VOLVERLO ALEATORIO
{

    dx1 = dx1 + 0.2;

}

void mover_corredor_der(float& x1, float& dx1)
{
    x1 = x1 + dx1;
}


//BOTS
void bots(Bot bots[], int n) {
    for (int i = 0; i < n; i++) {
        setxy(bots[i].x, bots[i].y + 0); cout << R"( O )" << "\n";
        setxy(bots[i].x, bots[i].y + 1); cout << R"(-|-)" << "\n";
        setxy(bots[i].x, bots[i].y + 2); cout << R"(| |)" << "\n";
    }
}

void velocidad_bots(Bot bots[], int n) {
    for (int i = 0; i < n; i++) {
        bots[i].velocidad = aleatorio();
    }
}

void borrarBots(Bot bots[], int n) {
    for (int i = 0; i < n; i++) {
        setxy(bots[i].x, bots[i].y + 0); cout << R"(   )" << "\n";
        setxy(bots[i].x, bots[i].y + 1); cout << R"(   )" << "\n";
        setxy(bots[i].x, bots[i].y + 2); cout << R"(   )" << "\n";
    }
}

//RONDA
void ronda() {
    Console::CursorVisible = false;
    Console::SetBufferSize(500, 120);
    srand(time(NULL));
    const int NmrCorredores = 3;
    Bot* robots = new Bot[NmrCorredores];
    int x = 5;
    int y = 15;
    int cuenta_regresiva = 3;
    float cuenta_iniciada = 0;
    float tiempos[NmrCorredores]; // Array para almacenar los tiempos de llegada de cada bot

    for (int i = 0; i < NmrCorredores; i++) {
        robots[i].x = x;
        robots[i].y = y + 5 * i;
        tiempos[i] = 0; // Inicializa los tiempos en 0
    }

    while (cuenta_regresiva > 0) {
        system("cls");
        setxy(0, 0);
        cout << "Empieza en " << cuenta_regresiva << " segundos";
        _sleep(1000);
        cuenta_regresiva--;
        Console::Clear();
    }
    escenario();
    while (true) {
        velocidad_bots(robots, NmrCorredores);
        borrarBots(robots, NmrCorredores);

        bool todosLlegaron = true; // Variable para verificar si todos los bots llegaron

        for (int i = 0; i < NmrCorredores; i++) {
            if (robots[i].x <= META) {
                robots[i].x += 5 * robots[i].velocidad;
                todosLlegaron = false;
            }
            if (tiempos[i] == 0 && robots[i].x > META) {
                tiempos[i] = cuenta_iniciada; // Registra el tiempo de llegada de cada bot
            }
        }

        bots(robots, NmrCorredores);

       
        
        _sleep(100);
        cuenta_iniciada++;

        if (todosLlegaron) {
            break;
        }
    }

    for (int i = 0; i < NmrCorredores; i++) {
        setxy(30, 22 + i);
        cout << "Bot " << i << " - Tiempo: " << tiempos[i] / 10 << " segundos";
    }
    setxy(30, 22 + NmrCorredores);
    cout << "Presione una tecla para continuar......";
    system("pause>0");
}