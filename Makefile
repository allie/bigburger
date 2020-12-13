include $(ROOT)/usr/include/make/PRdefs

N64KITDIR = C:/nintendo/n64kit

SRCDIR = src
INCDIR = include
OBJDIR = build
DATADIR = data

TARGET = bigburger

CODEFILES = $(wildcard $(SRCDIR)/*.c) 
CODEOBJECTS = $(subst $(SRCDIR),$(OBJDIR),$(CODEFILES:.c=.o)) $(NUOBJ)

OPTIMIZER = -O3

NUSYSDIR = $(N64KITDIR)/nusys
NUSYSINC = $(NUSYSDIR)/include
NUSYSLIB = $(NUSYSDIR)/lib
NUSTDDIR = $(N64KITDIR)/nustd
NUSTDINC = $(NUSTDDIR)/include
NUSTDLIB = $(NUSTDDIR)/lib

NUOBJ = $(NUSYSLIB)/nusys.o

LCDEFS = -DF3DEX_GBI_2
LCINCS = -I$(INC)/PR -I$(NUSYSINC) -I$(NUSTDINC) -I$(INCDIR) -I$(DATADIR)
LCOPTS = -G 0 $(OPTIMIZER)
LDFLAGS = -L$(ROOT)/usr/lib -L$(ROOT)/usr/lib/PR -L$(NUSYSLIB) -L$(NUSTDLIB) -lnusys -lnustd -lgultra -L$(GCCDIR)/mipse/lib -lkmc

# Uncomment for debugging symbols
# LCOPTS += -g

# Uncomment for debug output in game
# LCOPTS += -D__DEBUG__

# Uncomment to use debug libraries
# LDFLAGS = -L$(ROOT)/usr/lib -L$(ROOT)/usr/lib/PR -L$(NUSYSLIB) -L$(NUSTDLIB) -lnusys_d -lnustd_d -lgultra_d -L$(GCCDIR)/mipse/lib -lkmc

# Uncomment for PAL mode
# LCOPTS += -DPAL_MODE

CODESEGMENT = $(OBJDIR)/codesegment.o
SYMBOL = $(OBJDIR)/$(TARGET).out
ROM = $(OBJDIR)/$(TARGET).n64

default: $(ROM)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(CODESEGMENT):	$(CODEOBJECTS)
	$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(ROM):	$(CODESEGMENT)
	$(MAKEROM) spec -I$(NUSYSINC) -r $(ROM) -e $(SYMBOL)
	makemask $(ROM)
