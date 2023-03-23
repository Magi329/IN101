/* ZHANG Chen*/

#include<stdio.h>
/* 
creer une structure
ouvrir 
lire P2 et 3 valeurs
allouer un espace stocker afficher 
boucle sur pixel--mettre valeur dans le tableau
fermer le fichier
*/



struct image_t{
	int height;
	int weight;
	int max_pixel;
	int* pixels;
};


struct image_t load_pgm(char* fname){
	struct image_t image;
	int read;

	FILE *fp;
	fp = fopen(fname, "rb");
	if(fp == NULL)
		printf("fail to open the file! \n");
		return image;
	//read = fscanf(...)   !=1 number of succes
	char buffer[20];

//read the magic number and ensure P2
	fscanf(fp, "%s", buffer);
	if(strcmp(buffer,"P2")!=0){
		printf("fail to read P2! \n");
		fclose(fp);
		return image;
	}

//read weight and height
	read = fscanf(fp,"%d%d", &image.weight, &image.height);
	if(read!=2){
		printf("fail to read the height or weight \n");
		fclose(fp);
		return image;
	}
	if(image.height*image.weight<=0){
		printf("file corrupted \n");
		fclose(fp);
		return image;
	}
	
//read seuil
	read = fscanf(fp, "%d", &max_pixel);
	if(read!=2){
		printf("fail to read the max_pixel \n");
		fclose(fp);
		return image;
	}


//create table of pixels
	int size = image.weight*image.height;
	image.pixels = malloc(sizeof(int)*size);


//read each pixel. and transform it to 1 or 0, and fill in the table
	for(int i=0;i<size;i++){
		read = fscanf(fp, "%d", &image.pixels[i])
		if(read!=1){
			printf("fail to read the pixel %d\n", i);
			fclose(fp);
			return image;
		}
	}






	fclose(fp);
}





int main{
	
	return 0;
}