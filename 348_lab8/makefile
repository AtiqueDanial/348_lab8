CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra -pedantic

# Binaries
TASK1 = task1_nfl_scores
TASK2 = task2_temp_convert

all: $(TASK1) $(TASK2)

$(TASK1): task1_nfl_scores.c
	$(CC) $(CFLAGS) -o $(TASK1) task1_nfl_scores.c

$(TASK2): task2_temp_convert.c
	$(CC) $(CFLAGS) -o $(TASK2) task2_temp_convert.c

clean:
	$(RM) $(TASK1) $(TASK2)
