#include "pch.h"
#include "iostream"
#include "windows.h"
#include "conio.h"
#include "MMsystem.h"
#include "string"
#pragma comment(lib, "winmm.lib")

#define Derecha 77
#define META 290

using namespace System;
using namespace std;
#define color SetConsoleTextAttribute

//NO TOCAR LO DE ABAJO

struct Bot {
    float x = 5;
    int y = 5;
    float velocidad;
    string pais;
    string nombre;
} ;
struct Persona{
    string pais;
    string nombre;
    float x= 5;
    int y=17;
    float velocidad=1;
    int estado_animacion = 0;
};
struct Ganador {
    string nombre;
    string pais;
    float tiempo;
};

void setxy(int x, int y)
{
    Console::SetCursorPosition(x, y);

}
int aleatorio_paises() {
   return  rand() % 42;
}
int aleatorio_nombres() {
    return rand() % 50;
}
string paises() {
    string paises[42] = { "Antigua y Barbuda", "Argentina", "Aruba", "Bahamas", "Barbados", "Belice", "Bermudas", "Bolivia", "Brasil", "Canada", "Chile", "Colombia", "Costa Rica", "Cuba", "Dominica", "Ecuador", "El Salvador", "Estados Unidos", "Granada", "Guatemala", "Guyana", "Haiti", "Honduras", "Islas Caiman", "Islas Virgenes Britanicas", "Islas Virgenes de los Estados Unidos", "Jamaica", "Mexico", "Nicaragua", "Panama", "Paraguay", "Peru", "Puerto Rico", "Republica Dominicana", "San Cristobal y Nieves", "San Vicente y las Granadinas", "Santa Lucia", "Surinam", "Trinidad y Tobago", "Uruguay", "Venezuela" };
    int random_paises = aleatorio_paises();
    return paises[random_paises];
}
string nombres() {
    string nombres[50] = { "Carlos", "Juan", "Andres", "Pedro", "Gabriel", "Mateo", "Roberto", "Alejandro", "Javier", "Luis", "Daniel", "Martin", "Sergio", "Francisco", "Esteban", "Eduardo","Antonio", "Raul", "Diego", "Jorge", "Leonardo", "Jose", "Felipe", "Emilio", "Marcos","Maria", "Ana", "Laura", "Sofia", "Carmen", "Paula", "Isabel", "Gabriela", "Valentina", "Patricia", "Diana", "Alejandra", "Victoria", "Elena", "Raquel", "Lucia", "Beatriz", "Carla", "Daniela", "Gloria", "Natalia", "Rosa", "Conchita", "Adriana", "Lourdes" };
    int random_nombres = aleatorio_nombres();
    return nombres[random_nombres];
}
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
float aleatorio() {
    return ((float)rand()) / RAND_MAX;
}
void colorfondo(int texto, int fondo) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, texto + (fondo << 4));
}
void colores(int c)
{
    switch (c)
    {
    case 1:Console::ForegroundColor = ConsoleColor::Black;       break;
    case 2:Console::ForegroundColor = ConsoleColor::DarkGray;	 break;
    case 3:Console::ForegroundColor = ConsoleColor::Blue;		 break;
    case 4:Console::ForegroundColor = ConsoleColor::Cyan;		 break;
    case 5:Console::ForegroundColor = ConsoleColor::DarkBlue;	 break;
    case 6:Console::ForegroundColor = ConsoleColor::DarkCyan;	 break;
    case 7:Console::ForegroundColor = ConsoleColor::DarkGreen;	 break;
    case 8:Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 9:Console::ForegroundColor = ConsoleColor::DarkRed;	 break;
    case 10:Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 11:Console::ForegroundColor = ConsoleColor::Gray;		 break;
    case 12:Console::ForegroundColor = ConsoleColor::Green;		 break;
    case 13:Console::ForegroundColor = ConsoleColor::Magenta;	 break;
    case 14:Console::ForegroundColor = ConsoleColor::Red;		 break;
    case 15:Console::ForegroundColor = ConsoleColor::White;		 break;
    case 16:Console::ForegroundColor = ConsoleColor::Yellow;	 break;
    }
}


