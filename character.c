//取り合えず書いてあとで整形

//  boardの見方
//  0,0 0,1
//  1,0 1,1


// move_xy()    boardがboolean型用関数
// 引数：x=キャラ横座標、y=キャラ縦座標、z=移動方向、board[]=迷路配列
// (補足) z　=　(1:上, 2:下, 3:右, 4:左)
// 変数：xy[0]=横の座標、xy[1]=縦の座標
// board配列でtrueが通路、falseが壁、外周は必ず壁で囲まれている
// 移動不可：返り値0
// 移動可能：x,y変数を更新し、返り値1を返す
int move_xy(&x, &y, z, board){
    int xy[2]
    xy[0] = x;
    xy[1] = y;

    if(z == 0){
        xy[0]++;
    }else if(z == 1){
        xy[0]--;
    }else if(z == 2){
        xy[1]++;
    }else if(z == 3){
        xy[1]--;
    }

    // board配列が0～どこまであるか分からんから1以上だけ指定してる
    if(xy[0]>0 && xy[1]>0 && board[xy[0]][xy[1]] == true){
        x = xy[0];
        y = xy[1];
        return 1;
    }else{
        return 0;
    }
}


// move()     boardがint型用関数
// 引数：z=移動方向、board[]=迷路配列
// (補足) z　=　(1:上, 2:下, 3:右, 4:左)
// 変数：board配列で0が通路、1が壁、2が自分
// 移動不可：返り値0
// 移動可能：board配列を更新し、返り値1を返す
int move(z, board){
    int nowx = 0,nowy = 0;
    for(int i = 0,i < ??,i++){
        for(int j = 0;j < ??,j++){
            if(board[i][j] == 2){
                nowx = i;
                nowy = j;
            }
        }
    }

    if(z == 0){
        nowx++;
    }else if(z == 1){
        nowx--;
    }else if(z == 2){
        nowy++;
    }else if(z == 3){
        nowy--;
    }

    if(board[nowx][nowy] == 0){
        return 1;
    }else{
        return 0;
    }
}