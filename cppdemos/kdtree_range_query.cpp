// this is actually just a single query

#include "KDTree.h"

int test1(){
	int N = 30;
	vector< Point > A(N, vector<double>(2,0));
	A[0][0]   =  0.0565 ;  A[0][1]= 0.8670   ;
	A[1][0]   =  0.2016 ;  A[1][1]= 0.7061   ;
	A[2][0]   =  0.0795 ;  A[2][1]= 0.6096   ;
	A[3][0]   =  0.1094 ;  A[3][1]= 0.3056   ;
	A[4][0]   =  0.3583 ;  A[4][1]= 0.2529   ;
	A[5][0]   =  0.2500 ;  A[5][1]= 0.1623   ;
	A[6][0]   =  0.4919 ;  A[6][1]= 0.1477   ;
	A[7][0]   =  0.5219 ;  A[7][1]= 0.3085   ;
	A[8][0]   =  0.5620 ;  A[8][1]= 0.4635    ;
	A[9][0]  =   0.3744 ;  A[9][1] =0.6623    ;
	A[10][0]  =   0.3306 ;  A[10][1] =0.9050    ;
	A[11][0]  =   0.5081 ;  A[11][1] =0.9137    ;
	A[12][0]  =   0.4459 ;  A[12][1] =0.8699    ;
	A[13][0]  =   0.7108 ;  A[13][1] =0.6798    ;
	A[14][0]  =   0.7131 ;  A[14][1] =0.8816    ;
	A[15][0]  =   0.6279 ;  A[15][1] =0.8757    ;
	A[16][0]  =   0.6901 ;  A[16][1] =0.7675   ;
	A[17][0]  =   0.8353 ;  A[17][1] =0.7529   ;
	A[18][0]  =   0.6486 ;  A[18][1] =0.6038   ;
	A[19][0]  =   0.8145 ;  A[19][1] =0.4108   ;
	A[20][0]  =   0.6786 ;  A[20][1] =0.3319   ;
	A[21][0]  =   0.6555 ;  A[21][1] =0.4576   ;
	A[22][0]  =   0.5035 ;  A[22][1] =0.5658   ;
	A[23][0]  =   0.4412 ;  A[23][1] =0.4605   ;
	A[24][0]  =   0.4804 ;  A[24][1] =0.4137   ;
	A[25][0]  =   0.7362 ;  A[25][1] =0.3991   ;
	A[26][0]  =   0.6141 ;  A[26][1] =0.6652   ;
	A[27][0]   =  0.3698 ;  A[27][1] =0.7529   ;
	A[28][0]   =  0.2385 ;  A[28][1] =0.7822   ;
	A[29][0]   =  0.1694 ;  A[29][1] =0.6915   ;
	
	KDTree* tree = new KDTree( A );
	cout << "tree created" << endl;
	
	// Range query 
	vector<double> pmin(2,0);
	vector<double> pmax(2,0);
	for (int i=0; i<10; i++)
		for (unsigned int dim=0; dim < A[0].size(); dim++) {
			if( A[i][dim] < pmin[dim] ) pmin[dim] = A[i][dim];
			if( A[i][dim] > pmax[dim] ) pmax[dim] = A[i][dim];
		}
	cout << "query data created" << endl;
	
	vector<int> idxsInRange;
    tree->range_query( pmin, pmax, idxsInRange );
    cout << "query data executed" << endl;
    
    cout << "I found these points: " << idxsInRange.size() << endl;
    for (unsigned int i=0; i < idxsInRange.size(); i++)
		cout << "element in range: " << idxsInRange[i] << endl;
	
	return 0;
}
int main(){
	return test1();
}

