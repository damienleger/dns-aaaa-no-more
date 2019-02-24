C=gcc
CFLAGS=-fPIC -Wall
LDFLAGS=-shared -Wl,-soname,getaddrinfo.so
LDLIBS=-ldl

default: getaddrinfo.so

%.so: %.o
	$(CC) $(LDFLAGS) -o $@ $< $(LDLIBS)

clean:
	rm -f *.so *.o
