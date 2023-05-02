import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		PriorityQueue<Integer> start = new PriorityQueue<>();
		PriorityQueue<Integer> end = new PriorityQueue<>();
		
		for(int i=0; i<N; i++) {
			start.add(sc.nextInt());
			end.add(sc.nextInt());
		}
		
		int room = 0;
		int max = 0;
		while(!start.isEmpty() || !end.isEmpty()) {
			int s = Integer.MAX_VALUE;
			int e = Integer.MAX_VALUE;
			if(!start.isEmpty()) s = start.peek();
			if(!end.isEmpty()) e = end.peek();
			if(s<e) {
				start.poll();
				room++;
				if(room>max) max = room;
			}
			else {
				end.poll();
				room--;
			}
		}
		
		System.out.println(max);
	}
}