# Makefile for Feedback Arc Set (FAS)

include ./Makefile.config

all: $(MAIN)

# COMPILE
$(MAIN): $(MAIN).cpp $(DEPH) $(DEPCPP)
	$(CC) $(CXXFLAGS) -o $(MAIN) $(MAIN).cpp $(DEPCPP) -I$(CORE) $(LDFLAGS) $(LIBS)

clean:
	rm -f *.o $(MAIN) $(MAIN).exe
