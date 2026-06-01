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
    cout << endl << "------------------------------------------" << endl;
    cout << "Aby jsi mohl dobit Berounsko musis dobit i Tetin..." << endl;
    cout << "------------------------------------------" << endl;
    cout << "Vydavas se na Tetin..." << endl;


    string c1Jmeno = "Snejks z Kralova Dvora";
    int c1Hp = 50;
    int c1Utok = 10;

    cout << endl << ">> 1. PREKAZKA: V zatacce pod kopcem stoji " << c1Jmeno << "!" << endl;
    cout << "Snejks rve: 'To je vymysleny tohleto!' a dela karate. Ma " << c1Hp << " HP!" << endl;

    while (hp > 0 && c1Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH (vs Snejks) ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            c1Hp -= utok;
            cout << "Zasahl jsi Snejkse mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                c1Hp -= ultraDmg;
                cout << "Magicky vyboj poslal Snejkse k zemi za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c1Jmeno << " [" << c1Hp << " HP]" << endl;

        if (c1Hp > 0) {
            hp -= c1Utok;
            cout << endl << c1Jmeno << " ti dal bombu za " << c1Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c1Jmeno << " [" << c1Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Snejks te nepustil ani do kopce a zbil te svojim karate skillem. HRA KONCI." << endl;
        return 0;
    }
    cout << "-> Snejks dostal na budku a utekl smer Králuv Dvur!" << endl;

    string c2Jmeno = "Karlos Vemola";
    int c2Hp = 70;
    int c2Utok = 12;

    cout << endl << ">> 2. PREKAZKA: V pulce kopce na tebe vyskakuje " << c2Jmeno << "!" << endl;
    cout << "Karlos krici: 'Lvi zerou prvni!' a natahuje se po tvem krku. Ma " << c2Hp << " HP!" << endl;

    while (hp > 0 && c2Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH (vs Karlos) ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            c2Hp -= utok;
            cout << "Zasahl jsi Karlose mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                c2Hp -= ultraDmg;
                cout << "Magicky vyboj otrasl Terminatorem za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c2Jmeno << " [" << c2Hp << " HP]" << endl;

        if (c2Hp > 0) {
            hp -= c2Utok;
            cout << endl << c2Jmeno << " te hodil na zem a nasazuje kravatu za " << c2Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c2Jmeno << " [" << c2Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Karlos te uskrtil v gilotine a vzal si tvuj mec. HRA KONCI." << endl;
        return 0;
    }
    cout << "-> Karlos dostal KO a pada z tetinskeho svahu!" << endl;

    string c3Jmeno = "Psychopat Bejr";
    int c3Hp = 60;
    int c3Utok = 14;

    cout << endl << ">> 3. PREKAZKA: Tesne pod vrcholem te s silenym revem napada " << c3Jmeno << "!" << endl;
    cout << "Bejr toci zidli nad hlavou a rve na cele lesy. Ma " << c3Hp << " HP!" << endl;

    while (hp > 0 && c3Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH (vs Bejr) ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            c3Hp -= utok;
            cout << "Zasahl jsi Bejra mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                c3Hp -= ultraDmg;
                cout << "Magicky vyboj zasahl Bejra primo do hrudi za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c3Jmeno << " [" << c3Hp << " HP]" << endl;

        if (c3Hp > 0) {
            hp -= c3Utok;
            cout << endl << c3Jmeno << " te pretahl skladaci zidli po zadech za " << c3Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c3Jmeno << " [" << c3Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Psychopat Bejr te zlikvidoval zidli a utekl za rozhodcim. HRA KONCI." << endl;
        return 0;
    }
    cout << "-> Bejr utika do housti a nadava na nespravedlnost!" << endl;

    cout << endl << "------------------------------------------" << endl;
    cout << "DOSAHL JSI VRCHOLU: Tetin" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Zbroj mas ponicenou, mec zubaty, ale jsi nahore. Vyhled na Berounku je uchvatny," << endl;
    cout << "ale najednou se zeme otrese. Ze starobyleho hradiste vystupuje myticka postava," << endl;
    cout << "ktera zde strazi berounske tradice a drzi obri kamenny torpedo..." << endl;

    string bossJmeno = "Praotec Beroun (MINIBOSS)";
    int bossHp = 200;
    int bossUtok = 18;

    cout << endl << "!!! LEGENDA OZIVLA !!! Stoji proti tobe obri stin s kamennym sutrem!" << endl;
    cout << "Praotec Beroun te sleduje rudyma ocima. Ma celkem " << bossHp << " HP!" << endl;

    while (hp > 0 && bossHp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH (vs MINIBOSS) ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            bossHp -= utok;
            cout << "Zasahl jsi Praotce Berouna mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                bossHp -= ultraDmg;
                cout << "Tvuj magicky blesk otrasl samotnou skalou a zasahl Praotce za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << bossJmeno << " [" << bossHp << " HP]" << endl;

        if (bossHp > 0) {
            hp -= bossUtok;
            cout << endl << bossJmeno << " svihl kyjem a zasahl te silou berounske skaly za " << bossUtok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << bossJmeno << " [" << bossHp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Praotec Beroun te pohrbil na tetinském hradisti. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "!!! TETIN BYL DOBYT !!!" << endl;
        cout << "Praotec Beroun pada na kolena, uznava tvou silu a rozplyva se v ranni mlze." << endl;
        cout << "Zanechal po sobe bajny poklad: 400 zlata a 250 zkusenosti!" << endl;
        zlato += 400;
        xp += 250;

        if (xp >= 50) {
            level++;
            xp -= 50;
            maxHp += 12; hp = maxHp;
            maxMana += 6; mana = maxMana;
            utok += 5;
            cout << "!!! LEGENDARNI LEVEL UP !!! Nyni jsi level " << level << ". Tve statistiky brutalne vzrostly!" << endl;
        }

        cout << endl << "Chces se pred pokracovanim v ceste vratit na trh do Kralova Dvora?" << endl;
        cout << "1. Ne, jit rovnou" << endl;
        cout << "2. Yes, jit nakoupit zasoby za ukoristene zlato" << endl;
        int volbaNavrat7;
        cin >> volbaNavrat7;
        if (volbaNavrat7 == 2) {
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
                if (volbaObchodKralov == 1 && zlato >= cenikKraluvDvur[0][0]) { zlato -= cenikKraluvDvur[0][0]; hp = maxHp; cout << " HP plné!" << endl; }
                else if (volbaObchodKralov == 2 && zlato >= cenikKraluvDvur[1][0]) { zlato -= cenikKraluvDvur[1][0]; maxHp += cenikKraluvDvur[1][1]; hp = maxHp; cout << " HP navýšeno!" << endl; }
                else if (volbaObchodKralov == 3 && zlato >= cenikKraluvDvur[2][0]) { zlato -= cenikKraluvDvur[2][0]; maxMana += cenikKraluvDvur[2][1]; mana = maxMana; cout << " Mana navýšena!" << endl; }
                else if (volbaObchodKralov == 4 && zlato >= cenikKraluvDvur[3][0]) { zlato -= cenikKraluvDvur[3][0]; utok += cenikKraluvDvur[3][1]; cout << " Útok navýšen!" << endl; }
                else if (volbaObchodKralov == 5) vObchodeKralov = false;
            }
        }
    }
    cout << endl << "------------------------------------------" << endl;
    cout << "Pokracujes na Karlstejn" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Sestupujes z Tetina a vydavas se podel reky Berounky smerem k hradu Karlstejn." << endl;
    cout << "Cesta je temna, hluboke lesy jsou plne nebezpeci a stvur!" << endl;

    string c4Jmeno = "Divoky Berounsky Fetak";
    int c4Hp = 65;
    int c4Utok = 12;

    cout << endl << ">> Z housti vybiha nastvany " << c4Jmeno << "!" << endl;
    cout << "Fetka se riti primo na tebe. Ma " << c4Hp << " HP!" << endl;

    while (hp > 0 && c4Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            c4Hp -= utok;
            cout << "Zasahl jsi fetaka mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                c4Hp -= ultraDmg;
                cout << "Magicky vyboj srazil fetaka na bok za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c4Jmeno << " [" << c4Hp << " HP]" << endl;

        if (c4Hp > 0) {
            hp -= c4Utok;
            cout << endl << c4Jmeno << " ti vlepil za " << c4Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c4Jmeno << " [" << c4Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Divoky Fetak te ufetoval k smrti. HRA KONCI." << endl;
        return 0;
    }
    cout << "-> Fetak padl, jdes dal!" << endl;

    string c5Jmeno = "Wannabe samuraj";
    int c5Hp = 55;
    int c5Utok = 15;

    cout << endl << ">>  Nad tvoji hlavou proletelo neco obriho. Je to " << c5Jmeno << "!" << endl;
    cout << "Skocil ze skaly pred tebe. Ma " << c5Hp << " HP!" << endl;

    while (hp > 0 && c5Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            c5Hp -= utok;
            cout << "Zasahl jsi samuraje za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                c5Hp -= ultraDmg;
                cout << "Blesk smazil jeho papirovou cepku za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! samuraj se ti smeje." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c5Jmeno << " [" << c5Hp << " HP]" << endl;

        if (c5Hp > 0) {
            hp -= c5Utok;
            cout << endl << c5Jmeno << " te bodnul katanou ukradenou v Kladne za " << c5Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c5Jmeno << " [" << c5Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Wannabe samuraj te probodnul. HRA KONCI." << endl;
        return 0;
    }
    cout << "-> Samuraje si dodelal a pokracujes v ceste!" << endl;

    string c6Jmeno = "Falesny Pruvodce Karlstejna";
    int c6Hp = 80;
    int c6Utok = 11;

    cout << endl << ">> Pred podhradim te zastavuje podezrely muz v historickem kostymu: " << c6Jmeno << "!" << endl;
    cout << "Rve: 'Kup si predrazeny listek nebo neprojdes!' a taha skryty nuz. Ma " << c6Hp << " HP!" << endl;

    while (hp > 0 && c6Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            c6Hp -= utok;
            cout << "Zasahl jsi pruvodce mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                c6Hp -= ultraDmg;
                cout << "Tva magie rozmetala jeho falesne vstupenky za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c6Jmeno << " [" << c6Hp << " HP]" << endl;

        if (c6Hp > 0) {
            hp -= c6Utok;
            cout << endl << c6Jmeno << " te bodl zezadu za " << c6Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << c6Jmeno << " [" << c6Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Falesny pruvodce te okradl a nechal lezet v prikopu. HRA KONCI." << endl;
        return 0;
    }
    cout << "-> Pruvodce utekl a ty konecne vchazis do nove lokace!" << endl;

    cout << endl << "------------------------------------------" << endl;
    cout << "ODEMCENA NOVA VESNICE: Podhradi Karlstejna" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Dorazil jsi pod majestatni hrad. Mistni ti nabizeji" << endl;
    cout << "to nejlepsi kralovske vybaveni, abys mohl hrad dobyt!" << endl;

    int cenikKarlstejn[4][2] = {
        {40, 35},  
        {70, 20},  
        {70, 15},  
        {100, 10} 
    };

    bool vObchodeKarlstejn = true;
    while (vObchodeKarlstejn == true) {
        int volbaObchodKarlstejn;
        cout << endl << "--- KRALOVSKY TRH KARLSTEJNA --- (Zlato: " << zlato << ")" << endl;
        cout << "1. Kralovska medovina (Leceni +" << cenikKarlstejn[0][1] << " HP) - " << cenikKarlstejn[0][0] << " zlata" << endl;
        cout << "2. Brneni cisare Karla (+ " << cenikKarlstejn[1][1] << " Max HP) - " << cenikKarlstejn[1][0] << " zlata" << endl;
        cout << "3. Elixir moci (+ " << cenikKarlstejn[2][1] << " Max Manu) - " << cenikKarlstejn[2][0] << " zlata" << endl;
        cout << "4. Mec s drahokamy (+ " << cenikKarlstejn[3][1] << " Utok) - " << cenikKarlstejn[3][0] << " zlata" << endl;
        cout << "5. Vyrazit do hradu na BRUTALNI BITVU" << endl;
        cout << "Vase volba: ";
        cin >> volbaObchodKarlstejn;

        switch (volbaObchodKarlstejn) {
        case 1:
            if (zlato >= cenikKarlstejn[0][0]) {
                zlato -= cenikKarlstejn[0][0];
                hp += cenikKarlstejn[0][1];
                if (hp > maxHp) hp = maxHp;
                cout << "Citis se skvele. Aktualni HP: " << hp << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 2:
            if (zlato >= cenikKarlstejn[1][0]) {
                zlato -= cenikKarlstejn[1][0];
                maxHp += cenikKarlstejn[1][1];
                hp = maxHp;
                cout << "Maximalni HP zvyseno na: " << maxHp << endl;
            }
            else {
                cout << "Nemas dost zalta!" << endl;
            }
            break;
        case 3:
            if (zlato >= cenikKarlstejn[2][0]) {
                zlato -= cenikKarlstejn[2][0];
                maxMana += cenikKarlstejn[2][1];
                mana = maxMana;
                cout << "Maximalni mana zvysena na: " << maxMana << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 4:
            if (zlato >= cenikKarlstejn[3][0]) {
                zlato -= cenikKarlstejn[3][0];
                utok += cenikKarlstejn[3][1];
                cout << "Tvuj utok brutalne vzrostl na: " << utok << endl;
            }
            else {
                cout << "Nemas dost zlata!" << endl;
            }
            break;
        case 5:
            vObchodeKarlstejn = false;
            break;
        default:
            cout << "Neplatna volba!" << endl;
            break;
        }
    }

    cout << endl << "------------------------------------------" << endl;
    cout << "UTOK NA HRAD: Dobyvani Karlstejna" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Vylomil jsi branu a mlatis hradni straze levu i pravou." << endl;
    cout << "Vstupujes do kaple svateho Krize, kde na tebe ceka samotny boss hradu," << endl;
    cout << "kteri ovladl poklady Koruny ceske!" << endl;

    string boss2Jmeno = "Zly Kastelan Karlstejna (MINIBOSS)";
    int boss2Hp = 220;
    int boss2Utok = 20;

    cout << endl << "!!! BITVA O TRUN !!! Proti tobe stoji " << boss2Jmeno << " v tezke zbroji!" << endl;
    cout << "Kastelan rve: 'Zadne zeny ani hrdinove sem nesmi!' Ma celkem " << boss2Hp << " HP!" << endl;

    while (hp > 0 && boss2Hp > 0) {
        int akce;
        cout << endl << "--- TVUJ TAH (vs MINIBOSS KARLSTEJN) ---" << endl;
        cout << "1. Utok mecem" << endl;
        cout << "2. Kriticky zasah (10 many)" << endl;
        cout << "Tva volba: ";
        cin >> akce;

        if (akce == 1) {
            boss2Hp -= utok;
            cout << "Zasahl jsi Kastelana mecem za " << utok << " dmg." << endl;
        }
        else if (akce == 2) {
            if (mana >= 10) {
                mana -= 10;
                int ultraDmg = utok * 2 + 10;
                boss2Hp -= ultraDmg;
                cout << "Tvuj magicky blesk rozrazil stiny kaple a zasahl Kastelana za " << ultraDmg << " dmg!" << endl;
            }
            else {
                cout << "Nemas dost many! Jen jsi promachl." << endl;
            }
        }

        cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << boss2Jmeno << " [" << boss2Hp << " HP]" << endl;

        if (boss2Hp > 0) {
            hp -= boss2Utok;
            cout << endl << boss2Jmeno << " te sekl hradni halapartnou za " << boss2Utok << " dmg!" << endl;
            cout << ">> STAV: " << jmeno << " [" << hp << " HP | " << mana << " Mana] vs " << boss2Jmeno << " [" << boss2Hp << " HP]" << endl;
        }
    }

    if (hp <= 0) {
        cout << "Zly Kastelan te shodil z hradeb. HRA KONCI." << endl;
        return 0;
    }
    else {
        cout << endl << "==================================================================" << endl;
        cout << "   VITEZSTVI! Karlstejn byl uspesne dobyt a osvobozen!" << endl;
        cout << "==================================================================" << endl;
        cout << "Zly Kastelan pada na kolena a ty prebiras klice od celeho hradu." << endl;
    }
    return 0;
}