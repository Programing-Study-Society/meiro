// Goalなら1、まだなら0
// x, y, gxはGoalのx座標, gyはGoalのy座標
int goal_xy(x, y, gx, gy){
    if(x == gx && y == gy){
        return 1;
    }else{
        return 0;
    }
}
// Goalなら1、まだなら0
// board配列、goal配列はGoalの座標を保存
int goal(board, goal){
    int nowx = 0,nowy = 0;
    for(int i = 0,i < ??,i++){
        for(int j = 0;j < ??,j++){
            if(board[i][j] == 2){
                nowx = i;
                nowy = j;
            }
        }
    }
    if(nowx == goal[0] && nowy == goal[1]){
        return 1;
    }else{
        return 0;
    }
}