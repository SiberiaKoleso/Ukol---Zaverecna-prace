#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void zobrazMenu() {
    cout << "==========================================" << endl;
    cout << "  KRONIKY BEROUNA " << endl;
    cout << "==========================================" << endl;
    cout << "1. Nova hra" << endl;
    cout << "2. Ukoncit" << endl;
    cout << "Vase volba: ";
}

void vypisPribeh(string jmeno) {
    cout << endl << "--- PRIBEH ---" << endl;
    cout << "Berounsko upadlo do chaosu." << endl;
    cout << "Ty, hrdino " << jmeno << ", jsi posledni nadeji tohoto kraje." << endl;
    cout << "Ceka te dlouha cesta skrze berounsky stoky." << endl;
    cout << "==========================================" << endl << endl;
}

void Beroun() {
    cout << endl << "------------------------------------------" << endl;
    cout << "Vstoupil jsi do vesnice: Beroun" << endl;
    cout << "------------------------------------------" << endl;
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

    cout << endl << "Hrdina " << jmeno << " vstoupil do koncu Berounska..." << endl;

    Beroun();

    int cenik[4][2] = {
        {10, 5},
        {25, 5},
        {25, 5},
        {30, 2}
    };

    bool vObchode = true;
    while (vObchode == true) {
        int volbaObchod;
        cout << endl << "--- OBCHOD --- (Zlato: " << zlato << ")" << endl;
        cout << "1. Leceni (" << cenik[0][1] << " HP) - " << cenik[0][0] << " zlata" << endl;
        cout << "2. Zvysit Max HP (+ " << cenik[1][1] << ") - " << cenik[1][0] << " zlata" << endl;
        cout << "3. Zvysit Max Manu (+ " << cenik[2][1] << ") - " << cenik[2][0] << " zlata" << endl;
        cout << "4. Zvysit Utok (+ " << cenik[3][1] << ") - " << cenik[3][0] << " zlata" << endl;
        cout << "5. Odejit z vesnice" << endl;
        cout << "Vase volba: ";
        cin >> volbaObchod;

        switch (volbaObchod) {
        case 1:
            if (zlato >= cenik[0][0]) {
                zlato -= cenik[0][0];
                hp += cenik[0][1];
                if (hp > maxHp) hp = maxHp;
                cout << "Byl jsi vylecen. Aktualni HP: " << hp << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 2:
            if (zlato >= cenik[1][0]) {
                zlato -= cenik[1][0];
                maxHp += cenik[1][1];
                hp = maxHp;
                cout << "Maximalni HP zvyseno na: " << maxHp << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 3:
            if (zlato >= cenik[2][0]) {
                zlato -= cenik[2][0];
                maxMana += cenik[2][1];
                mana = maxMana;
                cout << "Maximalni mana zvysena na: " << maxMana << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 4:
            if (zlato >= cenik[3][0]) {
                zlato -= cenik[3][0];
                utok += cenik[3][1];
                cout << "Tvuj utok se zvysil na: " << utok << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 5:
            vObchode = false;
            break;
        default:
            cout << "Neplatna volba!" << endl;
            break;
        }
    }

    cout << endl << "Hrdina " << jmeno << " opousti vesnici a vydava se do temnych lesu..." << endl;

    // --- TYDEN 3: SOUBOJ S AKTUALIZACI STAVU ---

    string monstrumJmeno = "Zmutovana krysa z Berounky";
    int monstrumHp = 15;
    int monstrumUtok = 4;
    int odmenaXp = 50;

    cout << endl << "!!! POZOR !!! Narazil jsi na nepritele: " << monstrumJmeno << endl;

    while (hp > 0 && monstrumHp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Magicky vypad (stoji 5 many)" << endl;
        cout << "Tva akce: ";
        cin >> akce;

        if (akce == 1) {
            monstrumHp -= utok;
            cout << "Utocis na " << monstrumJmeno << " za " << utok << " poškozeni." << endl;
        }
        else if (akce == 2) {
            if (mana >= 5) {
                mana -= 5;
                int silnyUtok = utok * 2;
                monstrumHp -= silnyUtok;
                cout << "Pouzil jsi magii! Monstrum dostalo za " << silnyUtok << " poškozeni." << endl;
            }
            else {
                cout << "Nemas dost many! Ztracis tah." << endl;
            }
        }

        // Vypis stavu po tvem utoku
        cout << endl << ">> STAV PO TVEM UTOKU <<" << endl;
        cout << "Hrac " << jmeno << ": " << hp << " HP | Mana: " << mana << " | Damage: " << utok << endl;
        cout << "Nepritel " << monstrumJmeno << ": " << monstrumHp << " HP" << endl;
        cout << "------------------------" << endl;

        // Tah monstra (pokud jeste zije)
        if (monstrumHp > 0) {
            hp -= monstrumUtok;
            cout << endl << monstrumJmeno << " utoci a ubira ti " << monstrumUtok << " HP." << endl;

            // Vypis stavu po utoku monstra
            cout << ">> STAV PO UTOKU MONSTRA <<" << endl;
            cout << "Hrac " << jmeno << ": " << hp << " HP | Mana: " << mana << " | Damage: " << utok << endl;
            cout << "Nepritel " << monstrumJmeno << ": " << monstrumHp << " HP" << endl;
            cout << "------------------------" << endl;
        }
    }

    if (hp <= 0) {
        cout << endl << "Byl jsi porazen... HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Gratuluji! Zabil jsi " << monstrumJmeno << "." << endl;
        xp += odmenaXp;
        cout << "Ziskal jsi " << odmenaXp << " zkusenosti." << endl;

        if (rand() % 2 == 0) {
            int nalez = 15 + (rand() % 10);
            zlato += nalez;
            cout << "V krisi jsi nasel " << nalez << " zlata!" << endl;
        }

        if (xp >= 50) {
            level++;
            xp -= 50;
            maxHp += 5;
            hp = maxHp;
            utok += 2;
            cout << endl << "!!! NOVY LEVEL !!!" << endl;
            cout << "Nyni jsi level " << level << ". Tve HP a utok se zvysily." << endl;
        }
    }

    cout << endl << "Pokracujes dal v ceste berounskou pustinou..." << endl;

    return 0;
}