#include <iostream>


using namespace std;

bool output_is_enabled = false;

int work_with_array(int cols, int rows, int* arr_start)
{
	int total_space;
	if (output_is_enabled) cout << "Enter number of columns : " << cols << endl;

	if (output_is_enabled) cout << "Enter number of rows : " << rows << endl;

	if (cols <= 0 || rows <= 0)
	{
		if (output_is_enabled) cout << "Wrong input!" << endl;
		return 1;
	}
	total_space = cols * rows;
	int* array_ints = new int[total_space];

	*arr_start = int(array_ints);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (output_is_enabled)
			{
				cout << (array_ints + j + (i * cols));
				if (j < cols - 1)
				{
					cout << " | ";
				}
				else
				{
					cout << endl;
				}
			}
			*(array_ints + j + (i * cols)) = j + (i * cols);
		}
	}

	if (output_is_enabled) cout << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (output_is_enabled)
			{
				cout << *(array_ints + j + (i * cols));
				if (j < cols - 1)
				{
					cout << " | ";
				}
				else
				{
					cout << endl;
				}
			}
		}
	}

	delete[] array_ints;
	return 0;
}

int main()
{
	int counts = 0;
	int counts_limit = 10000;
	
	int* p_array_start = new int();
	int size_a, size_b, size_t;

	int stats[10000][2]; // !!!!!!!!!!!!!!!!!!! counts_limit
	int stats_by_size[10000][3]; //

	for (int i = 0; i < counts_limit; i++)
	{
		stats[i][0] = NULL;
		stats[i][1] = 0;
	}

	for (int i = 0; i < counts_limit; i++)
	{
		stats[i][0] = NULL;
		stats[i][1] = 0;
		stats[i][2] = 0;
	}

	while (counts < counts_limit)
	{
		size_a = rand() % 10;
		size_b = rand() % 10;
		size_t = size_a * size_b;

		work_with_array(size_a, size_b, p_array_start);
		
			/* это запись статистики по адрессам
			for (int i = 0; i < counts; i++)
			{
				if (stats[i][0] == *p_array_start)
				{
					stats[i][1]++;
					break;
				}
				else if (stats[i][0] == NULL)
				{
					stats[i][0] = *p_array_start;
					stats[i][1]++;
					break;
				}
			}

			*/

			/*Это запись статистики по адрессам, в зависимости от размера массива*/
		for (int i = 0; i < counts; i++)
		{
			if (stats_by_size[i][0] == NULL)
			{
				stats_by_size[i][0] = *p_array_start;
				stats_by_size[i][1]++;
				stats_by_size[i][2] = size_t;
				break;
			}


			if (stats_by_size[i][2] == size_t)
				if (stats_by_size[i][0] == *p_array_start)
				{
					stats_by_size[i][1]++;
					break;
				}
		}

		if (output_is_enabled)
		cout << "-----------------------------------" << endl;
		counts++;
	}
	cout << "STATS : \n \n \n";
	/*
	for (int i = 0; i < 100; i++)
	{
		if (stats[i][0] != NULL)
			cout << hex << stats[i][0] << " used " << dec << stats[i][1] << " times" << endl;
	}
	*/
	
	for (int i = 0; i < counts_limit; i++)
	{
		if (stats_by_size[i][0] != NULL)
			cout << hex << stats_by_size[i][0] << "," << dec << stats_by_size[i][1] << "," << stats_by_size[i][2] << endl;
		else break;
	}


	delete p_array_start;
	return 0;
}
