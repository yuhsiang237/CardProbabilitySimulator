/********************************************************************
CardProbabilitySimulator
Author:Yu Hsiang
Date:2021-10-30
Link:https://github.com/yuhsiang237/CardProbabilitySimulator
********************************************************************/
#include <stdio.h>
#include <math.h>
#include <time.h>

#define CARD_POOL 10000 // 卡池
#define DAWR_COUNT 1000000 // 卡片抽取次數

typedef struct _cardProbability 
{
    double probability; // 機率 
    char *name;	// 名稱 
} cardProbability_t;

// 卡片
cardProbability_t cpts[] = 
{
	{2.5,"SSR卡片"},{40,"R卡片"},{57.5,"N卡片"}
};
int cptsSize=sizeof(cpts)/sizeof(cardProbability_t);
// 抽卡機率陣列 
int * probabilityArr;
int pIndex = 0;
// 卡池內卡片量 
int *cardCountArr;
int totalCardCount;
// 統計抽取結果陣列
int *drawSumArr;

int getTotalCardCount(int * arr,int size); // 取得卡片加總數 
 
int main()                           
{   
	cardCountArr=(int *)malloc(cptsSize*sizeof(int));
	drawSumArr=(int *)malloc(cptsSize*sizeof(int));
	for(int i=0;i<cptsSize;i++) // 依照機率建立卡片量 
	{	
		cardCountArr[i] = cpts[i].probability/100.0f*CARD_POOL;
	}
	totalCardCount = getTotalCardCount(cardCountArr,cptsSize);
	probabilityArr = (int*)malloc(totalCardCount*sizeof(int));
	for(int i=0;i<cptsSize;i++) // 建置抽卡機率陣列 
	{
		int cardCount = cardCountArr[i]; // 卡片量 
		for(int j=0;j<cardCount;j++)
		{	
			probabilityArr[pIndex++] = i; 
		}
	}
	srand((unsigned)time(NULL)); // 初始亂數種子 
	for(int i=0;i<cptsSize;i++)
	{
		drawSumArr[i] = 0; 
	}
	for(int i=0;i<DAWR_COUNT;i++) // 開始抽取
	{
		int drawIndex=(rand()%(int)totalCardCount);  // 抽中卡片  
		for(int j=0;j<cptsSize;j++)
		{
			if(probabilityArr[drawIndex] == j)
			{
				drawSumArr[j]++; // 累加卡片抽中次數 
				break;
			} 
		}
	}
	printf("設定卡片機率數值:\n");
	for(int i=0;i<cptsSize;i++)
	{
		printf("%s機率: %.3f%%\n",cpts[i].name,cpts[i].probability);
	}
	printf("\n");
	printf("模擬抽%d次結果:\n",DAWR_COUNT);
	for(int i=0;i<cptsSize;i++)
	{
		printf("抽出%s: %d次，機率:%.3f%%\n",cpts[i].name,drawSumArr[i],drawSumArr[i]/(double)DAWR_COUNT*100);
	}
	return 0;
}

// 取得卡片加總數 
int getTotalCardCount(int * arr,int size)
{
	int total = 0;
	for(int i=0;i<size;i++)
	{
		total +=arr[i];
	}
	return total;
}
