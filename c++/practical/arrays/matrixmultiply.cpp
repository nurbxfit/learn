#include <iostream>

/*
example matrix representation
2x3 = [3,4,5]
      [2,3,4]

3x3 = [2,3,4]
      [4,3,5]
      [1,2,3]

*/
void multiply(int result[2][3],int mA[2][3], int mB[3][3]){
    for(int i=0; i<2;i++){
        
        for(int j=0; j<3;j++){
            result[i][j]=0;
            for(int k=0; k < 3; k++){
                //Rij= Rij + Aik * Bik
                //R00 = R00 + A00 * B00;
                // = 0 + 3x2

                // then R00 = (R01 + A0,1*B1,0) + A02*B2,0
                // (3x2) + 4x4 + 5x1
                // = 27  
                result[i][j]=result[i][j] + mA[i][k]*mB[k][j];
            }
        }
    }
}

void printRes(int result[2][3]){
    std::cout << "Result: " <<std::endl;
    for(int i=0;i<2;i++){
        for(int j=0;j < 3; j++){
            std::cout<<"|" << result[i][j] << "|";
        }
        std::cout << std::endl;
    }
}
int main(){
    int mA[2][3] = {
        {3,4,5},
        {2,3,4}
    }; //here we create 2x3 matrix
    int mB[3][3] = {
        {2,3,4},
        {4,3,5},
        {1,2,3}
    }; //here we create 3x3 matrix, simply an array within an array

    int result[2][3]; //result of multiplication is a 2x3 matrix

    multiply(result,mA,mB);
    printRes(result);

}