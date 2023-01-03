flag=-Wall -Wextra -Werror
grep=grep/
grep_f=grep/test_folder/
cat=cat/
cat_f=cat/test_folder/

OS = $(shell uname)

all: build

build: s21_grep s21_cat

s21_cat: s21_cat.o
	gcc $(flag) $(cat)$^ -o $(cat)$@

s21_cat.o:
	gcc -c $(flag) $(cat)s21_cat.c -o $(cat)$@

s21_grep: s21_grep.o
	gcc $(flag) $(grep)$^ -o $(grep)$@

s21_grep.o:
	gcc -c $(flag) $(grep)s21_grep.c -o $(grep)$@

clean: clean_grep clean_cat

test: test_grep test_cat

test_cat: clean_cat s21_cat
	mkdir $(cat_f)
# Без флага 
	./$(cat)s21_cat $(cat)text1 > $(cat_f)test1 && cat $(cat)text1 > $(cat_f)test2 && diff $(cat_f)test1 $(cat_f)test2
	./$(cat)s21_cat $(cat)text1 $(cat)text3 > $(cat_f)test3 && cat $(cat)text1 $(cat)text3 > $(cat_f)test4 && diff $(cat_f)test3 $(cat_f)test4
	./$(cat)s21_cat $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test23 && cat $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test24 && diff $(cat_f)test23 $(cat_f)test24
# Флаг -n
	./$(cat)s21_cat -n $(cat)text1 $(cat)text3 > $(cat_f)test5 && cat -n $(cat)text1 $(cat)text3 > $(cat_f)test6 && diff $(cat_f)test5 $(cat_f)test6
# Флаг -v
	./$(cat)s21_cat -v $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test9 && cat -v $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test10 && diff $(cat_f)test9 $(cat_f)test10
	./$(cat)s21_cat -ve $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test11 && cat -ve $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test12 && diff $(cat_f)test11 $(cat_f)test12
	./$(cat)s21_cat -vn $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test13 && cat -vn $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test14 && diff $(cat_f)test13 $(cat_f)test14
# Флаг -e
	./$(cat)s21_cat -e $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test15 && cat -e $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test16 && diff $(cat_f)test15 $(cat_f)test16
# Флаг -t
	./$(cat)s21_cat -t $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test19 && cat -t $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test20 && diff $(cat_f)test19 $(cat_f)test20
# Флаг -b в чем разница между n
	./$(cat)s21_cat -b $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test23 && cat -b $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test24 && diff $(cat_f)test23 $(cat_f)test24
# Флаг -s
	./$(cat)s21_cat -s $(cat)text1 $(cat)text3 $(cat)text4 $(cat)text5 $(cat)text6 > $(cat_f)test27 && cat -s $(cat)text1 $(cat)text3 $(cat)text4 $(cat)text5 $(cat)text6 > $(cat_f)test28 && diff $(cat_f)test27 $(cat_f)test28
# Комбо флагс
	./$(cat)s21_cat -sbvnet $(cat)text1 $(cat)text3 $(cat)text4 $(cat)text5 $(cat)text6 > $(cat_f)test31 && cat -sbvnet $(cat)text1 $(cat)text3 $(cat)text4 $(cat)text5 $(cat)text6 > $(cat_f)test32 && diff $(cat_f)test31 $(cat_f)test32
	./$(cat)s21_cat -snt $(cat)text1 $(cat)text3 $(cat)text4 $(cat)text5 $(cat)text6 > $(cat_f)test33 && cat -snt $(cat)text1 $(cat)text3 $(cat)text4 $(cat)text5 $(cat)text6 > $(cat_f)test34 && diff $(cat_f)test33 $(cat_f)test34
	./$(cat)s21_cat $(cat)text1 $(cat)text3 $(cat)text4 -t -e > $(cat_f)test37 && cat -t -e $(cat)text1 $(cat)text3 $(cat)text4 > $(cat_f)test38 && diff $(cat_f)test37 $(cat_f)test38
ifeq ($(OS), Linux)
	./$(cat)s21_cat --number $(cat)text1 $(cat)text3 > $(cat_f)test7 && cat --number $(cat)text1 $(cat)text3 > $(cat_f)test8 && diff $(cat_f)test7 $(cat_f)test8
	./$(cat)s21_cat -E $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test17 && cat -E $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test18 && diff $(cat_f)test17 $(cat_f)test18
	./$(cat)s21_cat -T $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test21 && cat -T $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test22 && diff $(cat_f)test21 $(cat_f)test22
	./$(cat)s21_cat --number-nonblank $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test25 && cat --number-nonblank $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test26 && diff $(cat_f)test25 $(cat_f)test26
	./$(cat)s21_cat --squeeze-blank $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test29 && cat --squeeze-blank $(cat)text1 $(cat)text3 $(cat)text4> $(cat_f)test30 && diff $(cat_f)test29 $(cat_f)test30
	./$(cat)s21_cat -b $(cat)text1 -e $(cat)text3 -t dfgdg $(cat)text4 -t $(cat)text5 $(cat)text6 > $(cat_f)test35 && cat -b $(cat)text1 -e $(cat)text3 -t $(cat)text4 -t $(cat)text5 $(cat)text6 > $(cat_f)test36 && diff $(cat_f)test35 $(cat_f)test36
endif


clean_cat:
	rm -rf $(cat)*.o $(cat)a.out $(cat)s21_cat $(cat_f)

clean_grep:
	rm -fr $(grep)*.o $(grep)a.out $(grep)s21_grep $(grep_f)

