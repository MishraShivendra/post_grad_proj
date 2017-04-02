/*
 * File: pre_process.c
 * Created on: Dec 1, 2013; 01:08:35 AM 
 * Author: Shivendra Mishra
 * Geany v4.5 (UNICODE)
 * 
 *
 *
 * Environment: Geany with gcc (Only on linux)
 * Input: Hex file from system file ./data/SCx_/Sx_Sy/Sx_Sy_t.txt      
 * Where x,y are path directions and t is trial.
 * Output: Pre-Processed data (16 Attributes = 4(IR Proximity Sensor) 
 * + 32(MEMS Thermal Imaging Sensor ))
 * Execution: Execute and choose 9 from Menu; If it is required to 
 * process step by step choose accordingly from menu.
 */

#include "pre_processing_multi.h"





void 
feed_links ( const char *link ) 
{
	static int scenario_one_iterator = 0;
	static int scenario_two_iterator = 0;
	static int scenario_three_iterator = 0;
	static int scenario_four_iterator = 0;
	static int scenario_five_iterator = 0;
	static int scenario_six_iterator = 0;
	static int scenario_seven_iterator = 0;
	static int result_one_iterator = 0;
	static int result_two_iterator = 0;
	static int result_three_iterator = 0;
	static int result_four_iterator = 0;
	static int result_five_iterator = 0;
	static int result_six_iterator = 0;
	static int result_seven_iterator = 0;


	if (    (scenario_one_iterator > TOTAL_TRIALS) || 
		(scenario_two_iterator > TOTAL_TRIALS) || 
		(scenario_three_iterator > TOTAL_TRIALS) || 
		(scenario_four_iterator > TOTAL_TRIALS) || 
		(scenario_five_iterator > TOTAL_TRIALS) || 
		(scenario_six_iterator > TOTAL_TRIALS) || 
		(scenario_seven_iterator > TOTAL_TRIALS) ) {
		fprintf ( stderr, "\nInvalid entries in directory.\n" );
		exit(EXIT_FAILURE);	
	}
	if (    (result_one_iterator > TOTAL_TRIALS) || 
		(result_two_iterator > TOTAL_TRIALS) || 
		(result_three_iterator > TOTAL_TRIALS) || 
		(result_four_iterator > TOTAL_TRIALS) || 
		(result_five_iterator > TOTAL_TRIALS) || 
		(result_six_iterator > TOTAL_TRIALS) || 
		(result_seven_iterator > TOTAL_TRIALS) ) {
		fprintf ( stderr, "\nres Invalid entries in result"\
				  " directory.\n" );
		exit(EXIT_FAILURE);	
	}
#ifdef DEBUG
	printf ( "link:%s\n",link==NULL?"null":link );
#endif
	if ( strstr( link, "SC_1" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_1][scenario_one_iterator].ip=strdup(link);
			scenario_one_iterator++;
		} else {
			links[SCENARIO_1][result_one_iterator].resl=strdup(link);
			result_one_iterator++;	
		}
	}else if ( strstr( link, "SC_2" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_2][scenario_two_iterator].ip=strdup(link);
			scenario_two_iterator++;
		}else {
			links[SCENARIO_2][result_two_iterator].resl=strdup(link);
			result_two_iterator++;	
		}
	}else if ( strstr( link, "SC_3" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_3][scenario_three_iterator].ip=strdup(link);
			scenario_three_iterator++;
		} else {
			links[SCENARIO_3][result_three_iterator].resl=strdup(link);
			result_three_iterator++;

		}
	}else if ( strstr( link, "SC_4" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_4][scenario_four_iterator].ip=strdup(link);
			scenario_four_iterator++;
		} else {
			links[SCENARIO_4][result_four_iterator].resl=strdup(link);
			result_four_iterator++;	
		}
	}else if ( strstr( link, "SC_5" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_5][scenario_five_iterator].ip=strdup(link);
			scenario_five_iterator++;
		}else {
			links[SCENARIO_5][result_five_iterator].resl=strdup(link);
			result_five_iterator++;	
		}
	}else if ( strstr( link, "SC_6" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_6][scenario_six_iterator].ip=strdup(link);
			scenario_six_iterator++;
		} else {
			links[SCENARIO_6][result_six_iterator].resl=strdup(link);
			result_six_iterator++;	
		}
	}else if ( strstr( link, "SC_7" ) != NULL ) {
		if ( is_input_file ) {
			links[SCENARIO_7][scenario_seven_iterator].ip=strdup(link);
			scenario_seven_iterator++;
		} else {
			links[SCENARIO_7][result_seven_iterator].resl=strdup(link);
			result_seven_iterator++;		
		}
	}else {
#ifdef DEBUG
		printf ( "Link: %s\n",link );
#endif
		fprintf ( stderr, "\n Invalid entries in directory.\n");
		exit(EXIT_FAILURE);
	} 	
