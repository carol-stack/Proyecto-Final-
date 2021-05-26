#include <iostream>
using namespace std;

int const filas=4;
int const columnas=5;
void limpiezaMatrices(bool disponibilidad[filas][columnas],int peso[filas][columnas],int precio[filas][columnas]);
void imprimirMatriz(bool disponibilidad[filas][columnas]);
void cantidadDeContenedores(bool disponibilidad[filas][columnas]);
void contenedoresdelPuerto(string nombrePuertos[],int contenedoresporPuerto[],int cantidadPuertos);
void listaMarcaEconomica(int precio[filas][columnas],string marca[filas][columnas]);
void listaMarcaPremium(int precio[filas][columnas],string marca[filas][columnas]);
int nombreDeLaEmpresa(string marca[filas][columnas],int precio[filas][columnas]);
float promedioPesoContenedores(bool disponibilidad[filas][columnas],int peso[filas][columnas]);
int filaCargaPesada(int peso[filas][columnas]);
int columnaCargaLiviana(int peso[filas][columnas]);
int cantidadDeArticulos(string tipoArticulo[filas][columnas]);
float promedioPesoDelPuerto(int peso[filas][columnas],string puertoCarga[filas][columnas]);
int MarcaMasPeso(int peso[filas][columnas],string marca[filas][columnas]);
int MarcaMenosPeso(int peso[filas][columnas],string marca[filas][columnas]);

int main(){
    int porcentaje=0;
    
    //Puertos
    int cantidadPuertos=0;
    cout<<"Ingrese la cantidad de puertos "<<endl;
    cin>>cantidadPuertos;
    string nombrePuertos[cantidadPuertos];
    for(int i=0;i<cantidadPuertos;i++){
        cout<<"Ingrese el nombre del puerto numero "<<i+1<<endl;
        cin>>nombrePuertos[i];
    }
    cout<<"Los puertos son "<<endl;
    for(int i=0;i<cantidadPuertos;i++){
        cout<<nombrePuertos[i]<<endl;
    }

    //matrices
    bool disponibilidad[filas][columnas];
    string marca[filas][columnas];
    string puertoCarga[filas][columnas];
    int peso[filas][columnas];
    string tipoArticulo[filas][columnas];
    int precio[filas][columnas];
    //Vectores
    int recaudoporPuerto[cantidadPuertos];
    int contenedoresporPuerto[cantidadPuertos];

    limpiezaMatrices(disponibilidad,peso,precio);

    //llenado de matrices
    for (int x=0;x<cantidadPuertos;x++){
        int numerodeContenedores=0;
        cout<<"Ingrese el numero de contenedores "<<nombrePuertos[x]<<endl;
        cin>>numerodeContenedores;
        contenedoresporPuerto[x]=numerodeContenedores;
        for(int i=0;i<numerodeContenedores;i++){
            bool bandera=0;
            while(bandera==0){
                int fila=0;
                int columna=0;
                cout<<"La disponibilidad es la siguiente "<<endl;
                imprimirMatriz(disponibilidad);
                cout<<"Ingrese la coordenada de la fila correspondiente "<<endl;
                cin>>fila;
                cout<<"Ingrese la coordenada de la columna correspondiente "<<endl;
                cin>>columna;
                if(disponibilidad[fila][columna]==1 && fila<4 && fila>=0 && columna<5 && columna>=0){
                    cout<<"Ingrese la marca del contenedor "<<endl;
                    cin>>marca[fila][columna];
                    cout<<"Ingrese el peso del contenedor "<<endl;
                    cin>>peso[fila][columna];
                    puertoCarga[fila][columna]=nombrePuertos[x];
                    cout<<"Ingrese el tipo de articulo, (A) son alimentos, (B) son dispositivos electronicos y (C) son ropa y demas textiles "<<endl;
                    cin>>tipoArticulo[fila][columna];
                    disponibilidad[fila][columna]=0;
                    bandera=1;
                }else{
                    cout<<"La coordenada ingresada es inexistente o se encuentra ocupada, intente nuevamente"<<endl;
                }
            }
        }
        int contador=0;
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(disponibilidad[i][j]==0){
                    contador=contador+1;
                }
            }
        }
        porcentaje=(contador*100)/20;
        cout<<"EL porcentaje de ocupación del barco ahora es del "<<porcentaje<<"%"<<endl;

        int acumulador=0;
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(puertoCarga[i][j]==nombrePuertos[x]){
                    acumulador=acumulador+precio[i][j];
                }
            }
        }
        recaudoporPuerto[x]=acumulador;
        cout<<"El valor que se recaudo en el puerto actual es de "<<recaudoporPuerto[x]<<"USD"<<endl;
    }
    cantidadDeContenedores(disponibilidad);
    contenedoresdelPuerto(nombrePuertos,contenedoresporPuerto,cantidadPuertos);
    listaMarcaEconomica(precio,marca);
    listaMarcaPremium(precio,marca);
    nombreDeLaEmpresa(marca,precio);
    promedioPesoContenedores(disponibilidad,peso);
    filaCargaPesada(peso);
    columnaCargaLiviana(peso);
    cantidadDeArticulos(tipoArticulo);
    promedioPesoDelPuerto(peso,puertoCarga);
    MarcaMasPeso(peso,marca);
    MarcaMenosPeso(peso,marca);
    return 0;
}

