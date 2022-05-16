#Confg, just variables, These allow us to
#1. have quick access to comands we may need
#2. change any of the comands in one spot and not hunt down locatoins
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

#This will make a list of all the .c files locaions 
#also uses the wildcard comand wich lets us find all files and use them
C_SRCS := \
	$(wildcard *.c) \
	$(wildcard src/*.c) \
	$(wildcard src/**/*.c)
# simmialr to the above statment but this will make a list of all
# .h file locaitons for use when formin.o files
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)

#This will change our .c files to .o and will add bin/ to it so we can file
# it at a later point. This will also be used to compile files
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# This is the default call like make
# it will activate the rest of the code by calling build
all: build
	@echo "All Done"

#This will call for the list of OBJS and then compile it using our
# above mentioned flags
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

#This will make a directory to hold the .o functions and move them
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# This will make a directory to hold the .o fuctions created from the 
# src folder and move them to the bin directory that was made.
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# This will just use the rm comand to remove the executable
# then the bin file
clean:
	rm -f $(TARGET)
	rm -rf bin
#This is what needs to be changed depending on the codes that
# is bing tested. This particular will run the exicutable and 
# add the needed ppm files
run: build
	./$(TARGET) secret.ppm key decrypt.ppm

#This will just use echo to show what are inside the lists
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

tar:
	tar -czvf FaulkLab7.tar.gz *
