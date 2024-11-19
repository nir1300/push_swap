/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrumpfhu <nrumpfhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:06:37 by edarmaev          #+#    #+#             */
/*   Updated: 2024/11/14 12:14:57 by nrumpfhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	match_counter(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

size_t	substring_counter(const char *s, char c)
{
	size_t	i;
	size_t	j;

	if (match_counter(s, c) == strlen(s) || s[0] == '\0')
		return (0);
	if (match_counter(s, c) == 0)
		return (1);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		
		i++;
	}
	//printf("j = %zu\n", j);
	return (j);
}

char	*ft_stringcopy(char const *s, char c)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (strlen(s) + 1));
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	while (i >= 0)
	{
		if (copy[i] == c)
			copy[i] = '\0';
		i--;
	}
	return (copy);
}

char	**ft_fillarray(char const *s, char c, char **arr, char *copy)
{
	size_t	k;
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (j < substring_counter(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		/*arr[j] = (char *)malloc(sizeof(char) * (strlen(&copy[i]) + 1));
		if (arr[j] == NULL)
			return (NULL);*/
		while (copy[i] != '\0')
		{
			arr[j][k] = copy[i];
			printf("arr[%zu][%zu] = %c\n", j, k, arr[j][k]);
			k++;
			i++;
		}
		arr[j][k] = '\0';
		printf("arr[0] = %s\n", arr[0]);
		j++;
	}
	
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	*copy;
	char	**arr;
	//size_t	i;

	copy = ft_stringcopy(s, c);
	//printf("nos = %zu\n", substring_counter(s, c));
	//printf("nom = %zu\n", match_counter(s, c));
	arr = (char **)malloc(sizeof(char) * (ft_strlen(s) - match_counter(s, c) + \
	substring_counter(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	if ((long unsigned int)match_counter(s, c) == (long unsigned int)ft_strlen(s) || s[0] == '\0')
		arr[0] = "\0";
	else
		arr = ft_fillarray(s, c, arr, copy);
	/*i = 0;
	while (i <= substring_counter(s, c))
	{
		printf("arr[%zu] = %s\n", i, arr[i]);
		i++;
	}*/
	//free(copy);
	arr[4] = NULL;
	return (arr);
}

/* int	main(void)
{
	char	s[] = "112221112111112111222";
	char	c = '1';
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_split(s, c);
	printf("\n");
	while (i < 5)
	{
		printf("arr[%zu] = %s\n", i, arr[i]);
		i++;
	}
	free(arr);
	printf("end of program\n");
	return (0);
}

int	main(void)
{
	char	s[] = "112221112111112111222";
	char	c = '1';
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_split(s, c);
	printf("\n");
	printf("substring_counter = %zu\n", substring_counter(s, c));
	while (i <= substring_counter(s, c))
	{
		printf("arr[%zu] = %s\n", i, arr[i]);
		i++;
	}
	free(arr);
	printf("end of program\n");
	return (0);
}

#include "libft.h"

size_t	match_counter(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

size_t	substring_counter(const char *s, char c)
{
	size_t	i;
	size_t	j;

	if (match_counter(s, c) == ft_strlen(s) || s[0] == '\0')
		return (0);
	if (match_counter(s, c) == 0)
		return (1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

char	*ft_stringcopy(char const *s, char c)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	while (i >= 0)
	{
		if (copy[i] == c)
			copy[i] = '\0';
		i--;
	}
	return (copy);
}

char	**ft_fillarray(char const *s, char c, char **arr, char *copy)
{
	size_t	k;
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (j < substring_counter(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr[j] = (char *)malloc(sizeof(char) * (ft_strlen(&copy[i]) + 1));
		if (arr[j] == NULL)
			return (NULL);
		while (copy[i] != '\0')
		{
			arr[j][k] = copy[i];
			printf("arr[%zu][%zu] = %c\n", j, k, arr[j][k]);
			k++;
			i++;
		}
		arr[j][k] = '\0';
		printf("arr[%zu] = %s\n", j, arr[j]);
		j++;
	}
	arr[j] = "\0";
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	*copy;
	char	**arr;

	copy = ft_stringcopy(s, c);
	printf("nos = %zu\n", substring_counter(s, c));
	printf("nom = %zu\n", match_counter(s, c));
	arr = (char **)malloc(sizeof(char) * (ft_strlen(s) - match_counter(s, c) + \
	substring_counter(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	if (match_counter(s, c) == ft_strlen(s) || s[0] == '\0')
		arr[0] = "\0";
	else
		arr = ft_fillarray(s, c, arr, copy);
	free(copy);
	return (arr);
}

int	main(void)
{
	char	s[] = "2221112111112111222";
	char	c = '1';
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_split(s, c);
	printf("\n");
	while (i <= substring_counter(s, c))
	{
		printf("arr[%zu] = %s\n", i, arr[i]);
		i++;
	}
	printf("end of program");
	return (0);
}
*/