void limpiezaMatrices(bool disponibilidad[filas][columnas],int peso[filas][columnas],int precio[filas][columnas]){
    	for(int i=0;i<filas;i++){
		for (int j=0;j<columnas;j++){
			disponibilidad[i][j]=1;
			peso[i][j]=0;
			precio[i][j]=0;
		}
	}
}

void imprimirMatriz(bool disponibilidad[filas][columnas]){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<disponibilidad[i][j]<<"\t";
        }
        cout<<endl;
    }
}

//1
void cantidadDeContenedores(bool disponibilidad[filas][columnas]){
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(disponibilidad[i][j]==0){
                contador=contador+1;
            }
        }
    }
    cout<<"El numero total de contenedores recogidos en los puertos es de "<<contador<<endl;
}

//2
void contenedoresdelPuerto(string nombrePuertos[],int contenedoresporPuerto[],int cantidadPuertos){
    for(int i=0;i<cantidadPuertos;i++){
        for(int j=0;j<cantidadPuertos;j++){
            if(contenedoresporPuerto[j]<contenedoresporPuerto[i]){
                int aux=contenedoresporPuerto[i];
                contenedoresporPuerto[i]=contenedoresporPuerto[j];
                contenedoresporPuerto[j]=aux;
                string auxnombre=nombrePuertos[i];
                nombrePuertos[i]=nombrePuertos[j];
                nombrePuertos[j]=auxnombre;
            }
        }
    }
    for(int i=0;i<cantidadPuertos;i++){
        cout<<nombrePuertos[i]<<"-->"<<contenedoresporPuerto[i]<<endl;
    }
}

//3
void listaMarcaEconomica(int precio[filas][columnas],string marca[filas][columnas]){
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(precio[i][j]==100 && marca[i][j]!=""){
                contador=contador+1;
            }
        }
    }
    string zonaEconomica[contador];
    for(int x=0;x<contador;x++){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(precio[i][j]==100 && marca[i][j]!=""){
                zonaEconomica[x]=marca[i][j];
                }
            }
        }
    }
    cout<<"La lista de marcas en la zona economica es "<<endl;
    for(int i=0;i<contador;i++){
        cout<<zonaEconomica[i]<<endl;
    }
}

//4
void listaMarcaPremium(int precio[filas][columnas],string marca[filas][columnas]){
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(precio[i][j]==300 && marca[i][j]!=""){
                contador=contador+1;
            }
        }
    }
    string zonaPremium[contador];
    for(int x=0;x<contador;x++){
        for(int i=0;i<filas;i++){
            for(int j=0;j<columnas;j++){
                if(precio[i][j]==300 && marca[i][j]!=""){
                zonaPremium[x]=marca[i][j];
                }
            }
        }
    }
    cout<<"La lista de marcas en la zona premium es "<<endl;
    for(int i=0;i<contador;i++){
        cout<<zonaPremium[i]<<endl;
    }
}

//5
int nombreDeLaEmpresa(string marca[filas][columnas],int precio[filas][columnas]){
    int acumulador=0;
    int contadorE=0;
    int contadorP=0;
    string marcaEmp="";
    cout<<"Ingrese el nombre de la empresa "<<endl;
    cin>>marcaEmp;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(marcaEmp==marca[i][j]){
                if(precio[i][j]==100){
                    acumulador=acumulador+precio[i][j];
                    contadorE=contadorE+1;
                }else if(precio[i][j]==300){
                    acumulador=acumulador+precio[i][j];
                    contadorP=contadorP+1;
                }
            }
        }
    }
    cout<<"La empresa "<<marcaEmp<<" tiene "<<contadorE<<" los siguientes contenedores en la zona economica y "<<contadorP<<" los siguientes contenedores en la zona premium"<<endl;
    return acumulador,contadorP,contadorE;
}

//6
float promedioPesoContenedores(bool disponibilidad[filas][columnas],int peso[filas][columnas]){
    float promedio=0;
    int acumulador=0;
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(disponibilidad[i][j]==0){
                contador=contador+1;
                acumulador=acumulador+peso[i][j];
            }
        }
    }
    promedio=acumulador/contador;
    cout<<"El promedio del peso de los contenedores es "<<promedio<<endl;
    return promedio;
}

