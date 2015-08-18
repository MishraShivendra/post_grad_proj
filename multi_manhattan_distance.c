/*
 * File: DIS.C
 * Created on: Apr 28, 2014; 04:15:10 PM 
 * Author: Shivendra Mishra
 * Geany v4.5 (UNICODE)
 * 
 *
 *
 * Environment: Geany with gcc
 * Input: Processed file from system file ./pdata/SCx_/Sx_Sy/Sx_Sy_t.txt      Where x,y are path directions and t is trial.
 * Output: Distance Matrix (70x70 Matrix)
 * Execution: Execute and choose path accordingly from menu.
 * Menu:
 *     1 to 4 : It will generate a distance matrix for THermal data + IR proximity Sensor;  
 *     5 to 8 : It will generate distance matrix only for THermal Imaging Sensor Data;
 *     9 to 12: It will generate distance matrix only for IR Proximity Sensor Data;
 */ 
#include<pthread.h>
#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h> 
// Header files
FILE *src1[8],*src2[8],*tmp[8];       
//int ch;
//char ip_1[100], ip_2[100];
struct fil
{
	char ip[35];                             // Variable for Input file
}links[8][70];

void set_links_1()                                                      // Storing preprocessed file links[0][0]
{
	strcpy(links[0][0].ip,"./pdata/SC1_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][1].ip,"./pdata/SC1_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][2].ip,"./pdata/SC1_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][3].ip,"./pdata/SC1_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][4].ip,"./pdata/SC1_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][5].ip,"./pdata/SC1_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][6].ip,"./pdata/SC1_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][7].ip,"./pdata/SC1_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][8].ip,"./pdata/SC1_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][9].ip,"./pdata/SC1_/S1_S2/S1_S2_10.txt");
	strcpy(links[0][10].ip,"./pdata/SC2_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][11].ip,"./pdata/SC2_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][12].ip,"./pdata/SC2_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][13].ip,"./pdata/SC2_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][14].ip,"./pdata/SC2_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][15].ip,"./pdata/SC2_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][16].ip,"./pdata/SC2_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][17].ip,"./pdata/SC2_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][18].ip,"./pdata/SC2_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][19].ip,"./pdata/SC2_/S1_S2/S1_S2_10.txt");
	strcpy(links[0][20].ip,"./pdata/SC3_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][21].ip,"./pdata/SC3_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][22].ip,"./pdata/SC3_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][23].ip,"./pdata/SC3_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][24].ip,"./pdata/SC3_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][25].ip,"./pdata/SC3_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][26].ip,"./pdata/SC3_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][27].ip,"./pdata/SC3_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][28].ip,"./pdata/SC3_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][29].ip,"./pdata/SC3_/S1_S2/S1_S2_10.txt");
	strcpy(links[0][30].ip,"./pdata/SC4_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][31].ip,"./pdata/SC4_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][32].ip,"./pdata/SC4_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][33].ip,"./pdata/SC4_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][34].ip,"./pdata/SC4_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][35].ip,"./pdata/SC4_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][36].ip,"./pdata/SC4_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][37].ip,"./pdata/SC4_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][38].ip,"./pdata/SC4_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][39].ip,"./pdata/SC4_/S1_S2/S1_S2_10.txt");
	strcpy(links[0][40].ip,"./pdata/SC5_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][41].ip,"./pdata/SC5_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][42].ip,"./pdata/SC5_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][43].ip,"./pdata/SC5_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][44].ip,"./pdata/SC5_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][45].ip,"./pdata/SC5_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][46].ip,"./pdata/SC5_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][47].ip,"./pdata/SC5_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][48].ip,"./pdata/SC5_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][49].ip,"./pdata/SC5_/S1_S2/S1_S2_10.txt");
	strcpy(links[0][50].ip,"./pdata/SC6_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][51].ip,"./pdata/SC6_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][52].ip,"./pdata/SC6_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][53].ip,"./pdata/SC6_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][54].ip,"./pdata/SC6_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][55].ip,"./pdata/SC6_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][56].ip,"./pdata/SC6_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][57].ip,"./pdata/SC6_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][58].ip,"./pdata/SC6_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][59].ip,"./pdata/SC6_/S1_S2/S1_S2_10.txt");
	strcpy(links[0][60].ip,"./pdata/SC7_/S1_S2/S1_S2_1.txt");
	strcpy(links[0][61].ip,"./pdata/SC7_/S1_S2/S1_S2_2.txt");
	strcpy(links[0][62].ip,"./pdata/SC7_/S1_S2/S1_S2_3.txt");
	strcpy(links[0][63].ip,"./pdata/SC7_/S1_S2/S1_S2_4.txt");
	strcpy(links[0][64].ip,"./pdata/SC7_/S1_S2/S1_S2_5.txt");
	strcpy(links[0][65].ip,"./pdata/SC7_/S1_S2/S1_S2_6.txt");
	strcpy(links[0][66].ip,"./pdata/SC7_/S1_S2/S1_S2_7.txt");
	strcpy(links[0][67].ip,"./pdata/SC7_/S1_S2/S1_S2_8.txt");
	strcpy(links[0][68].ip,"./pdata/SC7_/S1_S2/S1_S2_9.txt");
	strcpy(links[0][69].ip,"./pdata/SC7_/S1_S2/S1_S2_10.txt");
}
void set_links_2()
{
	strcpy(links[1][0].ip,"./pdata/SC1_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][1].ip,"./pdata/SC1_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][2].ip,"./pdata/SC1_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][3].ip,"./pdata/SC1_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][4].ip,"./pdata/SC1_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][5].ip,"./pdata/SC1_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][6].ip,"./pdata/SC1_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][7].ip,"./pdata/SC1_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][8].ip,"./pdata/SC1_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][9].ip,"./pdata/SC1_/S2_S1/S2_S1_10.txt");
	strcpy(links[1][10].ip,"./pdata/SC2_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][11].ip,"./pdata/SC2_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][12].ip,"./pdata/SC2_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][13].ip,"./pdata/SC2_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][14].ip,"./pdata/SC2_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][15].ip,"./pdata/SC2_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][16].ip,"./pdata/SC2_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][17].ip,"./pdata/SC2_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][18].ip,"./pdata/SC2_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][19].ip,"./pdata/SC2_/S2_S1/S2_S1_10.txt");
	strcpy(links[1][20].ip,"./pdata/SC3_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][21].ip,"./pdata/SC3_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][22].ip,"./pdata/SC3_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][23].ip,"./pdata/SC3_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][24].ip,"./pdata/SC3_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][25].ip,"./pdata/SC3_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][26].ip,"./pdata/SC3_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][27].ip,"./pdata/SC3_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][28].ip,"./pdata/SC3_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][29].ip,"./pdata/SC3_/S2_S1/S2_S1_10.txt");
	strcpy(links[1][30].ip,"./pdata/SC4_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][31].ip,"./pdata/SC4_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][32].ip,"./pdata/SC4_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][33].ip,"./pdata/SC4_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][34].ip,"./pdata/SC4_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][35].ip,"./pdata/SC4_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][36].ip,"./pdata/SC4_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][37].ip,"./pdata/SC4_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][38].ip,"./pdata/SC4_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][39].ip,"./pdata/SC4_/S2_S1/S2_S1_10.txt");
	strcpy(links[1][40].ip,"./pdata/SC5_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][41].ip,"./pdata/SC5_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][42].ip,"./pdata/SC5_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][43].ip,"./pdata/SC5_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][44].ip,"./pdata/SC5_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][45].ip,"./pdata/SC5_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][46].ip,"./pdata/SC5_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][47].ip,"./pdata/SC5_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][48].ip,"./pdata/SC5_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][49].ip,"./pdata/SC5_/S2_S1/S2_S1_10.txt");
	strcpy(links[1][50].ip,"./pdata/SC6_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][51].ip,"./pdata/SC6_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][52].ip,"./pdata/SC6_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][53].ip,"./pdata/SC6_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][54].ip,"./pdata/SC6_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][55].ip,"./pdata/SC6_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][56].ip,"./pdata/SC6_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][57].ip,"./pdata/SC6_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][58].ip,"./pdata/SC6_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][59].ip,"./pdata/SC6_/S2_S1/S2_S1_10.txt");
	strcpy(links[1][60].ip,"./pdata/SC7_/S2_S1/S2_S1_1.txt");
	strcpy(links[1][61].ip,"./pdata/SC7_/S2_S1/S2_S1_2.txt");
	strcpy(links[1][62].ip,"./pdata/SC7_/S2_S1/S2_S1_3.txt");
	strcpy(links[1][63].ip,"./pdata/SC7_/S2_S1/S2_S1_4.txt");
	strcpy(links[1][64].ip,"./pdata/SC7_/S2_S1/S2_S1_5.txt");
	strcpy(links[1][65].ip,"./pdata/SC7_/S2_S1/S2_S1_6.txt");
	strcpy(links[1][66].ip,"./pdata/SC7_/S2_S1/S2_S1_7.txt");
	strcpy(links[1][67].ip,"./pdata/SC7_/S2_S1/S2_S1_8.txt");
	strcpy(links[1][68].ip,"./pdata/SC7_/S2_S1/S2_S1_9.txt");
	strcpy(links[1][69].ip,"./pdata/SC7_/S2_S1/S2_S1_10.txt");
}
void set_links_3()
{
	strcpy(links[2][0].ip,"./pdata/SC1_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][1].ip,"./pdata/SC1_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][2].ip,"./pdata/SC1_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][3].ip,"./pdata/SC1_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][4].ip,"./pdata/SC1_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][5].ip,"./pdata/SC1_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][6].ip,"./pdata/SC1_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][7].ip,"./pdata/SC1_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][8].ip,"./pdata/SC1_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][9].ip,"./pdata/SC1_/S3_S4/S3_S4_10.txt");
	strcpy(links[2][10].ip,"./pdata/SC2_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][11].ip,"./pdata/SC2_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][12].ip,"./pdata/SC2_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][13].ip,"./pdata/SC2_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][14].ip,"./pdata/SC2_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][15].ip,"./pdata/SC2_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][16].ip,"./pdata/SC2_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][17].ip,"./pdata/SC2_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][18].ip,"./pdata/SC2_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][19].ip,"./pdata/SC2_/S3_S4/S3_S4_10.txt");
	strcpy(links[2][20].ip,"./pdata/SC3_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][21].ip,"./pdata/SC3_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][22].ip,"./pdata/SC3_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][23].ip,"./pdata/SC3_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][24].ip,"./pdata/SC3_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][25].ip,"./pdata/SC3_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][26].ip,"./pdata/SC3_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][27].ip,"./pdata/SC3_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][28].ip,"./pdata/SC3_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][29].ip,"./pdata/SC3_/S3_S4/S3_S4_10.txt");
	strcpy(links[2][30].ip,"./pdata/SC4_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][31].ip,"./pdata/SC4_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][32].ip,"./pdata/SC4_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][33].ip,"./pdata/SC4_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][34].ip,"./pdata/SC4_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][35].ip,"./pdata/SC4_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][36].ip,"./pdata/SC4_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][37].ip,"./pdata/SC4_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][38].ip,"./pdata/SC4_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][39].ip,"./pdata/SC4_/S3_S4/S3_S4_10.txt");
	strcpy(links[2][40].ip,"./pdata/SC5_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][41].ip,"./pdata/SC5_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][42].ip,"./pdata/SC5_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][43].ip,"./pdata/SC5_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][44].ip,"./pdata/SC5_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][45].ip,"./pdata/SC5_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][46].ip,"./pdata/SC5_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][47].ip,"./pdata/SC5_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][48].ip,"./pdata/SC5_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][49].ip,"./pdata/SC5_/S3_S4/S3_S4_10.txt");
	strcpy(links[2][50].ip,"./pdata/SC6_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][51].ip,"./pdata/SC6_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][52].ip,"./pdata/SC6_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][53].ip,"./pdata/SC6_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][54].ip,"./pdata/SC6_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][55].ip,"./pdata/SC6_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][56].ip,"./pdata/SC6_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][57].ip,"./pdata/SC6_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][58].ip,"./pdata/SC6_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][59].ip,"./pdata/SC6_/S3_S4/S3_S4_10.txt");
	strcpy(links[2][60].ip,"./pdata/SC7_/S3_S4/S3_S4_1.txt");
	strcpy(links[2][61].ip,"./pdata/SC7_/S3_S4/S3_S4_2.txt");
	strcpy(links[2][62].ip,"./pdata/SC7_/S3_S4/S3_S4_3.txt");
	strcpy(links[2][63].ip,"./pdata/SC7_/S3_S4/S3_S4_4.txt");
	strcpy(links[2][64].ip,"./pdata/SC7_/S3_S4/S3_S4_5.txt");
	strcpy(links[2][65].ip,"./pdata/SC7_/S3_S4/S3_S4_6.txt");
	strcpy(links[2][66].ip,"./pdata/SC7_/S3_S4/S3_S4_7.txt");
	strcpy(links[2][67].ip,"./pdata/SC7_/S3_S4/S3_S4_8.txt");
	strcpy(links[2][68].ip,"./pdata/SC7_/S3_S4/S3_S4_9.txt");
	strcpy(links[2][69].ip,"./pdata/SC7_/S3_S4/S3_S4_10.txt");
}
void set_links_4()
{
	strcpy(links[3][0].ip,"./pdata/SC1_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][1].ip,"./pdata/SC1_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][2].ip,"./pdata/SC1_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][3].ip,"./pdata/SC1_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][4].ip,"./pdata/SC1_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][5].ip,"./pdata/SC1_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][6].ip,"./pdata/SC1_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][7].ip,"./pdata/SC1_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][8].ip,"./pdata/SC1_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][9].ip,"./pdata/SC1_/S4_S3/S4_S3_10.txt");
	strcpy(links[3][10].ip,"./pdata/SC2_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][11].ip,"./pdata/SC2_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][12].ip,"./pdata/SC2_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][13].ip,"./pdata/SC2_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][14].ip,"./pdata/SC2_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][15].ip,"./pdata/SC2_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][16].ip,"./pdata/SC2_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][17].ip,"./pdata/SC2_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][18].ip,"./pdata/SC2_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][19].ip,"./pdata/SC2_/S4_S3/S4_S3_10.txt");
	strcpy(links[3][20].ip,"./pdata/SC3_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][21].ip,"./pdata/SC3_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][22].ip,"./pdata/SC3_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][23].ip,"./pdata/SC3_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][24].ip,"./pdata/SC3_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][25].ip,"./pdata/SC3_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][26].ip,"./pdata/SC3_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][27].ip,"./pdata/SC3_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][28].ip,"./pdata/SC3_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][29].ip,"./pdata/SC3_/S4_S3/S4_S3_10.txt");
	strcpy(links[3][30].ip,"./pdata/SC4_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][31].ip,"./pdata/SC4_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][32].ip,"./pdata/SC4_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][33].ip,"./pdata/SC4_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][34].ip,"./pdata/SC4_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][35].ip,"./pdata/SC4_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][36].ip,"./pdata/SC4_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][37].ip,"./pdata/SC4_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][38].ip,"./pdata/SC4_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][39].ip,"./pdata/SC4_/S4_S3/S4_S3_10.txt");
	strcpy(links[3][40].ip,"./pdata/SC5_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][41].ip,"./pdata/SC5_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][42].ip,"./pdata/SC5_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][43].ip,"./pdata/SC5_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][44].ip,"./pdata/SC5_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][45].ip,"./pdata/SC5_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][46].ip,"./pdata/SC5_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][47].ip,"./pdata/SC5_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][48].ip,"./pdata/SC5_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][49].ip,"./pdata/SC5_/S4_S3/S4_S3_10.txt");
	strcpy(links[3][50].ip,"./pdata/SC6_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][51].ip,"./pdata/SC6_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][52].ip,"./pdata/SC6_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][53].ip,"./pdata/SC6_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][54].ip,"./pdata/SC6_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][55].ip,"./pdata/SC6_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][56].ip,"./pdata/SC6_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][57].ip,"./pdata/SC6_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][58].ip,"./pdata/SC6_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][59].ip,"./pdata/SC6_/S4_S3/S4_S3_10.txt");
	strcpy(links[3][60].ip,"./pdata/SC7_/S4_S3/S4_S3_1.txt");
	strcpy(links[3][61].ip,"./pdata/SC7_/S4_S3/S4_S3_2.txt");
	strcpy(links[3][62].ip,"./pdata/SC7_/S4_S3/S4_S3_3.txt");
	strcpy(links[3][63].ip,"./pdata/SC7_/S4_S3/S4_S3_4.txt");
	strcpy(links[3][64].ip,"./pdata/SC7_/S4_S3/S4_S3_5.txt");
	strcpy(links[3][65].ip,"./pdata/SC7_/S4_S3/S4_S3_6.txt");
	strcpy(links[3][66].ip,"./pdata/SC7_/S4_S3/S4_S3_7.txt");
	strcpy(links[3][67].ip,"./pdata/SC7_/S4_S3/S4_S3_8.txt");
	strcpy(links[3][68].ip,"./pdata/SC7_/S4_S3/S4_S3_9.txt");
	strcpy(links[3][69].ip,"./pdata/SC7_/S4_S3/S4_S3_10.txt");
}