test_grep: clean_grep s21_grep
	mkdir $(grep_f)
	
# без флагов --------------------
	./$(grep)s21_grep P $(grep)text1 > $(grep_f)test1 && grep P $(grep)text1 > $(grep_f)test2 && diff $(grep_f)test1 $(grep_f)test2
# флаг -v 
	./$(grep)s21_grep -v P $(grep)text1 > $(grep_f)test3 && grep -v P $(grep)text1 > $(grep_f)test4 && diff $(grep_f)test3 $(grep_f)test4
# флаг -n
	./$(grep)s21_grep -n P $(grep)text1 > $(grep_f)test5 && grep -n P $(grep)text1 > $(grep_f)test6 && diff $(grep_f)test5 $(grep_f)test6
# флаг -i
	./$(grep)s21_grep -i P $(grep)text1 > $(grep_f)test7 && grep -i P $(grep)text1 > $(grep_f)test8 && diff $(grep_f)test7 $(grep_f)test8
# флаг -с 
	./$(grep)s21_grep -c P $(grep)text1 > $(grep_f)test9 && grep -c P $(grep)text1 > $(grep_f)test10 && diff $(grep_f)test9 $(grep_f)test10
# флаг -l  
	./$(grep)s21_grep -l P $(grep)text1 > $(grep_f)test11 && grep -l P $(grep)text1 > $(grep_f)test12 && diff $(grep_f)test11 $(grep_f)test12
# флаг -o
	./$(grep)s21_grep -o Pyt $(grep)text1 > $(grep_f)test13 && grep -o Pyt $(grep)text1 > $(grep_f)test14 && diff $(grep_f)test13 $(grep_f)test14
# Флагc
	./$(grep)s21_grep -i Pyt -i $(grep)text1 -i > $(grep_f)test13 && grep -i Pyt -i $(grep)text1 -i > $(grep_f)test14 && diff $(grep_f)test13 $(grep_f)test14
# Несколько файлов
	./$(grep)s21_grep Pyt $(grep)text1 $(grep)text2 > $(grep_f)test15 && grep Pyt $(grep)text1 $(grep)text2 > $(grep_f)test16 && diff $(grep_f)test15 $(grep_f)test16
	./$(grep)s21_grep -i Pt -i $(grep)text1 -i -i $(grep)text2 -i > $(grep_f)test17 && grep -i Pt -i $(grep)text1 -i -i $(grep)text2 -i > $(grep_f)test18 && diff $(grep_f)test17 $(grep_f)test18
	./$(grep)s21_grep -v Pt -v $(grep)text1 -v -v $(grep)text2 -v > $(grep_f)test19 && grep -v Pt -v $(grep)text1 -v -v $(grep)text2 -v > $(grep_f)test20 && diff $(grep_f)test19 $(grep_f)test20
	./$(grep)s21_grep -n Pt -n $(grep)text1 -n -n $(grep)text2 -n > $(grep_f)test21 && grep -n Pt -n $(grep)text1 -n -n $(grep)text2 -n > $(grep_f)test22 && diff $(grep_f)test21 $(grep_f)test22
	./$(grep)s21_grep -c Pt -c $(grep)text1 -c -c $(grep)text2 -c > $(grep_f)test23 && grep -c Pt -c $(grep)text1 -c -c $(grep)text2 -c > $(grep_f)test24 && diff $(grep_f)test23 $(grep_f)test24
	./$(grep)s21_grep -l Pt -l $(grep)text1 -l -l $(grep)text2 -l > $(grep_f)test25 && grep -l Pt -l $(grep)text1 -l -l $(grep)text2 -l > $(grep_f)test26 && diff $(grep_f)test25 $(grep_f)test26
	./$(grep)s21_grep -o Pt -o $(grep)text1 -o -o $(grep)text2 -o > $(grep_f)test27 && grep -o Pt -o $(grep)text1 -o -o $(grep)text2 -o > $(grep_f)test28 && diff $(grep_f)test27 $(grep_f)test28
	./$(grep)s21_grep -h Pt -h $(grep)text1 -h -h $(grep)text2 -h > $(grep_f)test35 && grep -h Pt -h $(grep)text1 -h -h $(grep)text2 -h > $(grep_f)test36 && diff $(grep_f)test35 $(grep_f)test36

# флаг -e 
	./$(grep)s21_grep -e Pyt -e Pt $(grep)text1 ttt $(grep)text2 -e pp > $(grep_f)test29 && grep -e Pyt -e Pt $(grep)text1 $(grep)text2 -e pp > $(grep_f)test30 && diff $(grep_f)test29 $(grep_f)test30
	./$(grep)s21_grep -e Pyt -e Pt $(grep)text1 -e pp > $(grep_f)test31 && grep -e Pyt -e Pt $(grep)text1 -e pp > $(grep_f)test32  && diff $(grep_f)test31 $(grep_f)test32
# флаг -s
	./$(grep)s21_grep -s Pyt -s $(grep)text1 ttt $(grep)text2 -s > $(grep_f)test29 && grep -s Pyt -s $(grep)text1 $(grep)text2 -s > $(grep_f)test30 && diff $(grep_f)test29 $(grep_f)test30

# флаг -f
	./$(grep)s21_grep -f $(grep)pattern.txt $(grep)text1 $(grep)text2 > $(grep_f)test33 && grep -f $(grep)pattern.txt $(grep)text1 $(grep)text2 > $(grep_f)test34 && diff $(grep_f)test33 $(grep_f)test34

