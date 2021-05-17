CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = sdl2-light.h sdl2-ttf-light.h constantes.h world.h graphic.h events.h
SRC = main.c sdl2-light.c sdl2-ttf-light.c world.c graphic.c events.c
OBJ = $(SRC:%.c=%.o)
TESTS = tests.c world.c events.c
TESTS_OBJ = $(TESTS:%.c=%.o)
PROG = spacecorridor

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

spacecorridor: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o *.exe $(PROG)
	rm -rf latex html

tests: $(TESTS_OBJ)
	gcc $(CFLAGS) $(TESTS_OBJ) $(LDFLAGS) -o $@