void set_links_5()
{

	strcpy(links[4][0].ip,"./pdata/SC1_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][1].ip,"./pdata/SC1_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][2].ip,"./pdata/SC1_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][3].ip,"./pdata/SC1_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][4].ip,"./pdata/SC1_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][5].ip,"./pdata/SC1_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][6].ip,"./pdata/SC1_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][7].ip,"./pdata/SC1_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][8].ip,"./pdata/SC1_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][9].ip,"./pdata/SC1_/S5_S6/S5_S6_10.txt");
	strcpy(links[4][10].ip,"./pdata/SC2_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][11].ip,"./pdata/SC2_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][12].ip,"./pdata/SC2_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][13].ip,"./pdata/SC2_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][14].ip,"./pdata/SC2_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][15].ip,"./pdata/SC2_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][16].ip,"./pdata/SC2_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][17].ip,"./pdata/SC2_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][18].ip,"./pdata/SC2_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][19].ip,"./pdata/SC2_/S5_S6/S5_S6_10.txt");
	strcpy(links[4][20].ip,"./pdata/SC3_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][21].ip,"./pdata/SC3_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][22].ip,"./pdata/SC3_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][23].ip,"./pdata/SC3_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][24].ip,"./pdata/SC3_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][25].ip,"./pdata/SC3_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][26].ip,"./pdata/SC3_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][27].ip,"./pdata/SC3_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][28].ip,"./pdata/SC3_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][29].ip,"./pdata/SC3_/S5_S6/S5_S6_10.txt");
	strcpy(links[4][30].ip,"./pdata/SC4_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][31].ip,"./pdata/SC4_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][32].ip,"./pdata/SC4_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][33].ip,"./pdata/SC4_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][34].ip,"./pdata/SC4_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][35].ip,"./pdata/SC4_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][36].ip,"./pdata/SC4_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][37].ip,"./pdata/SC4_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][38].ip,"./pdata/SC4_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][39].ip,"./pdata/SC4_/S5_S6/S5_S6_10.txt");
	strcpy(links[4][40].ip,"./pdata/SC5_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][41].ip,"./pdata/SC5_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][42].ip,"./pdata/SC5_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][43].ip,"./pdata/SC5_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][44].ip,"./pdata/SC5_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][45].ip,"./pdata/SC5_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][46].ip,"./pdata/SC5_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][47].ip,"./pdata/SC5_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][48].ip,"./pdata/SC5_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][49].ip,"./pdata/SC5_/S5_S6/S5_S6_10.txt");
	strcpy(links[4][50].ip,"./pdata/SC6_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][51].ip,"./pdata/SC6_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][52].ip,"./pdata/SC6_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][53].ip,"./pdata/SC6_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][54].ip,"./pdata/SC6_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][55].ip,"./pdata/SC6_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][56].ip,"./pdata/SC6_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][57].ip,"./pdata/SC6_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][58].ip,"./pdata/SC6_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][59].ip,"./pdata/SC6_/S5_S6/S5_S6_10.txt");
	strcpy(links[4][60].ip,"./pdata/SC7_/S5_S6/S5_S6_1.txt");
	strcpy(links[4][61].ip,"./pdata/SC7_/S5_S6/S5_S6_2.txt");
	strcpy(links[4][62].ip,"./pdata/SC7_/S5_S6/S5_S6_3.txt");
	strcpy(links[4][63].ip,"./pdata/SC7_/S5_S6/S5_S6_4.txt");
	strcpy(links[4][64].ip,"./pdata/SC7_/S5_S6/S5_S6_5.txt");
	strcpy(links[4][65].ip,"./pdata/SC7_/S5_S6/S5_S6_6.txt");
	strcpy(links[4][66].ip,"./pdata/SC7_/S5_S6/S5_S6_7.txt");
	strcpy(links[4][67].ip,"./pdata/SC7_/S5_S6/S5_S6_8.txt");
	strcpy(links[4][68].ip,"./pdata/SC7_/S5_S6/S5_S6_9.txt");
	strcpy(links[4][69].ip,"./pdata/SC7_/S5_S6/S5_S6_10.txt"); 
}

