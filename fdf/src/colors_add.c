/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:30:56 by gwaymar-          #+#    #+#             */
/*   Updated: 2019/05/22 12:02:57 by gwaymar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_10_color(t_coord **new_coord, t_vec *z1z2, int h, int h_min)
{
	if (z1z2->num1 <= h_min)
		(*new_coord)->color_start = take_collor(1);
	else if (z1z2->num1 >= 2 * h / 3)
		(*new_coord)->color_start = take_collor(7);
	else if (z1z2->num1 > h_min && z1z2->num1 < h / 3)
		(*new_coord)->color_start = take_collor(6);
	else
		(*new_coord)->color_start = take_collor(9);
	if (z1z2->num2 <= h_min)
		(*new_coord)->color_end = take_collor(1);
	else if (z1z2->num2 >= 2 * h / 3)
		(*new_coord)->color_end = take_collor(7);
	else if (z1z2->num2 > h_min && z1z2->num2 < h / 3)
		(*new_coord)->color_end = take_collor(6);
	else
		(*new_coord)->color_end = take_collor(9);
	return ;
}

void	get_11_color(t_coord **new_coord, t_vec *z1z2, int h, int h_min)
{
	if (z1z2->num1 <= h_min)
		(*new_coord)->color_start = take_collor(10);
	else if (z1z2->num1 >= 2 * h / 3)
		(*new_coord)->color_start = take_collor(2);
	else if (z1z2->num1 > h_min && z1z2->num1 < h / 3)
		(*new_coord)->color_start = take_collor(1);
	else
		(*new_coord)->color_start = take_collor(9);
	if (z1z2->num2 <= h_min)
		(*new_coord)->color_end = take_collor(10);
	else if (z1z2->num2 >= 2 * h / 3)
		(*new_coord)->color_end = take_collor(2);
	else if (z1z2->num2 > h_min && z1z2->num2 < h / 3)
		(*new_coord)->color_end = take_collor(1);
	else
		(*new_coord)->color_end = take_collor(9);
	return ;
}

void	get_12_color(t_coord **new_coord, t_vec *z1z2, int h, int h_min)
{
	if (z1z2->num1 <= h_min)
		(*new_coord)->color_start = take_collor(8);
	else if (z1z2->num1 >= 2 * h / 3)
		(*new_coord)->color_start = take_collor(4);
	else if (z1z2->num1 > h_min && z1z2->num1 < h / 3)
		(*new_coord)->color_start = take_collor(5);
	else
		(*new_coord)->color_start = take_collor(2);
	if (z1z2->num2 <= h_min)
		(*new_coord)->color_end = take_collor(8);
	else if (z1z2->num2 >= 2 * h / 3)
		(*new_coord)->color_end = take_collor(4);
	else if (z1z2->num2 > h_min && z1z2->num2 < h / 3)
		(*new_coord)->color_end = take_collor(5);
	else
		(*new_coord)->color_end = take_collor(2);
	return ;
}
