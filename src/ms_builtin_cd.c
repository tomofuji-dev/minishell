/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by t.fuji            #+#    #+#             */
/*   Updated: 2022/12/19 18:34:19 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ms_builtin_cd(char *argv[]);
static void	ms_builtin_cd_setpath_home(char	*path, char	*arg);
static void	ms_builtin_cd_setpath_absolute(char	*path, char	*arg);
static void	ms_builtin_cd_setpath_relative(char	*path, char	*arg);

int	ms_builtin_cd(char	*argv[])
{
	char	path[PATH_MAX + 1];

	if (argv == NULL || argv[1] == NULL)
		return (chdir(getenv(ENV_HOME)));
	else if (argv[1][0] == CHR_HOME \
		&& (argv[1][1] == CHR_DIR || argv[1][1] == '\0'))
		ms_builtin_cd_setpath_home(path, argv[1]);
	else if (argv[1][0] == CHR_DIR)
		ms_builtin_cd_setpath_absolute(path, argv[1]);
	else
		ms_builtin_cd_setpath_relative(path, argv[1]);
	return (chdir(path));
}

static void	ms_builtin_cd_setpath_home(char	*path, char	*arg)
{
	ft_strlcpy(path, getenv(ENV_HOME), PATH_MAX + 1);
	ft_strlcat(path, &arg[1], PATH_MAX + 1);
}

static void	ms_builtin_cd_setpath_absolute(char	*path, char	*arg)
{
	ft_strlcpy(path, arg, PATH_MAX + 1);
}

static void	ms_builtin_cd_setpath_relative(char	*path, char	*arg)
{
	getcwd(path, PATH_MAX);
	ft_strlcat(path, "STR_DIR", PATH_MAX + 1);
	ft_strlcat(path, arg, PATH_MAX + 1);
}

/*
int	main()
{
	char	*buf;

	printf("CWD: %s\n", getcwd(buf, PATH_MAX));
	printf("HOME: %s\n", getenv("HOME"));
	chdir("../");
	printf("CWD: %s\n", getcwd(buf, PATH_MAX));
	printf("PWD: %s\n", getenv("PWD"));
}
*/
