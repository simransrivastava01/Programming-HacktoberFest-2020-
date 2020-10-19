import java.util.*;
	public class LinkedList{
		Node head;
		static class Node{
			int data;
			Node next;
			Node(int d){
				data=d;
				next=null;
				}
			}
	public static void insert(LinkedList list,int q,int pos){
int count=1;
		Node n=new Node(q);
		if(list.head==null&&pos==1){
			list.head=n;
			}
		else if(list.head!=null&&pos==1){
			Node temp=list.head;
			list.head=n;
			n.next=temp;
			}
		else{
			Node last=list.head;
			while(count!=pos-1){
				last=last.next;
				count++;
				}
			Node temp=last.next;
			last.next=n;
			n.next=temp;
			}
		}
		public static void delete(LinkedList list){
		 Node last=list.head;
		 if(last.next==null){
		     list.head=null;
		 }
		 else{
		     while(last.next.next!=null){
		         last=last.next;
		     }
		     last.next=null;
		 }
		}
      public static void print(LinkedList list){
		Node temp=list.head;
		while(temp!=null){
			System.out.print(temp.data+" ");
			temp=temp.next;
			}
		}
	public static void main(String Args[]){
		LinkedList list=new LinkedList();
		insert(list,10,1);
		delete(list);
		print(list);
		}
	}