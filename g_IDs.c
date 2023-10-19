#include "main.h"

/**
 * g_IDs - identofiers
 * @frmt: print formats
 * @i: param
 * Return: IDs
 */
int g_IDs(const char *frmt, int *i)
{
	int a, cue;
	int IDs = 0;
	const char ID_signs[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ID_names[] = {FUN_SUB, FUN_ADD, FUN_NULL, FUN_HASH, FUN_EMPTY, 0};

	for (cue = *i + 1; frmt[cue] != '\0'; cue++)
	{
		for (a = 0; ID_signs[a] != '\0'; a++)
			if (frmt[cue] == ID_signs[a])
			{
				IDs |= ID_names[a];
				break;
			}

		if (ID_signs[a] == 0)
			break;
	}

	*i = cue - 1;

	return (IDs);
}
