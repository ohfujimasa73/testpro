CFLAGS     = -g -c -o
CC         = gcc
NAMESOBJ   = button_main.o button_getdata.o button_out.o
NAMESDOBJ  = button_main_d.o button_getdata_d.o button_out_d.o
NAMESEXE   = button.exe
NAMESDEXE  = button_debug.exe

.PHONY: all
all: $(NAMESEXE)
$(NAMESEXE): $(NAMESOBJ)
	$(CC) -o $(NAMESEXE) $(NAMESOBJ)
	ls -al
	echo "NORMAL BUILD END"
button_main.o: button_main.c common.h
	$(CC) -c button_main.c
button_out.o: button_out.c button_out.h common.h
	$(CC) -c button_out.c
button_getdata.o: button_getdata.c button_getdata.h common.h
	$(CC) -c button_getdata.c

.PHONY: debug
debug: $(NAMESDEXE)
$(NAMESDEXE): $(NAMESDOBJ)
	$(CC) -o $(NAMESDEXE) $(NAMESDOBJ)
	ls -al
	echo "DEBUG BUILD END"
button_main_d.o: button_main.c common.h
	$(CC) $(CFLAGS) button_main_d.o button_main.c 
button_out_d.o: button_out.c button_out.h common.h
	$(CC) $(CFLAGS) button_out_d.o button_out.c
button_getdata_d.o: button_getdata.c button_getdata.h common.h
	$(CC) $(CFLAGS) button_getdata_d.o button_getdata.c

.PHONY: clean
clean:
	rm -rf $(NAMESOBJ) $(NAMESEXE) $(NAMESDEXE) $(NAMESDOBJ)
	echo "CLEAN END"