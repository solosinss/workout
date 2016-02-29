#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
#if 0
    vector<string> svec1(2);
    vector<string> svec2(10, "b");
    vector<string>::iterator iter;

    for (iter = svec1.begin(); iter != svec1.end(); iter++)
    {
        //iter = svec1.begin();
        cout << *iter << endl;
    }
    for (iter = svec2.begin(); iter != svec2.end(); iter++)
    {
        //iter = --svec2.end();    
        cout << *iter << endl;
    }

    string word;
    int i = 0;
    while (cin >> word && i!=5)
    {
        svec1.push_back(word);
        i++;
    }

    for (iter = svec1.begin(); iter != svec1.end(); iter++)
    {
        //iter = svec1.begin();
        cout << *iter << endl;
    }

    cout << "svec1 size " << svec1.size()
        << "svec1 capacity " << svec1.capacity() << endl;
#else
    const char *cp = "Hello world!!!";
    char noNull[] = {'H', 'i'};

    string s1(cp);
    cout << s1 << endl;
    string s2(noNull);
    cout << s2 << endl;
    string s3(cp + 6, 5);
    cout << s3 << endl;

    string::size_type pos = s1.find("world");
    cout << "pos is " << pos << endl;
#endif
    return 0;
}
