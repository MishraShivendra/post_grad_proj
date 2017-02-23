#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

class k_med_clust {
		int representative_object[15];
		int K;
		int matrix_len;
		int cluster_no;
		vector<int> label_no;
		vector<string> files;
		vector<string> matrix_label;
		vector< vector<int> > distance_matrix;
	public:	
		k_med_clust( void );
		~k_med_clust( void );
		void conf_read_load_filename(string& file_list);
		void load_label_from_file( string& dist_matrix_file );
		void load_dist_matrix( string& dist_matrix_file );
		void print_dist_matrix( void );
		void create_cluster( void );
		int nearest_cluster( int object );
		int new_random_object( void );
		float initialise_clusters( void );
		void display_clusters( void );
		void form_cluster( string dist_matrix_file );
};
