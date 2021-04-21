vpath %.cpp src

TAR = test
MAIN = main.cpp STL_TEST.cpp 
GPP = g++

# # Linking
# $(TAR) : main.o
# 	$(GPP) main.o -o $(TAR)

# # Assembling
# main.o : main.s
# 	$(GPP) -c main.s -o main.o

# # Compling
# main.s : main.i
# 	$(GPP) -S main.i -o main.s

# # Pre-Processing
# main.i : $(MAIN)
# 	$(GPP) -E main.cpp -Iinclude -o main.i 




$(TAR) : $(MAIN)
	$(GPP)  -g $^ -Iinclude -Wall -std=c++17 -o $@ 



.PHONY:clean
clean:
	rm -rf *.i *.s *.o *.exe $(TAR)