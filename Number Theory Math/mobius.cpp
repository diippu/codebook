int mobius[MAX+5]; 
   int pcount[MAX+5];
   void mymobius() {
     mobius[1] = 1;
    for(int i = 2; i <= 500010; i++) {
      if(pcount[i]==0) {
        mobius[i] =-1;
        for(int j = 2; j*i <= 500010; j++) {
          if(j%i == 0) {
            pcount[i*j] = -1;
          } else if(pcount[i*j] != -1) pcount[i*j]++;
        }
      } else if(pcount[i] == -1) mobius[i] = 0;
      else mobius[i] = ((pcount[i]%2 == 0) ? 1 : -1);
    }
   }