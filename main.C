#include "Set.h"

int main()
{
    // *******************************************
    //   
    //  THIS main, which is what you'll be responsible
    //  for completing for both the characteristic vector
    //  AND List approach. 
    //   
    // ******************************************* 

    Set s1, s2, s3;
    
    s1.addToSet(27);
    s1.addToSet(0);
    s1.addToSet(109);
cout << "Checking set s1" << endl;
    s1.printSet();

    s2.addToSet(43);
    s2.addToSet(34);
    s2.addToSet(27);
cout << "Checking set s2" << endl;
    s2.printSet();

    s3.clear();
cout << "Checking set s3 before intersection" << endl;
    s3.printSet();
cout << "Performing s3 = s1 & s2 " << endl;
    s3 = s1 & s2;
    s3.printSet();
    cout << "The intersection of s1 and s2 is " << endl;
    s3.printSet();
    s3.clear();
cout << "Checking set s3 before union" << endl;
cout << "Performing s3 = s1 | s2 " << endl;
    s3 = s1 | s2;
    cout << endl << "The union of s1 and s2 is " << endl;
    s3.printSet();
cout << "About to test cardinality" << endl << endl;
cout << "The cardinality of S3 = " << s3.cardinality() << endl << endl;

    Set s4;
    s4 = s3 - s2;
    s4.printSet();
cout << "About to test removeFromSet" << endl << endl;
    s4.removeFromSet(109);
cout << "S4 after 109 is removed = " << endl;
    s4.printSet();
    return 0; 

}
