#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void sorularFonx();

	typedef struct Kullanici{
		char isim[20];
	    char sifre[8];
	    int PUAN;
	}kullanici1;
		
	kullanici1 m1;
	
	int girisFonx(){

        printf("Bilgi Yarismasina Hosgeldiniz!\n");
        printf("Yarismamiz puan sistemlidir..\n");
        printf("Lutfen kullanici adi ve sifrenizi dogru giriniz!\n");
        printf("Eger hesabiniz yoksa kayit olunuz.");
		   
		   int secim;
            printf("\n\nLutfen asagidakilerden birisini seciniz\n");
            printf("1)Giris Yap\n");
            printf("2)Kayit Ol\n");
			printf("3)��k�� Yap\n\nSe�iminiz:");
            scanf("%d",&secim);
        return secim;
    }

    int girisYapFonx(){
		system("cls");
        char girilenkul_ad[20];
        char girilensifre[8];
        int kontrol=0;
			printf("Kullan�c� giri� ekran�...\n\n");
            printf("Kullanici adinizi giriniz:");
    	        scanf("%s",&girilenkul_ad);
	        printf("Sifrenizi giriniz:");
        	    scanf("%s",&girilensifre);
            
            FILE * kayitPtr=fopen("kayitlar.dat","r+b");
			while(fread(&m1,sizeof(kullanici1),1,kayitPtr)!=NULL){
	
				if(strcmp(girilenkul_ad,m1.isim)==0 && strcmp(girilensifre,m1.sifre)==0){
                	printf("Sisteme Hosgeldiniz\n\n");
                	kontrol=1;
            	}			
			}
			fclose(kayitPtr);
		
		return kontrol;
	}

    int kayitOlFonx(){
		system("cls");
		printf("Kullan�c� kay�t ekran�...\n\n");
		printf("Lutfen Kullanic� Ad�n�z� Giriniz:"); scanf("%s",&m1.isim);
	    printf("\nLutfen Sifrenizi Giriniz:"); scanf("%s",&m1.sifre);
	
		FILE * kayitPtr=fopen("kayitlar.dat","w+b");
		fwrite(&m1,sizeof(kullanici1),1,kayitPtr);
		fclose(kayitPtr);	
	    printf("Kaydiniz Basarili Olmustur,Giris Ekranina Yonlendiriliyorsunuz...\n\n");
	
	    girisYapFonx();
    }	

 	

int main()
{	
anamenu:
	system("cls"); 
	setlocale(LC_ALL,"Turkish");
    int onay,a;
    int secim=girisFonx();

    if(secim==1)
   		onay=girisYapFonx();
    else if(secim==2)
        kayitOlFonx();
   
   	else if(secim==3){
		printf("\n��k�� yap�l�yor...\n");
		return 0;
	}
		
	else {
		printf("\nHatal� Se�im...\n");
		return 0;
	}
		
	if(onay==1){
		sorularFonx();
	}
	else
		printf("Hatali giris,tekrar deneyiniz!!!\n\n");

	printf("Ana men�ye d�nmek i�in 1'e , ��kmak i�in ba�ka bir tu�a basiniz!  "); 
	scanf("%d",&a);
	
	if(a==1)
		goto anamenu;	

    return 0;
}

