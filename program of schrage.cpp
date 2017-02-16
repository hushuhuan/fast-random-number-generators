#include<stdio.h>
#include<time.h>
#include<math.h>
main()
    {   
        double x,y;                 /* 定义获取二维随机点的变量x,y */
        FILE *p;                   
        void xk();
        void cl();                  /* 声明误差函数 */
        double rands();
        long int i;
        p=fopen("1.dat","w");
        for(i=0;i<1000;i++){      /* 产生1000个二维随机数 */
        x=rands();
        y=rands();
        printf("%f\t%f\n",x,y);
        fprintf(p,"%f\t%f\n",x,y);
        }

        fclose(p);
        xk();
        cl();                    /* 调用误差函数 */

        getchar();                /* 暂停屏幕 */
    }

double rands()                    /* 产生随机数 */
  {     static long int z,i=0;
        double x;
        if(i==0){
       time_t rawtime;
        time(&rawtime);               /* 取当前时间为种子值 */
       z=rawtime;
        i++;}    /* z为static变量，只在第一次调用时初始化 */
      z=16807*(z%127773)-2836*(z/127773);
      if(z<0) z=z+2147483647;
      x=(double)z/2147483647;
      return(x);

   }


  void xk(){                                  /* x^k误差函数 */
       float x,y,z=0.0,sum,sum1,t;long int N,k;
       FILE *p1;
       p1=fopen("2.txt","w");
       printf("\n\n采用误差函数XK\n");
       fprintf(p1,"\n\n采用误差函数XK\n");
       for(k=1;k<4;k++)
         {   z=0.0;
            printf("\n采误差函数的参数K的值为%d\n         N\t    <xk>\t|<xk>-C|\t1/N^0.5\n",k);
            fprintf(p1,"\n采误差函数的参数K的值为%d\n         N\t    <xk>\t|<xk>-C|\t1/N^0.5\n",k);
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
void cl(){                                  /* 误差函数C L */
         double x1,x2,y=0,sum,t,s;long int N;
         FILE *p2;
         p2=fopen("3.txt","w");
         x1=rands();
         printf("\n\n采用CL误差函数\n\n         N\t      Cl\t|Cl-0.25|\t1/N^0.5\n");

         fprintf(p2,"\n\n采用CL误差函数\n\n         N\t      Cl\t|Cl-0.25|\t1/N^0.5\n");
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




