import java.util.HashMap;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap< String, Integer > p_map = new HashMap< String, Integer >();
        for ( String p : participant ) {
            p_map.put( p, p_map.getOrDefault( p, 0 ) + 1 );
        }
        for ( String c : completion ) { 
            p_map.put( c, p_map.getOrDefault( c, 0 ) - 1 );
        }
        for( String key : p_map.keySet() ) {
            if ( p_map.get( key ) != 0 ) {
                answer = key; 
            }
        }
        return answer;
    }
}