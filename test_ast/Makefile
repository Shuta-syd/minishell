#       ___           ___           ___           ___           ___                       ___       ___
#      /\__\         /\  \         /\__\         /\  \         /\  \          ___        /\__\     /\  \
#     /::|  |       /::\  \       /:/  /        /::\  \       /::\  \        /\  \      /:/  /    /::\  \
#    /:|:|  |      /:/\:\  \     /:/__/        /:/\:\  \     /:/\:\  \       \:\  \    /:/  /    /:/\:\  \
#   /:/|:|__|__   /::\~\:\  \   /::\__\____   /::\~\:\  \   /::\~\:\  \      /::\__\  /:/  /    /::\~\:\  \
#  /:/ |::::\__\ /:/\:\ \:\__\ /:/\:::::\__\ /:/\:\ \:\__\ /:/\:\ \:\__\  __/:/\/__/ /:/__/    /:/\:\ \:\__\
#  \/__/~~/:/  / \/__\:\/:/  / \/_|:|~~|~    \:\~\:\ \/__/ \/__\:\ \/__/ /\/:/  /    \:\  \    \:\~\:\ \/__/
#        /:/  /       \::/  /     |:|  |      \:\ \:\__\        \:\__\   \::/__/      \:\  \    \:\ \:\__\
#       /:/  /        /:/  /      |:|  |       \:\ \/__/         \/__/    \:\__\       \:\  \    \:\ \/__/
#      /:/  /        /:/  /       |:|  |        \:\__\                     \/__/        \:\__\    \:\__\
#      \/__/         \/__/         \|__|         \/__/                                   \/__/     \/__/

CC		=	cc
CFLAGS	=	#-Wall -Wextra -Werror
LDFLAGS	=	-L$(LIBDIR) -lft -lreadline
NAME	=	minishell
SRCDIR	=	test_ast
OBJDIR	=	obj
LIBDIR	=	./libft
INCDIR	=	inc $(LIBDIR)/inc

# find src -name \*.c | sed -e "s/$/\\\/g" | pbcopy
SRCS	=	$(shell find $(SRCDIR) -name \*.c | tr "\n" " ") # fix here
OBJS	=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INCS	=	$(addprefix -I,$(INCDIR))

all: libft $(NAME) $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $(@))
	$(CC) $(CFLAGS) $(INCS) -o $(@) -c -g $(<)

$(NAME): $(OBJS)
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
