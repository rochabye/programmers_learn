using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort( citations.begin(), citations.end(),std::greater<int>() );
    int h_index = 0;
    for( int i = 0; i < citations.size(); ++i ) 
    {
        if ( h_index < citations[ i ] ) {
            ++h_index;
        }
    }
    return h_index;
}