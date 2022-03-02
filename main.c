#include "ABB.h"
#include "LSO.h"

//Dupla: Schuvab Arce Mathias Ezequiel y Soria Borizo Diego Lautaro
//Según lo analizado por nuestro programa, la estructura de almacenamiento ABB es la que mejor resultados entrega a la hora de realizar los costos debido que al hacer una alta o una baja son considerablemente bajos (entre 1 y 2), lo cual difiere en gran manera respecto a las listas secuenciales ordenadas, y respecto a la localizacion, un ABB tiene menores costos medios que una LSO, pero mayores que la busqueda binaria de una LSO.
//Sin embargo, si el ABB tuviese una distribucion "pareja" entre sus nodos, sus costos se acercarian a los de una LSOBB

void cargarPersona(Persona *p);
void cargarEnEstructura(LSO *lso,LSO *lsobb,ArbolbinarioBusqueda *abb,int opcion2);
int  ingresarDNI();
void eliminarDeEstructura (LSO *lso,LSO *lsobb,ArbolbinarioBusqueda *abb,int opcion2);
void buscarPersonaEnEstructura(LSO *lso,LSO *lsobb,ArbolbinarioBusqueda *abb,int opcion2);
void consultarPersonaEnEstructura(LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb,int opcion2);
void mostrarEstructura (LSO lso, LSO lsobb, ArbolbinarioBusqueda abb, int opcion2);
void comparacionDeEstructuras(FILE *fp, LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb);
double divisionPorCero(int numerador, double denominador);

int main()
{
    FILE *fp1;
    if((fp1 = fopen("Operaciones.txt","r"))==NULL);
    int opcion,opcion2,i=1,h=1,j=1, bar;
    LSO lso,lsobb;
    ArbolbinarioBusqueda abb;
    Persona p;
    inicializarPersona(&p);
    p.dni = 999999999;
    inicializarLSO(&lso);
    inicializarLSO(&lsobb);
    inicializarABB(&abb);
    AltaLSO(&lsobb,p,2,&bar);
    do{
        printf("=============MENU PRINCIPAL============\n\n");
        printf(" (1) Administracion de Estructuras\n");
        printf(" (2) Comparacion de Estructuras\n");
        printf(" (3) Salir del Programa\n\n");
        printf("============================Opcion: ");
        scanf("%d",&opcion);
        system("cls");
    while (opcion<1 || opcion>3){
        printf("=============MENU PRINCIPAL============\n\n");
        printf(" (1) Administracion de Estructuras\n");
        printf(" (2) Comparacion de Estructuras\n");
        printf(" (3) Salir del Programa\n\n");
        printf("==============Opcion No valida,ingrese de nuevo: ");
        scanf("%d",&opcion);
        system("cls");
    }
    switch(opcion){
        case 1:
                do{
                    do{
                        printf("===========Seleccione la estructura deseada===========\n\n");
                        printf(" (1) Lista Secuencial Ordenada con examinacion secuencial\n");
                        printf(" (2) Lista Secuencial Ordenada con busqueda binaria\n");
                        printf(" (3) Arbol Binario de Busqueda\n");
                        printf(" (4) Volver al menu anterior\n\n");
                        printf("==========================================Opcion: ");
                        scanf("%d",&opcion2);
                        system("cls");
                    }while (opcion2<1 || opcion2>4);
                    if(opcion2!=4){
                        h=1;
                        do{
                            j=1;
                            do{
                                printf("========Operaciones sobre la Estructura===========\n\n");
                                printf(" (1) Ingresar Persona\n");
                                printf(" (2) Eliminar Persona\n");
                                printf(" (3) Buscar Persona\n");
                                printf(" (4) Consultar Informacion de una Persona\n");
                                printf(" (5) Mostrar Estructura\n");
                                printf(" (6) Volver al menu anterior\n\n");
                                printf("=========================================Opcion: ");
                                scanf("%d",&opcion);
                                system("cls");
                            }while(opcion<1 || opcion>6);
                            switch(opcion){
                                case 1:
                                    cargarEnEstructura(&lso,&lsobb,&abb,opcion2);
                                    break;
                                case 2:
                                    eliminarDeEstructura(&lso,&lsobb,&abb,opcion2);
                                    break;
                                case 3:
                                    buscarPersonaEnEstructura(&lso,&lsobb,&abb,opcion2);
                                    break;
                                case 4:
                                    consultarPersonaEnEstructura(&lso,&lsobb,&abb,opcion2);
                                    break;
                                case 5:
                                    mostrarEstructura(lso, lsobb, abb, opcion2);
                                    break;
                                case 6: j=0;
                                    break;
                            }
                        }while(j);
                    }else{
                        h=0;
                    }
                }while(h);
                break;
        case 2:
                comparacionDeEstructuras(fp1,&lso,&lsobb,&abb);
                break;
        case 3:
                i=0;
                break;
    }
    }while(i);
    BorrarABB(&abb,abb.raiz);
    fclose(fp1);
    return 0;
}

