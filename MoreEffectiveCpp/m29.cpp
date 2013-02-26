/**
Test "reference count" function of system string
*/
void testRefCount()
{
    std::string str("Hello!");
    char* data = const_cast<char*>(str.data());
    char & bad = str[0];

    string str2 = str;
    cout<<str<<endl<<str2<<endl;
    data[0] = 'E'; ///modify both str and str2
    //bad = 'F'; ///modify only str
    cout<<str<<endl<<str2<<endl;
}
