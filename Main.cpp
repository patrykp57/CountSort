#include <stdio.h>




	void wypelnijTablice(int temp_n, int *temp_tab, int *temp_tab2) {
		int a, b;
	if(temp_n != 0) {
		for (int i = 0; i < temp_n; i++) {
			
			scanf_s("%d %d", &a, &b);
			temp_tab[i] = a;
			temp_tab2[i] = b;
		}
	  }
	}

	void sortowaniePierwszej(int temp_n, int *temp_tab) {
		
		if (temp_n != 0) {
		int *count_tab = new int[temp_n];
		int *container_tab = new int[temp_n];

	
		for (int i = 0; i < temp_n; i++) count_tab[i] = 0;
		for (int i = 0; i < temp_n; i++) count_tab[temp_tab[i]] += 1;
		for (int i = 1; i < temp_n; i++) count_tab[i] += count_tab[i-1];
		for (int i = temp_n - 1; i >= 0; i--) container_tab[--count_tab[temp_tab[i]]] = temp_tab[i];
		for (int i = 0; i < temp_n; i++) printf("%d\n",container_tab[i]);
	}
	}



	void sortowaniePar(int temp_n, int *temp_tab, int *temp_tab2) {
		
		if (temp_n != 0) {
		int *count_tab = new int[temp_n];
		int *container_tab = new int[temp_n];
		int *container_tab2 = new int[temp_n];
		int temp_number;	
			for (int i = 0; i < temp_n; i++) count_tab[i] = 0;
			for (int i = 0; i < temp_n; i++) count_tab[temp_tab[i]] += 1;
			for (int i = 1; i < temp_n; i++) count_tab[i] += count_tab[i - 1];
			for (int i = temp_n - 1; i >= 0; i--) {
				temp_number = --count_tab[temp_tab[i]];

				container_tab2[temp_number] = temp_tab2[i];
				container_tab[temp_number] = temp_tab[i];
			}
			for (int i = 0; i < temp_n; i++) printf("%d,%d\n", container_tab[i], container_tab2[i]);
		}
	}
	 

int main() {
	int n;
	int *tab;
	int *tab2;
	char jakieSortowanie;
	

	scanf_s("%d", &n);
	tab= new int[n];
	tab2= new int[n];
	
	wypelnijTablice(n,tab, tab2);
	scanf_s(" %c", &jakieSortowanie);
	if (jakieSortowanie == '0') {
		sortowaniePierwszej(n, tab);
	}
	if (jakieSortowanie =='1') sortowaniePar(n, tab, tab2);


	
	delete[] tab;
	delete[] tab2;
	return 0;	

	}