#ifndef _Star
#define _Star

typedef struct {
	char name[50];
	float dist;
	float magnitude;
	float deg;
	float min;
	float sec;
}Star;

typedef struct {
	char name[50];
	Star* stars;
}Constellation;

void Callocate(Constellation** cns, int c);
void Sallocate(Star** st, int c);
void cfree(Constellation** cns);

void cnst_table(Constellation* cns);
void read_data(Constellation** cns);
void print_data(Constellation* cns, int n);
void choice(Constellation* cns);
#endif
