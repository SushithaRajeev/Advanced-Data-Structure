#include "assign2SHJ986.h"

int main(){

cout << "*** Please read README file before executing the program***" << endl;
cout << "\nEnter the height: ";
cin >> h;
array_size = pow(2, h+1) - 1;
cout << "\nAre you going to enter all "<< array_size << " elements [If No Press 0, otherwise press 1 to continue]? ";
cin >> Val;
if (Val != 0 && Val != 1 )
{
    cout<<"InputERROR: not a valid input."<<endl;
    exit(0);
}
if(Val == 0)
{
    cout << "\nAlright, how many elements? Please enter number of elements between "<<pow(2, h)<<" and "<< array_size << ". ";
    cin >> Val;
    if (Val < pow(2, h) && Val > array_size)
   {
      cout << "InputERROR: not a valid number of elements for hieght = "<< h <<"."<<endl;
      exit(0);
   }
   array_size=Val;
}

int array[array_size];

cout << "\nEnter the array elements of " << array_size << " size of the Tree: ";
for(i = 1; i <= array_size; i++){
    cin >> array[i];
    if (cin.fail())
    {
        cout << "InputERROR: not a valid number input. Enter only digits" << endl;
        //break;
        exit(0);
    }
}

/*for(i = 0; i < array_size; i++)
  std::cout << array[i] << ' ';*/

TrickelDown(i, h, array_size, array);

cout << "\nDo you want to continue?? \n1. Insert\n2. DeleteMin\n3. DeleteMax or\n4. Exit\nPlease enter an option. ";
cin>>option;
switch(option)
{
case 1:
    {
      cout<<"Please enter the number of elements you want to insert. ";
      cin>>noOfInserts;
      if (cin.fail())
      {
          cout<<"InputError: should be a number."<<endl;
          exit(0);
      }
      int array_size1=array_size + noOfInserts;
      int array1[array_size1];
      for(i = 1; i <= array_size; i++){
         array1[i] = array[i];
      }
      cout<< " Insert the elements: ";
      for(i = array_size+1; i <= array_size1; i++){
         cin>>array1[i];
         if (cin.fail())
         {
           cout << "InputERROR: not a valid number input. Enter only digits" << endl;
           exit(0);
         }
      }
      int j=array_size1;
      if(j > (pow(2, h+1) - 1))
      {
        while ((pow(2, h+1) - 1) < j && j < (pow(2, h+2) - 1))
        {
           h++;
        }
      }
      TrickelDown(array_size,h,array_size1, array1);
    }
    break;
case 2: {
      int array_size1=array_size-1;
      int array1[array_size1];
      cout << "\nMinimum element is :" << array1[1] << endl;
      for(i = 2; i <= array_size; i++){
         array1[i-1] = array[i];
      }
      int j=array_size1;
      if(j > (pow(2, h+1) - 1))
      {
        while ((pow(2, h+1) - 1) < j && j < (pow(2, h+2) - 1))
        {
           h++;
        }
      }
      TrickelDown(i, h, array_size1, array1);
    }
    break;
case 3: {
      int array_size1=array_size-1;
      int array1[array_size1];
      int deleitem=2;
      if (array[3] > array[2])
      {
         deleitem = 3;
      }
      int k = 1; 
      for(i = 1; i <= array_size; i++){
         if (i == deleitem)
             continue;
         array1[k] = array[i];
         k++;
      }
      int j=array_size1;
      if(j > (pow(2, h+1) - 1))
      {
        while ((pow(2, h+1) - 1) < j && j < (pow(2, h+2) - 1))
        {
           h++;
        }
      }
      TrickelDown(i, h, array_size1, array1);
    }
    break;
case 4: {exit(0); break;}
default: {cout<<"Oops!! wrong input. "<<endl; exit(0);}
}

return 0;
}

void swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void Print(int* a, int n)
{
    int i;
    for (i = 1; i < n + 1; i++)
    {
        printf("%d  ", a[i]);
    }

}

int TrickelDown(int i, int h, int array_size, int *array){
  for(i = 1; i <= array_size; i++){
    if(isMinLevel(i, h) == true)
	TrickleDownMin(i, h, array_size, array);
    else 
	TrickleDownMax(i, h, array_size, array);
    Print(array, array_size);
    printf(" at i = %d\n", i);
      }  
}


		
bool isMinLevel(int i, int h){
    //cout << "Min level getting here";
    int prev = 1;
	bool min = true;
	for(int j = 0; j <= h; j++)
	{
	   int r = pow(2, j);
	   int start = prev;
	   int end = prev + r - 1;
	   if((min == true) && (start <= i && i <= end))
              return true;
		  
	   if((min == false) && (start <= i && i <= end))
	      return false;
	   
           prev = end + 1; 
	  
           if(min == true){
              min = false;
              continue;
             }
		  
	   if(min == false){
              min = true;
              continue;
	     } 
	    
	 
	}	
}

