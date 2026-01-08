#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Bilim{
    char isim[20];
    int secim,gezegen,asansor;
    double t,h,g,v0,m,G,Ep,P,Fk,p,V,L,T,T2,N,a;
};
const char*gezegenler[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

void menu_genel(){
    printf("ANA MENU\n");
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
}

void serbestDusmeDeneyi(struct Bilim *b, double *g_ptr){
    printf("Serbest dusme deneyini gerceklestireceksin %s\n",b->isim);

    printf("Deney ne kadar surede yapilmistir?(s cinsinden)\n");
    scanf("%lf",&(b->t));
    b->t = (b->t < 0) ? -b->t : b->t;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->h = 0.5 * yercekimi * b->t * b->t;
        printf("%s gezegeninde kat edilen yol: h = %.2f m\n", *(gezegenler+i), b->h);}}


void yukariAtisDeneyi(struct Bilim *b, double *g_ptr){
    printf("Yukari atis deneyini gerceklestireceksin %s\n",b->isim);

    printf("Cisim kac m/s hizla firlatildi?\n");
    scanf("%lf",&(b->v0));
    b->v0 = (b->v0 < 0) ? -b->v0 : b->v0;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->h = (b->v0 * b->v0)/(2.0 * yercekimi);
        printf("%s gezegeninde cikabilecegi max yukseklik: h = %.2f m\n", *(gezegenler+i), b->h);}}


void agirlikDeneyi(struct Bilim *b, double *g_ptr){
    printf("Agirlik deneyini gerceklestireceksin %s\n",b->isim);

    printf("Cismin kutlesi ne kadardir?(kg cinsinden)\n");
    scanf("%lf",&(b->m));
    b->m = (b->m < 0) ? -b->m : b->m;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->G = b->m*yercekimi;
        printf("%s gezegeninde cismin agirligi: G = %.2f N\n", *(gezegenler+i), b->G);}}


void kutlecekimselPotansiyelEnerjiDeneyi(struct Bilim *b, double *g_ptr){
    printf("Kutlecekimsel potansiyel enerji deneyini gerceklestireceksin %s\n",b->isim);

    printf("Cismin atildigi yukseklik ne kadardir?(m cinsinden)\n");
    scanf("%lf",&(b->h));
    b->h = (b->h < 0) ? -b->h : b->h;

    printf("Cismin kutlesi ne kadardir?(kg cinsinden)\n");
    scanf("%lf",&(b->m));
    b->m = (b->m < 0) ? -b->m : b->m;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->Ep = b->m*yercekimi*b->h;
        printf("%s gezegeninde cismin kutlecekimsel potansiyel enerjisi: Ep = %.2f J\n", *(gezegenler+i), b->Ep);}}


void hidrostatikBasincDeneyi(struct Bilim *b, double *g_ptr){
    printf("Hidrostatik basinc deneyini gerceklestireceksin %s\n",b->isim);

    printf("Sivinin derinligi ne kadardir?(m cinsinden)\n");
    scanf("%lf",&(b->h));
    b->h= (b->h < 0) ? -b->h : b->h;

    printf("Sivinin birim hacimdeki kutlesi ne kadardir?(kg/m^3 cinsinden)\n");
    scanf("%lf",&(b->p));
    b->p = (b->p < 0) ? -b->p : b->p;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->P = b->p*yercekimi*b->h;
        printf("%s gezegeninde cismin hidrostatik basinci: P = %.2f P\n", *(gezegenler+i), b->P);}}


void arsimetKaldirmaKuvvetiDeneyi(struct Bilim *b, double *g_ptr){
    printf("Arsimet kaldirma kuvveti deneyini gerceklestireceksin %s\n",b->isim);

    printf("Cismin batan hacmi ne kadardir?(m^3 cinsinden)\n");
    scanf("%lf",&(b->V));
    b->V = (b->V < 0) ? -b->V: b->V;

    printf("Sivinin birim hacimdeki kutlesi ne kadardir?(kg/m^3 cinsinden)\n");
    scanf("%lf",&(b->p));
    b->p = (b->p < 0) ? -b->p : b->p;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->Fk = b->p*yercekimi*b->V;
        printf("%s gezegeninde cisme uygulanan kaldirma kuvveti: Fk = %.2f N\n", *(gezegenler+i), b->Fk);}}


