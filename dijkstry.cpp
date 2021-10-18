#include<iostream>
using namespace std;

struct lista{
    lista *next;
    int v, w;
};

const int infinity = 1000;

int main(){
    int i, j, m, n, u, w, v, x, y, *d, *p, *Stos, tmp;
    bool *QS;
    lista **graf;
    lista *a, *b;

    cin >> v >> n >> m; //start, l wierzcholkow, l krawedzi;
    d = new int[n];
    p = new int[n];
    QS = new bool[n];

    graf = new lista *[n];
    Stos = new int[n];
    tmp = 0;

    for(i=0;i<n;i++){
        d[i] = infinity;
        p[i] = -1;
        QS[i] = false;
        graf[i] = NULL;
    }

    for(i=0;i<m;i++){
        cin>>x>>y>>w;
        a = new lista;
        a->v = y;
        a->w = w;
        a->next = graf[x];
        graf[x] = a;
    }

    cout<<endl;

    d[v]=0;
    for(i=0;i<n;i++){
        for(j=0;QS[j];j++);
        for(u=j++;j<n;j++)
            if(!QS[j] && (d[j]<d[u])) u=j;
        QS[u] = true;

        //relaksacja
        for(a=graf[u];a;a=a->next){
            if(!QS[a->v] && (d[a->v]>d[u]+a->w)){
                d[a->v] = d[u] + a->w;
                p[a->v] = u;
            }
        }
    }
    

    for(i=0;i<n;i++){
        cout<< i <<": droga -> ";
        for(j=i;j>-1;j=p[j]) Stos[tmp++]=j;
        while(tmp) cout<<Stos[--tmp]<< " ";
        cout<< "Koszt dojscia: "<<d[i]<<endl;
    }

    delete [] d;
    delete [] p;
    delete [] QS;
    delete [] Stos;
    for(i=0;i<n;i++){
        a = graf[i];
        while(a){
            b=a;
            a=a->next;
            delete b;
        }
    }
    delete [] graf;
    
    return 0;
}