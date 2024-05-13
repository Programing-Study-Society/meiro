int map_print(board, x, y){
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++)
            printf("%s", (map[x][y] == WALL) ? "■" : "　");
        printf("\n");
    }
}