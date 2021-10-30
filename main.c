#include <stdio.h>
#include <math.h>
#include <time.h>

#define CARD_POOL 10000 // �d��
#define DAWR_COUNT 1000000 // �d���������

typedef struct _cardProbability // �d�����c 
{
	int id;	// �ѧO�� 
    double probability; // ���v 
    char *name;	// �W�� 
} cardProbability_t;

// ���v�}�C 
int * probabilityArr;
int pIndex = 0;
// �d���d���q 
int cardCount1,cardCount2,cardCount3,totalCardCount;
// �έp������G 
int sum1=0,sum2=0,sum3=0;
// �d��
cardProbability_t *cpt1,*cpt2,*cpt3;

int main(void)                           
{      
	cpt1 = malloc(sizeof(cardProbability_t));
	cpt1->id = 1;
	cpt1->probability = 2.5;// �⤤�v2.5% 
	cpt1->name = "SSR�d��"; 
	
	cpt2 = malloc(sizeof(cardProbability_t));
	cpt2->id = 2;
	cpt2->probability = 40;// �⤤�v40%
	cpt2->name = "R�d��";
	
	cpt3 = malloc(sizeof(cardProbability_t));
	cpt3->id = 3;
	cpt3->probability = 57.5;// �⤤�v57.5%
	cpt3->name = "N�d��";
	
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
	
	srand(time(NULL)); // ��l�üƺؤl 
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
	
	printf("�]�w�d�����v�ƭ�:\n");
	printf("%s���v: %.3f%%\n",cpt1->name,cpt1->probability);
	printf("%s���v: %.3f%%\n",cpt2->name,cpt2->probability);
	printf("%s���v: %.3f%%\n",cpt3->name,cpt3->probability); 
	printf("\n");
	printf("������%d�����G:\n",DAWR_COUNT);
	printf("��X%s: %d���A���v:%.3f%%\n",cpt1->name,sum1,sum1/(double)DAWR_COUNT*100);
	printf("��X%s: %d���A���v:%.3f%%\n",cpt2->name,sum2,sum2/(double)DAWR_COUNT*100);
	printf("��X%s: %d���A���v:%.3f%%\n",cpt3->name,sum3,sum3/(double)DAWR_COUNT*100);
	
	return 0;
}
