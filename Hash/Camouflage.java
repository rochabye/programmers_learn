import java.util.HashMap;
import java.util.Iterator;
import java.util.ArrayList;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        HashMap< String, Integer > cloth_map = new HashMap< String, Integer >();
        
        for( int i = 0; i < clothes.length; ++i ) {
            cloth_map.put( clothes[i][1], cloth_map.getOrDefault( clothes[i][1], 0 ) + 1 );
        }
        Iterator< String > it = cloth_map.keySet().iterator();
        answer = cloth_map.get( it.next() ) + 1;
        while( it.hasNext() ) {
            answer = answer * ( cloth_map.get( it.next() ) + 1 );
        }
        --answer;
        return answer;
    }
}