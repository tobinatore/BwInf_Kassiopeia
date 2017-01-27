#include <iostream>
#include <cstdlib>
#include <string>

#define BREITE 7
#define HÖHE 5


void gib_aus(char Feld[HÖHE][BREITE])
{
	for (int i = 0; i < HÖHE; i++)
	{
		for (int j = 0; j < BREITE; j++)
		{
			std::cout << Feld[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::string floodfill(int y, int x, char Feld[HÖHE][BREITE])
{
	std::string Ergebnis;

	int begehbareFelder = 0;
	if (Feld[y][x] == 'K' || Feld[y][x] == 'k' || Feld[y][x] == ' ')
	{
		Feld[y][x] = '#';
		gib_aus(Feld);
		floodfill(y + 1, x, Feld);
		floodfill(y - 1, x, Feld);
		floodfill(y, x + 1, Feld);
		floodfill(y, x - 1, Feld);
	}

	for (int i = 0; i < HÖHE; i++)
	{
		for (int j = 0; j < BREITE; j++)
		{

			if (Feld[i][j] == ' ')
			{
				begehbareFelder++;
			}
		}
	}

	if (begehbareFelder == 0)
	{
		Ergebnis = "ja";
	}
	else
	{
		Ergebnis = "nein";
	}

	return Ergebnis;

}

int main()
{
	int x;
	int y;
	
	std::string Ergebnis;
	char Quadratien[HÖHE][BREITE] = { { '#', '#', '#', '#', '#', '#', '#' },
								{ '#', 'K', ' ', ' ', ' ', ' ', '#' },
								{ '#', ' ', '#', ' ', '#', ' ', '#' },
								{ '#', ' ', '#', ' ', '#', ' ', '#' },
								{ '#', '#', '#', '#', '#', '#', '#' }};
	
	
	for (int i = 0; i < HÖHE; i++)
	{

		for (int j = 0; j < BREITE; j++)
		{			
			if (Quadratien[i][j] == 'K' || Quadratien[i][j] == 'k')
			{
				y = i;
				x = j;
			}

		
		}
	}

	Ergebnis = floodfill(y, x, Quadratien);
	
	std::cout << "Sind alle Felder erreichbar: " << Ergebnis << std::endl;
	system("pause");
	return 0;
}



