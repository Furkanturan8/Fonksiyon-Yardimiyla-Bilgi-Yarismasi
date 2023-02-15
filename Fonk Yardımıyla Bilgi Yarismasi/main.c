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
			printf("3)Çýkýþ Yap\n\nSeçiminiz:");
            scanf("%d",&secim);
        return secim;
    }

    int girisYapFonx(){
		system("cls");
        char girilenkul_ad[20];
        char girilensifre[8];
        int kontrol=0;
			printf("Kullanýcý giriþ ekraný...\n\n");
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
		printf("Kullanýcý kayýt ekraný...\n\n");
		printf("Lutfen Kullanicý Adýnýzý Giriniz:"); scanf("%s",&m1.isim);
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
		printf("\nÇýkýþ yapýlýyor...\n");
		return 0;
	}
		
	else {
		printf("\nHatalý Seçim...\n");
		return 0;
	}
		
	if(onay==1){
		sorularFonx();
	}
	else
		printf("Hatali giris,tekrar deneyiniz!!!\n\n");

	printf("Ana menüye dönmek için 1'e , çýkmak için baþka bir tuþa basiniz!  "); 
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

	printf("BÝLGÝ YARIÞMAMIZ BAÞLADI! BOL ÞANSLAR \n\nBilgilendirme: Her sorunun kendine has puanlamasý vardýr. Baþarýlar Dileriz...\n\n");
	printf("------------------------------------------------------------------------------------------\n\n");
	
	for(i=0;i<5;i++){
		
		if(i==0){
		 	printf("SORU 1:Bir iþin uygun ve kolay olduðunu belirtmek için hangisi söylenir?  PUAN DEÐERÝ: 2 PUAN \n\n"
				   "a) Burnuma göre b) Kaþýma Göre c) Býyýðýma göre d) Diþime göre\n\n");
			printf("Yanýtýnýz: "); 
			scanf("%s",&cevap[0]); 	
		
			if(cevap[i]=='d' || cevap[i]=='D'){
				printf("Doðru yanýt! Tebrikler ! Güncel Puanýnýz: 2 \n\n");
				PUAN=2;
				i++;
			}		
			else{
				printf("Yanlýþ yanýt, Cevap D ! Üzgünüm ELENDÝNÝZ! Güncel Puanýnýz: 0 \n\n");
				PUAN=0;
				break;
			}
		}	
		
		if(i==1){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 2: \"Horozu çok olan köyde\" þeklinde baþlayan atasözünün devamý nasýldýr?  PUAN DEÐERÝ: 4 PUAN \n\n"
				   "a)Sabah geç olur b) Akþam geç olur c) Akþam erken olur d) Sabah erken olur \n\n");
			printf("Yanýtýnýz: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='a' || cevap[i]=='A'){
				printf("Doðru yanýt! Tebrikler ! Güncel Puanýnýz: 6 \n\n");
				PUAN+=4;
				i++;
			}		
			else{
				printf("Yanlýþ yanýt, Cevap A ! Üzgünüm ELENDÝNÝZ! Güncel Puanýnýz: %d \n\n",PUAN);
				break;
			}
		}
		
		if(i==2){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 3:Çubuklara geçirilmiþ küçük bayraklarla iþaretlenmiþ bir parkurda, belli kurallara göre\n ve zikzaklar çizerek yapýlan kayak yarýþý hangisidir?  PUAN DEÐERÝ: 10 PUAN \n\n"
				   "a) Skeleton b)Slalom c) Pentatlon d) Maraton \n\n");
			printf("Yanýtýnýz: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='b' || cevap[i]=='B' ){
				PUAN+=10;
				printf("Doðru yanýt! Tebrikler ! Güncel Puanýnýz: %d \n\n",PUAN);
				i++;
			}		
			else{
				printf("Yanlýþ yanýt, Cevap B ! Üzgünüm ELENDÝNÝZ! Güncel Puanýnýz: %d \n\n",PUAN);
				break;
			}
		}
		
		if(i==3){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 4: Gövdesi sarý veya kirli sarý; yelesi, kuyruðu ve bacaðýnýn alt kýsmýndaki\n kýllarý koyu renkte olan atlar içi kullanýlan ifade hangisidir?  PUAN DEÐERÝ: 14 PUAN \n\n"
				   "a) Doru b) Yaðýz  c) Kula  d) Seki \n\n");
			printf("Yanýtýnýz: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='c' || cevap[i]=='C'){
				PUAN+=14;
				printf("Doðru yanýt! Tebrikler ! Güncel Puanýnýz: %d \n\n",PUAN);
				i++;
			}		
			else{
				printf("Yanlýþ yanýt, Cevap C ! Üzgünüm ELENDÝNÝZ! Güncel Puanýnýz: %d \n\n",PUAN);
				break;
			}
		}
		
		if(i==4){
			printf("------------------------------------------------------------------------------------------\n\n");

		 	printf("SORU 4: Hangisi, 1980'li yýllarýn ünlü dizisi \"A Takýmý\"nýn karakterlerinden biri deðildir?  PUAN DEÐERÝ: 20 PUAN \n\n"
				   "a) Albay John Smith b) Yüzbaþý Murdock c) Komutan Logar d) B. A  \n\n");
			printf("Yanýtýnýz: "); 
			scanf("%s",&cevap[i]); 	
		
			if(cevap[i]=='c' || cevap[i]=='C' ){
				PUAN+=20;
				printf("Doðru yanýt! Tebrikler ! Güncel Puanýnýz: %d \n\n",PUAN);
				i++;
			}		
			else{
				printf("Yanlýþ yanýt, Cevap C ! Üzgünüm ELENDÝNÝZ! Güncel Puanýnýz: %d \n\n",PUAN);
				break;
			}
		}
			
	}
	printf("\nYarýþma Sonu Puanýnýz : %d\n",PUAN);
	m1.PUAN=PUAN;
	FILE* ptr=fopen("puanlar.txt","a");
	fwrite(&m1,sizeof(kullanici1),1,ptr);
	fclose(ptr);
}
