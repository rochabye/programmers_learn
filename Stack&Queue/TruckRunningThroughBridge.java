import java.util.Queue;
import java.util.LinkedList;

class Queue<T> {
	
	class Node<T> {
		private T data;
		private Node<T> next;
		
		public Node( T data ) {
			this.data = data;
		}
	}
	
	private Node<T> first;
	private Node<T> last;
	
	public void enQueue( T item ) {
		Node<T> t = new Node<T>( item );
		if ( last != null ) {
			last.next = t;
		}
		last = t;
		if ( first == null ) {
			first = last;
		}
	}
	
	public T remove() {
		if ( first == null ) {
			return null;
		}
		T data = first.data;
		first = first.next;
		if ( first == null ) {
			last = null;
		}
		return data;
	}
	
	public T peek() {
		if ( first == null ) {
			return null;
		}
		return first.data;
	}
	
	public boolean isEmpty() {
		return first == null;
	}
}

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue< Integer > q = new LinkedList< Integer >();
        int cnt = 0;
        while( cnt < truck_weights.length ) {
            q.push( truck_weights[ cnt ] );
            ++cnt;
        }
        return answer;
    }
}