/*
 * File: DIS.C
 * Created on: Apr 28, 2014; 04:15:10 PM 
 * Author: Shivendra Mishra
 * Notepad++ v6.5.5 (UNICODE)
 * 
 *
 *
 * Environment: Notepad++ with Borland C++ V5.5
 * Input: Processed file from system file c:/pdata/SCx_/Sx_Sy/Sx_Sy_t.xls      Where x,y are path directions and t is trial.
 * Output: Distance Matrix (70x70 Matrix)
 * Execution: Execute and choose path accordingly from menu.
 * Menu:
 *     1 to 4 : It will generate a distance matrix for THermal data + IR proximity Sensor;  
 *     5 to 8 : It will generate distance matrix only for THermal Imaging Sensor Data;
 *     9 to 12: It will generate distance matrix only for IR Proximity Sensor Data;
 */ 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>                 // Header files
FILE *src1,*src2,*tmp;       
int ch;
char ip_1[100], ip_2[100];
struct fil
{
	char ip[35];                             // Variable for Input file
}links[100];
struct mm
{
	float l_max,l_min,r_max,r_min;
}sin[7];
void set_links_1()                                                      // Storing preprocessed file links
{
	strcpy(links[0].ip,"C:/pdata/SC1_/S1_S2/S1_S2_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S1_S2/S1_S2_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S1_S2/S1_S2_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S1_S2/S1_S2_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S1_S2/S1_S2_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S1_S2/S1_S2_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S1_S2/S1_S2_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S1_S2/S1_S2_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S1_S2/S1_S2_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S1_S2/S1_S2_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S1_S2/S1_S2_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S1_S2/S1_S2_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S1_S2/S1_S2_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S1_S2/S1_S2_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S1_S2/S1_S2_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S1_S2/S1_S2_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S1_S2/S1_S2_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S1_S2/S1_S2_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S1_S2/S1_S2_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S1_S2/S1_S2_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S1_S2/S1_S2_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S1_S2/S1_S2_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S1_S2/S1_S2_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S1_S2/S1_S2_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S1_S2/S1_S2_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S1_S2/S1_S2_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S1_S2/S1_S2_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S1_S2/S1_S2_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S1_S2/S1_S2_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S1_S2/S1_S2_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S1_S2/S1_S2_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S1_S2/S1_S2_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S1_S2/S1_S2_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S1_S2/S1_S2_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S1_S2/S1_S2_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S1_S2/S1_S2_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S1_S2/S1_S2_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S1_S2/S1_S2_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S1_S2/S1_S2_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S1_S2/S1_S2_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S1_S2/S1_S2_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S1_S2/S1_S2_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S1_S2/S1_S2_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S1_S2/S1_S2_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S1_S2/S1_S2_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S1_S2/S1_S2_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S1_S2/S1_S2_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S1_S2/S1_S2_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S1_S2/S1_S2_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S1_S2/S1_S2_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S1_S2/S1_S2_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S1_S2/S1_S2_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S1_S2/S1_S2_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S1_S2/S1_S2_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S1_S2/S1_S2_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S1_S2/S1_S2_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S1_S2/S1_S2_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S1_S2/S1_S2_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S1_S2/S1_S2_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S1_S2/S1_S2_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S1_S2/S1_S2_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S1_S2/S1_S2_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S1_S2/S1_S2_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S1_S2/S1_S2_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S1_S2/S1_S2_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S1_S2/S1_S2_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S1_S2/S1_S2_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S1_S2/S1_S2_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S1_S2/S1_S2_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S1_S2/S1_S2_10.XLS");
}
void set_links_2()
{
	strcpy(links[0].ip,"C:/pdata/SC1_/S2_S1/S2_S1_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S2_S1/S2_S1_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S2_S1/S2_S1_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S2_S1/S2_S1_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S2_S1/S2_S1_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S2_S1/S2_S1_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S2_S1/S2_S1_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S2_S1/S2_S1_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S2_S1/S2_S1_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S2_S1/S2_S1_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S2_S1/S2_S1_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S2_S1/S2_S1_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S2_S1/S2_S1_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S2_S1/S2_S1_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S2_S1/S2_S1_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S2_S1/S2_S1_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S2_S1/S2_S1_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S2_S1/S2_S1_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S2_S1/S2_S1_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S2_S1/S2_S1_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S2_S1/S2_S1_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S2_S1/S2_S1_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S2_S1/S2_S1_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S2_S1/S2_S1_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S2_S1/S2_S1_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S2_S1/S2_S1_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S2_S1/S2_S1_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S2_S1/S2_S1_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S2_S1/S2_S1_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S2_S1/S2_S1_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S2_S1/S2_S1_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S2_S1/S2_S1_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S2_S1/S2_S1_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S2_S1/S2_S1_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S2_S1/S2_S1_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S2_S1/S2_S1_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S2_S1/S2_S1_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S2_S1/S2_S1_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S2_S1/S2_S1_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S2_S1/S2_S1_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S2_S1/S2_S1_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S2_S1/S2_S1_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S2_S1/S2_S1_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S2_S1/S2_S1_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S2_S1/S2_S1_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S2_S1/S2_S1_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S2_S1/S2_S1_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S2_S1/S2_S1_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S2_S1/S2_S1_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S2_S1/S2_S1_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S2_S1/S2_S1_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S2_S1/S2_S1_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S2_S1/S2_S1_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S2_S1/S2_S1_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S2_S1/S2_S1_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S2_S1/S2_S1_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S2_S1/S2_S1_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S2_S1/S2_S1_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S2_S1/S2_S1_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S2_S1/S2_S1_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S2_S1/S2_S1_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S2_S1/S2_S1_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S2_S1/S2_S1_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S2_S1/S2_S1_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S2_S1/S2_S1_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S2_S1/S2_S1_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S2_S1/S2_S1_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S2_S1/S2_S1_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S2_S1/S2_S1_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S2_S1/S2_S1_10.XLS");
}
void set_links_3()
{
	strcpy(links[0].ip,"C:/pdata/SC1_/S3_S4/S3_S4_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S3_S4/S3_S4_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S3_S4/S3_S4_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S3_S4/S3_S4_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S3_S4/S3_S4_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S3_S4/S3_S4_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S3_S4/S3_S4_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S3_S4/S3_S4_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S3_S4/S3_S4_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S3_S4/S3_S4_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S3_S4/S3_S4_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S3_S4/S3_S4_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S3_S4/S3_S4_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S3_S4/S3_S4_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S3_S4/S3_S4_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S3_S4/S3_S4_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S3_S4/S3_S4_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S3_S4/S3_S4_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S3_S4/S3_S4_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S3_S4/S3_S4_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S3_S4/S3_S4_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S3_S4/S3_S4_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S3_S4/S3_S4_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S3_S4/S3_S4_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S3_S4/S3_S4_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S3_S4/S3_S4_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S3_S4/S3_S4_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S3_S4/S3_S4_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S3_S4/S3_S4_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S3_S4/S3_S4_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S3_S4/S3_S4_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S3_S4/S3_S4_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S3_S4/S3_S4_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S3_S4/S3_S4_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S3_S4/S3_S4_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S3_S4/S3_S4_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S3_S4/S3_S4_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S3_S4/S3_S4_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S3_S4/S3_S4_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S3_S4/S3_S4_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S3_S4/S3_S4_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S3_S4/S3_S4_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S3_S4/S3_S4_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S3_S4/S3_S4_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S3_S4/S3_S4_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S3_S4/S3_S4_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S3_S4/S3_S4_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S3_S4/S3_S4_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S3_S4/S3_S4_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S3_S4/S3_S4_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S3_S4/S3_S4_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S3_S4/S3_S4_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S3_S4/S3_S4_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S3_S4/S3_S4_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S3_S4/S3_S4_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S3_S4/S3_S4_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S3_S4/S3_S4_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S3_S4/S3_S4_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S3_S4/S3_S4_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S3_S4/S3_S4_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S3_S4/S3_S4_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S3_S4/S3_S4_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S3_S4/S3_S4_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S3_S4/S3_S4_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S3_S4/S3_S4_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S3_S4/S3_S4_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S3_S4/S3_S4_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S3_S4/S3_S4_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S3_S4/S3_S4_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S3_S4/S3_S4_10.XLS");
}
void set_links_4()
{
	strcpy(links[0].ip,"C:/pdata/SC1_/S4_S3/S4_S3_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S4_S3/S4_S3_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S4_S3/S4_S3_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S4_S3/S4_S3_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S4_S3/S4_S3_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S4_S3/S4_S3_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S4_S3/S4_S3_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S4_S3/S4_S3_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S4_S3/S4_S3_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S4_S3/S4_S3_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S4_S3/S4_S3_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S4_S3/S4_S3_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S4_S3/S4_S3_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S4_S3/S4_S3_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S4_S3/S4_S3_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S4_S3/S4_S3_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S4_S3/S4_S3_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S4_S3/S4_S3_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S4_S3/S4_S3_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S4_S3/S4_S3_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S4_S3/S4_S3_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S4_S3/S4_S3_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S4_S3/S4_S3_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S4_S3/S4_S3_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S4_S3/S4_S3_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S4_S3/S4_S3_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S4_S3/S4_S3_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S4_S3/S4_S3_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S4_S3/S4_S3_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S4_S3/S4_S3_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S4_S3/S4_S3_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S4_S3/S4_S3_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S4_S3/S4_S3_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S4_S3/S4_S3_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S4_S3/S4_S3_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S4_S3/S4_S3_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S4_S3/S4_S3_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S4_S3/S4_S3_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S4_S3/S4_S3_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S4_S3/S4_S3_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S4_S3/S4_S3_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S4_S3/S4_S3_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S4_S3/S4_S3_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S4_S3/S4_S3_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S4_S3/S4_S3_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S4_S3/S4_S3_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S4_S3/S4_S3_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S4_S3/S4_S3_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S4_S3/S4_S3_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S4_S3/S4_S3_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S4_S3/S4_S3_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S4_S3/S4_S3_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S4_S3/S4_S3_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S4_S3/S4_S3_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S4_S3/S4_S3_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S4_S3/S4_S3_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S4_S3/S4_S3_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S4_S3/S4_S3_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S4_S3/S4_S3_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S4_S3/S4_S3_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S4_S3/S4_S3_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S4_S3/S4_S3_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S4_S3/S4_S3_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S4_S3/S4_S3_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S4_S3/S4_S3_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S4_S3/S4_S3_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S4_S3/S4_S3_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S4_S3/S4_S3_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S4_S3/S4_S3_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S4_S3/S4_S3_10.XLS");
}

