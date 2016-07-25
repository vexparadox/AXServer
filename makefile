program_NAME := CFServer
lib_NAME := libcf
program_CXX_SRCS := $(wildcard cfsrc/*.cpp)
program_CXX_SRCS += $(shell find serversrc/ -type f -name '*.cpp')
program_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_INCLUDE_DIRS := $(shell echo ./serversrc/**/)
program_HEADERS := $(foreach directory, $(program_INCLUDE_DIRS), -I$(directory))
program_LIBRARY_DIRS := lib/
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	program_LIBRARIES := enetLinux
endif
ifeq ($(UNAME), Darwin)
	program_LIBRARIES := enetOSX
endif



CPPFLAGS += -std=c++11 $(program_HEADERS) -Wno-c++11-extensions -Wno-c++11-compat-deprecated-writable-strings -Wno-return-stack-address -pthread
LDFLAGS +=  $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir)) -pthread
LIBRARIES += $(foreach library,$(program_LIBRARIES),-l$(library)) 

.PHONY: all clean distclean

all: $(program_NAME) run

lib: $(lib_NAME)

run:
	./$(program_NAME)
	
$(lib_NAME): $(program_OBJS)
	ar rsc $(lib_NAME).a $(program_OBJS)

$(program_NAME): $(program_OBJS)
	g++ $(LDFLAGS) $(program_OBJS) -o $(program_NAME) $(LIBRARIES)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean
