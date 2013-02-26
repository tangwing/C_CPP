/**Item 5
    Use new/delete rather than malloc/free.
    Be careful of delete and delete[], otherwise the
behavior is undefined.
    Better don't use typedef on arrays.
    Always init pointer (to 0) in the constructor, so that
we can always delete a pointer in the destructor.
*/

//typedef string AddressLines[4];
//string *pal = new AddressLines;// == new string[4]
//delete pal;//Wrong
//delete[] pal; //Right
