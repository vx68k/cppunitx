Programming interface
=====================

Assertions
----------

The functions described in this section are declared in the
`cppunitx::assertion` namespace.

.. cpp:namespace:: cppunitx::assertion

.. cpp:function:: template<class T, class U> \
                  void assertEqual(T x, U y, const char *message = nullptr)
                  template<class T, class U> \
                  void assertEqual(T x, U y, const std::string &message)

   This function asserts two values are equal to each other.

.. cpp:function:: void fail(const char *message = nullptr)
                  void fail(const std::string &message)

   This function signals a test failure by throwing an exception.
