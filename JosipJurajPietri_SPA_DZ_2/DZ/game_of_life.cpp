#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost()
{
    return rand() % (1 - 0 + 1);
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _generacija[i][j];
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

int game_of_life::ProvjeraSusjeda(int i, int j)
{
	int susjedi = 0;
	if (_generacija[i - 1][j - 1]) {
		++susjedi;
	}
	if (_generacija[i - 1][j]) {
		++susjedi;
	}
	if (_generacija[i][j - 1]) {
		++susjedi;
	}
	if (_generacija[i - 1][j + 1]) {
		++susjedi;
	}
	if (_generacija[i + 1][j - 1]) {
		++susjedi;
	}
	if (_generacija[i + 1][j]) {
		++susjedi;
	}
	if (_generacija[i][j + 1]) {
		++susjedi;
	}
	if (_generacija[i + 1][j + 1]) {
		++susjedi;
	}
	return susjedi;
}

void game_of_life::sljedeca_generacija()
{
	int susjedi;

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			susjedi = ProvjeraSusjeda(i, j);
			if (susjedi < 2) {
				_sljedeca_generacija[i][j] = 0;
			}
			else if (susjedi > 3) {
				_sljedeca_generacija[i][j] = 0;
			}
			else if (susjedi == 3) {
				_sljedeca_generacija[i][j] = 1;
			}				
			else if (_generacija[i][j]==1 && susjedi == 2) {
				_sljedeca_generacija[i][j] = 1;
			}				
			else {
				_sljedeca_generacija[i][j] = 0;
			}				
		}
	}
}

void game_of_life::kopija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}