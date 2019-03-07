import java.util.HashMap;

class Solution {
    public boolean solution(String[] phone_book) {
        HashMap< String, Integer >phone_map = new HashMap< String, Integer >();
        int cnt = 0; 
        for( String phone_num : phone_book ) {
            phone_map.put( phone_num, cnt );
            cnt++;
        }
        for( String key : phone_map.keySet() ) {
            for ( String key_comp : phone_map.keySet() ) {
            	if ( key.length() < key_comp.length() 
                    && key.compareTo( key_comp.substring( 0, key.length() ) ) == 0 
                    && phone_map.get( key ) != phone_map.get( key_comp ) ) {
	            			return false;
            		}
            }
        }
        return true;
    }
}