#include "tubes.h"
//=============PAPER
void createlistpaper(listpaper &Lp){
    first(Lp) = NULL;
}

void insertfirstpaper(listpaper &Lp, adrpaper p){
    if(first(Lp) == NULL){
        first(Lp) = p;
        next(p) = NULL;
    }else{
        next(p) = first(Lp);
        first(Lp) = p;
    }
}

adrpaper deletefirstpaper(listpaper &Lp){
    adrpaper x;
    if(first(Lp) == NULL){
        x = NULL;
        cout<<"List Kosong"<<endl;
    }else if (next(first(Lp)) == NULL){
        x = first(Lp);
        first(Lp) = NULL;
    }else{
        x = first(Lp);
        first(Lp) = next(first(Lp));
    }
    return x;
}

adrpaper deleteafterpaper(listpaper &Lp, adrpaper prec){
    adrpaper x;
    x = next(prec);
    next(prec) = next(x);
    next(x) = NULL;
    return x;
}

adrpaper deletelastpaper(listpaper &Lp){
    adrpaper x, y;
    if(first(Lp) == NULL){
        x = NULL;
        cout<<"List Kosong"<<endl;
    }else if (next(first(Lp)) == NULL){
        x = first(Lp);
        first(Lp) = NULL;
    }else{
        y = first(Lp);
        x = first(Lp);
        while(next(x) != NULL){
            y = x;
            x = next(x);
        }
        next(y) = NULL;
    }
    return x;
}

adrpaper deletepaper(listpaper &Lp, string judul){
    adrpaper x = first(Lp);
    adrpaper p = findpaper(Lp, judul);
    while(next(x) != NULL){
        x = next(x);
    }
    if(first(Lp) == p){
        p = deletefirstpaper(Lp);
    }else if(x == p){
        p = deletelastpaper(Lp);
    }else{
        adrpaper prec = first(Lp);
        while(next(prec) != p){
            prec = next(prec);
        }
        p = deleteafterpaper(Lp, prec);
    }
    return p;
}

adrpaper createnewelementpaper(infotypep x){
    adrpaper p = new elementp;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void showalldatapaper(listpaper Lp){
    adrpaper q;
    q = first(Lp);
    if(first(Lp) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        while(q != NULL){
            cout<<info(q).judul<<endl;
            q = next(q);
        }
    }
}

adrpaper findpaper(listpaper Lp, string judul){
    adrpaper q = first(Lp);
    while(q != NULL && info(q).judul != judul){
        q = next(q);
    }
    return q;
}

//=============Keyword
void createlistkeyword(listkeyword &Lk){
    first(Lk) = NULL;
}

void insertfirstkeyword(listkeyword &Lk, adrkeyword p){
    if(first(Lk) == NULL){
        first(Lk) = p;
        next(p) = NULL;
    }else{
        next(p) = first(Lk);
        first(Lk) = p;
    }
}

adrkeyword createnewelementkeyword(infotypek x){
    adrkeyword p = new elementk;
    info(p) = x;
    next(p) = NULL;
    return p;
}

adrkeyword findkeyword(listkeyword Lk, string kata){
    adrkeyword q = first(Lk);
    while(q != NULL && info(q).kata != kata){
        q = next(q);
    }
    return q;
}

adrkeyword findspeckeyword(listrelasi Lr, string kata, string judul){
    adrrelasi r = first(Lr);
    adrkeyword k;
    while(r != NULL){
        if(info(info(r).relasip).judul == judul && info(info(r).relasik).kata == kata){
            k = info(r).relasik;
        }
    }
    return k;
}

void showkeyword(listkeyword Lk){
    adrkeyword q;
    q = first(Lk);
    if(first(Lk) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        while(q != NULL){
            cout<<info(q).kata<<endl;
            q = next(q);
        }
    }
}

//=============RELASI
void createlistrelasi(listrelasi &Lr){
    first(Lr) = NULL;
}

void insertfirstrelasi(listrelasi &Lr, adrrelasi p){
    if(first(Lr) == NULL){
        first(Lr) = p;
        next(p) = NULL;
    }else{
        next(p) = first(Lr);
        first(Lr) = p;
    }
}

adrrelasi createnewelementrelasi(infotyper x){
    adrrelasi p = new elementr;
    info(p) = x;
    next(p) = NULL;
    return p;
}
adrrelasi deletefirstrelasi(listrelasi &Lr){
    adrrelasi x;
    if(first(Lr) == NULL){
        x = NULL;
        cout<<"List Kosong"<<endl;
    }else if (next(first(Lr)) == NULL){
        x = first(Lr);
        first(Lr) = NULL;
    }else{
        x = first(Lr);
        first(Lr) = next(first(Lr));
    }
    return x;
}

adrrelasi deleteafterrelasi(listrelasi &Lr, adrrelasi prec){
    adrrelasi x;
    x = next(prec);
    next(prec) = next(x);
    next(x) = NULL;
    return x;
}

adrrelasi deletelastrelasi(listrelasi &Lr){
    adrrelasi x, y;
    if(first(Lr) == NULL){
        x = NULL;
        cout<<"List Kosong"<<endl;
    }else if (next(first(Lr)) == NULL){
        x = first(Lr);
        first(Lr) = NULL;
    }else{
        y = first(Lr);
        x = first(Lr);
        while(next(x) != NULL){
            y = x;
            x = next(x);
        }
        next(y) = NULL;
    }
    return x;
}

adrrelasi deleterelasip(listrelasi &Lr,adrpaper p){
    adrrelasi r;
    adrrelasi x = first(Lr);
    while(next(x) != NULL){
        x = next(x);
    }
    if(info(first(Lr)).relasip == p){
        r = deletefirstrelasi(Lr);
    }else if(info(x).relasip == p){
        r = deletelastrelasi(Lr);
    }else{
        adrrelasi prec = first(Lr);
        while(next(info(prec).relasip) != p){
            prec = next(prec);
        }
        r = deleteafterrelasi(Lr, prec);
    }
    return r;

}

void deletepaperrelasi(listrelasi &Lr,listpaper &Lp,adrpaper &x, string judul){
    adrpaper p = findpaper(Lp,judul);
    adrrelasi r = first(Lr);
    while(r != NULL){
        if (info(r).relasip == p){
            deleterelasip(Lr,p);
        }
        r = next(r);
    }
    x = deletepaper(Lp,p);
}

void showrelasi(listrelasi Lr, listpaper Lp){
    if(first(Lr) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        adrrelasi q;
        adrpaper p;
        q = first(Lr);
        p = first(Lp);
        while(p != NULL){
            cout<<info(p).judul<<endl;
            while(q != NULL){
                if(info(q).relasip == p){
                    cout<<info(info(q).relasik).kata<<endl;
                }
                q = next(q);
            }
            p = next(p);
        }
    }
}


void connectrelasi(listrelasi &Lr, listpaper Lp, listkeyword Lk, string judul, string kata){
    infotyper info;
    adrrelasi x;
    info.relasip = findpaper(Lp, judul);
    info.relasik = findkeyword(Lk, kata);
    x = createnewelementrelasi(info);
    insertfirstrelasi(Lr, x);
}

int jumlah(listrelasi Lr, string judul){
    adrrelasi r = first(Lr);
    int j = 0;
    while(r != NULL){
        if(info(info(r).relasip).judul == judul){
            j = j + 1;
        }
        r = next(r);
    }
    return j;
}
