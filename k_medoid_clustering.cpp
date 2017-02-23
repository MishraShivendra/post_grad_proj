#include "a.h"

k_med_clust::k_med_clust( void )
{
	cout<<"Enter value for K:"<<endl;
	cin>>K;
}

k_med_clust::~k_med_clust( void )
{

}


// This function returns the cluster number 
// of the nearest representative object to 
// the object given as argument.
//
int k_med_clust::nearest_cluster( int object ) 
{
	int i, min_ele=0;
	for (i=0; i<K; i++) {
		if (representative_object[i] == object) { 
			return i;
		//i.e., if object is a representative object	
		}else if ( distance_matrix[object][representative_object[i]] < 
			   distance_matrix[object][
			   representative_object[min_ele]] ) {
			min_ele = i;
		}
	}
	return min_ele;
}

// Select a new representative object randomly.
// Make sure that the object selected is not already 
// a representative object. Function returns
// the index of the new.
//
int k_med_clust::new_random_object( void )
{
	int ele, i;
	int  unique; 
	srand(time(NULL));
	do{  
		unique = 1;
		// select a new rep object randomly
		ele = rand() % matrix_len;
		for (i=0; i<K; i++) {
			 // new rep object must be
			 // one of the current non rep
			 // objects.
			if (ele == representative_object[i]) {
				unique = 0;
				break;
			}
		}
	}while (unique==0);
	return ele;
}

// This function selects a random set of initial 
// representative objects.Function return the sum 
// of distances between an object and its representative 
// object.
//
float k_med_clust::initialise_clusters( void )
{
	int i, cluster;
	float  total_dist = 0.0;   

	for (i=0; i<K; i++) {
		representative_object[i]= new_random_object();
	}

	for (i=0; i< matrix_len; i++) {
		total_dist = total_dist + 
			     distance_matrix[i][representative_object
			     [nearest_cluster(i)]];
	}
	return total_dist;
}


// This function displays  members of the 
// current set of clusters.
//
void k_med_clust::display_clusters( void )
{
	int i, cluster, rep_object;
	for (i=0; i< matrix_len; i++) {
		label_no.at(i) = nearest_cluster(i);
	}
	for (cluster=0; cluster<K; cluster++) {
		cout<<"Cluster:"<<cluster;
		for (i=0; i< matrix_len; i++) {
			if ( label_no.at(i) == cluster ) {
				cout<<matrix_label.at(i);
			}
		}
	}
}

// This function implements the kmedoid algorithm. 
void k_med_clust::form_cluster( string dist_matrix_file )
{
	int i, epoch, cluster, old_rep_object;
	float total_dist, new_dist;
	int changed;
	cout<<"Distance Matrix:"<<dist_matrix_file<<endl;

	// Find the cumulative distance of initial cluster set
	total_dist = initialise_clusters();
	// Cluster reformation is iterated 200 times.
	cout<<"Initial cluster distance is:"<<total_dist;     
	for (epoch=0; epoch < 200; epoch ++) {
		changed = 0;
		for (cluster=0; cluster < K; cluster++) {
			for (i=0; i<matrix_len; i++) {
				new_dist = 0.0;
				old_rep_object = representative_object[cluster];
				representative_object[cluster] = 
							    new_random_object();

				for (i=0; i< matrix_len; i++) {
					new_dist = new_dist + distance_matrix[i][
						   representative_object[
						   nearest_cluster(i)]];
				}
				if (new_dist < total_dist) {
					total_dist = new_dist;
					changed = 1;
					break;
				} else{ 
					representative_object[cluster] = 
								old_rep_object;
				}
			}
		}
		if (changed == 1) {
			cout<<"EPOCH Number:"<<epoch<<endl;
			cout<<"Total distance is:"<<total_dist<<endl;
			// In case I just want to display results.
		}
	}
#ifdef DISPLAY
	display_clusters();
#endif
}


// Loops through the dist matrix files 
// given in conf_file and shows clustering result.
void k_med_clust::create_cluster( void ) 
{
	string conf_file = "clust.conf";
	conf_read_load_filename(conf_file);
	
	for( int i = 0; i<files.size(); i++ ) {
		load_label_from_file( files.at(i) );
		load_dist_matrix( files.at(i) );
#ifdef DEBUG
		print_dist_matrix();
#endif
		form_cluster( files.at(i) );
		distance_matrix.clear();
		matrix_label.clear();
		label_no.clear();
	}	
}


// Loads labels of a distance matrix (from file) to
// a vector.
void k_med_clust::load_label_from_file( string& dist_matrix_file )
{
	ifstream matrix_reader( dist_matrix_file );
	string labels;
	getline( matrix_reader, labels );
	matrix_reader.close();
	
	istringstream label_iss( labels );
	string slabel;
	while( label_iss >> slabel ) {
		matrix_label.push_back(slabel); 
	}
	for( int i = 0; i<matrix_len; i++ ) {
		label_no.push_back(i);
	}
#ifdef DEBUG
	cout<<"List of labels:"<<endl;
	for( vector<string>::iterator i = matrix_label.begin(); 
	     i!=matrix_label.end(); ++i ) {
		cout<<*i<<endl;
	}
#endif
}

// Print the loaded distance matrix 
// meant for debugging purpose.
void k_med_clust::print_dist_matrix( void ) 
{
	cout<<"size:"<<distance_matrix.size()<<endl;
	for( int i = 0; i< distance_matrix.size(); ++i ) {
		for( int j = 0; j<distance_matrix[i].size(); ++j ) {
			if( j == 0 ) {
			}
			cout<<distance_matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}


// Loads whole distance matrix from file to 
// a 2D matrix.
// Input: A file containing distance matrix.
void k_med_clust::load_dist_matrix( string& dist_matrix_file )
{
	ifstream matrix_reader( dist_matrix_file );
	string matrix_row;
	getline( matrix_reader, matrix_row );
	istringstream row_parse( matrix_row );
	//Read by row
	while( getline( matrix_reader, matrix_row ) ) {
		vector<int> row;
		int element;
		stringstream temp_ss;
		temp_ss << matrix_row;
		string temp;
		// Ignore the label column and push rest of the
		// values into vector.
		while( getline( temp_ss, temp, ' ') ) {
			if( stringstream(temp) >> element ) {
				row.push_back( element );	
			}
		}
		distance_matrix.push_back( row );
	}
	matrix_reader.close();
	matrix_len = distance_matrix.size();
}


// Reads a conf file with list of file names
// and pushes those file names into a string vector.
// Input: Conf file location
void k_med_clust::conf_read_load_filename( string& file_list )
{
	ifstream conf_reader( file_list );
	string line;
	while( getline( conf_reader, line ) ) {
		files.push_back( line );	
	}
	conf_reader.close();
#ifdef DEBUG
	cout<<"List of distance matrix Files:"<<endl;
	for( vector<string>::iterator i = files.begin(); i!=files.end(); ++i) {
		cout<<*i<<endl;
	}
#endif
}


int main( void )
{
	k_med_clust kmc;
	kmc.create_cluster();
	return 0;
}
