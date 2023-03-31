import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int min6 = Integer.MAX_VALUE;
		int min1 = Integer.MAX_VALUE;
		for(int i = 0; i < m;++i) {
			int price6 = sc.nextInt();
			int price1 = sc.nextInt();
			
			min6 = Math.min(price6, min6);
			min1 = Math.min(price1, min1);
		}
		
		int ans = n/6 * min6 + n%6 *min1;
		int packCnt = n/6;
		if(n%6 > 0)
			packCnt += 1;
		ans = Math.min(ans, packCnt*min6);
		ans = Math.min(ans, n*min1);
		System.out.println(ans);
	}
}