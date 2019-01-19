#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;
const int per_day_sub = 4 ;
const int per_week = 6 ;
class input
{
	public:
		int sub_no ,lab_no, i ,j,count  ;
		string sub[10];
		string sublab[10];
		string week[6] = { "MONDAY", "TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY" };
		void get_input();
			
};

void input :: get_input()
{
	cout << "Enter No of Subject  " ;
	cin >> sub_no;
	cout << "Enter No of Lab  " ;
	cin >> lab_no;
	for(i =0;i<sub_no;i++)
	{
		cout << "Enter Subject  " ;
		cin >> sub[i];
	}
	
	for(i =0;i<lab_no;i++)
	{
		cout << "Enter Subject Lab " ;
		cin >> sublab[i];
	}
}

class random : public input
{
	public:
		int r ,rl;
		string temp;
		string rand_sub[6][2];
		string rand_sublab[6];
		void get_random();
};
void random :: get_random()
{
	srand ( time(0) );
	for(j=0;j<per_week;j++)
	{
		for(i=0;i<(per_day_sub-2);i++)
		{
			r = rand() % sub_no;
			//cout << r <<" --> " << sub[r] <<endl;
			//rand_sub[j][i] = sub[r];
			if(i == 0)
			{
				rand_sub[j][i] = sub[r]; // check empty
			}
			else
			{
				for(int k=0;k < i;k++)
				{
					if(rand_sub[j][k] != sub[r])
					{
						//cout << "HI"<<endl;
						 temp = sub[r];
					}
					else
					{
						 
						temp = "0" ;
					}
				}
				rand_sub[j][i] = temp;
			}
		}
	}
	
	
	for(j=0;j < per_week;j++)
	{
		rl =  rand() % lab_no;
		if(j == 0)
		{
			rand_sublab[j] = sublab[rl]; // check lab empty
		}
		else
		{
			for(int k=0;k < i;k++)
			{
				if(rand_sublab[k] != sublab[rl])
				{
					//cout << "HI"<<endl;
					temp = sublab[rl];
				}
				else
				{
					 
					temp = "0" ;
					
				}
			}
			rand_sublab[j] = temp;
		}
		
	
	}
	 


}
/*	for(j=0;j<per_week;j++)
			{	
				cout << week[j]  <<"-->  " ;
				for(i=0;i<(per_day_sub-2);i++)
				{	
					cout << rand_sub[j][i] << " "  ;
				}
				cout << endl;
			}
	cout << "############## LAB #####################" <<endl;
	for(j=0;j<per_week;j++)
			{	
				cout << week[j]  <<"-->  " ;
				//rl =  rand() % lab_no;
				cout << sublab[j];
				
				cout << endl;
			}
}}
*/

class get_check : public random
{
	public : 
		void check();
		string h , min[20];
		int temps, blank, countsub[10],tempsort;	
};
void get_check :: check()
{
	for(int i2=0;i2<sub_no;i2++)
	{
		h = sub[i2];
		count = 0;
		for(j=0;j<per_week;j++)
		{
		for(i=0 ; i<(per_day_sub-2) ; i++)
			{
				if(rand_sub[j][i] == h)
				{
					count++;
				}
			}	
		}
		
		countsub[i2] = count;  // per subject count
		cout << sub[i2] <<" class/week --> " << countsub[i2] << endl;
	}
	
	blank = 0;
	for(j=0;j<per_week;j++)
		{
		for(i=0 ; i<(per_day_sub-2) ; i++)
			{
				if(rand_sub[j][i] == "0" or rand_sub[j][i] == " " )
				{
					blank = blank+1;
				}
			}	
			
		}
		
		int blanklab = (12 - (2*lab_no) ); //because per day 2 class allocate for lab so 2 multiply
		int total_blank = (blank + blanklab);
	cout << "Free Space  --> " << blank <<"    and  Lab Free --> "<<blanklab<< endl;

///// Allocate Subject minimum
if(blank > 0 )
{
for(j=0;j<blank;j++) 
{
tempsort = countsub[0]; // let 0th element is minimum
for(i=0;i < sub_no ; i++)
    {
        
        if(tempsort > countsub[i])
        {
            tempsort = countsub[i];
            temps = i;
            
            
        }
        
            
    }
    min[j] = sub[temps];
    
}
}
else if (blanklab >0) //if blank =0 but blanklab !=0 then
{
	for(j=0;j<blanklab;j++) 
{
tempsort = countsub[0]; // let 0th element is minimum
for(i=0;i < sub_no ; i++)
    {
        
        if(tempsort > countsub[i])
        {
            tempsort = countsub[i];
            temps = i;
            
            
        }
        
            
    }
    min[j] = sub[temps];
    
}
	
}

cout <<"Free Theory Class Fill by - " << min[0]<<endl;
cout <<"Free Lab Class Fill by - " << min[0]<<endl;
    	for(j=0;j<per_week;j++)
		{
		for(i=0 ; i<(per_day_sub-2) ; i++)
			{
				if(rand_sub[j][i] == "0" or rand_sub[j][i] == " " )
				{
					rand_sub[j][i] = sub[tempsort];
				}
			}
		}
		if(blanklab > 0)
		{
		for (j=0;j<blanklab;j++)
		{
			sublab[lab_no+j] = min[0]; 
		}
		}	
	

} // end of function
class display_routine : public get_check
{
	public : 
		void display() ; 
		
};

void display_routine :: display()  //display
{
	for(j=0;j<per_week;j++)
	{
		cout << week[j]  <<"-->  " ;
		for(i=0;i<(per_day_sub-2); i++)
		{
			cout  << " " <<rand_sub[j][i]   ;
			if(rand_sub[j][i] == "0" or rand_sub[j][i] == " " ) // blank space display after lowest sub
				{
					rand_sub[j][i] = sub[temps];
				}
		}
		
		for(i= (per_day_sub-2) ; i<per_day_sub ; i++)
		{
			cout << "  " <<sublab[j];
		}
		
		cout << endl;
		
	}
}

int main()
{
	display_routine r2;
	r2.get_input();
	r2.get_random();
	r2.check();
	r2.display();
	system("pause");
	return 0;
}