void set_links_5()
{

	strcpy(links[0].ip,"C:/pdata/SC1_/S5_S6/S5_S6_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S5_S6/S5_S6_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S5_S6/S5_S6_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S5_S6/S5_S6_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S5_S6/S5_S6_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S5_S6/S5_S6_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S5_S6/S5_S6_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S5_S6/S5_S6_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S5_S6/S5_S6_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S5_S6/S5_S6_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S5_S6/S5_S6_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S5_S6/S5_S6_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S5_S6/S5_S6_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S5_S6/S5_S6_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S5_S6/S5_S6_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S5_S6/S5_S6_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S5_S6/S5_S6_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S5_S6/S5_S6_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S5_S6/S5_S6_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S5_S6/S5_S6_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S5_S6/S5_S6_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S5_S6/S5_S6_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S5_S6/S5_S6_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S5_S6/S5_S6_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S5_S6/S5_S6_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S5_S6/S5_S6_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S5_S6/S5_S6_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S5_S6/S5_S6_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S5_S6/S5_S6_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S5_S6/S5_S6_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S5_S6/S5_S6_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S5_S6/S5_S6_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S5_S6/S5_S6_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S5_S6/S5_S6_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S5_S6/S5_S6_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S5_S6/S5_S6_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S5_S6/S5_S6_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S5_S6/S5_S6_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S5_S6/S5_S6_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S5_S6/S5_S6_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S5_S6/S5_S6_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S5_S6/S5_S6_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S5_S6/S5_S6_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S5_S6/S5_S6_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S5_S6/S5_S6_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S5_S6/S5_S6_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S5_S6/S5_S6_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S5_S6/S5_S6_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S5_S6/S5_S6_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S5_S6/S5_S6_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S5_S6/S5_S6_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S5_S6/S5_S6_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S5_S6/S5_S6_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S5_S6/S5_S6_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S5_S6/S5_S6_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S5_S6/S5_S6_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S5_S6/S5_S6_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S5_S6/S5_S6_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S5_S6/S5_S6_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S5_S6/S5_S6_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S5_S6/S5_S6_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S5_S6/S5_S6_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S5_S6/S5_S6_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S5_S6/S5_S6_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S5_S6/S5_S6_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S5_S6/S5_S6_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S5_S6/S5_S6_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S5_S6/S5_S6_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S5_S6/S5_S6_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S5_S6/S5_S6_10.XLS"); 
}

