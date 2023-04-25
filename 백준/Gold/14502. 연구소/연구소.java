import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int N,M,max;
	static int[][] arr, temparr;
	static List<Integer> virusx,virusy, blankx, blanky;
	static int[] dr = {1,-1,0,0};
	static int[] dc = {0,0,1,-1};
	
	static class Node{
		int x,y;
		public Node(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		temparr = new int[N][M];
		arr = new int[N][M];
		virusx = new ArrayList<>();
		virusy = new ArrayList<>();
		blankx = new ArrayList<>();
		blanky = new ArrayList<>();
		
		// 입력
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				int num = sc.nextInt();
				temparr[i][j] = num;
				if(num==2) {
					virusx.add(i);
					virusy.add(j);
				}
				else if(num==0) {
					blankx.add(i);
					blanky.add(j);
				}
			}
		}
		
		for(int i=0; i<blankx.size()-2; i++) {
			int firstx = blankx.get(i);
			int firsty = blanky.get(i);
			temparr[firstx][firsty] = 1;
			for(int j=i+1; j<blankx.size()-1; j++) {
				int secondx = blankx.get(j);
				int secondy = blanky.get(j);
				temparr[secondx][secondy] = 1;
				for(int k=j+1; k<blankx.size(); k++) {
					int thirdx = blankx.get(k);
					int thirdy = blanky.get(k);
					temparr[thirdx][thirdy] = 1;
					for(int a=0; a<N; a++) {
						for(int b=0; b<M; b++) {
							arr[a][b] = temparr[a][b];
						}
					}
					poison();
					check();
					temparr[thirdx][thirdy] = 0;
					
				}
				temparr[secondx][secondy] = 0;
				
			}
			temparr[firstx][firsty] = 0;
			
		}
		System.out.println(max);
	}
	
	static void check() {
		int cnt = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(arr[i][j] == 0) cnt++;
			}
		}
		if(cnt > max) max = cnt;
	}
	
	static void poison() {
		Queue<Node> q = new LinkedList<>();
		for(int i=0; i<virusx.size(); i++) {
			q.add(new Node(virusx.get(i), virusy.get(i)));
		}
		
		while(!q.isEmpty()) {
			Node cur = q.poll();
			
			for(int k=0; k<4; k++) {
				int nx = cur.x+dr[k];
				int ny = cur.y+dc[k];
				if(nx>=0 && ny>=0 && nx<N && ny<M && arr[nx][ny] == 0) {
					q.add(new Node(nx,ny));
					arr[nx][ny] = 2;
				}
				
			}
			
			
		}
	}
	
	
}