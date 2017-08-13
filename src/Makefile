all:
	gcc -g -o kata8 main.c -L. libvector.a

test: all
	./maintest.tcl ./kata8 

clean:
	rm kata8