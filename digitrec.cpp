//==========================================================================
//digitrec.cpp
//==========================================================================
// @brief: A k-nearest-neighbors implementation for digit recognition

#include "digitrec.h"

//----------------------------------------------------------
// Top function
//----------------------------------------------------------
// @param[in] : input - the testing instance
// @return : the recognized digit (0~9)

bit4 digitrec( digit input ) 
{
  #include "training_data.h"

  // This array stores K minimum distances per training set
  bit6 knn_set[10][K_CONST];

  // Initialize the knn set
  for ( int i = 0; i < 10; ++i )
    for ( int k = 0; k < K_CONST; ++k )
      // Note that the max distance is 49
      knn_set[i][k] = 50; 

  for ( int i = 0; i < TRAINING_SIZE; ++i ) {
	L1:for ( int j = 0; j < 10; j++ ) {

      // Read a new instance from the training set
      digit training_instance = training_data[j * TRAINING_SIZE + i];
      // Update the KNN set
      update_knn( input, training_instance, knn_set[j] );
    }
  } 

  // Compute the final output
  return knn_vote( knn_set ); 
}



//-----------------------------------------------------------------------
// update_knn function
//-----------------------------------------------------------------------
// Given the test instance and a (new) training instance, this
// function maintains/updates an array of K minimum
// distances per training set.

// @param[in] : test_inst - the testing instance
// @param[in] : train_inst - the training instance
// @param[in/out] : min_distances[K_CONST] - the array that stores the current
//                  K_CONST minimum distance values per training set

void update_knn( digit test_inst, digit train_inst, bit6 min_distances[K_CONST] )
{
  // -----------------------------
  // YOUR CODE GOES HERE
  // -----------------------------
	int dist=0;
	for(int i=0; i<test_inst.length();i++){
		if (test_inst[i]!=train_inst[i]) dist=dist+1;
	}
	for(int i=0;i<K_CONST;i++){
		if(dist<min_distances[i]){
			bit6 temp = min_distances[i];
			min_distances[i]=dist;
			dist = temp;
		}

		if(dist==50) break;
	}
}


//-----------------------------------------------------------------------
// knn_vote function
//-----------------------------------------------------------------------
// Given 10xK minimum distance values, this function 
// finds the actual K nearest neighbors and determines the
// final output based on the most common digit represented by 
// these nearest neighbors (i.e., a vote among KNNs). 
//
// @param[in] : knn_set - 10xK_CONST min distance values
// @return : the recognized digit
// 

bit4 knn_vote( bit6 knn_set[10][K_CONST] )
{
  // -----------------------------
  // YOUR CODE GOES HERE
  // -----------------------------
	bit4 decider[10];
	for(int i=0;i<10;i++) decider[i]=0;
	for(int i=0;i<K_CONST;i++){
		int min=50;
		int ind=-1;
		for(int j=0;j<10;j++){
			if(knn_set[j][decider[j]]<min){
				min = knn_set[j][decider[j]];
				ind = j;
			}
		}
		decider[ind]=decider[ind]+1;
	}
	int max=0;
	bit4 cls=-1;
	for(int i=0;i<10;i++){
		if(decider[i]>=max){
			max=decider[i];
			cls=i;
		}
	}

		
	return cls;

}
