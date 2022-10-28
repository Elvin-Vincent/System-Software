#include<stdio.h>
int main()
{
    int np, nf, i, j, pagefault= 0, f_count= 0;
    printf("Enter the no. of pages requested by the CPU: ");
    scanf("%d", &np);
    printf("Enter the total number of frames in memory: ");
    scanf("%d", &nf);

    int p[np], f[nf];
    printf("Enter reference string:\n");
    for(i= 0; i< np; i++)
        scanf("%d", &p[i]);

    
    for(j= 0; j< nf; j++)
        f[j]= -1;
    
    printf("Frame 1\tFrame 2\tFrame 3\tFrame 4\n");
    
    for(i= 0; i< np; i++)
    {
        for(j= 0; j< nf; j++)   //hit
            if(p[i] == f[j])   
                break;       
        
        if(j == nf)   //miss
        {
            pagefault++;

            if(f_count< nf) // vacant
            {	 
                f[f_count]= p[i];
                f_count++;
			}

            else      // occupied
            {
                int k, maxdist= 0, index, distance[nf];
                for(j= 0; j< nf; j++)
                {
                    distance[j]= 0;
                    for(k= i- 1; k>= 0; k--)
                    {
                        distance[j]++;
                        if(f[j] == p[k])
                            break;
                    }
                    if(distance[j]> maxdist)
                    {
                        maxdist= distance[j];
                        index= j;
                    }
                }
                f[index]= p[i];
            }
        }

        for(j= 0; j< nf; j++)
            printf("%d\t", f[j]);
        printf("\n");
    }
    printf("Total page faults = %d\n", pagefault);
}
