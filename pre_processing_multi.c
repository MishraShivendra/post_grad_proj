/*
 * File: pre_process.c
 * Created on: Dec 1, 2013; 01:08:35 AM 
 * Author: Shivendra Mishra
 * Geany v4.5 (UNICODE)
 * 
 *
 *
 * Environment: Geany with gcc (Only on linux)
 * Input: Hex file from system file ./data/SCx_/Sx_Sy/Sx_Sy_t.txt      Where x,y are path directions and t is trial.
 * Output: Pre-Processed data (16 Attributes=4(IR Proximity Sensor) + 32(MEMS Thermal Imaging Sensor ))
 * Execution: Execute and choose 9 from Menu; If it is required to process step by step choose accordingly from menu.
 */
 #if __linux__
 #include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>      
#include<error.h>                                        // Headers
unsigned char ther[35],diss[7][35],readbuff1[7][35],op1[20];          // Matrix for thermal imaging data
 volatile int prec=0;                                 // Result matrix of thermal imaging data
 
float fl1[7][16],val;
FILE *src[7], *temp[7],*oup[7];                                          // File pointers for i/o files
int count,ag=0;
char tmp[7], ip[7][35], op[7][35];
pthread_mutex_t my_lock;

struct fil
{
 char ip[35];                                                 // For storing input file location
 char resl[35];                                               // output file location
}links[7][80];