void basitSarkacPeriyoduDeneyi(struct Bilim *b, double *g_ptr){
    printf("Basit Sarkac Periyodu deneyini gerceklestireceksin %s\n",b->isim);

    printf("Sarkacin uzunlugu ne kadardir?(m cinsinden)\n");
    scanf("%lf",&(b->L));
    b->L = (b->L < 0) ? -b->L : b->L;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->T = 2 * 3.141592653589793 * sqrt(b->L/yercekimi);
        printf("%s gezegeninde sarkacin ilk konumdan son konuma gitme suresi: T = %.2f s\n", *(gezegenler+i), b->T);}}


void sabitIpGerilmesiDeneyi(struct Bilim *b, double *g_ptr){
    printf("Sabit Ip Gerilmesi deneyini gerceklestireceksin %s\n",b->isim);

    printf("Cismin kutlesi ne kadardir?(kg cinsinden)\n");
    scanf("%lf",&(b->m));
    b->m = (b->m< 0) ? -b->m : b->m;

    for(int i=0; i<8; i++){
        double yercekimi = *(g_ptr+i);
        b->T2 = b->m*yercekimi;
        printf("%s gezegeninde ipin gerilme kuvveti: T = %.2f N\n", *(gezegenler+i), b->T2);}}


void asansorDeneyi(struct Bilim *b, double *g_ptr){
    printf("Asansor deneyini gerceklestireceksin %s\n",b->isim);

    printf("Cismin kutlesi ne kadardir?(kg cinsinden)\n");
    scanf("%lf",&(b->m));
    b->m = (b->m< 0) ? -b->m : b->m;

    printf("Asansorun ivmesi ne kadardir?(m/s^2 cinsinden)\n");
    scanf("%lf",&(b->a));
    b->a = (b->a < 0) ? -b->a : b->a;

            int asansor;
            printf("\nAsansor hareketini sec:\n");
            printf("1 - Yukari ivmelenerek hizlanma\n");
            printf("2 - Yukari ivmelenerek yavaslama\n");
            printf("3 - Asagi ivmelenerek hizlanma\n");
            printf("4 - Asagi ivmelenerek yavaslama\n");
            printf("Secim: ");
            scanf("%d", &asansor);

            for(int i=0; i<8; i++){
                double yercekimi = *(g_ptr+i);
            switch(asansor){
                case 1:
                    b->N = b->m * (yercekimi + b->a);
                    break;
                case 2:
                    b->N = b->m * (yercekimi - b->a);
                    break;
                case 3:
                    b->N = b->m * (yercekimi - b->a);
                    break;
                case 4:
                    b->N = b->m * (yercekimi + b->a);
                    break;

                default:
                    printf("Gecersiz secim!\n");
                    return;}

            printf("%s gezegeninde hissedilen agirlik (N) = %.2f N\n", *(gezegenler+i), b->N);}}

int main(){
    struct Bilim bilim;
    printf("Bilim insaninin adi nedir?\n");
    scanf("%s",bilim.isim);
    printf("UZAY SIMULASYONUMUZA HOSGELDIN %s\n",bilim.isim);
    double gezegenYercekimi[] = {
    3.7,   // 0 - Merkür
    8.87,  // 1 - Venüs
    9.81,  // 2 - Dünya
    3.71,  // 3 - Mars
    24.79, // 4 - Jüpiter
    10.44, // 5 - Satürn
    8.69,  // 6 - Uranüs
    11.15  // 7 - Neptün
};

    while(1){
        menu_genel();
        scanf("%d",&bilim.secim);

        if(bilim.secim == -1){
            printf("Programdan cikiliyor.\n");
            break;}

        if(bilim.secim == 1) serbestDusmeDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 2) yukariAtisDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 3) agirlikDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 4) kutlecekimselPotansiyelEnerjiDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 5) hidrostatikBasincDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 6) arsimetKaldirmaKuvvetiDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 7) basitSarkacPeriyoduDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 8) sabitIpGerilmesiDeneyi(&bilim, gezegenYercekimi);
        else if(bilim.secim == 9) asansorDeneyi(&bilim, gezegenYercekimi);
        else printf("Gecersiz secim!\n");}

        return 0;}
