INCLUDES = -Iinclude -I/usr/include/python2.7
LIBS = -lpython2.7 -lpthread -ldl -lutil
LIB_DIRS = 
\
CC = g++
CFLAGS = -Xlinker -export-dynamic  -fPIC -Wall


BUILDDIR = build
SRCDIR = src
OBJDIR = objs

OUTPUT_FILE = libpython_plugin.so
INSTALL_DIR = ../ts3client/plugins
AFTER_INSTALL = 

PYTHON_FOLDER = python


OUTPUT = $(BUILDDIR)/$(OUTPUT_FILE)

SRCS:=$(shell find $(SRCDIR) -iname *.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS)) 

include makefile.override

all: $(OUTPUT)

autogen:
	cd scripts;	python main.py;	cd ..

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(OUTPUT): $(BUILDDIR) $(OBJS)
	$(CC) $(OBJS) $(LIB_DIRS) $(LIBS) $(CFLAGS) -shared -o $(OUTPUT)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OBJDIR)

install: install_scripts install_plugin
	$(AFTER_INSTALL)

install_scripts:
	cp -r $(PYTHON_FOLDER) $(INSTALL_DIR)

install_plugin:
	cp $(OUTPUT) $(INSTALL_DIR)

makefile.override: