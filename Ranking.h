#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

class Ranking{

protected:
    char Nombre[50];
    int Puntaje=0;

public:
    ///constructor
    Ranking(const char *n="VACIO",int p=0){
      strcpy(Nombre,n);
      Puntaje=p;
    }
    ///sets
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setPuntaje(int p){Puntaje=p;}

    ///gets
    const char *getNombre(){return Nombre;}
    int getPuntaje(){return Puntaje;}
    //getfecha

    void Mostrar(){
            cout<<"=========PUNTAJE RECORD============="<<endl;
            cout<<endl;
            cout<<"NOMBRE DE JUGADOR: "<<Nombre<<endl;
            cout<<"PUNTAJE: "<<Puntaje<<endl;
            cout<<endl;
            cout<<"===================================="<<endl;
        }

        int leerDeDisco(int pos){
            FILE *p;
            p=fopen("ranking.dat", "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof *this*pos,0);
            int leyo=fread(this, sizeof *this,1, p);
            fclose(p);
            return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("ranking.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }

    bool modificarArchivo(int pos){
    FILE *p;
    bool escribio;
    p=fopen("ranking.dat","rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(Ranking)*pos,0);
    escribio=fwrite(this,sizeof(Ranking),1,p);
    fclose(p);
    return escribio;
}

};

#endif // RANKING_H_INCLUDED
