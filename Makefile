FLAGS = gcc -Wall -Werror -Wextra -std=c11

# подбирает флаги для check в зависимости от системы (мак или линукс)
OS = $(shell uname -s)
ifeq ($(OS), Darwin)
CHECK_FLAGS = -lcheck
else ifeq ($(OS), Linux)
CHECK_FLAGS = -lcheck -lsubunit -lpthread -lrt
endif

all: clean s21_decimal.a test gcov_report

s21_decimal.a:
	gcc -c s21_*.c
	ar rcs s21_decimal.a s21_*.o
	ranlib s21_decimal.a

clean:
	rm -rf *.o *.a *.gch *.gcno *.gcda report/ s21_test.info *.dSYM/

rebuild: clean s21_decimal.a

test: s21_decimal.a
	$(FLAGS) -g --coverage our_tests.c s21_decimal.a -o run_tests.o $(CHECK_FLAGS) -lm
	./run_tests.o

gcov_report:
	gcc our_tests.c s21_*.c -o gcov_test --coverage $(CHECK_FLAGS) -lm
	./gcov_test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report/ s21_test.info
	open ./report/index.html
	rm -rf gcov_test

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c
	clang-format -n *.h
	rm -rf .clang-format

check:
	gcc -g s21*.c test.c -o test

valgrind:
	valgrind --tool=memcheck --leak-check=yes --log-file=valgrind_log  ./run_tests.o
