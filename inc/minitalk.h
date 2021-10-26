/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:34:58 by jzeybel           #+#    #+#             */
/*   Updated: 2021/10/26 18:36:08 by jzeybel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

unsigned int	ft_len(char *s);
int				ft_wrs(char *s);
int				ft_wrsln(char *s);
char			*ft_ltoa(long i, int base);
long			ft_atol(char *s);
void			ft_handler(int signo, siginfo_t *info, void *ctx);
void			ft_converter(int bit);
void			ft_sendmsg(char *s, pid_t pid);
void			ft_sendchar(unsigned char s, pid_t pid);
void			bitin(int bit);

#endif
