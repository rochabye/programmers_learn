#include <string>
#include <queue>
#include <map>
using namespace std;

template<typename T>
void pop_front(std::vector<T>& vec, std::vector<T>&vec_index)
{
    if ( !vec.empty() && !vec_index.empty() ) {
        vec.erase( vec.begin() );
        vec_index.erase( vec_index.begin() );
    }
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 0;
    std::vector< int > prior_q;
    prior_q = priorities;
    std::vector< int > index_q;
    for( int i = 0; i < prior_q.size(); ++i ) {
        index_q.push_back( i );
    }
    
    while( !prior_q.empty() ) {
        bool is_max = true;
        int prior = prior_q[0];
        int index = index_q[0];
        pop_front( prior_q, index_q );
        
        for( int i = 0; i < prior_q.size(); ++i ) {
            if ( prior < prior_q[i] ) {
                prior_q.push_back( prior );
                index_q.push_back( index );
                is_max = false;
            }
        }
        count++;
        if ( is_max && index == location ) { 
            answer = count; 
            break;
        }
    }
    
    return answer;
}