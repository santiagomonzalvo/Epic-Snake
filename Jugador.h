#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED



class Jugador{

protected:
    char Nombre[50];
    int Puntaje=0;

public:
    ///constructor
    Jugador(const char *n="VACIO",int p=0){
      strcpy(Nombre,n);
      Puntaje=p;
    }
    ///sets
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setPuntaje(int p){Puntaje=p;}
   // void setFecha(Fecha f){FechaP=f;}
    ///gets
    const char *getNombre(){return Nombre;}
    int getPuntaje(){return Puntaje;}
    //getfecha

    void Mostrar(){
            cout<<"==========================="<<endl;
            cout<<"NOMBRE DE JUGADOR: "<<Nombre<<endl;
            cout<<"PUNTAJE: "<<Puntaje<<endl;
        }

        int leerDeDisco(int pos){
            FILE *p;
            p=fopen("jugador.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof *this*pos,0);
            int leyo=fread(this, sizeof *this,1, p);
            fclose(p);
            return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("jugador.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

};

#endif // JUGADOR_H_INCLUDED
