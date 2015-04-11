from mibian import *
import numpy as np
from numpy.linalg import solve

#1
call = Me([50., 55., 4., 0.02*50., 6./12*365], volatility=20.)
put = Me([50., 45., 4., 0.02*50., 6./12*365], volatility=20.)

d_portfolioDelta = 1000*call.callDelta + 600*put.putDelta
print d_portfolioDelta, round(d_portfolioDelta)*50.

#2
ATMcall = Me([50., 50., 4., 0.02*50., 9./12*365], volatility=20.)
print call.callDelta, put.putDelta, ATMcall.callDelta
print call.gamma, put.gamma, ATMcall.gamma

a = np.array([[1,ATMcall.callDelta], [0,ATMcall.gamma]])
b = np.array([-1000*call.callDelta-600*put.putDelta, -1000*call.gamma-600*put.gamma])
x = solve(a, b)
print x
print round(x[0])*50.+round(x[1])*ATMcall.callPrice

#3