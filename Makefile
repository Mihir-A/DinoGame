# set compiler
CC = g++
# include files
INCLUDE = -I include -I sfml/include
#compilers flags for compiling object files
CFLAGSO = -std=c++17 -m64 -O2 -c ${INCLUDE}
# libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
#compilers flags for compiling binary file
CFLAGSB = -L./sfml/lib -s ${LIBS} 


default: objs
	mkdir -p ./bin
	${CC} ./bin/intermediates/*.o -o ./bin/main ${CFLAGSB}
	cp -r ./res ./bin/res

objs: 
	mkdir -p ./bin/intermediates
	${CC} ./src/*.cpp ${CFLAGSO}
	mv *.o ./bin/intermediates