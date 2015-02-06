## Copyright (c) 2015 <Olivier Gayot <duskcoder@gmail.com>
##
## This software is provided 'as-is', without any express or implied
## warranty. In no event will the authors be held liable for any damages
## arising from the use of this software.
##
## Permission is granted to anyone to use this software for any purpose,
## including commercial applications, and to alter it and redistribute it
## freely, subject to the following restrictions:
##
## 1. The origin of this software must not be misrepresented; you must not
##    claim that you wrote the original software. If you use this software
##    in a product, an acknowledgement in the product documentation would be
##    appreciated but is not required.
## 2. Altered source versions must be plainly marked as such, and must not be
##    misrepresented as being the original software.
## 3. This notice may not be removed or altered from any source distribution.

NAME = cph
CC ?= gcc
CPPFLAGS =
LDFLAGS =

SRC = cph.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) -o "$@" $^ $(LDFLAGS)

DEP = $(SRC:.c=.d)
-include $(DEP)

%.d: %.c
	$(CC) -MM $(CPPFLAGS) $< -MF $@ -MT "$*.o $@"

clean:
	$(RM) $(OBJ)

mrproper: clean
	$(RM) $(NAME)
	$(RM) $(DEP)


.PHONY: clean mrproper all
