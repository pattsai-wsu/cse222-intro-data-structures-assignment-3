COMPILEFLAGS=
CCOMP=gcc

main: main.o hash.o databaseHandler.o listInit.o listAdd.o listFind.o listLen.o listPrint.o listFree.o
	$(CCOMP) $(COMPILEFLAGS) -o plate main.o hash.o databaseHandler.o listInit.o listAdd.o listFind.o listLen.o listPrint.o listFree.o
main.o: main.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c main.c
hash.o: hash.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c hash.c
databaseHandler.o: databaseHandler.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c databaseHandler.c
listInit.o: listInit.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c listInit.c
listAdd.o: listAdd.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c listAdd.c
listFind.o: listFind.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c listFind.c
listLen.o: listLen.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c listLen.c
listPrint.o: listPrint.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c listPrint.c
listFree.o: listFree.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c listFree.c
clean:
	rm main.o hash.o databaseHandler.o listInit.o listAdd.o listFind.o listLen.o listPrint.o listFree.o plate
