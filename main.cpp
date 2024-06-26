#include <iostream>
#include <vector>
#include "People.h"
#include "Author.h"
#include "Book.h"

using namespace std;
int main() {
   Book books("something",200.50,001);
   cout<<books;
    return 0;
}
