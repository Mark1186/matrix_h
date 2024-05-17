FLAGS = -Wall -Werror -Wextra -std=c11 -g
OS := $(shell uname)
SOURCE = s21_matrix.c
TEST = s21_test_matrix.c

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURSE
endif

ifeq ($(OS),Darwin)
	OPEN_CMD = open
	ADD_LIB = -lcheck
endif

all: s21_matrix.a test gcov_report

test: s21_matrix.a
	gcc $(FLAGS) $(TEST) s21_matrix.a -o test $(ADD_LIB)
	./test

s21_matrix.a:
	gcc -c $(FLAGS) $(SOURCE)
	ar rcs s21_matrix.a *.o

gcov_report:
	gcc --coverage $(SOURCE) $(TEST) -o test $(ADD_LIB)
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html

clean:
	rm -f test
	rm -f *.gc*
	rm -f s21_test.info
	rm -rf report
	rm -f *.o *.a

clean_gc:
	rm -f *.gc* *.o *.info test

format:
	clang-format -style=Google -n *.c *.h
