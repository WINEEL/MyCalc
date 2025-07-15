# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Source files
INPUT = Input.c
OUTPUT = Output.c
HEADERS = wincalc.h

# Executable names
EXEC1 = input
EXEC2 = output

# Default rule: build both executables
all: $(EXEC1) $(EXEC2)

$(EXEC1): $(INPUT) $(HEADERS)
	$(CC) $(CFLAGS) $(INPUT) -o $(EXEC1)

$(EXEC2): $(OUTPUT) $(HEADERS)
	$(CC) $(CFLAGS) $(OUTPUT) -o $(EXEC2)

# Run the REPL loop
run:
	@echo "MyCalc [Version 1.1.0]"
	@echo "(c) Wilson Corporation. All rights reserved."
	@echo "---------------------------------------------"
	@$(MAKE) loop

# Loop REPL until exit_marker.txt is created
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

# Clean up generated files
clean:
	rm -f $(EXEC1) $(EXEC2) win.h exit_marker.txt