void set_links_1()                                                      //Storing input file links for scenario 1
{
 strcpy(links[0][0].ip,"./data/SC1_/S1_S2/S1_S2_1.txt");
 strcpy(links[0][1].ip,"./data/SC1_/S1_S2/S1_S2_2.txt");
 strcpy(links[0][2].ip,"./data/SC1_/S1_S2/S1_S2_3.txt");
 strcpy(links[0][3].ip,"./data/SC1_/S1_S2/S1_S2_4.txt");
 strcpy(links[0][4].ip,"./data/SC1_/S1_S2/S1_S2_5.txt");
 strcpy(links[0][5].ip,"./data/SC1_/S1_S2/S1_S2_6.txt");
 strcpy(links[0][6].ip,"./data/SC1_/S1_S2/S1_S2_7.txt");
 strcpy(links[0][7].ip,"./data/SC1_/S1_S2/S1_S2_8.txt");
 strcpy(links[0][8].ip,"./data/SC1_/S1_S2/S1_S2_9.txt");
 strcpy(links[0][9].ip,"./data/SC1_/S1_S2/S1_S2_10.txt");
 strcpy(links[0][10].ip,"./data/SC1_/S2_S1/S2_S1_1.txt");
 strcpy(links[0][11].ip,"./data/SC1_/S2_S1/S2_S1_2.txt");
 strcpy(links[0][12].ip,"./data/SC1_/S2_S1/S2_S1_3.txt");
 strcpy(links[0][13].ip,"./data/SC1_/S2_S1/S2_S1_4.txt");
 strcpy(links[0][14].ip,"./data/SC1_/S2_S1/S2_S1_5.txt");
 strcpy(links[0][15].ip,"./data/SC1_/S2_S1/S2_S1_6.txt");
 strcpy(links[0][16].ip,"./data/SC1_/S2_S1/S2_S1_7.txt");
 strcpy(links[0][17].ip,"./data/SC1_/S2_S1/S2_S1_8.txt");
 strcpy(links[0][18].ip,"./data/SC1_/S2_S1/S2_S1_9.txt");
 strcpy(links[0][19].ip,"./data/SC1_/S2_S1/S2_S1_10.txt");
 strcpy(links[0][20].ip,"./data/SC1_/S3_S4/S3_S4_1.txt");
 strcpy(links[0][21].ip,"./data/SC1_/S3_S4/S3_S4_2.txt");
 strcpy(links[0][22].ip,"./data/SC1_/S3_S4/S3_S4_3.txt");
 strcpy(links[0][23].ip,"./data/SC1_/S3_S4/S3_S4_4.txt");
 strcpy(links[0][24].ip,"./data/SC1_/S3_S4/S3_S4_5.txt");
 strcpy(links[0][25].ip,"./data/SC1_/S3_S4/S3_S4_6.txt");
 strcpy(links[0][26].ip,"./data/SC1_/S3_S4/S3_S4_7.txt");
 strcpy(links[0][27].ip,"./data/SC1_/S3_S4/S3_S4_8.txt");
 strcpy(links[0][28].ip,"./data/SC1_/S3_S4/S3_S4_9.txt");
 strcpy(links[0][29].ip,"./data/SC1_/S3_S4/S3_S4_10.txt");
 strcpy(links[0][30].ip,"./data/SC1_/S4_S3/S4_S3_1.txt");
 strcpy(links[0][31].ip,"./data/SC1_/S4_S3/S4_S3_2.txt");
 strcpy(links[0][32].ip,"./data/SC1_/S4_S3/S4_S3_3.txt");
 strcpy(links[0][33].ip,"./data/SC1_/S4_S3/S4_S3_4.txt");
 strcpy(links[0][34].ip,"./data/SC1_/S4_S3/S4_S3_5.txt");
 strcpy(links[0][35].ip,"./data/SC1_/S4_S3/S4_S3_6.txt");
 strcpy(links[0][36].ip,"./data/SC1_/S4_S3/S4_S3_7.txt");
 strcpy(links[0][37].ip,"./data/SC1_/S4_S3/S4_S3_8.txt");
 strcpy(links[0][38].ip,"./data/SC1_/S4_S3/S4_S3_9.txt");
 strcpy(links[0][39].ip,"./data/SC1_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[0][40].ip,"./data/SC1_/S5_S6/S5_S6_1.txt");
 strcpy(links[0][41].ip,"./data/SC1_/S5_S6/S5_S6_2.txt");
 strcpy(links[0][42].ip,"./data/SC1_/S5_S6/S5_S6_3.txt");
 strcpy(links[0][43].ip,"./data/SC1_/S5_S6/S5_S6_4.txt");
 strcpy(links[0][44].ip,"./data/SC1_/S5_S6/S5_S6_5.txt");
 strcpy(links[0][45].ip,"./data/SC1_/S5_S6/S5_S6_6.txt");
 strcpy(links[0][46].ip,"./data/SC1_/S5_S6/S5_S6_7.txt");
 strcpy(links[0][47].ip,"./data/SC1_/S5_S6/S5_S6_8.txt");
 strcpy(links[0][48].ip,"./data/SC1_/S5_S6/S5_S6_9.txt");
 strcpy(links[0][49].ip,"./data/SC1_/S5_S6/S5_S6_10.txt");
 strcpy(links[0][50].ip,"./data/SC1_/S6_S5/S6_S5_1.txt");
 strcpy(links[0][51].ip,"./data/SC1_/S6_S5/S6_S5_2.txt");
 strcpy(links[0][52].ip,"./data/SC1_/S6_S5/S6_S5_3.txt");
 strcpy(links[0][53].ip,"./data/SC1_/S6_S5/S6_S5_4.txt");
 strcpy(links[0][54].ip,"./data/SC1_/S6_S5/S6_S5_5.txt");
 strcpy(links[0][55].ip,"./data/SC1_/S6_S5/S6_S5_6.txt");
 strcpy(links[0][56].ip,"./data/SC1_/S6_S5/S6_S5_7.txt");
 strcpy(links[0][57].ip,"./data/SC1_/S6_S5/S6_S5_8.txt");
 strcpy(links[0][58].ip,"./data/SC1_/S6_S5/S6_S5_9.txt");
 strcpy(links[0][59].ip,"./data/SC1_/S6_S5/S6_S5_10.txt");
 strcpy(links[0][60].ip,"./data/SC1_/S7_S8/S7_S8_1.txt");
 strcpy(links[0][61].ip,"./data/SC1_/S7_S8/S7_S8_2.txt");
 strcpy(links[0][62].ip,"./data/SC1_/S7_S8/S7_S8_3.txt");
 strcpy(links[0][63].ip,"./data/SC1_/S7_S8/S7_S8_4.txt");
 strcpy(links[0][64].ip,"./data/SC1_/S7_S8/S7_S8_5.txt");
 strcpy(links[0][65].ip,"./data/SC1_/S7_S8/S7_S8_6.txt");
 strcpy(links[0][66].ip,"./data/SC1_/S7_S8/S7_S8_7.txt");
 strcpy(links[0][67].ip,"./data/SC1_/S7_S8/S7_S8_8.txt");
 strcpy(links[0][68].ip,"./data/SC1_/S7_S8/S7_S8_9.txt");
 strcpy(links[0][69].ip,"./data/SC1_/S7_S8/S7_S8_10.txt");
 strcpy(links[0][70].ip,"./data/SC1_/S8_S7/S8_S7_1.txt");
 strcpy(links[0][71].ip,"./data/SC1_/S8_S7/S8_S7_2.txt");
 strcpy(links[0][72].ip,"./data/SC1_/S8_S7/S8_S7_3.txt");
 strcpy(links[0][73].ip,"./data/SC1_/S8_S7/S8_S7_4.txt");
 strcpy(links[0][74].ip,"./data/SC1_/S8_S7/S8_S7_5.txt");
 strcpy(links[0][75].ip,"./data/SC1_/S8_S7/S8_S7_6.txt");
 strcpy(links[0][76].ip,"./data/SC1_/S8_S7/S8_S7_7.txt");
 strcpy(links[0][77].ip,"./data/SC1_/S8_S7/S8_S7_8.txt");
 strcpy(links[0][78].ip,"./data/SC1_/S8_S7/S8_S7_9.txt");
 strcpy(links[0][79].ip,"./data/SC1_/S8_S7/S8_S7_10.txt");
 
}
void set_links_2()                                                            //Storing input file links for scenario 2
{
 strcpy(links[1][0].ip,"./data/SC2_/S1_S2/S1_S2_1.txt");
 strcpy(links[1][1].ip,"./data/SC2_/S1_S2/S1_S2_2.txt");
 strcpy(links[1][2].ip,"./data/SC2_/S1_S2/S1_S2_3.txt");
 strcpy(links[1][3].ip,"./data/SC2_/S1_S2/S1_S2_4.txt");
 strcpy(links[1][4].ip,"./data/SC2_/S1_S2/S1_S2_5.txt");
 strcpy(links[1][5].ip,"./data/SC2_/S1_S2/S1_S2_6.txt");
 strcpy(links[1][6].ip,"./data/SC2_/S1_S2/S1_S2_7.txt");
 strcpy(links[1][7].ip,"./data/SC2_/S1_S2/S1_S2_8.txt");
 strcpy(links[1][8].ip,"./data/SC2_/S1_S2/S1_S2_9.txt");
 strcpy(links[1][9].ip,"./data/SC2_/S1_S2/S1_S2_10.txt");
 strcpy(links[1][10].ip,"./data/SC2_/S2_S1/S2_S1_1.txt");
 strcpy(links[1][11].ip,"./data/SC2_/S2_S1/S2_S1_2.txt");
 strcpy(links[1][12].ip,"./data/SC2_/S2_S1/S2_S1_3.txt");
 strcpy(links[1][13].ip,"./data/SC2_/S2_S1/S2_S1_4.txt");
 strcpy(links[1][14].ip,"./data/SC2_/S2_S1/S2_S1_5.txt");
 strcpy(links[1][15].ip,"./data/SC2_/S2_S1/S2_S1_6.txt");
 strcpy(links[1][16].ip,"./data/SC2_/S2_S1/S2_S1_7.txt");
 strcpy(links[1][17].ip,"./data/SC2_/S2_S1/S2_S1_8.txt");
 strcpy(links[1][18].ip,"./data/SC2_/S2_S1/S2_S1_9.txt");
 strcpy(links[1][19].ip,"./data/SC2_/S2_S1/S2_S1_10.txt");
 strcpy(links[1][20].ip,"./data/SC2_/S3_S4/S3_S4_1.txt");
 strcpy(links[1][21].ip,"./data/SC2_/S3_S4/S3_S4_2.txt");
 strcpy(links[1][22].ip,"./data/SC2_/S3_S4/S3_S4_3.txt");
 strcpy(links[1][23].ip,"./data/SC2_/S3_S4/S3_S4_4.txt");
 strcpy(links[1][24].ip,"./data/SC2_/S3_S4/S3_S4_5.txt");
 strcpy(links[1][25].ip,"./data/SC2_/S3_S4/S3_S4_6.txt");
 strcpy(links[1][26].ip,"./data/SC2_/S3_S4/S3_S4_7.txt");
 strcpy(links[1][27].ip,"./data/SC2_/S3_S4/S3_S4_8.txt");
 strcpy(links[1][28].ip,"./data/SC2_/S3_S4/S3_S4_9.txt");
 strcpy(links[1][29].ip,"./data/SC2_/S3_S4/S3_S4_10.txt");
 strcpy(links[1][30].ip,"./data/SC2_/S4_S3/S4_S3_1.txt");
 strcpy(links[1][31].ip,"./data/SC2_/S4_S3/S4_S3_2.txt");
 strcpy(links[1][32].ip,"./data/SC2_/S4_S3/S4_S3_3.txt");
 strcpy(links[1][33].ip,"./data/SC2_/S4_S3/S4_S3_4.txt");
 strcpy(links[1][34].ip,"./data/SC2_/S4_S3/S4_S3_5.txt");
 strcpy(links[1][35].ip,"./data/SC2_/S4_S3/S4_S3_6.txt");
 strcpy(links[1][36].ip,"./data/SC2_/S4_S3/S4_S3_7.txt");
 strcpy(links[1][37].ip,"./data/SC2_/S4_S3/S4_S3_8.txt");
 strcpy(links[1][38].ip,"./data/SC2_/S4_S3/S4_S3_9.txt");
 strcpy(links[1][39].ip,"./data/SC2_/S4_S3/S4_S3_10.txt");
 
 
 
 strcpy(links[1][40].ip,"./data/SC2_/S5_S6/S5_S6_1.txt");
 strcpy(links[1][41].ip,"./data/SC2_/S5_S6/S5_S6_2.txt");
 strcpy(links[1][42].ip,"./data/SC2_/S5_S6/S5_S6_3.txt");
 strcpy(links[1][43].ip,"./data/SC2_/S5_S6/S5_S6_4.txt");
 strcpy(links[1][44].ip,"./data/SC2_/S5_S6/S5_S6_5.txt");
 strcpy(links[1][45].ip,"./data/SC2_/S5_S6/S5_S6_6.txt");
 strcpy(links[1][46].ip,"./data/SC2_/S5_S6/S5_S6_7.txt");
 strcpy(links[1][47].ip,"./data/SC2_/S5_S6/S5_S6_8.txt");
 strcpy(links[1][48].ip,"./data/SC2_/S5_S6/S5_S6_9.txt");
 strcpy(links[1][49].ip,"./data/SC2_/S5_S6/S5_S6_10.txt");
 strcpy(links[1][50].ip,"./data/SC2_/S6_S5/S6_S5_1.txt");
 strcpy(links[1][51].ip,"./data/SC2_/S6_S5/S6_S5_2.txt");
 strcpy(links[1][52].ip,"./data/SC2_/S6_S5/S6_S5_3.txt");
 strcpy(links[1][53].ip,"./data/SC2_/S6_S5/S6_S5_4.txt");
 strcpy(links[1][54].ip,"./data/SC2_/S6_S5/S6_S5_5.txt");
 strcpy(links[1][55].ip,"./data/SC2_/S6_S5/S6_S5_6.txt");
 strcpy(links[1][56].ip,"./data/SC2_/S6_S5/S6_S5_7.txt");
 strcpy(links[1][57].ip,"./data/SC2_/S6_S5/S6_S5_8.txt");
 strcpy(links[1][58].ip,"./data/SC2_/S6_S5/S6_S5_9.txt");
 strcpy(links[1][59].ip,"./data/SC2_/S6_S5/S6_S5_10.txt");
 strcpy(links[1][60].ip,"./data/SC2_/S7_S8/S7_S8_1.txt");
 strcpy(links[1][61].ip,"./data/SC2_/S7_S8/S7_S8_2.txt");
 strcpy(links[1][62].ip,"./data/SC2_/S7_S8/S7_S8_3.txt");
 strcpy(links[1][63].ip,"./data/SC2_/S7_S8/S7_S8_4.txt");
 strcpy(links[1][64].ip,"./data/SC2_/S7_S8/S7_S8_5.txt");
 strcpy(links[1][65].ip,"./data/SC2_/S7_S8/S7_S8_6.txt");
 strcpy(links[1][66].ip,"./data/SC2_/S7_S8/S7_S8_7.txt");
 strcpy(links[1][67].ip,"./data/SC2_/S7_S8/S7_S8_8.txt");
 strcpy(links[1][68].ip,"./data/SC2_/S7_S8/S7_S8_9.txt");
 strcpy(links[1][69].ip,"./data/SC2_/S7_S8/S7_S8_10.txt");
 strcpy(links[1][70].ip,"./data/SC2_/S8_S7/S8_S7_1.txt");
 strcpy(links[1][71].ip,"./data/SC2_/S8_S7/S8_S7_2.txt");
 strcpy(links[1][72].ip,"./data/SC2_/S8_S7/S8_S7_3.txt");
 strcpy(links[1][73].ip,"./data/SC2_/S8_S7/S8_S7_4.txt");
 strcpy(links[1][74].ip,"./data/SC2_/S8_S7/S8_S7_5.txt");
 strcpy(links[1][75].ip,"./data/SC2_/S8_S7/S8_S7_6.txt");
 strcpy(links[1][76].ip,"./data/SC2_/S8_S7/S8_S7_7.txt");
 strcpy(links[1][77].ip,"./data/SC2_/S8_S7/S8_S7_8.txt");
 strcpy(links[1][78].ip,"./data/SC2_/S8_S7/S8_S7_9.txt");
 strcpy(links[1][79].ip,"./data/SC2_/S8_S7/S8_S7_10.txt");
}


void set_links_3()                                                                   //Storing input file links[2] for scenario 3
{
 strcpy(links[2][0].ip,"./data/SC3_/S1_S2/S1_S2_1.txt");
 strcpy(links[2][1].ip,"./data/SC3_/S1_S2/S1_S2_2.txt");
 strcpy(links[2][2].ip,"./data/SC3_/S1_S2/S1_S2_3.txt");
 strcpy(links[2][3].ip,"./data/SC3_/S1_S2/S1_S2_4.txt");
 strcpy(links[2][4].ip,"./data/SC3_/S1_S2/S1_S2_5.txt");
 strcpy(links[2][5].ip,"./data/SC3_/S1_S2/S1_S2_6.txt");
 strcpy(links[2][6].ip,"./data/SC3_/S1_S2/S1_S2_7.txt");
 strcpy(links[2][7].ip,"./data/SC3_/S1_S2/S1_S2_8.txt");
 strcpy(links[2][8].ip,"./data/SC3_/S1_S2/S1_S2_9.txt");
 strcpy(links[2][9].ip,"./data/SC3_/S1_S2/S1_S2_10.txt");
 strcpy(links[2][10].ip,"./data/SC3_/S2_S1/S2_S1_1.txt");
 strcpy(links[2][11].ip,"./data/SC3_/S2_S1/S2_S1_2.txt");
 strcpy(links[2][12].ip,"./data/SC3_/S2_S1/S2_S1_3.txt");
 strcpy(links[2][13].ip,"./data/SC3_/S2_S1/S2_S1_4.txt");
 strcpy(links[2][14].ip,"./data/SC3_/S2_S1/S2_S1_5.txt");
 strcpy(links[2][15].ip,"./data/SC3_/S2_S1/S2_S1_6.txt");
 strcpy(links[2][16].ip,"./data/SC3_/S2_S1/S2_S1_7.txt");
 strcpy(links[2][17].ip,"./data/SC3_/S2_S1/S2_S1_8.txt");
 strcpy(links[2][18].ip,"./data/SC3_/S2_S1/S2_S1_9.txt");
 strcpy(links[2][19].ip,"./data/SC3_/S2_S1/S2_S1_10.txt");
 strcpy(links[2][20].ip,"./data/SC3_/S3_S4/S3_S4_1.txt");
 strcpy(links[2][21].ip,"./data/SC3_/S3_S4/S3_S4_2.txt");
 strcpy(links[2][22].ip,"./data/SC3_/S3_S4/S3_S4_3.txt");
 strcpy(links[2][23].ip,"./data/SC3_/S3_S4/S3_S4_4.txt");
 strcpy(links[2][24].ip,"./data/SC3_/S3_S4/S3_S4_5.txt");
 strcpy(links[2][25].ip,"./data/SC3_/S3_S4/S3_S4_6.txt");
 strcpy(links[2][26].ip,"./data/SC3_/S3_S4/S3_S4_7.txt");
 strcpy(links[2][27].ip,"./data/SC3_/S3_S4/S3_S4_8.txt");
 strcpy(links[2][28].ip,"./data/SC3_/S3_S4/S3_S4_9.txt");
 strcpy(links[2][29].ip,"./data/SC3_/S3_S4/S3_S4_10.txt");
 strcpy(links[2][30].ip,"./data/SC3_/S4_S3/S4_S3_1.txt");
 strcpy(links[2][31].ip,"./data/SC3_/S4_S3/S4_S3_2.txt");
 strcpy(links[2][32].ip,"./data/SC3_/S4_S3/S4_S3_3.txt");
 strcpy(links[2][33].ip,"./data/SC3_/S4_S3/S4_S3_4.txt");
 strcpy(links[2][34].ip,"./data/SC3_/S4_S3/S4_S3_5.txt");
 strcpy(links[2][35].ip,"./data/SC3_/S4_S3/S4_S3_6.txt");
 strcpy(links[2][36].ip,"./data/SC3_/S4_S3/S4_S3_7.txt");
 strcpy(links[2][37].ip,"./data/SC3_/S4_S3/S4_S3_8.txt");
 strcpy(links[2][38].ip,"./data/SC3_/S4_S3/S4_S3_9.txt");
 strcpy(links[2][39].ip,"./data/SC3_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[2][40].ip,"./data/SC3_/S5_S6/S5_S6_1.txt");
 strcpy(links[2][41].ip,"./data/SC3_/S5_S6/S5_S6_2.txt");
 strcpy(links[2][42].ip,"./data/SC3_/S5_S6/S5_S6_3.txt");
 strcpy(links[2][43].ip,"./data/SC3_/S5_S6/S5_S6_4.txt");
 strcpy(links[2][44].ip,"./data/SC3_/S5_S6/S5_S6_5.txt");
 strcpy(links[2][45].ip,"./data/SC3_/S5_S6/S5_S6_6.txt");
 strcpy(links[2][46].ip,"./data/SC3_/S5_S6/S5_S6_7.txt");
 strcpy(links[2][47].ip,"./data/SC3_/S5_S6/S5_S6_8.txt");
 strcpy(links[2][48].ip,"./data/SC3_/S5_S6/S5_S6_9.txt");
 strcpy(links[2][49].ip,"./data/SC3_/S5_S6/S5_S6_10.txt");
 strcpy(links[2][50].ip,"./data/SC3_/S6_S5/S6_S5_1.txt");
 strcpy(links[2][51].ip,"./data/SC3_/S6_S5/S6_S5_2.txt");
 strcpy(links[2][52].ip,"./data/SC3_/S6_S5/S6_S5_3.txt");
 strcpy(links[2][53].ip,"./data/SC3_/S6_S5/S6_S5_4.txt");
 strcpy(links[2][54].ip,"./data/SC3_/S6_S5/S6_S5_5.txt");
 strcpy(links[2][55].ip,"./data/SC3_/S6_S5/S6_S5_6.txt");
 strcpy(links[2][56].ip,"./data/SC3_/S6_S5/S6_S5_7.txt");
 strcpy(links[2][57].ip,"./data/SC3_/S6_S5/S6_S5_8.txt");
 strcpy(links[2][58].ip,"./data/SC3_/S6_S5/S6_S5_9.txt");
 strcpy(links[2][59].ip,"./data/SC3_/S6_S5/S6_S5_10.txt");
 strcpy(links[2][60].ip,"./data/SC3_/S7_S8/S7_S8_1.txt");
 strcpy(links[2][61].ip,"./data/SC3_/S7_S8/S7_S8_2.txt");
 strcpy(links[2][62].ip,"./data/SC3_/S7_S8/S7_S8_3.txt");
 strcpy(links[2][63].ip,"./data/SC3_/S7_S8/S7_S8_4.txt");
 strcpy(links[2][64].ip,"./data/SC3_/S7_S8/S7_S8_5.txt");
 strcpy(links[2][65].ip,"./data/SC3_/S7_S8/S7_S8_6.txt");
 strcpy(links[2][66].ip,"./data/SC3_/S7_S8/S7_S8_7.txt");
 strcpy(links[2][67].ip,"./data/SC3_/S7_S8/S7_S8_8.txt");
 strcpy(links[2][68].ip,"./data/SC3_/S7_S8/S7_S8_9.txt");
 strcpy(links[2][69].ip,"./data/SC3_/S7_S8/S7_S8_10.txt");
 strcpy(links[2][70].ip,"./data/SC3_/S8_S7/S8_S7_1.txt");
 strcpy(links[2][71].ip,"./data/SC3_/S8_S7/S8_S7_2.txt");
 strcpy(links[2][72].ip,"./data/SC3_/S8_S7/S8_S7_3.txt");
 strcpy(links[2][73].ip,"./data/SC3_/S8_S7/S8_S7_4.txt");
 strcpy(links[2][74].ip,"./data/SC3_/S8_S7/S8_S7_5.txt");
 strcpy(links[2][75].ip,"./data/SC3_/S8_S7/S8_S7_6.txt");
 strcpy(links[2][76].ip,"./data/SC3_/S8_S7/S8_S7_7.txt");
 strcpy(links[2][77].ip,"./data/SC3_/S8_S7/S8_S7_8.txt");
 strcpy(links[2][78].ip,"./data/SC3_/S8_S7/S8_S7_9.txt");
 strcpy(links[2][79].ip,"./data/SC3_/S8_S7/S8_S7_10.txt");
}




void set_links_4()                                                                  //Storing input file links[3] for scenario 4
{
 strcpy(links[3][0].ip,"./data/SC4_/S1_S2/S1_S2_1.txt");
 strcpy(links[3][1].ip,"./data/SC4_/S1_S2/S1_S2_2.txt");
 strcpy(links[3][2].ip,"./data/SC4_/S1_S2/S1_S2_3.txt");
 strcpy(links[3][3].ip,"./data/SC4_/S1_S2/S1_S2_4.txt");
 strcpy(links[3][4].ip,"./data/SC4_/S1_S2/S1_S2_5.txt");
 strcpy(links[3][5].ip,"./data/SC4_/S1_S2/S1_S2_6.txt");
 strcpy(links[3][6].ip,"./data/SC4_/S1_S2/S1_S2_7.txt");
 strcpy(links[3][7].ip,"./data/SC4_/S1_S2/S1_S2_8.txt");
 strcpy(links[3][8].ip,"./data/SC4_/S1_S2/S1_S2_9.txt");
 strcpy(links[3][9].ip,"./data/SC4_/S1_S2/S1_S2_10.txt");
 strcpy(links[3][10].ip,"./data/SC4_/S2_S1/S2_S1_1.txt");
 strcpy(links[3][11].ip,"./data/SC4_/S2_S1/S2_S1_2.txt");
 strcpy(links[3][12].ip,"./data/SC4_/S2_S1/S2_S1_3.txt");
 strcpy(links[3][13].ip,"./data/SC4_/S2_S1/S2_S1_4.txt");
 strcpy(links[3][14].ip,"./data/SC4_/S2_S1/S2_S1_5.txt");
 strcpy(links[3][15].ip,"./data/SC4_/S2_S1/S2_S1_6.txt");
 strcpy(links[3][16].ip,"./data/SC4_/S2_S1/S2_S1_7.txt");
 strcpy(links[3][17].ip,"./data/SC4_/S2_S1/S2_S1_8.txt");
 strcpy(links[3][18].ip,"./data/SC4_/S2_S1/S2_S1_9.txt");
 strcpy(links[3][19].ip,"./data/SC4_/S2_S1/S2_S1_10.txt");
 strcpy(links[3][20].ip,"./data/SC4_/S3_S4/S3_S4_1.txt");
 strcpy(links[3][21].ip,"./data/SC4_/S3_S4/S3_S4_2.txt");
 strcpy(links[3][22].ip,"./data/SC4_/S3_S4/S3_S4_3.txt");
 strcpy(links[3][23].ip,"./data/SC4_/S3_S4/S3_S4_4.txt");
 strcpy(links[3][24].ip,"./data/SC4_/S3_S4/S3_S4_5.txt");
 strcpy(links[3][25].ip,"./data/SC4_/S3_S4/S3_S4_6.txt");
 strcpy(links[3][26].ip,"./data/SC4_/S3_S4/S3_S4_7.txt");
 strcpy(links[3][27].ip,"./data/SC4_/S3_S4/S3_S4_8.txt");
 strcpy(links[3][28].ip,"./data/SC4_/S3_S4/S3_S4_9.txt");
 strcpy(links[3][29].ip,"./data/SC4_/S3_S4/S3_S4_10.txt");
 strcpy(links[3][30].ip,"./data/SC4_/S4_S3/S4_S3_1.txt");
 strcpy(links[3][31].ip,"./data/SC4_/S4_S3/S4_S3_2.txt");
 strcpy(links[3][32].ip,"./data/SC4_/S4_S3/S4_S3_3.txt");
 strcpy(links[3][33].ip,"./data/SC4_/S4_S3/S4_S3_4.txt");
 strcpy(links[3][34].ip,"./data/SC4_/S4_S3/S4_S3_5.txt");
 strcpy(links[3][35].ip,"./data/SC4_/S4_S3/S4_S3_6.txt");
 strcpy(links[3][36].ip,"./data/SC4_/S4_S3/S4_S3_7.txt");
 strcpy(links[3][37].ip,"./data/SC4_/S4_S3/S4_S3_8.txt");
 strcpy(links[3][38].ip,"./data/SC4_/S4_S3/S4_S3_9.txt");
 strcpy(links[3][39].ip,"./data/SC4_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[3][40].ip,"./data/SC4_/S5_S6/S5_S6_1.txt");
 strcpy(links[3][41].ip,"./data/SC4_/S5_S6/S5_S6_2.txt");
 strcpy(links[3][42].ip,"./data/SC4_/S5_S6/S5_S6_3.txt");
 strcpy(links[3][43].ip,"./data/SC4_/S5_S6/S5_S6_4.txt");
 strcpy(links[3][44].ip,"./data/SC4_/S5_S6/S5_S6_5.txt");
 strcpy(links[3][45].ip,"./data/SC4_/S5_S6/S5_S6_6.txt");
 strcpy(links[3][46].ip,"./data/SC4_/S5_S6/S5_S6_7.txt");
 strcpy(links[3][47].ip,"./data/SC4_/S5_S6/S5_S6_8.txt");
 strcpy(links[3][48].ip,"./data/SC4_/S5_S6/S5_S6_9.txt");
 strcpy(links[3][49].ip,"./data/SC4_/S5_S6/S5_S6_10.txt");
 strcpy(links[3][50].ip,"./data/SC4_/S6_S5/S6_S5_1.txt");
 strcpy(links[3][51].ip,"./data/SC4_/S6_S5/S6_S5_2.txt");
 strcpy(links[3][52].ip,"./data/SC4_/S6_S5/S6_S5_3.txt");
 strcpy(links[3][53].ip,"./data/SC4_/S6_S5/S6_S5_4.txt");
 strcpy(links[3][54].ip,"./data/SC4_/S6_S5/S6_S5_5.txt");
 strcpy(links[3][55].ip,"./data/SC4_/S6_S5/S6_S5_6.txt");
 strcpy(links[3][56].ip,"./data/SC4_/S6_S5/S6_S5_7.txt");
 strcpy(links[3][57].ip,"./data/SC4_/S6_S5/S6_S5_8.txt");
 strcpy(links[3][58].ip,"./data/SC4_/S6_S5/S6_S5_9.txt");
 strcpy(links[3][59].ip,"./data/SC4_/S6_S5/S6_S5_10.txt");
 strcpy(links[3][60].ip,"./data/SC4_/S7_S8/S7_S8_1.txt");
 strcpy(links[3][61].ip,"./data/SC4_/S7_S8/S7_S8_2.txt");
 strcpy(links[3][62].ip,"./data/SC4_/S7_S8/S7_S8_3.txt");
 strcpy(links[3][63].ip,"./data/SC4_/S7_S8/S7_S8_4.txt");
 strcpy(links[3][64].ip,"./data/SC4_/S7_S8/S7_S8_5.txt");
 strcpy(links[3][65].ip,"./data/SC4_/S7_S8/S7_S8_6.txt");
 strcpy(links[3][66].ip,"./data/SC4_/S7_S8/S7_S8_7.txt");
 strcpy(links[3][67].ip,"./data/SC4_/S7_S8/S7_S8_8.txt");
 strcpy(links[3][68].ip,"./data/SC4_/S7_S8/S7_S8_9.txt");
 strcpy(links[3][69].ip,"./data/SC4_/S7_S8/S7_S8_10.txt");
 strcpy(links[3][70].ip,"./data/SC4_/S8_S7/S8_S7_1.txt");
 strcpy(links[3][71].ip,"./data/SC4_/S8_S7/S8_S7_2.txt");
 strcpy(links[3][72].ip,"./data/SC4_/S8_S7/S8_S7_3.txt");
 strcpy(links[3][73].ip,"./data/SC4_/S8_S7/S8_S7_4.txt");
 strcpy(links[3][74].ip,"./data/SC4_/S8_S7/S8_S7_5.txt");
 strcpy(links[3][75].ip,"./data/SC4_/S8_S7/S8_S7_6.txt");
 strcpy(links[3][76].ip,"./data/SC4_/S8_S7/S8_S7_7.txt");
 strcpy(links[3][77].ip,"./data/SC4_/S8_S7/S8_S7_8.txt");
 strcpy(links[3][78].ip,"./data/SC4_/S8_S7/S8_S7_9.txt");
 strcpy(links[3][79].ip,"./data/SC4_/S8_S7/S8_S7_10.txt");
}





void set_links_5()                                                             //Storing input file links[4] for scenario 5
{
 strcpy(links[4][0].ip,"./data/SC5_/S1_S2/S1_S2_1.txt");
 strcpy(links[4][1].ip,"./data/SC5_/S1_S2/S1_S2_2.txt");
 strcpy(links[4][2].ip,"./data/SC5_/S1_S2/S1_S2_3.txt");
 strcpy(links[4][3].ip,"./data/SC5_/S1_S2/S1_S2_4.txt");
 strcpy(links[4][4].ip,"./data/SC5_/S1_S2/S1_S2_5.txt");
 strcpy(links[4][5].ip,"./data/SC5_/S1_S2/S1_S2_6.txt");
 strcpy(links[4][6].ip,"./data/SC5_/S1_S2/S1_S2_7.txt");
 strcpy(links[4][7].ip,"./data/SC5_/S1_S2/S1_S2_8.txt");
 strcpy(links[4][8].ip,"./data/SC5_/S1_S2/S1_S2_9.txt");
 strcpy(links[4][9].ip,"./data/SC5_/S1_S2/S1_S2_10.txt");
 strcpy(links[4][10].ip,"./data/SC5_/S2_S1/S2_S1_1.txt");
 strcpy(links[4][11].ip,"./data/SC5_/S2_S1/S2_S1_2.txt");
 strcpy(links[4][12].ip,"./data/SC5_/S2_S1/S2_S1_3.txt");
 strcpy(links[4][13].ip,"./data/SC5_/S2_S1/S2_S1_4.txt");
 strcpy(links[4][14].ip,"./data/SC5_/S2_S1/S2_S1_5.txt");
 strcpy(links[4][15].ip,"./data/SC5_/S2_S1/S2_S1_6.txt");
 strcpy(links[4][16].ip,"./data/SC5_/S2_S1/S2_S1_7.txt");
 strcpy(links[4][17].ip,"./data/SC5_/S2_S1/S2_S1_8.txt");
 strcpy(links[4][18].ip,"./data/SC5_/S2_S1/S2_S1_9.txt");
 strcpy(links[4][19].ip,"./data/SC5_/S2_S1/S2_S1_10.txt");
 strcpy(links[4][20].ip,"./data/SC5_/S3_S4/S3_S4_1.txt");
 strcpy(links[4][21].ip,"./data/SC5_/S3_S4/S3_S4_2.txt");
 strcpy(links[4][22].ip,"./data/SC5_/S3_S4/S3_S4_3.txt");
 strcpy(links[4][23].ip,"./data/SC5_/S3_S4/S3_S4_4.txt");
 strcpy(links[4][24].ip,"./data/SC5_/S3_S4/S3_S4_5.txt");
 strcpy(links[4][25].ip,"./data/SC5_/S3_S4/S3_S4_6.txt");
 strcpy(links[4][26].ip,"./data/SC5_/S3_S4/S3_S4_7.txt");
 strcpy(links[4][27].ip,"./data/SC5_/S3_S4/S3_S4_8.txt");
 strcpy(links[4][28].ip,"./data/SC5_/S3_S4/S3_S4_9.txt");
 strcpy(links[4][29].ip,"./data/SC5_/S3_S4/S3_S4_10.txt");
 strcpy(links[4][30].ip,"./data/SC5_/S4_S3/S4_S3_1.txt");
 strcpy(links[4][31].ip,"./data/SC5_/S4_S3/S4_S3_2.txt");
 strcpy(links[4][32].ip,"./data/SC5_/S4_S3/S4_S3_3.txt");
 strcpy(links[4][33].ip,"./data/SC5_/S4_S3/S4_S3_4.txt");
 strcpy(links[4][34].ip,"./data/SC5_/S4_S3/S4_S3_5.txt");
 strcpy(links[4][35].ip,"./data/SC5_/S4_S3/S4_S3_6.txt");
 strcpy(links[4][36].ip,"./data/SC5_/S4_S3/S4_S3_7.txt");
 strcpy(links[4][37].ip,"./data/SC5_/S4_S3/S4_S3_8.txt");
 strcpy(links[4][38].ip,"./data/SC5_/S4_S3/S4_S3_9.txt");
 strcpy(links[4][39].ip,"./data/SC5_/S4_S3/S4_S3_10.txt");
 
 
 
 strcpy(links[4][40].ip,"./data/SC5_/S5_S6/S5_S6_1.txt");
 strcpy(links[4][41].ip,"./data/SC5_/S5_S6/S5_S6_2.txt");
 strcpy(links[4][42].ip,"./data/SC5_/S5_S6/S5_S6_3.txt");
 strcpy(links[4][43].ip,"./data/SC5_/S5_S6/S5_S6_4.txt");
 strcpy(links[4][44].ip,"./data/SC5_/S5_S6/S5_S6_5.txt");
 strcpy(links[4][45].ip,"./data/SC5_/S5_S6/S5_S6_6.txt");
 strcpy(links[4][46].ip,"./data/SC5_/S5_S6/S5_S6_7.txt");
 strcpy(links[4][47].ip,"./data/SC5_/S5_S6/S5_S6_8.txt");
 strcpy(links[4][48].ip,"./data/SC5_/S5_S6/S5_S6_9.txt");
 strcpy(links[4][49].ip,"./data/SC5_/S5_S6/S5_S6_10.txt");
 strcpy(links[4][50].ip,"./data/SC5_/S6_S5/S6_S5_1.txt");
 strcpy(links[4][51].ip,"./data/SC5_/S6_S5/S6_S5_2.txt");
 strcpy(links[4][52].ip,"./data/SC5_/S6_S5/S6_S5_3.txt");
 strcpy(links[4][53].ip,"./data/SC5_/S6_S5/S6_S5_4.txt");
 strcpy(links[4][54].ip,"./data/SC5_/S6_S5/S6_S5_5.txt");
 strcpy(links[4][55].ip,"./data/SC5_/S6_S5/S6_S5_6.txt");
 strcpy(links[4][56].ip,"./data/SC5_/S6_S5/S6_S5_7.txt");
 strcpy(links[4][57].ip,"./data/SC5_/S6_S5/S6_S5_8.txt");
 strcpy(links[4][58].ip,"./data/SC5_/S6_S5/S6_S5_9.txt");
 strcpy(links[4][59].ip,"./data/SC5_/S6_S5/S6_S5_10.txt");
 strcpy(links[4][60].ip,"./data/SC5_/S7_S8/S7_S8_1.txt");
 strcpy(links[4][61].ip,"./data/SC5_/S7_S8/S7_S8_2.txt");
 strcpy(links[4][62].ip,"./data/SC5_/S7_S8/S7_S8_3.txt");
 strcpy(links[4][63].ip,"./data/SC5_/S7_S8/S7_S8_4.txt");
 strcpy(links[4][64].ip,"./data/SC5_/S7_S8/S7_S8_5.txt");
 strcpy(links[4][65].ip,"./data/SC5_/S7_S8/S7_S8_6.txt");
 strcpy(links[4][66].ip,"./data/SC5_/S7_S8/S7_S8_7.txt");
 strcpy(links[4][67].ip,"./data/SC5_/S7_S8/S7_S8_8.txt");
 strcpy(links[4][68].ip,"./data/SC5_/S7_S8/S7_S8_9.txt");
 strcpy(links[4][69].ip,"./data/SC5_/S7_S8/S7_S8_10.txt");
 strcpy(links[4][70].ip,"./data/SC5_/S8_S7/S8_S7_1.txt");
 strcpy(links[4][71].ip,"./data/SC5_/S8_S7/S8_S7_2.txt");
 strcpy(links[4][72].ip,"./data/SC5_/S8_S7/S8_S7_3.txt");
 strcpy(links[4][73].ip,"./data/SC5_/S8_S7/S8_S7_4.txt");
 strcpy(links[4][74].ip,"./data/SC5_/S8_S7/S8_S7_5.txt");
 strcpy(links[4][75].ip,"./data/SC5_/S8_S7/S8_S7_6.txt");
 strcpy(links[4][76].ip,"./data/SC5_/S8_S7/S8_S7_7.txt");
 strcpy(links[4][77].ip,"./data/SC5_/S8_S7/S8_S7_8.txt");
 strcpy(links[4][78].ip,"./data/SC5_/S8_S7/S8_S7_9.txt");
 strcpy(links[4][79].ip,"./data/SC5_/S8_S7/S8_S7_10.txt");
}




void set_links_6()                                             //Storing input file links[5] for scenario 6
{
 strcpy(links[5][0].ip,"./data/SC6_/S1_S2/S1_S2_1.txt");
 strcpy(links[5][1].ip,"./data/SC6_/S1_S2/S1_S2_2.txt");
 strcpy(links[5][2].ip,"./data/SC6_/S1_S2/S1_S2_3.txt");
 strcpy(links[5][3].ip,"./data/SC6_/S1_S2/S1_S2_4.txt");
 strcpy(links[5][4].ip,"./data/SC6_/S1_S2/S1_S2_5.txt");
 strcpy(links[5][5].ip,"./data/SC6_/S1_S2/S1_S2_6.txt");
 strcpy(links[5][6].ip,"./data/SC6_/S1_S2/S1_S2_7.txt");
 strcpy(links[5][7].ip,"./data/SC6_/S1_S2/S1_S2_8.txt");
 strcpy(links[5][8].ip,"./data/SC6_/S1_S2/S1_S2_9.txt");
 strcpy(links[5][9].ip,"./data/SC6_/S1_S2/S1_S2_10.txt");
 strcpy(links[5][10].ip,"./data/SC6_/S2_S1/S2_S1_1.txt");
 strcpy(links[5][11].ip,"./data/SC6_/S2_S1/S2_S1_2.txt");
 strcpy(links[5][12].ip,"./data/SC6_/S2_S1/S2_S1_3.txt");
 strcpy(links[5][13].ip,"./data/SC6_/S2_S1/S2_S1_4.txt");
 strcpy(links[5][14].ip,"./data/SC6_/S2_S1/S2_S1_5.txt");
 strcpy(links[5][15].ip,"./data/SC6_/S2_S1/S2_S1_6.txt");
 strcpy(links[5][16].ip,"./data/SC6_/S2_S1/S2_S1_7.txt");
 strcpy(links[5][17].ip,"./data/SC6_/S2_S1/S2_S1_8.txt");
 strcpy(links[5][18].ip,"./data/SC6_/S2_S1/S2_S1_9.txt");
 strcpy(links[5][19].ip,"./data/SC6_/S2_S1/S2_S1_10.txt");
 strcpy(links[5][20].ip,"./data/SC6_/S3_S4/S3_S4_1.txt");
 strcpy(links[5][21].ip,"./data/SC6_/S3_S4/S3_S4_2.txt");
 strcpy(links[5][22].ip,"./data/SC6_/S3_S4/S3_S4_3.txt");
 strcpy(links[5][23].ip,"./data/SC6_/S3_S4/S3_S4_4.txt");
 strcpy(links[5][24].ip,"./data/SC6_/S3_S4/S3_S4_5.txt");
 strcpy(links[5][25].ip,"./data/SC6_/S3_S4/S3_S4_6.txt");
 strcpy(links[5][26].ip,"./data/SC6_/S3_S4/S3_S4_7.txt");
 strcpy(links[5][27].ip,"./data/SC6_/S3_S4/S3_S4_8.txt");
 strcpy(links[5][28].ip,"./data/SC6_/S3_S4/S3_S4_9.txt");
 strcpy(links[5][29].ip,"./data/SC6_/S3_S4/S3_S4_10.txt");
 strcpy(links[5][30].ip,"./data/SC6_/S4_S3/S4_S3_1.txt");
 strcpy(links[5][31].ip,"./data/SC6_/S4_S3/S4_S3_2.txt");
 strcpy(links[5][32].ip,"./data/SC6_/S4_S3/S4_S3_3.txt");
 strcpy(links[5][33].ip,"./data/SC6_/S4_S3/S4_S3_4.txt");
 strcpy(links[5][34].ip,"./data/SC6_/S4_S3/S4_S3_5.txt");
 strcpy(links[5][35].ip,"./data/SC6_/S4_S3/S4_S3_6.txt");
 strcpy(links[5][36].ip,"./data/SC6_/S4_S3/S4_S3_7.txt");
 strcpy(links[5][37].ip,"./data/SC6_/S4_S3/S4_S3_8.txt");
 strcpy(links[5][38].ip,"./data/SC6_/S4_S3/S4_S3_9.txt");
 strcpy(links[5][39].ip,"./data/SC6_/S4_S3/S4_S3_10.txt");
 
 
 
 
 strcpy(links[5][40].ip,"./data/SC6_/S5_S6/S5_S6_1.txt");
 strcpy(links[5][41].ip,"./data/SC6_/S5_S6/S5_S6_2.txt");
 strcpy(links[5][42].ip,"./data/SC6_/S5_S6/S5_S6_3.txt");
 strcpy(links[5][43].ip,"./data/SC6_/S5_S6/S5_S6_4.txt");
 strcpy(links[5][44].ip,"./data/SC6_/S5_S6/S5_S6_5.txt");
 strcpy(links[5][45].ip,"./data/SC6_/S5_S6/S5_S6_6.txt");
 strcpy(links[5][46].ip,"./data/SC6_/S5_S6/S5_S6_7.txt");
 strcpy(links[5][47].ip,"./data/SC6_/S5_S6/S5_S6_8.txt");
 strcpy(links[5][48].ip,"./data/SC6_/S5_S6/S5_S6_9.txt");
 strcpy(links[5][49].ip,"./data/SC6_/S5_S6/S5_S6_10.txt");
 strcpy(links[5][50].ip,"./data/SC6_/S6_S5/S6_S5_1.txt");
 strcpy(links[5][51].ip,"./data/SC6_/S6_S5/S6_S5_2.txt");
 strcpy(links[5][52].ip,"./data/SC6_/S6_S5/S6_S5_3.txt");
 strcpy(links[5][53].ip,"./data/SC6_/S6_S5/S6_S5_4.txt");
 strcpy(links[5][54].ip,"./data/SC6_/S6_S5/S6_S5_5.txt");
 strcpy(links[5][55].ip,"./data/SC6_/S6_S5/S6_S5_6.txt");
 strcpy(links[5][56].ip,"./data/SC6_/S6_S5/S6_S5_7.txt");
 strcpy(links[5][57].ip,"./data/SC6_/S6_S5/S6_S5_8.txt");
 strcpy(links[5][58].ip,"./data/SC6_/S6_S5/S6_S5_9.txt");
 strcpy(links[5][59].ip,"./data/SC6_/S6_S5/S6_S5_10.txt");
 strcpy(links[5][60].ip,"./data/SC6_/S7_S8/S7_S8_1.txt");
 strcpy(links[5][61].ip,"./data/SC6_/S7_S8/S7_S8_2.txt");
 strcpy(links[5][62].ip,"./data/SC6_/S7_S8/S7_S8_3.txt");
 strcpy(links[5][63].ip,"./data/SC6_/S7_S8/S7_S8_4.txt");
 strcpy(links[5][64].ip,"./data/SC6_/S7_S8/S7_S8_5.txt");
 strcpy(links[5][65].ip,"./data/SC6_/S7_S8/S7_S8_6.txt");
 strcpy(links[5][66].ip,"./data/SC6_/S7_S8/S7_S8_7.txt");
 strcpy(links[5][67].ip,"./data/SC6_/S7_S8/S7_S8_8.txt");
 strcpy(links[5][68].ip,"./data/SC6_/S7_S8/S7_S8_9.txt");
 strcpy(links[5][69].ip,"./data/SC6_/S7_S8/S7_S8_10.txt");
 strcpy(links[5][70].ip,"./data/SC6_/S8_S7/S8_S7_1.txt");
 strcpy(links[5][71].ip,"./data/SC6_/S8_S7/S8_S7_2.txt");
 strcpy(links[5][72].ip,"./data/SC6_/S8_S7/S8_S7_3.txt");
 strcpy(links[5][73].ip,"./data/SC6_/S8_S7/S8_S7_4.txt");
 strcpy(links[5][74].ip,"./data/SC6_/S8_S7/S8_S7_5.txt");
 strcpy(links[5][75].ip,"./data/SC6_/S8_S7/S8_S7_6.txt");
 strcpy(links[5][76].ip,"./data/SC6_/S8_S7/S8_S7_7.txt");
 strcpy(links[5][77].ip,"./data/SC6_/S8_S7/S8_S7_8.txt");
 strcpy(links[5][78].ip,"./data/SC6_/S8_S7/S8_S7_9.txt");
 strcpy(links[5][79].ip,"./data/SC6_/S8_S7/S8_S7_10.txt");
}



void set_links_7()                                                   //Storing input file links[6] for scenario 7
{
 strcpy(links[6][0].ip,"./data/SC7_/S1_S2/S1_S2_1.txt");
 strcpy(links[6][1].ip,"./data/SC7_/S1_S2/S1_S2_2.txt");
 strcpy(links[6][2].ip,"./data/SC7_/S1_S2/S1_S2_3.txt");
 strcpy(links[6][3].ip,"./data/SC7_/S1_S2/S1_S2_4.txt");
 strcpy(links[6][4].ip,"./data/SC7_/S1_S2/S1_S2_5.txt");
 strcpy(links[6][5].ip,"./data/SC7_/S1_S2/S1_S2_6.txt");
 strcpy(links[6][6].ip,"./data/SC7_/S1_S2/S1_S2_7.txt");
 strcpy(links[6][7].ip,"./data/SC7_/S1_S2/S1_S2_8.txt");
 strcpy(links[6][8].ip,"./data/SC7_/S1_S2/S1_S2_9.txt");
 strcpy(links[6][9].ip,"./data/SC7_/S1_S2/S1_S2_10.txt");
 strcpy(links[6][10].ip,"./data/SC7_/S2_S1/S2_S1_1.txt");
 strcpy(links[6][11].ip,"./data/SC7_/S2_S1/S2_S1_2.txt");
 strcpy(links[6][12].ip,"./data/SC7_/S2_S1/S2_S1_3.txt");
 strcpy(links[6][13].ip,"./data/SC7_/S2_S1/S2_S1_4.txt");
 strcpy(links[6][14].ip,"./data/SC7_/S2_S1/S2_S1_5.txt");
 strcpy(links[6][15].ip,"./data/SC7_/S2_S1/S2_S1_6.txt");
 strcpy(links[6][16].ip,"./data/SC7_/S2_S1/S2_S1_7.txt");
 strcpy(links[6][17].ip,"./data/SC7_/S2_S1/S2_S1_8.txt");
 strcpy(links[6][18].ip,"./data/SC7_/S2_S1/S2_S1_9.txt");
 strcpy(links[6][19].ip,"./data/SC7_/S2_S1/S2_S1_10.txt");
 strcpy(links[6][20].ip,"./data/SC7_/S3_S4/S3_S4_1.txt");
 strcpy(links[6][21].ip,"./data/SC7_/S3_S4/S3_S4_2.txt");
 strcpy(links[6][22].ip,"./data/SC7_/S3_S4/S3_S4_3.txt");
 strcpy(links[6][23].ip,"./data/SC7_/S3_S4/S3_S4_4.txt");
 strcpy(links[6][24].ip,"./data/SC7_/S3_S4/S3_S4_5.txt");
 strcpy(links[6][25].ip,"./data/SC7_/S3_S4/S3_S4_6.txt");
 strcpy(links[6][26].ip,"./data/SC7_/S3_S4/S3_S4_7.txt");
 strcpy(links[6][27].ip,"./data/SC7_/S3_S4/S3_S4_8.txt");
 strcpy(links[6][28].ip,"./data/SC7_/S3_S4/S3_S4_9.txt");
 strcpy(links[6][29].ip,"./data/SC7_/S3_S4/S3_S4_10.txt");
 strcpy(links[6][30].ip,"./data/SC7_/S4_S3/S4_S3_1.txt");
 strcpy(links[6][31].ip,"./data/SC7_/S4_S3/S4_S3_2.txt");
 strcpy(links[6][32].ip,"./data/SC7_/S4_S3/S4_S3_3.txt");
 strcpy(links[6][33].ip,"./data/SC7_/S4_S3/S4_S3_4.txt");
 strcpy(links[6][34].ip,"./data/SC7_/S4_S3/S4_S3_5.txt");
 strcpy(links[6][35].ip,"./data/SC7_/S4_S3/S4_S3_6.txt");
 strcpy(links[6][36].ip,"./data/SC7_/S4_S3/S4_S3_7.txt");
 strcpy(links[6][37].ip,"./data/SC7_/S4_S3/S4_S3_8.txt");
 strcpy(links[6][38].ip,"./data/SC7_/S4_S3/S4_S3_9.txt");
 strcpy(links[6][39].ip,"./data/SC7_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[6][40].ip,"./data/SC7_/S5_S6/S5_S6_1.txt");
 strcpy(links[6][41].ip,"./data/SC7_/S5_S6/S5_S6_2.txt");
 strcpy(links[6][42].ip,"./data/SC7_/S5_S6/S5_S6_3.txt");
 strcpy(links[6][43].ip,"./data/SC7_/S5_S6/S5_S6_4.txt");
 strcpy(links[6][44].ip,"./data/SC7_/S5_S6/S5_S6_5.txt");
 strcpy(links[6][45].ip,"./data/SC7_/S5_S6/S5_S6_6.txt");
 strcpy(links[6][46].ip,"./data/SC7_/S5_S6/S5_S6_7.txt");
 strcpy(links[6][47].ip,"./data/SC7_/S5_S6/S5_S6_8.txt");
 strcpy(links[6][48].ip,"./data/SC7_/S5_S6/S5_S6_9.txt");
 strcpy(links[6][49].ip,"./data/SC7_/S5_S6/S5_S6_10.txt");
 strcpy(links[6][50].ip,"./data/SC7_/S6_S5/S6_S5_1.txt");
 strcpy(links[6][51].ip,"./data/SC7_/S6_S5/S6_S5_2.txt");
 strcpy(links[6][52].ip,"./data/SC7_/S6_S5/S6_S5_3.txt");
 strcpy(links[6][53].ip,"./data/SC7_/S6_S5/S6_S5_4.txt");
 strcpy(links[6][54].ip,"./data/SC7_/S6_S5/S6_S5_5.txt");
 strcpy(links[6][55].ip,"./data/SC7_/S6_S5/S6_S5_6.txt");
 strcpy(links[6][56].ip,"./data/SC7_/S6_S5/S6_S5_7.txt");
 strcpy(links[6][57].ip,"./data/SC7_/S6_S5/S6_S5_8.txt");
 strcpy(links[6][58].ip,"./data/SC7_/S6_S5/S6_S5_9.txt");
 strcpy(links[6][59].ip,"./data/SC7_/S6_S5/S6_S5_10.txt");
 strcpy(links[6][60].ip,"./data/SC7_/S7_S8/S7_S8_1.txt");
 strcpy(links[6][61].ip,"./data/SC7_/S7_S8/S7_S8_2.txt");
 strcpy(links[6][62].ip,"./data/SC7_/S7_S8/S7_S8_3.txt");
 strcpy(links[6][63].ip,"./data/SC7_/S7_S8/S7_S8_4.txt");
 strcpy(links[6][64].ip,"./data/SC7_/S7_S8/S7_S8_5.txt");
 strcpy(links[6][65].ip,"./data/SC7_/S7_S8/S7_S8_6.txt");
 strcpy(links[6][66].ip,"./data/SC7_/S7_S8/S7_S8_7.txt");
 strcpy(links[6][67].ip,"./data/SC7_/S7_S8/S7_S8_8.txt");
 strcpy(links[6][68].ip,"./data/SC7_/S7_S8/S7_S8_9.txt");
 strcpy(links[6][69].ip,"./data/SC7_/S7_S8/S7_S8_10.txt");
 strcpy(links[6][70].ip,"./data/SC7_/S8_S7/S8_S7_1.txt");
 strcpy(links[6][71].ip,"./data/SC7_/S8_S7/S8_S7_2.txt");
 strcpy(links[6][72].ip,"./data/SC7_/S8_S7/S8_S7_3.txt");
 strcpy(links[6][73].ip,"./data/SC7_/S8_S7/S8_S7_4.txt");
 strcpy(links[6][74].ip,"./data/SC7_/S8_S7/S8_S7_5.txt");
 strcpy(links[6][75].ip,"./data/SC7_/S8_S7/S8_S7_6.txt");
 strcpy(links[6][76].ip,"./data/SC7_/S8_S7/S8_S7_7.txt");
 strcpy(links[6][77].ip,"./data/SC7_/S8_S7/S8_S7_8.txt");
 strcpy(links[6][78].ip,"./data/SC7_/S8_S7/S8_S7_9.txt");
 strcpy(links[6][79].ip,"./data/SC7_/S8_S7/S8_S7_10.txt");
}


void res_links_1()                                                            //Storing output file links[0] for scenario 1
{
 strcpy(links[0][0].resl,"./pdata/SC1_/S1_S2/S1_S2_1.txt");
 strcpy(links[0][1].resl,"./pdata/SC1_/S1_S2/S1_S2_2.txt");
 strcpy(links[0][2].resl,"./pdata/SC1_/S1_S2/S1_S2_3.txt");
 strcpy(links[0][3].resl,"./pdata/SC1_/S1_S2/S1_S2_4.txt");
 strcpy(links[0][4].resl,"./pdata/SC1_/S1_S2/S1_S2_5.txt");
 strcpy(links[0][5].resl,"./pdata/SC1_/S1_S2/S1_S2_6.txt");
 strcpy(links[0][6].resl,"./pdata/SC1_/S1_S2/S1_S2_7.txt");
 strcpy(links[0][7].resl,"./pdata/SC1_/S1_S2/S1_S2_8.txt");
 strcpy(links[0][8].resl,"./pdata/SC1_/S1_S2/S1_S2_9.txt");
 strcpy(links[0][9].resl,"./pdata/SC1_/S1_S2/S1_S2_10.txt");
 strcpy(links[0][10].resl,"./pdata/SC1_/S2_S1/S2_S1_1.txt");
 strcpy(links[0][11].resl,"./pdata/SC1_/S2_S1/S2_S1_2.txt");
 strcpy(links[0][12].resl,"./pdata/SC1_/S2_S1/S2_S1_3.txt");
 strcpy(links[0][13].resl,"./pdata/SC1_/S2_S1/S2_S1_4.txt");
 strcpy(links[0][14].resl,"./pdata/SC1_/S2_S1/S2_S1_5.txt");
 strcpy(links[0][15].resl,"./pdata/SC1_/S2_S1/S2_S1_6.txt");
 strcpy(links[0][16].resl,"./pdata/SC1_/S2_S1/S2_S1_7.txt");
 strcpy(links[0][17].resl,"./pdata/SC1_/S2_S1/S2_S1_8.txt");
 strcpy(links[0][18].resl,"./pdata/SC1_/S2_S1/S2_S1_9.txt");
 strcpy(links[0][19].resl,"./pdata/SC1_/S2_S1/S2_S1_10.txt");
 strcpy(links[0][20].resl,"./pdata/SC1_/S3_S4/S3_S4_1.txt");
 strcpy(links[0][21].resl,"./pdata/SC1_/S3_S4/S3_S4_2.txt");
 strcpy(links[0][22].resl,"./pdata/SC1_/S3_S4/S3_S4_3.txt");
 strcpy(links[0][23].resl,"./pdata/SC1_/S3_S4/S3_S4_4.txt");
 strcpy(links[0][24].resl,"./pdata/SC1_/S3_S4/S3_S4_5.txt");
 strcpy(links[0][25].resl,"./pdata/SC1_/S3_S4/S3_S4_6.txt");
 strcpy(links[0][26].resl,"./pdata/SC1_/S3_S4/S3_S4_7.txt");
 strcpy(links[0][27].resl,"./pdata/SC1_/S3_S4/S3_S4_8.txt");
 strcpy(links[0][28].resl,"./pdata/SC1_/S3_S4/S3_S4_9.txt");
 strcpy(links[0][29].resl,"./pdata/SC1_/S3_S4/S3_S4_10.txt");
 strcpy(links[0][30].resl,"./pdata/SC1_/S4_S3/S4_S3_1.txt");
 strcpy(links[0][31].resl,"./pdata/SC1_/S4_S3/S4_S3_2.txt");
 strcpy(links[0][32].resl,"./pdata/SC1_/S4_S3/S4_S3_3.txt");
 strcpy(links[0][33].resl,"./pdata/SC1_/S4_S3/S4_S3_4.txt");
 strcpy(links[0][34].resl,"./pdata/SC1_/S4_S3/S4_S3_5.txt");
 strcpy(links[0][35].resl,"./pdata/SC1_/S4_S3/S4_S3_6.txt");
 strcpy(links[0][36].resl,"./pdata/SC1_/S4_S3/S4_S3_7.txt");
 strcpy(links[0][37].resl,"./pdata/SC1_/S4_S3/S4_S3_8.txt");
 strcpy(links[0][38].resl,"./pdata/SC1_/S4_S3/S4_S3_9.txt");
 strcpy(links[0][39].resl,"./pdata/SC1_/S4_S3/S4_S3_10.txt");
 
 
 
 
 strcpy(links[0][40].resl,"./pdata/SC1_/S5_S6/S5_S6_1.txt");
 strcpy(links[0][41].resl,"./pdata/SC1_/S5_S6/S5_S6_2.txt");
 strcpy(links[0][42].resl,"./pdata/SC1_/S5_S6/S5_S6_3.txt");
 strcpy(links[0][43].resl,"./pdata/SC1_/S5_S6/S5_S6_4.txt");
 strcpy(links[0][44].resl,"./pdata/SC1_/S5_S6/S5_S6_5.txt");
 strcpy(links[0][45].resl,"./pdata/SC1_/S5_S6/S5_S6_6.txt");
 strcpy(links[0][46].resl,"./pdata/SC1_/S5_S6/S5_S6_7.txt");
 strcpy(links[0][47].resl,"./pdata/SC1_/S5_S6/S5_S6_8.txt");
 strcpy(links[0][48].resl,"./pdata/SC1_/S5_S6/S5_S6_9.txt");
 strcpy(links[0][49].resl,"./pdata/SC1_/S5_S6/S5_S6_10.txt");
 strcpy(links[0][50].resl,"./pdata/SC1_/S6_S5/S6_S5_1.txt");
 strcpy(links[0][51].resl,"./pdata/SC1_/S6_S5/S6_S5_2.txt");
 strcpy(links[0][52].resl,"./pdata/SC1_/S6_S5/S6_S5_3.txt");
 strcpy(links[0][53].resl,"./pdata/SC1_/S6_S5/S6_S5_4.txt");
 strcpy(links[0][54].resl,"./pdata/SC1_/S6_S5/S6_S5_5.txt");
 strcpy(links[0][55].resl,"./pdata/SC1_/S6_S5/S6_S5_6.txt");
 strcpy(links[0][56].resl,"./pdata/SC1_/S6_S5/S6_S5_7.txt");
 strcpy(links[0][57].resl,"./pdata/SC1_/S6_S5/S6_S5_8.txt");
 strcpy(links[0][58].resl,"./pdata/SC1_/S6_S5/S6_S5_9.txt");
 strcpy(links[0][59].resl,"./pdata/SC1_/S6_S5/S6_S5_10.txt");
 strcpy(links[0][60].resl,"./pdata/SC1_/S7_S8/S7_S8_1.txt");
 strcpy(links[0][61].resl,"./pdata/SC1_/S7_S8/S7_S8_2.txt");
 strcpy(links[0][62].resl,"./pdata/SC1_/S7_S8/S7_S8_3.txt");
 strcpy(links[0][63].resl,"./pdata/SC1_/S7_S8/S7_S8_4.txt");
 strcpy(links[0][64].resl,"./pdata/SC1_/S7_S8/S7_S8_5.txt");
 strcpy(links[0][65].resl,"./pdata/SC1_/S7_S8/S7_S8_6.txt");
 strcpy(links[0][66].resl,"./pdata/SC1_/S7_S8/S7_S8_7.txt");
 strcpy(links[0][67].resl,"./pdata/SC1_/S7_S8/S7_S8_8.txt");
 strcpy(links[0][68].resl,"./pdata/SC1_/S7_S8/S7_S8_9.txt");
 strcpy(links[0][69].resl,"./pdata/SC1_/S7_S8/S7_S8_10.txt");
 strcpy(links[0][70].resl,"./pdata/SC1_/S8_S7/S8_S7_1.txt");
 strcpy(links[0][71].resl,"./pdata/SC1_/S8_S7/S8_S7_2.txt");
 strcpy(links[0][72].resl,"./pdata/SC1_/S8_S7/S8_S7_3.txt");
 strcpy(links[0][73].resl,"./pdata/SC1_/S8_S7/S8_S7_4.txt");
 strcpy(links[0][74].resl,"./pdata/SC1_/S8_S7/S8_S7_5.txt");
 strcpy(links[0][75].resl,"./pdata/SC1_/S8_S7/S8_S7_6.txt");
 strcpy(links[0][76].resl,"./pdata/SC1_/S8_S7/S8_S7_7.txt");
 strcpy(links[0][77].resl,"./pdata/SC1_/S8_S7/S8_S7_8.txt");
 strcpy(links[0][78].resl,"./pdata/SC1_/S8_S7/S8_S7_9.txt");
 strcpy(links[0][79].resl,"./pdata/SC1_/S8_S7/S8_S7_10.txt");
}
void res_links_2()                                                             //Storing output file links[1] for scenario 2
{
 strcpy(links[1][0].resl,"./pdata/SC2_/S1_S2/S1_S2_1.txt");
 strcpy(links[1][1].resl,"./pdata/SC2_/S1_S2/S1_S2_2.txt");
 strcpy(links[1][2].resl,"./pdata/SC2_/S1_S2/S1_S2_3.txt");
 strcpy(links[1][3].resl,"./pdata/SC2_/S1_S2/S1_S2_4.txt");
 strcpy(links[1][4].resl,"./pdata/SC2_/S1_S2/S1_S2_5.txt");
 strcpy(links[1][5].resl,"./pdata/SC2_/S1_S2/S1_S2_6.txt");
 strcpy(links[1][6].resl,"./pdata/SC2_/S1_S2/S1_S2_7.txt");
 strcpy(links[1][7].resl,"./pdata/SC2_/S1_S2/S1_S2_8.txt");
 strcpy(links[1][8].resl,"./pdata/SC2_/S1_S2/S1_S2_9.txt");
 strcpy(links[1][9].resl,"./pdata/SC2_/S1_S2/S1_S2_10.txt");
 strcpy(links[1][10].resl,"./pdata/SC2_/S2_S1/S2_S1_1.txt");
 strcpy(links[1][11].resl,"./pdata/SC2_/S2_S1/S2_S1_2.txt");
 strcpy(links[1][12].resl,"./pdata/SC2_/S2_S1/S2_S1_3.txt");
 strcpy(links[1][13].resl,"./pdata/SC2_/S2_S1/S2_S1_4.txt");
 strcpy(links[1][14].resl,"./pdata/SC2_/S2_S1/S2_S1_5.txt");
 strcpy(links[1][15].resl,"./pdata/SC2_/S2_S1/S2_S1_6.txt");
 strcpy(links[1][16].resl,"./pdata/SC2_/S2_S1/S2_S1_7.txt");
 strcpy(links[1][17].resl,"./pdata/SC2_/S2_S1/S2_S1_8.txt");
 strcpy(links[1][18].resl,"./pdata/SC2_/S2_S1/S2_S1_9.txt");
 strcpy(links[1][19].resl,"./pdata/SC2_/S2_S1/S2_S1_10.txt");
 strcpy(links[1][20].resl,"./pdata/SC2_/S3_S4/S3_S4_1.txt");
 strcpy(links[1][21].resl,"./pdata/SC2_/S3_S4/S3_S4_2.txt");
 strcpy(links[1][22].resl,"./pdata/SC2_/S3_S4/S3_S4_3.txt");
 strcpy(links[1][23].resl,"./pdata/SC2_/S3_S4/S3_S4_4.txt");
 strcpy(links[1][24].resl,"./pdata/SC2_/S3_S4/S3_S4_5.txt");
 strcpy(links[1][25].resl,"./pdata/SC2_/S3_S4/S3_S4_6.txt");
 strcpy(links[1][26].resl,"./pdata/SC2_/S3_S4/S3_S4_7.txt");
 strcpy(links[1][27].resl,"./pdata/SC2_/S3_S4/S3_S4_8.txt");
 strcpy(links[1][28].resl,"./pdata/SC2_/S3_S4/S3_S4_9.txt");
 strcpy(links[1][29].resl,"./pdata/SC2_/S3_S4/S3_S4_10.txt");
 strcpy(links[1][30].resl,"./pdata/SC2_/S4_S3/S4_S3_1.txt");
 strcpy(links[1][31].resl,"./pdata/SC2_/S4_S3/S4_S3_2.txt");
 strcpy(links[1][32].resl,"./pdata/SC2_/S4_S3/S4_S3_3.txt");
 strcpy(links[1][33].resl,"./pdata/SC2_/S4_S3/S4_S3_4.txt");
 strcpy(links[1][34].resl,"./pdata/SC2_/S4_S3/S4_S3_5.txt");
 strcpy(links[1][35].resl,"./pdata/SC2_/S4_S3/S4_S3_6.txt");
 strcpy(links[1][36].resl,"./pdata/SC2_/S4_S3/S4_S3_7.txt");
 strcpy(links[1][37].resl,"./pdata/SC2_/S4_S3/S4_S3_8.txt");
 strcpy(links[1][38].resl,"./pdata/SC2_/S4_S3/S4_S3_9.txt");
 strcpy(links[1][39].resl,"./pdata/SC2_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[1][40].resl,"./pdata/SC2_/S5_S6/S5_S6_1.txt");
 strcpy(links[1][41].resl,"./pdata/SC2_/S5_S6/S5_S6_2.txt");
 strcpy(links[1][42].resl,"./pdata/SC2_/S5_S6/S5_S6_3.txt");
 strcpy(links[1][43].resl,"./pdata/SC2_/S5_S6/S5_S6_4.txt");
 strcpy(links[1][44].resl,"./pdata/SC2_/S5_S6/S5_S6_5.txt");
 strcpy(links[1][45].resl,"./pdata/SC2_/S5_S6/S5_S6_6.txt");
 strcpy(links[1][46].resl,"./pdata/SC2_/S5_S6/S5_S6_7.txt");
 strcpy(links[1][47].resl,"./pdata/SC2_/S5_S6/S5_S6_8.txt");
 strcpy(links[1][48].resl,"./pdata/SC2_/S5_S6/S5_S6_9.txt");
 strcpy(links[1][49].resl,"./pdata/SC2_/S5_S6/S5_S6_10.txt");
 strcpy(links[1][50].resl,"./pdata/SC2_/S6_S5/S6_S5_1.txt");
 strcpy(links[1][51].resl,"./pdata/SC2_/S6_S5/S6_S5_2.txt");
 strcpy(links[1][52].resl,"./pdata/SC2_/S6_S5/S6_S5_3.txt");
 strcpy(links[1][53].resl,"./pdata/SC2_/S6_S5/S6_S5_4.txt");
 strcpy(links[1][54].resl,"./pdata/SC2_/S6_S5/S6_S5_5.txt");
 strcpy(links[1][55].resl,"./pdata/SC2_/S6_S5/S6_S5_6.txt");
 strcpy(links[1][56].resl,"./pdata/SC2_/S6_S5/S6_S5_7.txt");
 strcpy(links[1][57].resl,"./pdata/SC2_/S6_S5/S6_S5_8.txt");
 strcpy(links[1][58].resl,"./pdata/SC2_/S6_S5/S6_S5_9.txt");
 strcpy(links[1][59].resl,"./pdata/SC2_/S6_S5/S6_S5_10.txt");
 strcpy(links[1][60].resl,"./pdata/SC2_/S7_S8/S7_S8_1.txt");
 strcpy(links[1][61].resl,"./pdata/SC2_/S7_S8/S7_S8_2.txt");
 strcpy(links[1][62].resl,"./pdata/SC2_/S7_S8/S7_S8_3.txt");
 strcpy(links[1][63].resl,"./pdata/SC2_/S7_S8/S7_S8_4.txt");
 strcpy(links[1][64].resl,"./pdata/SC2_/S7_S8/S7_S8_5.txt");
 strcpy(links[1][65].resl,"./pdata/SC2_/S7_S8/S7_S8_6.txt");
 strcpy(links[1][66].resl,"./pdata/SC2_/S7_S8/S7_S8_7.txt");
 strcpy(links[1][67].resl,"./pdata/SC2_/S7_S8/S7_S8_8.txt");
 strcpy(links[1][68].resl,"./pdata/SC2_/S7_S8/S7_S8_9.txt");
 strcpy(links[1][69].resl,"./pdata/SC2_/S7_S8/S7_S8_10.txt");
 strcpy(links[1][70].resl,"./pdata/SC2_/S8_S7/S8_S7_1.txt");
 strcpy(links[1][71].resl,"./pdata/SC2_/S8_S7/S8_S7_2.txt");
 strcpy(links[1][72].resl,"./pdata/SC2_/S8_S7/S8_S7_3.txt");
 strcpy(links[1][73].resl,"./pdata/SC2_/S8_S7/S8_S7_4.txt");
 strcpy(links[1][74].resl,"./pdata/SC2_/S8_S7/S8_S7_5.txt");
 strcpy(links[1][75].resl,"./pdata/SC2_/S8_S7/S8_S7_6.txt");
 strcpy(links[1][76].resl,"./pdata/SC2_/S8_S7/S8_S7_7.txt");
 strcpy(links[1][77].resl,"./pdata/SC2_/S8_S7/S8_S7_8.txt");
 strcpy(links[1][78].resl,"./pdata/SC2_/S8_S7/S8_S7_9.txt");
 strcpy(links[1][79].resl,"./pdata/SC2_/S8_S7/S8_S7_10.txt");
}


void res_links_3()                                                      //Storing output file links[2] for scenario 3
{
 strcpy(links[2][0].resl,"./pdata/SC3_/S1_S2/S1_S2_1.txt");
 strcpy(links[2][1].resl,"./pdata/SC3_/S1_S2/S1_S2_2.txt");
 strcpy(links[2][2].resl,"./pdata/SC3_/S1_S2/S1_S2_3.txt");
 strcpy(links[2][3].resl,"./pdata/SC3_/S1_S2/S1_S2_4.txt");
 strcpy(links[2][4].resl,"./pdata/SC3_/S1_S2/S1_S2_5.txt");
 strcpy(links[2][5].resl,"./pdata/SC3_/S1_S2/S1_S2_6.txt");
 strcpy(links[2][6].resl,"./pdata/SC3_/S1_S2/S1_S2_7.txt");
 strcpy(links[2][7].resl,"./pdata/SC3_/S1_S2/S1_S2_8.txt");
 strcpy(links[2][8].resl,"./pdata/SC3_/S1_S2/S1_S2_9.txt");
 strcpy(links[2][9].resl,"./pdata/SC3_/S1_S2/S1_S2_10.txt");
 strcpy(links[2][10].resl,"./pdata/SC3_/S2_S1/S2_S1_1.txt");
 strcpy(links[2][11].resl,"./pdata/SC3_/S2_S1/S2_S1_2.txt");
 strcpy(links[2][12].resl,"./pdata/SC3_/S2_S1/S2_S1_3.txt");
 strcpy(links[2][13].resl,"./pdata/SC3_/S2_S1/S2_S1_4.txt");
 strcpy(links[2][14].resl,"./pdata/SC3_/S2_S1/S2_S1_5.txt");
 strcpy(links[2][15].resl,"./pdata/SC3_/S2_S1/S2_S1_6.txt");
 strcpy(links[2][16].resl,"./pdata/SC3_/S2_S1/S2_S1_7.txt");
 strcpy(links[2][17].resl,"./pdata/SC3_/S2_S1/S2_S1_8.txt");
 strcpy(links[2][18].resl,"./pdata/SC3_/S2_S1/S2_S1_9.txt");
 strcpy(links[2][19].resl,"./pdata/SC3_/S2_S1/S2_S1_10.txt");
 strcpy(links[2][20].resl,"./pdata/SC3_/S3_S4/S3_S4_1.txt");
 strcpy(links[2][21].resl,"./pdata/SC3_/S3_S4/S3_S4_2.txt");
 strcpy(links[2][22].resl,"./pdata/SC3_/S3_S4/S3_S4_3.txt");
 strcpy(links[2][23].resl,"./pdata/SC3_/S3_S4/S3_S4_4.txt");
 strcpy(links[2][24].resl,"./pdata/SC3_/S3_S4/S3_S4_5.txt");
 strcpy(links[2][25].resl,"./pdata/SC3_/S3_S4/S3_S4_6.txt");
 strcpy(links[2][26].resl,"./pdata/SC3_/S3_S4/S3_S4_7.txt");
 strcpy(links[2][27].resl,"./pdata/SC3_/S3_S4/S3_S4_8.txt");
 strcpy(links[2][28].resl,"./pdata/SC3_/S3_S4/S3_S4_9.txt");
 strcpy(links[2][29].resl,"./pdata/SC3_/S3_S4/S3_S4_10.txt");
 strcpy(links[2][30].resl,"./pdata/SC3_/S4_S3/S4_S3_1.txt");
 strcpy(links[2][31].resl,"./pdata/SC3_/S4_S3/S4_S3_2.txt");
 strcpy(links[2][32].resl,"./pdata/SC3_/S4_S3/S4_S3_3.txt");
 strcpy(links[2][33].resl,"./pdata/SC3_/S4_S3/S4_S3_4.txt");
 strcpy(links[2][34].resl,"./pdata/SC3_/S4_S3/S4_S3_5.txt");
 strcpy(links[2][35].resl,"./pdata/SC3_/S4_S3/S4_S3_6.txt");
 strcpy(links[2][36].resl,"./pdata/SC3_/S4_S3/S4_S3_7.txt");
 strcpy(links[2][37].resl,"./pdata/SC3_/S4_S3/S4_S3_8.txt");
 strcpy(links[2][38].resl,"./pdata/SC3_/S4_S3/S4_S3_9.txt");
 strcpy(links[2][39].resl,"./pdata/SC3_/S4_S3/S4_S3_10.txt");
 
 
 
 
 strcpy(links[2][40].resl,"./pdata/SC3_/S5_S6/S5_S6_1.txt");
 strcpy(links[2][41].resl,"./pdata/SC3_/S5_S6/S5_S6_2.txt");
 strcpy(links[2][42].resl,"./pdata/SC3_/S5_S6/S5_S6_3.txt");
 strcpy(links[2][43].resl,"./pdata/SC3_/S5_S6/S5_S6_4.txt");
 strcpy(links[2][44].resl,"./pdata/SC3_/S5_S6/S5_S6_5.txt");
 strcpy(links[2][45].resl,"./pdata/SC3_/S5_S6/S5_S6_6.txt");
 strcpy(links[2][46].resl,"./pdata/SC3_/S5_S6/S5_S6_7.txt");
 strcpy(links[2][47].resl,"./pdata/SC3_/S5_S6/S5_S6_8.txt");
 strcpy(links[2][48].resl,"./pdata/SC3_/S5_S6/S5_S6_9.txt");
 strcpy(links[2][49].resl,"./pdata/SC3_/S5_S6/S5_S6_10.txt");
 strcpy(links[2][50].resl,"./pdata/SC3_/S6_S5/S6_S5_1.txt");
 strcpy(links[2][51].resl,"./pdata/SC3_/S6_S5/S6_S5_2.txt");
 strcpy(links[2][52].resl,"./pdata/SC3_/S6_S5/S6_S5_3.txt");
 strcpy(links[2][53].resl,"./pdata/SC3_/S6_S5/S6_S5_4.txt");
 strcpy(links[2][54].resl,"./pdata/SC3_/S6_S5/S6_S5_5.txt");
 strcpy(links[2][55].resl,"./pdata/SC3_/S6_S5/S6_S5_6.txt");
 strcpy(links[2][56].resl,"./pdata/SC3_/S6_S5/S6_S5_7.txt");
 strcpy(links[2][57].resl,"./pdata/SC3_/S6_S5/S6_S5_8.txt");
 strcpy(links[2][58].resl,"./pdata/SC3_/S6_S5/S6_S5_9.txt");
 strcpy(links[2][59].resl,"./pdata/SC3_/S6_S5/S6_S5_10.txt");
 strcpy(links[2][60].resl,"./pdata/SC3_/S7_S8/S7_S8_1.txt");
 strcpy(links[2][61].resl,"./pdata/SC3_/S7_S8/S7_S8_2.txt");
 strcpy(links[2][62].resl,"./pdata/SC3_/S7_S8/S7_S8_3.txt");
 strcpy(links[2][63].resl,"./pdata/SC3_/S7_S8/S7_S8_4.txt");
 strcpy(links[2][64].resl,"./pdata/SC3_/S7_S8/S7_S8_5.txt");
 strcpy(links[2][65].resl,"./pdata/SC3_/S7_S8/S7_S8_6.txt");
 strcpy(links[2][66].resl,"./pdata/SC3_/S7_S8/S7_S8_7.txt");
 strcpy(links[2][67].resl,"./pdata/SC3_/S7_S8/S7_S8_8.txt");
 strcpy(links[2][68].resl,"./pdata/SC3_/S7_S8/S7_S8_9.txt");
 strcpy(links[2][69].resl,"./pdata/SC3_/S7_S8/S7_S8_10.txt");
 strcpy(links[2][70].resl,"./pdata/SC3_/S8_S7/S8_S7_1.txt");
 strcpy(links[2][71].resl,"./pdata/SC3_/S8_S7/S8_S7_2.txt");
 strcpy(links[2][72].resl,"./pdata/SC3_/S8_S7/S8_S7_3.txt");
 strcpy(links[2][73].resl,"./pdata/SC3_/S8_S7/S8_S7_4.txt");
 strcpy(links[2][74].resl,"./pdata/SC3_/S8_S7/S8_S7_5.txt");
 strcpy(links[2][75].resl,"./pdata/SC3_/S8_S7/S8_S7_6.txt");
 strcpy(links[2][76].resl,"./pdata/SC3_/S8_S7/S8_S7_7.txt");
 strcpy(links[2][77].resl,"./pdata/SC3_/S8_S7/S8_S7_8.txt");
 strcpy(links[2][78].resl,"./pdata/SC3_/S8_S7/S8_S7_9.txt");
 strcpy(links[2][79].resl,"./pdata/SC3_/S8_S7/S8_S7_10.txt");
}




void res_links_4()                                               //Storing output file links[3][3] for scenario 4
{
 strcpy(links[3][0].resl,"./pdata/SC4_/S1_S2/S1_S2_1.txt");
 strcpy(links[3][1].resl,"./pdata/SC4_/S1_S2/S1_S2_2.txt");
 strcpy(links[3][2].resl,"./pdata/SC4_/S1_S2/S1_S2_3.txt");
 strcpy(links[3][3].resl,"./pdata/SC4_/S1_S2/S1_S2_4.txt");
 strcpy(links[3][4].resl,"./pdata/SC4_/S1_S2/S1_S2_5.txt");
 strcpy(links[3][5].resl,"./pdata/SC4_/S1_S2/S1_S2_6.txt");
 strcpy(links[3][6].resl,"./pdata/SC4_/S1_S2/S1_S2_7.txt");
 strcpy(links[3][7].resl,"./pdata/SC4_/S1_S2/S1_S2_8.txt");
 strcpy(links[3][8].resl,"./pdata/SC4_/S1_S2/S1_S2_9.txt");
 strcpy(links[3][9].resl,"./pdata/SC4_/S1_S2/S1_S2_10.txt");
 strcpy(links[3][10].resl,"./pdata/SC4_/S2_S1/S2_S1_1.txt");
 strcpy(links[3][11].resl,"./pdata/SC4_/S2_S1/S2_S1_2.txt");
 strcpy(links[3][12].resl,"./pdata/SC4_/S2_S1/S2_S1_3.txt");
 strcpy(links[3][13].resl,"./pdata/SC4_/S2_S1/S2_S1_4.txt");
 strcpy(links[3][14].resl,"./pdata/SC4_/S2_S1/S2_S1_5.txt");
 strcpy(links[3][15].resl,"./pdata/SC4_/S2_S1/S2_S1_6.txt");
 strcpy(links[3][16].resl,"./pdata/SC4_/S2_S1/S2_S1_7.txt");
 strcpy(links[3][17].resl,"./pdata/SC4_/S2_S1/S2_S1_8.txt");
 strcpy(links[3][18].resl,"./pdata/SC4_/S2_S1/S2_S1_9.txt");
 strcpy(links[3][19].resl,"./pdata/SC4_/S2_S1/S2_S1_10.txt");
 strcpy(links[3][20].resl,"./pdata/SC4_/S3_S4/S3_S4_1.txt");
 strcpy(links[3][21].resl,"./pdata/SC4_/S3_S4/S3_S4_2.txt");
 strcpy(links[3][22].resl,"./pdata/SC4_/S3_S4/S3_S4_3.txt");
 strcpy(links[3][23].resl,"./pdata/SC4_/S3_S4/S3_S4_4.txt");
 strcpy(links[3][24].resl,"./pdata/SC4_/S3_S4/S3_S4_5.txt");
 strcpy(links[3][25].resl,"./pdata/SC4_/S3_S4/S3_S4_6.txt");
 strcpy(links[3][26].resl,"./pdata/SC4_/S3_S4/S3_S4_7.txt");
 strcpy(links[3][27].resl,"./pdata/SC4_/S3_S4/S3_S4_8.txt");
 strcpy(links[3][28].resl,"./pdata/SC4_/S3_S4/S3_S4_9.txt");
 strcpy(links[3][29].resl,"./pdata/SC4_/S3_S4/S3_S4_10.txt");
 strcpy(links[3][30].resl,"./pdata/SC4_/S4_S3/S4_S3_1.txt");
 strcpy(links[3][31].resl,"./pdata/SC4_/S4_S3/S4_S3_2.txt");
 strcpy(links[3][32].resl,"./pdata/SC4_/S4_S3/S4_S3_3.txt");
 strcpy(links[3][33].resl,"./pdata/SC4_/S4_S3/S4_S3_4.txt");
 strcpy(links[3][34].resl,"./pdata/SC4_/S4_S3/S4_S3_5.txt");
 strcpy(links[3][35].resl,"./pdata/SC4_/S4_S3/S4_S3_6.txt");
 strcpy(links[3][36].resl,"./pdata/SC4_/S4_S3/S4_S3_7.txt");
 strcpy(links[3][37].resl,"./pdata/SC4_/S4_S3/S4_S3_8.txt");
 strcpy(links[3][38].resl,"./pdata/SC4_/S4_S3/S4_S3_9.txt");
 strcpy(links[3][39].resl,"./pdata/SC4_/S4_S3/S4_S3_10.txt");
 
 
 
 
 
 strcpy(links[3][40].resl,"./pdata/SC4_/S5_S6/S5_S6_1.txt");
 strcpy(links[3][41].resl,"./pdata/SC4_/S5_S6/S5_S6_2.txt");
 strcpy(links[3][42].resl,"./pdata/SC4_/S5_S6/S5_S6_3.txt");
 strcpy(links[3][43].resl,"./pdata/SC4_/S5_S6/S5_S6_4.txt");
 strcpy(links[3][44].resl,"./pdata/SC4_/S5_S6/S5_S6_5.txt");
 strcpy(links[3][45].resl,"./pdata/SC4_/S5_S6/S5_S6_6.txt");
 strcpy(links[3][46].resl,"./pdata/SC4_/S5_S6/S5_S6_7.txt");
 strcpy(links[3][47].resl,"./pdata/SC4_/S5_S6/S5_S6_8.txt");
 strcpy(links[3][48].resl,"./pdata/SC4_/S5_S6/S5_S6_9.txt");
 strcpy(links[3][49].resl,"./pdata/SC4_/S5_S6/S5_S6_10.txt");
 strcpy(links[3][50].resl,"./pdata/SC4_/S6_S5/S6_S5_1.txt");
 strcpy(links[3][51].resl,"./pdata/SC4_/S6_S5/S6_S5_2.txt");
 strcpy(links[3][52].resl,"./pdata/SC4_/S6_S5/S6_S5_3.txt");
 strcpy(links[3][53].resl,"./pdata/SC4_/S6_S5/S6_S5_4.txt");
 strcpy(links[3][54].resl,"./pdata/SC4_/S6_S5/S6_S5_5.txt");
 strcpy(links[3][55].resl,"./pdata/SC4_/S6_S5/S6_S5_6.txt");
 strcpy(links[3][56].resl,"./pdata/SC4_/S6_S5/S6_S5_7.txt");
 strcpy(links[3][57].resl,"./pdata/SC4_/S6_S5/S6_S5_8.txt");
 strcpy(links[3][58].resl,"./pdata/SC4_/S6_S5/S6_S5_9.txt");
 strcpy(links[3][59].resl,"./pdata/SC4_/S6_S5/S6_S5_10.txt");
 strcpy(links[3][60].resl,"./pdata/SC4_/S7_S8/S7_S8_1.txt");
 strcpy(links[3][61].resl,"./pdata/SC4_/S7_S8/S7_S8_2.txt");
 strcpy(links[3][62].resl,"./pdata/SC4_/S7_S8/S7_S8_3.txt");
 strcpy(links[3][63].resl,"./pdata/SC4_/S7_S8/S7_S8_4.txt");
 strcpy(links[3][64].resl,"./pdata/SC4_/S7_S8/S7_S8_5.txt");
 strcpy(links[3][65].resl,"./pdata/SC4_/S7_S8/S7_S8_6.txt");
 strcpy(links[3][66].resl,"./pdata/SC4_/S7_S8/S7_S8_7.txt");
 strcpy(links[3][67].resl,"./pdata/SC4_/S7_S8/S7_S8_8.txt");
 strcpy(links[3][68].resl,"./pdata/SC4_/S7_S8/S7_S8_9.txt");
 strcpy(links[3][69].resl,"./pdata/SC4_/S7_S8/S7_S8_10.txt");
 strcpy(links[3][70].resl,"./pdata/SC4_/S8_S7/S8_S7_1.txt");
 strcpy(links[3][71].resl,"./pdata/SC4_/S8_S7/S8_S7_2.txt");
 strcpy(links[3][72].resl,"./pdata/SC4_/S8_S7/S8_S7_3.txt");
 strcpy(links[3][73].resl,"./pdata/SC4_/S8_S7/S8_S7_4.txt");
 strcpy(links[3][74].resl,"./pdata/SC4_/S8_S7/S8_S7_5.txt");
 strcpy(links[3][75].resl,"./pdata/SC4_/S8_S7/S8_S7_6.txt");
 strcpy(links[3][76].resl,"./pdata/SC4_/S8_S7/S8_S7_7.txt");
 strcpy(links[3][77].resl,"./pdata/SC4_/S8_S7/S8_S7_8.txt");
 strcpy(links[3][78].resl,"./pdata/SC4_/S8_S7/S8_S7_9.txt");
 strcpy(links[3][79].resl,"./pdata/SC4_/S8_S7/S8_S7_10.txt");
}





void res_links_5()                                                 //Storing output file links[4] for scenario 5
{
 strcpy(links[4][0].resl,"./pdata/SC5_/S1_S2/S1_S2_1.txt");
 strcpy(links[4][1].resl,"./pdata/SC5_/S1_S2/S1_S2_2.txt");
 strcpy(links[4][2].resl,"./pdata/SC5_/S1_S2/S1_S2_3.txt");
 strcpy(links[4][3].resl,"./pdata/SC5_/S1_S2/S1_S2_4.txt");
 strcpy(links[4][4].resl,"./pdata/SC5_/S1_S2/S1_S2_5.txt");
 strcpy(links[4][5].resl,"./pdata/SC5_/S1_S2/S1_S2_6.txt");
 strcpy(links[4][6].resl,"./pdata/SC5_/S1_S2/S1_S2_7.txt");
 strcpy(links[4][7].resl,"./pdata/SC5_/S1_S2/S1_S2_8.txt");
 strcpy(links[4][8].resl,"./pdata/SC5_/S1_S2/S1_S2_9.txt");
 strcpy(links[4][9].resl,"./pdata/SC5_/S1_S2/S1_S2_10.txt");
 strcpy(links[4][10].resl,"./pdata/SC5_/S2_S1/S2_S1_1.txt");
 strcpy(links[4][11].resl,"./pdata/SC5_/S2_S1/S2_S1_2.txt");
 strcpy(links[4][12].resl,"./pdata/SC5_/S2_S1/S2_S1_3.txt");
 strcpy(links[4][13].resl,"./pdata/SC5_/S2_S1/S2_S1_4.txt");
 strcpy(links[4][14].resl,"./pdata/SC5_/S2_S1/S2_S1_5.txt");
 strcpy(links[4][15].resl,"./pdata/SC5_/S2_S1/S2_S1_6.txt");
 strcpy(links[4][16].resl,"./pdata/SC5_/S2_S1/S2_S1_7.txt");
 strcpy(links[4][17].resl,"./pdata/SC5_/S2_S1/S2_S1_8.txt");
 strcpy(links[4][18].resl,"./pdata/SC5_/S2_S1/S2_S1_9.txt");
 strcpy(links[4][19].resl,"./pdata/SC5_/S2_S1/S2_S1_10.txt");
 strcpy(links[4][20].resl,"./pdata/SC5_/S3_S4/S3_S4_1.txt");
 strcpy(links[4][21].resl,"./pdata/SC5_/S3_S4/S3_S4_2.txt");
 strcpy(links[4][22].resl,"./pdata/SC5_/S3_S4/S3_S4_3.txt");
 strcpy(links[4][23].resl,"./pdata/SC5_/S3_S4/S3_S4_4.txt");
 strcpy(links[4][24].resl,"./pdata/SC5_/S3_S4/S3_S4_5.txt");
 strcpy(links[4][25].resl,"./pdata/SC5_/S3_S4/S3_S4_6.txt");
 strcpy(links[4][26].resl,"./pdata/SC5_/S3_S4/S3_S4_7.txt");
 strcpy(links[4][27].resl,"./pdata/SC5_/S3_S4/S3_S4_8.txt");
 strcpy(links[4][28].resl,"./pdata/SC5_/S3_S4/S3_S4_9.txt");
 strcpy(links[4][29].resl,"./pdata/SC5_/S3_S4/S3_S4_10.txt");
 strcpy(links[4][30].resl,"./pdata/SC5_/S4_S3/S4_S3_1.txt");
 strcpy(links[4][31].resl,"./pdata/SC5_/S4_S3/S4_S3_2.txt");
 strcpy(links[4][32].resl,"./pdata/SC5_/S4_S3/S4_S3_3.txt");
 strcpy(links[4][33].resl,"./pdata/SC5_/S4_S3/S4_S3_4.txt");
 strcpy(links[4][34].resl,"./pdata/SC5_/S4_S3/S4_S3_5.txt");
 strcpy(links[4][35].resl,"./pdata/SC5_/S4_S3/S4_S3_6.txt");
 strcpy(links[4][36].resl,"./pdata/SC5_/S4_S3/S4_S3_7.txt");
 strcpy(links[4][37].resl,"./pdata/SC5_/S4_S3/S4_S3_8.txt");
 strcpy(links[4][38].resl,"./pdata/SC5_/S4_S3/S4_S3_9.txt");
 strcpy(links[4][39].resl,"./pdata/SC5_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[4][40].resl,"./pdata/SC5_/S5_S6/S5_S6_1.txt");
 strcpy(links[4][41].resl,"./pdata/SC5_/S5_S6/S5_S6_2.txt");
 strcpy(links[4][42].resl,"./pdata/SC5_/S5_S6/S5_S6_3.txt");
 strcpy(links[4][43].resl,"./pdata/SC5_/S5_S6/S5_S6_4.txt");
 strcpy(links[4][44].resl,"./pdata/SC5_/S5_S6/S5_S6_5.txt");
 strcpy(links[4][45].resl,"./pdata/SC5_/S5_S6/S5_S6_6.txt");
 strcpy(links[4][46].resl,"./pdata/SC5_/S5_S6/S5_S6_7.txt");
 strcpy(links[4][47].resl,"./pdata/SC5_/S5_S6/S5_S6_8.txt");
 strcpy(links[4][48].resl,"./pdata/SC5_/S5_S6/S5_S6_9.txt");
 strcpy(links[4][49].resl,"./pdata/SC5_/S5_S6/S5_S6_10.txt");
 strcpy(links[4][50].resl,"./pdata/SC5_/S6_S5/S6_S5_1.txt");
 strcpy(links[4][51].resl,"./pdata/SC5_/S6_S5/S6_S5_2.txt");
 strcpy(links[4][52].resl,"./pdata/SC5_/S6_S5/S6_S5_3.txt");
 strcpy(links[4][53].resl,"./pdata/SC5_/S6_S5/S6_S5_4.txt");
 strcpy(links[4][54].resl,"./pdata/SC5_/S6_S5/S6_S5_5.txt");
 strcpy(links[4][55].resl,"./pdata/SC5_/S6_S5/S6_S5_6.txt");
 strcpy(links[4][56].resl,"./pdata/SC5_/S6_S5/S6_S5_7.txt");
 strcpy(links[4][57].resl,"./pdata/SC5_/S6_S5/S6_S5_8.txt");
 strcpy(links[4][58].resl,"./pdata/SC5_/S6_S5/S6_S5_9.txt");
 strcpy(links[4][59].resl,"./pdata/SC5_/S6_S5/S6_S5_10.txt");
 strcpy(links[4][60].resl,"./pdata/SC5_/S7_S8/S7_S8_1.txt");
 strcpy(links[4][61].resl,"./pdata/SC5_/S7_S8/S7_S8_2.txt");
 strcpy(links[4][62].resl,"./pdata/SC5_/S7_S8/S7_S8_3.txt");
 strcpy(links[4][63].resl,"./pdata/SC5_/S7_S8/S7_S8_4.txt");
 strcpy(links[4][64].resl,"./pdata/SC5_/S7_S8/S7_S8_5.txt");
 strcpy(links[4][65].resl,"./pdata/SC5_/S7_S8/S7_S8_6.txt");
 strcpy(links[4][66].resl,"./pdata/SC5_/S7_S8/S7_S8_7.txt");
 strcpy(links[4][67].resl,"./pdata/SC5_/S7_S8/S7_S8_8.txt");
 strcpy(links[4][68].resl,"./pdata/SC5_/S7_S8/S7_S8_9.txt");
 strcpy(links[4][69].resl,"./pdata/SC5_/S7_S8/S7_S8_10.txt");
 strcpy(links[4][70].resl,"./pdata/SC5_/S8_S7/S8_S7_1.txt");
 strcpy(links[4][71].resl,"./pdata/SC5_/S8_S7/S8_S7_2.txt");
 strcpy(links[4][72].resl,"./pdata/SC5_/S8_S7/S8_S7_3.txt");
 strcpy(links[4][73].resl,"./pdata/SC5_/S8_S7/S8_S7_4.txt");
 strcpy(links[4][74].resl,"./pdata/SC5_/S8_S7/S8_S7_5.txt");
 strcpy(links[4][75].resl,"./pdata/SC5_/S8_S7/S8_S7_6.txt");
 strcpy(links[4][76].resl,"./pdata/SC5_/S8_S7/S8_S7_7.txt");
 strcpy(links[4][77].resl,"./pdata/SC5_/S8_S7/S8_S7_8.txt");
 strcpy(links[4][78].resl,"./pdata/SC5_/S8_S7/S8_S7_9.txt");
 strcpy(links[4][79].resl,"./pdata/SC5_/S8_S7/S8_S7_10.txt");
}




void res_links_6()                                                    //Storing output file links[5] for scenario 6
{
 strcpy(links[5][0].resl,"./pdata/SC6_/S1_S2/S1_S2_1.txt");
 strcpy(links[5][1].resl,"./pdata/SC6_/S1_S2/S1_S2_2.txt");
 strcpy(links[5][2].resl,"./pdata/SC6_/S1_S2/S1_S2_3.txt");
 strcpy(links[5][3].resl,"./pdata/SC6_/S1_S2/S1_S2_4.txt");
 strcpy(links[5][4].resl,"./pdata/SC6_/S1_S2/S1_S2_5.txt");
 strcpy(links[5][5].resl,"./pdata/SC6_/S1_S2/S1_S2_6.txt");
 strcpy(links[5][6].resl,"./pdata/SC6_/S1_S2/S1_S2_7.txt");
 strcpy(links[5][7].resl,"./pdata/SC6_/S1_S2/S1_S2_8.txt");
 strcpy(links[5][8].resl,"./pdata/SC6_/S1_S2/S1_S2_9.txt");
 strcpy(links[5][9].resl,"./pdata/SC6_/S1_S2/S1_S2_10.txt");
 strcpy(links[5][10].resl,"./pdata/SC6_/S2_S1/S2_S1_1.txt");
 strcpy(links[5][11].resl,"./pdata/SC6_/S2_S1/S2_S1_2.txt");
 strcpy(links[5][12].resl,"./pdata/SC6_/S2_S1/S2_S1_3.txt");
 strcpy(links[5][13].resl,"./pdata/SC6_/S2_S1/S2_S1_4.txt");
 strcpy(links[5][14].resl,"./pdata/SC6_/S2_S1/S2_S1_5.txt");
 strcpy(links[5][15].resl,"./pdata/SC6_/S2_S1/S2_S1_6.txt");
 strcpy(links[5][16].resl,"./pdata/SC6_/S2_S1/S2_S1_7.txt");
 strcpy(links[5][17].resl,"./pdata/SC6_/S2_S1/S2_S1_8.txt");
 strcpy(links[5][18].resl,"./pdata/SC6_/S2_S1/S2_S1_9.txt");
 strcpy(links[5][19].resl,"./pdata/SC6_/S2_S1/S2_S1_10.txt");
 strcpy(links[5][20].resl,"./pdata/SC6_/S3_S4/S3_S4_1.txt");
 strcpy(links[5][21].resl,"./pdata/SC6_/S3_S4/S3_S4_2.txt");
 strcpy(links[5][22].resl,"./pdata/SC6_/S3_S4/S3_S4_3.txt");
 strcpy(links[5][23].resl,"./pdata/SC6_/S3_S4/S3_S4_4.txt");
 strcpy(links[5][24].resl,"./pdata/SC6_/S3_S4/S3_S4_5.txt");
 strcpy(links[5][25].resl,"./pdata/SC6_/S3_S4/S3_S4_6.txt");
 strcpy(links[5][26].resl,"./pdata/SC6_/S3_S4/S3_S4_7.txt");
 strcpy(links[5][27].resl,"./pdata/SC6_/S3_S4/S3_S4_8.txt");
 strcpy(links[5][28].resl,"./pdata/SC6_/S3_S4/S3_S4_9.txt");
 strcpy(links[5][29].resl,"./pdata/SC6_/S3_S4/S3_S4_10.txt");
 strcpy(links[5][30].resl,"./pdata/SC6_/S4_S3/S4_S3_1.txt");
 strcpy(links[5][31].resl,"./pdata/SC6_/S4_S3/S4_S3_2.txt");
 strcpy(links[5][32].resl,"./pdata/SC6_/S4_S3/S4_S3_3.txt");
 strcpy(links[5][33].resl,"./pdata/SC6_/S4_S3/S4_S3_4.txt");
 strcpy(links[5][34].resl,"./pdata/SC6_/S4_S3/S4_S3_5.txt");
 strcpy(links[5][35].resl,"./pdata/SC6_/S4_S3/S4_S3_6.txt");
 strcpy(links[5][36].resl,"./pdata/SC6_/S4_S3/S4_S3_7.txt");
 strcpy(links[5][37].resl,"./pdata/SC6_/S4_S3/S4_S3_8.txt");
 strcpy(links[5][38].resl,"./pdata/SC6_/S4_S3/S4_S3_9.txt");
 strcpy(links[5][39].resl,"./pdata/SC6_/S4_S3/S4_S3_10.txt");
 
 
 
 
 
 strcpy(links[5][40].resl,"./pdata/SC6_/S5_S6/S5_S6_1.txt");
 strcpy(links[5][41].resl,"./pdata/SC6_/S5_S6/S5_S6_2.txt");
 strcpy(links[5][42].resl,"./pdata/SC6_/S5_S6/S5_S6_3.txt");
 strcpy(links[5][43].resl,"./pdata/SC6_/S5_S6/S5_S6_4.txt");
 strcpy(links[5][44].resl,"./pdata/SC6_/S5_S6/S5_S6_5.txt");
 strcpy(links[5][45].resl,"./pdata/SC6_/S5_S6/S5_S6_6.txt");
 strcpy(links[5][46].resl,"./pdata/SC6_/S5_S6/S5_S6_7.txt");
 strcpy(links[5][47].resl,"./pdata/SC6_/S5_S6/S5_S6_8.txt");
 strcpy(links[5][48].resl,"./pdata/SC6_/S5_S6/S5_S6_9.txt");
 strcpy(links[5][49].resl,"./pdata/SC6_/S5_S6/S5_S6_10.txt");
 strcpy(links[5][50].resl,"./pdata/SC6_/S6_S5/S6_S5_1.txt");
 strcpy(links[5][51].resl,"./pdata/SC6_/S6_S5/S6_S5_2.txt");
 strcpy(links[5][52].resl,"./pdata/SC6_/S6_S5/S6_S5_3.txt");
 strcpy(links[5][53].resl,"./pdata/SC6_/S6_S5/S6_S5_4.txt");
 strcpy(links[5][54].resl,"./pdata/SC6_/S6_S5/S6_S5_5.txt");
 strcpy(links[5][55].resl,"./pdata/SC6_/S6_S5/S6_S5_6.txt");
 strcpy(links[5][56].resl,"./pdata/SC6_/S6_S5/S6_S5_7.txt");
 strcpy(links[5][57].resl,"./pdata/SC6_/S6_S5/S6_S5_8.txt");
 strcpy(links[5][58].resl,"./pdata/SC6_/S6_S5/S6_S5_9.txt");
 strcpy(links[5][59].resl,"./pdata/SC6_/S6_S5/S6_S5_10.txt");
 strcpy(links[5][60].resl,"./pdata/SC6_/S7_S8/S7_S8_1.txt");
 strcpy(links[5][61].resl,"./pdata/SC6_/S7_S8/S7_S8_2.txt");
 strcpy(links[5][62].resl,"./pdata/SC6_/S7_S8/S7_S8_3.txt");
 strcpy(links[5][63].resl,"./pdata/SC6_/S7_S8/S7_S8_4.txt");
 strcpy(links[5][64].resl,"./pdata/SC6_/S7_S8/S7_S8_5.txt");
 strcpy(links[5][65].resl,"./pdata/SC6_/S7_S8/S7_S8_6.txt");
 strcpy(links[5][66].resl,"./pdata/SC6_/S7_S8/S7_S8_7.txt");
 strcpy(links[5][67].resl,"./pdata/SC6_/S7_S8/S7_S8_8.txt");
 strcpy(links[5][68].resl,"./pdata/SC6_/S7_S8/S7_S8_9.txt");
 strcpy(links[5][69].resl,"./pdata/SC6_/S7_S8/S7_S8_10.txt");
 strcpy(links[5][70].resl,"./pdata/SC6_/S8_S7/S8_S7_1.txt");
 strcpy(links[5][71].resl,"./pdata/SC6_/S8_S7/S8_S7_2.txt");
 strcpy(links[5][72].resl,"./pdata/SC6_/S8_S7/S8_S7_3.txt");
 strcpy(links[5][73].resl,"./pdata/SC6_/S8_S7/S8_S7_4.txt");
 strcpy(links[5][74].resl,"./pdata/SC6_/S8_S7/S8_S7_5.txt");
 strcpy(links[5][75].resl,"./pdata/SC6_/S8_S7/S8_S7_6.txt");
 strcpy(links[5][76].resl,"./pdata/SC6_/S8_S7/S8_S7_7.txt");
 strcpy(links[5][77].resl,"./pdata/SC6_/S8_S7/S8_S7_8.txt");
 strcpy(links[5][78].resl,"./pdata/SC6_/S8_S7/S8_S7_9.txt");
 strcpy(links[5][79].resl,"./pdata/SC6_/S8_S7/S8_S7_10.txt");
}



void res_links_7()                                                      //Storing output file links[6] for scenario 7
{
 strcpy(links[6][0].resl,"./pdata/SC7_/S1_S2/S1_S2_1.txt");
 strcpy(links[6][1].resl,"./pdata/SC7_/S1_S2/S1_S2_2.txt");
 strcpy(links[6][2].resl,"./pdata/SC7_/S1_S2/S1_S2_3.txt");
 strcpy(links[6][3].resl,"./pdata/SC7_/S1_S2/S1_S2_4.txt");
 strcpy(links[6][4].resl,"./pdata/SC7_/S1_S2/S1_S2_5.txt");
 strcpy(links[6][5].resl,"./pdata/SC7_/S1_S2/S1_S2_6.txt");
 strcpy(links[6][6].resl,"./pdata/SC7_/S1_S2/S1_S2_7.txt");
 strcpy(links[6][7].resl,"./pdata/SC7_/S1_S2/S1_S2_8.txt");
 strcpy(links[6][8].resl,"./pdata/SC7_/S1_S2/S1_S2_9.txt");
 strcpy(links[6][9].resl,"./pdata/SC7_/S1_S2/S1_S2_10.txt");
 strcpy(links[6][10].resl,"./pdata/SC7_/S2_S1/S2_S1_1.txt");
 strcpy(links[6][11].resl,"./pdata/SC7_/S2_S1/S2_S1_2.txt");
 strcpy(links[6][12].resl,"./pdata/SC7_/S2_S1/S2_S1_3.txt");
 strcpy(links[6][13].resl,"./pdata/SC7_/S2_S1/S2_S1_4.txt");
 strcpy(links[6][14].resl,"./pdata/SC7_/S2_S1/S2_S1_5.txt");
 strcpy(links[6][15].resl,"./pdata/SC7_/S2_S1/S2_S1_6.txt");
 strcpy(links[6][16].resl,"./pdata/SC7_/S2_S1/S2_S1_7.txt");
 strcpy(links[6][17].resl,"./pdata/SC7_/S2_S1/S2_S1_8.txt");
 strcpy(links[6][18].resl,"./pdata/SC7_/S2_S1/S2_S1_9.txt");
 strcpy(links[6][19].resl,"./pdata/SC7_/S2_S1/S2_S1_10.txt");
 strcpy(links[6][20].resl,"./pdata/SC7_/S3_S4/S3_S4_1.txt");
 strcpy(links[6][21].resl,"./pdata/SC7_/S3_S4/S3_S4_2.txt");
 strcpy(links[6][22].resl,"./pdata/SC7_/S3_S4/S3_S4_3.txt");
 strcpy(links[6][23].resl,"./pdata/SC7_/S3_S4/S3_S4_4.txt");
 strcpy(links[6][24].resl,"./pdata/SC7_/S3_S4/S3_S4_5.txt");
 strcpy(links[6][25].resl,"./pdata/SC7_/S3_S4/S3_S4_6.txt");
 strcpy(links[6][26].resl,"./pdata/SC7_/S3_S4/S3_S4_7.txt");
 strcpy(links[6][27].resl,"./pdata/SC7_/S3_S4/S3_S4_8.txt");
 strcpy(links[6][28].resl,"./pdata/SC7_/S3_S4/S3_S4_9.txt");
 strcpy(links[6][29].resl,"./pdata/SC7_/S3_S4/S3_S4_10.txt");
 strcpy(links[6][30].resl,"./pdata/SC7_/S4_S3/S4_S3_1.txt");
 strcpy(links[6][31].resl,"./pdata/SC7_/S4_S3/S4_S3_2.txt");
 strcpy(links[6][32].resl,"./pdata/SC7_/S4_S3/S4_S3_3.txt");
 strcpy(links[6][33].resl,"./pdata/SC7_/S4_S3/S4_S3_4.txt");
 strcpy(links[6][34].resl,"./pdata/SC7_/S4_S3/S4_S3_5.txt");
 strcpy(links[6][35].resl,"./pdata/SC7_/S4_S3/S4_S3_6.txt");
 strcpy(links[6][36].resl,"./pdata/SC7_/S4_S3/S4_S3_7.txt");
 strcpy(links[6][37].resl,"./pdata/SC7_/S4_S3/S4_S3_8.txt");
 strcpy(links[6][38].resl,"./pdata/SC7_/S4_S3/S4_S3_9.txt");
 strcpy(links[6][39].resl,"./pdata/SC7_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[6][40].resl,"./pdata/SC7_/S5_S6/S5_S6_1.txt");
 strcpy(links[6][41].resl,"./pdata/SC7_/S5_S6/S5_S6_2.txt");
 strcpy(links[6][42].resl,"./pdata/SC7_/S5_S6/S5_S6_3.txt");
 strcpy(links[6][43].resl,"./pdata/SC7_/S5_S6/S5_S6_4.txt");
 strcpy(links[6][44].resl,"./pdata/SC7_/S5_S6/S5_S6_5.txt");
 strcpy(links[6][45].resl,"./pdata/SC7_/S5_S6/S5_S6_6.txt");
 strcpy(links[6][46].resl,"./pdata/SC7_/S5_S6/S5_S6_7.txt");
 strcpy(links[6][47].resl,"./pdata/SC7_/S5_S6/S5_S6_8.txt");
 strcpy(links[6][48].resl,"./pdata/SC7_/S5_S6/S5_S6_9.txt");
 strcpy(links[6][49].resl,"./pdata/SC7_/S5_S6/S5_S6_10.txt");
 strcpy(links[6][50].resl,"./pdata/SC7_/S6_S5/S6_S5_1.txt");
 strcpy(links[6][51].resl,"./pdata/SC7_/S6_S5/S6_S5_2.txt");
 strcpy(links[6][52].resl,"./pdata/SC7_/S6_S5/S6_S5_3.txt");
 strcpy(links[6][53].resl,"./pdata/SC7_/S6_S5/S6_S5_4.txt");
 strcpy(links[6][54].resl,"./pdata/SC7_/S6_S5/S6_S5_5.txt");
 strcpy(links[6][55].resl,"./pdata/SC7_/S6_S5/S6_S5_6.txt");
 strcpy(links[6][56].resl,"./pdata/SC7_/S6_S5/S6_S5_7.txt");
 strcpy(links[6][57].resl,"./pdata/SC7_/S6_S5/S6_S5_8.txt");
 strcpy(links[6][58].resl,"./pdata/SC7_/S6_S5/S6_S5_9.txt");
 strcpy(links[6][59].resl,"./pdata/SC7_/S6_S5/S6_S5_10.txt");
 strcpy(links[6][60].resl,"./pdata/SC7_/S7_S8/S7_S8_1.txt");
 strcpy(links[6][61].resl,"./pdata/SC7_/S7_S8/S7_S8_2.txt");
 strcpy(links[6][62].resl,"./pdata/SC7_/S7_S8/S7_S8_3.txt");
 strcpy(links[6][63].resl,"./pdata/SC7_/S7_S8/S7_S8_4.txt");
 strcpy(links[6][64].resl,"./pdata/SC7_/S7_S8/S7_S8_5.txt");
 strcpy(links[6][65].resl,"./pdata/SC7_/S7_S8/S7_S8_6.txt");
 strcpy(links[6][66].resl,"./pdata/SC7_/S7_S8/S7_S8_7.txt");
 strcpy(links[6][67].resl,"./pdata/SC7_/S7_S8/S7_S8_8.txt");
 strcpy(links[6][68].resl,"./pdata/SC7_/S7_S8/S7_S8_9.txt");
 strcpy(links[6][69].resl,"./pdata/SC7_/S7_S8/S7_S8_10.txt");
 strcpy(links[6][70].resl,"./pdata/SC7_/S8_S7/S8_S7_1.txt");
 strcpy(links[6][71].resl,"./pdata/SC7_/S8_S7/S8_S7_2.txt");
 strcpy(links[6][72].resl,"./pdata/SC7_/S8_S7/S8_S7_3.txt");
 strcpy(links[6][73].resl,"./pdata/SC7_/S8_S7/S8_S7_4.txt");
 strcpy(links[6][74].resl,"./pdata/SC7_/S8_S7/S8_S7_5.txt");
 strcpy(links[6][75].resl,"./pdata/SC7_/S8_S7/S8_S7_6.txt");
 strcpy(links[6][76].resl,"./pdata/SC7_/S8_S7/S8_S7_7.txt");
 strcpy(links[6][77].resl,"./pdata/SC7_/S8_S7/S8_S7_8.txt");
 strcpy(links[6][78].resl,"./pdata/SC7_/S8_S7/S8_S7_9.txt");
 strcpy(links[6][79].resl,"./pdata/SC7_/S8_S7/S8_S7_10.txt");
}


void src_des(int sc, int no)                                                    // Set source destination file   (Argument is file no range between 0-69)       
{
	strncpy(ip[sc],links[sc][no].ip,strlen(links[sc][no].ip));
	ip[sc][strlen(links[sc][no].ip)] = '\0';
	//printf("\nLink:%s",ip[sc][]);
	switch(sc)
	{
	 case 0:
	    	strncpy(op[sc],"t_0.txt",7);
	    	op[sc][7] = '\0';
	    	break;
	 case 1:
	    	strncpy(op[sc],"t_1.txt",7);
	    	op[sc][7] = '\0';
	    	break; 
	 case 2:
	    	strncpy(op[sc],"t_2.txt",7);
	    	op[sc][7] = '\0';
	    	break;  	
	 case 3:
	    	strncpy(op[sc],"t_3.txt",7);
	    	op[sc][7] = '\0';
	    	break;
	 case 4:
	    	strncpy(op[sc],"t_4.txt",7);
	    	op[sc][7] = '\0';
	    	break;
	 case 5:
	    	strncpy(op[sc],"t_5.txt",7);
	    	op[sc][7] = '\0';
	    	break;
	  case 6:
	    	strncpy(op[sc],"t_6.txt",7);
	    	op[sc][7] = '\0';
	    	break;
    }
	
}
void open_fil(int sc)                                                    // open file
{
     
	//char my_err[40];
	src[sc] = fopen(ip[sc], "r+");                                       // Open I/O file
	//printf("\nSrc: %s",ip[sc]);
	//printf("\ntemp: %s",op[sc]);
	temp[sc] = fopen(op[sc], "r+");
	
	if(src[sc] == NULL )                                             // Notify Error
	  {
	   perror(ip[sc]);
       //getch();
	  }
	  if(temp[sc] == NULL)
	  {
	   perror(op[sc]);
	   //getch();
	  }
}
void clr_tmp(int sc)                                                                 //Clear temp file (proximity sensor data)
{
  temp[sc] = fopen(op[sc],"w");                                                        
  fclose(temp[sc]);
}
void coppy(int sc)                                                     //Copy data from temp file to raw data file
{                                                                // This function is used while removing redundant new lines/spaces in raw data file
	rewind(temp[sc]);
	fclose(src[sc]);
	src[sc] = fopen(ip[sc], "w");
	rewind(src[sc]);
	while(1)
	{
	  tmp[sc] = fgetc(temp[sc]);
	  if(tmp[sc] == EOF)
	   {
		 break;
	   }
	  else
	   {
		  fputc(tmp[sc],src[sc]);
	   }
	}

}
void new_lin_spa(int sc)                                                   // removes unwanted new line and replaces with space
{
	int no=0;
	rewind(src[sc]);
	rewind(temp[sc]);

	while(1)
	{
	  tmp[sc] = fgetc(src[sc]);
	  if(tmp[sc] == EOF)
	   {
		 break;
	   }

	  if(no == 2)                                                          //replacing new lines with spaces
	   {
		  fputc(' ',temp[sc]);
		  no =0;
	   }
	  else
	   {
		  fputc(tmp[sc],temp[sc]);
	   }
	  if(((tmp[sc] >= 65) && (tmp[sc] <= 90)) || ((tmp[sc] >= 48) && (tmp[sc] <= 57)))
	   {
	     no++;
	   }
	}
	coppy(sc);
    
}
void double_agnt(int sc)                                                         // This function removes redundant spaces in file
{
      int rs=0;
      rewind(temp[sc]);
      rewind(src[sc]);

      while(1)                                                              //removing redundant spaces
	{
	  tmp[sc] = fgetc(src[sc]);
	  if(tmp[sc]==EOF)
	   {
		 break;
	   }
	  if(tmp[sc] == ' ')
	   {
		  rs++;
		  if(rs==1)
		   {
		     fputc(' ',temp[sc]);
		   }
		  else
		   {

		   }
	   }
	  else
	   {
		rs=0;
		fputc(tmp[sc],temp[sc]);
	   }
	}
       coppy(sc);

}
void double_agent_x(int sc)                                    // This function removes new lines in raw data file
{
  int rs=0;
      rewind(temp[sc]);
      rewind(src[sc]);

	while(1)                                                               //Look for new lines, if it occurs twice remove and replace with space
	{
	  tmp[sc] = fgetc(src[sc]);
	  if(tmp[sc]==EOF)
	   {
		 break;
	   }
	  if(tmp[sc] == '\n')
	   {
		  rs++;
		  if(rs==1)
		   {
		     fputc('\n',temp[sc]);
		   }
		  else
		   {

		   }
	   }
	  else
	   {
		rs=0;
		fputc(tmp[sc],temp[sc]);
	   }
	}
       coppy(sc);
}
void agan()                                                               // Function prompts option to execute this program again
{
 printf("\n To continue, press 1:");
 scanf(" %d",&ag);
}

void kloj(int sc)                                                // This function closes I/o files
{
  fclose(src[sc]);
 fclose(temp[sc]);
}  
void calc(int sc)                                                 // This function calculates temperature if 35byte of data is provided
{
    unsigned char tpec1;
    unsigned int tp1[16],tptat1;  
    int k;
	tptat1 = 256*readbuff1[sc][1] + readbuff1[sc][0];              // Copy 35 byte and group them for 2byte/pixel
     tp1[0] = 256*readbuff1[sc][3] + readbuff1[sc][2];
     tp1[1] = 256*readbuff1[sc][5] + readbuff1[sc][4];
     tp1[2] = 256*readbuff1[sc][7] + readbuff1[sc][6];
     tp1[3] = 256*readbuff1[sc][9] + readbuff1[sc][8];
     tp1[4] = 256*readbuff1[sc][11] + readbuff1[sc][10];
     tp1[5] = 256*readbuff1[sc][13] + readbuff1[sc][12];
     tp1[6] = 256*readbuff1[sc][15] + readbuff1[sc][14];
     tp1[7] = 256*readbuff1[sc][17] + readbuff1[sc][16];
     tp1[8] = 256*readbuff1[sc][19] + readbuff1[sc][18];
     tp1[9] = 256*readbuff1[sc][21] + readbuff1[sc][20];
     tp1[10] = 256*readbuff1[sc][23] + readbuff1[sc][22];
     tp1[11] = 256*readbuff1[sc][25] + readbuff1[sc][24];
     tp1[12] = 256*readbuff1[sc][27] + readbuff1[sc][26];
     tp1[13] = 256*readbuff1[sc][29] + readbuff1[sc][28];
     tp1[14] = 256*readbuff1[sc][31] + readbuff1[sc][30];
     tp1[15] = 256*readbuff1[sc][33] + readbuff1[sc][32];
     tpec1 = readbuff1[sc][34];
	 for(k=0;k<=15;k++)
	 {
       fl1[sc][k] = tp1[k]/10.0;                             // Divide 2byte by 10 get temperature
	 }
	 //ft1 = tptat1/10.0;                                 // Calculating Reference temperature



}   
void writ(int sc)                                            //This function generates IR proximity sensor data file (Temporary MS excel file)
{                                                      // For information, this function is executed when user choose 9 in menu.
   char duriya[30];                                    
   float val[8],val1[8],ops[8];
   unsigned int tep;
   long int contg=0;
   FILE *temp11,*duri;
   int i=0,r,cntt=0,arr=1,x;
   //printf("\n Generating Avg. File.....");
   switch(sc)
   {
	   case 0:
	       stpcpy(duriya,"a_0.txt");
	       break;
	   case 1:
	       stpcpy(duriya,"a_1.txt");
	       break;
	   case 2:
	       stpcpy(duriya,"a_2.txt");
	       break;
	   case 3:
	       stpcpy(duriya,"a_3.txt");
	       break;
	  case 4:
	       stpcpy(duriya,"a_4.txt");
	       break;
	 case 5:
	       stpcpy(duriya,"a_5.txt");
	       break;
	 case 6:
	       stpcpy(duriya,"a_6.txt");
	       break;
	}
   
   strncpy(diss[sc],duriya,7);
   duri = fopen(duriya,"w");
   temp11 = fopen(ip[sc],"r");
     if(duri == NULL )
	  {
	   perror("\n Src1");
	   //getch();
	  }
	  if(temp11 == NULL)
	  {
	   perror("\n temp1");
	   //getch();
	  }
  
   rewind(temp11);
   fprintf(duri,"D1\tD2\tD3\tD4\tD5\t\n");
   while(fscanf(temp11,"%x",&tep) != EOF)
   {
	  if(i==0)
	  {
	    if(tep == 241)
	    {
	     contg++;
	    }
	   else
	   {
	    contg=0;
	   }
	 }
	if(contg==5)
	 {
	   i=1;
	   for(r=0;r<=4;r++)
	   {
	     fscanf(temp11,"%x",&tep);
		 if(arr == 1)
		 {
		  val[r] = (((10.00*((1.00/((0.001240875*(tep))+0.005))-0.42))))/10;
		  if(r==4)
		  {
		    arr++;
		  }
		 }
		 else if(arr==2)
		 {
		   val1[r] = (((10.00*((1.00/((0.001240875*(tep))+0.005))-0.42))))/10;
		   if(r==4)
		  {
		    arr=1;
		  }
		 }
	   }
	   cntt++;
	   if(cntt==2)
	   {
	     for(x=0;x<=4;x++)
		 {
		   ops[x] = val[x];                                        // For averaging replace it with ops[x] = (val[x] + val1[x])/2; 
		   /*if(ops[x]>100)
		   {
		    ops[x] = 100;
		   } */
		   fprintf(duri,"%.1f\t",ops[x]);
		   val[x] = 0;
		   val1[x] = 0;
		   if(x==4)
		   {
		     fprintf(duri,"\n");
			 cntt=0;
		   }
		 }
	   }
	   for(r=1;r<=5;r++)
	   {
	     fscanf(temp11,"%x",&tep);
	   }
	   i=0;
	 }
   }
   fclose(duri);
   fclose(temp11); 
}
void fis(int sc, int re)                                           //This function generates final text file, which is stored in pdata folder
{                                                          // To be noted fopen(-,"w") will delete existing data if executed twice or if file exist
   char duriya[30],valu[10];                               // This function is executed while user choose 9 in menu; This function is written by help of all function written before;
   unsigned int tep;
   float tempe=0.0,su;
   long int contg=0;
   FILE *temp11,*duri,*fi;
   int i=0,r,l,m,len;
   fi = fopen(diss[sc],"r");                              //a.xls IR Proximity Data
   duri = fopen(links[sc][re].resl,"w");
   temp11 = fopen(ip[sc],"r");
   if(duri == NULL )
	  {
	   perror("\n FI");
       //getch();
	  }
	  if(temp11 == NULL)
	  {
	   perror("\n IP");
	   //getch();
	  }
    if(fi == NULL)
	  {
	   perror("\n AVG");
	   //getch();
	  }
   rewind(temp11);
   for(l=0;l<=4;l++)
   {
     fscanf(fi,"%s",valu);
	 if(l!=2)
	 {
	   fprintf(duri,"%s\t",valu);
	 }
   }
   //fprintf(duri,"LT1\tLT2\tLT3\tLT4\tLT5\tLT6\tLT7\tLT8\tLT9\tLT10\tLT11\tLT12\tLT13\tLT14\tLT15\tLT16\tRT1\tRT2\tRT3\tRT4\tRT5\tRT6\tRT7\tRT8\tRT9\tRT10\tRT11\tRT12\tRT13\tRT14\tRT15\tRT16\n");
   fprintf(duri,"L\tR\n");
   while(fscanf(temp11,"%x",&tep) != EOF)
   {
	  if(i==0)
	  {
	    if(tep == 242)
	    {
	     contg++;
	    }
	   else
	   {
	    contg=0;
	   }
	 }
	if(contg==5)
	 {
	   i=1;
	   for(r=0;r<=34;r++)
	   {
	     fscanf(temp11,"%x",&tep);
		 readbuff1[sc][r] = tep;
	   }
	   for(l=0;l<=4;l++)
       {
        fscanf(fi,"%s",valu);
	    if(l!=2)
	    {
          fprintf(duri,"%s\t",valu);	    
	    }
       }
	   calc(sc);
/*	   for(r=0;r<=15;r++)
	   {	     
		   if(fl1[r]<90.0)
		   {
		    fprintf(duri,"%.1f\t",fl1[r]);
		   }
		  else
		  {
		    fprintf(duri,"30\t");
		  }		 
	   }
*/	   tempe=0;
	   for(r=5;r<=6;r++)
	   {	     
		   if(fl1[sc][r]<90.0)
		   {
		     tempe = tempe + fl1[sc][r];
		   }
		  else
		   {
		     tempe = tempe + 30.0;
		   }		 
	   }
	   for(r=9;r<=10;r++)
	   {	     
		   if(fl1[sc][r]<90.0)
		   {
		    tempe = tempe + fl1[sc][r];
		   }
		  else
		  {
		   tempe = tempe + 30.0;
		  }		 
	   }
	   fprintf(duri,"%.1f\t",(tempe/4.0));
       for(r=0;r<=34;r++)
	   {
	     fscanf(temp11,"%x",&tep);
		 readbuff1[sc][r] = tep;
	   }
	   calc(sc);
	   tempe=0;
	   for(r=5;r<=6;r++)
	   {	     
		   if(fl1[sc][r]<90.0)
		   {
		     tempe = tempe + fl1[sc][r];
		   }
		  else
		   {
		     tempe = tempe + 30.0;
		   }		 
	   }
	   for(r=9;r<=10;r++)
	   {	     
		   if(fl1[sc][r]<90.0)
		   {
		    tempe = tempe + fl1[sc][r];
		   }
		   else
		   {
		    tempe = tempe + 30.0;
		   }		 
	   }
	   fprintf(duri,"%.1f\n",(tempe/4.0));
       
/*	   for(r=0;r<=15;r++)
	   {	     
		   if(fl1[r]<90.0)
		   {
		    fprintf(duri,"%.1f\t",fl1[r]);
		   }
		  else
		  {
		   fprintf(duri,"30\t");
		  }
          if(r==15)
           {
		     fprintf(duri,"\n");
		   }		  
	   }
*/	   for(r=1;r<=5;r++)
	   {
	     fscanf(temp11,"%x",&tep);
	   }
	   i=0;
	 }
   }

   fclose(duri);
   fclose(temp11);
   fclose(fi);
   fi = fopen(diss[sc],"w");
   fclose(fi);
}

void procs_sc(int *sce)
{
  int i,si = (*sce);
  
  //printf("\n sc: %d",si);
  switch(si)
			   {
			     case 0:
				 {
				   //printf("\n Setting Links of Scenario (1)........");
				   set_links_1();
				   res_links_1();
				   break;
				 }
				 case 1:
				 {
				   //printf("\n Setting Links of Scenario (2)........");
				   set_links_2();
				   res_links_2();
				   break;
				 }
				 case 2:
				 {
				   //printf("\n Setting Links of Scenario (3)........");
				   set_links_3();
				   res_links_3();
				   break;
				 }
				 case 3:
				 {
				   //printf("\n Setting Links of Scenario (4)........");
				   set_links_4();
				   res_links_4();
				   break;
				 }
				 case 4:
				 {
				   //printf("\n Setting Links of Scenario (5)........");
				   set_links_5();
				   res_links_5();
				   break;
				 }
				 case 5:
				 {
					//printf("\n Setting Links of Scenario (6)........"); 
				   set_links_6();
				   res_links_6();
				   break;
				 }
				 case 6:
				 {
				   //printf("\n Setting Links of Scenario (7)........");
				   set_links_7();
				   res_links_7();
				   break;
				 }
			}
	    for(i=0;i<=79;i++)
			   {
			     src_des(si,i);
			     clr_tmp(si);
			     //printf("\n Scanning file finished....");
                 open_fil(si);
				 new_lin_spa(si);
				 kloj(si);
				 open_fil(si);
				 double_agnt(si);
				 kloj(si);
				 open_fil(si);
				 double_agent_x(si);
				 kloj(si);
				 //printf("\n Parsing finished......");
			     //ye_duriya(i);
				 writ(si);
			     fis(si,i);                                          // Argument defines result file's link	
			     pthread_mutex_lock(&my_lock);
				 prec++;
				 //val = prec/560;
				// val = 100*val;
				 pthread_mutex_unlock(&my_lock);		   
			   }
  	
	pthread_exit(0);
	
}
void stts()
{
   int e=0,cur;
  // char mes[20];
   float dev;
   while(1)
	{
	  //pthread_mutex_lock(&my_lock);
	  cur = prec;
	  //pthread_mutex_unlock(&my_lock);
	  dev = ((float)cur/559)*100;
	  printf("\r%.2f%% files Pre-Processed......",dev);
	  
     fflush(stdout);
     if(prec==560)
       {
		    e=1;
		    break;	
		}      
	}
	 if(e)
	  pthread_exit(0);
}
void remov()
{
	remove("a_0.txt");
	remove("a_1.txt");
	remove("a_2.txt");
	remove("a_3.txt");
	remove("a_4.txt");
	remove("a_5.txt");
	remove("a_6.txt");
	remove("t_0.txt");
	remove("t_1.txt");
	remove("t_2.txt");
	remove("t_3.txt");
	remove("t_4.txt");
	remove("t_5.txt");
	remove("t_6.txt");
}

int main()                            // Main function
{                                     // Menu explains purpose of functions in place

	int i;
	char my_err[10];
	pthread_t th[8];
	printf("\e[?25l"); /* hide the cursor */
	//clrscr();
	pre_proces:
     {
	            i=7;
	            if(pthread_create(&th[i],NULL,(void *)&stts,NULL))
	            {
					sprintf(my_err,"create[%d]",i);
					  perror(my_err);
				}
	              
			   for(i=0;i<=6;i++)
			   {
				   if(pthread_create(&th[i],NULL,(void *)&procs_sc,(void *)&i)) 
				   {
					  sprintf(my_err,"create[%d]",i);
					  perror(my_err);
				       
					}
			   }
			   
			   for(i=0;i<=6;i++)
			   {
				   if(pthread_join(th[i],NULL))
				   {
					  sprintf(my_err,"Join[%d]",i);
					  perror(my_err);
					}
				}		   
			   i=7;
			   if(pthread_join(th[i],NULL))
			   {
				  sprintf(my_err,"Join[%d]",i);
				  perror(my_err);
				}	
				
				remov();		      
			   printf("\n");
		}
  if(prec<559)
   {
	printf("Error in pre-processing, retrying......");
	goto pre_proces;
   }	   
   
   
   

   printf("\e[?25h"); /* show the cursor */
 return 0;
}

#else
   #error "This implementation works only in linux!"
 #endif





