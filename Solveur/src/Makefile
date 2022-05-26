mot:

arbre:

pattern:
		clang -c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls pattern.c
		clang -c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls test_pattern.c
		clang -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls pattern.o mot.o arbre.o test_pattern.o -o test_pattern

main:

clean_mot:

clean_arbre:

clean_pattern:
		rm pattern.o
		rm test_pattern.o
		rm test_pattern

clean_main: