#include <iostream>
using namespace std;
////////////////////////////////
class Nodo{
    public:
    int info=0;
    Nodo *liga=NULL;
};
////////////////////////////////
//F_inicio/final
Nodo* inserta_inicio(Nodo *,int);
void inserta_final(Nodo *,int);
//F_insertar  antes/despues
Nodo* inserta_antes_X (Nodo *,int,int);
void inserta_despues_X (Nodo *,int,int);
//mostrar
void ver(Nodo *);
//eliminar 
Nodo* eliminar_primer(Nodo*);
Nodo* eliminar_final(Nodo*);
//F_borrar antes/despues/x
Nodo* eliminar_X(Nodo *,int);
void eliminarDespues_X(Nodo *,int);
Nodo* eliminarAntes_X(Nodo *,int);
///menu
void menu();
Nodo * menu_agregar(Nodo*);
Nodo *menu_eliminar(Nodo*);
//corrector 
int corre();






//main principal

int main(){
    system("cls");
    menu();
    return 0;
}


//funciones 

Nodo * inserta_inicio(Nodo *P_ini,int DATO){
    Nodo *nuevo=new Nodo();
    nuevo->info=DATO;
    nuevo->liga=P_ini;
    P_ini=nuevo;
    return P_ini;
}


void inserta_final(Nodo *P_ini,int DATO){
    Nodo *aux=P_ini;
    while(aux->liga!=NULL){
       aux=aux->liga; 
    }
    Nodo *nuevo=new Nodo();
    nuevo->info=DATO;
    aux->liga=nuevo;
}



Nodo* inserta_antes_X (Nodo *P_ini,int DATO,int comp){
    Nodo *adelante=P_ini;
    int BAND=1;
    Nodo *atras;
    while ( adelante->info!=comp && BAND==1 ){
        if(adelante->liga!=NULL){
            atras=adelante;
            adelante=adelante->liga;
        }
        else{
            BAND=0;
        }
    }

    if(BAND==1){
        Nodo *nuevo=new Nodo();
        nuevo->info=DATO;
        if(P_ini==adelante){
            nuevo->liga=P_ini;
            P_ini=nuevo;
        }
        else{
            atras->liga=nuevo;
            adelante->liga=adelante;
        }
    }
    else{
        cout<<"EL NODO DADO COMO REFERENCIA NO SE ENCUENTRA EN LA LISTA";
    }
    return P_ini;
}


void inserta_despues_X (Nodo *P_ini,int DATO,int comp){
    Nodo *atras=P_ini;
    int BAND=1;
    Nodo *adelante=NULL;
    
    while ( atras->info!=comp && BAND==1 ){
        if(atras->liga!=NULL){
            atras=atras->liga;
            adelante=atras->liga;
        }
        else{
            BAND=0;
        }
    }
    
    if(BAND==1){
        if(atras==P_ini){
            Nodo *nuevo=new Nodo();
            Nodo *aux=P_ini->liga;
            nuevo->info=DATO;
            atras->liga=nuevo;
            nuevo->liga=aux;
        }
        else{
            Nodo *nuevo=new Nodo();
            nuevo->info=DATO;
            atras->liga=nuevo;
            nuevo->liga=adelante;
        }
    }
    else{
        cout<<"EL NODO DADO COMO REFERENCIA NO SE ENCUENTRA EN LA LISTA";
    }
    
}

void ver(Nodo *P_ini){
    if(P_ini==NULL){
        cout<<"\nNo se pudo mostrar [Lista vacia]";
    }
    cout<<endl;
    
    while(P_ini!=NULL){
        cout<<P_ini->info<<endl;
        P_ini=P_ini->liga;
    }
}
//////////////////////////////////////////////////////
//funciones eliminar :

Nodo* eliminar_primer(Nodo *P_ini){
    if(P_ini!=NULL){
        Nodo *aux=P_ini;
        P_ini=P_ini->liga;
        delete(aux);
    }
    else{
        cout<<"\n<Lista vacia>";
    }
    return P_ini;
}


///////////////////////////////////////////

Nodo *eliminar_final(Nodo *P_ini){
    if(P_ini!=NULL){
        Nodo *aux=P_ini;
        Nodo *borrar;
        while(aux->liga!=NULL){
            borrar=aux;
            aux=aux->liga; 
        }
        //caso -> inicio = final 
        if(aux==P_ini){
            delete(P_ini);
            P_ini=NULL;
        }
        //caso normal 
        else{
            borrar->liga=NULL;
            delete(aux);
        }
    }
    else{
        cout<<"\n<Lista Vacia>";
    }
    return P_ini;
}

///////////////////////////////////////////

Nodo* eliminar_X(Nodo *P_ini,int comp){
    if(P_ini!=NULL){
        Nodo *eliminar=P_ini;
        int BAND=1;
        Nodo *atras;
        while(eliminar->info!=comp && BAND==1 ){
            if(eliminar->liga!=NULL){
                atras=eliminar;
                eliminar=eliminar->liga;
            }
            else{
                BAND=0;
            }
        }
        if(BAND==1){
            if(eliminar==P_ini){
                P_ini=P_ini->liga;
            }
            else{
                atras->liga=eliminar->liga;
            }
            delete(eliminar);
        }
        else{
            cout<<"\n\nEL NODO NO SE ENCUENTRA EN LA LISTA";
        }
    }
    else{
        cout<<"\n<Lista vacia>";
    }
    return P_ini;
}
/////////////////////////////////////////////////////////////////////////

void eliminarDespues_X(Nodo *P_ini,int comp){
    if(P_ini!=NULL){
        Nodo *eliminar=P_ini;
        int BAND=1;
        Nodo *adelante=NULL;
        while(eliminar->info!=comp && BAND==1 ){
            if(eliminar->liga!=NULL){
                eliminar=eliminar->liga;
                adelante=eliminar->liga;
            }
            else{
                BAND=0;
            }
        }
        if(BAND==1){
            if(eliminar==P_ini){
                if(P_ini->liga!=NULL){
                    P_ini->liga=P_ini->liga->liga;
                }
                else{
                    cout<<"No existe un nodo despues de este";
                }
            }
            else{
                if(adelante!=NULL){
                    eliminar->liga=adelante->liga;
                }
                else{
                    cout<<"No existe elemento despues ";
                }
            }
            delete(adelante);
        }
        else{
            cout<<"\n\nEL NODO NO SE ENCUENTRA EN LA LISTA";
        }
    }
    else{
        cout<<"\n<Lista vacia>";
    }
}
/////////////////////////////////////////////////////////////////////////


Nodo* eliminarAntes_X(Nodo *P_ini,int comp){
    if(P_ini!=NULL){
        Nodo *adelante=P_ini;
        int BAND=1;
        Nodo *eliminar;
        while(adelante->info!=comp && BAND==1 ){
            if(adelante->liga!=NULL){
                eliminar=adelante;
                adelante=adelante->liga;
                if(adelante->liga!=NULL){
                    if(adelante->liga->info==comp){
                        break;
                    }
                }
            }
            else{
                BAND=0;
            }
        }
        if(BAND==1){
            if(adelante==P_ini){
                cout<<"\nSe encuentra en el primer elemento";
            }
            else{
                if(eliminar==P_ini&&adelante->info==comp){
                    P_ini=adelante;
                    delete(eliminar);
                }
                else{
                    eliminar->liga=adelante->liga;
                    delete(adelante);
                }
            }
        }
        else{
            cout<<"\n\nEL NODO NO SE ENCUENTRA EN LA LISTA";
        }
    }
    else{
        cout<<"\n<Lista vacia>";
    }
    return P_ini;
}

void menu(){
    system("cls");
    system("color 3");
    int i;
    string vali;
    Nodo *P_ini=NULL;
    do{
        system("cls");
        cout<<"\n\t\t****************MENU***************";
        cout<<"\n\t\t1.-Crear lista";
        cout<<"\n\t\t2.-Agregar elementos";
        cout<<"\n\t\t3.-Eliminar elementos";
        cout<<"\n\t\t4.-Mostrar lista";
        cout<<"\n\t\t5.-Salir";
        cout<<"\n\t\t********************************";
        cout<<"\n\n\t\tIngrese opcion >> ";i=corre();
        switch (i){
            case 1:
                system("cls");
                if(P_ini==NULL){
                    cout<<"\n\n\t\t\t||Creando nodo||";
                    P_ini=new Nodo();
                    cout<<"\nIngrese el dato :";P_ini->info=corre();
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }else{
                    cout<<"\nLa lista ya se encuentra creada :";
                    cout<<"\nPresione una tecla para continuar : ";cin>>vali;
                }
            break;
            case 2:
                P_ini=menu_agregar(P_ini);
            break;
            case 3:
                P_ini=menu_eliminar(P_ini);
            break;
            case 4:
                system("cls");
                cout<<"\n\n\t\tMostrando lista :";
                ver(P_ini);
                cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
            break;
        }
    }while(i!=5);
}

