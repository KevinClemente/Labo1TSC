/*no lo estoy recibiendo por referencia porque no quiero modificarlo
solo lo estoy recibiendo solo quiero utilizarlo */  

void showVector(Vector b)
{
    cout << "[\t";
    //Size es una funcion de los vectores que devuelve la lngitud
    for (int i = 0; i < b.size(); i++)
    {
        //el metodo at recibe una posicion
        cout << b.at(i) << "\t";
    }
    cout << "]\n";
} 

void showMatrix(Matrix k){  
     for (int i = 0; i < k.at(0).size(); i++)
     {
         cout << "[ \t";
         for (int j = 0; j < k.size(); j++)
         {
             cout << k.at(i).at(j) <<"\t";
         }
         cout<<"]\n";
     }
     cout<<"\n";
     cout<<"\n";
}

