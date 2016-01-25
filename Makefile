SRCDIR = ./src
OBJDIR = ./obj
OUTDIR = ./bin

SRCS = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/**/*.cpp)

CXX = g++
CXXFLAGS = `python3-config --includes` -std=c++14 -g

LDFLAGS = `python3-config --ldflags` -lgur

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
