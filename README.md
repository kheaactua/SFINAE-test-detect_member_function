# SFINAE-test-detect_member_function

SFINAE is annoying.  Making a repo saving working examples of detecting a member function
This relies on [Boost TTI](http://www.boost.org/doc/libs/1_56_0/libs/tti/doc/html/the_type_traits_introspection_library/tti_detail_has_member_function.html], which was recommended in [SFINAE Hell: detecting template methods](http://blog.quasardb.net/sfinae-hell-detecting-template-methods/)

Tested with:
- clang++ 5.0.1
- g++ 4.8
- Visual Studio 12 2013
