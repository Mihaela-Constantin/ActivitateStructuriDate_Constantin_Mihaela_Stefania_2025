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
// 1 - functie initializare atribute structura + functie listare atribute structura + functie dezalocare atribute de tip pointer din structura
// 2 - functie modificare pret
// 3 - functie modificare producator telefon
// 4 - functie modificare serie telefon
// 5 - functie modificare RAM telefon
// 6 - adaugare atribut stoc in structura si in functia de afisare + functie de modificare stoc

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








int main() {
	
	struct Telefon te;
	te = initializare(1, "Samsung", 'A', 512, 1500);
	afisare(te);



	return 0;
}