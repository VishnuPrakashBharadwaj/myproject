// Program for Leaky bucket algorithm

#include<stdio.h> 
#include<stdlib.h> 
struct packet {
    int time; 
    int size;
} p[50]; 

int main(){
    int i,n,m,k=0; 
    int bsize,bfilled,outrate; 
    printf("Enter the number of packets: "); 
    scanf("%d",&n); 
    printf("\nEnter packets in the order of their arrival time "); 
    for(i=0;i<n;i++){
        printf("\nEnter the time and size: "); 
        scanf("%d%d",&p[i].time,&p[i].size);
    } 
    printf("\nEnter the bucket size: "); 
    scanf("%d",&bsize); 
    printf("\nEnter the output rate: "); 
    scanf("%d",&outrate);

    m=p[n-1].time; //time of arrival 
    i=1; 
    k=0; 
    bfilled=0; 
    while(i < m || bfilled != 0){ //packets are arriving in order or not 
        printf("\n at time %d",i); 
        if(p[k].time == i){
            if(bsize >= bfilled+p[k].size){ //check if space is available in bucket  
                bfilled=bfilled+p[k].size; // add the packet into the bucket 
                printf("\n%d byte packet is inserted:",p[k].size); 
                k=k+1;
            }  //next packet  arrives} 
            else {
                printf("\n%d byte packet is discarded",p[k].size);//no space in the bucket so it gets discarded 
                k=k+1;
                }
        }

        if(bfilled==0){ //empty bucket 
            printf("\n no packets transmitted");
        } else if(bfilled >= outrate){
            bfilled=bfilled-outrate; 
            printf("\n %d bytes transferred",outrate);
        } else{
            printf("\n %d bytes transferred",bfilled); 
            bfilled=0;
        }

        printf("\n packets in the bucket %d byte",bfilled); 
        i++;
    } 
return 0;
} 