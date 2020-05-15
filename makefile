src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)
CPPFLAGS=-std=c++11

aob: $(obj)
	$(CXX) -o $@ $^ $(CPPFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) aob
