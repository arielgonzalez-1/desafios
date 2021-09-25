#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import calendar
import datetime as d

def main():
    actual = d.datetime.now()
    print(calendar.month(actual.year, actual.month))

if __name__ == '__main__':
    main()
