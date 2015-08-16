#Acquisition and Analysis of Robotic Environment Data Using Machine Learning Techniques

#####Abstract:
This project implements system for analysis and detection of objects in experimental robotic environment. For reference, the elementary work for this project consists of recording time series data from three long range IR distance sensors and five short range IR distance sensor. The robot was programed to record data at static sampling rate; while running on a straight path. This data goes through feature extraction and Pre-processing. And finally, the distance of the object from robotic path is obtained from left and right sensor; which is a time series stream data.

  In the implementation point of view; system is mainly having two modules. The First module consists of data recorded from the sensors. These sensors include of IR distance sensor, PIR thermal imaging Sensor, and Microphones. The time series spatial data of IR distance sensor is obtained by the help of ADC. Whereas, PIR Thermal Imaging Sensor is interfaced with the robot using the I2C bus switch; which is connected through the Two Wire Interface (TWI) of robot’s microcontroller. It has been planned to use Omron D6T-44L thermal Imaging Senor in both side of robot; which has 4x4 resolution with range of 2-3m (45° angle) and meets compatibility requirements. In case of microphone, two electret microphones are interfaced to ADC by the help of OPA344 based amplifier circuit. The spatial data received from ADC goes through FFT algorithm written in C, to obtain a time series stream of frequency distribution from audio signal.
        
  In the second module; a set of different experimental scenarios are designed; which includes of heat sources, different dummy shapes and sound sources kept around the robot path. Robot is programmed to run on an even, straight path with a constant speed to record time series data with 2 samples/second/sensor rate. Time Series Data obtained through these three sources goes for different phases of data mining algorithms. These phases includes of feature extraction, Pre-processing, and Clustering; which finally goes through a validation phase of result accuracy over the outcomes obtained. 

Complete Details can be found on the [project site](http://goo.gl/56nCqb).
