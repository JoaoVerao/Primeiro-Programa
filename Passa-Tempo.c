#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char word[50],L,tv[10],vlhcomp[8],verifica[50];
int E1,E2,E3,E4,jgd,k,m;

void ppt(int E2)
{
    int a;
    a=rand()%3+1;//COMP. RECEBE UM VALOR ALEATORIO DE 1 A 3
    printf("\n\t\t\t");
    if(E2==1)//CASO TENHA ESCOLHIDO PEDRA
    {
        printf("Voce escolheu PEDRA e ");
        if(a==1)
            printf("empatou com PEDRA.\n");
        else
            if(a==2)
                printf("perdeu para PAPEL :c\n");
            else
                printf("ganhou de TESOURA!!\n");
    }
    if(E2==2)//CASO TENHA ESCOLHIDO PAPEL
    {
        printf("Voce escolheu PAPEL e ");
        if(a==1)
            printf("ganhou de PEDRA!!\n");
        else
            if(a==2)
                printf("empatou com PAPEL.\n");
            else
                printf("perdeu para TESOURA:c\n");
    }
    if(E2==3)//CASO TENHA ESCOLHIDO TESOURA
    {
        printf("Voce escolheu TESOURA e ");
        if(a==1)
            printf("perdeu para PEDRA :c\n");
        else
            if(a==2)
                printf("ganhou de PAPEL !!\n");
            else
                printf("empatou com TESOURA.\n");
    }
}

int forca()
{
    int i,j,ttv,acrt,x,s,q=0;
    fflush(stdin);
    scanf("%[^\n]s",word);//LE A PALAVRA A SER JOGADA
    k=strlen(word);//RECEBE O TAMANHO DA STRING
    char wor2[k];//STRING A SER COMPARADA
    system("cls");
    acrt=0;
    for(i=0;i<k;i++)//SUBSTIUI AS SEGUNDA STRING POR "_" OU ESPAÇO
    {
        verifica[i]=' ';
        if(word[i]==' ')
        {
            wor2[i]=' ';
            acrt++;
        }
        else
            wor2[i]='_';
    }
    j=0;
    ttv=0;
    printf("\n\n\n\n\n\n\t\t\t%c%c%c%c%c\n\t\t\t%c\n\t\t\t%c\n\t\t\t%c\n\t\t\t%c",218,196,196,196,191,179,179,179,179);
    for(i=0;i<k;i++)
        printf("%c ",wor2[i]);
    do//IMPEDE QUE O JOGO ACABE ANTES DE CUMPRIR UM DOS REQUISITOS
    {
        x=1;
        do//IMPEDE QUE REPITA UMA LETRA
        {
            printf("\n\n\t\t\tTentativas: ");
            for(i=0;i<ttv;i++)//MOSTRA AS LETRAS JA TENTADAS QUE NAO CONTEM NA STRING
                printf("%d%c%c ",i+1,167,tv[i]);
            printf("\n\t\t\t%d%c Tentativa. Digite uma letra: ",ttv+1,167);
            scanf(" %c",&L);//LE A LETRA A SER TESTADA
            system("cls");
            printf("\n\n\n\n\n\n\t\t\t%c%c%c%c%c\n\t\t\t%c\n\t\t\t%c\n\t\t\t%c\n\t\t\t%c",218,196,196,196,191,179,179,179,179);
            s=0;
            m=0;
            for(i=0;i<k;i++)//VERIFICA SE A LETRA DIGITADA NAO SE REPETE
            {
                if(verifica[i]==L)
                    s++;
            }
            if(s==0)//SE NAO, GUARDA A LETRA DIGITADA PARA COMPARAR COM AS PROXIMAS E LIBERA SAIDA DO DO WHILE
            {
                x=0;
                verifica[q]=L;
                q++;
            }
            else//SE SIM, IMPRIME QUE A LETRA É REPETIDA E VOLTA AO COMEÇO PARA LER UM OUTRO CARACTER
            {
                for(i=0;i<k;i++)
                    printf("%c ",wor2[i]);
                printf("\n\n\t\t\t\tLetra repetida, tente outra!");
            }
        }while(x!=0);
        for(i=0;i<k;i++)
        {
            if(L==word[i])//COMPARA A LETRA LIDA COM A PALAVRA DIGITADA
            {
                wor2[i]=L;
                acrt++;
            }
            if(L!=word[i])//CONTA QUANTAS VEZES A LETRA NAO SE REPETE
                m++;
            printf("%c ",wor2[i]);
        }
        if(m==k)//SE NAO TIVER A LETRA DIGITADA NA PALAVRA A SER DESCOBERTA, PERDE UMA TENTATIVA
        {
            tv[j]=L;
            j++;
            ttv++;
        }
        if(ttv==10)//IMPRIME A PALAVRA NAO DESCOBERTA CASO ACABE AS TENTATIVAS
            printf("\n\n\t\t\tA palavra era \"%s\"...\n\t\t\tNao foi dessa vez.. :/",word);
        if(acrt==k)//PARABENIZA CASO DESCUBRA E PERMITE ENCERRAR O JOGO
        {
            ttv=10;
            printf("\n\n\t\t\tParabens, voce acertou!!");
        }
    }while(ttv!=10);
    printf("\n\t\t\tJogar de novo?\n\t\t\t1.SIM\n\t\t\t2.NAO\n");
    scanf("%d",&E3);
    system("cls");
    return(E3);
}