void set_links_6()
{
	strcpy(links[0].ip,"C:/pdata/SC1_/S6_S5/S6_S5_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S6_S5/S6_S5_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S6_S5/S6_S5_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S6_S5/S6_S5_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S6_S5/S6_S5_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S6_S5/S6_S5_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S6_S5/S6_S5_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S6_S5/S6_S5_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S6_S5/S6_S5_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S6_S5/S6_S5_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S6_S5/S6_S5_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S6_S5/S6_S5_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S6_S5/S6_S5_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S6_S5/S6_S5_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S6_S5/S6_S5_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S6_S5/S6_S5_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S6_S5/S6_S5_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S6_S5/S6_S5_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S6_S5/S6_S5_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S6_S5/S6_S5_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S6_S5/S6_S5_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S6_S5/S6_S5_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S6_S5/S6_S5_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S6_S5/S6_S5_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S6_S5/S6_S5_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S6_S5/S6_S5_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S6_S5/S6_S5_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S6_S5/S6_S5_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S6_S5/S6_S5_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S6_S5/S6_S5_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S6_S5/S6_S5_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S6_S5/S6_S5_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S6_S5/S6_S5_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S6_S5/S6_S5_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S6_S5/S6_S5_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S6_S5/S6_S5_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S6_S5/S6_S5_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S6_S5/S6_S5_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S6_S5/S6_S5_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S6_S5/S6_S5_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S6_S5/S6_S5_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S6_S5/S6_S5_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S6_S5/S6_S5_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S6_S5/S6_S5_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S6_S5/S6_S5_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S6_S5/S6_S5_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S6_S5/S6_S5_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S6_S5/S6_S5_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S6_S5/S6_S5_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S6_S5/S6_S5_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S6_S5/S6_S5_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S6_S5/S6_S5_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S6_S5/S6_S5_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S6_S5/S6_S5_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S6_S5/S6_S5_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S6_S5/S6_S5_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S6_S5/S6_S5_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S6_S5/S6_S5_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S6_S5/S6_S5_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S6_S5/S6_S5_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S6_S5/S6_S5_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S6_S5/S6_S5_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S6_S5/S6_S5_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S6_S5/S6_S5_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S6_S5/S6_S5_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S6_S5/S6_S5_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S6_S5/S6_S5_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S6_S5/S6_S5_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S6_S5/S6_S5_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S6_S5/S6_S5_10.XLS"); 

}