//NO TOCAR LO DE ARRIBA

//MENUS
void instrucciones() {
    int opcion = 1;
    int key;
    bool* repetir = new bool;

    *repetir = true;
    do
    {
        system("cls");
        cout << "*************************************************************************" << endl;
        cout << "*                             Instrucciones                             *" << endl;
        cout << "*                                                                       *" << endl;
        cout << R"(* ¡Bienvenido a "Carrera de 100 metros"!                              *)" << endl;
        cout << "* Tu objetivo es ser el mas rapido campeon de la carrera de 100 metros. *" << endl;
        cout << "* Asegurate que no haya nadie mas veloz que tu. ¿Estas listo para este  *" << endl;
        cout << "* desafio? Aqui tienes las instrucciones para comenzar:                 *" << endl;
        cout << "*                                                                       *" << endl;
        cout << "* Objetivo del Juego:                                                   *" << endl;
        cout << "* Tu objetivo principal sera llegar a la meta mas rapido que los otros  *" << endl;
        cout << "* campeones. Aumenta tu velocidad y vuela hasta el oro.                 *" << endl;
        cout << "*                                                                       *" << endl;
        cout << "* Controles:                                                            *" << endl;
        cout << "* Presiona repetidamente la tecla de flecha derecha para aumentar tu    *" << endl;
        cout << "* velocidad y vencer a tus oponentes.                                   *" << endl;
        cout << "*************************************************************************" << endl;


        cout << "1. REGRESAR";
        if (opcion == 1) {
            cout << " <--";
        }
        cout << "\n";
        cout << "0. SALIR ";
        if (opcion == 2) {
            cout << " <--";
        }

        key = getch();
        Console::Clear();
        switch (key) {
        case 72:
            opcion--;
            if (opcion < 0) {
                opcion = 1;
            }
            break;
        case 80:
            opcion++;
            if (opcion > 2) {
                opcion = 2;
            }
            break;
        case 13:
            if (opcion == 1) {
                *repetir = false;
            }
            else {
                exit(0);
            }
            break;
        }
    } while (*repetir);
}


