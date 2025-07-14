CC=gcc
CFLAGS=-Wall
INPUT=Input.c
OUTPUT=Output.c
HEADERS=wincalc.h
EXEC1=input
EXEC2=output

.PHONY: all clean run loop

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
			rm -f exit_marker.txt; \
			$(MAKE) clean; \
			break; \
		fi; \
		$(CC) $(CFLAGS) $(OUTPUT) -o $(EXEC2); \
		if [ $$? -ne 0 ]; then \
			continue; \
		fi; \
		./$(EXEC2); \
	done

clean:
	rm -f $(EXEC1) $(EXEC2) win.h exit_marker.txt
