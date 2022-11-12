#include <stdio.h>
#include <stdlib.h>

int cekkabisat(int tahun) {
if (tahun % 400==0 || (tahun %400 != 0 && tahun %100 !=0 && tahun%4==0)) return 1;
else return 0;
}

int carihari(int tgl_input,int bln_input,int thn_input)
{   int iskabisat;
    int tgl = 1, bln = 1, thn = 2022, hari = 5;
    int jmlhariperbulan[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while(tgl_input != tgl || bln_input != bln || thn_input != thn)
{
    iskabisat = cekkabisat(thn);
    if (thn == thn_input) {
// tahun sama
        if (bln == bln_input) {
// bulannya sama
                if (tgl < tgl_input) {
                    hari = (hari + (tgl_input-tgl)) % 7;
                    tgl = tgl_input;
                    }

                else
                    { hari = (hari - (tgl-tgl_input)) % 7;
                      hari += 7;
                      tgl = tgl_input;
                    }
 }


        else {
                if (bln < bln_input) {
                        if (bln == 2 && iskabisat==1)     {hari = (hari + 29) % 7;}
                        else    {hari = (hari + jmlhariperbulan[bln-1]) % 7;}
                        bln += 1;
                     }
                 }
 }


 else { if (thn < thn_input) {
        hari = (hari + (iskabisat?366:365)) % 7;
        thn+=1;
        }

    else {
        hari = ((hari - (cekkabisat(thn-1)?366:365))% 7) +7;// + 7;
        if (hari==7) hari=0;
        thn--;
         }
 }
}
return hari;
}



void printbulan(int bln_input,int thn_input)
{
int haripertama = carihari(1,bln_input,thn_input);
int pengulangan = haripertama;
int iskabisat=cekkabisat(thn_input);
char *namabulan[12] = {"Januari", "Februari", "Maret",
"April", "Mei", "Juni", "Juli", "Agustus", "September",
"Oktober","November", "Desember"};
int jmlhariperbulan[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

printf("\n\n-----%s-----\n",namabulan[bln_input-1]);
printf("\n Sen  Sel  Rab  Kam  Jum  Sab  Min \n");
if (iskabisat==1) jmlhariperbulan[1]=29;

for (int asal=1; asal<=haripertama;asal++) //hari haripertama =7
    {
        printf("     ");
    }
for (int i=1; i<=jmlhariperbulan[bln_input-1];i++)
    {
        printf("%3d  ", i);
        if (++pengulangan>6)
        {
            printf("\n");
            pengulangan=0;
        }

    }

}


int main()
{
int tgl_input, bln_input, thn_input;
int hari;
char *namahari[7] = {"Senin", "Selasa", "Rabu",
"Kamis", "Jumat", "Sabtu", "Minggu" };

printf("Masukkan Tanggal: "); scanf("%d", &tgl_input);
printf("Masukkan Bulan: "); scanf("%d", &bln_input);
printf("Masukkan Tahun: "); scanf("%d", &thn_input);

hari=carihari(tgl_input,bln_input,thn_input);
printf("Harinya adalah hari %s ",namahari[hari]);
printbulan(bln_input,thn_input);

return 0;
}
