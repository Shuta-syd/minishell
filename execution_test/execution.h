#include <libc.h>
#include "libft.h"

typedef struct s_cmd
{
	char **argv;
}	t_cmd;

typedef struct s_shell
{
	struct s_cmd	*cmds;
	uint32_t		cmd_cnt;
	char			*infile;
	char			*outfile;
	int				fd[2];
	int				pipe_fd[2];
	int				outfile_mode;
}	t_shell;

#define IN 0
#define OUT 1

#define TRUNC 0
#define APPEND 1

void	executor(t_shell *shell);
int	ft_execvp(char *file, char *argv[]);
