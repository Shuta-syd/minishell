# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 15:22:14 by shogura           #+#    #+#              #
#    Updated: 2022/07/18 19:39:56 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = libft.a
INCDIR = inc
SRCDIR = src
OBJDIR = obj

SRCS =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
			 ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			 ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c\
			 ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_split.c ft_strchr.c\
			 ft_strcmp.c ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strcat.c\
			 ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c\
			 ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
			 ft_strchr_rev.c ft_strnlen.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstclear.c\
			 ft_lstdelone.c

OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:%.c=%.o)))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCDIR) -o $(@) -c -g $(<)
	@echo "$(<)\n     \
	$(MGN)--->$(RES) \
	$(GRN)$(@)$(RES)"

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(CYN)\n=====archive=====$(RES)"
	@echo "$(YEL)Objects$(RES): $(OBJS)\n"
	@echo "$(YEL)Flags$(RES): $(ARFLAGS)\n"
	@echo "     $(MGN)--->$(RES) $(GRN)$(NAME)$(RES)"
	@echo "$(CYN)==============$(RES)"

clean:
	@echo "$(RED)"
	$(RM) $(OBJS)
	@$(RM)r $(OBJDIR)
	@echo "$(RES)"

eclean:
	@echo "$(RED)"
	$(RM) $(NAME)
	@echo "$(RES)"

fclean:	clean eclean

re: fclean all

.PHONY: all clean eclean fclean re

RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
