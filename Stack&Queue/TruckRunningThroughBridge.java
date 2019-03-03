import java.util.Queue;
import java.util.LinkedList;
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