NAME = gui_demo
CC = gcc
FWs = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
EXAMPLESRC = core_2d_camera_platformer.c
EXAMPLENAME = edemo
EXAMPLEOBJ = $(foreach file,$(EXAMPLESRC:.c=.o),$(ODIR)/$(file))
SRC = driver.c parse.c destroy.c draw.c images.c
LDIR = library
HDIR = headers
ODIR = objects
SDIR = sources
OBJ = $(foreach file,$(SRC:.c=.o),$(ODIR)/$(file))
INCLUDES = -I../$(HDIR) -I../$(MYLIBDIR)/mylib.h
MYLIBDIR = $(LDIR)/mylib
MYLIB = $(MYLIBDIR)/libmylib.a
LFLAGS = -L$(LDIR) -lraylib -L$(MYLIBDIR) -lmylib

$(NAME): $(OBJ) $(MYLIB)
	$(CC) $(FWs) -o $@ $^ $(LFLAGS)
$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/*
	cd $(ODIR) && $(CC) $(INCLUDES) -c ../$<

$(EXAMPLENAME): $(EXAMPLEOBJ) $(MYLIB)
	$(CC) $(FWs) -o $@ $^ $(LFLAGS)
$(MYLIB):
	$(MAKE) --directory=$(MYLIBDIR)
.PHONY: all clean re fclean fcleanall
clean:
	rm -rf $(ODIR)/*.o
re:
	make fclean
	make all
all: $(NAME)
fclean:
	make clean
	rm -f $(NAME) $(EXAMPLENAME)
fcleanall: fclean
	$(MAKE) fcleanall --directory=$(MYLIBDIR)
example: $(EXAMPLENAME)