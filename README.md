#Acquisition and Analysis of Robotic Environment Data Using Machine Learning Techniques

####Abstract:
This project implements system for analysis and detection of objects in experimental robotic environment. For reference, the elementary work for this project consists of recording time series data from three long range IR distance sensors and five short range IR distance sensor. The robot was programed to record data at static sampling rate; while running on a straight path. This data goes through feature extraction and Pre-processing. And finally, the distance of the object from robotic path is obtained from left and right sensor; which is a time series stream data.

  In the implementation point of view; system is mainly having two modules. The First module consists of data recorded from the sensors. These sensors include of IR distance sensor, PIR thermal imaging Sensor, and Microphones. The time series spatial data of IR distance sensor is obtained by the help of ADC. Whereas, PIR Thermal Imaging Sensor is interfaced with the robot using the I2C bus switch; which is connected through the Two Wire Interface (TWI) of robot’s microcontroller. It has been planned to use Omron D6T-44L thermal Imaging Senor in both side of robot; which has 4x4 resolution with range of 2-3m (45° angle) and meets compatibility requirements. In case of microphone, two electret microphones are interfaced to ADC by the help of OPA344 based amplifier circuit. The spatial data received from ADC goes through FFT algorithm written in C, to obtain a time series stream of frequency distribution from audio signal.
        
  In the second module; a set of different experimental scenarios are designed; which includes of heat sources, different dummy shapes and sound sources kept around the robot path. Robot is programmed to run on an even, straight path with a constant speed to record time series data with 2 samples/second/sensor rate. Time Series Data obtained through these three sources goes for different phases of data mining algorithms. These phases includes of feature extraction, Pre-processing, and Clustering; which finally goes through a validation phase of result accuracy over the outcomes obtained. 

####First Module - Code
- [Repo for thermal imaging sensor](https://github.com/MishraShivendra/D6T_44L)

####Phases of second module:

|**No.**| **Operation**                             |  **File name**                                           |
|-------|-------------------------------------------|----------------------------------------------------------|
|1. |Pre-processing of raw hexadecimal data     |  [pre_processing.c](https://github.com/MishraShivendra/post_grad_proj/blob/master/pre_processing.c), [pre_processing_multi.c](https://github.com/MishraShivendra/post_grad_proj/blob/master/pre_processing_multi.c), [chk_xl.m](https://github.com/MishraShivendra/post_grad_proj/blob/master/chk_xl.m), [col_rd.m](https://github.com/MishraShivendra/post_grad_proj/blob/master/col_rd.m), [file1_read.m](https://github.com/MishraShivendra/post_grad_proj/blob/master/file1_read.m), [file_read.m](https://github.com/MishraShivendra/post_grad_proj/blob/master/file_read.m), [find_nol.m](https://github.com/MishraShivendra/post_grad_proj/blob/master/find_nol.m), [pro_all.m](https://github.com/MishraShivendra/post_grad_proj/blob/master/pro_all.m)|
|2.|Feature Extraction                         |  [pre_processing.c](https://github.com/MishraShivendra/post_grad_proj/blob/master/pre_processing.c), [pre_processing_multi.c](https://github.com/MishraShivendra/post_grad_proj/blob/master/pre_processing_multi.c)|
|3.|Distance calculation                       |  [manhattan_distance_matrix.c](https://github.com/MishraShivendra/post_grad_proj/blob/master/manhattan_distance_matrix.c), [multi_manhattan_distance.c](https://github.com/MishraShivendra/post_grad_proj/blob/master/multi_manhattan_distance.c) |
|4.|Clustering                                 |  [k_medoid_clustering.cpp](https://github.com/MishraShivendra/post_grad_proj/blob/master/k_medoid_clustering.cpp)                                 |

####How to Compile
If you want to do frequencey analysis of audio samples, then open/run the *.m files written in the pre-processing row (in Matlab 2011a). pre_processing_multi.c file is to be used for pre-processing thermal imaging/proximity sensor data.
```bash
$ svn co https://github.com/MishraShivendra/post_grad_proj.git
```
Compile the pre-processor:
```bash
$ cd post_grad_proj.git/trunk 
$ gcc -pthread pre_processing_multi.c -o pre_processor
$ # See the pre-processor options
$ ./pre_processor -h

Multi-threaded Preprocessing options:
-h, --help         Show this help and exit.
-r, --result-file  Excepts result file locations.
-i, --input-file   Expects input file locations.

Input file and result file directories are required.
$ # Prepare a directory for processed data
$ cp -r ./data/ ./processed_data
$ #wait for pre_processor to be 100%
$ ./pre_processor -i data -r ./processed_data
100.00% files Pre-Processed.
```
The matrix calculation and clustering code is straight forward. Compilation and run should do the job.

####Further reading 
- [project site](http://goo.gl/56nCqb)
- [Publication-On Springer page](http://link.springer.com/chapter/10.1007%2F978-81-322-2202-6_44)

####Write to me
I am looking forward to collaborate with people in this project as well other projects. Please feel free to write me an e-mail:
shivendra _ mishra at live dot com
