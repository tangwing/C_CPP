
void testNewDelete()
{
    int * itab = new int [3];
    delete itab;//false, but no complilation error
    int * itab2 = new int [3];
    delete []itab2;//true
    int * itab3 = 0;
    delete itab3;


//    int i = 0;
//    delete i;//error
}
