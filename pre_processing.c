/*
 * File: pre_process.c
 * Created on: Dec 1, 2013; 01:08:35 AM 
 * Author: Shivendra Mishra
 * Notepad++ v6.5.5 (UNICODE)
 * 
 *
 *
 * Environment: Notepad++ with Borland C++ V5.5
 * Input: Hex file from system file c:/data/SCx_/Sx_Sy/Sx_Sy_t.txt      Where x,y are path directions and t is trial.
 * Output: Pre-Processed data (16 Attributes=4(IR Proximity Sensor) + 32(MEMS Thermal Imaging Sensor ))
 * Execution: Execute and choose 9 from Menu; If it is required to process step by step choose accordingly from menu.
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>                                              // Headers
unsigned char ther[35],diss[35],readbuff1[35],op1[20];          // Matrix for thermal imaging data
unsigned int tp1[16],tptat1;                                    // Result matrix of thermal imaging data
float fl1[16],ft1;
FILE *src, *temp,*oup;                                          // File pointers for i/o files
int count,ag=0;
char tmp, ip[35], op[35];


struct fil
{
 char ip[35];                                                 // For storing input file location
 char resl[35];                                               // output file location
}links[100];


void set_links_1()                                                      //Storing input file links for scenario 1
{
 strcpy(links[0].ip,"C:/data/SC1_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC1_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC1_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC1_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC1_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC1_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC1_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC1_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC1_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC1_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC1_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC1_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC1_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC1_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC1_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC1_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC1_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC1_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC1_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC1_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC1_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC1_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC1_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC1_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC1_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC1_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC1_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC1_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC1_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC1_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC1_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC1_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC1_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC1_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC1_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC1_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC1_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC1_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC1_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC1_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].ip,"C:/data/SC1_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC1_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC1_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC1_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC1_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC1_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC1_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC1_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC1_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC1_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC1_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC1_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC1_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC1_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC1_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC1_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC1_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC1_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC1_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC1_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC1_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC1_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC1_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC1_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC1_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC1_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC1_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC1_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC1_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC1_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC1_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC1_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC1_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC1_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC1_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC1_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC1_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC1_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC1_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC1_/S8_S7/S8_S7_10.txt");
 
}
void set_links_2()                                                            //Storing input file links for scenario 2
{
 strcpy(links[0].ip,"C:/data/SC2_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC2_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC2_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC2_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC2_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC2_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC2_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC2_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC2_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC2_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC2_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC2_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC2_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC2_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC2_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC2_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC2_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC2_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC2_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC2_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC2_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC2_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC2_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC2_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC2_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC2_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC2_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC2_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC2_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC2_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC2_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC2_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC2_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC2_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC2_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC2_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC2_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC2_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC2_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC2_/S4_S3/S4_S3_10.txt");
 
 
 
 strcpy(links[40].ip,"C:/data/SC2_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC2_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC2_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC2_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC2_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC2_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC2_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC2_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC2_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC2_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC2_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC2_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC2_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC2_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC2_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC2_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC2_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC2_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC2_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC2_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC2_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC2_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC2_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC2_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC2_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC2_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC2_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC2_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC2_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC2_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC2_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC2_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC2_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC2_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC2_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC2_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC2_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC2_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC2_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC2_/S8_S7/S8_S7_10.txt");
}


void set_links_3()                                                                   //Storing input file links for scenario 3
{
 strcpy(links[0].ip,"C:/data/SC3_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC3_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC3_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC3_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC3_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC3_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC3_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC3_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC3_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC3_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC3_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC3_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC3_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC3_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC3_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC3_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC3_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC3_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC3_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC3_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC3_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC3_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC3_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC3_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC3_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC3_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC3_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC3_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC3_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC3_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC3_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC3_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC3_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC3_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC3_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC3_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC3_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC3_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC3_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC3_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].ip,"C:/data/SC3_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC3_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC3_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC3_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC3_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC3_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC3_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC3_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC3_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC3_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC3_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC3_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC3_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC3_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC3_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC3_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC3_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC3_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC3_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC3_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC3_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC3_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC3_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC3_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC3_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC3_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC3_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC3_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC3_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC3_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC3_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC3_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC3_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC3_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC3_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC3_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC3_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC3_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC3_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC3_/S8_S7/S8_S7_10.txt");
}




void set_links_4()                                                                  //Storing input file links for scenario 4
{
 strcpy(links[0].ip,"C:/data/SC4_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC4_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC4_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC4_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC4_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC4_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC4_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC4_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC4_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC4_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC4_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC4_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC4_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC4_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC4_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC4_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC4_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC4_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC4_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC4_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC4_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC4_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC4_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC4_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC4_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC4_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC4_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC4_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC4_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC4_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC4_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC4_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC4_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC4_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC4_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC4_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC4_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC4_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC4_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC4_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].ip,"C:/data/SC4_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC4_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC4_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC4_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC4_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC4_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC4_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC4_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC4_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC4_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC4_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC4_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC4_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC4_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC4_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC4_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC4_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC4_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC4_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC4_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC4_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC4_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC4_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC4_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC4_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC4_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC4_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC4_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC4_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC4_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC4_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC4_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC4_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC4_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC4_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC4_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC4_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC4_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC4_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC4_/S8_S7/S8_S7_10.txt");
}





void set_links_5()                                                             //Storing input file links for scenario 5
{
 strcpy(links[0].ip,"C:/data/SC5_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC5_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC5_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC5_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC5_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC5_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC5_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC5_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC5_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC5_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC5_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC5_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC5_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC5_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC5_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC5_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC5_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC5_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC5_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC5_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC5_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC5_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC5_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC5_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC5_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC5_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC5_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC5_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC5_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC5_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC5_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC5_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC5_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC5_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC5_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC5_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC5_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC5_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC5_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC5_/S4_S3/S4_S3_10.txt");
 
 
 
 strcpy(links[40].ip,"C:/data/SC5_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC5_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC5_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC5_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC5_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC5_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC5_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC5_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC5_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC5_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC5_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC5_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC5_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC5_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC5_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC5_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC5_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC5_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC5_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC5_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC5_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC5_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC5_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC5_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC5_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC5_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC5_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC5_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC5_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC5_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC5_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC5_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC5_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC5_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC5_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC5_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC5_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC5_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC5_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC5_/S8_S7/S8_S7_10.txt");
}




void set_links_6()                                             //Storing input file links for scenario 6
{
 strcpy(links[0].ip,"C:/data/SC6_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC6_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC6_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC6_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC6_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC6_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC6_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC6_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC6_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC6_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC6_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC6_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC6_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC6_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC6_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC6_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC6_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC6_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC6_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC6_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC6_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC6_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC6_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC6_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC6_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC6_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC6_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC6_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC6_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC6_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC6_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC6_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC6_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC6_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC6_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC6_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC6_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC6_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC6_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC6_/S4_S3/S4_S3_10.txt");
 
 
 
 
 strcpy(links[40].ip,"C:/data/SC6_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC6_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC6_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC6_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC6_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC6_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC6_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC6_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC6_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC6_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC6_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC6_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC6_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC6_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC6_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC6_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC6_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC6_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC6_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC6_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC6_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC6_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC6_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC6_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC6_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC6_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC6_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC6_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC6_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC6_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC6_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC6_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC6_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC6_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC6_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC6_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC6_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC6_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC6_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC6_/S8_S7/S8_S7_10.txt");
}



void set_links_7()                                                   //Storing input file links for scenario 7
{
 strcpy(links[0].ip,"C:/data/SC7_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].ip,"C:/data/SC7_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].ip,"C:/data/SC7_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].ip,"C:/data/SC7_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].ip,"C:/data/SC7_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].ip,"C:/data/SC7_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].ip,"C:/data/SC7_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].ip,"C:/data/SC7_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].ip,"C:/data/SC7_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].ip,"C:/data/SC7_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].ip,"C:/data/SC7_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].ip,"C:/data/SC7_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].ip,"C:/data/SC7_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].ip,"C:/data/SC7_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].ip,"C:/data/SC7_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].ip,"C:/data/SC7_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].ip,"C:/data/SC7_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].ip,"C:/data/SC7_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].ip,"C:/data/SC7_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].ip,"C:/data/SC7_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].ip,"C:/data/SC7_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].ip,"C:/data/SC7_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].ip,"C:/data/SC7_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].ip,"C:/data/SC7_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].ip,"C:/data/SC7_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].ip,"C:/data/SC7_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].ip,"C:/data/SC7_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].ip,"C:/data/SC7_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].ip,"C:/data/SC7_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].ip,"C:/data/SC7_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].ip,"C:/data/SC7_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].ip,"C:/data/SC7_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].ip,"C:/data/SC7_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].ip,"C:/data/SC7_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].ip,"C:/data/SC7_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].ip,"C:/data/SC7_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].ip,"C:/data/SC7_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].ip,"C:/data/SC7_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].ip,"C:/data/SC7_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].ip,"C:/data/SC7_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].ip,"C:/data/SC7_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].ip,"C:/data/SC7_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].ip,"C:/data/SC7_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].ip,"C:/data/SC7_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].ip,"C:/data/SC7_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].ip,"C:/data/SC7_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].ip,"C:/data/SC7_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].ip,"C:/data/SC7_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].ip,"C:/data/SC7_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].ip,"C:/data/SC7_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].ip,"C:/data/SC7_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].ip,"C:/data/SC7_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].ip,"C:/data/SC7_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].ip,"C:/data/SC7_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].ip,"C:/data/SC7_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].ip,"C:/data/SC7_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].ip,"C:/data/SC7_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].ip,"C:/data/SC7_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].ip,"C:/data/SC7_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].ip,"C:/data/SC7_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].ip,"C:/data/SC7_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].ip,"C:/data/SC7_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].ip,"C:/data/SC7_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].ip,"C:/data/SC7_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].ip,"C:/data/SC7_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].ip,"C:/data/SC7_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].ip,"C:/data/SC7_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].ip,"C:/data/SC7_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].ip,"C:/data/SC7_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].ip,"C:/data/SC7_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].ip,"C:/data/SC7_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].ip,"C:/data/SC7_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].ip,"C:/data/SC7_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].ip,"C:/data/SC7_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].ip,"C:/data/SC7_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].ip,"C:/data/SC7_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].ip,"C:/data/SC7_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].ip,"C:/data/SC7_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].ip,"C:/data/SC7_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].ip,"C:/data/SC7_/S8_S7/S8_S7_10.txt");
}


void res_links_1()                                                            //Storing output file links for scenario 1
{
 strcpy(links[0].resl,"C:/sound/SC1_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC1_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC1_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC1_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC1_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC1_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC1_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC1_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC1_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC1_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC1_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC1_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC1_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC1_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC1_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC1_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC1_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC1_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC1_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC1_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC1_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC1_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC1_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC1_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC1_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC1_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC1_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC1_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC1_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC1_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC1_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC1_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC1_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC1_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC1_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC1_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC1_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC1_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC1_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC1_/S4_S3/S4_S3_10.txt");
 
 
 
 
 strcpy(links[40].resl,"C:/sound/SC1_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC1_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC1_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC1_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC1_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC1_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC1_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC1_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC1_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC1_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC1_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC1_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC1_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC1_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC1_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC1_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC1_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC1_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC1_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC1_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC1_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC1_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC1_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC1_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC1_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC1_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC1_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC1_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC1_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC1_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC1_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC1_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC1_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC1_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC1_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC1_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC1_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC1_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC1_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC1_/S8_S7/S8_S7_10.txt");
}
void res_links_2()                                                             //Storing output file links for scenario 2
{
 strcpy(links[0].resl,"C:/sound/SC2_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC2_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC2_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC2_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC2_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC2_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC2_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC2_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC2_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC2_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC2_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC2_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC2_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC2_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC2_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC2_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC2_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC2_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC2_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC2_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC2_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC2_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC2_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC2_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC2_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC2_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC2_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC2_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC2_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC2_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC2_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC2_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC2_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC2_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC2_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC2_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC2_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC2_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC2_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC2_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].resl,"C:/sound/SC2_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC2_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC2_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC2_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC2_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC2_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC2_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC2_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC2_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC2_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC2_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC2_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC2_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC2_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC2_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC2_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC2_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC2_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC2_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC2_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC2_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC2_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC2_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC2_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC2_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC2_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC2_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC2_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC2_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC2_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC2_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC2_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC2_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC2_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC2_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC2_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC2_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC2_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC2_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC2_/S8_S7/S8_S7_10.txt");
}


void res_links_3()                                                      //Storing output file links for scenario 3
{
 strcpy(links[0].resl,"C:/sound/SC3_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC3_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC3_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC3_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC3_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC3_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC3_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC3_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC3_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC3_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC3_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC3_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC3_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC3_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC3_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC3_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC3_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC3_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC3_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC3_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC3_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC3_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC3_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC3_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC3_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC3_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC3_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC3_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC3_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC3_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC3_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC3_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC3_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC3_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC3_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC3_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC3_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC3_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC3_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC3_/S4_S3/S4_S3_10.txt");
 
 
 
 
 strcpy(links[40].resl,"C:/sound/SC3_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC3_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC3_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC3_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC3_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC3_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC3_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC3_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC3_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC3_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC3_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC3_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC3_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC3_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC3_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC3_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC3_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC3_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC3_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC3_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC3_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC3_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC3_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC3_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC3_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC3_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC3_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC3_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC3_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC3_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC3_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC3_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC3_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC3_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC3_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC3_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC3_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC3_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC3_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC3_/S8_S7/S8_S7_10.txt");
}




void res_links_4()                                               //Storing output file links for scenario 4
{
 strcpy(links[0].resl,"C:/sound/SC4_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC4_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC4_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC4_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC4_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC4_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC4_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC4_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC4_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC4_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC4_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC4_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC4_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC4_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC4_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC4_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC4_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC4_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC4_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC4_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC4_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC4_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC4_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC4_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC4_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC4_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC4_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC4_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC4_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC4_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC4_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC4_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC4_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC4_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC4_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC4_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC4_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC4_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC4_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC4_/S4_S3/S4_S3_10.txt");
 
 
 
 
 
 strcpy(links[40].resl,"C:/sound/SC4_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC4_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC4_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC4_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC4_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC4_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC4_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC4_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC4_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC4_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC4_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC4_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC4_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC4_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC4_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC4_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC4_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC4_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC4_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC4_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC4_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC4_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC4_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC4_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC4_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC4_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC4_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC4_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC4_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC4_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC4_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC4_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC4_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC4_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC4_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC4_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC4_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC4_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC4_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC4_/S8_S7/S8_S7_10.txt");
}





void res_links_5()                                                 //Storing output file links for scenario 5
{
 strcpy(links[0].resl,"C:/sound/SC5_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC5_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC5_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC5_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC5_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC5_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC5_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC5_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC5_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC5_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC5_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC5_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC5_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC5_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC5_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC5_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC5_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC5_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC5_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC5_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC5_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC5_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC5_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC5_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC5_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC5_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC5_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC5_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC5_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC5_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC5_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC5_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC5_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC5_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC5_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC5_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC5_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC5_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC5_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC5_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].resl,"C:/sound/SC5_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC5_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC5_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC5_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC5_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC5_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC5_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC5_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC5_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC5_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC5_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC5_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC5_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC5_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC5_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC5_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC5_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC5_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC5_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC5_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC5_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC5_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC5_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC5_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC5_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC5_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC5_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC5_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC5_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC5_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC5_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC5_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC5_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC5_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC5_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC5_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC5_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC5_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC5_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC5_/S8_S7/S8_S7_10.txt");
}




void res_links_6()                                                    //Storing output file links for scenario 6
{
 strcpy(links[0].resl,"C:/sound/SC6_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC6_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC6_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC6_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC6_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC6_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC6_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC6_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC6_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC6_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC6_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC6_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC6_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC6_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC6_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC6_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC6_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC6_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC6_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC6_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC6_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC6_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC6_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC6_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC6_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC6_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC6_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC6_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC6_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC6_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC6_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC6_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC6_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC6_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC6_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC6_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC6_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC6_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC6_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC6_/S4_S3/S4_S3_10.txt");
 
 
 
 
 
 strcpy(links[40].resl,"C:/sound/SC6_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC6_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC6_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC6_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC6_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC6_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC6_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC6_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC6_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC6_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC6_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC6_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC6_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC6_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC6_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC6_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC6_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC6_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC6_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC6_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC6_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC6_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC6_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC6_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC6_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC6_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC6_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC6_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC6_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC6_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC6_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC6_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC6_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC6_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC6_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC6_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC6_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC6_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC6_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC6_/S8_S7/S8_S7_10.txt");
}



void res_links_7()                                                      //Storing output file links for scenario 7
{
 strcpy(links[0].resl,"C:/sound/SC7_/S1_S2/S1_S2_1.txt");
 strcpy(links[1].resl,"C:/sound/SC7_/S1_S2/S1_S2_2.txt");
 strcpy(links[2].resl,"C:/sound/SC7_/S1_S2/S1_S2_3.txt");
 strcpy(links[3].resl,"C:/sound/SC7_/S1_S2/S1_S2_4.txt");
 strcpy(links[4].resl,"C:/sound/SC7_/S1_S2/S1_S2_5.txt");
 strcpy(links[5].resl,"C:/sound/SC7_/S1_S2/S1_S2_6.txt");
 strcpy(links[6].resl,"C:/sound/SC7_/S1_S2/S1_S2_7.txt");
 strcpy(links[7].resl,"C:/sound/SC7_/S1_S2/S1_S2_8.txt");
 strcpy(links[8].resl,"C:/sound/SC7_/S1_S2/S1_S2_9.txt");
 strcpy(links[9].resl,"C:/sound/SC7_/S1_S2/S1_S2_10.txt");
 strcpy(links[10].resl,"C:/sound/SC7_/S2_S1/S2_S1_1.txt");
 strcpy(links[11].resl,"C:/sound/SC7_/S2_S1/S2_S1_2.txt");
 strcpy(links[12].resl,"C:/sound/SC7_/S2_S1/S2_S1_3.txt");
 strcpy(links[13].resl,"C:/sound/SC7_/S2_S1/S2_S1_4.txt");
 strcpy(links[14].resl,"C:/sound/SC7_/S2_S1/S2_S1_5.txt");
 strcpy(links[15].resl,"C:/sound/SC7_/S2_S1/S2_S1_6.txt");
 strcpy(links[16].resl,"C:/sound/SC7_/S2_S1/S2_S1_7.txt");
 strcpy(links[17].resl,"C:/sound/SC7_/S2_S1/S2_S1_8.txt");
 strcpy(links[18].resl,"C:/sound/SC7_/S2_S1/S2_S1_9.txt");
 strcpy(links[19].resl,"C:/sound/SC7_/S2_S1/S2_S1_10.txt");
 strcpy(links[20].resl,"C:/sound/SC7_/S3_S4/S3_S4_1.txt");
 strcpy(links[21].resl,"C:/sound/SC7_/S3_S4/S3_S4_2.txt");
 strcpy(links[22].resl,"C:/sound/SC7_/S3_S4/S3_S4_3.txt");
 strcpy(links[23].resl,"C:/sound/SC7_/S3_S4/S3_S4_4.txt");
 strcpy(links[24].resl,"C:/sound/SC7_/S3_S4/S3_S4_5.txt");
 strcpy(links[25].resl,"C:/sound/SC7_/S3_S4/S3_S4_6.txt");
 strcpy(links[26].resl,"C:/sound/SC7_/S3_S4/S3_S4_7.txt");
 strcpy(links[27].resl,"C:/sound/SC7_/S3_S4/S3_S4_8.txt");
 strcpy(links[28].resl,"C:/sound/SC7_/S3_S4/S3_S4_9.txt");
 strcpy(links[29].resl,"C:/sound/SC7_/S3_S4/S3_S4_10.txt");
 strcpy(links[30].resl,"C:/sound/SC7_/S4_S3/S4_S3_1.txt");
 strcpy(links[31].resl,"C:/sound/SC7_/S4_S3/S4_S3_2.txt");
 strcpy(links[32].resl,"C:/sound/SC7_/S4_S3/S4_S3_3.txt");
 strcpy(links[33].resl,"C:/sound/SC7_/S4_S3/S4_S3_4.txt");
 strcpy(links[34].resl,"C:/sound/SC7_/S4_S3/S4_S3_5.txt");
 strcpy(links[35].resl,"C:/sound/SC7_/S4_S3/S4_S3_6.txt");
 strcpy(links[36].resl,"C:/sound/SC7_/S4_S3/S4_S3_7.txt");
 strcpy(links[37].resl,"C:/sound/SC7_/S4_S3/S4_S3_8.txt");
 strcpy(links[38].resl,"C:/sound/SC7_/S4_S3/S4_S3_9.txt");
 strcpy(links[39].resl,"C:/sound/SC7_/S4_S3/S4_S3_10.txt");
 
 
 strcpy(links[40].resl,"C:/sound/SC7_/S5_S6/S5_S6_1.txt");
 strcpy(links[41].resl,"C:/sound/SC7_/S5_S6/S5_S6_2.txt");
 strcpy(links[42].resl,"C:/sound/SC7_/S5_S6/S5_S6_3.txt");
 strcpy(links[43].resl,"C:/sound/SC7_/S5_S6/S5_S6_4.txt");
 strcpy(links[44].resl,"C:/sound/SC7_/S5_S6/S5_S6_5.txt");
 strcpy(links[45].resl,"C:/sound/SC7_/S5_S6/S5_S6_6.txt");
 strcpy(links[46].resl,"C:/sound/SC7_/S5_S6/S5_S6_7.txt");
 strcpy(links[47].resl,"C:/sound/SC7_/S5_S6/S5_S6_8.txt");
 strcpy(links[48].resl,"C:/sound/SC7_/S5_S6/S5_S6_9.txt");
 strcpy(links[49].resl,"C:/sound/SC7_/S5_S6/S5_S6_10.txt");
 strcpy(links[50].resl,"C:/sound/SC7_/S6_S5/S6_S5_1.txt");
 strcpy(links[51].resl,"C:/sound/SC7_/S6_S5/S6_S5_2.txt");
 strcpy(links[52].resl,"C:/sound/SC7_/S6_S5/S6_S5_3.txt");
 strcpy(links[53].resl,"C:/sound/SC7_/S6_S5/S6_S5_4.txt");
 strcpy(links[54].resl,"C:/sound/SC7_/S6_S5/S6_S5_5.txt");
 strcpy(links[55].resl,"C:/sound/SC7_/S6_S5/S6_S5_6.txt");
 strcpy(links[56].resl,"C:/sound/SC7_/S6_S5/S6_S5_7.txt");
 strcpy(links[57].resl,"C:/sound/SC7_/S6_S5/S6_S5_8.txt");
 strcpy(links[58].resl,"C:/sound/SC7_/S6_S5/S6_S5_9.txt");
 strcpy(links[59].resl,"C:/sound/SC7_/S6_S5/S6_S5_10.txt");
 strcpy(links[60].resl,"C:/sound/SC7_/S7_S8/S7_S8_1.txt");
 strcpy(links[61].resl,"C:/sound/SC7_/S7_S8/S7_S8_2.txt");
 strcpy(links[62].resl,"C:/sound/SC7_/S7_S8/S7_S8_3.txt");
 strcpy(links[63].resl,"C:/sound/SC7_/S7_S8/S7_S8_4.txt");
 strcpy(links[64].resl,"C:/sound/SC7_/S7_S8/S7_S8_5.txt");
 strcpy(links[65].resl,"C:/sound/SC7_/S7_S8/S7_S8_6.txt");
 strcpy(links[66].resl,"C:/sound/SC7_/S7_S8/S7_S8_7.txt");
 strcpy(links[67].resl,"C:/sound/SC7_/S7_S8/S7_S8_8.txt");
 strcpy(links[68].resl,"C:/sound/SC7_/S7_S8/S7_S8_9.txt");
 strcpy(links[69].resl,"C:/sound/SC7_/S7_S8/S7_S8_10.txt");
 strcpy(links[70].resl,"C:/sound/SC7_/S8_S7/S8_S7_1.txt");
 strcpy(links[71].resl,"C:/sound/SC7_/S8_S7/S8_S7_2.txt");
 strcpy(links[72].resl,"C:/sound/SC7_/S8_S7/S8_S7_3.txt");
 strcpy(links[73].resl,"C:/sound/SC7_/S8_S7/S8_S7_4.txt");
 strcpy(links[74].resl,"C:/sound/SC7_/S8_S7/S8_S7_5.txt");
 strcpy(links[75].resl,"C:/sound/SC7_/S8_S7/S8_S7_6.txt");
 strcpy(links[76].resl,"C:/sound/SC7_/S8_S7/S8_S7_7.txt");
 strcpy(links[77].resl,"C:/sound/SC7_/S8_S7/S8_S7_8.txt");
 strcpy(links[78].resl,"C:/sound/SC7_/S8_S7/S8_S7_9.txt");
 strcpy(links[79].resl,"C:/sound/SC7_/S8_S7/S8_S7_10.txt");
}


void src_des(int no)                                                    // Set source destination file   (Argument is file no range between 0-69)       
{
	strcpy(ip,links[no].ip);
	//printf("%s",ip);
	strcpy(op,"t.txt");
}
void open_fil()                                                    // open file
{

	src = fopen(ip, "r+");                                       // Open I/O file
	temp = fopen(op, "r+");
	if(src == NULL )                                             // Notify Error
	  {
	   perror("\n Src");
       getch();
	  }
	  if(temp == NULL)
	  {
	   perror("\n temp");
	   getch();
	  }
}
void clr_tmp()                                                                 //Clear temp file (proximity sensor data)
{
  temp = fopen(op,"w");                                                        
  fclose(temp);
}
void fil_scan()                                                               // scans file for number of spaces new line
{
  int nl = 0, spc = 0;
  rewind(src);
  rewind(temp);

  while(1)
	{
	  tmp = fgetc(src);
	  if(tmp == EOF)
	   {
		 break;
	   }
	  if(tmp == '\n')
	   {
		 nl++;
	   }
	  if(tmp == ' ')
	   {
		  spc++;
	   }
	}

   printf("\n Number of Lines:%d",nl);
   printf("\n Number of Spaces:%d",spc);
   
}
void coppy()                                                     //Copy data from temp file to raw data file
{                                                                // This function is used while removing redundant new lines/spaces in raw data file
	rewind(temp);
	fclose(src);
	src = fopen(ip, "w");
	rewind(src);
	while(1)
	{
	  tmp = fgetc(temp);
	  if(tmp == EOF)
	   {
		 break;
	   }
	  else
	   {
		  fputc(tmp,src);
	   }
	}

}
void new_lin_spa()                                                   // removes unwanted new line and replaces with space
{
	int no=0;
	rewind(src);
	rewind(temp);

	while(1)
	{
	  tmp = fgetc(src);
	  if(tmp == EOF)
	   {
		 break;
	   }

	  if(no == 2)                                                          //replacing new lines with spaces
	   {
		  fputc(' ',temp);
		  no =0;
	   }
	  else
	   {
		  fputc(tmp,temp);
	   }
	  if(((tmp >= 65) && (tmp <= 90)) || ((tmp >= 48) && (tmp <= 57)))
	   {
	     no++;
	   }
	}
	coppy();
    
}
void double_agnt()                                                         // This function removes redundant spaces in file
{
      int rs=0;
      rewind(temp);
      rewind(src);

      while(1)                                                              //removing redundant spaces
	{
	  tmp = fgetc(src);
	  if(tmp==EOF)
	   {
		 break;
	   }
	  if(tmp == ' ')
	   {
		  rs++;
		  if(rs==1)
		   {
		     fputc(' ',temp);
		   }
		  else
		   {

		   }
	   }
	  else
	   {
		rs=0;
		fputc(tmp,temp);
	   }
	}
       coppy();

}
void double_agent_x()                                    // This function removes new lines in raw data file
{
  int rs=0;
      rewind(temp);
      rewind(src);

	while(1)                                                               //Look for new lines, if it occurs twice remove and replace with space
	{
	  tmp = fgetc(src);
	  if(tmp==EOF)
	   {
		 break;
	   }
	  if(tmp == '\n')
	   {
		  rs++;
		  if(rs==1)
		   {
		     fputc('\n',temp);
		   }
		  else
		   {

		   }
	   }
	  else
	   {
		rs=0;
		fputc(tmp,temp);
	   }
	}
       coppy();
}
void agan()                                                               // Function prompts option to execute this program again
{
 printf("\n To continue, press 1:");
 scanf(" %d",&ag);
}
void ite()                                                               //This function can be used, if one has received (Either) only Proximity or thermal sensor data without any guard byte                               
{
 int no=0,nc;
 rewind(src);
 rewind(temp);
 printf("\n Option: \n1. Iteration for Distance Sensor \n2.Iteration for Thermal Sensor\n Enter Choice:");
 scanf("%d",&nc);
 switch(nc)
 {
  case 1:
  {
  while(1)                                       // Does parsing if file contain IR Proximity data (Only)
	{
	  tmp = fgetc(src);
	  if(tmp == EOF)
	   {
		 break;
	   }
	  if(no==16)
	   {
		  fputc('\n',temp);
		  no=0;
	   }
	  else
	   {
	     fputc(tmp,temp);
	   }
	  if(((tmp >= 65) && (tmp <= 90)) || ((tmp >= 48) && (tmp <= 57)))
	   {
	     no++;
	   }

	}
     break;
   }
   case 2:                                        // Does parsing for Thermal Imaging Sensor, includes new line after every 35 byte of data;
   {
    no=0;
    while(1)
	{
	  tmp = fgetc(src);
	  if(tmp == 32)
	   {
	     no++;
	   }
	  if(tmp == EOF)
	   {
	     break;
	   }
	  if(no==35)
	   {
		  fputc('\n',temp);
		  no=0;
	   }
	  else
	   {
	     fputc(tmp,temp);
	   }


	}
     break;
   }
  }
      coppy();
}
void frnt_rem()                                         // This function removes removes data of front IR Proximity Sensor
{
  int no=0;
 rewind(src);
 rewind(temp);
 clr_tmp();
 while(1)
	{
	  tmp = fgetc(src);
	  if(tmp == EOF)
	   {

		break;
	   }
	  if((no==0) || (no==1))
	   {

	   }
	  else if(no==16)
	   {
		  fputc('\n',temp);
		  no=0;
	   }
	  else
	   {
	     fputc(tmp,temp);
	   }
	  if(((tmp >= 65) && (tmp <= 90)) || ((tmp >= 48) && (tmp <= 57)))
	   {
	     no++;
	   }

	}
}
void kloj()                                                // This function closes I/o files
{
  fclose(src);
 fclose(temp);
}
void duriya()                                             // This function calculates IR Proximity Output by calculating Raw input;
{                                                         // This function considers only two proximity sensor data is available
 unsigned int c;
 int chans=0;
 float dist;
 src = fopen(ip, "r");
 printf("\n Enter Traget file name:");
 scanf("%s",op);
 temp = fopen(op, "w");
 if(src == NULL)
  {
   perror("Error:");
  }
 while(fscanf(src,"%x",&c) != EOF)
  {

     chans++;
     if(chans == 1)
      {
	dist =((10.00*((1.00/((0.001240875*(c))+0.005))-0.42)));             //Calculate distance of Objects for 1st proximity sensor
	printf("%d %d\n",c,dist);
	fprintf(temp,"%f",dist/10);
	fprintf(temp,"%c",' ');
      }
     else if(chans == 2)
      {
	dist =((10.00*((1.00/((0.001240875*(c))+0.005))-0.42)));            // Calculate distance of Objects for 1st proximity sensor
	printf("%d %f\n",c,dist/10);
	fprintf(temp,"%.1f",dist/10);
	fprintf(temp,"%c",'\n');

      }
     else if(chans == 7)
      {
	 chans = 0;
      }
  }
}
void calc()                                                 // This function calculates temperature if 35byte of data is provided
{
    unsigned char tpec1;
    int k;
	tptat1 = 256*readbuff1[1] + readbuff1[0];              // Copy 35 byte and group them for 2byte/pixel
     tp1[0] = 256*readbuff1[3] + readbuff1[2];
     tp1[1] = 256*readbuff1[5] + readbuff1[4];
     tp1[2] = 256*readbuff1[7] + readbuff1[6];
     tp1[3] = 256*readbuff1[9] + readbuff1[8];
     tp1[4] = 256*readbuff1[11] + readbuff1[10];
     tp1[5] = 256*readbuff1[13] + readbuff1[12];
     tp1[6] = 256*readbuff1[15] + readbuff1[14];
     tp1[7] = 256*readbuff1[17] + readbuff1[16];
     tp1[8] = 256*readbuff1[19] + readbuff1[18];
     tp1[9] = 256*readbuff1[21] + readbuff1[20];
     tp1[10] = 256*readbuff1[23] + readbuff1[22];
     tp1[11] = 256*readbuff1[25] + readbuff1[24];
     tp1[12] = 256*readbuff1[27] + readbuff1[26];
     tp1[13] = 256*readbuff1[29] + readbuff1[28];
     tp1[14] = 256*readbuff1[31] + readbuff1[30];
     tp1[15] = 256*readbuff1[33] + readbuff1[32];
     tpec1 = readbuff1[34];
	 for(k=0;k<=15;k++)
	 {
       fl1[k] = tp1[k]/10.0;                             // Divide 2byte by 10 get temperature
	 }
	 ft1 = tptat1/10.0;                                 // Calculating Reference temperature



}
void seprt()                                              // This function calculate Proximity Sensor data, Thermal Imaging Data
{                                                         // It considers data has no gaurd byte and 1st five byte is for Proximity sesnor followed by 70byte thermal data;
  FILE *nf1;
  unsigned char readbuff2[35];
  
  unsigned int tp2[16],tptat2;
  float fl2[16],ft2;
  int no=1,seq=1,ind=0,k=0,f;
  unsigned int my_temp;
  char fn[25];
  printf("\nFile Name:");
  scanf("%s",fn);
  nf1 = fopen(fn, "w");
  rewind(src);
  rewind(temp);
  fprintf(nf1,"No.\tS1\tS2\tD1\tD2\tD3\tD4\tD5\tR1\tLT1\tLT2\tLT3\tLT4\tLT5\tLT6\tLT7\tLT8\tLT9\tLT10\tLT11\tLT12\tLT13\tLT14\tLT15\tLT16");
  fprintf(nf1,"\tR2\tRT1\tRT2\tRT3\tRT4\tRT5\tRT6\tRT7\tRT8\tRT9\tRT10\tRT11\tRT12\tRT13\tRT14\tRT15\tRT16");
  while(fscanf(src,"%x",&my_temp) != EOF)
  {

	
	if(seq==1)
	{
	 
	 fprintf(nf1,"\n%d.\t",no);                   //type serial no in file
	 no++;
	 fprintf(nf1,"%d\t",my_temp);
	 seq++;
	}
	else if(seq==2)
	{
	 
	 fprintf(nf1,"%d\t",my_temp);
	 seq++;
	}
	else if ((seq>=3) && (seq<=7))
	{
	 
	 fprintf(nf1,"%.1f\t",(((10.00*((1.00/((0.001240875*(my_temp))+0.005))-0.42))))/10);       //calculate distance
	 seq++;
	}
	else if((seq>=8) && (seq<=42))
	{
	 
	 readbuff1[k] = my_temp;                             // copy thermal sensor data
	 k++;
	 seq++;
	if((seq==43)&&(k==35))
	 {
	   calc();
	   fprintf(nf1,"%.1f\t",ft1);                        
	   for(f=0;f<=15;f++)
	   {
	    fprintf(nf1,"%.1f\t",fl1[f]);               //copy output to file
	   }
	   
	   k=0;
	 }

	}
	else if((seq>=43) && (seq<=77))
	{
	 
	 readbuff2[k] = my_temp;                             // copy another 35byte
	 
	 k++;
	 seq++;
	 if((seq==78)&&(k==35))
	 {
	   
	    tptat2 = 256*readbuff2[1] + readbuff2[0];
	tp2[0] = 256*readbuff2[3] + readbuff2[2];
	tp2[1] = 256*readbuff2[5] + readbuff2[4];
	tp2[2] = 256*readbuff2[7] + readbuff2[6];
	tp2[3] = 256*readbuff2[9] + readbuff2[8];
	tp2[4] = 256*readbuff2[11] + readbuff2[10];
	tp2[5] = 256*readbuff2[13] + readbuff2[12];
	tp2[6] = 256*readbuff2[15] + readbuff2[14];
	tp2[7] = 256*readbuff2[17] + readbuff2[16];
	tp2[8] = 256*readbuff2[19] + readbuff2[18];
	tp2[9] = 256*readbuff2[21] + readbuff2[20];
	    tp2[10] = 256*readbuff2[23] + readbuff2[22];
	tp2[11] = 256*readbuff2[25] + readbuff2[24];
	tp2[12] = 256*readbuff2[27] + readbuff2[26];
	tp2[13] = 256*readbuff2[29] + readbuff2[28];
	tp2[14] = 256*readbuff2[31] + readbuff2[30];
	tp2[15] = 256*readbuff2[33] + readbuff2[32];                  // bring 2byte together for each pixel

	    for(k=0;k<=15;k++)
	   {
	     fl2[k] = tp2[k]/10.0;                                   // calculate temperature
	   }
	   ft2 = tptat1/10.0;

	   
	   fprintf(nf1,"%.1f\t",ft2);
	   
	   for(f=0;f<=15;f++)
	   {
	    fprintf(nf1,"%.1f\t",fl2[f]);                              //write 16 pixel data
		
	   }
	   k=0;
	   seq=1;
	}
      
  }


  }    



}


void usmiya()                                         //This function calculate thermal imaging sensor data
{                                                     // Considers file has only thermal sensor data (Same algorithm used as in previous function)
  unsigned char readbuff[35],op[20];
  unsigned char my_temp;
  unsigned int tp[16],tptat,tpec;
  float fl[16],ft;
  int i=0,j=0,k=0;
  src = fopen(ip, "r");
  printf("\n Enter Target file name:");
  scanf("%s",op);
  oup = fopen(op, "w");
  if((src == NULL)||(oup == NULL))
  {
   perror("Kill yourself!");
  }
  while(fscanf(src,"%x",&my_temp) != EOF)
  {
   if(j < 36)
   {
     readbuff[j]=my_temp;
     printf("%x",readbuff[j]);
     j++;
   }
   if(j == 35)
   {
     printf("levl2");
	 tptat = 256*readbuff[1] + readbuff[0];
	 printf("\n :%d",tptat);
     tp[0] = 256*readbuff[3] + readbuff[2];
     tp[1] = 256*readbuff[5] + readbuff[4];
     tp[2] = 256*readbuff[7] + readbuff[6];
     tp[3] = 256*readbuff[9] + readbuff[8];
     tp[4] = 256*readbuff[11] + readbuff[10];
     tp[5] = 256*readbuff[13] + readbuff[12];
     tp[6] = 256*readbuff[15] + readbuff[14];
     tp[7] = 256*readbuff[17] + readbuff[16];
     tp[8] = 256*readbuff[19] + readbuff[18];
     tp[9] = 256*readbuff[21] + readbuff[20];
     tp[10] = 256*readbuff[23] + readbuff[22];
     tp[11] = 256*readbuff[25] + readbuff[24];
     tp[12] = 256*readbuff[27] + readbuff[26];
     tp[13] = 256*readbuff[29] + readbuff[28];
     tp[14] = 256*readbuff[31] + readbuff[30];
     tp[15] = 256*readbuff[33] + readbuff[32];
     tpec = readbuff[34];
	 for(k=0;k<=15;k++)
	 {
       fl[k] = tp[k]/10.0;
	 }
	 ft = tptat/10.0;
	 fprintf(oup,"\n Reference Temp:%.2f",ft);
	 fprintf(oup,"\n Grid:\n");
	 for(i=0;i<=15;i+=1)
	 {
	   fprintf(oup,"%.2f ",fl[i]);
	   if((i==3)||(i==7)||(i==11)||(i==15))
	   {
	    fprintf(oup,"\n");
	   }
	 }
	 j=0;
   }

 }
  //cleardevice();
  //line(0,0,0,200);
  fclose(oup);
}
void ye_duriya(int fil)                                            // This function read microphone data and writes equivalent integer in file 
{
   char duriya[10],op_nam[35];
   unsigned int tep,count=0;
   long int contg=0,contg1=0;
   FILE *temp11,*duri;
   int i=0,r,j=0,ye=0;
   temp11 = fopen(ip,"r");
   strcpy(op_nam,ip);
   op_nam[3]='s';
   op_nam[4]='o';
   op_nam[5]='u';
   op_nam[6]='n';
   duri = fopen(op_nam,"w");
   printf("\nIp:%s\nRes:%s",ip,op_nam);
   //getch();
   while(fscanf(temp11,"%x",&tep) != EOF)
   {
	  if(i==0)
	  {
	    if(tep == 241)
	    {
	     contg++;
		 ye=1;
	    }
	   else
	   {
	    contg=0;
	   }
	 }
	 
	 if(contg==5)
	 {
	   for(r=1;r<=5;r++)
	   {
	     fscanf(temp11,"%x",&tep);                      // Read Microphone hexadecimal value
	   }
	   for(r=1;r<=5;r++)
	   {
	     fscanf(temp11,"%x",&tep);
	   }
	   i=0;
	   
	 }
	if(j==0)
	  {
	    if(tep == 242)
	    {
	     contg1++;
		 ye=1;
	    }
	   else
	   {
	    contg1=0;
	   }
	 }
	if(contg1==5)
	 {
	   
	   for(r=0;r<=34;r++)
	   {
	     fscanf(temp11,"%x",&tep);
	   }
	   
	   for(r=0;r<=34;r++)
	   {
	     fscanf(temp11,"%x",&tep);
	   }
	   for(r=1;r<=5;r++)
	   {
	     fscanf(temp11,"%x",&tep);
	   }
	   
	  }
	 if(ye==0)
	 {
	    if(tep>50)
	     {
	      fprintf(duri,"%d ",tep);                          // Write equivalent integer
	     }
	    else
	     {
	      fprintf(duri,"125 ");
	     }                          // Write equivalent integer
	    count++;
	    if(count%2 ==0)
	    {
	       fprintf(duri,"\n");
	       count=0;
	    }
	 }
	ye=0;
   }

   fclose(duri);
   fclose(temp11);
}

void ceprt()                                               // This function Calculates distance
{                                                          // Considers 5byte (int)241 is present in file [before and after,(i.e.) 5times 241 5byte proximity sensor data 5times 241]
   char duriya[10];
   unsigned int tep;
   long int contg=0;
   FILE *temp11,*duri;
   int i=0,r;
   printf("\n Enter distance file name:");
   scanf("%s",duriya);
   strcpy(diss,duriya);
   duri = fopen(duriya,"w");
   temp11 = fopen(ip,"r");
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
	   for(r=1;r<=5;r++)
	   {
	     fscanf(temp11,"%x",&tep);
		 fprintf(duri,"%.1f\t",(((10.00*((1.00/((0.001240875*(tep))+0.005))-0.42))))/10);
	   }
	   fprintf(duri,"\n");
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

void writ()                                            //This function generates IR proximity sensor data file (Temporary MS excel file)
{                                                      // For information, this function is executed when user choose 9 in menu.
   char duriya[30];                                    
   float val[8],val1[8],ops[8];
   unsigned int tep;
   long int contg=0;
   FILE *temp11,*duri;
   int i=0,r,cntt=0,arr=1,x;
   printf("\n Generating Avg. File.....");
   stpcpy(duriya,"a.xls");
   strcpy(diss,duriya);
   duri = fopen(duriya,"w");
   temp11 = fopen(ip,"r");
     if(duri == NULL )
	  {
	   perror("\n Src1");
	   getch();
	  }
	  if(temp11 == NULL)
	  {
	   perror("\n temp1");
	   getch();
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
void fis(int re)                                           //This function generates final text file, which is stored in pdata folder
{                                                          // To be noted fopen(-,"w") will delete existing data if executed twice or if file exist
   char duriya[30],valu[10];                               // This function is executed while user choose 9 in menu; This function is written by help of all function written before;
   unsigned int tep;
   float tempe=0.0,su;
   long int contg=0;
   FILE *temp11,*duri,*fi;
   int i=0,r,l,m,len;
   fi = fopen(diss,"r");                              //a.xls IR Proximity Data
   duri = fopen(links[re].resl,"w");
   temp11 = fopen(ip,"r");
   if(duri == NULL )
	  {
	   perror("\n FI");
       getch();
	  }
	  if(temp11 == NULL)
	  {
	   perror("\n IP");
	   getch();
	  }
    if(fi == NULL)
	  {
	   perror("\n AVG");
	   getch();
	  }
   rewind(temp11);
   for(l=0;l<=4;l++)
   {
     fscanf(fi,"%s",&valu);
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
		 readbuff1[r] = tep;
	   }
	   for(l=0;l<=4;l++)
       {
        fscanf(fi,"%s",&valu);
	    if(l!=2)
	    {
          fprintf(duri,"%s\t",valu);	    
	    }
       }
	   calc();
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
		   if(fl1[r]<90.0)
		   {
		     tempe = tempe + fl1[r];
		   }
		  else
		   {
		     tempe = tempe + 30.0;
		   }		 
	   }
	   for(r=9;r<=10;r++)
	   {	     
		   if(fl1[r]<90.0)
		   {
		    tempe = tempe + fl1[r];
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
		 readbuff1[r] = tep;
	   }
	   calc();
	   tempe=0;
	   for(r=5;r<=6;r++)
	   {	     
		   if(fl1[r]<90.0)
		   {
		     tempe = tempe + fl1[r];
		   }
		  else
		   {
		     tempe = tempe + 30.0;
		   }		 
	   }
	   for(r=9;r<=10;r++)
	   {	     
		   if(fl1[r]<90.0)
		   {
		    tempe = tempe + fl1[r];
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
   fi = fopen(diss,"w");
   fclose(fi);
}

int main()                            // Main function
{                                     // Menu explains purpose of functions in place

	int cho,i,si;
	clrscr();
	aga:
	     {

			printf("\n Menu:\n 0: Exit\n 1. Feed Source destination\n 2. Scan file\n 3. Error-full New Line removal");
			printf("\n 4. Prepare Iteration\n 5. Front Sensor Data Removal\n 6. Distance Calculation\n 7. Draw Thermal Grid\n 8. Generate Final file \n 9. Separated Output\n Enter choice:");
			scanf("%d", &cho);
			switch(cho)
			{
			 case 0:
			 {
			   exit(0);
			   break;
			 }
			 case 1:
			 {
				 //src_des();
				 agan();
				 break;
			 }
			 case 2:
			 {
			   open_fil();
			   fil_scan();
			   kloj();
			   agan();
			   break;
			 }
			 case 3:
			 {
				 open_fil();
				 new_lin_spa();
				 kloj();
				 open_fil();
				 double_agnt();
				 kloj();
				 open_fil();
				 double_agent_x();
				 kloj();
				 agan();
				 break;
			 }
			 case 4:
			 {
				 open_fil();
				 ite();
				 kloj();
				 agan();
				 break;
			 }
			 case 5:
			 {
			     open_fil();
			     frnt_rem();
			     kloj();
			     src = fopen(ip, "w");
			     temp = fopen(op, "r+");
			     coppy();
			     kloj();
			     agan();
			     break;
			 }
			 case 6:
			 {

			  duriya();
			  kloj();
			  agan();
			  break;
			 }
			 case 7:
			 {
			    printf("\nlevel1");
				usmiya();
			    kloj();
			    agan();
				break;
			 }
			 case 8:
			 {
			  open_fil();
			  seprt();
			  kloj();
			  agan();
			  break;
			 }
			 case 9:
			 {
			   //printf("\nEnter Scenario No:");
			   //scanf("%d",&si);
			   for(si=1;si<=7;si++)
			   {
			   switch(si)
			   {
			     case 1:
				 {
				   set_links_1();
				   res_links_1();
				   break;
				 }
				 case 2:
				 {
				   set_links_2();
				   res_links_2();
				   break;
				 }
				 case 3:
				 {
				   set_links_3();
				   res_links_3();
				   break;
				 }
				 case 4:
				 {
				   set_links_4();
				   res_links_4();
				   break;
				 }
				 case 5:
				 {
				   set_links_5();
				   res_links_5();
				   break;
				 }
				 case 6:
				 {
				   set_links_6();
				   res_links_6();
				   break;
				 }
				 case 7:
				 {
				   set_links_7();
				   res_links_7();
				   break;
				 }
			   
			   }
			   for(i=0;i<=79;i++)
			   {
			     src_des(i);
			     clr_tmp();
			     printf("\n Scanning file finished....");
                 open_fil();
				 new_lin_spa();
				 kloj();
				 open_fil();
				 double_agnt();
				 kloj();
				 open_fil();
				 double_agent_x();
				 kloj();
				 printf("\n Parsing finished......");
			     //ye_duriya(i);
				 writ();
			     fis(i);                                          // Argument defines result file's link			   
			   }
			   }
			   agan();
			   break;
			 }
			 deafult:
			 {
			  goto aga;
			 }


			}

	     }
 if(ag==1)
 {
	 goto aga;
 }
 getch();
 return 0;
}







