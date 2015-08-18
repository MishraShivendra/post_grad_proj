/** @fil kmedoids
 * This program is used to cluster the given data into various clusters using k-medoids clustering algorithm.
 * Input is the DTW distance matrix.
 * Output is the set of various clusters.
 *
 * @date 15-05-2014
 *
 */
//HEADER FILES
#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//#include<cstdlib.h>
#include<string.h>
#include<errno.h>
//using namespace std;
fstream fil;


// VARIABLE DECLARATIONS
FILE *res;
const int NO_OF_FILES_READ = 70;
int K,path; 				// vale of k in k-medoid
int representative_object[15];
float dtwdist[NO_OF_FILES_READ][NO_OF_FILES_READ];    /* DTW dtwdistance matrix*/
struct links
{
	char ips[35];
}link[8];
struct label
{
	int cluster_no;
	char filename[20];
}trial[70];

void set_links()
{
	strcpy(link[0].ips,"1.xls");
	strcpy(link[1].ips,"2.xls");
	strcpy(link[2].ips,"3.xls");
	strcpy(link[3].ips,"4.xls");
	strcpy(link[4].ips,"5.xls");
	strcpy(link[5].ips,"6.xls");
	strcpy(link[6].ips,"7.xls");
	strcpy(link[7].ips,"8.xls");
}

//FUNCTION DEFINITIONS
void Read_dist_matrix(int l)                    //read dist matrix and write to dtwdist[][]
{
	char ch,temp[30];
	int i, j,count=0,ind=0;
	FILE *in;
	in = fopen(link[l].ips,"r");
	if(!in)
	{
		cerr << strerror(errno);
		cout<<":Opening file!";

	}
	for(i=0;i<=69;i++)
	{
		fscanf(in,"%s",&temp);
	}
	for(i=0;i<=69;i++)
	{
		trial[i].cluster_no = i;
	}
	for(i=0;i<NO_OF_FILES_READ;i++)
	{
		for(j=0;j<NO_OF_FILES_READ;j++)
		{
			if(j==0)
			{
				fscanf(in,"%s",&trial[i].filename);		 
			}

			fscanf(in,"%s",&temp);
			dtwdist[i][j] = atof(temp);      //;

		}
	}
	fclose(in);
	for(i=0;i<=69;i++)
	{
		for(j=0;j<=69;j++)
		{
			//cout<<"\n["<<i<<"]["<<j<<"]:"<<dtwdist[i][j];
			//getch();
		}
	}
}

// This function returns the cluster number of the nearest representative object.
//  
// to the object given as argument. 
int nearest_cluster(int object) 
{
	int i, min_ele=0;
	for (i=0; i<K; i++)
	{
		if (representative_object[i] == object) return i;  // i.e., if object is a representative object
		else if (dtwdist[object][representative_object[i]] < dtwdist[object][representative_object[min_ele]])	
			min_ele = i;
	}
	return min_ele;
}

// Select a new representative object randomly. 
// Make sure that the object selected is not already a representative object. 
// Function returns the index of the new 
int new_random_object()
{
	int ele, i;
	int  unique; 
	do                                                                                                         
	{  
		unique = 1;
		ele = rand() % NO_OF_FILES_READ;          // select a new rep object randomly

		for (i=0; i<K; i++)
		{
			if (ele == representative_object[i])   // new rep object must be one of the current non rep objects
			{
				unique = 0;
				break;
			}
		}
	}
	while (unique==0);
	return ele;
}

// This function selects a random set of initial representative objects
// Function return the sum of distances between an object and its representative object.
float initialise_clusters()
{
	int i, cluster;
	float  total_dist = 0.0;   

	for (i=0; i<K; i++)
		representative_object[i]= new_random_object();

	for (i=0; i< NO_OF_FILES_READ; i++)
		total_dist = total_dist + dtwdist[i][representative_object[nearest_cluster(i)]];

	return total_dist;
}
void open_res()
{
	res = fopen("res.xls","w");
}

// This function displays  memebrs of the current set of clusters.
void display_clusters()
{
	int i, cluster, rep_object;
	for (i=0; i< NO_OF_FILES_READ; i++)
	{
		trial[i].cluster_no = nearest_cluster(i);
	}
	for (cluster=0; cluster<K; cluster++)
	{

		fprintf(res,"\n\nCluster %d:\t",cluster);
		for (i=0; i< NO_OF_FILES_READ; i++)
		{
			if (trial[i].cluster_no == cluster)
			{
				fprintf(res,"%s\t",trial[i].filename);
			}
		}
	}
}

// This function implements the kmedoid algorithm.

void form_cluster(int f)
{
	int i, epoch, cluster, old_rep_object;
	float total_dist, new_dist;
	int changed;
	fprintf(res,"\n\n\n\t\t\t\t\t\t\t\tPath:%d\n",path);
	set_links();
	Read_dist_matrix(f);                          // Read the DTW matrix from file

	total_dist = initialise_clusters();		// Find the cumulative distance of initial cluster set
	fprintf(res,"\nInitial cluster distance is:%.1f\n",total_dist);     // Cluster reformation is iterated 200 times.
	for (epoch=0; epoch < 200; epoch ++)
	{
		changed = 0;
		for (cluster=0; cluster < K; cluster++)
		{
			for (i=0; i<NO_OF_FILES_READ; i++)
			{
				new_dist = 0.0;
				old_rep_object = representative_object[cluster];
				representative_object[cluster]= new_random_object();

				for (i=0; i< NO_OF_FILES_READ; i++)
					new_dist = new_dist + dtwdist[i][representative_object[nearest_cluster(i)]];
				if (new_dist < total_dist)
				{
					total_dist = new_dist;
					changed = 1;
					break;
				}
				else representative_object[cluster] = old_rep_object;
			}
		}
		if (changed == 1)
		{
			fprintf(res,"\nEPOCH Number:%d\n",epoch);
			fprintf(res,"\nTotal distance is:%.1f\n",total_dist);
			//		display_clusters();
		}
	}
	display_clusters();
}

int main()
{
	int ag=1;
	open_res();
	do{
		clrscr();
		cout<<"\nEnter number of Cluster(K):";
		cin>>K;
		for(path=0;path<=7;path++)
		{
			form_cluster(path);
			cout<<"\nCalculating Path:"<<path;	
		}  
		cout<<"\nTo continue,Press1:";
		cin>>ag;
	}while(ag==1);
	fclose(res);
	getch();  

	return 0;

}

