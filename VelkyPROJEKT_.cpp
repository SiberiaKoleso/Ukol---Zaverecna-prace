#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;


void zobrazMenu() {
    cout << "==========================================" << endl;
    cout << "  KRONIKY AETHELGARDU: STIN KRALE CUTALOTA " << endl;
    cout << "==========================================" << endl;
    cout << "1. Nova hra" << endl;
    cout << "2. Ukoncit" << endl;
    cout << "Vase volba: ";
}


void vypisPribeh(string jmeno) {
    cout << endl << "--- PRIBEH ---" << endl;
    cout << "Svet Aethelgardu upadl do chaosu. Tyran Cutalot ovladl zeme." << endl;
    cout << "Ty, hrdino " << jmeno << ", jsi posledni nadeji tohoto sveta." << endl;
    cout << "Ceka te dlouha cesta skrze monstra a vesnice." << endl;
    cout << "==========================================" << endl << endl;
}

int main() {
    
    srand(time(0));

    
    string jmeno;
    string profese;
    int hp, maxHp, mana, maxMana, utok, zlato, level, xp;

    int volbaMenu;
    int volbaTridy;
    int potvrzeni;
    bool hotovo = false;

    zobrazMenu();
    cin >> volbaMenu;

    if (volbaMenu != 1) {
        return 0;
    }

    cout << endl << "Zadej jmeno hrdiny: ";
    cin >> jmeno;

    vypisPribeh(jmeno);

    
    while (hotovo == false) {
        cout << "Vyber si svou tridu:" << endl;
        cout << "1. Paladin (Tank)" << endl;
        cout << "2. Mag (Damage)" << endl;
        cout << "3. Lovec (Zlato)" << endl;
        cout << "Vase volba: ";
        cin >> volbaTridy;

        
        switch (volbaTridy) {
        case 1:
            profese = "Paladin";
            maxHp = 20; hp = 20;
            maxMana = 10; mana = 10;
            utok = 5; zlato = 50;
            break;
        case 2:
            profese = "Mag";
            maxHp = 12; hp = 12;
            maxMana = 25; mana = 25;
            utok = 8; zlato = 30;
            break;
        case 3:
            profese = "Lovec";
            maxHp = 15; hp = 15;
            maxMana = 15; mana = 15;
            utok = 6; zlato = 100;
            break;
        default:
            cout << "Neplatna volba!" << endl;
            continue;
        }

        cout << endl << "--- " << jmeno << " (" << profese << ") ---" << endl;
        cout << "HP: " << hp << "/" << maxHp << " | Mana: " << mana << "/" << maxMana << endl;
        cout << "Utok: " << utok << " | Zlato: " << zlato << endl;

        cout << endl << "Chces tuto postavu? (1 - Ano / 0 - Ne): ";
        cin >> potvrzeni;

        if (potvrzeni == 1) {
            hotovo = true;
        }
    }

    level = 1;
    xp = 0;

    cout << endl << "Hrdina " << jmeno << " vstoupil do sveta Aethelgardu..." << endl;

    return 0;
}