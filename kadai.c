#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	double science[20]
	={65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70};
	double english[20]
	={44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84};
	
	double hensachi_s[20]={0};
	double hensachi_e[20]={0};

	double ave_s=0,ave_e=0,hyo_s=0,hyo_e=0,sum_s,sum_e;
	double hyo_ss,hyo_ee;
	int i,j;
	double temp_s,temp_e;

	for(i=0; i<20; i++){
		ave_s += science[i];
		ave_e += english[i];
	}
	
	sum_s = ave_s;
	sum_e = ave_e;
	
	ave_s /= 20.0;
	ave_e /= 20.0;

	for(i=0; i<20; i++){
		hyo_s += (science[i] - ave_s) * (science[i] - ave_s);
		hyo_e += (english[i] - ave_e) * (english[i] - ave_e);
	}
	hyo_s /= 20.0;
	hyo_e /= 20.0;
	
 	hyo_ss = sqrt(hyo_s);
	hyo_ee = sqrt(hyo_e);
	
	for(i=0; i<20; i++){
		hensachi_s[i]=50+10*((science[i]-ave_s)/hyo_ss);
		hensachi_e[i]=50+10*((english[i]-ave_e)/hyo_ee);
	}

	for (i=0; i<19; i++) {
		for (j=19; j>i; j--) {
			if (science[j-1] < science[j]) {
				temp_s = science[j];
				science[j] = science[j-1];
				science[j-1]= temp_s;
			}
		}	
	}
	
	for (i=0; i<19; i++) {
		for (j=19; j>i; j--) {
			if (english[j-1] < english[j]) {
				temp_e = english[j];
				english[j] = english[j-1];
				english[j-1]= temp_e;
			}
		}	
	}

	printf("理科\n");
	printf("平均点=%f\n",ave_s);
	printf("標準偏差=%f\n",hyo_ss);
	printf("合計点=%f\n",sum_s);

	printf("\n");

	printf("英語\n");
	printf("平均点=%f\n",ave_e);
	printf("標準偏差=%f\n",hyo_ee);
	printf("合計点=%f\n",sum_e);
	
	printf("\n");

	printf("理科の偏差値\n");
	for(i=0; i<20; i++){
		printf("%d人目：%f\n",i+1,hensachi_s[i]);
	}
	printf("\n");

	printf("英語の偏差値\n");
	for(i=0; i<20; i++){
		printf("%d人目：%f\n",i+1,hensachi_e[i]);
	}
	printf("\n");

	printf("理科の点数（高い順）\n");
	for(i=0;i<20;i++){
		printf("%f\n",science[i]);
	}
	printf("\n");

	printf("英語の点数（高い順）\n");
	for(i=0;i<20;i++){
		printf("%f\n",english[i]);
	}
	printf("\n");

	return 0;
}