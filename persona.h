#include <string.h>
#include <ctype.h>

typedef struct Persona {
    int dni;
    char nombre [51];
    char apellido [51];
    char numTelefono[21];
    char domicilio [71];
    char fechaInhibicion [11];
} Persona;

void inicializarPersona(Persona *p){
    p->dni = 0;
    strcpy(p->nombre,"");
    strcpy(p->apellido,"");
    strcpy(p->numTelefono,"");
    strcpy(p->domicilio,"");
    strcpy(p->fechaInhibicion,"");
}

void AddDNI (Persona *p, int i){
    p->dni = i;
}

void AddNombre (Persona *p, char s []){
    strcpy(p->nombre, s);
}

void AddApellido (Persona *p, char s []){
    strcpy(p->apellido, s);
}

void AddTelefono (Persona *p, char s []){
    strcpy(p->numTelefono, s);
}

void AddDomicilio (Persona *p, char s []){
    strcpy(p->domicilio, s);
}

void AggFechaInhibicion (int anio, int mes, int dia,Persona *p){
    char fechaa[11];
    char fecham[11];
    char fechad[11];
    itoa(anio,fechaa,10);
    itoa(mes,fecham,10);
    itoa(dia,fechad,10);
    strcat(fechaa,"-");
    strcat(fechaa,fecham);
    strcat(fechaa,"-");
    strcat(fechaa,fechad);
    strcpy(p->fechaInhibicion,fechaa);
}

void Imprimir (Persona p) {
    printf("DNI: %d \n", p.dni);
    printf("Nombre: %s \n", p.nombre);
    printf("Apellido: %s \n", p.apellido);
    printf("Numero telefonico: %s \n", p.numTelefono);
    printf("Domicilio: %s \n", p.domicilio);
    printf("Fecha de invalidez de compra: %s \n", p.fechaInhibicion);
}

void hacerMin (Persona *p){
    int i;
    for(i=0;i<strlen(p->nombre);i++){
        p->nombre[i] = tolower(p->nombre[i]);
    }
    for(i=0;i<strlen(p->apellido);i++){
        p->apellido[i] = tolower(p->apellido[i]);
    }
    for(i=0;i<strlen(p->domicilio);i++){
        p->domicilio[i] = tolower(p->domicilio[i]);
    }
}

int CompararPersonas (Persona p, Persona q) {
    int i [6]={0,0,0,0,0,0};
    int d;
    hacerMin(&p);
    hacerMin(&q);
    i[0] = (!(p.dni == q.dni));
    i[1] = strcmp(p.nombre, q.nombre);
    i[2] = strcmp(p.apellido, q.apellido);
    i[3] = strcmp(p.domicilio, q.domicilio);
    i[4] = strcmp(p.numTelefono, q.numTelefono);
    i[5] = strcmp(p.fechaInhibicion, q.fechaInhibicion);
    for(d=0;d<6;d++){
        if(i[d] != 0){
            return 0;
        }
    }
    return 1;
}