int velha()
{
    int a,k,i,j,opjv,ln,cl,jgd,plyr,matriz[3][3],receptor,compara[9],cont;
    k=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            matriz[i][j]=k;//NUMERA UMA MATRIZ DE 0 A 8 PARA PODE USAR DE ENDEREÇO
            k++;
        }
    }
    for(i=0;i<9;i++)//LIMPA A STRING E O COMPARADOR
    {
        vlhcomp[i]=' ';
        compara[i]=-1;
    }
    printf("\n\n\n\n\n\n\n\n\n\t\t\tJogo da Velha\n\n\n\t\t\t1.Jogar com 2 Jogadores\n\t\t\t2.Jogar com Computador\n\t\t\t3.Sair\n\t\t\tOp%c%co:",135,198);
    scanf("%d",&opjv);
    switch(opjv)//ESCOLHE O MODO
    {
        case 1://MODO 2 PLAYERS
        {
            cont=0;
            jgd=0;
            system("cls");
            plyr=1;
            do
            {
                printf("\n\n\n\n\t\t\tJogador 1 joga com X\n\t\t\tJogador 2 joga com O");
                if(jgd<9)
                    printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                if(plyr==1)//JOGADOR 1 JOGA
                {
                    a=0;
                    while(a!=1)//IMPEDE DE SAIR ENQUANTO NAO DIGITE UMA LACUNA EXISTENTE E NAO REPETIDA
                    {
                        printf("\n\n\t\t\tJogador 1:\n\t\t\tLinha: ");
                        scanf("%d",&ln);//LE LINHA
                        printf("\t\t\tColuna: ");
                        scanf("%d",&cl);//LE COLUNA
                        receptor=matriz[ln-1][cl-1];//USA A MATRIZ PARA CONSEGUIR O ENDEREÇO
                        j=0;
                        if(ln>0&&ln<4&&cl<4&&cl>0)
                        {
                            for(i=0;i<9;i++)
                            {
                                if(receptor==compara[i])//VERIFICA SE JA NAO ESTA EM USO
                                    j=1;
                            }
                            if(j==0)//RECEBE E IMPRIME O VALOR CASO NAO ESTEJA EM USO
                            {
                                vlhcomp[receptor]='X';
                                a=1;
                                jgd++;
                                compara[cont]=receptor;
                                cont++;
                            }
                            else//CASO ESTEJA, IMPRIME UM AVISO E VOLTA PRA AREA DE LEITURA DE ENDEREÇO
                            {
                                printf("Essa lacuna ja esta em uso\n\n");
                                system("pause");
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                            }
                        }
                        else//CASO DIGITE UM ENDEREÇO INEXISTENTE, SERA AVISADO DO OCORRIDO E VOLTARÁ PARA DIGITAR OUTRO ENDEREÇO
                        {
                            printf("Essa lacuna nem existe!\n\n");
                            system("pause");
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                        }
                    }
                }
                if(plyr==0)//JOGADOR 2 JOGA
                {
                    a=0;
                    while(a!=1)//IMPEDE DE SAIR ENQUANTO NAO DIGITE UMA LACUNA EXISTENTE E NAO REPETIDA
                    {
                        printf("\n\n\t\t\tJogador 2:\n\t\t\tLinha: ");
                        scanf("%d",&ln);//LE LINHA
                        printf("\t\t\tColuna: ");
                        scanf("%d",&cl);//LE COLUNA
                        receptor=matriz[ln-1][cl-1];//USA A MATRIZ PARA CONSEGUIR O ENDEREÇO
                        j=0;
                        if(ln>0&&ln<4&&cl<4&&cl>0)
                        {
                            for(i=0;i<9;i++)
                            {
                                if(receptor==compara[i])//VERIFICA SE JA NAO ESTA EM USO
                                    j=1;
                            }
                            if(j==0)//RECEBE E IMPRIME O VALOR CASO NAO ESTEJA EM USO
                            {
                                vlhcomp[receptor]='O';
                                a=1;
                                jgd++;
                                compara[cont]=receptor;
                                cont++;
                            }
                            else//CASO ESTEJA, IMPRIME UM AVISO E VOLTA PRA AREA DE LEITURA DE ENDEREÇO
                            {
                                printf("Essa lacuna ja esta em uso\n\n");
                                system("pause");
                                system("cls");
                                printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                            }
                        }
                        else//CASO DIGITE UM ENDEREÇO INEXISTENTE, SERA AVISADO DO OCORRIDO E VOLTARÁ PARA DIGITAR OUTRO ENDEREÇO
                        {
                            printf("Essa lacuna nem existe!\n\n");
                            system("pause");
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                        }
                    }
                }
                system("cls");
                {//JOGADOR 1 VENCE
                if(vlhcomp[0]=='X'&&vlhcomp[1]=='X'&&vlhcomp[2]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[3]=='X'&&vlhcomp[4]=='X'&&vlhcomp[5]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[6]=='X'&&vlhcomp[7]=='X'&&vlhcomp[8]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='X'&&vlhcomp[4]=='X'&&vlhcomp[8]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='X'&&vlhcomp[4]=='X'&&vlhcomp[6]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='X'&&vlhcomp[3]=='X'&&vlhcomp[6]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[1]=='X'&&vlhcomp[4]=='X'&&vlhcomp[7]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='X'&&vlhcomp[5]=='X'&&vlhcomp[8]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                }
                {//JOGADOR 2 VENCE
                 if(vlhcomp[0]=='O'&&vlhcomp[1]=='O'&&vlhcomp[2]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[3]=='O'&&vlhcomp[4]=='O'&&vlhcomp[5]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[6]=='O'&&vlhcomp[7]=='O'&&vlhcomp[8]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='O'&&vlhcomp[4]=='O'&&vlhcomp[8]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='O'&&vlhcomp[4]=='O'&&vlhcomp[6]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='O'&&vlhcomp[3]=='O'&&vlhcomp[6]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[1]=='O'&&vlhcomp[4]=='O'&&vlhcomp[7]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='O'&&vlhcomp[5]=='O'&&vlhcomp[8]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 2 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                }
                //EMPATA
                if(jgd==9)
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tDeu Velha!\n\n\n\n\n\n\n");
                plyr++;
                plyr=plyr%2;
            }while(jgd<9);
            system("pause");
        }
        break;
        case 2://MODO CONTRA O COMPUTADOR
        {
            cont=0;
            jgd=0;
            k=0;
            system("cls");
            printf("\n\n\n\n\t\t\tJogador 1 joga com X\n\t\t\tComputador joga com O");
            plyr=0;
            do
            {
            if(plyr==1){//COMPUTADOR JOGA
                a=0;
                while(a!=1)//IMPEDE DE SAIR CASO NAO ATENDA OS REQUISITOS
                {
                    receptor=rand()%9;//DA UM NUMERO ALEATORIO ENTRE 0 E 8
                    j=0;
                    for(i=0;i<9;i++)
                    {
                        if(receptor==compara[i])//VERIFICA SE JA ESTA EM USO
                            j=1;
                    }
                    if(j==0)//CASO NAO ESTEJA, ELE PERMITE A ENTRADA
                    {
                        vlhcomp[receptor]='O';
                        a=1;
                        jgd++;
                        compara[cont]=receptor;
                        cont++;
                    }
                }
            }
            if(jgd<9)
                printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
            if(plyr==0&&jgd<9){//JOGADOR 1 JOGA
                a=0;
                while(a!=1)//IMPEDE A SAIDA CASO NAO ATENDA OS REQUISITOS
                {
                    printf("\n\n\t\t\tJogador 1:\n\t\t\tLinha: ");
                    scanf("%d",&ln);//LE LINHA
                    printf("\t\t\tColuna: ");
                    scanf("%d",&cl);//LE COLUNA
                    receptor=matriz[ln-1][cl-1];//PEGA O ENDEREÇO USANDO A MATRIZ
                    j=0;
                    if(ln<4&&ln>0&&cl<4&&cl>0)
                    {
                        for(i=0;i<9;i++)
                        {
                            if(receptor==compara[i])//VERIFICA SE JA NAO ESTA EM USO
                                j=1;
                        }
                        if(j==0)//PERMITE A ENTRADA CASO NAO ESTEJA EM USO
                        {
                            vlhcomp[receptor]='X';
                            a=1;
                            jgd++;
                            compara[cont]=receptor;
                            cont++;
                        }
                        else//AVISA QUE JA ESTA EM USO E NAO PERMITE PROCEDER
                        {
                            printf("Essa lacuna ja esta em uso\n\n");
                            system("pause");
                            system("cls");
                            printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                        }
                    }
                    else//AVISA QUE O ENDEREÇO NAO EXISTE E IMPEDE DE PROCEDER
                    {
                        printf("Essa lacuna nem existe!\n\n");
                        system("pause");
                        system("cls");
                        printf("\n\n\n\n\n\n\t\t\t\t%c%c%c%c%c  1\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  2\n\t\t\t\t%c%c%c%c%c\n\t\t\t\t%c%c%c%c%c  3\n\n\t\t\t\t1 2 3\n",vlhcomp[0],179,vlhcomp[1],179,vlhcomp[2],196,197,196,197,196,vlhcomp[3],179,vlhcomp[4],179,vlhcomp[5],196,197,196,197,196,vlhcomp[6],179,vlhcomp[7],179,vlhcomp[8]);
                    }
                }
            }
            system("cls");
            {//JOGADOR 1 VENCE
                if(vlhcomp[0]=='X'&&vlhcomp[1]=='X'&&vlhcomp[2]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[3]=='X'&&vlhcomp[4]=='X'&&vlhcomp[5]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[6]=='X'&&vlhcomp[7]=='X'&&vlhcomp[8]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='X'&&vlhcomp[4]=='X'&&vlhcomp[8]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='X'&&vlhcomp[4]=='X'&&vlhcomp[6]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='X'&&vlhcomp[3]=='X'&&vlhcomp[6]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[1]=='X'&&vlhcomp[4]=='X'&&vlhcomp[7]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='X'&&vlhcomp[5]=='X'&&vlhcomp[8]=='X')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tJogador 1 Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                }
            {//COMPUTADOR VENCE
                if(vlhcomp[0]=='O'&&vlhcomp[1]=='O'&&vlhcomp[2]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[3]=='O'&&vlhcomp[4]=='O'&&vlhcomp[5]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[6]=='O'&&vlhcomp[7]=='O'&&vlhcomp[8]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='O'&&vlhcomp[4]=='O'&&vlhcomp[8]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='O'&&vlhcomp[4]=='O'&&vlhcomp[6]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[0]=='O'&&vlhcomp[3]=='O'&&vlhcomp[6]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[1]=='O'&&vlhcomp[4]=='O'&&vlhcomp[7]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                if(vlhcomp[2]=='O'&&vlhcomp[5]=='O'&&vlhcomp[8]=='O')
                {
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tComputador Venceu!\n\n\n\n\n\n\n");
                    jgd=10;
                }
                }
                //EMPATA
                if(jgd==9)//CASO TODAS AS LACUNAS SEJA PREENCHIDA E NAO HAJA NENHUM VENCEDOR O JOGO EMPATAE ENCERRA
                    printf("\n\n\n\n\n\n\n\n\n\t\t\t\tDeu Velha!\n\n\n\n\n\n\n");
                plyr++;
                plyr=plyr%2;
            }while(jgd<9);
            system("pause");
        }
        break;
        case 3://SAIR DO JOGO DA VELHA
            E4=2;
        break;
        default:
            printf("Op%c%co invalida.\n",135,198);
            system("pause");
    }
    system("cls");
    return(E4);
}


int main()
{
    system("color f9");
    int a,ag,i,k,j,m;
    srand(time(NULL));
    do//IMPEDE QUE O PROGRAMA FEXE ENQUANTO NAO DER O COMANDO
    {
        printf("\n\n\n\n\n\n\n\n\n\t\t\tEscolha um passatempo:\n\n\t\t\t1.Pedra, Papel e Tesoura\n\t\t\t2.Jogo da Forca\n\t\t\t3.Jogo da Velha\n\t\t\t4.Sair\n\t\t\tOp%c%co: ",135,198);
        scanf("%d",&E1);
        system("cls");
        switch(E1)
        {
            case 1://PEDRA PAPEL E TESOURA
                do
                {
                    printf("\n\n\n\n\n\n\n\t\t\tPedra, Papel e Tesoura\n\n\t\t\tJogue:\n\t\t\t1.Pedra\n\t\t\t2.Papel\n\t\t\t3.Tesoura\n\t\t\t4.Sair\n\t\t\tOp%c%co: ",135,198);
                    scanf("%d",&E2);
                    ag=1;
                    if(E2<4&&E2>0)//ENTRA NO PROCEDIMENTO
                    {
                        ppt(E2);
                        printf("\n\t\t\tJogar de novo?\n\t\t\t1.SIM\n\t\t\t2.NAO\n\t\t\t");
                        scanf("%d",&ag);
                    }
                    if(ag<1||ag>2)//NEGA ENTRADA
                    {
                        printf("\t\t\tEntrada invalida!\n\n\t\t");
                        system("pause");
                    }
                    if(E2>=5||E2<=0)//NEGA ENTRADA
                    {
                        printf("\t\t\tEntrada invalida!\n\n\t\t");
                        system("pause");
                    }
                    system("cls");
                    if(ag == 2)
                        E2=4;
                }while(E2!=4);
            break;
            case 2://JOGO DA FORCA
                do
                {
                    printf("\n\n\n\n\t\t\t\tJOGO DA FORCA\n\n\n\n\t\t   Digite a palavra, sem o outro jogador ver:\n\n\t\t\t\t");
                    E3=forca();//CHAMA A FUNÇÃO
                }while(E3!=2);
            break;
            case 3://JOGO DA VELHA
                do
                {
                    E4=velha();//CHAMA A FUNÇÃO
                }while(E4!=2);
            break;
            case 4://SAIR
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\tVoce encerrou o programa!\n\n\n\n\n\n\n\n\n\n\n");
            break;
            default:
                printf("\t\t\tEntrada invalida!\n");
        }
    }while(E1!=4);
}