#ifdef DEBUG
	printf ( "\nentries in directory.%d %d %d %d %d %d %d\n",
	 			scenario_three_iterator, scenario_one_iterator, 
				scenario_two_iterator, scenario_four_iterator, 
				scenario_five_iterator, scenario_six_iterator,
				scenario_seven_iterator );
#endif

}



int 
print_entry(const char *filepath, const struct stat *info,
		const int typeflag, struct FTW *pathinfo)
{
	static int scenario_iterator=0;
	static int trial_iterator=0;

	if (typeflag == FTW_SL) {
		char   *target;
		size_t  maxlen = 1023;
		ssize_t len;

		while (1) {

			target = malloc(maxlen + 1);
			if (target == NULL)
				return ENOMEM;

			len = readlink(filepath, target, maxlen);
			if (len == (ssize_t)-1) {
				const int saved_errno = errno;
				free(target);
				return saved_errno;
			}
			if (len >= (ssize_t)maxlen) {
				free(target);
				maxlen += 1024;
				continue;
			}

			target[len] = '\0';
			break;
		}

		printf(" %s -> %s\n", filepath, target);
		free(target);

	} else
		if (typeflag == FTW_SLN) {

			fprintf(stderr, " %s (dangling symlink)\n", filepath);
		}else
			if (typeflag == FTW_F){
				feed_links( filepath );
			}
	return 0;
}


int 
print_directory_tree(const char *const dirpath)
{
	int result;

	/* Invalid directory path? */
	if (dirpath == NULL || *dirpath == '\0')
		return errno = EINVAL;

	result = nftw(dirpath, print_entry, USE_FDS, FTW_PHYS);
	if (result >= 0)
		errno = result;

	return errno;
}




