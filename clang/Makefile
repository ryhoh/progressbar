libprogress.a:	progress.o
	ar r $@ progress.o

test:	test.cc progress.o
	g++-8 -o $@ progress.o -lgtest -lgtest_main -lpthread test.cc && ./test

# --

progress.o:	progress.cc
	g++-8 progress.cc -c

# --

clean:
	rm -f progress.o test
