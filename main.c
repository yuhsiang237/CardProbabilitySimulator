#include <stdio.h>
#include <math.h>
#include <time.h>

#define CARD_POOL 10000 // 卡池
#define DAWR_COUNT 1000000 // 卡片抽取次數

typedef struct _cardProbability // 卡片結構 
{
    int id;	// 識別值 
    double probability; // 機率 
    char *name;	// 名稱 
} cardProbability_t;

// 機率陣列 
int * probabilityArr;
int pIndex = 0;
// 卡池卡片量 
int cardCount1,cardCount2,cardCount3,totalCardCount;
// 統計抽取結果 
int sum1=0,sum2=0,sum3=0;
// 卡片
cardProbability_t *cpt1,*cpt2,*cpt3;

int main(void)                           
{      
	cpt1 = malloc(sizeof(cardProbability_t));
	cpt1->id = 1;
	cpt1->probability = 2.5;// 抽中率2.5% 
	cpt1->name = "SSR卡片"; 
	
	cpt2 = malloc(sizeof(cardProbability_t));
	cpt2->id = 2;
	cpt2->probability = 40;// 抽中率40%
	cpt2->name = "R卡片";
	
	cpt3 = malloc(sizeof(cardProbability_t));
	cpt3->id = 3;
	cpt3->probability = 57.5;// 抽中率57.5%
	cpt3->name = "N卡片";
	
	cardCount1 = cpt1->probability/100.0f*CARD_POOL;
	cardCount2 = cpt2->probability/100.0f*CARD_POOL;
	cardCount3 = cpt3->probability/100.0f*CARD_POOL;
	totalCardCount = cardCount1+cardCount2+cardCount3; 
	
	probabilityArr = (int*)malloc((int)totalCardCount*sizeof(int));
	
	for(int i=0;i<cardCount1;i++)
	{
		probabilityArr[pIndex++] = cpt1->id;
	}
	for(int i=0;i<cardCount2;i++)
	{
		probabilityArr[pIndex++] = cpt2->id;
	}
	for(int i=0;i<cardCount3;i++)
	{
		probabilityArr[pIndex++] = cpt3->id;
	}	
	
	srand(time(NULL)); // 初始亂數種子 
	for(int i=0;i<=DAWR_COUNT;i++)
	{
		int resultIndex=(rand()%(int)totalCardCount);
		if(probabilityArr[resultIndex]==cpt1->id)
			sum1++;
		if(probabilityArr[resultIndex]==cpt2->id)
			sum2++;
		if(probabilityArr[resultIndex]==cpt3->id)
			sum3++;
	} 
	
	printf("設定卡片機率數值:\n");
	printf("%s機率: %.3f%%\n",cpt1->name,cpt1->probability);
	printf("%s機率: %.3f%%\n",cpt2->name,cpt2->probability);
	printf("%s機率: %.3f%%\n",cpt3->name,cpt3->probability); 
	printf("\n");
	printf("模擬抽%d次結果:\n",DAWR_COUNT);
	printf("抽出%s: %d次，機率:%.3f%%\n",cpt1->name,sum1,sum1/(double)DAWR_COUNT*100);
	printf("抽出%s: %d次，機率:%.3f%%\n",cpt2->name,sum2,sum2/(double)DAWR_COUNT*100);
	printf("抽出%s: %d次，機率:%.3f%%\n",cpt3->name,sum3,sum3/(double)DAWR_COUNT*100);
	
	return 0;
}
