CROSS_COMPILE :=
AR       := $(CROSS_COMPILE)ar
RANLIB   := $(CROSS_COMPILE)ranlib
CC       := $(CROSS_COMPILE)gcc
CFLAGS   := -g -O2
CPPFLAGS := -Wall -Werror -std=gnu99 -I$(CURDIR) -MMD
LDFLAGS  := -L$(CURDIR)
LIBS     :=

DEMO_SRC := demo.c
DEMO_OBJS:= $(patsubst %.c,%.o,$(DEMO_SRC))
DEMO_DEPS:= $(patsubst %.c,%.d,$(SRC))
DEMO_LIBS := -liniparser

LIB_SRC  := iniparser.c
LIB_OBJS := $(patsubst %.c,%.o,$(LIB_SRC))
LIB_DEPS := $(patsubst %.c,%.d,$(LIB_SRC))
LIB_OUT  := libiniparser.a

TARGET   := run.exe

DEPS     := $(DEMO_DEPS) $(LIB_DEPS)
OBJS     := $(DEMO_OBJS) $(LIB_OBJS)

.PHONY: all
all: $(TARGET) $(LIB_OUT)

-include $(DEMO_DEPS) $(LIB_DEPS)
$(LIB_OUT): $(LIB_OBJS)
	$(AR) rc $@ $^
	$(RANLIB) $@
$(TARGET): $(DEMO_OBJS) $(LIB_OUT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(DEMO_OBJS) $(LIBS) $(DEMO_LIBS)
$(LIB_OBJS) $(DEMO_OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(DEPS)
	$(RM) $(OBJS)
	$(RM) $(TARGET)
	$(RM) $(LIB_OUT)
