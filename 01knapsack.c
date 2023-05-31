#include <stdio.h>
 
int max(int a, int b) { return (a > b)? a : b; }

void knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main()
{
      float wt[20], val[20], ratio[20], W, temp;
    int num, i, j; 

    printf("enter the no of objects\n");
    scanf("%d", &num);

    printf("enter the weights and profits of each object\n");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &wt[i], &val[i]);
    }
    printf("enter the total capacity of knapsack\n");
    scanf("%f", &W);

    for (i = 0; i < num; i++)
    {
        ratio[i] = val[i] / wt[i];
    }
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                temp = wt[j];
                wt[j] = wt[i];
                wt[i] = temp;

                temp = val[j];
                val[j] = val[i];
                val[i] = temp;
            }
        }
    }
    knapsack(W, wt, val, num);
    return 0;

}
