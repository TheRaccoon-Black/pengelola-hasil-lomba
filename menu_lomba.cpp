#include<stdio.h>
#include<string.h>

typedef struct peserta{
    int nomor;
    char nama[50];
    float lamaWaktu;
} PESERTA;

const int N=3;

PESERTA pesertaLombaBalapMobil[N];

bool input = false;

void inputPeserta(){
    int no;
    char nama[50];
    float waktu;

    for (int i=0; i<N; i++){
        printf("\n Input pembalap ke-%d", i+1);
        printf("\n\n");

        printf("Masukkan nomor pembalap  :");
        fflush(stdin); scanf("%d",&no);

        printf("Masukkan nama pembalap  :");
        fflush(stdin); scanf("%s",&nama);

        printf("Masukan Lama Waktu (Dalam detik) :" );
        fflush(stdin); scanf("%d",&waktu);

        printf("\n========================================\n");
        pesertaLombaBalapMobil[i].nomor = no;
        strcpy(pesertaLombaBalapMobil[i].nama, nama);
        pesertaLombaBalapMobil[i].lamaWaktu = waktu;


    }input = true;
}

void urutan(){
    if (input){
        printf("\nurutan peserta berdasarkan waktu\n");

        PESERTA Temp;
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                if (pesertaLombaBalapMobil[i].lamaWaktu > pesertaLombaBalapMobil[j].lamaWaktu){
                    Temp = pesertaLombaBalapMobil[i];
                    pesertaLombaBalapMobil[i] = pesertaLombaBalapMobil[j];
                    pesertaLombaBalapMobil[j] = Temp;
                }
            }  
            printf("\n=====");
            printf("\npeserta nomor: %d", pesertaLombaBalapMobil[i].nomor);
            printf("\nnama pembalap: %s", pesertaLombaBalapMobil[i].nama);
            printf("\nlama waktu adalah: %d detik", pesertaLombaBalapMobil[i].lamaWaktu);
            printf("\n");
            printf("\npembalap mendapat juara : %d", i+1);
            printf("\n=========\n");

        }
    }else{
        printf("belum ada data yang dimasukkan");
    }
}
void cari(){
    if(input){
        int nomor;
        printf("masukkan nomor pembalap yang ingi dicari: ");
        scanf("%d",&nomor);

        for (int i=0;i<N;i++){
            if(pesertaLombaBalapMobil[i].nomor==nomor){
                printf("\n=======");
                printf("\npembalap nomor %d", pesertaLombaBalapMobil[i].nomor);
                printf("\nnama pembalap: %s", pesertaLombaBalapMobil[i].nama);
                printf("\nwaktu yang ditempuh yaitu: %d detik", pesertaLombaBalapMobil[i].lamaWaktu);
                printf("\npeserta mendapatkan juara-%d", i+1);
                printf("\n==================\n");
                break;
            }
        }

    }else{
        printf("\nbelum ada data yang dimasukkan");
    }
}

void exit(){
    printf("\nprogram telah selesai");
}

main(){
    int pilihan;
    printf("\n=====================\n");
    printf("\nMenu");
    printf("\n1. input data");
    printf("\n2. tampilkan juara");
    printf("\n3. cari data berdasarkan nomor pembalap");
    printf("\n4. exit");
    printf("\n==============\n");
    printf("masukkan pilihan anda: ");
    scanf("%d",&pilihan);
    switch(pilihan){
        case 1:
            inputPeserta();
            main();
            break;
        case 2:
            urutan();
            main();
            break;
        case 3:
            cari();
            main();
            break;
        case 4:
            exit();
            break;
        default:
            printf("\ntidak ada pilihan tersebut di menu");
            main();
            break;
    }
    printf("\n-----------------------\n");
}