Nodo *menu_agregar(Nodo* P_ini){
    system("cls");
    system("color 3");
    int i,numero,comp;
    string vali;
    do{
        system("cls");
        cout<<"\n\t\t****************MENU***************";
        cout<<"\n\t\t1.-insertar al inico";
        cout<<"\n\t\t2.-insertar al final";
        cout<<"\n\t\t3.-insertar despues de X";
        cout<<"\n\t\t4.-insertar antes de X";
        cout<<"\n\t\t5.-Retroceder al menu principal";
        cout<<"\n\t\t********************************";
        cout<<"\n\n\t\tIngrese opcion >> ";i=corre();
        switch (i){
            case 1:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion insertar inicio :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese el dato :";numero=corre();
                    P_ini=inserta_inicio(P_ini,numero);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"\n\nNo existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 2:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion insertar final :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese el dato :";numero=corre();
                    inserta_final(P_ini,numero);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 3:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion insertar despues de X :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese dato X:";comp=corre();
                    cout<<"\nIngrese el dato :";numero=corre();
                    inserta_despues_X(P_ini,numero,comp);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 4:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion insertar antes de X :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese dato X:";comp=corre();
                    cout<<"\nIngrese el dato :";numero=corre();
                    P_ini=inserta_antes_X (P_ini,numero,comp);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
        }
    }while(i!=5);
    return P_ini;
}


Nodo *menu_eliminar(Nodo* P_ini){
    system("cls");
    system("color 3");
    int i,numero,comp;
    string vali;
    do{
        system("cls");
        cout<<"\n\t\t****************MENU***************";
        cout<<"\n\t\t1.-eliminar al inico";
        cout<<"\n\t\t2.-eliminar al final";
        cout<<"\n\t\t3.-eliminar despues de X";
        cout<<"\n\t\t4.-eliminar antes de X";
        cout<<"\n\t\t5.-eliminar X";
        cout<<"\n\t\t6.-Retroceder al menu principal";
        cout<<"\n\t\t********************************";
        cout<<"\n\n\t\tIngrese opcion >> ";i=corre();
        switch (i){
            case 1:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion eliminar inicio :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    P_ini=eliminar_primer(P_ini);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"\n\nNo existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 2:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion eliminar final :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    P_ini=eliminar_final(P_ini);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 3:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion eliminar despues de X :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese dato X:";comp=corre();
                    eliminarDespues_X(P_ini,comp);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 4:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion eliminar antes de X :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese dato X:";comp=corre();
                    P_ini=eliminarAntes_X(P_ini,comp);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
            case 5:
                system("cls");
                if(P_ini!=NULL){
                    cout<<"\n\nopcion eliminar X :>>>>";
                    cout<<"\n\nMostrando lista actual : ";
                    ver(P_ini);
                    cout<<"\nIngrese dato X:";comp=corre();
                    P_ini=eliminar_X(P_ini,comp);
                    cout<<"\n\nMostrando lista despues : ";
                    ver(P_ini);
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
                else{
                    cout<<"No existe la lista se tiene que crear";
                    cout<<"\n\nPresiona una tecla para continuar >>";cin>>vali;
                }
            break;
        }
    }while(i!=6);
    return P_ini;
}

///corrector de entero
int corre(){
    int dt;
    cin>>dt;
    if(cin.fail()){
        cin.clear(); // se resetea el flag de error de cin en el caso de ingresar un char
        fflush(stdin); // se limpia el buffer
        return 0;//retorna 15 uso unico para menus de opciones con numeros<15
    }
    else{
        return dt; 
    }
}
