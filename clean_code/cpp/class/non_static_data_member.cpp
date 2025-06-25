class S
{
    int n;              // non-static data member
    int& r;             // non-static data member of reference type
    int a[2] = {1, 2};  // non-static data member with default member initializer (C++11)
    std::string s, *ps; // two non-static data members

    struct NestedS
    {
        std::string s;
    } d5;               // non-static data member of nested type

    char bit : 2;       // two-bit bitfield
};
