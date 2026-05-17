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

    string monstrumJmeno = "Sjetej Kaluba";
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

        cout << endl << ">> STAV PO TVEM UTOKU <<" << endl;
        cout << "Hrac " << jmeno << ": " << hp << " HP | Mana: " << mana << " | Damage: " << utok << endl;
        cout << "Nepritel " << monstrumJmeno << ": " << monstrumHp << " HP" << endl;
        cout << "------------------------" << endl;

        if (monstrumHp > 0) {
            hp -= monstrumUtok;
            cout << endl << monstrumJmeno << " utoci a ubira ti " << monstrumUtok << " HP." << endl;

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
    cout << endl << "Cesta se zacina zuzovat a stromy kolem tebe jsou cim dal vic citit omackou od kebabu." << endl;
    cout << "Z krovi se najednou vyritilo neco mnohem tlustejsiho nez predchozi nepritel!" << endl;

    string m2Jmeno = "Tadeas Vesely";
    int m2Hp = 25;
    int m2Utok = 6;

    cout << endl << "!!! BOJ !!! Tvari v tvar ti stoji: " << m2Jmeno << endl;

    while (hp > 0 && m2Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Magicky vypad (5 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            m2Hp -= utok;
            cout << "Zasahl jsi Tadease za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 5) {
                mana -= 5;
                int silnyDmg = utok + 7;
                m2Hp -= silnyDmg;
                cout << "Magie usekla Tadeasovi speky za " << silnyDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m2Jmeno << " [" << m2Hp << " HP]" << endl;

        if (m2Hp > 0) {
            hp -= m2Utok;
            cout << endl << m2Jmeno << " ti dal speko facku za " << m2Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m2Jmeno << " [" << m2Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Tadeas te rozsednul. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Tadeas Vesely padl k zemi. Nasel jsi v jeho durumu 40 zlata!" << endl;
        zlato += 40;
        xp += 60;

        if (xp >= 50) {
            level++;
            xp -= 50;
            maxHp += 5; hp = maxHp;
            utok += 2;
            cout << "!!! LEVEL UP !!! Nyni jsi level " << level << endl;
        }

        cout << endl << "Co udelas nyni?" << endl;
        cout << "1. Pokracovat hloubeji do lesa" << endl;
        cout << "2. Vratit se do vesnice Beroun pro zasoby" << endl;
        cout << "Tva volba: ";
        int volbaNavrat;
        cin >> volbaNavrat;
        if (volbaNavrat == 2) {
            Beroun();
            vObchode = true;
            while (vObchode == true) {
                int volbaObchod;
                cout << endl << "--- OBCHOD --- (Zlato: " << zlato << ")" << endl;
                cout << "1. Leceni (" << cenik[0][1] << " HP) - " << cenik[0][0] << " zlata" << endl;
                cout << "2. Zvysit Max HP (+ " << cenik[1][1] << ") - " << cenik[1][0] << " zlata" << endl;
                cout << "3. Zvysit Max Manu (+ " << cenik[2][1] << ") - " << cenik[2][0] << " zlata" << endl;
                cout << "4. Zvysit Utok (+ " << cenik[3][1] << ") - " << cenik[3][0] << " zlata" << endl;
                cout << "5. Odejit z vesnice zpet do akce" << endl;
                cout << "Vase volba: ";
                cin >> volbaObchod;
                switch (volbaObchod) {
                case 1: if (zlato >= cenik[0][0]) { zlato -= cenik[0][0]; hp += cenik[0][1]; if (hp > maxHp) hp = maxHp; cout << "Vyleceno!" << endl; } break;
                case 2: if (zlato >= cenik[1][0]) { zlato -= cenik[1][0]; maxHp += cenik[1][1]; hp = maxHp; cout << "HP zvyseno!" << endl; } break;
                case 3: if (zlato >= cenik[2][0]) { zlato -= cenik[2][0]; maxMana += cenik[2][1]; mana = maxMana; cout << "Mana zvysena!" << endl; } break;
                case 4: if (zlato >= cenik[3][0]) { zlato -= cenik[3][0]; utok += cenik[3][1]; cout << "Utok zvysen!" << endl; } break;
                case 5: vObchode = false; break;
                }
            }
        }
    }

    cout << endl << "Prochazis hloubeji, kde mlha hustne. Citis zapach kovu a krve." << endl;
    cout << "Z mlhy vystoupil tenky stin!" << endl;

    string m3Jmeno = "Shopaholic Adel";
    int m3Hp = 40;
    int m3Utok = 8;

    cout << endl << "!!! POZOR !!! Utoci na tebe: " << m3Jmeno << endl;

    while (hp > 0 && m3Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            m3Hp -= utok;
            cout << "Uderil jsi Adelu za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 5;
                m3Hp -= ultraDmg;
                cout << "Naprahl jsi se a udelil " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Malo many!" << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m3Jmeno << " [" << m3Hp << " HP]" << endl;

        if (m3Hp > 0) {
            hp -= m3Utok;
            cout << endl << m3Jmeno << " ti dala facku za " << m3Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m3Jmeno << " [" << m3Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Adela te porazila. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Shopaholic Adel padla! Sebral jsi ji Gucci kabelku se 100 zlata." << endl;
        zlato += 100;
        xp += 100;

        cout << endl << "Chces vyuzit situace a vratit se do Berouna pred dalsim pruzkumem?" << endl;
        cout << "1. Ne, jit dal" << endl;
        cout << "2. Ano, do vesnice" << endl;
        int volbaNavrat2;
        cin >> volbaNavrat2;
        if (volbaNavrat2 == 2) {
            Beroun();
            vObchode = true;
            while (vObchode == true) {
                int volbaObchod;
                cout << endl << "--- OBCHOD --- (Zlato: " << zlato << ")" << endl;
                cout << "1. Leceni (" << cenik[0][1] << " HP) - " << cenik[0][0] << " zlata" << endl;
                cout << "2. Zvysit Max HP (+ " << cenik[1][1] << ") - " << cenik[1][0] << " zlata" << endl;
                cout << "3. Zvysit Max Manu (+ " << cenik[2][1] << ") - " << cenik[2][0] << " zlata" << endl;
                cout << "4. Zvysit Utok (+ " << cenik[3][1] << ") - " << cenik[3][0] << " zlata" << endl;
                cout << "5. Odejit z vesnice zpet do akce" << endl;
                cout << "Vase volba: ";
                cin >> volbaObchod;
                switch (volbaObchod) {
                case 1: if (zlato >= cenik[0][0]) { zlato -= cenik[0][0]; hp += cenik[0][1]; if (hp > maxHp) hp = maxHp; cout << "Vyleceno!" << endl; } break;
                case 2: if (zlato >= cenik[1][0]) { zlato -= cenik[1][0]; maxHp += cenik[1][1]; hp = maxHp; cout << "HP zvyseno!" << endl; } break;
                case 3: if (zlato >= cenik[2][0]) { zlato -= cenik[2][0]; maxMana += cenik[2][1]; mana = maxMana; cout << "Mana zvysena!" << endl; } break;
                case 4: if (zlato >= cenik[3][0]) { zlato -= cenik[3][0]; utok += cenik[3][1]; cout << "Utok zvysen!" << endl; } break;
                case 5: vObchode = false; break;
                }
            }
        }
    }

    cout << endl << "Cesta se zacina zuzovat a stromy kolem tebe jsou cim dal cernejsi." << endl;
    cout << "Z krovi se najednou ozvalo: PRAHA, JAK SE MATE, PRAHAAAAA!" << endl;

    string m4Jmeno = "Spikr Jira";
    int m4Hp = 25;
    int m4Utok = 6;

    cout << endl << "!!! BOJ !!! Tvari v tvar ti stoji: " << m4Jmeno << endl;

    while (hp > 0 && m4Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Magicky vypad (5 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            m4Hp -= utok;
            cout << "Zasahl jsi spikra za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 5) {
                mana -= 5;
                int silnyDmg = utok + 7;
                m4Hp -= silnyDmg;
                cout << "Magie dala " << silnyDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m4Jmeno << " [" << m4Hp << " HP]" << endl;

        if (m4Hp > 0) {
            hp -= m4Utok;
            cout << endl << m4Jmeno << " ti natahnul za " << m4Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m4Jmeno << " [" << m4Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Jira te porazil. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Spikr Jira padl k zemi. Nasel jsi v jeho schovce 40 zlata!" << endl;
        zlato += 40;
        xp += 60;

        if (xp >= 50) {
            level++;
            xp -= 50;
            maxHp += 5; hp = maxHp;
            utok += 2;
            cout << "!!! LEVEL UP !!! Nyni jsi level " << level << endl;
        }

        cout << endl << "Co udelas nyni?" << endl;
        cout << "1. Pokracovat hloubeji do lesa" << endl;
        cout << "2. Vratit se do vesnice Beroun pro zasoby" << endl;
        cout << "Tva volba: ";
        int volbaNavrat;
        cin >> volbaNavrat;
        if (volbaNavrat == 2) {
            Beroun();
            vObchode = true;
            while (vObchode == true) {
                int volbaObchod;
                cout << endl << "--- OBCHOD --- (Zlato: " << zlato << ")" << endl;
                cout << "1. Leceni (" << cenik[0][1] << " HP) - " << cenik[0][0] << " zlata" << endl;
                cout << "2. Zvysit Max HP (+ " << cenik[1][1] << ") - " << cenik[1][0] << " zlata" << endl;
                cout << "3. Zvysit Max Manu (+ " << cenik[2][1] << ") - " << cenik[2][0] << " zlata" << endl;
                cout << "4. Zvysit Utok (+ " << cenik[3][1] << ") - " << cenik[3][0] << " zlata" << endl;
                cout << "5. Odejit z vesnice zpet do akce" << endl;
                cout << "Vase volba: ";
                cin >> volbaObchod;
                switch (volbaObchod) {
                case 1: if (zlato >= cenik[0][0]) { zlato -= cenik[0][0]; hp += cenik[0][1]; if (hp > maxHp) hp = maxHp; cout << "Vyleceno!" << endl; } break;
                case 2: if (zlato >= cenik[1][0]) { zlato -= cenik[1][0]; maxHp += cenik[1][1]; hp = maxHp; cout << "HP zvyseno!" << endl; } break;
                case 3: if (zlato >= cenik[2][0]) { zlato -= cenik[2][0]; maxMana += cenik[2][1]; mana = maxMana; cout << "Mana zvysena!" << endl; } break;
                case 4: if (zlato >= cenik[3][0]) { zlato -= cenik[3][0]; utok += cenik[3][1]; cout << "Utok zvysen!" << endl; } break;
                case 5: vObchode = false; break;
                }
            }
        }
    }

    cout << endl << "Blizis se k ruinam vlakoveho narazi." << endl;
    cout << "Z mlhy vystoupil obrovsky stin s rezavou sekerou!" << endl;

    string m5Jmeno = "Hasic - bezdomovec";
    int m5Hp = 40;
    int m5Utok = 8;

    cout << endl << "!!! POZOR !!! Utoci na tebe: " << m5Jmeno << endl;

    while (hp > 0 && m5Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            m5Hp -= utok;
            cout << "Uderil jsi hasice za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 5;
                m5Hp -= ultraDmg;
                cout << "Soustredil jsi vsi silu a udelil " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Malo many!" << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m5Jmeno << " [" << m5Hp << " HP]" << endl;

        if (m5Hp > 0) {
            hp -= m5Utok;
            cout << endl << m5Jmeno << " te prastil sekerou za " << m5Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m5Jmeno << " [" << m5Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Bezdomovec te porazil. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Bezdomovec se jmenem Hasic padl! Sebral jsi mu vacek se 100 zlata." << endl;
        zlato += 100;
        xp += 100;

        cout << endl << "Chces vyuzit situace a vratit se do Berouna pred dalsim pruzkumem?" << endl;
        cout << "1. Ne, jit dal" << endl;
        cout << "2. Ano, do vesnice" << endl;
        int volbaNavrat2;
        cin >> volbaNavrat2;
        if (volbaNavrat2 == 2) {
            Beroun();
            vObchode = true;
            while (vObchode == true) {
                int volbaObchod;
                cout << endl << "--- OBCHOD --- (Zlato: " << zlato << ")" << endl;
                cout << "1. Leceni - " << cenik[0][0] << " zlata" << endl;
                cout << "2. Max HP - " << cenik[1][0] << " zlata" << endl;
                cout << "3. Max Mana - " << cenik[2][0] << " zlata" << endl;
                cout << "4. Utok - " << cenik[3][0] << " zlata" << endl;
                cout << "5. Odejit" << endl;
                cin >> volbaObchod;
                if (volbaObchod == 1 && zlato >= cenik[0][0]) { zlato -= cenik[0][0]; hp = maxHp; }
                else if (volbaObchod == 2 && zlato >= cenik[1][0]) { zlato -= cenik[1][0]; maxHp += cenik[1][1]; hp = maxHp; }
                else if (volbaObchod == 3 && zlato >= cenik[2][0]) { zlato -= cenik[2][0]; maxMana += cenik[2][1]; mana = maxMana; }
                else if (volbaObchod == 4 && zlato >= cenik[3][0]) { zlato -= cenik[3][0]; utok += cenik[3][1]; }
                else if (volbaObchod == 5) vObchode = false;
            }
        }
    }

    cout << endl << "Pokracujes hloubeji do pustiny..." << endl;
    cout << endl << "------------------------------------------" << endl;
    cout << "Vstoupil jsi do vesnice: Kraluv Dvur" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Mistni lide jsou vydeseni. Kralovodvorsky starosta te prosi o pomoc," << endl;
    cout << "protoze z nedalekych lazni a lesu lezou cim dal hrozivejsi stvury." << endl;

    int cenikKraluvDvur[4][2] = {
        {20, 10},
        {40, 8},
        {40, 8},
        {50, 4}
    };

    bool vObchodeKralov = true;
    while (vObchodeKralov == true) {
        int volbaObchodKralov;
        cout << endl << "--- TRH KRALOVA DVORA --- (Zlato: " << zlato << ")" << endl;
        cout << "1. Kralovske leceni (" << cenikKraluvDvur[0][1] << " HP) - " << cenikKraluvDvur[0][0] << " zlata" << endl;
        cout << "2. Tezka zbroj z huti (+ " << cenikKraluvDvur[1][1] << " Max HP) - " << cenikKraluvDvur[1][0] << " zlata" << endl;
        cout << "3. Elixir moudrosti (+ " << cenikKraluvDvur[2][1] << " Max Manu) - " << cenikKraluvDvur[2][0] << " zlata" << endl;
        cout << "4. Mec z kralovodvorske oceli (+ " << cenikKraluvDvur[3][1] << " Utok) - " << cenikKraluvDvur[3][0] << " zlata" << endl;
        cout << "5. Vyrazit branou ven z vesnice" << endl;
        cout << "Vase volba: ";
        cin >> volbaObchodKralov;

        switch (volbaObchodKralov) {
        case 1:
            if (zlato >= cenikKraluvDvur[0][0]) {
                zlato -= cenikKraluvDvur[0][0];
                hp += cenikKraluvDvur[0][1];
                if (hp > maxHp) hp = maxHp;
                cout << "Aktualni HP: " << hp << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 2:
            if (zlato >= cenikKraluvDvur[1][0]) {
                zlato -= cenikKraluvDvur[1][0];
                maxHp += cenikKraluvDvur[1][1];
                hp = maxHp;
                cout << "Maximalni HP zvyseno na: " << maxHp << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 3:
            if (zlato >= cenikKraluvDvur[2][0]) {
                zlato -= cenikKraluvDvur[2][0];
                maxMana += cenikKraluvDvur[2][1];
                mana = maxMana;
                cout << "Maximalni mana zvysena na: " << maxMana << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 4:
            if (zlato >= cenikKraluvDvur[3][0]) {
                zlato -= cenikKraluvDvur[3][0];
                utok += cenikKraluvDvur[3][1];
                cout << "Tvuj utok se zvysil na: " << utok << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 5:
            vObchodeKralov = false;
            break;
        default:
            cout << "Neplatna volba!" << endl;
            break;
        }
    }

    cout << endl << "Hrdina " << jmeno << " opousti bezpeci Kralova Dvora a jde vycistit okrajove lesy..." << endl;
    cout << "U silnice na tebe ze stinu zamku vyskocil nebezpecny wannabe!" << endl;

    string m6Jmeno = "Kralovodvorsky wannabe";
    int m6Hp = 100;
    int m6Utok = 14;

    cout << endl << "!!! BOJ !!! Tve ceste brani: " << m6Jmeno << endl;

    while (hp > 0 && m6Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Magicky vypad (5 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            m6Hp -= utok;
            cout << "Sekl jsi gangstera za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 5) {
                mana -= 5;
                int silnyDmg = utok + 12;
                m6Hp -= silnyDmg;
                cout << "Magicky plamen popalil gangstera za " << silnyDmg << " dmg!" << endl;
            }
            else {
                cout << "Malo many! Tvuj tah si promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m6Jmeno << " [" << m6Hp << " HP]" << endl;

        if (m6Hp > 0) {
            hp -= m6Utok;
            cout << endl << m6Jmeno << " na tebe vytahl teleskop a dal ti na zebra za " << m6Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m6Jmeno << " [" << m6Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Dezerter te nechal u silnice. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Wannabe padl k zemi. Pobral jsi jeho lup v hodnote 180 zlata!" << endl;
        zlato += 180;
        xp += 150;

        if (xp >= 50) {
            level++;
            xp -= 50;
            maxHp += 5; hp = maxHp;
            utok += 2;
            cout << "!!! LEVEL UP !!! Nyni jsi level " << level << endl;
        }

        cout << endl << "Chces se pred dalsi hrozbou stahnout zpet do Kralova Dvora?" << endl;
        cout << "1. Ne, pokracovat hluboko do lesa" << endl;
        cout << "2. Ano, zpet na mistni trh" << endl;
        int volbaNavrat5;
        cin >> volbaNavrat5;
        if (volbaNavrat5 == 2) {
            vObchodeKralov = true;
            while (vObchodeKralov == true) {
                int volbaObchodKralov;
                cout << endl << "--- TRH KRALOVA DVORA --- (Zlato: " << zlato << ")" << endl;
                cout << "1. Leceni - " << cenikKraluvDvur[0][0] << " zlata" << endl;
                cout << "2. Max HP - " << cenikKraluvDvur[1][0] << " zlata" << endl;
                cout << "3. Max Mana - " << cenikKraluvDvur[2][0] << " zlata" << endl;
                cout << "4. Utok - " << cenikKraluvDvur[3][0] << " zlata" << endl;
                cout << "5. Odejit" << endl;
                cin >> volbaObchodKralov;
                if (volbaObchodKralov == 1 && zlato >= cenikKraluvDvur[0][0]) { zlato -= cenikKraluvDvur[0][0]; hp = maxHp; cout << " HP plne!" << endl; }
                else if (volbaObchodKralov == 2 && zlato >= cenikKraluvDvur[1][0]) { zlato -= cenikKraluvDvur[1][0]; maxHp += cenikKraluvDvur[1][1]; hp = maxHp; cout << " HP navyseno!" << endl; }
                else if (volbaObchodKralov == 3 && zlato >= cenikKraluvDvur[2][0]) { zlato -= cenikKraluvDvur[2][0]; maxMana += cenikKraluvDvur[2][1]; mana = maxMana; cout << " Mana navysena!" << endl; }
                else if (volbaObchodKralov == 4 && zlato >= cenikKraluvDvur[3][0]) { zlato -= cenikKraluvDvur[3][0]; utok += cenikKraluvDvur[3][1]; cout << " Utok navysen!" << endl; }
                else if (volbaObchodKralov == 5) vObchodeKralov = false;
            }
        }
    }

    cout << endl << "Vstoupil jsi do znamejch mocalu kousek za obci." << endl;
    cout << "Zacala hrat Evropa 2 a z vody neco vyskocilo!" << endl;

    string m7Jmeno = "Leos Mares";
    int m7Hp = 130;
    int m7Utok = 16;

    cout << endl << "!!! POZOR !!! Tahle radiova stvura nezna slitovani. Utoci na tebe: " << m7Jmeno << endl;

    while (hp > 0 && m7Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            m7Hp -= utok;
            cout << "Sekl jsi Leose do kozichu za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 15;
                m7Hp -= ultraDmg;
                cout << "Soustredena magicka sila utrhla kus jeho kozichu za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nedostatek magicke energie!" << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m7Jmeno << " [" << m7Hp << " HP]" << endl;

        if (m7Hp > 0) {
            hp -= m7Utok;
            cout << endl << m7Jmeno << " te srazil mikrofinem do bahna a ubral " << m7Utok << " HP!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << m7Jmeno << " [" << m7Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Praskly ti usni bubinky. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "Leos Mares uz si nezamodruje. V rohu studia si nasel truhlu s 250 zlatými!" << endl;
        zlato += 250;
        xp += 180;

        if (xp >= 50) {
            level++;
            xp -= 50;
            maxHp += 5; hp = maxHp;
            utok += 2;
            cout << "!!! LEVEL UP !!! Nyni jsi level " << level << endl;
        }

        cout << endl << "Chces se vratit slavit vitezstvi do hostince v Kralove Dvore?" << endl;
        cout << "1. Ne, jit rovnou dal k zatracenemu hradu" << endl;
        cout << "2. Ano, zpet do Kralova Dvora" << endl;
        int volbaNavrat6;
        cin >> volbaNavrat6;
        if (volbaNavrat6 == 2) {
            vObchodeKralov = true;
            while (vObchodeKralov == true) {
                int volbaObchodKralov;
                cout << endl << "--- TRH KRALOVA DVORA --- (Zlato: " << zlato << ")" << endl;
                cout << "1. Leceni - " << cenikKraluvDvur[0][0] << " zlata" << endl;
                cout << "2. Max HP - " << cenikKraluvDvur[1][0] << " zlata" << endl;
                cout << "3. Max Mana - " << cenikKraluvDvur[2][0] << " zlata" << endl;
                cout << "4. Utok - " << cenikKraluvDvur[3][0] << " zlata" << endl;
                cout << "5. Odejit" << endl;
                cin >> volbaObchodKralov;
                if (volbaObchodKralov == 1 && zlato >= cenikKraluvDvur[0][0]) { zlato -= cenikKraluvDvur[0][0]; hp = maxHp; cout << " HP plne!" << endl; }
                else if (volbaObchodKralov == 2 && zlato >= cenikKraluvDvur[1][0]) { zlato -= cenikKraluvDvur[1][0]; maxHp += cenikKraluvDvur[1][1]; hp = maxHp; cout << " HP navyseno!" << endl; }
                else if (volbaObchodKralov == 3 && zlato >= cenikKraluvDvur[2][0]) { zlato -= cenikKraluvDvur[2][0]; maxMana += cenikKraluvDvur[2][1]; mana = maxMana; cout << " Mana navysena!" << endl; }
                else if (volbaObchodKralov == 4 && zlato >= cenikKraluvDvur[3][0]) { zlato -= cenikKraluvDvur[3][0]; utok += cenikKraluvDvur[3][1]; cout << " Utok navysen!" << endl; }
                else if (volbaObchodKralov == 5) vObchodeKralov = false;
            }
        }
    }

    return 0;
}