#include<stdio.h>
#include<cstdlib>
#define size 40
#define msize 25


void parr(int ar[25]);
void prmat(int matr[msize][msize][10], int);
int t4(int ar6[msize][msize][10], int);

int main()
{
	int mat[msize][msize][10];     //es erachap zangvac a A matrici u mnacac matricneri hamar
	int mat1[size][2] = { {1,15},{1,13},{1,17},{1,19},{1,25},{1,9},{2,3},{3,12},{4,5},{5,9},{6,14},{7,0},{8,7},{9,0},{10,7},{11,0},{12,11},{13,9},{14,0},{15,17},{16,13},{17,14},{18,7},{19,18},{20,21},{21,8},{22,20},{22,10},{22,6},{22,18},{23,25},{23,19},{23,13},{24,2},{24,10},{24,16},{24,4},{24,6},{24,20},{25,3} };
	int k = 0, i = 0, j, m, n; float ep = 0;
	/*
	Printf("Nermuceq Epsilon tiv@ ");
	scanf("%f", &ep);
	printf("Ushadir nermuceq tarreri mijev kaper@ iraric 1 probel heravorutyamb");
	while(scanf("%d %d", &mat1[i][0], &mat1[i][1])==2) //ES MOMENT@ PTI DZVI HL@
	{i++;};*/
	i = size;
	for (j = 0; j < i; j++)                                 //dnum a 1 hamapatasxan texerum
	{
		if (mat1[j][1] != 0)
			mat[mat1[j][0] - 1][mat1[j][1] - 1][0] = 1;
		else
			mat[mat1[j][0] - 1][mat1[j][1]][0] = 0; //elqayin tarreri hamar
	};
	for (m = 0; m < msize; m++)							   //dnum a 0 mnacac texerum
		for (n = 0; n < msize; n++)
		{
			if (mat[m][n][0] != 1)
			{
				mat[m][n][0] = 0;
			};
		};



	for (m = 0, n = 0; m < msize, n < msize; m++, n++)         //nayum a ankyunagcum 1 chlni
		if (mat[m][n][0] == 1)
		{
			printf("Ankyunagcum ka 1!! Ushadir nermuceq tver@!\n");
			return 0;
		};




	printf("A matric@ uni hetevyal tesq@\n");
	prmat(mat, 0);



	int arr1[25] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 }, t1 = 0;   //stex hashvum a t1-@
	for (m = 0; m < i; m++)
		arr1[mat1[m][1] - 1] = 0;
	for (m = 0; m < 25; m++)
		if (arr1[m] != 0) t1++;
	printf("Mutqayin tarrer: t1=%d  ", t1);
	parr(arr1);


	int arr2[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, t2 = 0;         //hashvum a t2-@ u t3-@
	int t3 = 0, arr3[25] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (m = 0; m < i; m++)
		for (n = 0; n < i; n++)
		{
			if (mat1[m][0] == mat1[n][1])
			{
				arr2[mat1[m][0] - 1] = mat1[m][0];
			};
		};
	for (m = 0; m < i; m++)
	{
		if (mat1[m][1] == 0)
		{
			arr2[mat1[m][0] - 1] = 0;
			arr3[mat1[m][0] - 1] = mat1[m][0];
			t3++;
		};
	};

	for (m = 0; m < 25; m++)
	{
		if (arr2[m] != 0)
			t2++;
	};
	printf("Mijankyal tarrer: t2=%d  ", t2);
	parr(arr2);
	printf("Elqayin tarrer: t3=%d  ", t3);
	parr(arr3);
	int t7 = t4(mat, 0) - 1;
	float Kmo = (float)t7 / (float)(t7 + 1);
	float kmij = Kmo;
	printf("Tvyal matrici hamar t7=%d\n", t7);
	printf("Tvyal matrici hamar Kmo=%.3f\n\n", Kmo);

	int t;								//bolor matricneri tarrer@ 0 a darcnum
	for (t = 1; t < 10; t++)
		for (m = 0; m < msize; m++)
			for (n = 0; n < msize; n++)
				mat[m][n][t] = 0;

	int c = 0, r = 0, g = 0;				//bazmapatkum a matricner@
	for (j = 1; j < 10; j++)
		for (m = 0; m < msize; m++)
			for (n = 0; n < msize; n++)
				for (k = 0; k < msize; k++)
					mat[m][n][j] = mat[m][n][j] + mat[m][k][j - 1] * mat[k][n][0];



	t = 0;
	for (j = 1; j < 10; j++)								//esel lriv tarrer@ 0 matricner@ hashvelu hamar
	{
		g = 0;
		for (m = 0; m < msize; m++)
			for (n = 0; n < msize; n++)
				if (mat[m][n][j] == 0)
				{
					g++;
					if (g == 625)
						t++;
				};
	}

	printf("A2 matric@ uni hetevyal tesq@");
	for (k = 1; k < 10 - t; k++)							//tpum a mnacac matricner@
	{
		prmat(mat, k);
		t7 = t4(mat, k) - (k + 1);
		Kmo = (float)t7 / (float)(t7 + k + 1);
		kmij += Kmo;
		printf("Tvyal matrici hamar t7=%d\n", t7);
		printf("Tvyal matrici hamar Kmo=%.3f\n\n\n", Kmo);
		if (k == 9 - t)
			printf("Delta matric@ uni hetevyal tesq@");
		else
			printf("A%d matric@ uni hetevyal tesq@", k + 2);
	};

	for (j = 0; j < 10 - t; j++)			//hashvum a delta matric@
		for (m = 0; m < msize; m++)
			for (n = 0; n < msize; n++)
				mat[m][n][10 - t] += mat[m][n][j];
	prmat(mat, 10 - t);
	t4(mat, 10 - t);
	printf("Ays hamakargi hamar Kmo(mij)=%.3f\n", kmij / (float)(10 - t));
	float Km = (float)t2 / (float)msize;
	printf("Ays hamakargi hamar Km=%.3f\n", Km);
	if ((Km - kmij) < ep)
		printf("Hamakargum pastatxtashrjanarutyun@ kazmakerpvac e racional!");
	system("pause");
	return 0;
}

void parr(int ar[25])
{
	printf(" {");
	for (int n = 0; n < 25; n++)
	{
		if (ar[n] != 0)
			printf("%d,", ar[n]);
	};
	printf("}\n");
}

void prmat(int matr[msize][msize][10], int q)
{
	int m, n;
	printf("\n");
	for (m = 0; m < msize; m++)
		for (n = 0; n < msize; n++)
		{
			printf("%d ", matr[m][n][q]);
			if (n == msize - 1)
				printf("\n");
			if (m == msize - 1 && n == msize - 1)
				printf("\n");
		};
}

int t4(int ar6[msize][msize][10], int a)
{
	int s = 0, t4 = 0, i, j;
	for (i = 0; i < msize; i++)
	{
		s = 0;
		for (j = 0; j < msize; j++)
			s += ar6[j][i][a];
		if (s == 0)
			t4++;
	}
	printf("Tvyal matrici hamar t4=%d\n", t4);
	return t4;
}
