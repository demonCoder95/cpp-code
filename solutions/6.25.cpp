int secondsSince12(int hours, int mins, int secs){
    int hrsSince12 = hours % 12;    // hours passed since last time 12 was struck

    return hrsSince12*60*60 + mins*60 + secs;
}

