#define MAX 150
char Times[MAX]; // filled with spaces
char bestTimes[MAX];
int bestj,bestk,bestl;
int ScheduleFinder(int ta, int tb, int tc, int td){
  int i,j,k,l; int jitter=0; 
  int thei,thejitter;   // find schedule for task b with min jitter
  jitter = 100000;
  for(j=0; j<tb; j++){      // slide factor task B
    for(k=0; k<tc; k++){    // slide factor task C
      for(l=0; l<td; l++){  // slide factor task D
        for(i=0; i<MAX; i++) Times[i] = ' '; // space means time not used
        for(i=0; i<MAX; i=i+ta) Times[i] = 'a'; // schedule task a
        thejitter = 0;
        for(i=j; i<MAX; i=i+tb){
          if(Times[i]== ' '){
            Times[i] = 'b'; // schedule B no jitter
          } else{
            thei = i;  // search for place to schedule
            do{
              thei++;
              thejitter++;
            }
            while(Times[thei]!= ' '&&thei<MAX);
            if(thei<MAX) Times[thei] = 'B'; // schedule B with jitter
          }
        }
        for(i=k; i<MAX; i=i+tc){
          if(Times[i]== ' '){
            Times[i] = 'c'; // schedule C no jitter
          } else{
            thei = i;  // search for place to schedule
            do{
              thei++;
              thejitter++;
            }
            while(Times[thei]!= ' '&&thei<MAX);
            if(thei<MAX) Times[thei] = 'C'; // schedule C with jitter
          }
        }
        for(i=l; i<MAX; i=i+td){
          if(Times[i]== ' '){
            Times[i] = 'd'; // schedule D no jitter
          } else{
            thei = i;  // search for place to schedule
            do{
              thei++;
              thejitter++;
            }
            while(Times[thei]!= ' '&&thei<MAX);
            if(thei<MAX) Times[thei] = 'D'; // schedule D with jitter
          }
        }
        if(thejitter<jitter){
          bestj = j;  bestk = k; bestl = l;
          jitter = thejitter;
          for(i=0; i<MAX; i++) bestTimes[i] = Times[i]; // best schedule
        }
      }
    }
  }
  return jitter;
}
