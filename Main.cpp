#include <iostream> 
#include "math_tools.h"
#include "display_tools.h"


int main(void){

    Matrix example_matrix, answer_matrix;
    
    float real = 2.5;
    

    zeroes(example_matrix,3);

    example_matrix.at(0).at(0)=2; example_matrix.at(0).at(1)=2; example_matrix.at(0).at(2)=3;
    example_matrix.at(1).at(0)=4; example_matrix.at(1).at(1)=5; example_matrix.at(1).at(2)=6; 
    example_matrix.at(2).at(0)=7; example_matrix.at(2).at(1)=8; example_matrix.at(2).at(2)=9;
    

    cout<<" \n LA MATRIZ ORIGINAL ES: \n \n ";
    inversa(example_matrix,answer_matrix);
    showMatrix(example_matrix);
    cout<<"LA MATRIZ INVERSA ES: \n \n ";
    showMatrix(answer_matrix);

    return 0;
}