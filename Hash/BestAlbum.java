java.util.HashMap;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        HashMap< String, Integer > genres_map = new HashMap< String, Integer >();
        
        for( int i = 0; i < genres.length; ++i ) {
        	if ( !genres_map.containsKey( genres[ i ] ) ) {
        		genres_map.put( genres[ i ], plays[ i ] );
        	} 
        	else {
        		genres_map.put( genres[ i ], genres_map.get( genres[ i ] ) + plays[ i ] );
        	}
        }
        String max_key = genres[ 0 ];
        int max = genres_map.get( max_key );
        for ( String key : genres_map.keySet() ) {
        	if ( max < genres_map.get( key ) ) {
        		max = genres_map.get( key );
        		max_key = key;
        	}
        }
        return answer;
    }
}