#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>

static int	readInput(char *buffer, size_t size)
{
	size_t	length;
	int		character;

	if (!fgets(buffer, size, stdin))
		return (0);
	length = strlen(buffer);
	if (length > 0 && buffer[length - 1] == '\n')
		buffer[--length] = '\0';
	else if (!feof(stdin))
	{
		while ((character = getchar()) != '\n' && character != EOF)
			;
		return (0);
	}
	return (1);
}

static int	isValidNumber(char *input, char type)
{
	char	*end;
	double	value;

	errno = 0;
	if (type == 'd')
	{
		value = strtol(input, &end, 10);
		if (errno == ERANGE || end == input)
			return (0);
	}
	else
	{
		value = strtof(input, &end);
		if (errno == ERANGE || end == input || !isfinite(value))
			return (0);
	}
	while (isspace((unsigned char)*end))
		end++;
	return (*end == '\0');
}

static int	isValidInput(char *input, char type)
{
	if (type == 'd' || type == 'f')
		return (isValidNumber(input, type));
	if (type == 'c')
		return (strlen(input) == 1);
	return (type == 's');
}

static void	*convertInput(char *input, char type)
{
	void	*result;

	if (type == 's')
	{
		result = malloc(strlen(input) + 1);
		if (result)
			strcpy((char *)result, input);
		return (result);
	}
	if (type == 'd')
	{
		result = malloc(sizeof(int));
		if (result)
			*(int *)result = (int)strtol(input, NULL, 10);
		return (result);
	}
	if (type == 'f')
	{
		result = malloc(sizeof(float));
		if (result)
			*(float *)result = strtof(input, NULL);
		return (result);
	}
	result = malloc(sizeof(char));
	if (result)
		*(char *)result = input[0];
	return (result);
}

/*
    char *expectedInput -> will be treated like printf (using %_)
    max char *lenght = 1024
*/
void	*inputTreatment(char *expectedInputType)
{
	char	buffer[1024];

	if (!expectedInputType || expectedInputType[0] != '%' || expectedInputType[1] == '\0')
		return (NULL);

	if (expectedInputType[1] != 'd' && expectedInputType[1] != 'f' && expectedInputType[1] != 's' && expectedInputType[1] != 'c')
		return (NULL);
	while (1)
	{
		if (!readInput(buffer, sizeof(buffer)))
			return (NULL);
		if (!isValidInput(buffer, expectedInputType[1]))
		{
			fprintf(stderr, "Invalid input. Try again.\n");
			continue ;
		}
		return (convertInput(buffer, expectedInputType[1]));
	}
}
