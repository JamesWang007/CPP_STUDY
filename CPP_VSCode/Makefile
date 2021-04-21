# -include include/a.mk 
# VPATH=src:include
vpath %.cpp src
# vpath %.cpp  	# cancel %.cpp 
vpath 			# cancel all
vpath %.cpp src:include


GPP = g++
MAIN = helloworld.cpp
DEPENDENCIES = helloworld.cpp Swap.cpp Calculator.cpp
TARGET = test
INCLUDE = -Iinclude

$(TARGET):$(DEPENDENCIES)
	$(GPP) -g $^ -Iinclude -o $@

# g++ -MM helloworld -Iinclude
# $(GPP) -g $^ -o $@

.PHONY:
clean:
	rm -rf $(TARGET) *.o *.exe

