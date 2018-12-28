
#include "dna_seq.h"
#include "DNAReader.h"
#include "DNAWriter.h"
using namespace std;

void test_dna_assaiment();
void test_dna_assaiment_in_string();
void test_dna_assaiment_in_string_failed();
void test_dna_constructors_failed();
void test_dna_copyconstructors();
void test_dna_constructors();
void test_dna_indexes();
void test_dna_indexes_failed();
void test_dna_getLength();
void test_dna_equal1();
void test_dna_equal2();
void test_dna_equal3();
void test_dna_notEqual();
void test_dna_index();
void test_dna_pair();
void test_dna_slice();
void test_dna_write_file();
void test_dna_read_file();

int main()
{
    std::cout << "hello world\n";
//    test_dna_assaiment();
//    test_dna_assaiment_in_string();
//    test_dna_copyconstructors();
//    test_dna_constructors();
//    test_dna_indexes();
//    test_dna_indexes_failed();
//    test_dna_assaiment_in_string_failed();
//    test_dna_constructors_failed();
//    test_dna_getLength();
//    test_dna_equal1();
//    test_dna_equal2();
//    test_dna_notEqual();
//    test_dna_index();
//    test_dna_equal3();
//    test_dna_slice();
//    test_dna_pair();
//    test_dna_write_file();
//    test_dna_read_file();

    return 0;
}

void test_dna_read_file() {
    DNAReader d("/home/cfrenkel/Desktop/dna_file.txt");
    DNA d1 = d.read();
    cout<<"read --- "<<d1<<"\n";
}

void test_dna_write_file() {
    DNAWriter d("/home/cfrenkel/Desktop/dna_write_file.txt");
    DNA d1("AAAGGGCCCAAAGGGCCC");
    d.Write(d1);
}

void test_dna_getLength() {
    DNA d("AAAgAA");
    cout<<d.getLength()<<endl;
}
void test_dna_constructors() {
    try {
        DNA d("agagagaAA");
        std::cout << d << endl;
    }
    catch (const char * msg){
        cout<<msg<<endl;
    }
}
void test_dna_copyconstructors() {
    try{
        DNA d("GGGgGG");
        DNA d1(d);
        cout<<d1<<endl;

    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_constructors_failed() {
    try{
        DNA d("LLLLgg");
        cout<<d<<endl;

    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_assaiment_in_string_failed() {
    try{
        DNA d = "AGAGAUgAG";
        cout<<d<<endl;

    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_assaiment_in_string() {
    try{
        DNA d = "AAA";
        cout<<d<<endl;

    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_assaiment() {
    try {
        DNA d("GGGGGg");
        DNA d1 = d;
        cout << d1 << endl;
    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_indexes(){
    try{
        DNA d("AGAgAA");
        cout<<d[1]<<endl;
    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_indexes_failed(){
    try{
        DNA d("AGAgAA");
        cout<<d[d.getLength()]<<endl;
    }
    catch (const char * msg) {
        cout<<msg<<endl;
    }
}
void test_dna_equal1() {
    DNA d("AAA");
    DNA d1("AGA");
    if (d1 == "aAGa")
    {
        cout<<"1 -- Equal\n";
    }
    else
    {
        cout<<"1 -- Not Equal\n";
    }
}
void test_dna_equal2() {
    DNA d("AAA");
    DNA d1 = d;
    if (d1 == d)
    {
        cout<<"Equal\n";
    }
    else
    {
        cout<<"Not Equal\n";
    }
}
void test_dna_notEqual() {
    DNA d("AAA");
    DNA d1 = d;
    if (d1!=d)
    {
        cout<<" Not Equal\n";
    }
    else
    {
        cout<<"Equal\n";
    }
}
void test_dna_index(){
    DNA d("AAggga");
    cout<<"before: "<<d<<endl;
    d[0] = 'C';
    cout<<"after: "<<d<<endl;
}
void test_dna_equal3() {
    DNA d("agagagaga");
    try {
        d[0] = 'A';
        if ('G' == d[1]) {
            cout << "3-- Equal\n";
        } else {
            cout << "3-- Not Equal\n";
        }
    }
    catch (const char * msg)
    {
        cout<<msg<<" Equal 3 "<<endl;
    }
}
void test_dna_pair(){
    DNA d("GTGggC");
    DNA d1(d.getPair());
    cout<<"pair: "<<d1<<endl;
}
void test_dna_slice(){
    DNA d1("AGgggGGAA");
    try {
        DNA d(d1.slice(1, 5));
        cout << "slice: " << d << endl;
    }
    catch (const char * msg)
    {
        cout<<msg<<endl;
    }
}
