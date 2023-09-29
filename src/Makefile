CC = g++
CFLAGS=-std=c++17 -Wpedantic -Wall -Werror -Wextra -g
SOURCE_FILES = test.cc Model/*.cc Controller/*.cc
COVFLAGS = --coverage
TFLAGS = -lgtest_main -lgcov -lgtest


all: clean uninstall install	

install:
	@mkdir build
	cd build; cmake ..; cmake --build .

uninstall:
	rm -rf build


dist: 
	@mkdir 3D_Viewer_dist
	cp CMakeLists.txt 3D_Viewer_dist
	cp -r Controller 3D_Viewer_dist
	cp -r Model 3D_Viewer_dist
	cp -r View 3D_Viewer_dist
	cp -r Documentation 3D_Viewer_dist
	cp main.cc 3D_Viewer_dist
	cp gif.h 3D_Viewer_dist
	cp Makefile 3D_Viewer_dist
	cp test.cc 3D_Viewer_dist
	tar -czf 3D_Viewer.tar.gz 3D_Viewer_dist/
	rm -rf 3D_Viewer_dist

run:
	open build/3d_viewer.app

test: 
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o test $(TFLAGS)
	./test

gcov_report:
	$(CC) $(GFLAGS) $(COVFLAGS) $(SOURCE_FILES) -L. $(TFLAGS) -o ./htmlreport.out
	./htmlreport.out
	lcov -t "htmlreport" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

check:
	clang-format -n main.cc test.cc View/* Model/* Controller/*
	cppcheck --enable=all --suppress=unusedFunction --suppress=missingInclude --language=c++ test.cc Model/*.cc Controller/*.cc View/*.cc


leakscheck: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

clean:
	rm -rf *.o *.a *.css index.html *.gcno *.gcda *.out *.info test report *.dSYM *.gcov build *.gch 3D_Viewer_dist 3D_Viewer.tar.gz

rebuild: all

.PHONY : dvi clean run test gcov_report install uninstall
