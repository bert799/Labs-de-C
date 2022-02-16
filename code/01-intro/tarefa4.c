int process_pixel(int level, int limiar) {
    int new_level;

    new_level = level + limiar;
    if(new_level > 255){
        new_level = 255;
    }

    return new_level;
}
