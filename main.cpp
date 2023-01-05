#include "tubes.h"

using namespace std;

int main(){
    listpaper Lp;
    listkeyword Lk;
    listrelasi Lr;
    adrpaper x, y;
    adrkeyword a;
    infotypep p;
    infotypek k;
    createlistpaper(Lp);
    createlistrelasi(Lr);
    createlistkeyword(Lk);
    /*p.judul = "kontol";
    x = createnewelementpaper(p);
    insertfirstpaper(Lp, x);
    k.kata = "asu";
    a = createnewelementkeyword(k);
    insertfirstkeyword(Lk, a);
    connectrelasi(Lr, Lp, Lk, p.judul, k.kata);
    k.kata = "av";
    a = createnewelementkeyword(k);
    insertfirstkeyword(Lk, a);
    connectrelasi(Lr, Lp, Lk, p.judul, k.kata);
    showrelasi(Lr, Lp);
    cout<<jumlah(Lr, "kontol")<<endl;
    */
    p.judul = "kontol";
    x = createnewelementpaper(p);
    insertfirstpaper(Lp, x);
    p.judul = "o";
    x = createnewelementpaper(p);
    insertfirstpaper(Lp, x);
    p.judul = "l";
    x = createnewelementpaper(p);
    insertfirstpaper(Lp, x);
    p.judul = "k";
    x = createnewelementpaper(p);
    insertfirstpaper(Lp, x);
    showalldatapaper(Lp);
    y = deletepaper(Lp, "o");
    showalldatapaper(Lp);

}
