SRCDIR = ./src
OBJDIR = ./obj
OUTDIR = ./bin

PYTHON_INC =# /usr/include/python3.4m
PYTHON_LIBDIR =# /usr/lib/python3.4/config-3.4m-x86_64-linux-gnu
PYTHON_LIB =# python3.4m

LIBGUR_INC =# ../libgur/inc
LIBGUR_LIBDIR =# ../libgur/bin

SRCS = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/**/*.cpp)

CXX = g++
CXXFLAGS = -I$(PYTHON_INC) -I$(LIBGUR_INC) -std=c++14 -g

LDFLAGS = -L$(PYTHON_LIBDIR) -l$(PYTHON_LIB) -L$(LIBGUR_LIBDIR) -lgur

all: gurpy.so

$(OBJDIR)/%.po: $(SRCDIR)/%.cpp
	$(CXX) -fPIC -c -o $@ $< $(CXXFLAGS)

OBJS := $(patsubst %.cpp, %.po, $(SRCS))
OBJS := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJS))

gurpy.so: $(OBJS)
	$(CXX) -shared -o $(OUTDIR)/$@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OUTDIR)/* $(OBJDIR)/*.po $(OBJDIR)/**/*.po
