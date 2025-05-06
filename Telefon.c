#include<stdio.h>
#include<stdlib.h>

struct Telefon {
	int id;
	int ram;
	char* producator;
	float pret;
	char serie;
};

struct Telefon initializare(int id, int ram, const char* producator, float pret, char serie) {
	struct Telefon t;
	t.id = 1;
	t.ram = ram;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) +1)); 
	strcpy_s(t.producator, strlen(producator) + 1, producator);
	t.pret = pret;
	t.serie = serie;
	return t;
}

//afisarea tuturor atributelor.
void afisare(struct Telefon t) {
	// varianta comasata
	printf("%d. Telefonul %s seria %c are %d Gb RAM, costa %5.2f RON\n", t.id, (t.producator != NULL) ? t.producator : "No Name", t.serie, t.ram, t.pret);
}

//modificare atribut pret, este un fel de setter
void modificaPret(struct Telefon* t, float pretNou) {
	if (pretNou > 0) {
		t->pret = pretNou;
	}
}

//dezalocare campuri alocate dinamic
void dezalocare(struct Telefon* t) {
	if (t->producator != NULL) {
		free(t->producator);
		t->producator = NULL;
	}
}

int main() {
	struct Telefon t;
	t = initializare(1, 256, "Samsung", 2000.5, 'A');
	afisare(t);
	modificaPret(&t, 1500);
	afisare(t);
	dezalocare(&t);
	afisare(t);
	return 0;
}