#include<stdio.h>
#include<stdlib.h>

struct Telefon {
	int id;
	int ram;
	char* producator;
	float pret;
	char serie;
};

// === STRUCTURI si FUNCTII => TO DO:
// 1 - functie initializare atribute structura
// 2 - functie listare atribute structura
// 3 - functie dezalocare atribute de tip pointer din structura
// 4 - functie modificare pret
// 5 - functie modificare producator telefon
// 6 - functie modificare serie telefon
// 7 - functie modificare RAM telefon
// 8 - adaugare atribut stoc in structura si in functia de afisare
// 9 - functie de modificare stoc

struct Telefon initializare(int id, const char* producator, char serie, int ram, float pret) {

	struct Telefon te;
	te.id = id;
	te.ram = ram;
	te.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy_s(te.producator, strlen(producator) + 1, producator);
	te.pret = pret;
	te.serie = serie;

	return te;
}


void afisare(struct Telefon te) {
	printf("%d. Telefon %s | Seria %c | Ram %d Gb | Pret %5.2f RON\n", te.id, (te.producator != NULL) ? te.producator : "No Name", te.serie, te.ram, te.pret);
}

void dezalocare(struct Telefon* te) {
	if (te->producator != NULL) {
		free(te->producator);
		te->producator = NULL;
	}
}

void modificaPret(struct Telefon* te, float pretNou) {

	if (pretNou > 0) {
		te->pret = pretNou;
	} else {
		printf("\nPretul intodus este mai mic sau egal cu 0.\n");
	}
}

void modificaProducator(struct Telefon* te, char* producatorNou) {

	if (strcmp(te->producator, producatorNou) == 0) {
		printf("\nValorile sunt identice.\n");
	}
	else {

		if (te->producator != NULL) {
			free(te->producator);
		}

		te->producator = (char*)malloc(strlen(producatorNou) + 1);
		strcpy_s(te->producator, strlen(producatorNou) + 1, producatorNou);
	}
}

void modificaSerie(struct Telefon* te, char serieNoua) {

	if (te->serie == serieNoua) {
		printf("\nValorile sunt identice %c.\n", te->serie);
	}
	else {
		te->serie = serieNoua;
	}
}

void modificaRam(struct Telefon* te, int ramNou) {

	if (te->ram == ramNou) {
		printf("\nValorile sunt identice %d.\n", te->ram);
	}
	else {
		te->ram = ramNou;
	}
}








int main() {
	
	struct Telefon te;
	te = initializare(1, "Samsung", 'A', 512, 1500);

	//printf("=== Pret, inainte de modificare ===\n");
	//afisare(te);
	//modificaPret(&te, 1000);
	//printf("\n=== Pret, inainte dupa modificare ===\n");
	//afisare(te);

	//printf("=== Producator, inainte de modificare ===\n");
	//afisare(te);
	//modificaProducator(&te, "Nokia");
	//printf("\n=== Producator, inainte dupa modificare ===\n");
	//afisare(te);

	//printf("=== Serie, inainte de modificare ===\n");
	//afisare(te);
	//modificaSerie(&te, 'C');
	//printf("\n=== Serie, inainte dupa modificare ===\n");
	//afisare(te);

	printf("=== RAM, inainte de modificare ===\n");
	afisare(te);
	modificaRam(&te, 128);
	printf("\n=== RAM, inainte dupa modificare ===\n");
	afisare(te);
	

	dezalocare(&te);


	return 0;
}