CC = gcc
CFLAGS = -Wall
SRC_DIR = /home/poojashree/first/makefile/10_files
OUT_DIR = /home/poojashree/first/makefile/10_files
SRC_FILES = bye.c check_1.c check_2.c end.c hostname.c sample.c \
            traceroute.c traceroute_final.c traceroute_route.c welcome.c
OUT_FILES = $(SRC_FILES:.c=.out)
all: $(OUT_FILES)
%.out: %.c
	$(CC) $(CFLAGS) -o $@ $<



clean:
	rm -f $(OUT_FILES)


.PHONY: all clean