void cargarPersona(Persona *p){
    int rta=1, anio, mes, dia;
    char fechaa[10];
    char fecham[10];
    char fechad[10];
    do{
    //DNI
        do{
            printf("======Cargando Persona======\n");
            printf("Ingrese dni de la Persona: ");
            fflush(stdin);
            scanf("%d",&p->dni);
            system("cls");
        }while(p->dni<10000000 || p->dni>99999999);
    //NOMBRE
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Ingrese nombre de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->nombre);
        system("cls");
    //APELLIDO
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Ingrese apellido de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->apellido);
        system("cls");
    //NRO DE TELEFONO
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Ingrese numero de telefono de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->numTelefono);
        system("cls");
    //DOMICILIO
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Ingrese domicilio de la Persona: ");
        fflush(stdin);
        scanf("%[^\n]",p->domicilio);
        system("cls");
    //AÑO
        do{
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Domicilio: %s\n",p->domicilio);
        printf("Ingrese a%co desde que esta inhibida la Persona: ",164);
        fflush(stdin);
        scanf("%d",&anio);
        system("cls");
        }while(anio<1950 || anio>2100);
    //MES
        do{
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Domicilio: %s\n",p->domicilio);
        printf("Fecha: %d-MM-DD\n",anio);
        printf("Ingrese mes desde que esta inhibida la Persona: ");
        fflush(stdin);
        scanf("%d",&mes);
        system("cls");
        }while(mes<1 || mes>12);
    //DIA
        do{
        printf("======Cargando Persona======\n");
        printf("Dni: %d\n",p->dni);
        printf("Nombre: %s\n",p->nombre);
        printf("Apellido: %s\n",p->apellido);
        printf("Numero de telefono: %s\n",p->numTelefono);
        printf("Domicilio: %s\n",p->domicilio);
        printf("Fecha: %d-%d-DD\n",anio,mes);
        printf("Ingrese dia desde que esta inhibida la Persona: ");
        fflush(stdin);
        scanf("%d",&dia);
        system("cls");
        }while(dia<1 || dia>31);
        itoa(anio,fechaa,10);
        itoa(mes,fecham,10);
        itoa(dia,fechad,10);
        strcat(fechaa,"-");
        strcat(fechaa,fecham);
        strcat(fechaa,"-");
        strcat(fechaa,fechad);
        strcpy(p->fechaInhibicion,fechaa);
        system("cls");
        //re ingreso
        Imprimir(*p);
        printf("Desea modificar la persona?\n1 - SI\n2 - NO\n");
        printf("Ingrese opcion: ");
        scanf("%d", &rta);
        while(rta < 1 || rta > 2){
            printf("Opcion Incorrecta.Desea modificar la persona?\n1 - SI\n2 - NO\n");
            printf("Ingrese opcion: ");
            scanf("%d", &rta);
        }
        system("cls");
    }
    while(rta == 1);
}

void cargarEnEstructura(LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb,int opcion2){
    Persona p;
    int costo=1,exito;
    cargarPersona(&p);
    if(opcion2==1){
        exito = AltaLSO(lso,p,1,&costo);
    }
    else{
        if(opcion2==2){
            exito = AltaLSO(lsobb,p,2,&costo);
        }
        else{
            exito = AltaABB(abb,p,&costo);
        }
    }
    if(exito){
        if(exito==1){
            printf("\n\n\t %c Se ha cargado exitosamente.  %c\n\n",186,186);
        }
        else{
            printf("\n\n\t %c No se ha podido cargar porque la estructura esta llena.  %c\n\n",186,186);
        }
    }
    else{
        printf("\n\n\t %c No se ha cargardo porque ya exite una persona con ese DNI.  %c\n\n",186,186);
    }
    printf("\t");
    system("pause");
    system("cls");
}