void contador_1() {
    colores(12);
    const wchar_t* musicFile = L"sonidocontador.wav";
    // Reproducir la música
    PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
cout << R"(
                          .·:''''''':·.
                          : :  .--. : :
                          : : /_  | : :
                          : :  |  | : :
                          : :  |  | : :
                          : :  |  | : :
                          : :  `--' : :
                          '·:.......:·')";

}
void contador_2() {
    colores(16);
    const wchar_t* musicFile = L"sonidocontador.wav";
    // Reproducir la música
    PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
    cout << R"(
                              .·:'''''''''':·.
                              : :  .----.  : :
                              : : \_,-.  | : :
                              : :    .' .' : :
                              : :  .'  /_  : :
                              : : |      | : :
                              : : `------' : :
                              '·:..........:·')";
}
void contador_3() {
    colores(14);
    const wchar_t* musicFile = L"sonidocontador.wav";
    // Reproducir la música
    PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
    cout << R"(
                                     .·:'''''''''':·.
                                     : :  .----.  : :
                                     : : \_.-,  | : :
                                     : :   |_  <  : :
                                     : : .-. \  | : :
                                     : : \ `-'  / : :
                                     : :  `---''  : :
                                     '·:..........:·')";
}
void contador_4() {
    colores(12);
    const wchar_t* musicFile = L"sonidogo.wav";

    PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
    cout << R"(
                                 _______  _______  __   __ 
                                |       ||       ||  | |  |
                                |    ___||   _   ||  | |  |
                                |   | __ |  | |  ||  | |  |
                                |   ||  ||  |_|  ||__| |__|
                                |_______||_______||__| |__|)";
}
void escenario() {

    Console::SetWindowSize(80, 40);
    Console::SetBufferSize(500, 500);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    color(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);

    char cuadrado = 178;  // Codigo decimal del cuadrado en el conjunto de caracteres ASCII

    std::cout << "                                                                                                                                                                                                                                                                                                                                                                                                                       " << std::endl;
    std::cout << " _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl; SetConsoleTextAttribute(hConsole, 7);
    std::cout << "|      |";
    for (int i = 0; i < 50; i++) {
        cout << "\033[38;2;255;228;196m"; std::cout << "   " << cuadrado << "   ";
    }
    std::cout << std::endl;
    std::cout << "|      |";
    for (int i = 0; i < 50; i++) {
        int random = getRandomNumber(3, 16);
        colores(random); cout << "  " << cuadrado << cuadrado << cuadrado << "  ";
    }
    SetConsoleTextAttribute(hConsole, 7);
    std::cout << std::endl;
    std::cout << "|      |________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
    std::cout << "|        |";
    for (int i = 0; i < 50; i++) {
        cout << "\033[38;2;255;228;196m"; cout << "   " << cuadrado << "   ";
    }
    std::cout << std::endl;
    std::cout << "|        |";
    for (int i = 0; i < 50; i++) {
        int random = getRandomNumber(3, 16);
        colores(random); cout << "  " << cuadrado << cuadrado << cuadrado << "  ";
    }
    colores(15);
    std::cout << std::endl;
    std::cout << "|        |________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
    std::cout << "|          |";
    for (int i = 0; i < 50; i++) {
        cout << "\033[38;2;255;228;196m"; cout << "   " << cuadrado << "   ";
    }
    std::cout << std::endl;
    std::cout << "|          |";
    for (int i = 0; i < 50; i++) {
        int random = getRandomNumber(3, 16);
        colores(random); cout << "  " << cuadrado << cuadrado << cuadrado << "  ";
    }
    colores(15);
    std::cout << std::endl;
    std::cout << "|          |__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
    std::cout << "|             |"; cout << "                                                                                                                                                                                                                                                                                           ";
    for (int i = 0; i < 4; i++) {
        cout << "\033[38;2;255;228;196m"; cout << "     " << cuadrado;
    }
    std::cout << std::endl;
    std::cout << "|             |"; cout << "                                                                                                                                                                                                                                                                                            ";
    for (int i = 0; i < 4; i++) {
        int random = getRandomNumber(3, 16);
        colores(2); cout << "   " << cuadrado << cuadrado << cuadrado;
    }
    std::cout << endl;

    std::cout << "|_____________|__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|__________________________________________________________________________________________________________________" << std::endl;




    for (int i = 0; i < 500; i++) {
        color(hConsole, BACKGROUND_GREEN); cout << "  ";
    }

    for (int i = 0; i < 1000; i++) {
        color(hConsole, BACKGROUND_RED); cout << "  ";
    }   


    for (int i = 0; i < 500; i++) {
        color(hConsole, BACKGROUND_GREEN); cout << "  ";
    }


    for (int i = 0; i < 1000; i++) {
        color(hConsole, BACKGROUND_RED); cout << "  ";
    }


    for (int i = 0; i < 500; i++) {
        color(hConsole, BACKGROUND_GREEN); cout << "  ";
    }

    for (int i = 0; i < 1000; i++) {
        color(hConsole, BACKGROUND_RED); cout << "  ";
    }

    for (int i = 0; i < 500; i++) {
        color(hConsole, BACKGROUND_GREEN); cout << "  ";
    }
    for (int i = 0; i < 1000; i++) {
        color(hConsole, BACKGROUND_RED); cout << "  ";
    }


    for (int i = 0; i < 500; i++) {
        color(hConsole, BACKGROUND_GREEN); cout << "  "; color(hConsole, BACKGROUND_RED);
    }

}
void animar_personaje(Persona& jugador) {
    jugador.estado_animacion = (jugador.estado_animacion + 1) % 5;
}
//JUGADOR
void dibuja_personaje(Persona& jugador)
{
    colores(4);
    setxy(jugador.x, jugador.y);      cout << R"( O )" << "\n";
    setxy(jugador.x, jugador.y + 1);  cout << R"(/|\)" << "\n";
    setxy(jugador.x + 3, jugador.y + 1); ; cout << R"(  )" << "\n";
    setxy(jugador.x, jugador.y + 2);

    switch (jugador.estado_animacion) {
    case 0: cout << R"(/ \)"; break;
    case 1: cout << R"(> \)"; break;
    case 2: cout << R"(| \)"; break;
    case 3: cout << R"(| >)"; break;
    case 4: cout << R"(/ \)"; break;
    }

}



void borrar(Persona& jugador)
{
    // Clear previous position

    setxy(jugador.x, jugador.y);       colores(0); cout << "   ";
    setxy(jugador.x, jugador.y + 1);   colores(0); cout << "   ";
    setxy(jugador.x, jugador.y + 2);   colores(0); cout << "   ";

    setxy(jugador.x-1, jugador.y);     colores(0); cout << "   ";
    setxy(jugador.x-1, jugador.y + 1); colores(0); cout << "   ";
    setxy(jugador.x-1, jugador.y + 2); colores(0); cout << "   ";
    setxy(jugador.x - 2, jugador.y);     colores(0); cout << "   ";
    setxy(jugador.x - 2, jugador.y + 1); colores(0); cout << "   ";
    setxy(jugador.x - 2, jugador.y + 2); colores(0); cout << "   ";
    setxy(jugador.x - 3, jugador.y);     colores(0); cout << "   ";
    setxy(jugador.x - 3, jugador.y + 1); colores(0); cout << "   ";
    setxy(jugador.x - 3, jugador.y + 2); colores(0); cout << "   ";


}

void aumentar_velocidad(Persona& jugador) // POR VER PARA VOLVERLO ALEATORIO
{

    jugador.velocidad += aleatorio();
}

void mover_corredor_der(Persona& jugador)
{
    jugador.x += jugador.velocidad;
}


//BOTS
void bots(Bot bots[], int n) {
    for (int i = 0; i < n; i++) {
        colores(4);
        setxy(bots[i].x, bots[i].y + 0);    cout << R"( O )" << "\n";
        setxy(bots[i].x, bots[i].y + 1);    cout << R"(-|-)" << "\n";
        setxy(bots[i].x, bots[i].y + 2);    cout << R"(| |)" << "\n";
        setxy(bots[i].x+28, bots[i].y + 2);    cout << R"(  )" << "\n";
    }
}

void velocidad_bots(Bot bots[], int n) {
    for (int i = 0; i < n; i++) {
        bots[i].velocidad = aleatorio();
    }
}

void borrarBots(Bot bots[], int n) {
    for (int i = 0; i < n; i++) {
        setxy(bots[i].x-1, bots[i].y + 0); cout << R"(   )" << "\n";
        setxy(bots[i].x-1, bots[i].y + 1); cout << R"(   )" << "\n";
        setxy(bots[i].x-1, bots[i].y + 2); cout << R"(   )" << "\n";
    }
}
void DistanciaBots(Bot robots[], float tiempos[], int NmrCorredores, int x, int y) {
    for (int i = 0; i < NmrCorredores; i++) {
        robots[i].x = x;
        robots[i].y = y + 6 * i;
        tiempos[i] = 0; 
    }
}
void NombrePaisBots(Bot robots[], int NmrCorredores) {
    for (int i = 0; i < NmrCorredores; i++) {
        robots[i].pais = paises();
        robots[i].nombre = nombres();
    }
}

//RONDA
Ganador ronda(int NmrCorredores, float multiplicador, int velocidadbarra) {


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    Console::CursorVisible = false;
    Console::SetBufferSize(2500, 500);
    srand(time(NULL));

    Bot* robots = new Bot[NmrCorredores];
    float* tiempos = new float[NmrCorredores]; // Cambiado a int ya que al final se está dividiendo por 10 para obtener segundos
    int* x = new int(5);
    int* y = new int(22);
    int* cuenta_regresiva = new int(4);
    float* cuenta_iniciada = new float(0);

    // Asignar nombre y país a los bots
    NombrePaisBots(robots, NmrCorredores);

    // Asignar distancia entre cada bot
    DistanciaBots(robots, tiempos, NmrCorredores, *x, *y);

    // Cuenta regresiva
    while (*cuenta_regresiva > 0) {
        system("cls");

        switch (*cuenta_regresiva) {
        case 1: setxy(40, 15); contador_4(); break;
        case 2: setxy(40, 15); contador_1(); break;
        case 3: setxy(40, 15); contador_2(); break;
        case 4: setxy(40, 15); contador_3(); break;
        default:
            break;
        }

        _sleep(1000);
        (*cuenta_regresiva)--;
        Console::Clear();
    }

    escenario(); // Escenario

    // Jugador
    int* anchoBarraProgreso = new int(20);
    float* maximavelocidad = new float(2);
    char* rellenoBarraProgreso = new char(219);
    char* vacioBarraProgreso = new char(' ');
    int progreso = 0;
    int progresoOriginal = 0;
    int* xde = new int(0);
    int* yde = new int(0);

    int* ultimaActualizacion = new int(GetTickCount64());
    int* ultimaTeclaPresionada = new int(0);
    Persona jugador;
    Ganador ganador;
    int* maximo = new int(100);

    const wchar_t* musicFile = L"musicacarrera.wav";
    PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
    dibuja_personaje(jugador);

    while (true) {
        *xde = jugador.x;
        *yde = jugador.y + 21;
        animar_personaje(jugador);
        borrar(jugador);
        dibuja_personaje(jugador);


        
        // Calcular tiempo desde la última actualización
        int ahora = GetTickCount64();
        int tiempoDesdeUltimaActualizacion = ahora - *ultimaActualizacion;

        // Actualizar progreso cada vez que se presiona la tecla derecha o izquierda
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == Derecha && progreso < *anchoBarraProgreso) {
                progreso += 2;  // Ajusta según sea necesario
                if (progreso > *anchoBarraProgreso) progreso = *anchoBarraProgreso;
                *ultimaTeclaPresionada = ahora;
                dibuja_personaje(jugador);
            }
        }

        // Reducir el progreso con el tiempo
        if (tiempoDesdeUltimaActualizacion > velocidadbarra) {
            progreso -= 2;  // Ajusta según sea necesario
            if (progreso < 0) progreso = 0;
            *ultimaActualizacion = ahora;
            dibuja_personaje(jugador);
        }

        // Mover el jugador solo si el progreso es mayor que 0
        if (progreso > 0) {
            // Mover el jugador según su velocidad
            if (tiempoDesdeUltimaActualizacion > 1 / (jugador.velocidad + 1)) {
                dibuja_personaje(jugador);
                jugador.x += progreso / 10 + 0.14;  // Ajusta según sea necesario
                

            }

            if (jugador.x > 290) {
                jugador.x = 290;
            }

        }


        colorfondo(14, 2);
        setxy(*xde+37, *yde); cout << R"(   )";
        setxy(*xde-5, *yde);
        if (*xde == 290) {
            *xde= *xde+1;
            if (*xde > 350) {
                *xde = 350;
            }
        }

        cout << "   " << "Velocidad: {";
            for (int i = 0; i < progreso; ++i) {
                cout << *rellenoBarraProgreso;
            }
            for (int i = progreso; i < *anchoBarraProgreso; ++i) {
                cout << *vacioBarraProgreso;
            }
            int porcentaje = progreso * 100 / *anchoBarraProgreso;
            std::cout << "} " << porcentaje << "  ";

            colorfondo(7, 4);
        
        velocidad_bots(robots, NmrCorredores);
        borrarBots(robots, NmrCorredores);
        bool todosLlegaron = true;
        for (int i = 0; i < NmrCorredores; i++) {
            if (robots[i].x <= META) {
                robots[i].x += multiplicador * robots[i].velocidad;
                todosLlegaron = false;
            }
            if (tiempos[i] == 0 && robots[i].x > META) {
                tiempos[i] = *cuenta_iniciada / 2; // Registra el tiempo de llegada de cada bot
            }

        }
        bots(robots, NmrCorredores);
        _sleep(30);
        *cuenta_iniciada= *cuenta_iniciada+1;

        if (todosLlegaron) {
            break;
        }
    }
    int* ganadore = new int;

    *ganadore = 0;
    for (int i = 1; i < NmrCorredores; i++) {
        if (tiempos[i] < tiempos[*ganadore]) {
            *ganadore = i;
        }
    }

    ganador.nombre = robots[*ganadore].nombre;
    ganador.pais = robots[*ganadore].pais;
    ganador.tiempo = tiempos[*ganadore] / 10;

    color(hConsole, 07);
    system("cls");
    for (int i = 0; i < NmrCorredores; i++) {
        colores(15);
        setxy(15, 15 + i);
        cout << robots[i].nombre << "-" << robots[i].pais << " - Tiempo: " << tiempos[i] / 10 << " segundos";
    }
    // Convierte a segundos
    setxy(30, 22 + NmrCorredores);
    cout << "Presione una tecla para continuar......";
    system("pause>0");

    delete x; delete y; delete xde; delete yde; delete ultimaActualizacion; delete ultimaTeclaPresionada; delete maximo; delete vacioBarraProgreso; delete rellenoBarraProgreso; delete maximavelocidad; delete anchoBarraProgreso; delete cuenta_regresiva; delete[] robots; delete[] tiempos;

    return ganador;
}

void animar_alabador(Persona& jugador) {
    jugador.estado_animacion = (jugador.estado_animacion + 1) % 4;
}
void animar_ganador(Persona& jugador) {
    jugador.estado_animacion = (jugador.estado_animacion + 1) % 2;
}

void dibuja_perdedor(Persona& jugador) {
    char guion = 236;
    switch (jugador.estado_animacion) {
    case 0:
        setxy(jugador.x, jugador.y); cout << R"(         )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(   _     )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"( \((}/   )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"(  ) '    )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"( ,` )    )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << "  " << guion << guion << "    " << endl;
        break;
    case 1:
        setxy(jugador.x, jugador.y);     cout << R"(          )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(    _     )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(  |´(}/   )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"(  / .´    )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"( ,` )     )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << "  " << guion << guion << "    " << endl;
        break;
    case 2:
        setxy(jugador.x, jugador.y);     cout << R"(          )" << endl;
        setxy(jugador.x, jugador.y + 1);   cout << R"(           )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(       _   )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"(    ,-´/}_  )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"(  ,' ,¯¯    )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << "   " << guion << guion << "    " << endl;
        break;
    case 3:
        setxy(jugador.x, jugador.y);     cout << R"(          )" << endl;
        setxy(jugador.x, jugador.y + 1);   cout << R"(          )" << endl;
        setxy(jugador.x, jugador.y + 2);   cout << R"(          )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"(      _   )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"( ,-'¯´_)  )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << " " << guion << guion << guion << " " << guion << guion << "   " << endl;
    }
}
void dibuja_perdedor2(Persona& jugador) {
    char guion = '-';
    switch (jugador.estado_animacion) {
    case 0:
        setxy(jugador.x, jugador.y);     cout << R"(          )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(  _        )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(\{))/      )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"( ' (       )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"( ( `,      )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << " " << guion << guion << "    " << endl;
        break;
    case 1:
        setxy(jugador.x, jugador.y);     cout << R"(            )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(  _        )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(\{)´|      )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"( `. \      )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"(  ( `,     )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << "   " << guion << guion << "    " << endl;
        break;
    case 2:
        setxy(jugador.x, jugador.y);     cout << R"(           )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(           )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(  _        )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"(_{\´-,     )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"(¯¯, ',     )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << "   " << guion << guion << "    " << endl;
        break;
    case 3:
        setxy(jugador.x, jugador.y - 1);     cout << R"(             )" << endl;
        setxy(jugador.x, jugador.y);     cout << R"(             )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(             )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(              )" << endl;
        setxy(jugador.x, jugador.y + 3); cout << R"(  _        )" << endl;
        setxy(jugador.x, jugador.y + 4); cout << R"(_(_´¯'-,       )" << endl;
        setxy(jugador.x, jugador.y + 5); cout << " " << guion << guion << " " << guion << guion << guion << "   " << endl;
    }
}

void dibuja_ganador(Persona& jugador) {
    switch (jugador.estado_animacion) {
    case 0:
        setxy(jugador.x, jugador.y);     cout << R"(  \O/ )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(   |  )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(  / \ )" << endl;
        break;
    case 1:
        setxy(jugador.x, jugador.y);     cout << R"(  <O> )" << endl;
        setxy(jugador.x, jugador.y + 1); cout << R"(   |  )" << endl;
        setxy(jugador.x, jugador.y + 2); cout << R"(  / \ )" << endl;
        break;



    }
}
void dibuja_nombre_ganador(string ganador)
{

    setxy(33, 30); cout << "\033[48;2;249;240;167m" << ganador;
    Console::BackgroundColor = ConsoleColor::DarkCyan;


}

int matriz[26][58] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,4,4,4,4,4,4,4,4,4,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,4,4,4,4,4,4,4,4,4,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,4,4,4,4,4,4,4,4,4,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,4,4,4,4,4,4,4,4,4,4,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,4,4,4,4,4,4,4,4,4,4,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,6,6,6},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,5,5,5,5,5,5,5,5,5,5,5,6},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,5,5,5,5,5,5,5,5,5,5,5,6},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,5,5,5,5,5,5,5,5,5,5,5,6},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,5,5,5,5,5,5,5,5,5,5,5,6},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,5,5,5,5,5,5,5,5,5,5,5,6},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,6,5,5,5,5,5,5,5,5,5,5,5,6} };


void dibujarMatriz() {
    system("Color 30");
    Console::SetWindowSize(80, 40);
    for (int filas = 0; filas < 26; filas++) {
        for (int columnas = 0; columnas < 58; columnas++) {
            if (matriz[filas][columnas] == 0) {
                Console::BackgroundColor = ConsoleColor::DarkCyan;
            }
            else if (matriz[filas][columnas] == 4) {
                Console::BackgroundColor = ConsoleColor::Yellow;
            }
            else if (matriz[filas][columnas] == 5) {
                Console::BackgroundColor = ConsoleColor::DarkYellow;
            }
            else if (matriz[filas][columnas] == 2) {
                Console::BackgroundColor = ConsoleColor::Gray;
            }
            else if (matriz[filas][columnas] == 6) {
                Console::BackgroundColor = ConsoleColor::DarkGray;
            }
            cout << " ";
        }
        // Mueve el cursor a la siguiente línea para la próxima fila de la matriz
        setxy(0, filas + 15);

    }
}

int ganar(Ganador ganador) {
    Console::CursorVisible = false;
    Persona jugador1;
    Persona jugador2;
    Persona jugador3;

    jugador1.x = 20;
    jugador1.y = 25;

    jugador2.x = 47;
    jugador2.y = 27;

    jugador3.x = 35;
    jugador3.y = 23;

    // Configuración inicial de posiciones de las personitas y matriz

    // Bucle principal
    bool repetir = true;
    const wchar_t* musicFile = L"musicacelebracion.wav";


    PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
    dibujarMatriz();
    while (repetir) {
        animar_alabador(jugador1);
        dibuja_perdedor(jugador1);

        animar_alabador(jugador2);
        dibuja_perdedor2(jugador2);

        animar_ganador(jugador3);
        dibuja_ganador(jugador3);
        dibuja_nombre_ganador(ganador.nombre);
        // Verifica si alguna tecla ha sido presionada
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'q' || tecla == 'Q') {
                repetir = false; // Sale del bucle si se presiona 'q' o 'Q'
            }


        }
        Sleep(100);
    }

    return 0;
}


void menu() {

    Ganador ganador;
    bool repetir = true;
    Console::CursorVisible = false;
    Console::SetWindowSize(80, 40);


    int opcion = 1;

    do {
        colores(15);
        setxy(25, 1);
        cout << R"(
                 /==============================================\
                 ||  ___  _   _      _   _                     ||
                 || / _ \| | | |    | | (_)                    ||
                 ||/ /_\ \ |_| | ___| |_ _ ___ _ __ ___   ___  ||
                 |||  _  | __| |/ _ \ __| / __| '_ ` _ \ / _ \ ||
                 ||| | | | |_| |  __/ |_| \__ \ | | | | | (_) |||
                 ||\_| |_/\__|_|\___|\__|_|___/_| |_| |_|\___/ ||
                 \==============================================/
)" << "\n";
        colores(15);
        setxy(25, 10);
        if (opcion == 1) {
            colores(12);
        }
        cout << R"(    
    _  _     _____ ____  ____ 
   / |/ \ /\/  __//  _ \/  __\
   | || | ||| |  _| / \||  \/|
/\_| || \_/|| |_//| |-|||    /
\____/\____/\____\\_/ \|\_/\_\)";

        colores(7);

        std::cout << "\n\n";
        colores(15);
        setxy(25, 16);
        if (opcion == 2) {
            colores(13);
        }
        cout << R"(    
 _  _      ____  _____  ____  _     ____  ____  _  ____  _      _____ ____ 
/ \/ \  /|/ ___\/__ __\/  __\/ \ /\/   _\/   _\/ \/  _ \/ \  /|/  __// ___\
| || |\ |||    \  / \  |  \/|| | |||  /  |  /  | || / \|| |\ |||  \  |    \
| || | \||\___ |  | |  |    /| \_/||  \_ |  \_ | || \_/|| | \|||  /_ \___ |
\_/\_/  \|\____/  \_/  \_/\_\\____/\____/\____/\_/\____/\_/  \|\____\\____/)";
        colores(7);

        cout << "\n\n";
        colores(15);
        setxy(25, 23);
        if (opcion == 3) {
            colores(2);
        }
        cout << R"(    
 ____  ____  _____ ____  _  _____  ____  ____ 
/   _\/  __\/  __//  _ \/ \/__ __\/  _ \/ ___\
|  /  |  \/||  \  | | \|| |  / \  | / \||    \
|  \__|    /|  /_ | |_/|| |  | |  | \_/|\___ |
\____/\_/\_\\____\\____/\_/  \_/  \____/\____/)";

        colores(7);

        cout << "\n\n";
        colores(15);
        setxy(25, 30);
        if (opcion == 0) {
            colores(14);
        }
        cout << R"(    
 ____  ____  _     _  ____ 
/ ___\/  _ \/ \   / \/  __\
|    \| / \|| |   | ||  \/|
\___ || |-||| |_/\| ||    /
\____/\_/ \|\____/\_/\_/\_\)";

        colores(7);

        cout << "\n\n\n\n\n";

        // Leer la tecla presionada
        char key = _getch();

        switch (key) {
        case 72:
            opcion--;
            if (opcion == 0) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion == 1) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion == 2) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion == 3) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion < 0) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
                opcion = 3;

            }


            break;
        case 80:
            opcion++;
            if (opcion == 1) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion == 2) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion == 3) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion == 4) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);

            }
            if (opcion > 3) {
                const wchar_t* musicFile = L"sonidomenu.wav";

                // Reproducir la música
                PlaySound(musicFile, NULL, SND_FILENAME | SND_ASYNC);
                opcion = 0;
            }
            break;
        case 13:
            if (opcion == 1) {

                Ganador ganadorRonda = ronda(3, 2, 94);
                Ganador ganadorRonda1 = ronda(2, 2, 94);
                system("cls");
                ganar(ganadorRonda);
 

                repetir = false;

            }

            else if (opcion == 2) {

                instrucciones();

            }
            else if (opcion == 3) {

                instrucciones();
            }

            else if (opcion == 0) {
                exit(0);
            }
            break;
        }

    } while (repetir);
}



