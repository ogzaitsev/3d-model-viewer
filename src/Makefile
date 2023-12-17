UNAME:=$(shell uname -s)
ifeq ($(UNAME), Linux)
LEAKS_CHECK=valgrind --track-origins=yes --tool=memcheck --leak-check=full
OPEN=xdg-open
CPPFLAGS_TEST= -lgtest -lpthread -fprofile-arcs -ftest-coverage
endif
ifeq ($(UNAME), Darwin)
LEAKS_CHECK= leaks --atExit -- 
OPEN=open
CPPFLAGS_TEST= -lgtest -lstdc++ -pthread -fprofile-arcs -ftest-coverage
endif

T_NAME = $(P_NAME)-build-realese-v1.tar.gz
P_NAME = 3dviewer_v2
BUILD_FOLDER=3dviewer/build

all: install

CXX=g++
CPPFLAGS= -g -Wall -Werror -Wextra -std=c++17
SOURCE    = 3dviewer/model/ObjFileReader.cc \
			3dviewer/model/DataBuilder.cc \
			3dviewer/model/TransformContext.cc \
			3dviewer/model/strategy/*.cc 
HEADER    = 3dviewer/model/ObjFileReader.h 3dviewer/model/Data3D.h \
			3dviewer/model/DataBuilder.h \
			3dviewer/model/TransformContext.h \
			3dviewer/model/strategy/*.h 
TEST_OUT = tests/test.out

test:
	$(CXX) $(CPPFLAGS) -g tests/*.cc $(HEADER) $(SOURCE) $(CPPFLAGS_TEST) -o $(TEST_OUT)
	cd tests; ./../$(TEST_OUT)

leaks:
	cd tests; $(LEAKS_CHECK) ./../$(TEST_OUT)

install:
	-cd 3dviewer; qmake -o build/Makefile 3dviewer_v2.pro
	-cd 3dviewer/build; make
.PHONY : install

run:
		3dviewer/build/$(P_NAME)
.PHONY : run

gcov_report: test
	gcov $(SOURCE)
	lcov -t . --no-external -o report.info -c -d .
	genhtml -o report report.info
	$(OPEN) ./report/index.html
	rm -f *.gcno *.gcda
.PHONY : gcov_report

style:
		clang-format -n --style=Google ./3dviewer/*/*.cc ./3dviewer/*/*.h tests/*.cc
.PHONY : style

dvi:
		cd doxygen && doxygen Doxyfile
		$(OPEN) doxygen/html/index.html 2> /dev/null
.PHONY : dvi

dist:
		rm -rf $(BUILD_FOLDER)/$(T_NAME)
		touch $(BUILD_FOLDER)/$(T_NAME)
		tar --exclude=$(BUILD_FOLDER)/$(T_NAME) -zcvf $(BUILD_FOLDER)/$(T_NAME) $(BUILD_FOLDER)
.PHONY : dist

uninstall: clean
	rm -f 3dviewer/build/* 3dviewer/build/.qmake.stash
	rm -f 3dviewer/.qmake.stash
	rm -f 3dviewer/moc_*
	rm -f 3dviewer/$(P_NAME) *.pro.user
	rm -rf report report.info

clean:
	rm -f 3dviewer/*.o 3dviewer/build/*.cpp 3dviewer/build/*.o 3dviewer/build/*.h 3dviewer/3dviewer_v2.pro.user
	rm -f *.gcda *.gcno
	rm -f $(TEST_OUT)
	rm -rf doxygen/html


