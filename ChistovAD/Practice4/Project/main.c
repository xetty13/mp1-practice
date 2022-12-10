#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 4 

void barcode(int*);
int adding();

int _c(int* a, int* b)
{
	for (int i = 0; i < N; i++)
	{
		if (a[i] != b[i])
		{
			return 1;
		}
	}
	return 0;
}

struct product {
	char name[20];
	char description[500];
	int barcode;
	int price;
	double discount;
};

int main() {
	int k;
	int a[N] = { 0,0,0,0 };
	int b[N] = { 0, 2, 3, 4 };
	int c[N] = { 4, 0, 5, 1 };
	int m[N] = { 8, 9, 5, 0 };
	int s[N] = { 2,4,5,6 };
	int f[N] = { 4,7,8,9 };
	int e[N] = { 7,8,9,0 };
	int l[N] = { 1,2,4,3 };
	int w[N] = { 8,9,0,7 };
	int j[N] = { 4,5,6,7 };
	int o[N] = { 5,6,7,8 };
	int p[N] = { 2,4,5,7 };
	int r[N] = { 7,8,9,0 };
	int breads = 0;
	int milks = 0;
	int cheeses = 0;
	int sausages = 0;
	int fishes = 0;
	int eggs = 0;
	int lemons = 0;
	int waters = 0;
	int jams = 0;
	int onions = 0;
	int porridges = 0;
	int rices = 0;
	struct product bread = { "bread", "Environmentally friendly, non-GMO, beloved by Nizhny Novgorod residents. This is a delicious quality product, loved since childhood. The packaging format - a bag with a closing clip is convenient: it can be stored, opened and closed several times.",b[N],40, 0.1 };
	struct product milk = { "milk","100% natural milk. No added preservatives or colorings.3.2% fat is suitable for those who love the traditional taste of milk.Domik v derevne milk can be drunk cold or warm.Ideal for coffee, tea and cooking your favorite dishes",m[N],80,0.2 };
	struct product cheese = { "cheese","Has a pronounced cheesy, slightly sour taste and smell. The rind of the cheese is even, without a thick subcortical layer. The consistency of the product is moderately elastic, uniform throughout the mass. . The color of the product varies from white to light yellow in various shades, uniform throughout the mass.",c[N],200,0.3 };
	struct product sausage = { "sausage","Sausage is a food product; class-forming type of sausages, which is minced meat in an oblong casing. May contain one or more types of meat, such as poultry meat, various fillers, heat-treated (boiled, sometimes multiple; fried) or fermented.",s[N], 80,0.1 };
	struct product fish = { "fish","Fish are caught in huge quantities in the oceans, lakes and rivers, bred on special farms. It is boiled, baked in the oven, fried on a grill or pan, cut into thin strips for sushi...", f[N],1000,0.25 };
	struct product egg = { "eggs","The egg consists of egg white and yolk in a calcareous translucent shell.The color of the yolk depends on the diet of the laying hen and can range from pale yellow to dark orange and greenish..Egg white is made up of water and proteins",e[N],330,0.1 };
	struct product lemon = { "lemon","Lemon is a citrus fruit, the fruit of a small evergreen tree called Citrus limon. It grows in the subtropics of the Mediterranean, the USA, Mexico, Argentina, the countries of the Caucasus, Central Asia, etc.",l[N],120,0.5 };
	struct product water = { "water","a transparent liquid without color, taste and smell, which consists of two hydrogen atoms and one oxygen. Changes state depending on temperature: freezes or evaporates",w[N], 20,0.05 };
	struct product jam = { "jam","Jams are perfect for use in a wide variety of products: pastries, puff products, pancakes, dumplings. They are also ideal for use with ice cream, yoghurts, cheese curds, curd masses and other desserts.",j[N],300,0.03 };
	struct product onion = { "onion","widespread vegetable culture, which has been known since the 4th millennium BC. e., and is an important component of a large number of dishes. More than 400 of its species are known in the world for food.",o[N],45, 0.02 };
	struct product porridge = { "porridge","liquid, thick or crumbly food, cereals boiled in water or milk, a dish of cooked cereals or flour",p[N],250,0.1 };
	struct product rice = { "rice","genus of annual and perennial herbaceous plants of the grass family.  Basically, three main types can be distinguished: round-grain, medium-grain and long-grain rice.",r[N],50,0 };
	while (1) {
		printf("Electronic cash register\n");
		printf("1.scan next product\n");
		printf("2.display the description of the scanned product\n");
		printf("3.add data about the product to the receipt\n");
		printf("4.generate a check for the purchase\n");
		printf("5.calculate the total amount payable\n");
		printf("6.Exit\n");
		printf("\n");
		printf("select mode:");
		scanf("%d", &k);
		if ((k > 6) || (k < 1)) {
			do {
				printf("You can choose mode 1-6.Try again:");
				scanf("%d", &k);
			} while ((k > 6) || (k < 1));

		}
		switch (k) {
		case 1: {
			barcode(a);
			if (_c(a, b) == 0) {
				printf("%s\n", bread.name);
				system("pause");
				system("cls");
			}
			else
				if (_c(a, c) == 0) {
					printf("%s\n", cheese.name);
					system("pause");
					system("cls");
				}
				else
					if (_c(a, m) == 0) {
						printf("%s", milk.name);
						system("pause");
						system("cls");
					}
					else
						if (_c(a, s) == 0) {
							printf("%s\n", sausage.name);
							system("pause");
							system("cls");
						}
						else
							if (_c(a, f) == 0) {
								printf("%s\n", fish.name);
								system("pause");
								system("cls");
							}
							else
								if (_c(a, e) == 0) {
									printf("%s\n", egg.name);
									system("pause");
									system("cls");
								}
								else
									if (_c(a, l) == 0) {
										printf("%s\n", lemon.name);
										system("pause");
										system("cls");
									}
									else
										if (_c(a, w) == 0) {
											printf("%s\n", water.name);
											system("pause");
											system("cls");
										}
										else
											if (_c(a, j) == 0) {
												printf("%s\n", jam.name);
												system("pause");
												system("cls");
											}
											else
												if (_c(a, o) == 0) {
													printf("%s\n", onion.name);
													system("pause");
													system("cls");
												}
												else
													if (_c(a, p) == 0) {
														printf("%s\n", porridge.name);
														system("pause");
														system("cls");
													}
													else
														if (_c(a, r) == 0) {
															printf("%s\n", rice.name);
															system("pause");
															system("cls");
														}
														else {
															printf("The barcode you entered does not apply to any of the products.");
															system("pause");
															system("cls");
														}
			break;
		}
		case 2: {
			barcode(a);
			if (_c(a, b) == 0) {
				printf("%s", bread.description);
				system("pause");
				system("cls");
			}
			else
				if (_c(a, c) == 0) {
					printf("%s", cheese.description);
					system("pause");
					system("cls");
				}
				else
					if (_c(a, m) == 0) {
						printf("%s", milk.description);
						system("pause");
						system("cls");
					}
					else
						if (_c(a, s) == 0) {
							printf("%s", sausage.description);
							system("pause");
							system("cls");
						}
						else
							if (_c(a, f) == 0) {
								printf("%s", fish.description);
								system("pause");
								system("cls");
							}
							else
								if (_c(a, e) == 0) {
									printf("%s", egg.description);
									system("pause");
									system("cls");
								}
								else
									if (_c(a, l) == 0) {
										printf("%s", lemon.description);
										system("pause");
										system("cls");
									}
									else
										if (_c(a, w) == 0) {
											printf("%s", water.description);
											system("pause");
											system("cls");
										}
										else
											if (_c(a, o) == 0) {
												printf("%s", onion.description);
												system("pause");
												system("cls");
											}
											else
												if (_c(a, p) == 0) {
													printf("%s", porridge.description);
													system("pause");
													system("cls");
												}
												else
													if (_c(a, r) == 0) {
														printf("%s", rice.description);
														system("pause");
														system("cls");
													}
													else {
														printf("The barcode you entered does not apply to any of the products.");
														system("pause");
														system("cls");
													}
			break;
		}
		case 3: {
			barcode(a);
			int t = 0;
			if (_c(a, b) == 0)
			{
				t = adding();
				if (t == 1) {
					breads++;
					printf("Bread has been added to cart");
					system("pause");
					system("cls");
				}
				if (t == 2) {
					system("pause");
					system("cls");
				}
			}
			else
				if (_c(a, m) == 0)
				{
					t = adding();
					if (t == 1) {
						milks++;
						printf("Milk has been added to cart");
						system("pause");
						system("cls");
					}
					if (t == 2) {
						system("pause");
						system("cls");
					}
				}
				else
					if (_c(a, c) == 0)
					{
						t = adding();
						if (t == 1) {
							cheeses++;
							printf("Cheese has been added to cart");
							system("pause");
							system("cls");
						}
						if (t == 2) {
							system("pause");
							system("cls");
						}
					}
					else
						if (_c(a, s) == 0)
						{
							t = adding();
							if (t == 1) {
								sausages++;
								printf("Sausage has been added to cart");
								system("pause");
								system("cls");
							}
							if (t == 2) {
								system("pause");
								system("cls");
							}
						}
						else
							if (_c(a, f) == 0)
							{
								t = adding();
								if (t == 1) {
									fishes++;
									printf("Fish has been added to cart");
									system("pause");
									system("cls");
								}
								if (t == 2) {
									system("pause");
									system("cls");
								}
							}
							else
								if (_c(a, e) == 0)
								{
									t = adding();
									if (t == 1) {
										eggs++;
										printf("Egg has been added to cart");
										system("pause");
										system("cls");
									}
									if (t == 2) {

										system("pause");
										system("cls");
									}
								}
								else
									if (_c(a, l) == 0)
									{
										t = adding();
										if (t == 1) {
											lemons++;
											printf("Lemon has been added to cart");
											system("pause");
											system("cls");
										}
										if (t == 2) {
											system("pause");
											system("cls");
										}
									}
									else
										if (_c(a, w) == 0)
										{
											t = adding();
											if (t == 1) {
												waters++;
												printf("Water has been added to cart");
												system("pause");
												system("cls");
											}
											if (t == 2) {
												system("pause");
												system("cls");
											}
										}
										else
											if (_c(a, j) == 0)
											{
												t = adding();
												if (t == 1) {
													jams++;
													printf("Jam has been added to cart");
													system("pause");
													system("cls");
												}
												if (t == 2) {
													system("pause");
													system("cls");
												}
											}
											else
												if (_c(a, o) == 0)
												{
													t = adding();
													if (t == 1) {
														onions++;
														printf("Onion has been added to cart");
														system("pause");
														system("cls");
													}
													if (t == 2) {
														system("pause");
														system("cls");
													}
												}
												else
													if (_c(a, p) == 0)
													{
														t = adding();
														if (t == 1) {
															porridges++;
															printf("Porridge has been added to cart");
															system("pause");
															system("cls");
														}
														if (t == 2) {
															system("pause");
															system("cls");
														}
													}
													else
														if (_c(a, r) == 0)
														{
															t = adding();
															if (t == 1) {
																rices++;
																printf("Rice has been added to cart");
																system("pause");
																system("cls");
															}
															if (t == 2) {
																system("pause");
																system("cls");
															}
														}
			break;
		}
		case 4: {
			printf("total check:\n");
			printf("Bread-amount %d and total %lf\n", breads, (double)breads * bread.price * (1 - bread.discount));
			printf("Milk-amount %d and total %lf\n", milks, (double)milks * milk.price * (1 - milk.discount));
			printf("Cheese-amount %d and total %lf\n", cheeses, (double)cheeses * cheese.price * (1 - cheese.discount));
			printf("Sausage-amount %d and total %lf\n", sausages, (double)sausages * sausage.price * (1 - sausage.discount));
			printf("Fish-amount %d and total %lf\n", fishes, (double)fishes * fish.price * (1 - fish.discount));
			printf("Egg-amount %d and total %lf\n", eggs, (double)eggs * egg.price * (1 - egg.discount));
			printf("Lemon-amount %d and total %lf\n", lemons, (double)lemons * lemon.price * (1 - lemon.discount));
			printf("Water-amount %d and total %lf\n", waters, (double)waters * water.price * (1 - water.discount));
			printf("Jam-amount %d and total %lf\n", jams, (double)jams * jam.price * (1 - jam.discount));
			printf("Onion-amount %d and total %lf\n", onions, (double)onions * onion.price * (1 - onion.discount));
			printf("Porridge-amount %d and total %lf\n", porridges, (double)porridges * porridge.price * (1 - porridge.discount));
			printf("Rice-amount %d and total %lf\n", rices, (double)rices * rice.price * (1 - rice.discount));
		}
			  break;
		case 5: {
			double sum;
			sum = (double)breads * bread.price * (1 - bread.discount) + (double)milks * milk.price * (1 - milk.discount) + (double)cheeses * cheese.price * (1 - cheese.discount) + (double)sausages * sausage.price * (1 - sausage.discount) + (double)fishes * fish.price * (1 - fish.discount) + (double)eggs * egg.price * (1 - egg.discount) + (double)lemons * lemon.price * (1 - lemon.discount) + (double)waters * water.price * (1 - water.discount) + (double)jams * jam.price * (1 - jam.discount) + (double)onions * onion.price * (1 - onion.discount) + (double)porridges * porridge.price * (1 - porridge.discount) + (double)rices * rice.price * (1 - rice.discount);
			printf("the total amount is %lf", sum);
			system("pause");
		}
			  break;
		case 6: {
			system("cls");
			return 0; }
		default:
			break;
		}
	}
}

void barcode(int* a) {
	int q;
	int i;
	printf("Enter a 4-digit product barcode:");
	scanf("%d", &q);
	int r = q;
	int counter = 0;
	while (r != 0)
	{
		r /= 10;
		counter++;
	}
	if (counter > 4)
	{
		do {
			counter = 0;
			printf("You scan only a four-digit barcode");
			scanf("%d", &q);
			r = q;
			while (r != 0)
			{
				r /= 10;
				counter++;
			}
		} while (counter > 4);
	}
	while (q > 0) {
		for (i = 3; i >= 0; i--) {
			a[i] = q % 10;
			q /= 10;
		}
	}
}

int adding()
{
	int t;
	printf("Do you want to add a product to your shopping cart? 1-yes, 2- no :");
	scanf("%d", &t);
	if ((t != 1) && (t != 2))
		do {
			printf("You can only answer yes or no ");
			scanf("%d", &t);
		} while ((t != 1) && (t != 2));
		return t;
}
