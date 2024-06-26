/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:27:15 by albartol          #+#    #+#             */
/*   Updated: 2024/06/14 01:07:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	merge(int *list, int i, int n, int *list_temp)
{
	int	j;
	int	m;
	int	end;
	int	middle;

	j = i;
	end = n;
	m = (n + i) / 2;
	middle = m;
	while (j < end)
	{
		if (i < middle && (m >= end || list[i] <= list[m]))
			list_temp[j++] = list[i++];
		else
			list_temp[j++] = list[m++];
	}
}

static void	merge_split(int *list, int i, int n, int *list_temp)
{
	int	m;

	if (n - i <= 1)
		return ;
	m = (n + i) / 2;
	merge_split(list_temp, i, m, list);
	merge_split(list_temp, m, n, list);
	merge(list_temp, i, n, list);
}

void	merge_sort(int *list, int i, int *list_temp)
{
	int	n;

	n = 0;
	while (i--)
	{
		list_temp[n] = list[n];
		n++;
	}
	merge_split(list, 0, n, list_temp);
}

/* int main(void)
{
    int i[] = {1,5,8,2,0,7,9,3,4,6};
	int j[10];
    int n = 0;

    ft_merge_sort(i, 10 , j);
    while (n < 10)
        ft_printf("%d", i[n++]);
    return (0);
} */