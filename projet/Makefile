CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

<<<<<<< HEAD
INC = sdl2-light.h constante.h graphique.h monde.h
SRC = main.c sdl2-light.c
=======
INC = sdl2-light.h world.h graphic.h
SRC = main.c sdl2-light.c world.c graphic.c
>>>>>>> e1ce42115a0ab2b2593ae3469e50844a6134c929
OBJ = $(SRC:%.c=%.o)

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

tests: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

