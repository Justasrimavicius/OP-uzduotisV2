# OP-uzduotis1
Šiame projekte bus padaryta programa, kuri galės:

nuskaityti vardą ir pavardę.
nuskaityti n atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.

Tuomet iš šių duomenų, suskaičiuoti galutinį balą (galutinis):
GALUTINIS = 0.4 * vidurkis + 0.6 * egzaminas.

Kriterijai:
    Turi būti 6 versijos: v0.1, v0.2, v0.3, v0.4, v0.5 ir v1.0. Kiekviena versija turės savo atskirus reikalavius, kurie bus surašyti žemiau.
    Neturi būti kodo klaidų - įvedami blogo tipo duomenys, neįvadami namų darbai, ...





# V0.1
Pagal aprašytus užduoties reikalavimus realizuokite programą, kuri nuskaito vartotojų įvedamus reikiamus duomenis (struktūros elementai):
    studento vardą ir pavardę;
    namų darbų ir egzamino rezultatą;

Baigus duomenų įvedimą, suskaičiuoja galutinį balą ir juos pateikia į ekraną tokiu ar panašiu pavidalu (kur galutinis apskaičiuotas balas pateikiamas dviejų skaičių po kablelio tikslumu):
Pavardė     Vardas      Galutinis(vid./med.)

Čia galutinis rezultatas gali būti skaičiuojamas naudojant namų darbų vidutinį balą arba medianą.

Sukurti 2 atskirus failus(darbartiniu atveju - uzduotisMASYVAI.cpp ir uzduotisVEKTORIAI.cpp) kurie studento namų darbų rezultatų įvedimui naudotų dinaminius masyvus ir vektorius.

# V0.2
Papildykite programos versiją (v0.1) taip, kad būtų galima duomenis ne tik įvesti bet ir nuskaityti iš failo.

Reikalavimai output’ui: studentai turi būti surūšiuoti pagal vardus (ar pavardes) ir visi stulpeliai būtų gražiai "išlygiuoti".

# V0.3
Papildyta V0.2 versija - functions.h faile perkelta strucktura bei rikiavimo algoritmas, prideti try/catch blokai.

# V0.4
Papildyta V0.3 versija - sukurtos šios funkcijos:
    sortStudents() - surikiuoja studentus į atskirus failus pagal jų galutinį balą(< 5 studentai eis į ...blogi.txt, likusieji į ...protingi.txt);
    generateFile() - sukuria failą, kuriame yra tam tikras kiekis studentų su tam tikru kiekiu namų darbų;
Ir šie failai:
    testGenerator.cpp - generuoja testavimo failus.
    greicioAnalize.cpp - atlieka greicio analize(sukuria failus su 1000, 10000, 100000, ... studentų, juos nuskaito, atskiria į skirtingus failus).

# V0.5
Procesoriaus tipas	        Apple M1
Branduoliai	                8
Procesoriaus modelis	    Apple M1 (8 branduolių)

Operatyvioji RAM atmintis	8 GB
Kietasis diskas	            256 GB
Atminties tipas	            SSD

Vaizdo plokštė	            Apple M1
Vaizdo plokštės modelis	    Apple M1 (7 branduolių)

# V1.0
Optimizacijos funkcija, testuojanti vector, list ir deque konteineriu naudojimo sparta.
rusiavimoOptimizavimas.cpp faile galima kurti studentu failus, testuoti vektor konteineri nenaudojant tam skirtu algoritmu ir juos naudojant, bei testuoti deque, list ir vector konteinerius naudojant 2 optimizavimo metodus.

Funkciju paleidimas aprasytas makefile

# V1.1
Struct duomenų tipo pakeitimas į class.
Dauguma funkcijų buvo atnaujintos dėl šių pakeitimų.
Greičio palyginimas - deque struktūra, be funkcijų optimizacijos(rusiavimoOptimizavimas.cpp, 2 optimizacija):
Naudojant klases:

1000        0.01464
10000       1.48135
100000    153.69425

Naudojant struktūras:
1000        0.01664
10000       1.49143
100000    151.95475

Su mažiau duomenų, naudojant klases vietoj struktūrų, klasės yra truputį greitesnės už struktūras(labai minimaliai).

Naudojant -O2 optimizavimą su klasėmis: 

1000        0.00097
10000       0.09486
100000      9.49361

Naudojant optimizaciją, su 1000 duomenų įrašų naudojant O2 optimizaciją ir klases, programa veikia maždaug 15 kartų greičiau.
Naudojant optimizaciją, su 10000 duomenų įrašų naudojant O2 optimizaciją ir klases, programa veikia maždaug 15.5 kartų greičiau.
Naudojant optimizaciją, su 100000 duomenų įrašų naudojant O2 optimizaciją ir klases, programa veikia maždaug 16 kartų greičiau.

Duomenys su 03 optimizacija labai panašūs.


# V1.2
Neaišku, ar gerai suprasta salyga - panaudotos 2 "Rule of five" realizacijos, tačiau ar to užtenka ir ar jos panaudotos tinkamai pasakyti negaliu.

# V1.5
Base klasė Zmogus implementuota - iš jos klasė Studentas paveldi vardo bei pavardės getter ir setter funkcijas. Base klasė Zmogus dėl dummy virtual funckijos negali būti kviečiama atskirai.

# V2.0
Finalinė projekto versija. Padaryta minimali dokumentacija - rodomi failai, jų funkcijos, klasės, trumpas vienos funkcijos aprašymas kaip koncepto suvokimo įrodymas.
Sukurtas testavimo failas test.cpp, naudojantis Catch testavimo biblioketą. Testuojama tik viena funkcija, vėl gi, koncepto suvokimo įrodymui.

# V3.0
std::vector atkartojimas.
Sukurta customVector klasė(customVector.h) ir atliktas jos testavimas.
Keli testavimo atvejai(visi testai matomi testVector.cpp):
    
    Vektoriaus initializavimas:
        customVector<int> vec;
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.empty());

    Elementų gavimas:
        customVector<int> vec = {1, 2, 3, 4, 5};
        REQUIRE(vec.at(0) == 1);
        REQUIRE(vec.at(2) == 3);
        REQUIRE(vec.at(4) == 5);
        REQUIRE(vec.front() == 1);
        REQUIRE(vec.back() == 5);
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[2] == 3);
        REQUIRE(vec[4] == 5);

    push_back(), size(), clear() funckijos:
        customVector<int> myVector;
        myVector.push_back(5);
        myVector.push_back(6);
        myVector.push_back(7);
        myVector.push_back(8);
        myVector.push_back(9);
        REQUIRE(myVector.size() == 5);
        REQUIRE(myVector.back() == 9);
        REQUIRE(myVector.front() == 5);
        vec.clear();
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.empty());

Greičio palyginimas:
    10000       std::vector 0.004s  customVector 0.00015s
    100000      std::vector 0.004s  customVector 0.001s
    1000000     std::vector 0.025s  customVector 0.009s
    10000000    std::vector 0.29s   customVector 0.1s
    100000000   std::vector 2.9s    customVector 1.16s

Perskirtymų kiekis su 100mil. elementų naudojant abu vektorių tipus buvo 27.
    
    