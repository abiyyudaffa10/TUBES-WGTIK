#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)

typedef struct paper infotypep;
typedef struct keyword infotypek;
typedef struct relasi infotyper;
typedef struct elementp *adrpaper;
typedef struct elementk *adrkeyword;
typedef struct elementr *adrrelasi;

struct paper{
    string judul;
};

struct keyword{
    string kata;
};

struct relasi{
    adrpaper relasip;
    adrkeyword relasik;
};

struct elementp{
    infotypep info;
    adrpaper next;
};

struct elementk{
    infotypek info;
    adrkeyword next;
};

struct elementr{
    infotyper info;
    adrrelasi next;
};

struct listpaper{
    adrpaper first;
};

struct listkeyword{
    adrkeyword first;
};

struct listrelasi{
    adrrelasi first;
};

void createlistpaper(listpaper &Lp);
void createlistkeyword(listkeyword &Lk);
void createlistrelasi(listrelasi &Lr);
adrpaper createnewelementpaper(infotypep x);
adrkeyword createnewelementkeyword(infotypek x);
adrrelasi createnewelementrelasi(infotyper x);
void insertfirstpaper(listpaper &Lp, adrpaper p);
void insertfirstkeyword(listkeyword &Lk, adrkeyword p);
void insertfirstrelasi(listrelasi &Lr, adrrelasi p);
void showalldatapaper(listpaper Lp);
void showkeyword(listkeyword Lk);
void showrelasi(listrelasi Lr, listpaper Lp);
adrpaper deletefirstpaper(listpaper &Lp);
adrpaper deleteafterpaper(listpaper &Lp, adrpaper prec);
adrpaper deletelastpaper(listpaper &Lp);
adrpaper deletepaper(listpaper &Lp, string judul);
adrrelasi deletefirstrelasi(listrelasi &Lr);
adrrelasi deleteafterrelasi(listrelasi &Lr, adrrelasi prec);
adrrelasi deletelastrelasi(listrelasi &Lr);
adrrelasi deleterelasip(listrelasi &Lr,adrpaper p);
void deletepaperrelasi(listrelasi &Lr,listpaper &Lp,adrpaper &x, string judul);
adrpaper findpaper(listpaper Lp, string judul);
adrkeyword findkeyword(listkeyword Lk, string kata);
adrkeyword findspeckeyword(listrelasi Lr, string kata, string judul);
void connectrelasi(listrelasi &Lr, listpaper Lp, listkeyword Lk, string judul, string kata);
int jumlah(listrelasi Lr, string judul);

#endif // TUBES_H_INCLUDED
