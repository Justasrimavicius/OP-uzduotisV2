# Failu naudojimo instrukcijos yra konsoleje, paleidziant faila.

# Failas testuoja deque, vector ir list konteinerius naudojantis 2 optimizavimo budais.
rusiavimoOptimizavimas:
	g++ -std=c++11 functions.cpp compareFunctions.cpp rusiavimoOptimizavimas.cpp -O3 -o run && ./run

# Failas palygina deque, vector ir list tipo konteineriu sparta ivairiuose situacijose.
greicioAnalize:
	g++ -std=c++11 functions.cpp compareFunctions.cpp greicioAnalize.cpp  -o run && ./run

# Failas atlieka tik vector tipo greicio analize.
compare:
	g++ -std=c++11 functions.cpp compareFunctions.cpp compare.cpp -o run && ./run

# Failas generuoja studentu failus.
testGenerator:
	g++ -std=c++11 functions.cpp compareFunctions.cpp testGenerator.cpp -o run && ./run

uzduotisVEKTORIAI:
	g++ -std=c++11 functions.cpp uzduotisVEKTORIAI.cpp -o run && ./run

clean:
	rm -f run studentai1000.txt studentai10000.txt studentai100000.txt studentai1000000.txt studentai10000000.txt studentai1000geri.txt studentai10000geri.txt studentai100000geri.txt studentai1000000geri.txt studentai10000000geri.txt studentai1000blogi.txt studentai10000blogi.txt studentai100000blogi.txt studentai1000000blogi.txt studentai10000000blogi.txt run test


