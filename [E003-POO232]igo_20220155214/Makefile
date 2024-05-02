# Variáveis para os compiladores e as flags do compilador
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Nome do arquivo de saída
OUTFILE = biblioteca

# Arquivos fonte
SRCS = main.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

all: $(OUTFILE)

$(OUTFILE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(OUTFILE) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	rm -f *.o $(OUTFILE)
