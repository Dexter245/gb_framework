
CC=$(GBDKDIR)bin/lcc
BIN_RELEASE=bin/release.gb
BIN_DEBUG=bin/debug.gb
SRC=src/main.c src/gfx.c src/sound.c src/timer.c src/input.c src/log.c
#TILES=src/tiles/white.c src/tiles/light_grey.c src/tiles/dark_grey.c src/tiles/black.c
TILES=src/tiles/colorRects.c

release: $(SRC)
	$(CC) -o $(BIN_RELEASE) $(SRC) $(TILES)

run_release: release
	gvba $(BIN_RELEASE)

debug: $(SRC)
	$(CC) -Wf-debug -o $(BIN_DEBUG) $(SRC) $(TILES)

run_debug: debug
	gvba $(BIN_DEBUG)

clean:
	rm $(BIN_RELEASE) $(BIN_DEBUG)

#debug: 





