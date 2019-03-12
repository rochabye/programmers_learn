
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class Music implements Comparable< Music >{
    private int number;
    private int playTime;
    
    Music( int number, int playTime ) {
        this.number = number;
        this.playTime = playTime;
    }
    public int getNumber() {
        return number;
    }
    public void setNumber( int number ) {
        this.number = number;
    }
    public int getPlayTime() {
        return playTime;
    }
    public void setPlayTime( int playTime ) {
        this.playTime = playTime;
    }
    
    @Override
    public int compareTo(Music o) {
        return o.playTime - this.playTime;
    }
}

class Genre implements Comparable< Genre > {
    private String name;
    private List< Music > musics;
    private int totalCount;
    
    Genre( String name ) {
        this.name = name;
        musics = new LinkedList<>();
        this.totalCount = 0;
    }
    
    void addMusic( Music music ) {
        musics.add( music );
    }
    
    void sortMusics() {
        Collections.sort( musics );
    }
    
    void calcTotalCount() { 
        for( Music music : musics ) {
            totalCount += music.getPlayTime();
        }
    }
    
    Music getMusic ( int number ) {
        return musics.get( number );
    }
    
    @Override
    public boolean equals( Object o ) {
        if ( this == o ) return true;
        if ( o == null || getClass() != o.getClass() ) return false;
        Genre genre = ( Genre ) o;
        return name != null ? name.equals( genre.name ) : genre.name == null;
    }
    
    @Override 
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
    @Override
    public int compareTo(Genre o) {
        return o.totalCount - this.totalCount;
    }
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List< Music > getMusics() {
        return musics;
    }
}

class Solution {

    public int[] solution(String[] genres, int[] plays) {
        List< Genre > genreList = setGenresAndMusics( genres, plays );
        
        for( Genre genre : genreList ) {
            genre.sortMusics();
            genre.calcTotalCount();
        }
        Collections.sort( genreList );
        List< Integer > answerList = new ArrayList<>();
        for( Genre genre : genreList ) {
            answerList.add( genre.getMusic(0).getNumber() );
            if ( genre.getMusics().size() > 1 ) {
                answerList.add( genre.getMusic(1).getNumber() );
            }
        }
        
        int[] answer = new int[ answerList.size() ];
        for( int i = 0; i < answer.length; ++i ) {
            answer[ i ] = answerList.get( i ) ;
            
        }
        return answer;
    }
    
    private List< Genre > setGenresAndMusics( String[] genres, int[] plays ) {
        List< Genre >genreList = new ArrayList<>();
        
        for( int i = 0; i < genres.length; ++i ) {
            Genre genre1 = new Genre( genres[ i ] );
            if( !genreList.contains( genre1 ) ) {
                genreList.add(genre1);
            }
            for( Genre genre : genreList ) {
                if( genre.getName().equals( genres[ i ] ) ) {
                    genre.addMusic( new Music( i, plays[ i ] ) );
                }
            }
        }
        return genreList;
    }
}
   
