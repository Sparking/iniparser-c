CC       := gcc
CFLAGS   := -g -O0
CPPFLAGS := -Wall -Werror -std=gnu99 -I$(CURDIR) -MMD
LDFLAGS  :=
LIBS     :=

SRC      := demo.c iniparser.c
OBJS     := $(patsubst %.c,%.o,$(SRC))
DEPS     := $(patsubst %.c,%.d,$(SRC))
TARGET   := run.exe

.PHONY: all
all: $(TARGET)

-include $(DEPS)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(DEPS)
	$(RM) $(OBJS)
	$(RM) $(TARGET)