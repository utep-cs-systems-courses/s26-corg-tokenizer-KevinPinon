OBJS= test.o


CFLAGS=-g -O3 # -g for debug, -O3 for optimization

all: test

test: $(OBJS) 
	cc -o test $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h

clean:
	rm -f *.o test

run:test
	./test
