PROG = hexdumpExample

all: $(PROG)

$(PROG): example.cpp Hexdump.hpp
	g++ -Wall --pedantic -std=c++14 -o $@ $<

clean:
	rm -f $(PROG)
