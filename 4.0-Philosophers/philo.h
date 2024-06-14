/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:41 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/14 16:48:54 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H//REMOVE $(NAME) from Makefile before pushing
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

# define PROGRAM_NAME	"philo"

# define TOO_FEW_ARG 	"too few arguments\n"
# define TOO_MANY_ARG 	"too many arguments\n"
# define NOT_AN_UINT 	"invalid argument: not a positive int\n"

# define TRUE			1
# define FALSE			0
# define INT_MAX		2147483647

//typedef struct s_mutex
//{
//	pthread_mutex_t	mtx;
//	pthread_mutex_t	print;
//	pthread_mutex_t	dead;
//	pthread_mutex_t	full;
//}					t_mutex;

/*
 * `pthread_t`	thread;
 * `int`		id;
 * `int`		died;
 * `int`		is_eating;
 * `int`		is_thinking;
 * `int *`		left_fork;
 * `int *`		right_fork;
 * `t_data *`	data;
*/
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				died;
	int				is_eating;
	int				is_thinking;
	int				*left_fork;
	int				*right_fork;
	struct s_data	*data;
}					t_philo;

/*
 * `pthread_mutex_t`	mutex;
 * `t_philo **`			forum;
 * `int`				nb_philo;
 * `int`				time_to_die;
 * `int`				time_to_eat;
 * `int`				time_to_sleep;
 * `int`				max_meal;
 * `int`				start_time;
*/
typedef struct s_data
{
	pthread_mutex_t	mutex;
	t_philo			**forum;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meal;
	int				start_time;
	int				**forks;
}					t_data;

int			gettimestamp(int start_time);
int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(const char *str);
int			ft_isnum(const char *str);
//utils.c


void		*philo_routine(void *philo);
// threads.c

int			error(char *error_msg);
// error.c

void		freentab(char **tab, int heap, int n);
void		freedata(t_data *data);
// free.c

#endif
