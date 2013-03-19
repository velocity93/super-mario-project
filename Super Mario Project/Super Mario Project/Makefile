########################################################################
## Makefile
## Super Mario Project
## Lionel Joseph lionel.r.joseph@gmail.com
## Olivier Guittonneau openmengine@gmail.com
########################################################################

#CXX=g++ -std=c++0x
#CXX=LC_ALL=en_US.UTF-8 colorgcc -std=c++0x
CXX=clang++ -std=c++11

CXXWARN=-Wall -Wextra \
-fno-common -Wformat=2 -Winit-self -Winline \
-Wpacked -Wp,-D_FORTIFY_SOURCE=2 -Wpointer-arith -Wlarger-than-65500 \
-Wmissing-declarations -Wmissing-format-attribute -Wmissing-noreturn \
-Wredundant-decls -Wsign-compare -Wstrict-aliasing=2 -Wswitch-enum \
-Wundef -Wunreachable-code -Wwrite-strings \
-Werror=implicit-function-declaration \
-pedantic #-pedantic-errors

CXXFLAGS=-I/usr/include/libxml2/ -lxml2 -lsfml-window -lsfml-graphics -lsfml-system -lGL -lGLU -Wno-reorder -Wno-newline-eof

all: smp
	@echo "\033[1;32m======[build complete]=======\033[0m"

smp: *.[hc]pp
	$(CXX) $(CXXWARN) *.cpp -o smp $(CXXFLAGS)

clean:
	@rm -rf smp
	@echo "\033[1;32m======[Clean complete]=======\033[0m"

.PHONY: all clean
