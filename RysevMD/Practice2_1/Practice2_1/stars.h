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
}Ñonstellation;

void allocate(Ñonstellation** cns);
void cfree(Ñonstellation** cns);

void cnst_table(Ñonstellation* cns);
void read_data(Ñonstellation* cns);
void print_data(Ñonstellation* cns, int n);
void choice(Ñonstellation* cns);
#endif
