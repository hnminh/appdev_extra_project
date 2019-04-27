OBJ = main.o screen.o text.o
APPNAME = data.out
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm	# math library is used

%.o : %.c
	gcc -c -o $@ $<

clean : 
	rm $(APPNAME) $(OBJ) wlist.txt

tar:
	tar cf text.tar *.c *.h makefile README