void set_links_6()
{
	strcpy(links[5][0].ip,"./pdata/SC1_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][1].ip,"./pdata/SC1_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][2].ip,"./pdata/SC1_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][3].ip,"./pdata/SC1_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][4].ip,"./pdata/SC1_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][5].ip,"./pdata/SC1_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][6].ip,"./pdata/SC1_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][7].ip,"./pdata/SC1_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][8].ip,"./pdata/SC1_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][9].ip,"./pdata/SC1_/S6_S5/S6_S5_10.txt");
	strcpy(links[5][10].ip,"./pdata/SC2_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][11].ip,"./pdata/SC2_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][12].ip,"./pdata/SC2_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][13].ip,"./pdata/SC2_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][14].ip,"./pdata/SC2_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][15].ip,"./pdata/SC2_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][16].ip,"./pdata/SC2_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][17].ip,"./pdata/SC2_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][18].ip,"./pdata/SC2_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][19].ip,"./pdata/SC2_/S6_S5/S6_S5_10.txt");
	strcpy(links[5][20].ip,"./pdata/SC3_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][21].ip,"./pdata/SC3_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][22].ip,"./pdata/SC3_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][23].ip,"./pdata/SC3_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][24].ip,"./pdata/SC3_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][25].ip,"./pdata/SC3_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][26].ip,"./pdata/SC3_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][27].ip,"./pdata/SC3_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][28].ip,"./pdata/SC3_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][29].ip,"./pdata/SC3_/S6_S5/S6_S5_10.txt");
	strcpy(links[5][30].ip,"./pdata/SC4_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][31].ip,"./pdata/SC4_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][32].ip,"./pdata/SC4_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][33].ip,"./pdata/SC4_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][34].ip,"./pdata/SC4_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][35].ip,"./pdata/SC4_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][36].ip,"./pdata/SC4_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][37].ip,"./pdata/SC4_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][38].ip,"./pdata/SC4_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][39].ip,"./pdata/SC4_/S6_S5/S6_S5_10.txt");
	strcpy(links[5][40].ip,"./pdata/SC5_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][41].ip,"./pdata/SC5_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][42].ip,"./pdata/SC5_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][43].ip,"./pdata/SC5_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][44].ip,"./pdata/SC5_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][45].ip,"./pdata/SC5_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][46].ip,"./pdata/SC5_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][47].ip,"./pdata/SC5_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][48].ip,"./pdata/SC5_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][49].ip,"./pdata/SC5_/S6_S5/S6_S5_10.txt");
	strcpy(links[5][50].ip,"./pdata/SC6_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][51].ip,"./pdata/SC6_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][52].ip,"./pdata/SC6_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][53].ip,"./pdata/SC6_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][54].ip,"./pdata/SC6_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][55].ip,"./pdata/SC6_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][56].ip,"./pdata/SC6_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][57].ip,"./pdata/SC6_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][58].ip,"./pdata/SC6_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][59].ip,"./pdata/SC6_/S6_S5/S6_S5_10.txt");
	strcpy(links[5][60].ip,"./pdata/SC7_/S6_S5/S6_S5_1.txt");
	strcpy(links[5][61].ip,"./pdata/SC7_/S6_S5/S6_S5_2.txt");
	strcpy(links[5][62].ip,"./pdata/SC7_/S6_S5/S6_S5_3.txt");
	strcpy(links[5][63].ip,"./pdata/SC7_/S6_S5/S6_S5_4.txt");
	strcpy(links[5][64].ip,"./pdata/SC7_/S6_S5/S6_S5_5.txt");
	strcpy(links[5][65].ip,"./pdata/SC7_/S6_S5/S6_S5_6.txt");
	strcpy(links[5][66].ip,"./pdata/SC7_/S6_S5/S6_S5_7.txt");
	strcpy(links[5][67].ip,"./pdata/SC7_/S6_S5/S6_S5_8.txt");
	strcpy(links[5][68].ip,"./pdata/SC7_/S6_S5/S6_S5_9.txt");
	strcpy(links[5][69].ip,"./pdata/SC7_/S6_S5/S6_S5_10.txt"); 

}

