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
