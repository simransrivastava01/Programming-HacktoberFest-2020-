import java.util.*;
public class LinkedList{
		Node tail,head;
		static class Node{
			int data;
			Node next;
			Node(int q){
				data=q;
				}
			}
		public static void insert(LinkedList list,int q,int pos){
		int count=1;
		Node n=new Node(q);
		if(list.head==null){
			list.head=n;
			list.tail=n;
			n.next=list.head;
			}
		else if(list.head!=null&&pos==1){
			Node temp=list.head;
			list.tail.next=n;
			list.head=n;
			n.next=temp;
			}
		else{
			Node last=list.head;
			while(count!=pos-1){
				last=last.next;
				count++;
				}
				
			     if(last.next==list.head){
				last.next=n;
				n.next=list.head;
				list.tail=n;
				}
			    else{
				Node temp=last.next;
				last.next=n;
				n.next=temp;
				}
			}
		}
		public static void delete(LinkedList list){
		    Node last=list.head;
		       if(last.next==list.head){
		          last.next=null; 
		       }
		       else{
		    while(last.next.next!=list.head){
		        last=last.next;
		    }
		    last.next=list.head;
		       }
		}
	public static void print(LinkedList list){
		Node last=list.head;
		if(last.next==null){

		}
		else{
		while(last.next!=list.head){
			System.out.print(last.data+" ");
			last=last.next;
			}
			System.out.print(last.data);
		  }
		}
    public static void main(String Args[]){
			LinkedList list=new LinkedList();
			insert(list,10,1);
			insert(list,20,1);
			insert(list,30,1);
			insert(list,40,2);
			insert(list,50,5);
			print(list);
			}
	}