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
LDFLAGS	=	-L$(LIBDIR) -lft -L$(shell brew --prefix readline)/lib -lreadline
NAME	=	minishell
SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	./libft
INCDIR	=	inc $(LIBDIR)/inc $(shell brew --prefix readline)/include

# find src -name \*.c | sed -e "s/$/\\\/g" | pbcopy <-- copy all src files
SRCS	=	$(shell find $(SRCDIR) -name "*.c" -type f) # fix here
OBJS	=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INCS	=	$(addprefix -I,$(INCDIR))

all: libft $(NAME) $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCS) -o $(@) -c -g $(<)
	@echo "$(<)\n     \
	$(MGN)--->$(RES) \
	$(GRN)$(@)$(RES)"

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "$(CYN)\n=====link=====$(RES)"
	@echo "$(YEL)Objects$(RES): $(OBJS)\n"
	@echo "$(YEL)Flags$(RES): $(LDFLAGS)\n"
	@echo "     $(MGN)--->$(RES) $(GRN)$(NAME)$(RES)"
	@echo "$(CYN)==============$(RES)"

libft:
	@make -C $(LIBDIR)

libre:
	@make re -C $(LIBDIR)

clean:
	@echo "$(RED)"
	$(RM) $(OBJS)
	@$(RM)r $(OBJDIR)
	@echo "$(RES)"
	rm -rf bin

eclean:
	@echo "$(RED)"
	$(RM) $(NAME)
	@echo "$(RES)"

fclean:	clean eclean

re: fclean all

reall: libre re

.PHONY: all libft clean fclean eclean re

RED = \033[31m
GRN = \033[32m
YEL = \033[33m
BLU = \033[34m
MGN = \033[35m
CYN = \033[36m
RES = \033[m
