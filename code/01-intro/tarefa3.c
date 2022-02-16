int process_pixel(int level, int limiar) {
    int new_level;

    if(limiar <= level){
        new_level = 255;
    }
    else{
        new_level = 0;
    }

    return new_level;
}
