#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
-------------------------------------------------
   File Name:infix2postfix
   Author:jasonhaven
   date:18-9-28
-------------------------------------------------
   Change Activity:18-9-28:
-------------------------------------------------
"""

import re

level = {}
level['('] = 0
level['+'] = 1
level['-'] = 1
level['*'] = 2
level['/'] = 2


def convert(s):
    output = []
    opStack = []
    list = s.split()
    for i in list:
        if re.match(r'^\d+$', i):
            output.append(i)
        elif i == '(':
            opStack.append(i)
        elif i == ')':
            top = opStack.pop()
            while top != '(':
                output.append(top)
                top = opStack.pop()
        elif i in '+-*/':
            while opStack and (level[opStack[-1]] >= level[i]):
                output.append(opStack.pop())
            opStack.append(i)
        else:
            raise Exception('meet a unexpected operator "%s"' % (i,))

    while opStack:
        output.append(opStack.pop())

    return output


if __name__ == '__main__':
    ins = input()
    post = convert(ins)
    print(post)