int ingresarDNI (int valor){
    int dni, rta;
    rta=1;
    if(valor == 9){
        do{
            do{
            printf("\n\t%s", "Ingrese DNI de la Persona que desea eliminar: ");
            scanf("%d", &dni);
            system("cls");
            }while(dni<10000000 || dni>99999999);
            printf("\n\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
            printf("%s", "\tIngrese opcion: ");
            scanf("%d", &rta);
            system("cls");
            while (rta < 1 || rta > 2){
                printf("\n\t%s\n", "Opcion incorrecta.");
                printf("\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
                printf("%s", "\tIngrese opcion: ");
                scanf("%d", &rta);
                system("cls");
            }
        }while (rta==1);
    }
    if(valor == 2){
        do{
            do{
            printf("\n\t%s", "Ingrese DNI de la Persona que desea buscar: ");
            scanf("%d", &dni);
            system("cls");
            }while(dni<10000000 || dni>99999999);
            printf("\n\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
            printf("%s", "\tIngrese opcion: ");
            scanf("%d", &rta);
            system("cls");
            while (rta < 1 || rta > 2){
                printf("\n\t%s\n", "Opcion incorrecta.");
                printf("\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
                printf("%s", "\tIngrese opcion: ");
                scanf("%d", &rta);
                system("cls");
            }
        }while (rta==1);
    }
    if(valor == 5){
        do{
            do{
            printf("\n\t%s", "Ingrese DNI de la Persona de la que desea consultar informacion: ");
            scanf("%d", &dni);
            system("cls");
            }while(dni<10000000 || dni>99999999);
            printf("\n\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
            printf("%s", "\tIngrese opcion: ");
            scanf("%d", &rta);
            system("cls");
            while (rta < 1 || rta > 2){
                printf("\n\t%s\n", "Opcion incorrecta.");
                printf("\tEl DNI ingresado es: %d\n\t¿Desea cambiarlo?\n\t1 - SI\n\t2 - NO\n", dni);
                printf("%s", "\tIngrese opcion: ");
                scanf("%d", &rta);
                system("cls");
            }
        }while (rta==1);
    }
    return dni;
}

void eliminarDeEstructura(LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb,int opcion2){
    int dni, costo;
    Persona p;
    costo = 1;
    dni = ingresarDNI(9);
    if(opcion2==1){
         if(BajaLSO(lso,dni,1,&costo, p)){
            printf("\n\n\t %c Se ha eliminado exitosamente  %c\n\n",186,186);
         }
         else{
            printf("\n\n\t %c No ha sido posible eliminar a la persona  %c\n\n",186,186);
         }
    }
    else{
        if(opcion2==2){
            if(BajaLSO(lsobb,dni,2,&costo,p)){
                printf("\n\n\t %c Se ha eliminado exitosamente  %c\n\n",186,186);
            }
            else{
                printf("\n\n\t %c No ha sido posible eliminar a la persona  %c\n\n",186,186);
            }
        }
        else{
             if(BajaABB(abb,dni,p,&costo)){
                printf("\n\n\t %c Se ha eliminado exitosamente  %c\n\n",186,186);
             }
             else{
                printf("\n\n\t %c No ha sido posible eliminar a la persona  %c\n\n",186,186);
             }
        }
    }
    printf("\t");
    system("pause");
    system("cls");
}

void buscarPersonaEnEstructura(LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb,int opcion2){
    int dni,exito;
    dni = ingresarDNI (2);
    if(opcion2==1){
         exito = PerteneceLSO(*lso,dni,1);
    }
    else{
        if(opcion2==2){
             exito = PerteneceLSO(*lsobb,dni,2);
        }
        else{
             exito = PerteneceABB(*abb,dni);
        }
    }
    if(exito){
        printf("\n\tLa persona con el dni:%d se encuentra inhibida\n\n\t",dni);
    }
    else{
        printf("\n\tLa persona con el dni:%d no se encuentra inhibida\n\n\t",dni);
    }
    system("pause");
    system("cls");
}

void consultarPersonaEnEstructura(LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb,int opcion2){
    int dni,exito;
    dni = ingresarDNI (2);
    Persona p;
    if(opcion2==1){
         exito = EvocacionLSO(dni,*lso,1,&p);

    }
    else{
        if(opcion2==2){
             exito = EvocacionLSO(dni,*lsobb,2,&p);
        }
        else{
             exito = EvocacionABB(*abb,dni,&p);
        }
    }
    if(!exito){
        printf("\n\tLa persona con el dni:%d no se encuentra inhibida\n",dni);
    }
    else{
        printf("===== Persona Inhibida ======\n");
        Imprimir(p);
    }
    printf("\n\n\t");
    system("pause");
    system("cls");
}

void mostrarEstructura (LSO lso, LSO lsobb, ArbolbinarioBusqueda abb, int opcion2){
    printf("** MOSTRANDO ESTRUCTURA **\n");
    if (opcion2 == 1){
        printf("Lista Secuencial Ordenada: \n\n");
        MostrarLSO(lso);
    }
    if (opcion2 == 2){
        printf("Lista Secuencial Ordenada por busqueda Binaria: \n\n");
        MostrarLSOBB(lsobb);
    }
    if (opcion2 == 3){
        printf("Arbol Binario de Busqueda: \n\n");
        MostrarABB(abb.raiz);
    }
    printf("\n");
    system("pause");
    system("cls");
}

void comparacionDeEstructuras(FILE *fp, LSO *lso, LSO *lsobb, ArbolbinarioBusqueda *abb){
    int operacion, longitud,costo=0,pos,exito;
    double operacionesLSO[4]={0,0,0,0}, operacionesLSOBB[4]={0,0,0,0}, operacionesABB[4]={0,0,0,0};
    int costoLSO[4]={0,0,0,0},costoLSOBB[4]={0,0,0,0},costoABB[4]={0,0,0,0};
    int mayorLSO[4]={0,0,0,0}, mayorLSOBB[4]={0,0,0,0}, mayorABB[4]={0,0,0,0};
    rewind(fp);
    Persona p;
    inicializarPersona(&p);
    p.dni = 999999999;
    BorrarLSO(lso);
    BorrarLSO(lsobb);
    BorrarABB(abb,abb->raiz);
    AltaLSO(lsobb,p,2,&costo);
    inicializarABB(abb);
    while(!feof(fp)){
        costo = 0;
        fscanf(fp,"%d",&operacion);
        if(operacion==1 || operacion==2){
            fscanf(fp,"%d\n",&p.dni);
            fgets(p.nombre, 51, fp);
            longitud = strlen(p.nombre) - 1;
            if (p.nombre && p.nombre[longitud] == '\n'){
                p.nombre[longitud] = '\0';
            }
            fgets(p.apellido, 51, fp);
            longitud = strlen(p.apellido) - 1;
            if (p.apellido && p.apellido[longitud] == '\n'){
                p.apellido[longitud] = '\0';
            }
            fgets(p.numTelefono, 21, fp);
            longitud = strlen(p.numTelefono) - 1;
            if (p.numTelefono && p.numTelefono[longitud] == '\n'){
                p.numTelefono[longitud] = '\0';
            }
            fgets(p.domicilio, 70, fp);
            longitud = strlen(p.domicilio) - 1;
            if (p.domicilio && p.domicilio[longitud] == '\n'){
                p.domicilio[longitud] = '\0';
            }
            fgets(p.fechaInhibicion,11,fp);
            longitud = strlen(p.fechaInhibicion) - 1;
            if (p.fechaInhibicion && p.fechaInhibicion[longitud] == '\n'){
                p.fechaInhibicion[longitud] = '\0';
            }
            if(operacion==1){ //ALTA
                if(AltaLSO(lso,p,1,&costo) == 1){
                    operacionesLSO[0] += 1;
                }
                costoLSO[0] += costo;
                if(costo>mayorLSO[0]){
                    mayorLSO[0] = costo;
                }
                costo = 0;
                if(AltaLSO(lsobb,p,2,&costo) == 1){
                    operacionesLSOBB[0] +=1;
                }
                costoLSOBB[0] += costo;
                if(costo>mayorLSOBB[0]){
                    mayorLSOBB[0] = costo;
                }
                costo = 0;
                if(AltaABB(abb,p,&costo) == 1){
                    operacionesABB[0] += 1;
                }
                costoABB[0] += costo;
                if(costo>mayorABB[0]){
                    mayorABB[0] = costo;
                }
            }
            if(operacion==2){ //BAJA
                if(BajaLSO(lso,p.dni,1,&costo,p)){
                    operacionesLSO[1] += 1;
                }
                costoLSO[1] += costo;
                if(costo>mayorLSO[1]){
                    mayorLSO[1] = costo;
                }
                costo = 0;
                if(BajaLSO(lsobb,p.dni,2,&costo,p)){
                    operacionesLSOBB[1] += 1;
                }
                costoLSOBB[1] += costo;
                if(costo>mayorLSOBB[1]){
                    mayorLSOBB[1] = costo;
                }
                costo = 0;
                if(BajaABB(abb,p.dni,p,&costo)){
                    operacionesABB[1] += 1;
                }
                costoABB[1] += costo;
                if(costo>mayorABB[1]){
                    mayorABB[1] = costo;
                }
            }
            operacion=4;
        }
        if(operacion==3){ //LOCALIZAR
            fscanf(fp,"%d",&p.dni);
            exito = LocalizarSec(p.dni,&pos,*lso,&costo);
            if(exito){
                operacionesLSO[2] += 1;
                costoLSO[2] += costo;
                if(costo>mayorLSO[2]){
                    mayorLSO[2] = costo;
                }
            }
            else{
                operacionesLSO[3] += 1;
                costoLSO[3] += costo;
                if(costo>mayorLSO[3]){
                    mayorLSO[3] = costo;
                }
            }
            costo = 0;
            exito = LocalizarBin(p.dni,&pos,*lsobb,&costo);
            if(exito){
                operacionesLSOBB[2] += 1;
                costoLSOBB[2] += costo;
                if(costo>mayorLSOBB[2]){
                    mayorLSOBB[2] = costo;
                }
            }
            else{
                operacionesLSOBB[3] += 1;
                costoLSOBB[3] += costo;
                if(costo>mayorLSOBB[3]){
                    mayorLSOBB[3] = costo;
                }
            }
            costo = 0;
            exito = LocalizarABB(abb,p.dni,&costo);
            if(exito){
                operacionesABB[2] += 1;
                costoABB[2] += costo;
                if(costo>mayorABB[2]){
                    mayorABB[2] = costo;
                }
            }
            else{
                operacionesABB[3] += 1;
                costoABB[3] += costo;
                if(costo>mayorABB[3]){
                    mayorABB[3] = costo;
                }
            }
        }
        operacion = 4;
    }
    printf("============================Comparacion de Estructura=============================\n");
    printf("\t\t\t\t\tCosto LSO\tCosto LSOBB\tCosto ABB\n");
    printf("MAX. ALTA:\t\t\t\t%d\t\t%d\t\t%d\n",mayorLSO[0],mayorLSOBB[0],mayorABB[0]);
    printf("MED. ALTA:\t\t\t\t%.2f\t\t%.2f\t\t%.2f\n",divisionPorCero(costoLSO[0],operacionesLSO[0]),divisionPorCero(costoLSOBB[0],operacionesLSOBB[0]),divisionPorCero(costoABB[0],operacionesABB[0]));
    printf("MAX. BAJA:\t\t\t\t%d\t\t%d\t\t%d\n",mayorLSO[1],mayorLSOBB[1],mayorABB[1]);
    printf("MED. BAJA:\t\t\t\t%.2f\t\t%.2f\t\t%.2f\n",divisionPorCero(costoLSO[1],operacionesLSO[1]),divisionPorCero(costoLSOBB[1],operacionesLSOBB[1]),divisionPorCero(costoABB[1],operacionesABB[1]));
    printf("MAX. LOCALIZACION EXITOSA:\t\t%d\t\t%d\t\t%d\n",mayorLSO[2],mayorLSOBB[2],mayorABB[2]);
    printf("MED. LOCALIZACION EXITOSA:\t\t%.2f\t\t%.2f\t\t%.2f\n",divisionPorCero(costoLSO[2],operacionesLSO[2]),divisionPorCero(costoLSOBB[2],operacionesLSOBB[2]),divisionPorCero(costoABB[2],operacionesABB[2]));
    printf("MAX. LOCALIZACION FRACASO:\t\t%d\t\t%d\t\t%d\n",mayorLSO[3],mayorLSOBB[3],mayorABB[3]);
    printf("MED. LOCALIZACION FRACASO:\t\t%.2f\t\t%.2f\t\t%.2f\n",divisionPorCero(costoLSO[3],operacionesLSO[3]),divisionPorCero(costoLSOBB[3],operacionesLSOBB[3]),divisionPorCero(costoABB[3],operacionesABB[3]));
    printf("==================================================================================\n");
    system("pause");
    system("cls");
}

double divisionPorCero(int numerador, double denominador){
    if(denominador == 0){
        return 0.0;
    }
    else{
        return (numerador/denominador);
    }
}
