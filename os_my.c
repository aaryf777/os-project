#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int bt[20],at[10],n,n2,n3,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10],te[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    //Level 1 code
    printf("Enter the number of process in Level 1:");
    scanf("%d",&n);n2=n;
    for(i=0; i<n; i++)
    {
		printf("Enter name of process : ");
 		scanf("%s",&pn[i]);
 		
		printf("Enter process %d Arrival time: ",i+1);
		scanf("%d",&at[i]);
		
		printf("Enter process %d burst time: ",i+1);
		scanf("%d",&bt[i]);

		printf("Enter process %d priority: ",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
    }
    
    // Level 2 code

     int k,ts,temp2=0;
     int aw; float awt2;
     int bt2[10],wt2[10],te2[10],rt2[10],at2[10];j=0;
     char pn2[10][10];
     printf("\nenter number of process in Level2:\t");
     scanf("%d",&n3);
    for(i=0;i<n3;i++)
      {
      	 printf("Enter name of process : ");
 		 scanf("%s",&pn2[i]);
          printf("%d  \nbrust time : ");
          scanf("%d",&bt2[i]);
          printf("ariavl time : ");
          scanf("%d",&at2[i]);
          te2[i]=0;     wt2[i]=0;
      }
    for(i=0;i<n3;i++)
      {
        for(j=i+1;j<n3;j++)
         {
             if(at2[i]>at2[j])      //sorting according to arrival time
               {
                    temp2=at2[i];                                          
                    at2[i]=at2[j];
                    at2[j]=temp;
                    temp=bt2[i];
                    bt2[i]=bt2[j];
                    bt2[j]=temp;
              }
         }
     }
    printf("\n enter time quantum : ");
    scanf("%d",&ts); int q=0;
    printf("\nprocess  :")  ;
    for(i=0;i<n3;i++)
     {
       printf("  %d",i+1);
      }
    printf("\nBrust time : ");
    for(i=0;i<n3;i++)
       {
         printf("  %d",bt2[i]); rt2[i]=bt2[i];
        }
    printf("\nArrival time :");
    for(i=0;i<n;i++)
      {
          printf(" %d",at2[i]);
      }
    j=0;

    while(j<=n)
       {
          j++;
          for(i=0;i<n3;i++)
            {
              if(rt2[i]==0)  continue;
                   if(rt2[i]>ts)
                     {
                        q=q+ts;
                        rt2[i]=rt2[i]-ts;
                        te2[i]=te2[i]+1;
                     }
                  else
                    {
                       wt2[i]=q-te2[i]*ts;
                       q=q+rt2[i]; 
                       rt2[i]=rt2[i]-rt2[i];
                    }
            }
       }                                   //end of while     
    awt2=0;
    printf("\n Process   Waitnig time");
    for(i=0;i<n3;i++)
       {
                       wt2[i]=wt2[i]-at2[i];
                       awt2=awt2+wt2[i];
        }
		int tat[10];
        for(i=0;i<n;i++)
        {
        	tat[i]=wt[i]+bt[i];	
		}
		int tat2[10];
		for(i=0;i<n3;i++)
		{
			tat2[i]=wt2[i]+bt2[i];
		}
		printf("\nPname\tArrival time\tBurst time\tpriority\tTAtime\t\tWaiting time");
    	for(i=0;i<n;i++)
		{
       		printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],bt[i],p[i],tat[i],wt[i]);
       	}
       	for(i=0;i<n3;i++)
		{
			printf("\n%s\t%5d\t\t%5d\t\t\t\t%5d\t\t%5d",pn2[i],at2[i],bt2[i],tat2[i],wt2[i]);
		}
	for(i=0;i<n;i++) // sum of TAT
	{
		totta=totta+tat[i];
	}
	for(i=0;i<n3;i++)
	{
		totta=totta+tat2[i];
	}
    aw=awt2+totwt;
    float total=(float)aw/(n2+n3);
    float total2=(float)totta/(n2+n3);
    printf("\nTotal TAtime : %d",totta);
    printf("\nTotal waiting time : %d",aw);
    printf("\n Avg TAtime %f: ",total2);
    printf("\n Avg wainting time %f: ",total);
    getch();
    
}