//7
int filaCargaPesada(int peso[filas][columnas]){
    int mayor=0;
    int fila=0;
    int acumuladorA=0;
    int acumuladorB=0;
    int acumuladorC=0;
    int acumuladorD=0;
    for(int i=0;i<filas;i++){
        int acumulador=0;
        for(int j=0;j<columnas;j++){
            if(i==0){
                acumuladorA=acumuladorA+peso[i][j];
            }else if(i==1){
                acumuladorB=acumuladorB+peso[i][j];
            }else if(i==2){
                acumuladorC=acumuladorC+peso[i][j];
            }else if(i==3){
                acumuladorD=acumuladorD+peso[i][j];
            }
        }
    }
    int pesoFila[4];
    for(int i=0;i<4;i++){
        if(i==0){
            pesoFila[i]=acumuladorA;
        }else if(i==1){
            pesoFila[i]=acumuladorB;
        }else if(i==2){
            pesoFila[i]=acumuladorC;
        }else if(i==3){
            pesoFila[i]=acumuladorD;
        }
    }
    for(int i=0;i<4;i++){
        if(pesoFila[i]>mayor){
            mayor=pesoFila[i];
            fila=i;
        }
    }
    cout<<"La fila numero "<<fila<<" tiene el mayor peso que es de "<<mayor<<" toneladas"<<endl;
    return mayor,fila;
}

//8
int columnaCargaLiviana(int peso[filas][columnas]){
    int menor=0;
    int columna=0;
    int acumuladorA=0;
    int acumuladorB=0;
    int acumuladorC=0;
    int acumuladorD=0;
    int acumuladorE=0;
    for(int i=0;i<filas;i++){
        int acumulador=0;
        for(int j=0;j<columnas;j++){
            if(j==0){
                acumuladorA=acumuladorA+peso[i][j];
            }else if(j==1){
                acumuladorB=acumuladorB+peso[i][j];
            }else if(j==2){
                acumuladorC=acumuladorC+peso[i][j];
            }else if(j==3){
                acumuladorD=acumuladorD+peso[i][j];
            }else if(j==4){
                acumuladorE=acumuladorE+peso[i][j];
            }
        }
    }
    int pesoColumna[5];
    for(int i=0;i<5;i++){
        if(i==0){
            pesoColumna[i]=acumuladorA;
        }else if(i==1){
            pesoColumna[i]=acumuladorB;
        }else if(i==2){
            pesoColumna[i]=acumuladorC;
        }else if(i==3){
            pesoColumna[i]=acumuladorD;
        }else if(i==4){
            pesoColumna[i]=acumuladorE;
        }
    }
    for(int i=0;i<5;i++){
        if(pesoColumna[i]<menor){
            menor=pesoColumna[i];
            columna=i;
        }
    }
    cout<<"La columna numero "<<columna<<" tiene el menor peso que es de "<<menor<<" toneladas"<<endl;
    return menor,columna;
}

//9
int cantidadDeArticulos(string tipoArticulo[filas][columnas]){
    int contador=0;
    string articulos="";
    cout<<"Ingrese el tipo de articulo teniendo en cuenta que (A) son alimentos, (B) son dispositivos electronicos y (C) son ropa y demas textiles"<<endl;
    cin>>articulos;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(articulos==tipoArticulo[i][j]){
                contador=contador+1;
            }
        }
    }
    cout<<"Se encontraron "<<contador<<" contenedores del articulo "<<articulos<<endl;
    return contador;
}

//10
float promedioPesoDelPuerto(int peso[filas][columnas],string puertoCarga[filas][columnas]){
    float promedio=0;
    int contador=0;
    int acumulador=0;
    string nombreDelPuerto="";
    cout<<"Ingrese el nombre del puerto a buscar "<<endl;
    cin>>nombreDelPuerto;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(nombreDelPuerto==puertoCarga[i][j]){
                contador=contador+1;
                acumulador=acumulador+peso[i][j];
            }
        }
    }
    promedio=acumulador/contador;
    cout<<"El promedio del peso en el puerto "<<nombreDelPuerto<<" es de "<<promedio<<" toneladas"<<endl;
    return promedio;
}

//11
int MarcaMasPeso(int peso[filas][columnas],string marca[filas][columnas]){
    int mayor=0;
    string empresa="";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(peso[i][j]>mayor){
                mayor=peso[i][j];
                empresa=marca[i][j];
            }
        }
    }
    cout<<"La empresa "<<empresa<<" tiene el contenedor mas pesado con "<<mayor<<" toneladas"<<endl;
    return mayor;
}

//12
int MarcaMenosPeso(int peso[filas][columnas],string marca[filas][columnas]){
    int n=INT_MAX;
    string empresa="";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(peso[i][j]<menor){
                menor=peso[i][j];
                empresa=marca[i][j];
            }
        }
    }
    cout<<"La empresa "<<empresa<<" tiene el contenedor menos pesado con "<<menor<<" toneladas"<<endl;
    return menor;
}