void set_links_7()
{

	strcpy(links[6][0].ip,"./pdata/SC1_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][1].ip,"./pdata/SC1_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][2].ip,"./pdata/SC1_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][3].ip,"./pdata/SC1_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][4].ip,"./pdata/SC1_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][5].ip,"./pdata/SC1_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][6].ip,"./pdata/SC1_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][7].ip,"./pdata/SC1_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][8].ip,"./pdata/SC1_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][9].ip,"./pdata/SC1_/S7_S8/S7_S8_10.txt");
	strcpy(links[6][10].ip,"./pdata/SC2_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][11].ip,"./pdata/SC2_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][12].ip,"./pdata/SC2_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][13].ip,"./pdata/SC2_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][14].ip,"./pdata/SC2_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][15].ip,"./pdata/SC2_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][16].ip,"./pdata/SC2_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][17].ip,"./pdata/SC2_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][18].ip,"./pdata/SC2_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][19].ip,"./pdata/SC2_/S7_S8/S7_S8_10.txt");
	strcpy(links[6][20].ip,"./pdata/SC3_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][21].ip,"./pdata/SC3_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][22].ip,"./pdata/SC3_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][23].ip,"./pdata/SC3_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][24].ip,"./pdata/SC3_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][25].ip,"./pdata/SC3_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][26].ip,"./pdata/SC3_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][27].ip,"./pdata/SC3_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][28].ip,"./pdata/SC3_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][29].ip,"./pdata/SC3_/S7_S8/S7_S8_10.txt");
	strcpy(links[6][30].ip,"./pdata/SC4_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][31].ip,"./pdata/SC4_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][32].ip,"./pdata/SC4_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][33].ip,"./pdata/SC4_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][34].ip,"./pdata/SC4_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][35].ip,"./pdata/SC4_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][36].ip,"./pdata/SC4_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][37].ip,"./pdata/SC4_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][38].ip,"./pdata/SC4_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][39].ip,"./pdata/SC4_/S7_S8/S7_S8_10.txt");
	strcpy(links[6][40].ip,"./pdata/SC5_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][41].ip,"./pdata/SC5_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][42].ip,"./pdata/SC5_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][43].ip,"./pdata/SC5_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][44].ip,"./pdata/SC5_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][45].ip,"./pdata/SC5_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][46].ip,"./pdata/SC5_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][47].ip,"./pdata/SC5_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][48].ip,"./pdata/SC5_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][49].ip,"./pdata/SC5_/S7_S8/S7_S8_10.txt");
	strcpy(links[6][50].ip,"./pdata/SC6_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][51].ip,"./pdata/SC6_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][52].ip,"./pdata/SC6_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][53].ip,"./pdata/SC6_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][54].ip,"./pdata/SC6_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][55].ip,"./pdata/SC6_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][56].ip,"./pdata/SC6_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][57].ip,"./pdata/SC6_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][58].ip,"./pdata/SC6_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][59].ip,"./pdata/SC6_/S7_S8/S7_S8_10.txt");
	strcpy(links[6][60].ip,"./pdata/SC7_/S7_S8/S7_S8_1.txt");
	strcpy(links[6][61].ip,"./pdata/SC7_/S7_S8/S7_S8_2.txt");
	strcpy(links[6][62].ip,"./pdata/SC7_/S7_S8/S7_S8_3.txt");
	strcpy(links[6][63].ip,"./pdata/SC7_/S7_S8/S7_S8_4.txt");
	strcpy(links[6][64].ip,"./pdata/SC7_/S7_S8/S7_S8_5.txt");
	strcpy(links[6][65].ip,"./pdata/SC7_/S7_S8/S7_S8_6.txt");
	strcpy(links[6][66].ip,"./pdata/SC7_/S7_S8/S7_S8_7.txt");
	strcpy(links[6][67].ip,"./pdata/SC7_/S7_S8/S7_S8_8.txt");
	strcpy(links[6][68].ip,"./pdata/SC7_/S7_S8/S7_S8_9.txt");
	strcpy(links[6][69].ip,"./pdata/SC7_/S7_S8/S7_S8_10.txt");

}

