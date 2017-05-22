#include "../lib/save.h"

int main()
{
	int rep;

	/************
	* save test *
	************/
	board b = createBoard(4);
	save(&b);
	char doss[100] = "./save/";
	DIR* directory = opendir(doss);
	struct dirent* direct;

	printf("\n=========================\n");
	printf("* Liste des sauvegardes * \n");
	printf("=========================\n");
	while ((direct = readdir(directory)) != NULL)
	{
        	printf("%s\n",direct->d_name);
	}
	closedir(directory);

	printf("\nVoyez vous votre sauvegarde ?\n");
	printf("1. Oui\n");
	printf("2. Non\n");
	scanf("%d",&rep);
	if(rep != 1)
	{
		printf("Failed save test\n");
		exit(1);
	}
	
	/***********************
	* load & loadGame test *
	************************/
	// La fonction load est comprise dans loadGame, il s'agit d'un test 2 en 1
	loadGame();
	printf("\nSatisfait du test ?\n");
	printf("1. Oui\n");
	printf("2. Non\n");
	scanf("%d",&rep);
	if(rep != 1)
	{
		printf("Failed load & loadGame test\n");
		exit(2);
	}
	
	return 0;
}
