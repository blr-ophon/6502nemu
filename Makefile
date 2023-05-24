CC = gcc
OPT = -O2
CFLAGS = -std=c2x -fPIC -g -Wall -Wextra -pedantic $(OPT)

INCLUDES= -I ./include

CFILES_DIR := ./src
BUILD_DIR := ./build

CFILES := $(wildcard ./src/*.c)
CFILES := $(filter-out src/test.c, $(CFILES))
OBJECTS := $(CFILES:$(CFILES_DIR)/%.c=$(BUILD_DIR)/%.o)

MERGED_OBJECT := ./6502nemu.o
EXEC := ./6502nemutest
DLIB := ./6502.so

all: ${EXEC}

${EXEC}: ${MERGED_OBJECT}
	gcc ${CFLAGS} ${INCLUDES} $^ -o $@

${MERGED_OBJECT}: ${OBJECTS}
	ld -r -o $@ $^

${BUILD_DIR}/%.o: ${CFILES_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) ${CFLAGS} ${INCLUDES} -c $< -o $@


lib: ${MERGED_OBJECT}
	${CC} -shared -o ${DLIB} $^ ${CFLAGS}

clean:
	rm -rf ${OBJECTS}
	rm -rf ${EXEC}
	rm -rf ${MERGED_OBJECT}

testleak: ${EXEC}
	valgrind --leak-check=full --show-leak-kinds=all ./$^ ./tests/TST8080.COM

testrom-all: testrom1 testrom2 testrom3

testrom1: ${EXEC} 
	./$< ./tests/TST8080.COM 

testrom2: ${EXEC}
	./$< ./tests/8080PRE.COM

testrom3: ${EXEC}
	./$< ./tests/8080EXM.COM

debug: ${EXEC}
	cgdb --args ./$< ./tests/TST8080.COM
