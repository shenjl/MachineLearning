#include<stdio.h>
/*
    问题：菜鸟仓库是一个很大很神奇的地方，各种琳琅满目的商品整整齐齐地摆放在一排排货架上，通常一种品类(sku)的商品会放置在货架的某一个格子中，格子设有统一的编号，方便工人们拣选。 有一天沐哲去菜鸟仓库参观，无意中发现第1个货架格子编码为1，第2-3个分别为1,2，第4-6个格子分别是1，2，3，第7-10个格子编号分别是1,2,3,4，每个格子编号都是0-9中的一个整数，且相邻格子的编号连在一起有如下规律 1|12|123|1234|...|123456789101112131415|...|123456789101112131415……n 这个仓库存放的商品品类非常丰富，共有1千万多个货架格子。沐哲很好奇，他想快速知道第k个格子编号是多少？ 
    思路：
      1.易知编号的规律是每一部分为上一部分加1（并非格子编号，格子编号只能是0-9的个位数）；
      2.设置一个标记项flag用来记录当前部分的最大值，用count作为局部计数器来对每一部分进行计数；
      3.i遍历1到n，每次count值达到flag值大小时count重新计数，flag自增；
      4.每次取count中一位数，从高位到低位取，每取一位i值加1，当i==n时返回当前取到的位值。
    例如：
      1|12|123|1234|12345|123456|1234567|12345678|123456789|12345678910|
      当n=10时，格子编号为4；当n=55时，格子编号为;1；当n=56时，格子编号为0
 */
int power(int x, int n)
{
	if(n==1)
		return x;
	if(n==0)
		return 1;
	return x*power(x, n-1);
}

int get(int n){

	int x, j, m;
	int flag=1, count=0;

	for(int i=1; i<=n; ){
		count++;
		
		j = count;
		m = 0;	// digit
		while(j>0){
			// 计算count多少位
			j = j/10;
			m++;
		}
		while(m>0){
			x = (count/power(10, m-1))%10;	// 取count中的第m位
			if(i == n)
				return x;
			m--;
			i++;
		}

		if(flag==count){
			flag++;
			count = 0;
		}
	}

	return x;
}
int main(){
	int n;
	//scanf("%d", &n);
	for(n=1; n<10000; n++){
		int r = get(n);
		printf("%d",r);
	}
	printf("\n");

	return 0;
}