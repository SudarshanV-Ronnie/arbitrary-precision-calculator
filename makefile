OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))
apc.exe:$(OBJ)
	gcc -o $@ $^
%.o:%.c
	gcc -c $<
clean:
	rm *.exe *.o