void set_links_7()
{

	strcpy(links[0].ip,"C:/pdata/SC1_/S7_S8/S7_S8_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S7_S8/S7_S8_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S7_S8/S7_S8_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S7_S8/S7_S8_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S7_S8/S7_S8_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S7_S8/S7_S8_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S7_S8/S7_S8_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S7_S8/S7_S8_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S7_S8/S7_S8_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S7_S8/S7_S8_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S7_S8/S7_S8_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S7_S8/S7_S8_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S7_S8/S7_S8_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S7_S8/S7_S8_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S7_S8/S7_S8_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S7_S8/S7_S8_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S7_S8/S7_S8_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S7_S8/S7_S8_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S7_S8/S7_S8_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S7_S8/S7_S8_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S7_S8/S7_S8_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S7_S8/S7_S8_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S7_S8/S7_S8_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S7_S8/S7_S8_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S7_S8/S7_S8_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S7_S8/S7_S8_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S7_S8/S7_S8_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S7_S8/S7_S8_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S7_S8/S7_S8_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S7_S8/S7_S8_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S7_S8/S7_S8_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S7_S8/S7_S8_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S7_S8/S7_S8_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S7_S8/S7_S8_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S7_S8/S7_S8_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S7_S8/S7_S8_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S7_S8/S7_S8_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S7_S8/S7_S8_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S7_S8/S7_S8_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S7_S8/S7_S8_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S7_S8/S7_S8_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S7_S8/S7_S8_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S7_S8/S7_S8_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S7_S8/S7_S8_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S7_S8/S7_S8_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S7_S8/S7_S8_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S7_S8/S7_S8_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S7_S8/S7_S8_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S7_S8/S7_S8_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S7_S8/S7_S8_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S7_S8/S7_S8_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S7_S8/S7_S8_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S7_S8/S7_S8_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S7_S8/S7_S8_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S7_S8/S7_S8_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S7_S8/S7_S8_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S7_S8/S7_S8_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S7_S8/S7_S8_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S7_S8/S7_S8_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S7_S8/S7_S8_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S7_S8/S7_S8_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S7_S8/S7_S8_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S7_S8/S7_S8_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S7_S8/S7_S8_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S7_S8/S7_S8_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S7_S8/S7_S8_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S7_S8/S7_S8_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S7_S8/S7_S8_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S7_S8/S7_S8_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S7_S8/S7_S8_10.XLS");

}

