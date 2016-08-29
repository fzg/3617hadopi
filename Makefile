PRG = newtest
SRC = main.c welcome.c util.c auth.c ad.c

CFLAGS = -g -Wall -Wextra -DTELNET

all    : clean $(PRG)

re     : fclean all

clean  :
	-rm  *~ *.o

fclean :
	-rm $(PRG) tmg

$(PRG) :
	$(CC) -lnewt $(SRC) -o $(PRG) $(CFLAGS)
	$(CC) tmg.c -o tmg
