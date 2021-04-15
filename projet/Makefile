CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = sdl2-light.h world.h graphic.h
SRC = main.c sdl2-light.c world.c graphic.c
OBJ = $(SRC:%.c=%.o)
TESTS = world.c tests.c
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
	rm -f *~ *.o $(PROG)
	rm -rf latex html

tests: $(TESTS_OBJ)
	gcc $(CFLAGS) $(TESTS_OBJ) $(LDFLAGS) -o $@