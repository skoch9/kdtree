#include "KDTree.h"
#include "mex.h"

mxArray* KDTree::to_matlab_matrix(){
    /// Create an empty 1x1 struct  
    const char* fieldnames[] = {"points", "nodes"};
    mxArray* matstruct = mxCreateStructMatrix(1,1,2,fieldnames);
    
    /// Sticks datapoints into a mxArray
    {
        /// Create memory
        mxArray* points_mex = mxCreateDoubleMatrix(npoints, ndims(), mxREAL);
        double* points_data = mxGetPr(points_mex);        
        /// Fill data
        for( int i=0; i<npoints; i++ )
            for( int j=0; j<ndims(); j++ )
                points_data[ i + j*npoints ] = points[i][j]; 
        /// Add it to struct
        mxSetField(matstruct, 0, "points", points_mex);
    }    

    /// Sticks tree nodes into an 
    {
        /// Create memory
        mxArray* nodes_mex = mxCreateNumericMatrix(nodesPtrs.size(), 3, mxINT64_CLASS, mxREAL);
        int* nodes_data = (int*) mxGetData(nodes_mex);
        /// Fill data
        for( int i=0; i<nodesPtrs.size(); i+=3 ){
            nodes_data[i+0] = nodesPtrs[i]->LIdx;
            nodes_data[i+1] = nodesPtrs[i]->RIdx;
            nodes_data[i+2] = nodesPtrs[i]->pIdx;
        }       
        mxSetField(matstruct, 0, "nodes", nodes_mex);
    }
    
    return matstruct;
}

void mexFunction(int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[]){
    if(nrhs!=1) mexErrMsgTxt("varargin{1}  must be tree pointer");
    if(nlhs!=1) mexErrMsgTxt("varargout{1} is the target struct");
    KDTree* tree = KDTree::retrieve_pointer(prhs[0]);
    plhs[0] = tree->to_matlab_matrix();
}
