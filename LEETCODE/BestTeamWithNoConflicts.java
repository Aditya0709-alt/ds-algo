class Solution {
    private int dp[];
    private int max;
    public int bestTeamScore(int[] scores, int[] ages) {
        
        Player[] players = new Player[scores.length];
        
        //group scores and ages in single data structure
        for(int i=0;i<players.length;i++){
            players[i] = new Player(ages[i],scores[i]);
        }
        
        //sort on the basis of ages, use score for breaking ties
        Arrays.sort(players, (player1,player2)->player1.age==player2.age?player1.score-player2.score:player1.age-player2.age);
        
        dp = new int[players.length];
        Arrays.fill(dp, -1);
        
        //trying to consider all the players atleast once
        for(int i=0;i<players.length;i++)
            max = Math.max(max,dfs(i, players));
        
        return max;
    }
    
    public int dfs(int index, Player[] players) {
        if(dp[index] != -1) return dp[index];
        
        dp[index] = players[index].score;
        for(int i = index+1; i < players.length; i++) {
            if(players[i].score >= players[index].score) {
                dp[index] = Math.max(dp[index], dfs(i, players) + players[index].score);
            }
        }
        
        return dp[index];
    }
}

class Player{
    public int age;
    public int score;
        
    public Player(int age, int score){
        this.age = age;
        this.score = score;
    }
}
