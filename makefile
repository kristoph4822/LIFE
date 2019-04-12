all:
	cc argsReader.c -c
	cc arrayCreator.c -c
	cc txtCreator.c -c
	cc pngCreator.c -c
	cc nextGen.c -c
	cc genGenerator.c -c
	cc main.c arrayCreator.o pngCreator.o txtCreator.o argsReader.o genGenerator.o  nextGen.o -lpng
	
pngCreator test:
	cc TEST_pngCreator.c arrayCreator.o pngCreator.o -lpng
