export make_basedir = ../

#
# Hide command line echo
# Display simple target
#
#CXX32=@echo Build $@ && g++
#CXX32 = clang++
INCLUDE += -I$(make_basedir)thirdpart/lua

src_dbcommon2	:= main.cpp

obj_dbcommon2	:= $(src_dbcommon2:.cpp=.o)
obj_dbcommon2	:= $(obj_dbcommon2:.c=.o)

.SUFFIXES: .o .cpp .c

.cpp.o:
	g++ $(INCLUDE) -Wno-deprecated -c -o $@ $<

#.c.o:
#	$(CXX)  -DONE_SELECTOR_PER_THREAD $(CXXFLAGS) -c -o $@ $<

all: lnode
lnode: $(obj_dbcommon2)
	g++ -o $@ $(LINK_CXXFLAG) $(obj_dbcommon2) -L$(make_basedir)thirdpart/lua -llua -lm -ldl

install:
	install lnode ../bin
clean:
	rm -f *.o
	rm -f *_m
	rm -f $(obj_dbcommon2)