void sorularFonx(){
	
	system("cls");
	int i=0;
	int PUAN=0;
	char cevap[10];

	printf("B�LG� YARI�MAMIZ BA�LADI! BOL �ANSLAR \n\nBilgilendirme: Her sorunun kendine has puanlamas� vard�r. Ba�ar�lar Dileriz...\n\n");
	printf("------------------------------------------------------------------------------------------\n\n");
	
	for(i=0;i<5;i++){
		
		if(i==0){
		 	printf("SORU 1:Bir i�in uygun ve kolay oldu�unu belirtmek i�in hangisi s�ylenir?  PUAN DE�ER�: 2 PUAN \n\n"
				   "a) Burnuma g�re b) Ka��ma G�re c) B�y���ma g�re d) Di�ime g�re\n\n");
			printf("Yan�t�n�z: "); 
			scanf("%s",&cevap[0]); 	
		
			if(cevap[i]=='d' || cevap[i]=='D'){
				printf("Do�ru yan�t! Tebrikler ! G�ncel Puan�n�z: 2 \n\n");
				PUAN=2;
				i++;
			}		
			else{
				printf("Yanl�� yan�t, Cevap D ! �zg�n�m ELEND�N�Z! G�ncel Puan�n�z: 0 \n\n");
				PUAN=0;
				break;
			}
		}	
		
		if(i==1){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 2: \"Horozu �ok olan k�yde\" �eklinde ba�layan atas�z�n�n devam� nas�ld�r?  PUAN DE�ER�: 4 PUAN \n\n"
				   "a)Sabah ge� olur b) Ak�am ge� olur c) Ak�am erken olur d) Sabah erken olur \n\n");
			printf("Yan�t�n�z: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='a' || cevap[i]=='A'){
				printf("Do�ru yan�t! Tebrikler ! G�ncel Puan�n�z: 6 \n\n");
				PUAN+=4;
				i++;
			}		
			else{
				printf("Yanl�� yan�t, Cevap A ! �zg�n�m ELEND�N�Z! G�ncel Puan�n�z: %d \n\n",PUAN);
				break;
			}
		}
		
		if(i==2){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 3:�ubuklara ge�irilmi� k���k bayraklarla i�aretlenmi� bir parkurda, belli kurallara g�re\n ve zikzaklar �izerek yap�lan kayak yar��� hangisidir?  PUAN DE�ER�: 10 PUAN \n\n"
				   "a) Skeleton b)Slalom c) Pentatlon d) Maraton \n\n");
			printf("Yan�t�n�z: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='b' || cevap[i]=='B' ){
				PUAN+=10;
				printf("Do�ru yan�t! Tebrikler ! G�ncel Puan�n�z: %d \n\n",PUAN);
				i++;
			}		
			else{
				printf("Yanl�� yan�t, Cevap B ! �zg�n�m ELEND�N�Z! G�ncel Puan�n�z: %d \n\n",PUAN);
				break;
			}
		}
		
		if(i==3){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 4: G�vdesi sar� veya kirli sar�; yelesi, kuyru�u ve baca��n�n alt k�sm�ndaki\n k�llar� koyu renkte olan atlar i�i kullan�lan ifade hangisidir?  PUAN DE�ER�: 14 PUAN \n\n"
				   "a) Doru b) Ya��z  c) Kula  d) Seki \n\n");
			printf("Yan�t�n�z: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='c' || cevap[i]=='C'){
				PUAN+=14;
				printf("Do�ru yan�t! Tebrikler ! G�ncel Puan�n�z: %d \n\n",PUAN);
				i++;
			}		
			else{
				printf("Yanl�� yan�t, Cevap C ! �zg�n�m ELEND�N�Z! G�ncel Puan�n�z: %d \n\n",PUAN);
				break;
			}
		}
		
		if(i==4){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 4: Hangisi, 1980'li y�llar�n �nl� dizisi \"A Tak�m�\"n�n karakterlerinden biri de�ildir?  PUAN DE�ER�: 20 PUAN \n\n"
				   "a) Albay John Smith b) Y�zba�� Murdock c) Komutan Logar d) B. A  \n\n");
			printf("Yan�t�n�z: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='c' || cevap[i]=='C' ){
				PUAN+=20;
				printf("Do�ru yan�t! Tebrikler ! G�ncel Puan�n�z: %d \n\n",PUAN);
				i++;
			}		
			else{
				printf("Yanl�� yan�t, Cevap C ! �zg�n�m ELEND�N�Z! G�ncel Puan�n�z: %d \n\n",PUAN);
				break;
			}
		}
			
	}
	printf("\nYar��ma Sonu Puan�n�z : %d\n",PUAN);
	m1.PUAN=PUAN;
	FILE* ptr=fopen("puanlar.txt","a");
	fwrite(&m1,sizeof(kullanici1),1,ptr);
	fclose(ptr);
}
