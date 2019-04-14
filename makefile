all:
	cc argsReader.c -c
	cc arrayCreator.c -c
	cc txtCreator.c -c
	cc pngCreator.c -c
	cc nextGen.c -c
	cc genGenerator.c -c
	cc main.c arrayCreator.o pngCreator.o txtCreator.o argsReader.o genGenerator.o  nextGen.o -lpng
	
TestPNG:
	cc TEST_pngCreator.c arrayCreator.o pngCreator.o -lpng

TestArgs:
	cc TEST_argsReader.c argsReader.o

TestArray:
	cc TEST_arrayCreator.c arrayCreator.o

TestTxt:
	cc TEST_txtCreator.c txtCreator.o

TestNextGen:
	cc TEST_nextGen.c nextGen.o

TestGenGenerator:
	cc TEST_genGenerator.c genGenerator.o nextGen.o
