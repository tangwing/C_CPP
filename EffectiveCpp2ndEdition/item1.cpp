/**Item 1
Use more const,inline rather than #define:
1, defined macro is not in the symbol list
2, define a function can cause problems
*/
///Constants outside class
const char* const str = "asdf";
///Constants in classes
class GamePlayer
{
public:
    static const int NUM_TURNS = 5; ///normal way
    enum{NUM_TURNS2 = 6};           ///The enum hack
    int scores[NUM_TURNS];
    int scores2[NUM_TURNS2];
};
