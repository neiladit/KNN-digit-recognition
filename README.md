# Digit recognition using KNN classification
This is the lab assignemnt for ECE 5775 course offered in the fall semester at the ECE department at Cornell University.  
# Abstract
We have defined distance in our case to be the total number of mismatches in the two image bit sequences. For each input image, I update the distance of its k-nearest-neighbors among groups of already labelled data of 0-9 digits. I assign the input to the class (0-9) which appears the most in the k least distance list. The error rate of the model for the given test image sequence with k=3 is 6.11%. Further, I have compared the error rates with varying values of k and optimized the latency by an order using hardware directives of loop unrolling and array partitioning. 
# Running the code
To simply run the code on CPU and compare accuracy just follow the lines below:
```
make
```
The Makefile will compile the necessary files and compare results. The value of k=3 in this case which can be changed in the Makefile

# HLS design tool
You'll need access to Vivado HLS tool for this part. Source settings from vivado and then run the follwoing command:
```
vivado_hls run.tcl
```
