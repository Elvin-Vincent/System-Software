#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inihead, n, totheadmov= 0, i, totsize, dir, j, temp, index;
    printf("No. of Requests: ");
    scanf("%d", &n);
    
    int rq[n];
    printf("Request sequence:\n");
    for(i= 0; i< n; i++)
        scanf("%d", &rq[i]);

    printf("Initial head position: ");
    scanf("%d", &inihead);

    printf("Total disk size: ");
    scanf("%d", &totsize);
    printf("Head movement direction (1:high & 0:low) : ");
    scanf("%d", &dir);

    for(i= 0; i< n; i++)
    {
        for(j= 0; j< n- i- 1; j++)
        {
            if(rq[j]> rq[j+ 1])
            {
                temp= rq[j];
                rq[j]= rq[j+ 1];
                rq[j+ 1]= temp;
            }
        }
    }

    for(i= 0; i< n; i++)
    {
        if(rq[i]> inihead)
        {
            index= i;
            break;
        }
    }

    if(dir == 1)
    {
        for(i= index; i< n; i++)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i]; 
        }
       
        totheadmov += abs((totsize- 1)- inihead);
        inihead= totsize- 1;
        
        totheadmov += abs(0- inihead);
        inihead= 0;
     
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i];
        }
    }

    if(dir == 0)
    {
        for(i= index- 1; i>= 0; i--)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i]; 
        }
        
        totheadmov += abs(0- inihead);
        inihead= 0;
        
        totheadmov += abs((totsize- 1)- inihead);
        inihead= totsize- 1;
       
        for(i= totsize- 1; i>= index; i--)
        {
            totheadmov += abs(rq[i]- inihead);
            inihead= rq[i];
        }
    }
    printf("Total head movement = %d\n", totheadmov);
    return 0;
}
