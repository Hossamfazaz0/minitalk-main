/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:43:00 by hfazaz            #+#    #+#             */
/*   Updated: 2024/04/29 22:07:15 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "unistd.h"
# include "utils.c"
typedef struct s_data
{
	int		byte;
	int		bit_count;
	char	current_char;

}			t_data;

#endif