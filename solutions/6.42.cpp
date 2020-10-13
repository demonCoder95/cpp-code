// attempting recursion on the main() function
#include <iostream>

using namespace std;

int main(void){
    static int count = 1;
    
    cout << "Attempting to recursively call main().. count: " << count << endl;
    count++;

    // ka-boom!
    main();

    cout << "Oh, something happened!";

    return 0;
}