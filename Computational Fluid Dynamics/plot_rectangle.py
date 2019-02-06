import matplotlib.pyplot as plt 
from matplotlib.patches import Rectangle
import pandas as pd

data = pd.read_csv("Integral_plot.csv",index_col=None, header=None)
# Data: y-Values, rectangle_start, rectangle_width, height
y = data.iloc[:,0]
x_start = data.iloc[:,1]
width = data.iloc[:,2]
height = data.iloc[:,3]


x = [width[0]*i for i in range(len(y))]
#print(x)
y_start = [0 for i in range(len(x_start))]
assert len(y_start) == len(x_start)
#print(y)

plt.figure()
plt.plot(x,y,"b")
plt.xlim(0,max(x_start)+2*width.any())
plt.ylim(0,max(y)+width.any())
currentAxis = plt.gca()
for i in range(len(x_start)-1):

    currentAxis.add_patch(Rectangle((x_start[i], y_start[i]), width[i], height[i], fill=None, alpha=1,color = "red"))
plt.show()