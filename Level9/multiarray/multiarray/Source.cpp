#include "boost/multi_array.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>

int main () {
    typedef boost::multi_array_types::index_range range;
    typedef boost::multi_array<char, 2> Array2d;
    Array2d a(boost::extents[80][24]);

    //to view the two-dimensional array as a one-dimensional one can use multi_array_ref?
    boost::multi_array_ref<char, 1> a_ref(a.data(), boost::extents[a.num_elements()]);
    std::fill(a_ref.begin(), a_ref.end(), '-');

    //to apply algorithm to one row or column, can use array_view
    //especially useful for traversing it vertically?
    //e.g:
    Array2d::array_view<1>::type views[4] = {
        a[boost::indices[range()][0]], //left column
        a[boost::indices[range()][a[0].size() - 1]], //right column
        a[boost::indices[0][range()]], //top row
        a[boost::indices[a.size()-1][range()]] //bottom row
    };
    for (unsigned i = 0; i != sizeof(views)/sizeof(views[0]); ++i) {
        std::fill ( views[i].begin(), views[i].end(), 'X' );
    }

    //output
    for (unsigned i = 0; i != a.size(); ++i) {
        std::copy(a[i].begin(), a[i].end(), std::ostream_iterator<char>(std::cout, ""));
        std::cout << '\n';
    }
}