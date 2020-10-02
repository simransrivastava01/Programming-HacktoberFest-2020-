
//Circular Queue using Arrays

import java.util.*;
class Main
{
  static int SIZE=4;
  static int front=-1;
  static int rear=-1;
  static int array[]=new int[SIZE];
void enqueue(int item)
  {
    if(front==0 && rear==(SIZE-1))
    {return ;}
    if(front == -1 && rear == -1)
    {front++;
     rear++;}
    else if(front != 0 && rear==(SIZE-1))
    {rear=0;}
    else
    {rear++;}
    
    array[rear]=item;

  }

  int dequeue()
  {
    if(front==-1)
    {return -1;}
    int item=array[front];
    if(front==rear)
    {front=rear=-1;}
    else if(front==(SIZE-1))
    {front=0;}
    else
    {++front;}
    return item;

}
  public static void main(String[] args)
  {
    Main ob1=new Main();
    Scanner s=new Scanner(System.in);
    int n, q1, q2;
      n = s.nextInt();    //no.of operations
      while(n>0)
      {
        q1 = s.nextInt();
        if(q1 == 1)
        {
          q2 = s.nextInt();
          ob1.enqueue(q2);
        }
        else
          System.out.print(ob1.dequeue() + " ");
        n--;
      }
      System.out.println();
}
}