void set_links_8()
{

	strcpy(links[0].ip,"C:/pdata/SC1_/S8_S7/S8_S7_1.XLS");
	strcpy(links[1].ip,"C:/pdata/SC1_/S8_S7/S8_S7_2.XLS");
	strcpy(links[2].ip,"C:/pdata/SC1_/S8_S7/S8_S7_3.XLS");
	strcpy(links[3].ip,"C:/pdata/SC1_/S8_S7/S8_S7_4.XLS");
	strcpy(links[4].ip,"C:/pdata/SC1_/S8_S7/S8_S7_5.XLS");
	strcpy(links[5].ip,"C:/pdata/SC1_/S8_S7/S8_S7_6.XLS");
	strcpy(links[6].ip,"C:/pdata/SC1_/S8_S7/S8_S7_7.XLS");
	strcpy(links[7].ip,"C:/pdata/SC1_/S8_S7/S8_S7_8.XLS");
	strcpy(links[8].ip,"C:/pdata/SC1_/S8_S7/S8_S7_9.XLS");
	strcpy(links[9].ip,"C:/pdata/SC1_/S8_S7/S8_S7_10.XLS");
	strcpy(links[10].ip,"C:/pdata/SC2_/S8_S7/S8_S7_1.XLS");
	strcpy(links[11].ip,"C:/pdata/SC2_/S8_S7/S8_S7_2.XLS");
	strcpy(links[12].ip,"C:/pdata/SC2_/S8_S7/S8_S7_3.XLS");
	strcpy(links[13].ip,"C:/pdata/SC2_/S8_S7/S8_S7_4.XLS");
	strcpy(links[14].ip,"C:/pdata/SC2_/S8_S7/S8_S7_5.XLS");
	strcpy(links[15].ip,"C:/pdata/SC2_/S8_S7/S8_S7_6.XLS");
	strcpy(links[16].ip,"C:/pdata/SC2_/S8_S7/S8_S7_7.XLS");
	strcpy(links[17].ip,"C:/pdata/SC2_/S8_S7/S8_S7_8.XLS");
	strcpy(links[18].ip,"C:/pdata/SC2_/S8_S7/S8_S7_9.XLS");
	strcpy(links[19].ip,"C:/pdata/SC2_/S8_S7/S8_S7_10.XLS");
	strcpy(links[20].ip,"C:/pdata/SC3_/S8_S7/S8_S7_1.XLS");
	strcpy(links[21].ip,"C:/pdata/SC3_/S8_S7/S8_S7_2.XLS");
	strcpy(links[22].ip,"C:/pdata/SC3_/S8_S7/S8_S7_3.XLS");
	strcpy(links[23].ip,"C:/pdata/SC3_/S8_S7/S8_S7_4.XLS");
	strcpy(links[24].ip,"C:/pdata/SC3_/S8_S7/S8_S7_5.XLS");
	strcpy(links[25].ip,"C:/pdata/SC3_/S8_S7/S8_S7_6.XLS");
	strcpy(links[26].ip,"C:/pdata/SC3_/S8_S7/S8_S7_7.XLS");
	strcpy(links[27].ip,"C:/pdata/SC3_/S8_S7/S8_S7_8.XLS");
	strcpy(links[28].ip,"C:/pdata/SC3_/S8_S7/S8_S7_9.XLS");
	strcpy(links[29].ip,"C:/pdata/SC3_/S8_S7/S8_S7_10.XLS");
	strcpy(links[30].ip,"C:/pdata/SC4_/S8_S7/S8_S7_1.XLS");
	strcpy(links[31].ip,"C:/pdata/SC4_/S8_S7/S8_S7_2.XLS");
	strcpy(links[32].ip,"C:/pdata/SC4_/S8_S7/S8_S7_3.XLS");
	strcpy(links[33].ip,"C:/pdata/SC4_/S8_S7/S8_S7_4.XLS");
	strcpy(links[34].ip,"C:/pdata/SC4_/S8_S7/S8_S7_5.XLS");
	strcpy(links[35].ip,"C:/pdata/SC4_/S8_S7/S8_S7_6.XLS");
	strcpy(links[36].ip,"C:/pdata/SC4_/S8_S7/S8_S7_7.XLS");
	strcpy(links[37].ip,"C:/pdata/SC4_/S8_S7/S8_S7_8.XLS");
	strcpy(links[38].ip,"C:/pdata/SC4_/S8_S7/S8_S7_9.XLS");
	strcpy(links[39].ip,"C:/pdata/SC4_/S8_S7/S8_S7_10.XLS");
	strcpy(links[40].ip,"C:/pdata/SC5_/S8_S7/S8_S7_1.XLS");
	strcpy(links[41].ip,"C:/pdata/SC5_/S8_S7/S8_S7_2.XLS");
	strcpy(links[42].ip,"C:/pdata/SC5_/S8_S7/S8_S7_3.XLS");
	strcpy(links[43].ip,"C:/pdata/SC5_/S8_S7/S8_S7_4.XLS");
	strcpy(links[44].ip,"C:/pdata/SC5_/S8_S7/S8_S7_5.XLS");
	strcpy(links[45].ip,"C:/pdata/SC5_/S8_S7/S8_S7_6.XLS");
	strcpy(links[46].ip,"C:/pdata/SC5_/S8_S7/S8_S7_7.XLS");
	strcpy(links[47].ip,"C:/pdata/SC5_/S8_S7/S8_S7_8.XLS");
	strcpy(links[48].ip,"C:/pdata/SC5_/S8_S7/S8_S7_9.XLS");
	strcpy(links[49].ip,"C:/pdata/SC5_/S8_S7/S8_S7_10.XLS");
	strcpy(links[50].ip,"C:/pdata/SC6_/S8_S7/S8_S7_1.XLS");
	strcpy(links[51].ip,"C:/pdata/SC6_/S8_S7/S8_S7_2.XLS");
	strcpy(links[52].ip,"C:/pdata/SC6_/S8_S7/S8_S7_3.XLS");
	strcpy(links[53].ip,"C:/pdata/SC6_/S8_S7/S8_S7_4.XLS");
	strcpy(links[54].ip,"C:/pdata/SC6_/S8_S7/S8_S7_5.XLS");
	strcpy(links[55].ip,"C:/pdata/SC6_/S8_S7/S8_S7_6.XLS");
	strcpy(links[56].ip,"C:/pdata/SC6_/S8_S7/S8_S7_7.XLS");
	strcpy(links[57].ip,"C:/pdata/SC6_/S8_S7/S8_S7_8.XLS");
	strcpy(links[58].ip,"C:/pdata/SC6_/S8_S7/S8_S7_9.XLS");
	strcpy(links[59].ip,"C:/pdata/SC6_/S8_S7/S8_S7_10.XLS");
	strcpy(links[60].ip,"C:/pdata/SC7_/S8_S7/S8_S7_1.XLS");
	strcpy(links[61].ip,"C:/pdata/SC7_/S8_S7/S8_S7_2.XLS");
	strcpy(links[62].ip,"C:/pdata/SC7_/S8_S7/S8_S7_3.XLS");
	strcpy(links[63].ip,"C:/pdata/SC7_/S8_S7/S8_S7_4.XLS");
	strcpy(links[64].ip,"C:/pdata/SC7_/S8_S7/S8_S7_5.XLS");
	strcpy(links[65].ip,"C:/pdata/SC7_/S8_S7/S8_S7_6.XLS");
	strcpy(links[66].ip,"C:/pdata/SC7_/S8_S7/S8_S7_7.XLS");
	strcpy(links[67].ip,"C:/pdata/SC7_/S8_S7/S8_S7_8.XLS");
	strcpy(links[68].ip,"C:/pdata/SC7_/S8_S7/S8_S7_9.XLS");
	strcpy(links[69].ip,"C:/pdata/SC7_/S8_S7/S8_S7_10.XLS");
}
char* label(int no)                                           // This function will return a file label as SCx_Sy_Sz_t
{                                                             // Argument is location of file.
	char buff[35],temp[15];                                      // As e.g. Menu choice: 04; Argument = 69 will return SC7_S4_S3_10 (i.e.) Scenario 7, S4_S3 path, Trial 10; 
	int i=0,j=0,count=0;                                         // It will be used for distance matrix heading
	strcpy(buff,links[no].ip);                                   
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
	tmp = fopen("1.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp");
		getch();
	}
}
void open_res_2()                         // Opening file for path 2
{
	tmp = fopen("2.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp2");
		getch();
	}
}
void open_res_3()                              // Opening file for path 2
{
	tmp = fopen("3.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp3");
		getch();
	}
}
void open_res_4()                            // Opening file for path 2
{
	tmp = fopen("4.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp4");
		getch();
	}
}


