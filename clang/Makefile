libprogress.a:	src/progress.o
	ar r $@ src/progress.o

testProgress:	test/testProgress.cc src/progress.o
	g++-8 -o $@ src/progress.o test/testProgress.cc \
	-lgtest -lgtest_main -lpthread \
	&& ./$@

# --

progress.o:	src/progress.cc
	g++-8 src/progress.cc -c -o src/$@

# --

clean:
	rm -f src/progress.o testProgress
