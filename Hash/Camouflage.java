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
        if ( cloth_map.keySet().size() > 1 ) {
            answer = cloth_map.get( it.next() );
            while( it.hasNext() ) {
                answer = answer * cloth_map.get( it.next() ); 
            }
        }
        
        it = cloth_map.keySet().iterator();
        ArrayList< Integer > type = new ArrayList< Integer >();
        while( it.hasNext() ) {
            String key = it.next();
            answer = answer + cloth_map.get( key ); // sum each one 
            type.add( cloth_map.get(key ) );
        }
        ArrayList< Integer > type_multi = new ArrayList< Integer >();
        for( int i = 0 ; i < type.size(); ++i ) {
            for( int j = i + 1; j < type.size(); ++j ) {
                type_multi.add( type.get( i ) * type.get( j ) );
            }
        }
        int all_multi = 1;
        for( int i = 0; i < type.size(); ++ i ) {
            all_multi *= type.get(i);
        }
        
        return answer;
    }
}