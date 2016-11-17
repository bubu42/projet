CC= gcc
CFLAGS = -g -O2 -Wall `pkg-config --cflags MLV`
LDFLAGS = `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS = `pkg-config --libs-only-l MLV`

main : main.c regles_du_jeu.h
	$(CC) $(CFLAGS) $(LDFLAGS) main.c  $(LDLIBS) -o Main

clean :
	rm -f *.o *~  Main *#