void 
feed_io_file_to_struct(int sc, int no)    /* Set source destination file   
					     (Argument is file no range 
					     between 0-69)*/       
{
	strncpy(ip[sc],links[sc][no].ip,strlen(links[sc][no].ip));
	ip[sc][strlen(links[sc][no].ip)] = '\0';
#ifdef DEBUG
	printf("\nLink:%s",ip[sc]);
#endif
	switch(sc)
	{
		case 0:
			strncpy(op[sc],"t_0.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break;
		case 1:
			strncpy(op[sc],"t_1.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break; 
		case 2:
			strncpy(op[sc],"t_2.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break;  	
		case 3:
			strncpy(op[sc],"t_3.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break;
		case 4:
			strncpy(op[sc],"t_4.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break;
		case 5:
			strncpy(op[sc],"t_5.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break;
		case 6:
			strncpy(op[sc],"t_6.txt",7);
			op[sc][NO_OF_SCENARIOS] = '\0';
			break;
	}
#ifdef DEBUG
	printf("\nsetting Link[%d]:%s op %s \n",sc, ip[sc], op[sc]);
#endif
}

	
void 
open_data_file(int sc)				/* open file*/
{
#ifdef DEBUG

	printf ( "opening[%d]:%s op:%s\n",sc,ip[sc],op[sc]);
#endif
	src[sc] = fopen(ip[sc], "r+");			/* Open I/O file */
	if(src[sc] == NULL )				/* Notify Error */
	{
		perror(ip[sc]==NULL?"ip NULL":ip[sc]);
	}
	temp[sc] = fopen(op[sc], "r+");

	if(temp[sc] == NULL)
	{
		perror(op[sc]==NULL?"op NULL":op[sc]);
	}
}


void 
clear_temp_file(int sc)		/* Clear temp file (proximity sensor data) */
{
	temp[sc] = fopen(op[sc],"w");                                           
	fclose(temp[sc]);
}

void 
write_back_from_temp(int sc)			    /* Copy data from temp 
						       file to raw data file */
{						    /* This function is used 
						       while removing redundant 
						       new lines/spaces in raw 
						       data file */
	rewind(temp[sc]);
	fclose(src[sc]);
	src[sc] = fopen(ip[sc], "w");
	if ( src[sc] == NULL ) {
		perror( ip[sc] );
	}
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

	
	
void 
remove_new_lines(int sc)                           /* removes unwanted 
						      new line and replaces 
						      with space */
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

		if(no == 2)				/* replacing new lines 
							   with spaces*/
		{
			fputc(' ',temp[sc]);
			no =0;
		}
		else
		{
			fputc(tmp[sc],temp[sc]);
		}
		/* If they were hex char than no++ - 
		 * sorry for magic numbers*/
		if(((tmp[sc] >= 65) && (tmp[sc] <= 90)) || 
		   ((tmp[sc] >= 48) && (tmp[sc] <= 57)))
		{
			no++;
		}
	}
	write_back_from_temp(sc);

}
void 
remove_spaces_from_file(int sc)		/* This function removes 
					   redundant spaces in file */
{
	int rs=0;
	rewind(temp[sc]);
	rewind(src[sc]);

	while(1)			/* removing redundant spaces */
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
	write_back_from_temp(sc);

}

void 
remove_trailing_new_lines(int sc)		/* This function removes new 
						   lines in raw data file */
{
	int rs=0;
	rewind(temp[sc]);
	rewind(src[sc]);

	while(1)				/* Look for new lines, 
						   if it occurs twice remove 
						   and replace with space*/
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
	write_back_from_temp(sc);
}

void 
continue_dialog_prompt()			/* Function prompts option 
						   to execute this program 
						   again */
{
	printf("\n To continue, press 1:");
	scanf(" %d",&ag);
}

void 
close_data_file(int sc)				        /* This function closes 
							   I/o files */
{
	fclose(src[sc]);
	fclose(temp[sc]);
}  

void 
process_thermal_image(int sc)			    /* This function calculates 
						       temperature if 35byte of 
						       data is provided */
{
	unsigned char tpec1;
	unsigned int tp1[THERMAL_IMAGE_RESO],tptat1;  
	int k;
	int pixel=0;
	int buffer_iterator=2;
	tptat1 = 256*readbuff1[sc][1] + readbuff1[sc][0];	
	/* why magic number 256? 
	 * Copy 35 byte and group 
	 * them for 2byte/pixel 
	 */
	for ( pixel=0; pixel<=THERMAL_IMAGE_RESO; pixel++ ) {
		tp1[pixel] = 256*readbuff1[sc][buffer_iterator+1] + 
			     readbuff1[sc][buffer_iterator];
		buffer_iterator = buffer_iterator + 2;
	}

	tpec1 = readbuff1[sc][34];
	/* Why magic number 10.0?
	 * well, Because sensor sends 
	 * data in this format. So that
	 * we can get more accuracy.
	 */
	for(k=0;k<=THERMAL_IMAGE_RESO;k++)
	{
		fl1[sc][k] = tp1[k]/10.0;		/* Divide 2byte by 10 
							   get temperature */
	}
	/* ft1 = tptat1/10.0;
	 * Calculating Reference 
	 * temperature
	 */

}   



/* This function generates 
 * IR proximity sensor data 
 * file (Temporary MS excel file)
 * For information, this function 
 * is executed when user choose 9 
 * in menu.
 */
void 
process_proximity_sensor_data(int sc) 
{
	char duriya[30];                                    
	float val[8],val1[8],ops[8];
	unsigned int tep;
	long int contg=0;
	FILE *temp11,*duri;
	int i=0,r,cntt=0,arr=1,x;
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

	strncpy(diss[sc],duriya,NO_OF_SCENARIOS);
	duri = fopen(duriya,"w");
	temp11 = fopen(ip[sc],"r");
	if(duri == NULL )
	{
		perror("\n Src1");
	}
	if(temp11 == NULL)
	{
		perror("\n temp1");
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
					/* Magic numbers adopted from 
					 * the data sheet of proximity sensor */
					val[r] = (((10.00*((1.00/((0.001240875*
						  (tep))+0.005))-0.42))))/10;
					if(r==4)
					{
						arr++;
					}
				}
				else if(arr==2)
				{
					val1[r] = (((10.00*((1.00/((0.001240875*
						  (tep))+0.005))-0.42))))/10;
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
					ops[x] = val[x];
					/* For averaging replace 
					 * it with ops[x] = 
					 * (val[x] + val1[x])/2;
					 */
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

/* This function generates final text file, which 
 * is stored in pdata folder. To be noted fopen(-,"w") 
 * will delete existing data if executed twice or if file 
 * exist.This function is executed while user choose 9 
 * in menu. This function is written by help of 
 * all function written before;
 */
void 
write_processed_data_to_file(int sc, int re)                                    
{   
	char duriya[30],valu[10];
	unsigned int tep;
	float tempe=0.0,su;
	long int contg=0;
	FILE *temp11,*duri,*fi;
	int i=0,r,l,m,len;
	fi = fopen(diss[sc],"r");

	/* a.xls is IR Proximity Data */

	duri = fopen(links[sc][re].resl,"w");
	temp11 = fopen(ip[sc],"r");
	if(duri == NULL )
	{
		perror("\n FI");
	}
	if(temp11 == NULL)
	{
		perror("\n IP");
	}
	if(fi == NULL)
	{
		perror("\n AVG");
	}
	rewind(temp11);
	for(l=0;l<=4;l++)
	{
		fscanf(fi,"%s",valu);
		if(l!=2) {
			fprintf(duri,"%s\t",valu);
		}
	}
	fprintf(duri,"L\tR\n");
	while(fscanf(temp11,"%x",&tep) != EOF)
	{
		if(i==0) {
			if(tep == 242) {
				contg++;
			}
			else {
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
			process_thermal_image(sc);
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
			fprintf(duri,"%.1f\t",(tempe/4.0));
			for(r=0;r<=34;r++)
			{
				fscanf(temp11,"%x",&tep);
				readbuff1[sc][r] = tep;
			}
			process_thermal_image(sc);
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

			for(r=1;r<=5;r++)
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



/* Following function sets
 * the link for input/output
 * files.
 */
void 
prcoess_raw_data_files(void *sce)
{
	int i, sc = *((int*)sce);
#ifdef MANUAL_DIR
	/* Not required anymore - posix library does the job.*/
	   switch(si)
	   {
	   case 0:
	   {
	   set_links_1();
	   res_links_1();
	   break;
	   }
	   case 1:
	   {
	   set_links_2();
	   res_links_2();
	   break;
	   }
	   case 2:
	   {
	   set_links_3();
	   res_links_3();
	   break;
	   }
	   case 3:
	   {
	   set_links_4();
	   res_links_4();
	   break;
	   }
	   case 4:
	   {
	   set_links_5();
	   res_links_5();
	   break;
	   }
	   case 5:
	   {
	   set_links_6();
	   res_links_6();
	   break;
	   }
	   case 6:
	   {
	   set_links_7();
	   res_links_7();
	   break;
	   }
	   }
#endif


	for(i=0;i<TOTAL_TRIALS;i++)
	{

		feed_io_file_to_struct(sc,i);
		clear_temp_file(sc);
		open_data_file(sc);
		remove_new_lines(sc);
		close_data_file(sc);
		open_data_file(sc);
		remove_spaces_from_file(sc);
		close_data_file(sc);
		open_data_file(sc);
		remove_trailing_new_lines(sc);
		close_data_file(sc);
		process_proximity_sensor_data(sc);
		write_processed_data_to_file(sc,i);
		/* Argument defines 
		 * result file's link
		 */
		pthread_mutex_lock(&my_lock);
		prec++;
		pthread_mutex_unlock(&my_lock);		   
	}
	pthread_exit(0);
}

/* Following function
 * prints the status of 
 * pre-processed files
 * at the moment.
 */
void 
show_processing_status()
{
	int completed_flag = 0, cur;
	float dev;
	while(1)
	{
		cur = prec;
		/* Why magic number 559 and 100?
		 * Well, for showing percentage status, 
		 * I am multiplying 100 to it. And 559 is 
		 * the total number of files. 
		 * i.e. NO_OF_SCENARIOS X number of trials on each 
		 * path x Number of paths = 560 
		 */
		dev = ((float)cur/559)*100;
#ifdef DEBUG
		printf("\r%.2f%% files Pre-Processed......",dev);
#endif
		fflush(stdout);
		if(prec==560)
		{
			completed_flag = 1;
			break;	
		}
	}
	if( completed_flag ) {
		pthread_exit(0);
	}
}

/* Following function
 * removes the temporary 
 * files.
 */
void 
remove_temp_files()
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

void
show_help () {
	printf ( "\nMulti-threaded Preprocessing options:\n" );
	printf ( "-h, --help         Show this help and exit.\n" );
	printf ( "-r, --result-file  Excepts result file locations.\n");
	printf ( "-i, --input-file   Expects input file locations.\n" );
}


int 
main( int argc, char *argv[])
{

	int i,j;
	char thread_err[10];
	pthread_t th[8];
	int *argument[NO_OF_SCENARIOS];
	int option = 0;
	char *result_file_dir = NULL;
	char *input_file_dir = NULL;
	const char *short_option = "r:i:h";
	struct option long_options[] = {
		{"result-file", 1, NULL, 'r'},
		{"input-file",  1, NULL, 'i'},
		{"help",        0, NULL, 'h'},
		{NULL,          0, NULL,  0}
	};
	while ( (option = getopt_long( argc, argv, short_option, 
					long_options, NULL ) )> 0 ) {
		switch ( option ) {
			case 'r':
				result_file_dir = optarg;
				break;
			case 'i':
				input_file_dir = optarg;
				break;
			case 'h':
				show_help();
				break;
			case ':':
				printf ( "Argument missing." );
				exit(0);
			case '?':
				printf ( "\nInvalid option:%c\n",(char)option ) ;
				exit(0);
		} 
	}
	if ( (result_file_dir == NULL) || ( input_file_dir == NULL ) ) {
		fprintf ( stderr, "\nInput file and result file directories "\
			 "are required.\n" );
		exit(EXIT_FAILURE);
	}
	print_directory_tree( input_file_dir );
#ifdef DEBUG
	printf( "Printed input dir tree \n" );
#endif
	is_input_file = 0;
	print_directory_tree( result_file_dir );
	for ( i=0; i<NO_OF_SCENARIOS; i++ ) {
		for( j=0; j<TOTAL_TRIALS;j++) {
			printf ( "ip[%d][%d]:%s op:%s\n ",
						i,j,links[i][j].ip, 
					  	links[i][j].resl );
		}
	}
	printf("\e[?25l");		/* hide the cursor */

	i = NO_OF_SCENARIOS;
	if(pthread_create(&th[i],NULL,(void *)&show_processing_status,NULL))
	{
		sprintf(thread_err,"create[%d]",i);
		perror(thread_err);
	}
	//prcoess_raw_data_files(0);

	for(i=0;i<=0;i++)
	{
		argument[i] = (int*) malloc( sizeof(int));
		*argument[i] = i;
		if(pthread_create(&th[i],NULL,(void *)&prcoess_raw_data_files,
								argument[i])){
			sprintf(thread_err,"create[%d]",i);
			perror(thread_err);
		}
	}
	for(i=0;i<=0;i++)
	{
		if(pthread_join(th[i],NULL))
		{
			sprintf(thread_err,"Join[%d]",i);
			perror(thread_err);
		}
	}
	i=NO_OF_SCENARIOS;
	if(pthread_join(th[i],NULL))
	{
		sprintf(thread_err,"Join[%d]",i);
		perror(thread_err);
	}
	remove_temp_files();

	printf("\n");
	/* show the cursor */
	printf("\e[?25h");
	for ( i=0; i<1;i++) {
		free(argument[i]);
	}
	return EXIT_SUCCESS;
}
