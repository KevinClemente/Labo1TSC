#include <vector>
#include "math.h"
#include "stdlib.h"
using namespace std;


typedef vector<float> Vector;
typedef vector<Vector> Matrix;

    /* ESTA FUNCION VA A RECIBIR UN VECTOR
    LO VA A RECIBIR POR REFERENCIA (&) ESTO PORQUE
    NO LE INTERESA CREAR OTRO VECTOR SINO MODIFICARLO
    Y n VA A SER EL QUE VA INDICAR LA LONGITUD DEL VECTOR
    */
void zeroes(Vector &v, int n){
    for (int i = 0; i < n; i++)
    { 
        //el metodo push back va a ir agregando nuevos datos al vector
        v.push_back(0.0);
    }
}

    //llena de ceros una matriz
void zeroes(Matrix &M, int n){
    for (int i = 0; i < n; i++)
    {
        Vector row(n,0.0);
        M.push_back(row); 
    }
    
}

    //dado un vector quiero copiar la informacion en otro vector
void copyVector(Vector v,Vector &copy){

    zeroes(copy,v.size());

    for (int i = 0; i < v.size(); i++)
    {
        copy.at(i)=v.at(i);
    }
}

void copyMatrix(Matrix A , Matrix &copy){

    zeroes (copy, A.size());

    for (int i = 0; i < A.size() ; i++)
    {
        for (int j = 0; j < A.at(0).size();  j++)
        {
        copy.at(i).at(j)=A.at(i).at(j);
        }   
    }

}


void productMatrixVector(Matrix A, Vector v, Vector &R){

    for (int fila = 0; fila < A.size(); fila++)
    {
        float cell = 0.0;//acumulador
        for (int col = 0; col < v.size(); col++) //como las dimensiones coinciden puede ocupar cualquier vector como condicion de paro
        {
          cell += A.at(fila).at(col)*v.at(col); 
        }
        R.at(fila) += cell;
    }
    

}




//La funcion recibe: Una matriz y la matriz que contendra a la primera transpuesta
void transpose(Matrix M, Matrix &T){
    //Se prepara la matriz resultante con las mismas dimensiones
    //de la matriz original
    zeroes(T,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            //La posicion actual se almacena en la posicion con indices
            //invertidos de la matriz resultante
            T.at(j).at(i) = M.at(i).at(j);
}


//La funcion elimina en la matriz la fila i, y la columna j
//La funcion recibe: Una matriz, un indice de fila i y un indice de fila j.
void getMinor(Matrix &M,int i, int j){
    //Se elimina la fila i
    M.erase(M.begin()+i); //Uso de begin para obtener un iterator a la posicion de interes
    //Se recorren las filas restantes
    for(int i=0;i<M.size();i++)
        //En cada fila se elimina la columna j
        M.at(i).erase(M.at(i).begin()+j);
}


//La funcion calcula el determinante de la matriz de forma recursiva
//La funcion recibe: Una natriz  
float determinant(Matrix M){
    //Caso trivial: si la matriz solo tiene una celda, ese valor es el determinante
    if(M.size() == 1) return M.at(0).at(0);
    else{
        //Se inicia un acumulador           
        float det=0.0;
        //Se recorre la primera fila
        for(int i=0;i<M.at(0).size();i++){
            //Se obtiene el menor de la posicion actual
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);

            //Se calculala contribucion de la celda actual al determinante
            //(valor alternante * celda actual * determinante de menor actual)
            det += pow(-1,i)*M.at(0).at(i)*determinant(minor);
        }
        return det;
    }
}     


//La funcion recibe saca el cofactor de una matriz.
//La funcion recibe: Una matriz y la matriz que contendra los cofactores de la primera.
void cofactors(Matrix M, Matrix &Cof){
    //Se prepara la matriz de cofactores para que sea de las mismas
    //dimensiones de la matriz original
    zeroes(Cof,M.size());
    //Se recorre la matriz original
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            //Se obtiene el menor de la posicion actual
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            //Se calcula el cofactor de la posicion actual
            //      alternante * determinante del menor de la posicion actual
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}



void inversa(Matrix M,Matrix &answer_matrix){
    Matrix cofactors_matrix,transpose_matrix;
    
    float real=determinant(M);

    cofactors(M,cofactors_matrix);
    transpose(cofactors_matrix,transpose_matrix);

    if (real!=0)
    {
        zeroes(answer_matrix,transpose_matrix.size());
        //Se recorre la matriz 
        for(int i=0;i<transpose_matrix.size();i++)
            for(int j=0;j<transpose_matrix.at(0).size();j++)
                answer_matrix.at(i).at(j) = 1/real*(transpose_matrix.at(i ).at(j));
    }

    else
    {
        exit(EXIT_FAILURE);
    }
          
}