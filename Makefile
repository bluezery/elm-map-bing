PREF = /usr/local/lib/elementary/modules
POST = linux-gnu-i686-1.0.0
DIR = /usr/local/lib/elementary/modules/dir/linux-gnu-i686-1.0.0
TARGET = module.so
SRCS = bing_aerial bing_aerial_road bing_road

all:
	gcc -c util.c
	for src in $(SRCS); do\
		gcc -c -fPIC $$src.c util.c `pkg-config --cflags elementary` && \
		gcc -shared  -Wl,-z,defs -Wl,-soname,$$src.so -o $$src.so  $$src.o util.o -Wl,--as-needed `pkg-config --libs elementary`;\
	done

install:
	for src in $(SRCS); do\
		test -z $(PREF)/$$src/$(POST)/ || mkdir -p $(PREF)/$$src/$(POST)/ && install $$src.so $(PREF)/$$src/$(POST)/module.so;\
		done

clean:
	rm -rf *.o *.so