void set_links_8()
{

	strcpy(links[7][0].ip,"./pdata/SC1_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][1].ip,"./pdata/SC1_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][2].ip,"./pdata/SC1_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][3].ip,"./pdata/SC1_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][4].ip,"./pdata/SC1_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][5].ip,"./pdata/SC1_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][6].ip,"./pdata/SC1_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][7].ip,"./pdata/SC1_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][8].ip,"./pdata/SC1_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][9].ip,"./pdata/SC1_/S8_S7/S8_S7_10.txt");
	strcpy(links[7][10].ip,"./pdata/SC2_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][11].ip,"./pdata/SC2_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][12].ip,"./pdata/SC2_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][13].ip,"./pdata/SC2_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][14].ip,"./pdata/SC2_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][15].ip,"./pdata/SC2_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][16].ip,"./pdata/SC2_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][17].ip,"./pdata/SC2_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][18].ip,"./pdata/SC2_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][19].ip,"./pdata/SC2_/S8_S7/S8_S7_10.txt");
	strcpy(links[7][20].ip,"./pdata/SC3_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][21].ip,"./pdata/SC3_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][22].ip,"./pdata/SC3_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][23].ip,"./pdata/SC3_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][24].ip,"./pdata/SC3_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][25].ip,"./pdata/SC3_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][26].ip,"./pdata/SC3_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][27].ip,"./pdata/SC3_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][28].ip,"./pdata/SC3_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][29].ip,"./pdata/SC3_/S8_S7/S8_S7_10.txt");
	strcpy(links[7][30].ip,"./pdata/SC4_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][31].ip,"./pdata/SC4_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][32].ip,"./pdata/SC4_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][33].ip,"./pdata/SC4_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][34].ip,"./pdata/SC4_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][35].ip,"./pdata/SC4_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][36].ip,"./pdata/SC4_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][37].ip,"./pdata/SC4_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][38].ip,"./pdata/SC4_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][39].ip,"./pdata/SC4_/S8_S7/S8_S7_10.txt");
	strcpy(links[7][40].ip,"./pdata/SC5_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][41].ip,"./pdata/SC5_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][42].ip,"./pdata/SC5_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][43].ip,"./pdata/SC5_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][44].ip,"./pdata/SC5_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][45].ip,"./pdata/SC5_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][46].ip,"./pdata/SC5_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][47].ip,"./pdata/SC5_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][48].ip,"./pdata/SC5_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][49].ip,"./pdata/SC5_/S8_S7/S8_S7_10.txt");
	strcpy(links[7][50].ip,"./pdata/SC6_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][51].ip,"./pdata/SC6_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][52].ip,"./pdata/SC6_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][53].ip,"./pdata/SC6_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][54].ip,"./pdata/SC6_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][55].ip,"./pdata/SC6_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][56].ip,"./pdata/SC6_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][57].ip,"./pdata/SC6_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][58].ip,"./pdata/SC6_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][59].ip,"./pdata/SC6_/S8_S7/S8_S7_10.txt");
	strcpy(links[7][60].ip,"./pdata/SC7_/S8_S7/S8_S7_1.txt");
	strcpy(links[7][61].ip,"./pdata/SC7_/S8_S7/S8_S7_2.txt");
	strcpy(links[7][62].ip,"./pdata/SC7_/S8_S7/S8_S7_3.txt");
	strcpy(links[7][63].ip,"./pdata/SC7_/S8_S7/S8_S7_4.txt");
	strcpy(links[7][64].ip,"./pdata/SC7_/S8_S7/S8_S7_5.txt");
	strcpy(links[7][65].ip,"./pdata/SC7_/S8_S7/S8_S7_6.txt");
	strcpy(links[7][66].ip,"./pdata/SC7_/S8_S7/S8_S7_7.txt");
	strcpy(links[7][67].ip,"./pdata/SC7_/S8_S7/S8_S7_8.txt");
	strcpy(links[7][68].ip,"./pdata/SC7_/S8_S7/S8_S7_9.txt");
	strcpy(links[7][69].ip,"./pdata/SC7_/S8_S7/S8_S7_10.txt");
}
char *label(int pt, int no)                                          // This function will return a file label as SCx_Sy_Sz_t
{                                                             // Argument is location of file.
	char buff[35],*temp;                                      // As e.g. Menu choice: 04; Argument = 69 will return SC7_S4_S3_10 (i.e.) Scenario 7, S4_S3 path, Trial 10; 
	int i=0,j=0,count=0;                                         // It will be used for distance matrix heading
	temp = (char *)malloc(15);
	strcpy(buff,links[pt][no].ip);                                   
	while(1)
	{
		if(buff[i] == '.')
		{
			break;
		}
		else if(buff[i]=='/')
		{
			count++;
		}
		else if(count==2)
		{
			temp[j] = buff[i];
			j++;
		}
		else if(count==4)
		{
			temp[j] = buff[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	return temp;
}
void open_res()                              // Opening file for Path 1
{
	tmp[0] = fopen("1.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp");
		//getch();
	}
}
void open_res_2()                         // Opening file for path 2
{
	tmp[1] = fopen("2.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp2");
		//getch();
	}
}
void open_res_3()                              // Opening file for path 2
{
	tmp[2] = fopen("3.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp3");
		//getch();
	}
}
void open_res_4()                            // Opening file for path 2
{
	tmp[3] = fopen("4.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp4");
		//getch();
	}
}