void TrickleDownMin(int i, int h, int array_size, int *array)
{ 
    
  //if(array_size > (i * 2 + 1)) //i has children
    
    lc = Left(i);
    if (lc > array_size) // A[i] has no children
        return;
    else
    {
        rc = Right(i);
        mc = rc > array_size ? lc : (array[lc] > array[rc]) ? rc : lc;      //smallest of lc and rc
        child = true; // keep tracking m comes from children or grandchildren
        // m = smallest of children and grand children
        lclc = Left(lc);
        if (lclc <= array_size)
        {
            lcrc = Right(lc);
            mlc = lcrc > array_size ? lclc :(array[lclc] > array[lcrc]) ? lcrc : lclc;   ///smallest of grandchildren of left child of i
            mc = array[mlc] > array[mc] ? mc : mlc;   // smallest of child of i and grandchildren of left child of i
            if (mc == mlc)    /// if grandchildren is smallest than children of i i.e. m is from grandchildren
                child = false;
        }
        rclc = Left(rc);
        if (rclc <= array_size)
        {
            rcrc = Right(rc);
            mrc = rcrc > array_size ? rclc : (array[rclc] > array[rcrc]) ? rcrc : rclc;   //mrc->smalest of grandchildren of right child of i
            mc = array[mrc] > array[mc] ? mc : mrc;   //smalest of child of i and grandchildren of left of i and grandchildren of right child of i
            if (mc == mrc)   /// if grandchildren is smallest than children of i i.e. m is from grandchildren
                child = false;
        }
        m = mc;
        //cout << "\nmin value" << m;
        //cout << "\nValue of parent\n" << array[Parent(m)];
        if (!child)   //m is one of the grandchildren of i
        {
            if (array[m] < array[i])
            {
               
                swap(&array[m], &array[i]);
                if (array[m] > array[Parent(m)])                                 ////if for max level??
                    swap(&array[m], &array[Parent(m)]);
                    //cout << Parent(m);

 		if(isMinLevel(i, h) == true)
			BubbleUpMin(i, array);
    		else 
			BubbleUpMax(i, array);

                
                TrickleDownMin(m, h, array_size, array);
            } 
        }
        else    //m is child of i
        {
            if (array[m] < array[i])
                swap(&array[i], &array[m]);
		
	    if(isMinLevel(i, h) == true)
		BubbleUpMin(i, array);
    	    else 
		BubbleUpMax(i, array);

         }
    }		  
}       

void TrickleDownMax(int i, int h, int array_size, int *array)
{ 
    
    lc = Left(i);
    if (lc > array_size) // A[i] has no children
        return;
    else
    {
        rc = Right(i);
        mc = rc > array_size ? lc : (array[lc] < array[rc]) ? rc : lc;
        child = true; // keep tracking m comes from children or grandchildren
        // m = smallest of children and grand children
        lclc = Left(lc);
        if (lclc <= array_size)
        {
            lcrc = Right(lc);
            mlc = lcrc > array_size ? lclc :(array[lclc] < array[lcrc]) ? lcrc : lclc;
            mc = array[mlc] < array[mc] ? mc : mlc;
            if (mc == mlc)
                child = false;
        }
        rclc = Left(rc);
        if (rclc <= array_size)
        {
            rcrc = Right(rc);
            mrc = rcrc > array_size ? rclc : (array[rclc] < array[rcrc]) ? rcrc : rclc;
            mc = array[mrc] < array[mc] ? mc : mrc;
            if (mc == mrc)
                child = false;
        }
        m = mc;
        //cout << "Value of min" << m;

        if (!child)//m is one of the child of i
        {
            if (array[m] > array[i])
            {
                swap(&array[m], &array[i]);
                if (array[m] < array[Parent(m)])                         ////is for min level??
                    swap(&array[m], &array[Parent(m)]);
	    	if(isMinLevel(i, h) == true)
			BubbleUpMin(i, array);
    	    	else 
			BubbleUpMax(i, array);

                TrickleDownMax(m, h, array_size, array);
            }
        }
        else    //m is child of i
        {
            if (array[m] > array[i])
                swap(&array[i], &array[m]);
	    if(isMinLevel(i, h) == true)
		BubbleUpMin(i, array);
    	    else 
		BubbleUpMax(i, array);


        }


    }		  
}    

void BubbleUp(int start, int h, int array_size, int *array){
  for(int i = start+1; i <= array_size; i++){
    if(isMinLevel(i, h) == true)
        BubbleUpMin(i, array);
    else
        BubbleUpMax(i, array);
    Print(array, array_size);
    printf(" at i = %d\n", i);
      }
}

int BubbleUpMin(int i, int *array)
{
     if(GrandParent(i) > 0){
        if(array[i] < array[GrandParent(i)])
           swap(&array[i], &array[GrandParent(i)]);
           BubbleUpMin(GrandParent(i), array);
     }
}

int BubbleUpMax(int i, int *array)
{
     if(GrandParent(i) > 0){
        if(array[i] > array[GrandParent(i)])
           swap(&array[i], &array[GrandParent(i)]);
           BubbleUpMax(GrandParent(i), array);
     }
}
