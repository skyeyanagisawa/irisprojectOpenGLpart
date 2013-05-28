CC = g++
CFLAGS = -Wall #Show all warnings
PROG = sonify 

SRCS = main.cpp iris_data.o graphLoop.o pa_allocation.o front.o pa_unix_util.o pa_debugprint.o\
       pa_ringbuffer.o audio_callback.o pa_unix_hostapis.o init_audiostream.o\
       audio_engine.o

ifeq ($(shell uname),Darwin)
	LIBS = -L/Users/Isaac/realtime/portaudio/lib -L/Users/Isaac/realtime/portaudio/include/ -L/Users/Isaac/realtime/portaudio/src/common
else
#windows stuff here
endif

all: $(PROG)

$(PROG):	$(SRCS)
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(INCLUDE)   $(LIBS) -lportaudio

clean:
	rm -f $(PROG)
