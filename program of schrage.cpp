#include<stdio.h>
#include<time.h>
#include<math.h>
main()
    {   
        double x,y;                 /* �����ȡ��ά�����ı���x,y */
        FILE *p;                   
        void xk();
        void cl();                  /* �������� */
        double rands();
        long int i;
        p=fopen("1.dat","w");
        for(i=0;i<1000;i++){      /* ����1000����ά����� */
        x=rands();
        y=rands();
        printf("%f\t%f\n",x,y);
        fprintf(p,"%f\t%f\n",x,y);
        }

        fclose(p);
        xk();
        cl();                    /* �������� */

        getchar();                /* ��ͣ��Ļ */
    }

double rands()                    /* ��������� */
  {     static long int z,i=0;
        double x;
        if(i==0){
       time_t rawtime;
        time(&rawtime);               /* ȡ��ǰʱ��Ϊ����ֵ */
       z=rawtime;
        i++;}    /* zΪstatic������ֻ�ڵ�һ�ε���ʱ��ʼ�� */
      z=16807*(z%127773)-2836*(z/127773);
      if(z<0) z=z+2147483647;
      x=(double)z/2147483647;
      return(x);

   }


  void xk(){                                  /* x^k���� */
       float x,y,z=0.0,sum,sum1,t;long int N,k;
       FILE *p1;
       p1=fopen("2.txt","w");
       printf("\n\n��������XK\n");
       fprintf(p1,"\n\n��������XK\n");
       for(k=1;k<4;k++)
         {   z=0.0;
            printf("\n�������Ĳ���K��ֵΪ%d\n         N\t    <xk>\t|<xk>-C|\t1/N^0.5\n",k);
            fprintf(p1,"\n�������Ĳ���K��ֵΪ%d\n         N\t    <xk>\t|<xk>-C|\t1/N^0.5\n",k);
            for(N=1;N<=10000000;N++)
              {
                 x=rands();
                 y=pow(x,k);
                 z=z+y;
                 if(N==10||N==100||N==1000||N==10000||N==100000||N==1000000||N==10000000)
                    {
                       sum=z/(double)N;
                       sum1=fabs(sum-1/((double)k+1)); t=1/pow(N,0.5);
                       printf("%10d\t%f\t%f\t%f\n",N,sum,sum1,t);
                       fprintf(p1,"%10d\t%f\t%f\t%f\n",N,sum,sum1,t);


                     }
                }
           }
       fclose(p1);
    }
void cl(){                                  /* ����C L */
         double x1,x2,y=0,sum,t,s;long int N;
         FILE *p2;
         p2=fopen("3.txt","w");
         x1=rands();
         printf("\n\n����CL����\n\n         N\t      Cl\t|Cl-0.25|\t1/N^0.5\n");

         fprintf(p2,"\n\n����CL����\n\n         N\t      Cl\t|Cl-0.25|\t1/N^0.5\n");
         for(N=1;N<=10000000;N++)
             {
                 x2=rands();
                 y=y+x1*x2;
                 x1=x2;
                 if(N==10||N==100||N==1000||N==10000||N==100000||N==1000000||N==10000000)
                     {
                       sum=y/(double)N;s=fabs(sum-0.25);t=1/pow(N,0.5);
                       printf("%10d\t%f\t%f\t%f\n",N,sum,s,t);
                       fprintf(p2,"%10d\t%f\t%f\t%f\n",N,sum,s,t);
                       
                      }
              }
         fclose(p2);
      }