void open_res_5()                              // Opening file for Path 1
{
	tmp[4] = fopen("5.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp5");
		//getch();
	}
}
void open_res_6()                         // Opening file for path 2
{
	tmp[5] = fopen("6.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp6");
		//getch();
	}
}
void open_res_7()                              // Opening file for path 2
{
	tmp[6] = fopen("7.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp7");
		//getch();
	}
}

void open_res_8()                            // Opening file for path 2
{
	tmp[7] = fopen("8.txt", "w");
	if(tmp == NULL )
	{
		perror("\n tmp8");
		//getch();
	}
}


void open_fil(int pt, int sr1, int sr2)                             // open file for calculating distance
{                                                           // Argument is link number of input file
	src1[pt] = fopen(links[pt][sr1].ip, "r");                       // Open file 1 and 2
	src2[pt] = fopen(links[pt][sr2].ip, "r");

	if(src1[pt] == NULL )
	{
		perror(links[pt][sr1].ip);
		// printf("(%s)",links[sr1].ip);
		//getch();
	}
	if(src2[pt] == NULL )
	{
		perror(links[pt][sr2].ip);
		//printf("(%s)",links[sr2].ip);
		//getch();
	} 
}


float cal_dis_nt(int pt)                                       //This function calculates distance without threshold
{                                                        // THis function is used for choice : 1,2,3,4;

	char tmp1[20],tmp2[20];
	int k,count=0;
	float sum=0;
	float val1,val2;
	for(k=1;k<=6;k++)
	{
		fscanf(src1[pt],"%s",tmp1);
		fscanf(src2[pt],"%s",tmp2);
	}
	while(fscanf(src1[pt],"%s",tmp1) != EOF)
	{
		if(fscanf(src2[pt],"%s",tmp2) == EOF)
		{
			break;
		}
		else
		{
			//printf("\n%d:%s\t%s",count,tmp1,tmp2);
			////getch();
			if(atof(tmp1)>atof(tmp2))
			{
				sum = sum + (atof(tmp1)-atof(tmp2));
			}
			else if(atof(tmp1)<atof(tmp2))
			{
				sum = sum + (atof(tmp2)-atof(tmp1));
			}      
		}

	}
	return sum;
}
void close_al(int pt)
{
	fclose(src1[pt]);
	fclose(src2[pt]);

}
void close_res(int pt)
{
	fclose(tmp[pt]);
}
void write_res(int pt)                                          // This function writes distance results to a excel file
{
	int i,j;
	float ret;
	fprintf(tmp[pt],"\t");
	for(i=0;i<=69;i++)
	{
		fprintf(tmp[pt],"%s\t",label(pt,i));
	}
	fprintf(tmp[pt],"\n");
	for(i=0;i<=69;i++)
	{
		fprintf(tmp[pt],"%s\t",label(pt,i));
		for(j=0;j<=69;j++)
		{
			open_fil(pt,i,j);
			ret = cal_dis_nt(pt);
			fprintf(tmp[pt],"%.1f\t",ret);
			//printf("\nCalculating Distance of file[%d] and file [%d]....",i,j);
			close_al(pt);
		}
		fprintf(tmp[pt],"\n");
	}
}
void* our_fn(int *pt)
{
	int ch = (*pt);
	switch(ch)
	{
		case 0:
			set_links_1();
			open_res();
			write_res(ch);
			close_res(ch);
			break;
		case 1:
			set_links_2();
			open_res_2();
			write_res(ch);
			close_res(ch);
			break;
		case 2:
			set_links_3();
			open_res_3();
			write_res(ch);
			close_res(ch); 
			break;
		case 3:
			set_links_4();
			open_res_4();
			write_res(ch);
			close_res(ch);
			break;
		case 4:
			set_links_5();
			open_res_5();
			write_res(ch);
			close_res(ch); 
			break;
		case 5:
			set_links_6();
			open_res_6();
			write_res(ch);
			close_res(ch); 
			break;
		case 6:
			set_links_7();
			open_res_7();
			write_res(ch);
			close_res(ch);
			break;
		case 7:
			set_links_8();
			open_res_8();
			write_res(ch);
			close_res(ch);  	 
			break;	
	}
	pthread_exit(0);
}
int main()                                  // Main function
{                                            // Menu explains code block
	int i;
	char my_err[20];
	pthread_t th[8];
	for(i=0;i<=7;i++)
	{
		if(pthread_create(&th[i],NULL,(void *) &our_fn,(void *) &i)) 
		{
			sprintf(my_err,"create[%d]",i);
			perror(my_err);

		}
	}
	for(i=0;i<=7;i++)
	{
		if(pthread_join(th[i],NULL))
		{
			sprintf(my_err,"Join[%d]",i);
			perror(my_err);
		}
	}		 	 
	return 0;	
}




