CC=clang
LLVM=/usr/local/opt/llvm
#CC=$(LLVM)/bin/clang
LDFLAGS=-L$(LLVM)/lib 
CPPFLAGS=-I$(LLVM)/include
CFLAGS=-std=c99 -Wall -Wextra -pedantic -fdiagnostics-color=always
CFLAGS+=$(CPPFLAGS) -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls # -DNDEBUG
LDFLAGS+=-fsanitize=address

#RUN_ENV=LSAN_OPTIONS=suppressions=lsan.ignore:print_suppressions=0 ASAN_OPTIONS=detect_leaks=1:symbolize=1 MallocNanoZone=0
#RUN_ENV=ASAN_OPTIONS=detect_leaks=1:symbolize=1
RUN_ENV=

mot : test_mot
	$(RUN_ENV) ./test_mot

test_mot: test_mot.o mot.o arbre.o pattern.o

tes_mot.o: mot.o test_mot.c

mot.o: mot.c



arbre: test_arbre
	$(RUN_ENV) ./test_arbre

test_arbre: test_arbre.o arbre.o mot.o pattern.o

test_arbre.o : arbre.o test_arbre.c

arbre.o : arbre.c 




pattern: test_pattern
	$(RUN_ENV) ./test_pattern

test_pattern: test_pattern.o pattern.o arbre.o

test_pattern.o : pattern.o test_pattern.c arbre.o

pattern.o : pattern.c 



solveur_main_test : solveur_main
	$(RUN_ENV) ./solveur_main

solveur_main : solveur_main.o pattern.o arbre.o mot.o

solveur_main.o : solveur_main.c



algo : test_algo
	$(RUN_ENV) ./test_algo

test_algo : test_algo.o pattern.o arbre.o mot.o

test_algo.o : test_algo.c


clean : 
	rm solveur_main
	rm test_arbre
	rm test_pattern
	rm test_mot
	rm *.o
	rm test_algo