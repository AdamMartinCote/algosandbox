from math import factorial
from unittest import TestCase

from dynamicprogramming.nchoosek import nchoosek_recursive, nchoosek_dp


class Test(TestCase):
    def nchoosek_template_method(self, method):
        for n in range(1, 6):
            for k in range(1, n):
                print(f"{n} choose {k}:")
                res = method(n, k)
                print(res)

                ref = factorial(n) / (factorial(k) * factorial(n - k))
                self.assertEqual(ref, res)
                print(ref)

    def test_nchoosek_recursive(self):
        self.nchoosek_template_method(nchoosek_recursive)

    def test_nchoosek_dp(self):
        self.nchoosek_template_method(nchoosek_dp)
