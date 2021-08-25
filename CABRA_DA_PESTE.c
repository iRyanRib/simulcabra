#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int leite=0;
int farinha_osso=1;
int trigo=1;
int horario=4;
int dia=1;
char pasto[25][50];


void inicializa(){
    int i, j, lin, col;  

    //espaço
    for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            pasto[i][j]=' ';
        }
    }
    
    //lama 3-3(~)
    for(i=0;i<3;i++){
        lin=abs(rand()%(25)-2);
        col=abs(rand()%(50)-2);
        pasto[lin][col]='~';
        pasto[lin-1][col]='~';
        pasto[lin][col+1]='~';
        pasto[lin][col-1]='~';
        pasto[lin-1][col+1]='~';
        pasto[lin-1][col-1]='~';
    }
    //lama 2-2-2(~)
    for(i=0;i<3;i++){
        lin=abs(rand()%(25)-2);
        col=abs(rand()%(50)-2);
        pasto[lin][col]='~';
        pasto[lin+1][col+1]='~';
        pasto[lin+1][col]='~';
        pasto[lin][col+1]='~';
        pasto[lin-1][col]='~';
        pasto[lin-1][col+1]='~';
      
    }
    //5 brotos de trigo(t)
    for(i=0;i<5;i++){
        lin=rand()%(25);
        col=rand()%(50);
        if(pasto[lin][col]==' '){
            pasto[lin][col]='t';
        }else{
            i--;
        }
    }
    //11 raposas (R)
    for(i=0;i<11;i++){
        lin=rand()%25; 
        col=rand()%50;
        if(pasto[lin][col]==' '){
            pasto[lin][col]='R';
        }else{
            i--;
        }
    }
    //5 cabras com chifre
    for(i=0;i<5;i++){
        lin=rand()%25;
        col=rand()%50;
        if(pasto[lin][col]==' '){
            pasto[lin][col]=-102;
        }else{
            i--;
        }
    }
}
void imprime(){
    int i,j;
    printf("\n");
    printf("                      |1|1|1|1|1|1|1|1|1|1|2|2|2|2|2|2|2|2|2|2|3|3|3|3|3|3|3|3|3|3|4|4|4|4|4|4|4|4|4|4\n");
    printf("   0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9|0|1|2|3|4|5|6|7|8|9\n");
    for(i=0;i<25;i++){
        printf("%2d", i);
        for(j=0;j<50;j++){
            printf("|%1c", pasto[i][j]);
        }
        printf("\n");
    }
}
void colher(){
     int lin, col;
        printf("colher trigo [linha coluna]:");
        scanf("%d %d", &lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(pasto[lin][col]=='T'){
               pasto[lin][col]=' ';
               trigo++;
               horario+=2;
            }else{
                printf("coordenada nao tem trigo!\n");
            }
        }else{
            printf("coordenadas invalidas\n");
        }
}
void fertilizar(){
    int lin, col;
    if(farinha_osso>0){
        printf("fertilizar broto de trigo[linha coluna]:");
        scanf("%d %d", &lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(pasto[lin][col]=='t'){
               pasto[lin][col]='T';
               farinha_osso--;
               horario+=2;
            }else{
                printf("coordenada nao tem broto de trigo\n");
            }
        }else{
            printf("coordenadas invalidas\n");
        }
    }else{
        printf("sem saldo de farinha de osso\n");
    }
}
void ordenhar(){
    int lin, col;
        printf("ordenhar cabra sem chifre[linha coluna]:");
        scanf("%d %d", &lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(pasto[lin][col]=='U'){
               pasto[lin][col]=-102;
               leite++;
               horario+=2;
            }else{
                printf("coordenada nao tem cabra sem chifre!\n");
            }
        }else{
            printf("coordenadas invalidas\n");
        }
}
void alimentar(){
    int lin, col;
        printf("alimentar cabra com chifre ou cabrita[linha coluna]:");
        scanf("%d %d", &lin, &col);
        getchar();//captura enter
           if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
               if(pasto[lin][col]=='u'){
                   if(leite>0){
                    pasto[lin][col]=-102;
                    leite--;
                    horario+=2;               
                   }else{
                       printf("saldo de leite insuficiente!\n");
                   }               
                }else{
                    if(pasto[lin][col]==-102){
                        if(trigo>0){
                            if((pasto[lin][col+1]==-102)&&(pasto[lin][col+2]==' ')){
                                    pasto[lin][col+2]='u';
                                    trigo--;
                                    horario+=2;  
                            }                    
                        }else{
                            printf("saldo de trigo insuficiente!\n");
                        }
                     }else{
                        printf("coordenada nao contem cabra com chifre ou cabrita!!\n");
                    }
                  }
            }else{
                printf("coordenadas invalidas!!\n");
            }

}
void mover (){
    int l1,c1,l2,c2;
    printf("coordenada de origem[linha coluna]:\n");
    scanf("%d %d", &l1,&c1);
    getchar();
        if((l1>=0)&&(l1<=24)&&(c1>=0)&&(c1<=49)){
            if((pasto[l1][c1]=='u')||(pasto[l1][c1]=='U')||(pasto[l1][c1]==-102)){
                printf("coordenada de destino[linha coluna]:\n");
                scanf("%d %d", &l2,&c2);
                getchar();
                if((l2>=0)&&(l2<=24)&&(c2>=0)&&(c2<=49)){
                    if((l2-l1>=-1)&&(l2-l1<=1)&&(c2-c1>=-1)&&(c2-c1<=1)){
                        if(pasto[l2][c2]==' '){//move 
                            pasto[l2][c2]=pasto[l1][c1];
                            pasto[l1][c1]=' ';
                            horario+=2;
                        }else{
                            if((pasto[l1][c1]==-102)&&(pasto[l2][c2]=='R')){//matar raposa
                                pasto[l2][c2]='U';
                                pasto[l1][c1]=' ';
                                farinha_osso++;
                                horario+=2;                       
                            }else{
                                printf("movimento invalido!!\n");
                            }
                        }

                    }else{
                        printf("destino nao eh vizinho\n");

                    }
                }else{
                    printf("coordenada de destino fora do limite da matriz!!\n");
                }   
            }else{
                printf("coordenada sem cabra\n");
            }
        }else{
            printf("coordenada de origem fora do limite da matriz!!\n");
        }   
}
void noite(){
    int i,j,lin,col,x=0;
    for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            if(pasto[i][j]=='R'){//raposas recebem espaço
                pasto[i][j]=' ';
            }
            if((pasto[i][j]=='U')&&(rand()%100<30)){//cabra ganhar chifre
                pasto[i][j]=-102;
            }
            if((pasto[i][j]==' ')&&(rand()%1250==0)){//aparecer trigo
                pasto[i][j]='t';
            }           
          }       
        }
        while(x<11){
        lin = (rand()%25);
        col = (rand()%50);
        if((pasto[lin][col]==' ')||(pasto[lin][col]=='u')||(pasto[lin][col]=='U')||(pasto[lin][col]==-102)){//Recebe 11 raposas
            pasto[lin][col]='R';
            x++;
        }
    }
}
int main(int argc, char const *argv[])
{
    char op=' ';
    srand(time(NULL));
    inicializa();
    while(op != 's'){
        imprime();
        printf("leite=%d farinha de osso=%d trigo=%d\n", leite, farinha_osso, trigo);
        printf("(c)colher / (f)ertilizar / (o)ordenhar / (a)alimentar / (m)over / (n)oite / (s)air");
        printf("{horario: %d:00 dia:%d } opcao:", horario,dia);
        op = getch();
        printf("%c\n", op);
        switch(op){         
            case 'c' : //colher
                colher();
                break;
            case 'f' : //fertilizar
                fertilizar();
                break;
            case 'o' : //ordenhar
                ordenhar();
                break;
            case 'a' : //alimentar
                alimentar();
                break;
            case 'm' : //mover
                mover();
                break;
            case 'n' : //noite
                noite();
                break;
            case 's' ://sair
                break;
            default:
                printf("[opcao invalida]");
        }
        if(horario==18){
            imprime();
            noite();
            horario=4;
            dia++;
        }
    }
    
    return 0;

}
