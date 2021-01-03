#!/opt/local/bin/python3
# -*- coding: utf-8 -*-
# Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
# Licensed under the MIT License. See the LICENSE file in the project root for more information.
#
# Name: validate.py - Version 1.0.0
# Author: crdrisko
# Date: 10/29/2020-09:20:01
# Description: Validate the results of the finiteDifferencesExample using numpy's gradient and scipy's cumtrapz

import numpy as np
from scipy import integrate

x = np.linspace(0, 10000.1, 100002)
y = (4 * x**2) + (2 * x) - 7

derivative1st = np.gradient(y, x)
integral2nd = integrate.cumtrapz(derivative1st, x, initial=0.0)

integral1st = integrate.cumtrapz(y, x, initial=0.0)
derivative2nd = np.gradient(integral1st, x)

counter1 = 0
counter2 = 0

tolerance = 2 * (x[1] - x[0])

for i in range(1, np.size(x) - 1):
    if y[i] - (integral2nd[i] - 7) <= tolerance:
        counter1 += 1

    if y[i] - derivative2nd[i] - 2 <= tolerance:
        counter2 += 1

print("The calculation of ∫(dy / dx) dx resulted in %d out of %d elements within %0.1f of the exact result."
    % (counter1, np.size(y) - 2, tolerance))

print("The calculation of d(∫y dx) / dx resulted in %d out of %d elements within %0.1f of the exact result."
    % (counter2, np.size(y) - 2, tolerance))
