# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 19:18:48 by shogura           #+#    #+#              #
#    Updated: 2022/06/25 14:23:06 by shogura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		=	cc
CFLAGS	=	#-Wall -Wextra -Werror
LDFLAGS	=	-L$(LIBDIR) -lft -lreadline #-lft??
NAME	=	minishell
SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	./src/libft
INCDIR	=	inc $(LIBDIR)/inc

# find src -name \*.c | sed -e "s/$/\\\/g" | pbcopy
SRCS	=	$(shell find $(SRCDIR) -name \*.c | tr "\n" " ") # fix here
OBJS	=	$(addprefix $(OBJDIR)/,$(subst ../$(SRCDIR)/,,$(addprefix ../,$(SRCS:%.c=%.o))))
INCS	=	$(addprefix -I,$(INCDIR))

all: libft $(NAME) $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $(@))
	$(CC) $(CFLAGS) $(INCS) -o $(@) -c -g $(<)

$(NAME): $(OBJS) $(LIB)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

libft:
	@make -C $(LIBDIR)

clean:
	$(RM) $(OBJS)
	$(RM)r $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
