OS := $(shell uname -s)

ifeq ($(OS),Windows_NT)
    RM = del /f /q
    EXEC_EXT = .exe
    NULL_DEVICE = nul
else
    RM = rm -f
    EXEC_EXT =
    NULL_DEVICE = /dev/null
endif

CC = gcc
CFLAGS = -Wall

INPUT = Input.c
OUTPUT = Output.c
HEADERS = wincalc.h
EXEC1 = input$(EXEC_EXT)
EXEC2 = output$(EXEC_EXT)

.PHONY: all clean run loop watch

all: $(EXEC1) $(EXEC2)

$(EXEC1): $(INPUT) $(HEADERS)
	$(CC) $(CFLAGS) $(INPUT) -o $(EXEC1)

$(EXEC2): $(OUTPUT) $(HEADERS)
	$(CC) $(CFLAGS) $(OUTPUT) -o $(EXEC2)

run:
	@echo "MyCalc [Version 1.1.0]"
	@echo "(c) Wilson Corporation. All rights reserved."
	@echo "---------------------------------------------"
	@$(MAKE) loop

loop:
	@while true; do \
		$(CC) $(CFLAGS) $(INPUT) -o $(EXEC1); \
		./$(EXEC1); \
		if [ -f exit_marker.txt ]; then \
			$(RM) exit_marker.txt > $(NULL_DEVICE) 2>&1; \
			$(MAKE) clean; \
			break; \
		fi; \
		$(CC) $(CFLAGS) $(OUTPUT) -o $(EXEC2); \
		if [ $$? -ne 0 ]; then \
			continue; \
		fi; \
		./$(EXEC2); \
	done

watch:
	ls *.c *.h Makefile | entr -c make run

clean:
	$(RM) $(EXEC1) $(EXEC2) win.h exit_marker.txt > $(NULL_DEVICE) 2>&1
