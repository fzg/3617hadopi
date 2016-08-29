PRG = lol
SRC = main.c commands.c globals.c
CFLAGS = -g -Wall -Wextra -lreadline

re : fclean $(PRG)

fclean : clean
	-@ rm $(PRG)

clean :
	-@ rm *~ *.o

$(PRG):
	$(CC) -o $(PRG) $(SRC) $(CFLAGS)