void open_res_5()                              // Opening file for Path 1
{
	tmp = fopen("5.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp5");
		getch();
	}
}
void open_res_6()                         // Opening file for path 2
{
	tmp = fopen("6.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp6");
		getch();
	}
}
void open_res_7()                              // Opening file for path 2
{
	tmp = fopen("7.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp7");
		getch();
	}
}
void open_res_8()                            // Opening file for path 2
{
	tmp = fopen("8.xls", "w");
	if(tmp == NULL )
	{
		perror("\n tmp8");
		getch();
	}
}




void open_fil(int sr1, int sr2)                             // open file for calculating distance
{                                                           // Argument is link number of input file
	src1 = fopen(links[sr1].ip, "r");                       // Open file 1 and 2
	src2 = fopen(links[sr2].ip, "r");

	if(src1 == NULL )
	{
		perror("\n Src_1:");
		printf("(%s)",links[sr1].ip);
		getch();
	}
	if(src2 == NULL )
	{
		perror("\n Src_2:");
		printf("(%s)",links[sr2].ip);
		getch();
	}

}
void max_min()                                         //This function is used for calculating Max-Min of 10 trials in path to minimize fluctuations
{                                                      //This function is not used for calculations
	int ki,k,contg=0;
	FILE *mfil;
	float max=30.0,min=30.0;
	char mtmp[20];

	for(ki=0;ki<=60;ki=ki+10)
	{
		mfil = fopen(links[ki].ip,"r");
		printf("\nk=%d",ki);
		if(mfil==NULL)
		{
			perror("Max_Min:");
		}
		for(k=1;k<=5;k++)
		{
			fscanf(mfil,"%s",&mtmp);
		}
		while(fscanf(mfil,"%s",&mtmp) != EOF)
		{
			contg++;
			if(contg==6)
			{
				printf("\nval:%s",mtmp); 
				//getch();
				if(atof(mtmp)>max)
				{
					max = atof(mtmp);
				}
				if(atof(mtmp)<min)
				{
					min = atof(mtmp);
				}
				contg=0;
			}
		}
		sin[ki/10].l_max = max;
		sin[ki/10].l_min = min;	
		printf("\nfile:%s;",links[ki].ip);
		printf("\nl_max[%d]:%.1f\nl_Min:%.1f",(ki/10),sin[ki/10].l_max,sin[ki/10].l_min);
		max=30.0;
		min=30.0;
		contg=0;
		//getch();
		rewind(mfil);
		for(k=1;k<=6;k++)
		{
			fscanf(mfil,"%s",&mtmp);
		}
		while(fscanf(mfil,"%s",&mtmp) != EOF)
		{
			contg++;
			if(contg==6)
			{
				printf("\nval:%s",mtmp);
				//getch();
				if(atof(mtmp)>max)
				{
					max = atof(mtmp);
				}
				if(atof(mtmp)<min)
				{
					min = atof(mtmp);
				}
				contg=0;
			}
		}
		fclose(mfil);
		sin[ki/10].r_max = max;
		sin[ki/10].r_min = min;	
		printf("\nfile:%s;",links[ki].ip);
		printf("\nr_max:%.1f\nr_Min:%.1f",sin[ki/10].r_max,sin[ki/10].r_min);
		max=30.0;
		min=30.0;
		contg=0;
		//getch();
		fclose(mfil);
	}

}
float cal_dis(int a, int b)              //This function calculates distance with threshold
{                                        
	FILE *com;
	char tmp1[20],tmp2[20];
	int k,cnts=0,cnts1=0;
	float sum=0,valu1,valu2;
	float val1,val2;
	com = fopen("c.xls","w");
	for(k=1;k<=6;k++)
	{
		fscanf(src1,"%s",&tmp1);
		fscanf(src2,"%s",&tmp2);
	}
	while(fscanf(src1,"%s",&tmp1) != EOF)
	{
		cnts1++;
		if(cnts1==5)
		{
			valu1 = atof(tmp1);
			if(valu1>38)
			{
				valu1 = sin[a/10].l_max;
			}
			else if(valu1<27)
			{
				valu1 = sin[a/10].l_min;
			}
			fprintf(com,"%.1f\t",valu1);
			printf("\n%.1f\t",valu1);
			getch();
		}
		else if(cnts1==6)
		{
			valu1 = atof(tmp1);
			if(valu1>38)
			{
				valu1 = sin[a/10].r_max;
			}
			else if(valu1<27)
			{
				valu1 = sin[a/10].r_min;
			}
			fprintf(com,"%.1f\n",valu2);
			printf("%.1f\n",valu2);
			getch();
			cnts1=0;
		}
		else
		{
			valu1 = atof(tmp1);
			//fprintf(com,"%.1f\t",valu1);
		}	
		if(fscanf(src2,"%s",&tmp2) == EOF)
		{
			break;
		}
		else
		{
			cnts++;
			if(cnts==5)
			{
				valu2 = atof(tmp2);
				if(valu2>38)
				{
					valu2 = sin[b/10].l_max;
					//fprintf(com,"%.1f\n",valu2);
				}
				else if(valu2<27)
				{
					valu2 = sin[b/10].l_min;
					//fprintf(com,"%.1f\n",valu2);
				}
			}
			else if(cnts==6)
			{
				valu2 = atof(tmp2);

				if(valu2>38)
				{
					valu2 = sin[b/10].r_max;
				}
				else if(valu2<27)
				{
					valu2 = sin[b/10].r_min;
				}
				cnts=0;
			}
			else
			{
				valu2 = atof(tmp2);
			}	

			//printf("\n%s\t%s",tmp1,tmp2);
			//getch();
			if(valu1>valu2)
			{
				sum = sum + (valu1-valu2);
			}
			else if(valu1<valu2)
			{
				sum = sum + (valu2-valu1);
			}
			printf("\n Val1:%.1f,val2:%.1f,distance:%.1f",valu1,valu2,sum);

		}

	}

	//printf("\nDistance (S1T1 -> S2T1):%.1f",sum);

	fclose(com);
	getch();
	return sum;
}
float only_2()                                                     // THis function calculates distance considering only two attribute thermal data
{
	char tmp1[20],tmp2[20];
	int k,cnts=0,cnts1=0;
	float sum=0,valu1,valu2;
	float val1,val2;
	for(k=1;k<=6;k++)
	{
		fscanf(src1,"%s",&tmp1);
		fscanf(src2,"%s",&tmp2);
	}
	while(fscanf(src1,"%s",&tmp1) != EOF)
	{
		cnts1++;
		if(cnts1==5)
		{
			valu1 = atof(tmp1);
		}
		else if(cnts1==6)
		{
			valu1 = atof(tmp1);
		}
		else
		{

		}	
		if(fscanf(src2,"%s",&tmp2) == EOF)
		{
			break;
		}
		else
		{
			cnts++;
			if(cnts==5)
			{
				valu2 = atof(tmp2);
			}
			else if(cnts==6)
			{
				valu2 = atof(tmp2);
				cnts=0;
			}	  
			//printf("\n%s\t%s",tmp1,tmp2);
			//getch();
			if(valu1>valu2)
			{
				sum = sum + (valu1-valu2);
			}
			else if(valu1<valu2)
			{
				sum = sum + (valu2-valu1);
			}
			//printf("\n Val1:%.1f,val2:%.1f,distance:%.1f",valu1,valu2,sum);
			//getch();
		}

	}

	//printf("\nDistance (S1T1 -> S2T1):%.1f",sum);
	//getch();
	return sum;



}
float cal_dis_nt()                                       //This function calculates distance without threshold
{                                                        // THis function is used for choice : 1,2,3,4;

	char tmp1[20],tmp2[20];
	int k,count=0;
	float sum=0;
	float val1,val2;
	for(k=1;k<=6;k++)
	{
		fscanf(src1,"%s",&tmp1);
		fscanf(src2,"%s",&tmp2);
	}
	while(fscanf(src1,"%s",&tmp1) != EOF)
	{
		if(fscanf(src2,"%s",&tmp2) == EOF)
		{
			break;
		}
		else
		{
			//printf("\n%d:%s\t%s",count,tmp1,tmp2);
			//getch();
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
float cal_dis_d()                                               // This function calculates distance for only IR proximity sensor values
{
	char tmp1[20],tmp2[20];
	int k,count=0;
	float sum=0;
	float val1,val2;
	for(k=1;k<=6;k++)
	{
		fscanf(src1,"%s",&tmp1);
		fscanf(src2,"%s",&tmp2);
	}
	while(fscanf(src1,"%s",&tmp1) != EOF)
	{
		if(fscanf(src2,"%s",&tmp2) == EOF)
		{
			break;
		}
		else
		{
			count++;
			if(count<=4)
			{
				//printf("\n%d:%s\t%s",count,tmp1,tmp2);
				//getch();
				if(atof(tmp1)>atof(tmp2))
				{
					sum = sum + (atof(tmp1)-atof(tmp2));
				}
				else if(atof(tmp1)<atof(tmp2))
				{
					sum = sum + (atof(tmp2)-atof(tmp1));
				}
			}
			else if(count==36)
			{
				count=0;
			}



		}

	}
	return sum;
}  
float cal_dis_t()                                          // This function calculates distance for only THermal Imaging sensor values
{
	char tmp1[20],tmp2[20];
	int k,count=0;
	float sum=0;
	float val1,val2;
	for(k=1;k<=6;k++)
	{
		fscanf(src1,"%s",&tmp1);
		fscanf(src2,"%s",&tmp2);
	}
	while(fscanf(src1,"%s",&tmp1) != EOF)
	{
		if(fscanf(src2,"%s",&tmp2) == EOF)
		{
			break;
		}
		else
		{
			count++;
			if(count>4)
			{
				//printf("\n%d:%s\t%s",count,tmp1,tmp2);
				//getch();
				if(atof(tmp1)>atof(tmp2))
				{
					sum = sum + (atof(tmp1)-atof(tmp2));
				}
				else if(atof(tmp1)<atof(tmp2))
				{
					sum = sum + (atof(tmp2)-atof(tmp1));
				}
			}
			if(count==36)
			{
				count=0;
			}     
		}

	}
	return sum;

}
void close_al()
{
	fclose(src1);
	fclose(src2);

}
void close_res()
{
	fclose(tmp);
}
void write_res()                                          // This function writes distance results to a excel file
{
	int i,j;
	float ret;
	fprintf(tmp,"\t");
	for(i=0;i<=69;i++)
	{
		fprintf(tmp,"%s\t",label(i));
	}
	fprintf(tmp,"\n");
	for(i=0;i<=69;i++)
	{
		fprintf(tmp,"%s\t",label(i));
		for(j=0;j<=69;j++)
		{
			open_fil(i,j);
			if(ch==1)
			{
				ret = cal_dis_nt();
			}
			else if(ch==2)
			{
				ret = cal_dis_d();
			}
			else if(ch==3)
			{
				ret = cal_dis_t();
			}
			fprintf(tmp,"%.1f\t",ret);
			printf("\nCalculating Distance of file[%d] and file [%d]....",i,j);
			close_al();
		}
		fprintf(tmp,"\n");
	}


}
void main()                                  // Main function
{                                            // Menu explains code block
	float res;
	int i,ag=1;
	do
	{
		clrscr();
		printf("\nMenu:\n1.Thermal and Distance- Distance Matrix (Press 1,2,3,4 for paths)\n2.Only IR data distance Matrix (Press 5,6,7,8 for path 1,2,3,4)\n3.Only Thermal(Press 9 to 12 for paths)\nEnter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					set_links_1();
					//max_min();
					open_res();
					write_res();
					close_res();

					set_links_2();
					//max_min();
					open_res_2();
					write_res();
					close_res();	

					set_links_3();
					//max_min();
					open_res_3();
					write_res();
					close_res(); 

					set_links_4();
					//max_min();
					open_res_4();
					write_res();
					close_res(); 
					set_links_5();
					//max_min();
					open_res_5();
					write_res();
					close_res();  	 

					set_links_6();
					//max_min();
					open_res_6();
					write_res();
					close_res();  	 

					set_links_7();
					//max_min();
					open_res_7();
					write_res();
					close_res();  

					set_links_8();
					//max_min();
					open_res_8();
					write_res();
					close_res();  	 


					break;
				}
			case 2:
				{
					set_links_1();
					//max_min();
					open_res();
					write_res();
					close_res(); 
					set_links_2();
					//max_min();
					open_res_2();
					write_res();
					close_res();
					set_links_3();
					//max_min();
					open_res_3();
					write_res();
					close_res();  
					set_links_4();
					//max_min();
					open_res_4();
					write_res();
					close_res();  

					set_links_5();
					//max_min();
					open_res_5();
					write_res();
					close_res();  	 

					set_links_6();
					//max_min();
					open_res_6();
					write_res();
					close_res();  	 

					set_links_7();
					//max_min();
					open_res_7();
					write_res();
					close_res();  

					set_links_8();
					//max_min();
					open_res_8();
					write_res();
					close_res();  	 
					break;
				}
			case 3:
				{
					set_links_1();
					//max_min();
					open_res();
					write_res();
					close_res();  
					set_links_2();
					//max_min();
					open_res_2();
					write_res();
					close_res(); 
					set_links_3();
					// max_min();
					open_res_3();
					write_res();
					close_res();  
					set_links_4();
					//max_min();
					open_res_4();
					write_res();
					close_res();

					set_links_5();
					//max_min();
					open_res_5();
					write_res();
					close_res();  	 

					set_links_6();
					//max_min();
					open_res_6();
					write_res();
					close_res();  	 

					set_links_7();
					//max_min();
					open_res_7();
					write_res();
					close_res();  

					set_links_8();
					//max_min();
					open_res_8();
					write_res();
					close_res();  	 
					break;	
				}

		}
		printf("\nTo Continue, Press 1:");
		scanf("%d",&ag);
	}while(ag==1);
	getch();
}




