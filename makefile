# Failu naudojimo instrukcijos yra konsoleje, paleidziant faila.

# Failas testuoja deque, vector ir list konteinerius naudojantis 2 optimizavimo budais.
rusiavimoOptimizavimas:
	g++ -std=c++11 functions.cpp compareFunctions.cpp rusiavimoOptimizavimas.cpp -o run.exe && ./run.exe

# Failas palygina deque, vector ir list tipo konteineriu sparta ivairiuose situacijose.
greicioAnalize:
	g++ -std=c++11 functions.cpp compareFunctions.cpp greicioAnalize.cpp -o run.exe && ./run.exe

# Failas atlieka tik vector tipo greicio analize.
compare:
	g++ -std=c++11 functions.cpp compareFunctions.cpp compare.cpp -o run.exe && ./run.exe

# Failas generuoja studentu failus.
testGenerator:
	g++ -std=c++11 functions.cpp compareFunctions.cpp testGenerator.cpp -o run.exe && ./run.exe

clean:
	rm -f run.exe studentai1000.txt studentai10000.txt studentai100000.txt studentai1000000.txt studentai10000000.txt
