INCLUDES = -Iinclude -I/usr/include/python2.7
LIBS = -lpython2.7

CC = g++
CFLAGS = -c -fPIC -Wall $(INCLUDES)
LINKFLAGS = -fPIC -Wall -shared $(LIBS)

BUILDDIR = build
SRCDIR = src
OBJDIR = objs

OUTPUT_FILE = libpython_plugin.so
INSTALL_DIR = ../ts3client/plugins

PYTHON_FOLDER = python


OUTPUT = $(BUILDDIR)/$(OUTPUT_FILE)

SRCS:=$(shell find $(SRCDIR) -iname *.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS)) 

all: $(OUTPUT)

autogen:
	cd scripts;	python main.py;	cd ..

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(OUTPUT): $(BUILDDIR) $(OBJS)
	$(CC) $(OBJS) $(LINKFLAGS) -o $(OUTPUT)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OBJDIR)

install: install_scripts install_plugin

install_scripts:
	cp -r $(PYTHON_FOLDER) $(INSTALL_DIR)

install_plugin:
	cp $(OUTPUT) $(INSTALL_DIR)
