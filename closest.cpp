//******-> haithem ben abdelaziz: haithem.ben.abdelaziz@gmail.com, wis auusi ah

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMENTS(x) (sizeof (x) / sizeof ((x)[0]))

int closestInterval (int array[], int size);

int main (int argc, char* argv[])
{
	int array[] = {1, 4, 7, 10, 18};
	int closest = 1;
	
	printf ("sizeof (array) : %lu\n", NELEMENTS (array));
	
	closest = closestInterval (array, NELEMENTS (array));
	
	printf ("closest : %d\n", closest);
	
	
	return EXIT_SUCCESS;
}

int closestInterval (int array[], int size)
{
	int closest = 1;
	
	int dist[size][size];
	
	memset (dist, 0, sizeof(dist[0][0]) * size * size);
	
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			if (i != j)
				dist[i][j] = abs (array[i] - array[j]);
	
	closest = dist[0][1];
	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++)
			if (i != j && dist[i][j] < closest)
				closest = dist[i][j];
	
	return closest;
}